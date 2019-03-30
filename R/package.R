
#' Correct Resource Cleaup in C Code
#'
#' Correct Resource Cleaup in C Code
#'
#' @docType package
#' @name safecall
#' @useDynLib safecall,.registration = TRUE
NULL

safecall <- function(cfun, ...) {
  if (!inherits(cfun, "CallRoutine") ||
      !inherits(cfun$address, "RegisteredNativeSymbol")) {
    stop("Not a .Call routine")
  }
  .Call(c_safecall, cfun$address, cfun$numParameters, list(...))
}
