/*
 * int_mset.c
 *
 *  Created on: Aug 8, 2014
 *      Author: dejan
 */

#include "mcsat/utils/int_mset.h"

#include <stdbool.h>
#include <stddef.h>
#include <assert.h>

void int_mset_construct(int_mset_t* set) {
  init_int_hmap(&set->count_map, 0);
  init_ivector(&set->element_list, 0);
  set->is_compact = true;
  set->size = 0;
}

void int_mset_destruct(int_mset_t* set) {
  delete_int_hmap(&set->count_map);
  delete_ivector(&set->element_list);
}

void int_mset_add(int_mset_t* set, int32_t x) {
  int_hmap_pair_t* find_x;

  find_x = int_hmap_find(&set->count_map, x);
  if (find_x == NULL) {
    // first time
    int_hmap_add(&set->count_map, x, 1);
    ivector_push(&set->element_list, x);
  } else {
    // it was already there
    find_x->val ++;
  }

  set->size ++;
}

uint32_t int_mset_contains(const int_mset_t* set, int32_t x) {
  int_hmap_pair_t* find_x;
  int_hmap_t* set_nonconst;

  set_nonconst = (int_hmap_t*) &set->count_map;
  find_x = int_hmap_find(set_nonconst, x);
  if (find_x == NULL) return 0;
  else return find_x->val;
}

void int_mset_remove(int_mset_t* set, int32_t x) {
  int_hmap_pair_t* find_x;

  assert(int_mset_contains(set, x) > 0);

  find_x = int_hmap_find(&set->count_map, x);
  set->size -= find_x->val;
  find_x->val = 0;
  set->is_compact = false;

}

void int_mset_clear(int_mset_t* set) {
  int_hmap_reset(&set->count_map);
  ivector_reset(&set->element_list);
  set->is_compact = true;
}

void int_mset_compact(int_mset_t* set) {
  uint32_t keep, i;
  int32_t x;
  for (keep = 0, i = 0; i < set->element_list.size; ++ i) {
    x = set->element_list.data[i];
    if (int_mset_contains(set, x)) {
      set->element_list.data[keep ++] = x;
    }
  }
  ivector_shrink(&set->element_list, keep);
  set->is_compact = true;
}

ivector_t* int_mset_get_list(int_mset_t* set) {
  if (!set->is_compact) {
    int_mset_compact(set);
  }
  return &set->element_list;
}