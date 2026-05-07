data("Fake_maltiel_RD", package = "stansum")

test_that("transmission bias count model works", {
  skip_on_cran()
  K <- ncol(Fake_maltiel_RD)
  expect_no_error(
    r <- maltiel_tbm_count(
      N = nrow(Fake_maltiel_RD),
      K = K,
      y = data.matrix(Fake_maltiel_RD),
      m = rep(0.01, K),
      L = apply(data.matrix(Fake_maltiel_RD), 1, max),
      eta = rep(1, K),
      v = rep(1, K),
      chains = 1,
      iter_warmup = 5,
      iter_sampling = 5
    )
  )
})
