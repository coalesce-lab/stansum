# `stansum`: Bayesian Models for Aggregated Relational Data

<!-- badges: start -->
[![R-CMD-check](https://github.com/coalesce-lab/stansum/actions/workflows/R-CMD-check.yaml/badge.svg)](https://github.com/coalesce-lab/stansum/actions/workflows/R-CMD-check.yaml)
<!-- badges: end -->

R package wraping Bayesian models for Aggregated Relational Data (ARD) relevant for the Network Scale-Up Method (NSUM) and degree estimation. The package includes models by
Zheng et al (2006),
Maltiel et al (2015),
Baum & Marsden (2023).




## Installation

You can install the development version of stansum from [GitHub](https://github.com/) with:

``` r
# install.packages("remotes")
remotes::install_github("coalesce-lab/stansum")
```

or soon from <https://coalesce-lab.r-universe.dev/builds>.


## References

Baum, D. S., & Marsden, P. V. (2023). Uses and limitations of
dichotomous aggregate relational data. *Social Networks*, 74, 42–61.
<doi:10.1016/j.socnet.2023.02.001>

Maltiel, R., Raftery, A. E., McCormick, T. H., & Baraff, A. J. (2015).
Estimating Population Size Using the Network Scale Up Method. *The Annals
of Applied Statistics*, 9(3), 1247–1277.
<doi:10.1214/15-AOAS827>

Zheng, T., Salganik, M. J., & Gelman, A. (2006). How Many People Do You
Know in Prison? Using Overdispersion in Count Data to Estimate Social
Structure in Networks. Journal of the American Statistical Association,
101(474), 409–423. <doi:10.1198/016214505000001168>
