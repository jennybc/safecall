
#include <R.h>
#include <Rinternals.h>

#include "safecall.h"

static void cleanup_free(void *data) {
  Rprintf("free!\n");
  free(data);
}

SEXP testfunc4(SEXP env) {
  SEXP callback = PROTECT(install("callback"));
  SEXP l1 = PROTECT(Rf_lang1(callback));
  SEXP res;

  int *x = malloc(100);
  r_on_exit(cleanup_free, x);

  res = PROTECT(Rf_eval(l1, env));
  UNPROTECT(3);
  return res;
}

SEXP testfunc42() {
  error("oopsie");
}

SEXP testfunc43(SEXP env) {
  SEXP callback = PROTECT(install("callback"));
  SEXP l1 = PROTECT(Rf_lang1(callback));
  SEXP res;
  res = PROTECT(Rf_eval(l1, env));
  UNPROTECT(3);
  return res;
}

SEXP testfunc44() {
  int *x = malloc(100);
  r_on_exit(cleanup_free, x);
  error("oopsie");
}
