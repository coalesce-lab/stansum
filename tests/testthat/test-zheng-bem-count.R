data("Fake_maltiel_RD", package = "stansum")

test_that("Zheng et al BEM works", {
  expect_no_error(
    zheng_bem_count(
      N = nrow(Fake_maltiel_RD),
      K = 3,
      y = data.matrix(Fake_maltiel_RD),
      chains = 1,
      iter_warmup = 5,
      iter_sampling = 5,
      show_messages = FALSE,
      show_exceptions = FALSE,
      diagnostics = NULL
    )
  )
})
