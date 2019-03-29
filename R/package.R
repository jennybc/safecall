
#' Correct Resource Cleaup in C Code
#'
#' Correct Resource Cleaup in C Code
#'
#' @docType package
#' @name ccleanup
#' @useDynLib ccleanup, .registration = TRUE
NULL

cleanup_test <- function() {
  .Call(wrapper1)
}
