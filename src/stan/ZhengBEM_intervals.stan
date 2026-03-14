// BEM of Zheng etal for ordered categorical intervals responses
//
// Stan implementation features within-chain parallelism via reduce_sum().

functions {
  real partial_sum(
    array[] int slice_j,          // categories for this slice of observations
    int start, int end,           // global positions in td_j
    vector alpha, vector beta, vector phi,
    array[] int td_i, array[] int td_k,
    array[] int L, array[] int U
  ) {
    real ll = 0;
    for (n in 1:size(slice_j)) {
      int i = td_i[start + n - 1];
      int k = td_k[start + n - 1];
      int j = slice_j[n];
      real mu = phi[k] * exp(alpha[i] + beta[k]);
      if (U[j] >= 0) {
        if (L[j] == 0)
          ll += neg_binomial_lcdf(U[j] | mu, phi[k]);
        else
          ll += log_diff_exp(
            neg_binomial_lcdf(U[j]     | mu, phi[k]),
            neg_binomial_lcdf(L[j] - 1 | mu, phi[k])
          );
      } else {
        if (L[j] > 0)
          ll += neg_binomial_lccdf(L[j] - 1 | mu, phi[k]);
      }
    }
    return ll;
  }
}

data {
  int<lower=1> N;
  int<lower=1> K;
  int<lower=2> J;

  // Observed categorical responses in {1,...,J}; use -1 for missing-by-design
  array[N, K] int y_cat;

  // Interval bounds: category j is counts in [L[j], U[j]]
  // Use U[j] = -1 to indicate U[j] = +infinity (typically only for j=J).
  array[J] int<lower=0> L;
  array[J] int U;
}

transformed data {
  // Flat list of observed cells. Max size N*K; actual used entries = N_obs.
  int N_obs = 0;
  array[N*K] int td_i;   // respondent index
  array[N*K] int td_k;   // item index
  array[N*K] int td_j;   // category index

  for (k in 1:K) {
    for (i in 1:N) {
      if (y_cat[i, k] >= 1) {
        N_obs += 1;
        td_i[N_obs] = i;
        td_k[N_obs] = k;
        td_j[N_obs] = y_cat[i, k];
      }
    }
  }
}

parameters {
  vector[N] alpha_raw;   // non-centered: alpha = alpha_raw * sigma_alpha
  vector[K] beta_raw;    // non-centered: beta  = mu_beta + beta_raw * sigma_beta
  vector<lower=0, upper=1>[K] inv_omega;

  real mu_beta;
  real<lower=0> sigma_beta;
  real<lower=0> sigma_alpha;
}

transformed parameters {
  vector[N] alpha = alpha_raw * sigma_alpha;
  vector[K] beta  = mu_beta + beta_raw * sigma_beta;

  vector<lower=0>[K] phi = inv_omega ./ (1 - inv_omega);
}

model {
  alpha_raw ~ normal(0, 1);
  beta_raw  ~ normal(0, 1);

  mu_beta     ~ normal(0, 2);
  sigma_beta  ~ normal(0, 1);
  sigma_alpha ~ normal(0, 1);

  target += reduce_sum(partial_sum, td_j[1:N_obs], 1,
                       alpha, beta, phi, td_i, td_k, L, U);
}
