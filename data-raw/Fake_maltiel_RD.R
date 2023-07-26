# Maltiel et al RD --------------------------------------------------------

# Simulate ARD from Maltiel et al Random Degree model.

set.seed(666)
s <- 1000 # Sample size
popsize <- 3 * 10^6 # Population size
subpopsizes <- c(1,2,3) * 10^5 # Sub-population sizes
names(subpopsizes) <- paste0("p", seq_along(subpopsizes))
degs <- rlnorm(s, meanlog = 3, sdlog = 1/16) # Degrees
# hist(degs)
Fake_maltiel_RD <- vapply(
  subpopsizes / popsize,
  function(p) rbinom(s, round(degs), p),
  numeric(s)
) |>
  as.data.frame()

usethis::use_data(Fake_maltiel_RD, overwrite = TRUE)
