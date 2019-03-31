
#include "../inst/include/safecall.h"

#include <R.h>
#include <Rinternals.h>

#include <fcntl.h>
#include <unistd.h>

DEFINE_ON_EXIT

void cleanup_free(void *data) {
  Rprintf("free!\n");
  free(data);
}

void cleanup_file(void *data) {
  int fd = *(int*)(data);
  Rprintf("close!\n");
  close(fd);
}

SEXP testfunc1(SEXP arg1, SEXP arg2) {
  char *x = malloc(100);
  on_exit(cleanup_free, x);
  int *fd = malloc(1);
  on_exit(cleanup_free, fd);
  *fd = open(CHAR(STRING_ELT(arg1, 0)), O_WRONLY | O_CREAT);
  on_exit(cleanup_file, fd);
  return ScalarInteger(42);
}

SEXP testfunc2(SEXP arg1, SEXP arg2) {
  char *x = malloc(100);
  on_exit(cleanup_free, x);
  int *fd = malloc(1);
  on_exit(cleanup_free, fd);
  *fd = open(CHAR(STRING_ELT(arg1, 0)), O_WRONLY | O_CREAT);
  on_exit(cleanup_file, fd);

  error("oops");
 /* # nocov start */
  return R_NilValue;
}
/* # nocov end */

void clean_null(void *data) {
  /* Do nothing */
}

SEXP testfunc3(SEXP num) {
  int cnum = INTEGER(num)[0];
  int i;
  char *x = malloc(100);
  on_exit(cleanup_free, x);
  for (i = 0; i < cnum; i++) {
    on_exit(clean_null, 0);
  }

  return ScalarInteger(i);
}
