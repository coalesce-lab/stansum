
<!-- README.md is generated from README.Rmd. Please edit that file -->

# `stansum`: Bayesian Models for Aggregated Relational Data

<!-- badges: start -->

[![R-CMD-check](https://github.com/coalesce-lab/stansum/actions/workflows/R-CMD-check.yaml/badge.svg)](https://github.com/coalesce-lab/stansum/actions/workflows/R-CMD-check.yaml)
<!-- badges: end -->

R package wraping Bayesian models for Aggregated Relational Data (ARD)
relevant for the Network Scale-Up Method (NSUM) and degree estimation.
The package includes models by Zheng, Salganik, and Gelman (2006),
Maltiel et al. (2015), Baum and Marsden (2023)

The package relies on **instantiate** (Landau 2023) to embed Stan models
in an R package.

See package’s webpage at <https://coalesce-lab.github.io/stansum/>.

## Authors and contributors

- Michał Bojanowski
- Derick S. Baum

## Installation

You can install the development version of stansum from
[GitHub](https://github.com/) with:

``` r
# install.packages("remotes")
remotes::install_github("coalesce-lab/stansum")
```

or soon from <https://coalesce-lab.r-universe.dev/builds>.

## Acknowledgements

Michał Bojanowski thanks European Research Council for support through
grant 101020038 (PI Miranda Lubbers, COALESCE Lab, UAB)
<http://patchwork-erc.eu/>.

[![](man/figures/logos-patchwork.png)](http://coalesce-lab.com/en)

![](man/figures/logos-erc.png)

## References

<div id="refs" class="references csl-bib-body hanging-indent">

<div id="ref-baum_marsden_2023" class="csl-entry">

Baum, Derick S., and Peter V. Marsden. 2023. “Uses and Limitations of
Dichotomous Aggregate Relational Data.” *Social Networks* 74 (July):
42–61. <https://doi.org/10.1016/j.socnet.2023.02.001>.

</div>

<div id="ref-r-instantiate" class="csl-entry">

Landau, William Michael. 2023. *Instantiate: Pre-Compiled CmdStan Models
in r Packages*.

</div>

<div id="ref-maltiel_etal_2015" class="csl-entry">

Maltiel, Rachael, Adrian E. Raftery, Tyler H. McCormick, and Aaron J.
Baraff. 2015. “Estimating Population Size Using the Network Scale Up
Method.” *The Annals of Applied Statistics* 9 (3): 1247–77.
<https://doi.org/10.1214/15-AOAS827>.

</div>

<div id="ref-zheng_etal_2006" class="csl-entry">

Zheng, Tian, Matthew J. Salganik, and Andrew Gelman. 2006. “How Many
People Do You Know in Prison? Using Overdispersion in Count Data to
Estimate Social Structure in Networks.” *Journal of the American
Statistical Association* 101 (474): 409–23.
<https://doi.org/10.1198/016214505000001168>.

</div>

</div>
