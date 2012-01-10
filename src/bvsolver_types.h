/*
 * DATA STRUCTURES FOR THE BITVECTOR SOLVER
 */

/*
 * Version 2: pure bit-blasting/no subsolver. All bit-blasting
 * is done directly in the core.
 * 
 * For each variable x, we store
 * - bit_size[x] = number of bits in x
 * - kind[x] = tag so that we know how to interpre def[x]
 * - def[x] = definition of x 
 * - eterm[x] = attached egraph term (optional)
 * - map[x] = array of literals (bit blasting)
 *
 * Bit vector atoms are of three kinds:
 * - bveq x y
 * - bvge x y: x <= y, where x and y are interpreted 
 *   as unsigned integers
 * - bvsge x y: x <= y, where x and y are as signed
 *   integers
 */

#ifndef __BVSOLVER_TYPES_H
#define __BVSOLVER_TYPES_H

#include <stdint.h>
#include <setjmp.h>

#include "int_vectors.h"
#include "bvpoly_buffers.h"
#include "power_products.h"
#include "remap_table.h"
#include "bit_blaster.h"
#include "merge_table.h"
#include "egraph_assertion_queues.h"

#include "bv_vartable.h"
#include "bv_atomtable.h"
#include "bvexp_table.h"
#include "bv_intervals.h"

#include "smt_core.h"
#include "egraph.h"
#include "context.h"





/*****************
 *  BOUND QUEUE  *
 ****************/

/*
 * A bound on a variable 'x' an atom (x >= a) where a is a constant,
 * and the atom is either true or false at the top-level.
 * - the bounds on x are stored in a queue
 * - each element in the queue is an atom index 
 * - the start of the list is stored in queue->bounds[x]
 * - we also store disequalities (x != 0) in the list
 */

/*
 * Bound descriptor: atom index + index of the predecessor
 * element in the queue pointer
 */
typedef struct bv_bound_s {
  int32_t atom_id;
  int32_t pre;
} bv_bound_t;


/*
 * Queue:
 * - data = array of bound descriptors
 * - top = index in data = number of elements in the queue
 * - size = total size of the array
 * To store the lists:
 * - bound = array of indices
 * - bsize = size of this array 
 * For a variable 0 <= x < vtbl->nvars 
 * - if x < bsize then bound[x] = index of the last 
 *   bound asserted on x. 
 *   If bound[x] = k then data[k].atom_id is the bound
 *   and data[k].pre = previous bound on x.
 *   The list is terminated by -1.
 * - if x >= bsize then there's no bound on x
 */
typedef struct bv_bound_queue_s {
  bv_bound_t *data;
  int32_t *bound;
  uint32_t top;
  uint32_t size;
  uint32_t bsize;
} bv_bound_queue_t;


#define DEF_BV_BOUND_QUEUE_SIZE 50
#define MAX_BV_BOUND_QUEUE_SIZE (UINT32_MAX/sizeof(bv_bound_t))

#define DEF_BV_BOUND_NUM_LISTS 100
#define MAX_BV_BOUND_NUM_LISTS (UINT32_MAX/sizeof(int32_t))




/***********************************
 *  INTERVAL COMPUTATION BUFFERS   *
 **********************************/

/*
 * For computing enclosing intervals on a bitvector expression,
 * we may need a stack of bv_intervals and a bv_aux_buffer structure.
 * These are stored in the following structure.
 *
 * Initially, this is set to: 
 * - data = NULL
 * - buffers = NULL
 * - size = 0
 *
 * When the first interval is requested the stack and aux_buffers
 * are allocated.
 */
typedef struct bv_interval_stack_s {
  bv_interval_t *data;
  bv_aux_buffers_t *buffers;
  uint32_t size;
  uint32_t top;
} bv_interval_stack_t;


#define DEF_BV_INTV_STACK_SIZE 6
#define MAX_BV_INTV_STACK_SIZE (UINT32_MAX/sizeof(bv_interval_t))




/********************
 *  PUSH/POP STACK  *
 *******************/

/*
 * For every push, we keep track of the number of variables amd atoms
 * on entry to the new base level, and the size of the bound queue.
 */
typedef struct bv_trail_s {
  uint32_t nvars;
  uint32_t natoms;
  uint32_t nbounds;
} bv_trail_t;

typedef struct bv_trail_stack_s {
  uint32_t size;
  uint32_t top;
  bv_trail_t *data;
} bv_trail_stack_t;

#define DEF_BV_TRAIL_SIZE 20
#define MAX_BV_TRAIL_SIZE (UINT32_MAX/sizeof(bv_trail_t))





/***********************
 *  LEMMAS/CACHE TAG   *
 **********************/

/*
 * Experiment: simpler approach to deal with equality and
 * disequalities from the egraph.
 *
 * We can force the egraph and bv_solver to agree by
 * generating lemmas of the form (eq t1 t2) <=> (bveq x1 x2),
 * where t1 and t2 are egraph terms
 *   and x1 and x2 are the corresponding bit-vector variables.
 *
 * To avoid generating several times the same lemma, we keep
 * the pair (x1, x2) in a cache, with the tag BVEQUIV_LEMMA.
 *
 * Other tags:
 * in egraph_types.h: 
 *   DISTINCT_LEMMA = 0
 *   ACKERMANN_LEMMA = 1
 * in simplex_types.h
 *   TRICHOTOMY_LEMMA = 2
 */
typedef enum bv_lemma_tag {
  BVEQUIV_LEMMA = 3,
} bv_lemma_tag_t;

typedef enum bv_lemma_flag {
  ACTIVE_BV_LEMMA = 1, // anything non-zero will do
} bv_lemma_flag_t;




/***********************
 * SETS OF USED VALUES *
 **********************/

/*
 * When building models, the egraph may need fresh bitvector values.
 * A value is fresh if it's distinct from the values assigned to all
 * the bitvector variables.
 * 
 * To generate fresh values of type (bitvector k), we build the set of
 * used values of that type and search for something not in the set.
 * Depending on k, we use different data structures to store the set:
 * - k <= SMALL_BVSET_LIMIT: use small_bvset_t
 * - k > SMALL_BVSET_LIMIT: use red-black trees
 *
 * The used_bvval structure store pairs <bitsize k, set>
 */

// ptr is either a pointer to a small_bvset_t or to a rb_bvset_t
// depending on bitsize
typedef struct bvset_s {
  uint32_t bitsize;
  void *ptr;
} bvset_t;

typedef struct used_bvval_s {
  bvset_t *data;
  uint32_t nsets;
  uint32_t size;
} used_bvval_t;

#define SMALL_BVSET_LIMIT 13

#define USED_BVVAL_DEF_SIZE 8
#define USED_BVVAL_MAX_SIZE (UINT32_MAX/sizeof(bvset_t))




/************
 *  SOLVER  * 
 ***********/

/*
 * Minimal solver for now: to test internalization
 */
typedef struct bv_solver_s {
  /*
   * Attached smt core + egraph
   */
  smt_core_t *core;
  egraph_t *egraph;

  /*
   * Base level and decision level
   */
  uint32_t base_level;
  uint32_t decision_level;

  /*
   * Variable + atom tables
   */
  bv_vartable_t vtbl;
  bv_atomtable_t atbl;

  /*
   * Expanded forms
   */
  bvexp_table_t etbl;

  /*
   * Table to merge equal variables
   */
  mtbl_t mtbl;

  /*
   * Bound queue
   */
  bv_bound_queue_t bqueue;

  /*
   * Data structures for bit-blasting
   * - blaster + remap table are allocated on demand
   */
  bit_blaster_t *blaster;
  remap_table_t *remap;

  /*
   * Queue of egraph assertions
   */
  eassertion_queue_t egraph_queue;

  /*
   * Push/pop stack
   */
  bv_trail_stack_t trail_stack;


  /*
   * Auxiliary buffers for internalization and simplification
   */
  bvpoly_buffer_t buffer;
  pp_buffer_t prod_buffer;
  ivector_t aux_vector;
  bvconstant_t aux1;
  bvconstant_t aux2;
  bvconstant_t aux3;

  // buffers for computing expanded forms
  bvarith_buffer_t exp_buffer;
  bvarith64_buffer_t exp64_buffer;

  // buffers for computing intervals
  bv_interval_stack_t intv_stack;

  // buffers for bit-blasting
  ivector_t a_vector;
  ivector_t b_vector;


  /*
   * Sets for generating fresh values
   */
  used_bvval_t used_vals;

  /*
   * Jump buffer for exception handling during internalization
   */
  jmp_buf *env;

} bv_solver_t;



#endif /* __BVSOLVER_TYPES_H */
