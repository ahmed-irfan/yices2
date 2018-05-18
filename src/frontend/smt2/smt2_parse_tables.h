/*
 * This file is part of the Yices SMT Solver.
 * Copyright (C) 2017 SRI International.
 *
 * Yices is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Yices is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Yices.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Tables for parsing the SMT-LIB 2.0 language
 */

#ifndef __SMT2_PARSE_TABLES_H
#define __SMT2_PARSE_TABLES_H

#include <stdint.h>

/*
 * States
 */
typedef enum state_s {
  c0, c1, c3, c4, c5, c6, c6a, c8, c9, c9a, c9b,
  c10, c10a, c10b, c11, c11a, c11b, c11d, c11f, c12, c12b,
  c13, c14, c15, c16, c16a, c16b, c16c, c16d,
  a0, a1, v0,
  s0, s1, s2, s3, s4, s5, s6, s7, s8, s10,
  t0, t1, t2, t2a, t2b, t2d, t2e,
  t3, t3a, t3b, t3d, t3e,
  t4a, t4b, t4c, t4d, t4e, t4g,
  t5, t5a, t5b, t5c, t5d,
  t6, t6a, t6b, t6c, t6d, t6e, t6g, t6h, t6i, t6j,
  t7, t7a, t7b, t8a,
  r0,
} state_t;


/*
 * Action codes
 */
typedef enum actions {
  // commands
  next_goto_c1,
  empty_command_return,

  assert_next_push_r0_goto_t0,
  check_sat_next_goto_r0,
  check_sat_assuming_next_goto_c16,
  declare_sort_next_goto_c8,
  declare_const_next_goto_c14,
  declare_fun_next_goto_c10,
  define_sort_next_goto_c9,
  define_const_next_goto_c15,
  define_fun_next_goto_c11,
  echo_next_goto_c13,
  exit_next_goto_r0,
  get_assertions_next_goto_r0,
  get_assignment_next_goto_r0,
  get_info_next_goto_c4,
  get_model_next_goto_r0,
  get_option_next_goto_c4,
  get_proof_next_goto_r0,
  get_unsat_assumptions_next_goto_r0,
  get_unsat_core_next_goto_r0,
  get_value_next_goto_c12,
  pop_next_goto_c3,
  push_next_goto_c3,
  set_logic_next_goto_c5,
  set_info_next_goto_c6,
  set_option_next_goto_c6,
  reset_next_goto_r0,
  reset_assertions_next_goto_r0,

  // arguments to the commands
  numeral_next_goto_r0,
  keyword_next_goto_r0,
  symbol_next_goto_r0,
  keyword_next_goto_c6a,
  next_return,
  push_r0_goto_a0,
  symbol_next_goto_c3,
  symbol_next_goto_c9a,
  next_goto_c9b,
  next_push_r0_goto_s0,
  symbol_next_goto_c9b,
  symbol_next_goto_c10a,
  next_goto_c10b,
  push_c10b_goto_s0,
  symbol_next_goto_c11a,
  next_goto_c11b,
  next_push_r0_push_t0_goto_s0,
  next_goto_c11d,
  symbol_next_push_c11f_goto_s0,
  eval_next_goto_c11b,
  next_push_c12b_goto_t0,
  next_goto_r0,
  push_c12b_goto_t0,
  string_next_goto_r0,
  symbol_next_push_r0_goto_s0,
  symbol_next_push_r0_push_t0_goto_s0,
  next_goto_c16a,
  symbol_next_goto_c16a,
  next_goto_c16b,
  not_next_goto_c16c,
  symbol_next_goto_c16d,

  // attribute values + s-expressions
  numeral_next_return,
  decimal_next_return,
  hexadecimal_next_return,
  binary_next_return,
  string_next_return,
  symbol_next_return,
  next_goto_a1,
  push_a1_goto_v0,
  keyword_next_return,

  // sorts
  sort_symbol_next_return,
  next_goto_s1,
  next_goto_s2,
  next_goto_s5,
  symbol_next_push_s10_goto_s0,
  symbol_next_goto_s3,
  numeral_next_goto_s4,
  next_goto_s6,
  symbol_next_goto_s7,
  numeral_next_goto_s8,
  next_push_s10_goto_s0,
  push_s10_goto_s0,

  // terms
  term_symbol_next_return,
  next_goto_t1,
  next_goto_t2,           // (let
  forall_next_goto_t3,    // (forall
  exists_next_goto_t3,    // (exists
  next_push_t4a_goto_t0,  // (!
  next_goto_t5,           // (as
  next_goto_t6,           // ((
  next_goto_t7,           // (_

  // simple function application (<symbol> <term> ... <term>)
  symbol_next_push_t8a_goto_t0,

  // (let ...
  next_goto_t2a,
  next_goto_t2b,
  symbol_next_push_t2d_goto_t0,
  next_goto_t2e,
  next_push_r0_goto_t0,

  // (exists ... and (forall ...
  next_goto_t3a,
  next_goto_t3b,
  symbol_next_push_t3d_goto_s0,
  next_goto_t3e,

  // (! <term> ...
  check_keyword_then_branch,
  push_t4c_goto_a0,
  symbol_next_goto_t4c,
  next_push_t4g_goto_t0,
  next_goto_t4c,
  push_t4g_goto_t0,

  // (as ...
  next_goto_t5a,
  asymbol_next_push_r0_goto_s0,
  next_goto_t5b,
  symbol_next_goto_t5c,
  numeral_next_goto_t5d,

  // (( ...
  next_goto_t6a,
  next_goto_t6h,

  // ((as ...
  next_goto_t6b,
  symbol_next_push_t6g_goto_s0,
  next_goto_t6c,
  symbol_next_goto_t6d,
  numeral_next_goto_t6e,
  next_push_t6g_goto_s0,
  next_push_t8a_goto_t0,

  // ((_ ...
  symbol_next_goto_t6i,
  numeral_next_goto_t6j,

  // (_ ...
  symbol_next_goto_t7a,
  numeral_next_goto_t7b,

  // after <term> in a function application
  push_t8a_goto_t0,

  // errors
  error_lp_expected,
  error_string_expected,
  error_symbol_expected,
  error_numeral_expected,
  error_keyword_expected,
  error_rp_expected,
  error_underscore_expected,
  error_command_expected,
  error_literal_expected,
  error_not_expected,
  error,
} smt2_action_t;



/*
 * Tables generated by table_builder
 * see utils/table_builder.c
 */

// Table sizes
#define NSTATES 80
#define BSIZE 298

// Default values for each state
static const uint8_t default_value[NSTATES] = {
  error_lp_expected,
  error_command_expected,
  error_numeral_expected,
  error_keyword_expected,
  error_symbol_expected,
  error_keyword_expected,
  push_r0_goto_a0,
  error_symbol_expected,
  error_symbol_expected,
  error_lp_expected,
  error,
  error_symbol_expected,
  error_lp_expected,
  push_c10b_goto_s0,
  error_symbol_expected,
  error_lp_expected,
  error,
  error_symbol_expected,
  error_rp_expected,
  error_lp_expected,
  push_c12b_goto_t0,
  error,
  error_symbol_expected,
  error_symbol_expected,
  error_lp_expected,
  error_literal_expected,
  error_not_expected,
  error_symbol_expected,
  error_symbol_expected,
  error,
  push_a1_goto_v0,
  error,
  error,
  error,
  error_symbol_expected,
  error_numeral_expected,
  error,
  error_underscore_expected,
  error_symbol_expected,
  error_numeral_expected,
  error,
  push_s10_goto_s0,
  error,
  error,
  error_lp_expected,
  error_lp_expected,
  error_symbol_expected,
  error_rp_expected,
  error,
  error_lp_expected,
  error_lp_expected,
  error_symbol_expected,
  error_rp_expected,
  error,
  error_keyword_expected,
  push_t4c_goto_a0,
  error,
  error_symbol_expected,
  error_lp_expected,
  push_t4g_goto_t0,
  error,
  error_underscore_expected,
  error_symbol_expected,
  error_numeral_expected,
  error,
  error,
  error,
  error_underscore_expected,
  error_symbol_expected,
  error_numeral_expected,
  error,
  error_rp_expected,
  error_symbol_expected,
  error_numeral_expected,
  error,
  error_symbol_expected,
  error_numeral_expected,
  error,
  push_t8a_goto_t0,
  error_rp_expected,
};

// Base values for each state
static const uint8_t base[NSTATES] = {
     0,   0,   0,   0,  40,   1,   0,   0,  42,   4,
    52,  46,   5,   5,  48,   7,  12,  50,  13,  15,
    15,  10,  10,  54,  20,  65,  44,  56,  66,  97,
    67, 107, 120, 126, 114,  66,  88,  56, 116,  76,
    92,  83, 170, 193,  90,  99, 122, 107, 118, 109,
   121, 150, 132, 138, 126, 144, 180, 189, 140, 146,
   195, 133, 212, 160, 164, 154, 218, 149, 224, 179,
   183, 182, 236, 184, 188, 242, 185, 191, 198, 205,
};

// Check table
static const uint8_t check[BSIZE] = {
     0,   6,   0,   2,   9,  12,  13,  15,   7,   7,
     3,   5,  16,  16,  18,  19,  20,  21,  22,  22,
    24,   1,   1,   1,   1,   1,   1,   1,   1,   1,
     1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
     1,   1,   1,   1,   1,   1,   1,   1,   4,   4,
     8,   8,  26,  10,  11,  11,  14,  14,  17,  17,
    10,  10,  23,  23,  27,  25,  25,  28,  30,  35,
     4,  37,   8,  25,  25,   4,  11,   8,  14,  39,
    17,  11,  10,  14,  41,  17,   4,  10,   8,  36,
    44,  36,  11,  40,  14,  40,  17,  29,  10,  45,
    29,  29,  29,  29,  29,  29,  29,  31,  47,  49,
    31,  31,  31,  31,  31,  31,  31,  31,  48,  48,
    32,  50,  34,  34,  38,  38,  33,  29,  32,  32,
    46,  46,  29,  52,  33,  33,  54,  31,  53,  53,
    58,  33,  31,  29,  34,  55,  38,  59,  61,  34,
    32,  38,  46,  31,  55,  32,  33,  46,  51,  51,
    34,  33,  38,  63,  67,  64,  32,  64,  46,  65,
    42,  65,  33,  42,  42,  42,  42,  42,  42,  42,
    51,  56,  69,  71,  70,  51,  70,  73,  76,  74,
    56,  74,  77,  43,  77,  60,  51,  57,  57,  78,
    42,  43,  43,  60,  60,  42,  79,  80,  43,  43,
    43,  43,  43,  43,  80,  80,  42,  80,  66,  57,
    62,  62,  80,  43,  57,  60,  66,  66,  43,  80,
    60,  80,  68,  68,  80,  57,  80,  80,  80,  43,
    80,  60,  62,  80,  72,  72,  80,  62,  66,  80,
    75,  75,  80,  66,  68,  80,  80,  80,  62,  68,
    80,  80,  80,  80,  66,  80,  72,  80,  80,  80,
    68,  72,  75,  80,  80,  80,  80,  75,  80,  80,
    80,  80,  72,  80,  80,  80,  80,  80,  75,  80,
    80,  80,  80,  80,  80,  80,  80,  80,
};

// Value table
static const uint8_t value[BSIZE] = {
  next_goto_c1,
  next_return,
  empty_command_return,
  numeral_next_goto_r0,
  next_goto_c9b,
  next_goto_c10b,
  next_push_r0_goto_s0,
  next_goto_c11b,
  symbol_next_goto_c3,
  symbol_next_goto_c3,
  keyword_next_goto_r0,
  keyword_next_goto_c6a,
  next_goto_c11d,
  next_push_r0_push_t0_goto_s0,
  eval_next_goto_c11b,
  next_push_c12b_goto_t0,
  next_goto_r0,
  string_next_goto_r0,
  symbol_next_push_r0_goto_s0,
  symbol_next_push_r0_goto_s0,
  next_goto_c16a,
  assert_next_push_r0_goto_t0,
  check_sat_next_goto_r0,
  check_sat_assuming_next_goto_c16,
  declare_sort_next_goto_c8,
  declare_const_next_goto_c14,
  declare_fun_next_goto_c10,
  define_sort_next_goto_c9,
  define_const_next_goto_c15,
  define_fun_next_goto_c11,
  echo_next_goto_c13,
  exit_next_goto_r0,
  get_assertions_next_goto_r0,
  get_assignment_next_goto_r0,
  get_info_next_goto_c4,
  get_model_next_goto_r0,
  get_option_next_goto_c4,
  get_proof_next_goto_r0,
  get_unsat_assumptions_next_goto_r0,
  get_unsat_core_next_goto_r0,
  get_value_next_goto_c12,
  pop_next_goto_c3,
  push_next_goto_c3,
  set_logic_next_goto_c5,
  set_info_next_goto_c6,
  set_option_next_goto_c6,
  reset_next_goto_r0,
  reset_assertions_next_goto_r0,
  symbol_next_goto_r0,
  symbol_next_goto_r0,
  symbol_next_goto_c9a,
  symbol_next_goto_c9a,
  not_next_goto_c16c,
  next_push_r0_goto_s0,
  symbol_next_goto_c10a,
  symbol_next_goto_c10a,
  symbol_next_goto_c11a,
  symbol_next_goto_c11a,
  symbol_next_push_c11f_goto_s0,
  symbol_next_push_c11f_goto_s0,
  symbol_next_goto_c9b,
  symbol_next_goto_c9b,
  symbol_next_push_r0_push_t0_goto_s0,
  symbol_next_push_r0_push_t0_goto_s0,
  symbol_next_goto_c16d,
  next_goto_c16b,
  next_goto_r0,
  next_goto_c16a,
  next_return,
  numeral_next_goto_s4,
  symbol_next_goto_r0,
  next_goto_s6,
  symbol_next_goto_c9a,
  symbol_next_goto_c16a,
  symbol_next_goto_c16a,
  symbol_next_goto_r0,
  symbol_next_goto_c10a,
  symbol_next_goto_c9a,
  symbol_next_goto_c11a,
  numeral_next_goto_s8,
  symbol_next_push_c11f_goto_s0,
  symbol_next_goto_c10a,
  symbol_next_goto_c9b,
  symbol_next_goto_c11a,
  next_return,
  symbol_next_push_c11f_goto_s0,
  symbol_next_goto_r0,
  symbol_next_goto_c9b,
  symbol_next_goto_c9a,
  next_return,
  next_goto_t2a,
  numeral_next_goto_s4,
  symbol_next_goto_c10a,
  next_push_s10_goto_s0,
  symbol_next_goto_c11a,
  numeral_next_goto_s8,
  symbol_next_push_c11f_goto_s0,
  next_goto_a1,
  symbol_next_goto_c9b,
  next_goto_t2b,
  numeral_next_return,
  decimal_next_return,
  hexadecimal_next_return,
  binary_next_return,
  string_next_return,
  symbol_next_return,
  symbol_next_return,
  next_goto_a1,
  next_goto_t2e,
  next_goto_t3a,
  numeral_next_return,
  decimal_next_return,
  hexadecimal_next_return,
  binary_next_return,
  string_next_return,
  symbol_next_return,
  symbol_next_return,
  keyword_next_return,
  next_goto_t2b,
  next_push_r0_goto_t0,
  next_goto_s1,
  next_goto_t3b,
  symbol_next_goto_s3,
  symbol_next_goto_s3,
  symbol_next_goto_s7,
  symbol_next_goto_s7,
  next_goto_s5,
  symbol_next_return,
  sort_symbol_next_return,
  sort_symbol_next_return,
  symbol_next_push_t2d_goto_t0,
  symbol_next_push_t2d_goto_t0,
  symbol_next_return,
  next_goto_t3e,
  symbol_next_push_s10_goto_s0,
  symbol_next_push_s10_goto_s0,
  check_keyword_then_branch,
  symbol_next_return,
  next_goto_t3b,
  next_push_r0_goto_t0,
  next_push_t4g_goto_t0,
  next_goto_s2,
  symbol_next_return,
  symbol_next_return,
  symbol_next_goto_s3,
  next_return,
  symbol_next_goto_s7,
  next_goto_t4c,
  next_goto_t5b,
  symbol_next_goto_s3,
  sort_symbol_next_return,
  symbol_next_goto_s7,
  symbol_next_push_t2d_goto_t0,
  symbol_next_return,
  check_keyword_then_branch,
  sort_symbol_next_return,
  symbol_next_push_s10_goto_s0,
  symbol_next_push_t2d_goto_t0,
  symbol_next_push_t3d_goto_s0,
  symbol_next_push_t3d_goto_s0,
  symbol_next_goto_s3,
  symbol_next_push_s10_goto_s0,
  symbol_next_goto_s7,
  numeral_next_goto_t5d,
  next_goto_t6c,
  next_push_r0_goto_s0,
  sort_symbol_next_return,
  numeral_next_goto_t5d,
  symbol_next_push_t2d_goto_t0,
  next_goto_t6h,
  next_goto_t1,
  next_goto_t6a,
  symbol_next_push_s10_goto_s0,
  numeral_next_return,
  decimal_next_return,
  hexadecimal_next_return,
  binary_next_return,
  string_next_return,
  term_symbol_next_return,
  term_symbol_next_return,
  symbol_next_push_t3d_goto_s0,
  next_return,
  numeral_next_goto_t6e,
  next_push_t8a_goto_t0,
  next_push_t6g_goto_s0,
  symbol_next_push_t3d_goto_s0,
  numeral_next_goto_t6e,
  numeral_next_goto_t6j,
  numeral_next_goto_t7b,
  next_push_t8a_goto_t0,
  check_keyword_then_branch,
  numeral_next_goto_t6j,
  next_return,
  next_goto_t6,
  numeral_next_goto_t7b,
  next_goto_t5a,
  symbol_next_push_t3d_goto_s0,
  symbol_next_goto_t4c,
  symbol_next_goto_t4c,
  next_return,
  term_symbol_next_return,
  symbol_next_push_t8a_goto_t0,
  symbol_next_push_t8a_goto_t0,
  asymbol_next_push_r0_goto_s0,
  asymbol_next_push_r0_goto_s0,
  term_symbol_next_return,
  next_return,
  error,
  next_goto_t7,
  next_push_t4a_goto_t0,
  next_goto_t5,
  next_goto_t2,
  exists_next_goto_t3,
  forall_next_goto_t3,
  error,
  error,
  term_symbol_next_return,
  error,
  next_goto_t6b,
  symbol_next_goto_t4c,
  symbol_next_goto_t5c,
  symbol_next_goto_t5c,
  error,
  symbol_next_push_t8a_goto_t0,
  symbol_next_goto_t4c,
  asymbol_next_push_r0_goto_s0,
  symbol_next_push_t6g_goto_s0,
  symbol_next_push_t6g_goto_s0,
  symbol_next_push_t8a_goto_t0,
  error,
  asymbol_next_push_r0_goto_s0,
  error,
  symbol_next_goto_t6d,
  symbol_next_goto_t6d,
  error,
  symbol_next_goto_t4c,
  error,
  error,
  error,
  symbol_next_push_t8a_goto_t0,
  error,
  asymbol_next_push_r0_goto_s0,
  symbol_next_goto_t5c,
  error,
  symbol_next_goto_t6i,
  symbol_next_goto_t6i,
  error,
  symbol_next_goto_t5c,
  symbol_next_push_t6g_goto_s0,
  error,
  symbol_next_goto_t7a,
  symbol_next_goto_t7a,
  error,
  symbol_next_push_t6g_goto_s0,
  symbol_next_goto_t6d,
  error,
  error,
  error,
  symbol_next_goto_t5c,
  symbol_next_goto_t6d,
  error,
  error,
  error,
  error,
  symbol_next_push_t6g_goto_s0,
  error,
  symbol_next_goto_t6i,
  error,
  error,
  error,
  symbol_next_goto_t6d,
  symbol_next_goto_t6i,
  symbol_next_goto_t7a,
  error,
  error,
  error,
  error,
  symbol_next_goto_t7a,
  error,
  error,
  error,
  error,
  symbol_next_goto_t6i,
  error,
  error,
  error,
  error,
  error,
  symbol_next_goto_t7a,
  error,
  error,
  error,
  error,
  error,
  error,
  error,
  error,
  error,
};

#endif /* __SMT2_PARSE_TABLES_H */
