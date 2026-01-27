# A simple Bernoulli model for testing purposes

A test Bernoulli model taken from Stan documentation.

## Usage

``` r
test_model(N, y, ...)
```

## Arguments

- N:

  integer; number of trials

- y:

  integer; vector of Bernoulli outcomes

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

## See also

Use
[`get_model()`](https://coalesce-lab.github.io/stansum/reference/get_model.md)
to return Stan model object of class
[cmdstanr::CmdStanModel](https://mc-stan.org/cmdstanr/reference/CmdStanModel.html)
without fitting it.

Other models in this package:
[`maltiel_bem`](https://coalesce-lab.github.io/stansum/reference/maltiel_bem.md),
[`maltiel_rdm`](https://coalesce-lab.github.io/stansum/reference/maltiel_rdm.md),
[`zheng_bem`](https://coalesce-lab.github.io/stansum/reference/zheng_bem.md),
[`zheng_gp`](https://coalesce-lab.github.io/stansum/reference/zheng_gp.md)
