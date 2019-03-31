
#include "../inst/include/safecall.h"

#include <R.h>
#include <Rinternals.h>

#include <fcntl.h>
#include <unistd.h>

DEFINE_ON_EXIT

void cleanup_free(void *data) {
  REprintf("free!\n");
  free(data);
}

void cleanup_file(void *data) {
  int fd = *(int*)(data);
  REprintf("close!\n");
  close(fd);
}

SEXP testfunc1(SEXP arg1, SEXP arg2) {
  char *x = malloc(100);
  on_exit(cleanup_free, x);
  int *fd = malloc(1);
  on_exit(cleanup_free, fd);
  *fd = open("foobar", O_WRONLY | O_CREAT);
  on_exit(cleanup_file, fd);
  return ScalarInteger(42);
}

SEXP testfunc2(SEXP arg1, SEXP arg2) {
  char *x = malloc(100);
  on_exit(cleanup_free, x);
  int *fd = malloc(1);
  on_exit(cleanup_free, fd);
  *fd = open("foobar", O_WRONLY | O_CREAT);
  on_exit(cleanup_file, fd);

  error("oops");
  return R_NilValue;
}
