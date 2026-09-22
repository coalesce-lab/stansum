# Maltiel et al Transmission Bias Model

Bayesian model for ARD with transmission bias parameters.

- `maltiel_tbm_count` – transmission bias model for count responses. All
  `tau_k` are estimated from the data.

## Usage

``` r
maltiel_tbm_count(N, K, y, m, L, eta, v, ...)
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
[`test_model()`](https://coalesce-lab.github.io/stansum/reference/test_model.md),
[`zheng_bem`](https://coalesce-lab.github.io/stansum/reference/zheng_bem.md),
[`zheng_gp`](https://coalesce-lab.github.io/stansum/reference/zheng_gp.md)

Other models of Maltiel et al (2015):
[`maltiel_bem`](https://coalesce-lab.github.io/stansum/reference/maltiel_bem.md),
[`maltiel_rdm`](https://coalesce-lab.github.io/stansum/reference/maltiel_rdm.md)

## Examples

``` r
data("Fake_maltiel_RD", package = "stansum")
K <- ncol(Fake_maltiel_RD)
r <- maltiel_tbm_count(
  N = nrow(Fake_maltiel_RD),
  K = K,
  y = data.matrix(Fake_maltiel_RD),
  m = rep(0.01, K),
  L = apply(data.matrix(Fake_maltiel_RD), 1, max),
  eta = rep(1, K),
  v = rep(1, K),
  chains = 1,
  iter_warmup = 200,
  iter_sampling = 10
)
#> Running MCMC with 1 chain...
#> 
#> Chain 1 Iteration:   1 / 210 [  0%]  (Warmup) 
#> Chain 1 Iteration: 100 / 210 [ 47%]  (Warmup) 
#> Chain 1 Iteration: 200 / 210 [ 95%]  (Warmup) 
#> Chain 1 Iteration: 201 / 210 [ 95%]  (Sampling) 
#> Chain 1 Iteration: 210 / 210 [100%]  (Sampling) 
#> Chain 1 finished in 9.3 seconds.
```
