#' Maltiel et al Transmission Bias Model
#'
#' @name maltiel_tbm
#'
#' @description Bayesian model for ARD with transmission bias parameters.
#'
#' @template wrapped-stan-model
#'
#' @references Maltiel, R., Raftery, A. E., McCormick, T. H., & Baraff, A.
#'   J. (2015). Estimating Population Size Using the Network Scale Up
#'   Method. *The Annals of Applied Statistics*, 9(3), 1247–1277.
#'   \doi{10.1214/15-AOAS827}
#'
#' @family models of Maltiel et al (2015)




#' @rdname maltiel_tbm
#'
#' @description - `maltiel_tbm_count` -- transmission bias model for count
#'   responses. All `tau_k` are estimated from the data.
#'
#' @param N integer; population size
#' @param K integer; number of sub-populations
#' @param y numeric matrix; ARD counts (N x K)
#' @param m numeric vector; fractional sub-population sizes (length K)
#' @param L numeric vector; lower bounds on individual degrees (length N).
#'   Must satisfy `L[i] >= max(y[i,])` for each respondent `i` so that the
#'   degree is always at least as large as the maximum observed count.
#' @param eta numeric vector; Beta prior shape 1 for each transmission bias
#'   (length K)
#' @param v numeric vector; Beta prior shape 2 for each transmission bias
#'   (length K)
#' @param ... other arguments passed to [cmdstanr::sample()]
#'
#' @export
#'
#' @examples
#' data("Fake_maltiel_RD", package = "stansum")
#' K <- ncol(Fake_maltiel_RD)
#' r <- maltiel_tbm_count(
#'   N = nrow(Fake_maltiel_RD),
#'   K = K,
#'   y = data.matrix(Fake_maltiel_RD),
#'   m = rep(0.01, K),
#'   L = apply(data.matrix(Fake_maltiel_RD), 1, max),
#'   eta = rep(1, K),
#'   v = rep(1, K),
#'   chains = 1,
#'   iter_warmup = 200,
#'   iter_sampling = 10
#' )
#'
maltiel_tbm_count <- function(N, K, y, m, L, eta, v, ...) {
  mod <- get_model("MaltielTBM_count")
  d <- list(N = N, K = K, y = y, m = m, L = L, eta = eta, v = v)
  mod$sample(data = d, ...)
}
