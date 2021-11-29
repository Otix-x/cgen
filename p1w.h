#ifndef P1W_H_
#define P1W_H_

#include "arr.h"
#include "gtype.h"

typedef struct p1w_s {
  arr_t(gtype) data;
  gtype_cmp_t cmp;
} *p1w_t;

p1w_t create_p1w(gtype_cmp_t cmp);
p1w_t p1w_from_arr(arr_t(gtype) arr, gtype_cmp_t cmp);
p1w_t p1w_from_arr2(gtype* a, long n, gtype_cmp_t cmp);
gtype p1w_peek(p1w_t h);
gtype p1w_dequeue(p1w_t h);
int p1w_enqueue(p1w_t h, gtype value);
long p1w_size(p1w_t h);
gtype *p1w_arr(p1w_t h);

#define p1w_is_empty(h) \
  (p1w_size(h) == 0)

#define p1w_free(h) \
  do { \
    arr_free(h->data); \
    free(h); \
  } while (0)

#define P1WARR(h) (ARR(h->data))

#endif  // P1W_H_