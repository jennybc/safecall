
cleanup_test <- function() {
  safecall(testfunc1, "foo", 1:10)
}

cleanup_test2 <- function() {
  safecall(testfunc2, "foo", 1:10)
}
