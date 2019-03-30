
#' Correct Resource Cleaup in C Code
#'
#' Correct Resource Cleaup in C Code
#'
#' @docType package
#' @name safecall
#' @useDynLib safecall,.registration = TRUE
NULL

cleanup_test <- function() {
  .Call(xwrapper1)
}

cleanup_test2 <- function() {
  .Call(xwrapper2)
}
