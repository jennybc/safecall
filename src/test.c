
#include "ccleanup.h"

void cleanup_free(void *data) {
  REprintf("free!\n");
  free(data);
}

SEXP testfunc1(SEXP arg1, SEXP arg2) {
  char *x = malloc(100);
  on_exit(cleanup_free, x);
  return ScalarInteger(42);
}

SEXP testfunc2(SEXP arg1, SEXP arg2) {
  char *x = malloc(100);
  on_exit(cleanup_free, x);
  error("oops");
  return R_NilValue;
}
