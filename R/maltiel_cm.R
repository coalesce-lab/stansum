#' Maltiel et al (2015) Combined Model
#'
#' @name maltiel_cm
#'
#' @description Bayesian model for ARD with both barrier effect and
#'   transmission bias parameters.
#'
#' @template wrapped-stan-model
#'
#' @references Maltiel, R., Raftery, A. E., McCormick, T. H., & Baraff, A.
#'   J. (2015). Estimating Population Size Using the Network Scale Up
#'   Method. *The Annals of Applied Statistics*, 9(3), 1247–1277.
#'   \doi{10.1214/15-AOAS827}
#'
#' @family models of Maltiel et al (2015)




#' @rdname maltiel_cm
#'
#' @description - `maltiel_cm_count` -- combined model for count responses, as
#'   described in section 2.4 of Maltiel et al (2015). It carries both the
#'   per-sub-population overdispersion `rho_k` of the barrier effects model and
#'   the transmission bias `tau_k` of the transmission bias model:
#'   `y_ik ~ Binomial(d_i, tau_k * q_ik)` with `d_i ~ LogNormal(mu, sigma^2)`
#'   and `q_ik ~ Beta(m_k, rho_k)`. Multiplying `q_ik` by `tau_k` breaks the
#'   Beta-Binomial conjugacy, so -- unlike [maltiel_bem_count()] -- the latent
#'   `q_ik` cannot be integrated out and are sampled together with the
#'   remaining parameters. This adds `N * K` parameters, so fits are
#'   substantially slower than for the component models.
#'
#' @details The transmission biases `tau_k` and the degrees `d_i` are only
#'   weakly identified from ARD alone: scaling `tau_k` down and the degrees up
#'   leaves the reported counts largely unchanged. The `eta` / `v` prior on
#'   `tau` is what resolves this, so an uninformative `eta = v = 1` will
#'   typically pull the posterior for `tau` below 1 and inflate the estimated
#'   degrees. Supply an informative prior reflecting what is known about
#'   transmission for each sub-population.
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
#' y <- data.matrix(Fake_maltiel_RD)[1:50, ]
#' K <- ncol(y)
#' r <- maltiel_cm_count(
#'   N = nrow(y),
#'   K = K,
#'   y = y,
#'   m = rep(0.01, K),
#'   L = apply(y, 1, max),
#'   eta = rep(1, K),
#'   v = rep(1, K),
#'   chains = 1,
#'   iter_warmup = 200,
#'   iter_sampling = 10
#' )
#'
maltiel_cm_count <- function(N, K, y, m, L, eta, v, ...) {
  mod <- get_model("MaltielCM_count")
  d <- list(N = N, K = K, y = y, m = m, L = L, eta = eta, v = v)
  mod$sample(data = d, ...)
}
