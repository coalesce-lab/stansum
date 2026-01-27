# Maltiel et al (2015) Barrier Effects Model

Bayesian model for ARD including parameters capturing barrier effects.

- `maltiel_bem_count` – model for count responses

&nbsp;

- `maltiel_bem_dichotomous` – model for dichotmous responses proposed by
  Baum & Marsden (2023).

&nbsp;

- `maltiel_bem_trichotomous` – model for trichotomous responses proposed
  by Baum & Marsden (2023).

## Usage

``` r
maltiel_bem_count(N, K, y, m, L, ...)

maltiel_bem_dichotomous(N, K, y, m, L, ...)

maltiel_bem_trichotomous(N, K, y, m, L, ...)
```

## Arguments

- N:

  integer; population size

- K:

  integer; number of sub-populations

- y:

  integer matrix; ARD

- m:

  numeric; vector of fractional sizes of sub-populations

- L:

  numeric; lower bound on degree

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

Baum, D. S., & Marsden, P. V. (2023). Uses and limitations of
dichotomous aggregate relational data. *Social Networks*, 74, 42–61.
[doi:10.1016/j.socnet.2023.02.001](https://doi.org/10.1016/j.socnet.2023.02.001)

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
[`maltiel_rdm`](https://coalesce-lab.github.io/stansum/reference/maltiel_rdm.md),
[`test_model()`](https://coalesce-lab.github.io/stansum/reference/test_model.md),
[`zheng_bem`](https://coalesce-lab.github.io/stansum/reference/zheng_bem.md),
[`zheng_gp`](https://coalesce-lab.github.io/stansum/reference/zheng_gp.md)

Other models of Maltiel et al (2015):
[`maltiel_rdm`](https://coalesce-lab.github.io/stansum/reference/maltiel_rdm.md)
