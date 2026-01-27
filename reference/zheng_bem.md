# Zheng et al (2006) Barrier Effects Model

Bayesian model for ARD...

- `zheng_bem_count` – model for count responses

&nbsp;

- `zheng_bem_dichotomous` – model for dichotmous responses proposed by
  Baum & Marsden (2023).

&nbsp;

- `zheng_bem_trichotomous` – model for trichotomous responses proposed
  by Baum & Marsden (2023).

## Usage

``` r
zheng_bem_count(N, K, y, ...)

zheng_bem_dichotomous(N, K, y, ...)

zheng_bem_trichotomous(N, K, y, ...)
```

## Arguments

- N:

  integer; sample size

- K:

  integer; number of sub-populations

- y:

  integer matrix; ARD

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

Zheng, T., Salganik, M. J., & Gelman, A. (2006). How Many People Do You
Know in Prison? Using Overdispersion in Count Data to Estimate Social
Structure in Networks. Journal of the American Statistical Association,
101(474), 409–423.
[doi:10.1198/016214505000001168](https://doi.org/10.1198/016214505000001168)

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
[`zheng_gp`](https://coalesce-lab.github.io/stansum/reference/zheng_gp.md)

Other models of Zheng et al (2006):
[`zheng_gp`](https://coalesce-lab.github.io/stansum/reference/zheng_gp.md)
