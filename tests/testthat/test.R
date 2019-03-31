
context("safecall")

split_lines <- function(x) strsplit(x, "\r?\n")[[1]]
rimraf <- function(x) unlink(x, recursive = TRUE, force = TRUE)

test_that("safecall works", {
  on.exit(rimraf(tmp1), add = TRUE)
  out <- capture_output(x <- safecall(testfunc1, tmp1 <- tempfile(), 1:10))
  expect_identical(x, 42L)
  expect_equal(
    split_lines(out),
    c("close!", "free!", "free!"))
  expect_true(file.exists(tmp1))

  on.exit(rimraf(tmp2), add = TRUE)
  out <- capture_output(
    expect_error(safecall(testfunc2, tmp2 <- tempfile(), 1:10),"oops"))
  expect_equal(
    split_lines(out),
    c("close!", "free!", "free!"))
  expect_true(file.exists(tmp2))
})

test_that("arg check", {
  expect_error(
    safecall("foobar"),
    "Not a .Call routine")
})

test_that("r_on_exit without safecall", {
  tmp1 <- tempfile()
  on.exit(rimraf(tmp1), add = TRUE)
  out <- capture_output(expect_error(
    .Call(testfunc1, tmp1, 1:10),
    "r_on_exit must be called from within"))
  expect_equal(split_lines(out), "free!")
})

test_that("cleanup stack full, cleanup proper", {
  out <- capture_output(
    expect_error(safecall(testfunc3, 200L), "Cleanup stack full"))
  expect_equal(split_lines(out), "free!")
})

test_that("various number of arguments", {
  for (i in 0:30) {
    nr <- get(paste0("argtest", i))
    r <- do.call(safecall, c(list(nr), as.list(seq_len(i))))
    expect_identical(r, sum(seq_len(i)))
  }
})
