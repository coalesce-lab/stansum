# Maltiel et al (2015) Combined Model

Bayesian model for ARD with both barrier effect and transmission bias
parameters.

- `maltiel_cm_count` – combined model for count responses, as described
  in section 2.4 of Maltiel et al (2015). It carries both the
  per-sub-population overdispersion `rho_k` of the barrier effects model
  and the transmission bias `tau_k` of the transmission bias model:
  `y_ik ~ Binomial(d_i, tau_k * q_ik)` with
  `d_i ~ LogNormal(mu, sigma^2)` and `q_ik ~ Beta(m_k, rho_k)`.
  Multiplying `q_ik` by `tau_k` breaks the Beta-Binomial conjugacy, so –
  unlike
  [`maltiel_bem_count()`](https://coalesce-lab.github.io/stansum/reference/maltiel_bem.md)
  – the latent `q_ik` cannot be integrated out and are sampled together
  with the remaining parameters. This adds `N * K` parameters, so fits
  are substantially slower than for the component models.

## Usage

``` r
maltiel_cm_count(N, K, y, m, L, eta, v, ...)
```

## Arguments

- N:

  integer; population size

- K:

  integer; number of sub-populations

- y:

  numeric matrix; ARD counts (N x K)

- m:

  numeric vector; fractional sub-population sizes (length K)

- L:

  numeric vector; lower bounds on individual degrees (length N). Must
  satisfy `L[i] >= max(y[i,])` for each respondent `i` so that the
  degree is always at least as large as the maximum observed count.

- eta:

  numeric vector; Beta prior shape 1 for each transmission bias (length
  K)

- v:

  numeric vector; Beta prior shape 2 for each transmission bias (length
  K)

- ...:

  other arguments passed to
  [`cmdstanr::sample()`](https://mc-stan.org/cmdstanr/reference/model-method-sample.html)

## Value

Object of class
[cmdstanr::CmdStanMCMC](https://mc-stan.org/cmdstanr/reference/CmdStanMCMC.html)
containing the samples.

## Details

Calling this function(s) will load the model object using
[`get_model()`](https://coalesce-lab.github.io/stansum/reference/get_model.md)
and sample from the posterior using the
[`cmdstanr::sample()`](https://mc-stan.org/cmdstanr/reference/model-method-sample.html)
method.

The transmission biases `tau_k` and the degrees `d_i` are only weakly
identified from ARD alone: scaling `tau_k` down and the degrees up
leaves the reported counts largely unchanged. The `eta` / `v` prior on
`tau` is what resolves this, so an uninformative `eta = v = 1` will
typically pull the posterior for `tau` below 1 and inflate the estimated
degrees. Supply an informative prior reflecting what is known about
transmission for each sub-population.

## References

Maltiel, R., Raftery, A. E., McCormick, T. H., & Baraff, A. J. (2015).
Estimating Population Size Using the Network Scale Up Method. *The
Annals of Applied Statistics*, 9(3), 1247–1277.
[doi:10.1214/15-AOAS827](https://doi.org/10.1214/15-AOAS827)

## See also

Use
[`get_model()`](https://coalesce-lab.github.io/stansum/reference/get_model.md)
to return Stan model object of class
[cmdstanr::CmdStanModel](https://mc-stan.org/cmdstanr/reference/CmdStanModel.html)
without fitting it.

Other models in this package:
[`maltiel_bem`](https://coalesce-lab.github.io/stansum/reference/maltiel_bem.md),
[`maltiel_rdm`](https://coalesce-lab.github.io/stansum/reference/maltiel_rdm.md),
[`maltiel_tbm`](https://coalesce-lab.github.io/stansum/reference/maltiel_tbm.md),
[`test_model()`](https://coalesce-lab.github.io/stansum/reference/test_model.md),
[`zheng_bem`](https://coalesce-lab.github.io/stansum/reference/zheng_bem.md),
[`zheng_gp`](https://coalesce-lab.github.io/stansum/reference/zheng_gp.md)

Other models of Maltiel et al (2015):
[`maltiel_bem`](https://coalesce-lab.github.io/stansum/reference/maltiel_bem.md),
[`maltiel_rdm`](https://coalesce-lab.github.io/stansum/reference/maltiel_rdm.md),
[`maltiel_tbm`](https://coalesce-lab.github.io/stansum/reference/maltiel_tbm.md)

## Examples

``` r
data("Fake_maltiel_RD", package = "stansum")
y <- data.matrix(Fake_maltiel_RD)[1:50, ]
K <- ncol(y)
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
#> Running MCMC with 1 chain...
#> 
#> Chain 1 Iteration:   1 / 210 [  0%]  (Warmup) 
#> Chain 1 Informational Message: The current Metropolis proposal is about to be rejected because of the following issue:
#> Chain 1 Exception: beta_lpdf: First shape parameter is 0, but must be positive finite! (in '/tmp/RtmpkUMlaH/model-29062f94785e.stan', line 37, column 4 to column 74)
#> Chain 1 If this warning occurs sporadically, such as for highly constrained variable types like covariance matrices, then the sampler is fine,
#> Chain 1 but if this warning occurs often then your model may be either severely ill-conditioned or misspecified.
#> Chain 1 
#> Chain 1 Informational Message: The current Metropolis proposal is about to be rejected because of the following issue:
#> Chain 1 Exception: beta_lpdf: First shape parameter is 0, but must be positive finite! (in '/tmp/RtmpkUMlaH/model-29062f94785e.stan', line 37, column 4 to column 74)
#> Chain 1 If this warning occurs sporadically, such as for highly constrained variable types like covariance matrices, then the sampler is fine,
#> Chain 1 but if this warning occurs often then your model may be either severely ill-conditioned or misspecified.
#> Chain 1 
#> Chain 1 Informational Message: The current Metropolis proposal is about to be rejected because of the following issue:
#> Chain 1 Exception: beta_lpdf: First shape parameter is 0, but must be positive finite! (in '/tmp/RtmpkUMlaH/model-29062f94785e.stan', line 37, column 4 to column 74)
#> Chain 1 If this warning occurs sporadically, such as for highly constrained variable types like covariance matrices, then the sampler is fine,
#> Chain 1 but if this warning occurs often then your model may be either severely ill-conditioned or misspecified.
#> Chain 1 
#> Chain 1 Iteration: 100 / 210 [ 47%]  (Warmup) 
#> Chain 1 Iteration: 200 / 210 [ 95%]  (Warmup) 
#> Chain 1 Iteration: 201 / 210 [ 95%]  (Sampling) 
#> Chain 1 Iteration: 210 / 210 [100%]  (Sampling) 
#> Chain 1 finished in 0.4 seconds.
```
