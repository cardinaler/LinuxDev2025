#include <check.h>
#include "buf.h"


float * a;
long *ai;

#test capacity_init
    a = 0;
    ck_assert_int_eq(buf_capacity(a), 0);
    buf_free(a);


#test size_init
    a = 0;
    ck_assert_int_eq(buf_size(a), 0);
    buf_free(a);


#test size_1
    a = 0;
    buf_push(a, 1.3f);
    ck_assert_int_eq(buf_size(a), 1);
    buf_free(a);

#test value
    a = 0;
    buf_push(a, 1.3f);
    ck_assert_float_eq(a[0], (float)1.3f);
    buf_free(a);    

#test clear
    a = 0;
    buf_push(a, 1.3f);
    buf_clear(a);
    ck_assert_int_eq(buf_size(a), 0);
    buf_free(a);

#test clear_not_free
    a = 0;
    buf_push(a, 1.3f);
    buf_clear(a);
    ck_assert_ptr_nonnull(a);
    buf_free(a);

#test free_
    a = 0;
    buf_push(a, 1.3f);
    buf_clear(a);
    buf_free(a);
    ck_assert_ptr_null(a);

#test clear_empty
    a = 0;
    buf_clear(a);
    ck_assert_int_eq(buf_size(a), 0);

#test clear_no_op
    a = 0;
    buf_clear(a);
    ck_assert_ptr_null(a);

#test size_10000
    ai = 0;
    for (int i = 0; i < 10000; i++)
        buf_push(ai, i);
    ck_assert_int_eq(buf_size(ai), 10000);
    buf_free(ai);

#test match_10000
    ai = 0;
    for (int i = 0; i < 10000; i++)
        buf_push(ai, i);
    int match = 0;
    for (int i = 0; i < (int)(buf_size(ai)); i++)
        match += ai[i] == i;
    ck_assert_int_eq(match, 10000);
    buf_free(ai);

#test grow_1000
    ai = 0;
    buf_grow(ai, 1000);
    ck_assert_int_eq(buf_capacity(ai), 1000);
    buf_free(ai);

#test size_0_grow
    ai = 0;
    buf_grow(ai, 1000);
    ck_assert_int_eq(buf_size(ai), 0);
    buf_free(ai);

#test trunc_100
    ai = 0;
    buf_grow(ai, 1000);
    buf_trunc(ai, 100);
    ck_assert_int_eq(buf_capacity(ai), 100);
    buf_free(ai);

#test size_4
    a = 0;
    buf_push(a, 1.1);
    buf_push(a, 1.2);
    buf_push(a, 1.3);
    buf_push(a, 1.4);
    ck_assert_int_eq(buf_size(a), 4);
    buf_free(a);


#test size_3
    a = 0;
    buf_push(a, 1.1);
    buf_push(a, 1.2);
    buf_push(a, 1.3);
    buf_push(a, 1.4);
    buf_pop(a);
    buf_trunc(a, 3);
    ck_assert_int_eq(buf_size(a), 3);
    buf_free(a);

#test pops
    a = 0;
    buf_push(a, 1.1);
    buf_push(a, 1.2);
    buf_push(a, 1.3);
    buf_push(a, 1.4);
    ck_assert_float_eq(buf_pop(a), (float)1.4f);
    buf_trunc(a, 3);
    ck_assert_float_eq(buf_pop(a), (float)1.3f);
    ck_assert_float_eq(buf_pop(a), (float)1.2f);
    ck_assert_float_eq(buf_pop(a), (float)1.1f);
    ck_assert_int_eq(buf_size(a), 0);




