# `stansum`: Bayesian Models for Aggregated Relational Data

R package wraping Bayesian models for Aggregated Relational Data (ARD)
relevant for the Network Scale-Up Method (NSUM) and degree estimation.
The package includes models by Zheng, Salganik, and Gelman (2006),
Maltiel et al. (2015), Baum and Marsden (2023)

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

[![](reference/figures/logos-patchwork.png)](http://coalesce-lab.com/en)

![](reference/figures/logos-erc.png)

## License

GPL 3

## References

Baum, Derick S., and Peter V. Marsden. 2023. “Uses and Limitations of
Dichotomous Aggregate Relational Data.” *Social Networks* 74 (July):
42–61. <https://doi.org/10.1016/j.socnet.2023.02.001>.

Landau, William Michael. 2023. *Instantiate: Pre-Compiled CmdStan Models
in r Packages*.

Maltiel, Rachael, Adrian E. Raftery, Tyler H. McCormick, and Aaron J.
Baraff. 2015. “Estimating Population Size Using the Network Scale Up
Method.” *The Annals of Applied Statistics* 9 (3): 1247–77.
<https://doi.org/10.1214/15-AOAS827>.

Zheng, Tian, Matthew J. Salganik, and Andrew Gelman. 2006. “How Many
People Do You Know in Prison? Using Overdispersion in Count Data to
Estimate Social Structure in Networks.” *Journal of the American
Statistical Association* 101 (474): 409–23.
<https://doi.org/10.1198/016214505000001168>.
