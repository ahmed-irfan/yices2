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
 
#include "mcsat/value.h"

#include <assert.h>

#include "utils/memalloc.h"
#include "utils/hash_functions.h"

const mcsat_value_t mcsat_value_none = { VALUE_NONE, { true } };
const mcsat_value_t mcsat_value_true = { VALUE_BOOLEAN, { true } };
const mcsat_value_t mcsat_value_false = { VALUE_BOOLEAN, { false } };

void mcsat_value_construct_default(mcsat_value_t* value) {
  value->type = VALUE_NONE;
}

void mcsat_value_construct_bool(mcsat_value_t* value, bool b) {
  value->type = VALUE_BOOLEAN;
  value->b = b;
}

void mcsat_value_construct_rational(mcsat_value_t* value, const rational_t* q) {
  value->type = VALUE_RATIONAL;
  q_init(&value->q);
  q_set(&value->q, q);
}

void mcsat_value_construct_lp_value(mcsat_value_t* value, const lp_value_t* lp_value) {
  value->type = VALUE_LIBPOLY;
  lp_value_construct_copy(&value->lp_value, lp_value);
}

void mcsat_value_construct_bv_value(mcsat_value_t* value, const bvconstant_t* bvvalue) {
  value->type = VALUE_BV;
  init_bvconstant(&value->bv_value);
  bvconstant_copy(&value->bv_value, bvvalue->bitsize, bvvalue->data);
}

void mcsat_value_construct_copy(mcsat_value_t* value, const mcsat_value_t* from) {
  value->type = from->type;
  switch (value->type) {
  case VALUE_NONE:
    break;
  case VALUE_BOOLEAN:
    value->b = from->b;
    break;
  case VALUE_RATIONAL:
    q_init(&value->q);
    q_set(&value->q, &from->q);
    break;
  case VALUE_LIBPOLY:
    lp_value_construct_copy(&value->lp_value, &from->lp_value);
    break;
  case VALUE_BV:
    init_bvconstant(&value->bv_value);
    bvconstant_copy(&value->bv_value, from->bv_value.bitsize, from->bv_value.data);
    break;
  default:
    assert(false);
  }
}

/** Construct a MCSAT value from a constant term */
void mcsat_value_construct_from_constant_term(mcsat_value_t* t_value, term_table_t* terms, term_t t) {
  term_kind_t t_kind = term_kind(terms, t);
  switch (t_kind) {
  case BV_CONSTANT: {
    bvconst_term_t* t_desc = bvconst_term_desc(terms, t);
    bvconstant_t t_bvconst;
    init_bvconstant(&t_bvconst);
    bvconstant_set_bitsize(&t_bvconst, t_desc->bitsize);
    bvconstant_copy(&t_bvconst, t_desc->bitsize, t_desc->data);
    mcsat_value_construct_bv_value(t_value, &t_bvconst);
    delete_bvconstant(&t_bvconst);
    break;
  }
  case BV64_CONSTANT: {
    // Propagate constant value (it's first time we see it, so should be safe
    bvconst64_term_t* t_desc = bvconst64_term_desc(terms, t);
    bvconstant_t t_bvconst;
    init_bvconstant(&t_bvconst);
    bvconstant_set_bitsize(&t_bvconst, t_desc->bitsize);
    bvconstant_copy64(&t_bvconst, t_desc->bitsize, t_desc->value);
    mcsat_value_construct_bv_value(t_value, &t_bvconst);
    delete_bvconstant(&t_bvconst);
    break;
  }
  case CONSTANT_TERM: {
    assert(t == true_term || t == false_term);
    mcsat_value_construct_bool(t_value, t == true_term);
    break;
  }
  default:
    assert(false);
  }
}


mcsat_value_t* mcsat_value_new_default() {
  mcsat_value_t* result = (mcsat_value_t*) safe_malloc(sizeof(mcsat_value_t));
  mcsat_value_construct_default(result);
  return result;
}

mcsat_value_t* mcsat_value_new_bool(bool b) {
  mcsat_value_t* result = (mcsat_value_t*) safe_malloc(sizeof(mcsat_value_t));
  mcsat_value_construct_bool(result, b);
  return result;
}

mcsat_value_t* mcsat_value_new_rational(const rational_t *q) {
  mcsat_value_t* result = (mcsat_value_t*) safe_malloc(sizeof(mcsat_value_t));
  mcsat_value_construct_rational(result, q);
  return result;
}

mcsat_value_t* mcsat_value_new_lp_value(const lp_value_t *lp_value) {
  mcsat_value_t* result = (mcsat_value_t*) safe_malloc(sizeof(mcsat_value_t));
  mcsat_value_construct_lp_value(result, lp_value);
  return result;
}

mcsat_value_t* mcsat_value_new_bv_value(const bvconstant_t *bv_value) {
  mcsat_value_t* result = (mcsat_value_t*) safe_malloc(sizeof(mcsat_value_t));
  mcsat_value_construct_bv_value(result, bv_value);
  return result;
}

mcsat_value_t* mcsat_value_new_copy(const mcsat_value_t *from) {
  mcsat_value_t* result = (mcsat_value_t*) safe_malloc(sizeof(mcsat_value_t));
  mcsat_value_construct_copy(result, from);
  return result;
}

void mcsat_value_destruct(mcsat_value_t* value) {
  switch (value->type) {
  case VALUE_NONE:
    break;
  case VALUE_BOOLEAN:
    break;
  case VALUE_RATIONAL:
    q_clear(&value->q);
    break;
  case VALUE_LIBPOLY:
    lp_value_destruct(&value->lp_value);
    break;
  case VALUE_BV:
    delete_bvconstant(&value->bv_value);
    break;
  default:
    assert(false);
  }
}

void mcsat_value_delete(mcsat_value_t* value) {
  mcsat_value_destruct(value);
  safe_free(value);
}

void mcsat_value_assign(mcsat_value_t* value, const mcsat_value_t* from) {
  if (value != from) {
    mcsat_value_destruct(value);
    mcsat_value_construct_copy(value, from);
  }
}

void mcsat_value_print(const mcsat_value_t* value, FILE* out) {
  switch (value->type) {
  case VALUE_NONE:
    fprintf(out, "<NONE>");
    break;
  case VALUE_BOOLEAN:
    if (value->b) {
      fprintf(out, "true");
    } else {
      fprintf(out, "false");
    }
    break;
  case VALUE_RATIONAL:
    q_print(out, (rational_t*) &value->q);
    break;
  case VALUE_LIBPOLY:
    lp_value_print(&value->lp_value, out);
    break;
  case VALUE_BV:
    bvconst_print(out, value->bv_value.data, value->bv_value.bitsize);
    break;
  default:
    assert(false);
  }
}

bool mcsat_value_eq(const mcsat_value_t* v1, const mcsat_value_t* v2) {
  assert(v1->type == v2->type);
  if (v1 == v2) {
    return true;
  }
  switch (v1->type) {
  case VALUE_BOOLEAN:
    return v1->b == v2->b;
  case VALUE_RATIONAL:
    if (v2->type == VALUE_RATIONAL) {
      return q_cmp(&v1->q, &v2->q) == 0;
    } else {
      assert(v2->type == VALUE_LIBPOLY);
      mpq_t v1_mpq;
      mpq_init(v1_mpq);
      q_get_mpq((rational_t*)&v1->q, v1_mpq);
      lp_value_t v1_lp;
      lp_value_construct_none(&v1_lp);
      lp_value_assign_raw(&v1_lp, LP_VALUE_RATIONAL, &v1_mpq);
      int cmp = lp_value_cmp(&v1_lp, &v2->lp_value);
      lp_value_destruct(&v1_lp);
      mpq_clear(v1_mpq);
      return cmp == 0;
    }
  case VALUE_LIBPOLY:
    if (v2->type == VALUE_LIBPOLY) {
      return lp_value_cmp(&v1->lp_value, &v2->lp_value) == 0;
    } else {
      assert(v1->type == VALUE_RATIONAL);
      mpq_t v2_mpq;
      mpq_init(v2_mpq);
      q_get_mpq((rational_t*)&v2->q, v2_mpq);
      lp_value_t v2_lp;
      lp_value_construct_none(&v2_lp);
      lp_value_assign_raw(&v2_lp, LP_VALUE_RATIONAL, &v2_mpq);
      int cmp = lp_value_cmp(&v1->lp_value, &v2_lp);
      lp_value_destruct(&v2_lp);
      mpq_clear(v2_mpq);
      return cmp == 0;
    }
  case VALUE_BV: {
    assert(v1->bv_value.bitsize == v2->bv_value.bitsize);
    return bvconst_eq(v1->bv_value.data, v2->bv_value.data, v1->bv_value.width);
  }
  default:
    assert(false);
    return false;
  }
}

uint32_t mcsat_value_hash(const mcsat_value_t* v) {
  switch (v->type) {
  case VALUE_BOOLEAN:
    return v->b;
  case VALUE_RATIONAL:
  {
    mpq_t v_mpq;
    mpq_init(v_mpq);
    q_get_mpq((rational_t*)&v->q, v_mpq);
    lp_value_t v_lp;
    lp_value_construct_none(&v_lp);
    lp_value_assign_raw(&v_lp, LP_VALUE_RATIONAL, &v_mpq);
    uint32_t hash = lp_value_hash(&v_lp);
    lp_value_destruct(&v_lp);
    mpq_clear(v_mpq);
    return hash;
  }
  case VALUE_LIBPOLY:
    return lp_value_hash(&v->lp_value);
  case VALUE_BV: {
    bvconst_normalize(v->bv_value.data, v->bv_value.bitsize);
    return bvconst_hash(v->bv_value.data, v->bv_value.bitsize);
  }
  default:
    assert(false);
    return 0;
  }
}

value_t mcsat_value_to_value(mcsat_value_t* mcsat_value, type_table_t *types, type_t type, value_table_t* vtbl) {
  value_t value = null_value;
  switch (mcsat_value->type) {
  case VALUE_BOOLEAN:
    value = vtbl_mk_bool(vtbl, mcsat_value->b);
    break;
  case VALUE_RATIONAL:
    if (type_kind(types, type) == UNINTERPRETED_TYPE) {
      int32_t id;
      bool ok = q_get32(&mcsat_value->q, &id);
      (void) ok; // unused in release build
      assert(ok);
      value = vtbl_mk_const(vtbl, type, id, NULL);
    } else {
      value = vtbl_mk_rational(vtbl, &mcsat_value->q);
    }
    break;
  case VALUE_LIBPOLY:
    if (lp_value_is_rational(&mcsat_value->lp_value)) {
      lp_rational_t lp_q;
      lp_rational_construct(&lp_q);
      lp_value_get_rational(&mcsat_value->lp_value, &lp_q);
      rational_t q;
      q_init(&q);
      q_set_mpq(&q, &lp_q);
      value = vtbl_mk_rational(vtbl, &q);
      q_clear(&q);
      lp_rational_destruct(&lp_q);
    } else {
      value = vtbl_mk_algebraic(vtbl, &mcsat_value->lp_value.value.a);
    }
    break;
  case VALUE_BV:
    value = vtbl_mk_bv_from_bv(vtbl, mcsat_value->bv_value.bitsize, mcsat_value->bv_value.data);
    break;
  default:
    assert(false);
  }
  return value;
}

bool mcsat_value_is_zero(const mcsat_value_t* value) {
  switch (value->type) {
  case VALUE_RATIONAL:
    return q_is_zero(&value->q);
  case VALUE_LIBPOLY: {
    lp_rational_t zero;
    lp_rational_construct(&zero);
    int cmp = lp_value_cmp_rational(&value->lp_value, &zero);
    lp_rational_destruct(&zero);
    return cmp == 0;
  }
  default:
    return false;
  }
}

bool mcsat_value_is_true(const mcsat_value_t* value) {
  return value->type == VALUE_BOOLEAN && value->b;
}

bool mcsat_value_is_false(const mcsat_value_t* value) {
  return value->type == VALUE_BOOLEAN && !value->b;
}
