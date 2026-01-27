# List or get Stan model objects

List Stan models available in this package or load them in the form of
`CmdStanModel` objects as implemented in the cmdstanr package.

## Usage

``` r
get_model(name, ...)

list_models()
```

## Arguments

- name:

  character; name of the model to load

- ...:

  arguments passed to
  [instantiate::stan_package_model](https://wlandau.github.io/instantiate/reference/stan_package_model.html)

## Value

`get_model` returns an "CmdStanModel" object.

`list_models` returns a character vector of model names provided with
the package.
