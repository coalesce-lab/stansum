data("Fake_maltiel_RD", package = "stansum")

test_that("combined model for counts works", {
  skip_on_cran()
  y <- data.matrix(Fake_maltiel_RD)[1:50, ]
  K <- ncol(y)
  expect_no_error(
    r <- maltiel_cm_count(
      N = nrow(y),
      K = K,
      y = y,
      m = rep(0.01, K),
      L = apply(y, 1, max),
      eta = rep(1, K),
      v = rep(1, K),
      chains = 1,
      iter_warmup = 200,
      iter_sampling = 10
    )
  )
})
