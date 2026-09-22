data {
  int N;
  int K;
  array[N, K] int y;
}

transformed data {
  // count observed cells (negative entries encode missing, as before)
  int M = 0;
  for (k in 1:K) {
    for (i in 1:N) {
      if (y[i, k] >= 0) {
        M += 1;
      }
    }
  }

  array[M] int ii;
  array[M] int kk;
  array[M] int yy;
  {
    int m = 0;
    for (k in 1:K) {
      for (i in 1:N) {
        if (y[i, k] >= 0) {
          m += 1;
          ii[m] = i;
          kk[m] = k;
          yy[m] = y[i, k];
        }
      }
    }
  }
}

parameters {
  vector[N] alpha_std;
  real<lower=0> sigma_alpha;

  vector[K] beta_std;
  real mu_beta;
  real<lower=0> sigma_beta;

  vector<lower=0>[K] eta;               // eta_k = omega_k - 1
}

transformed parameters {
  vector[N] alpha = alpha_std * sigma_alpha;
  vector[K] beta  = mu_beta + beta_std * sigma_beta;
}

model {
  alpha_std ~ std_normal();
  beta_std  ~ std_normal();

  sigma_alpha ~ normal(0, 1);
  sigma_beta  ~ normal(0, 1);           // stops the chain-3 runaway
  mu_beta     ~ normal(-0.25, 1);       // log-scale of your column means

  eta ~ gamma(2, 4);                    // mean 0.5, zero density at eta = 0

  {
    vector[M] phi = inv(eta[kk]);       // finite for all eta > 0
    yy ~ neg_binomial(exp(alpha[ii] + beta[kk]) .* phi, phi);
  }
}

generated quantities {
  vector[K] omega = 1 + eta;
  vector[K] inv_omega = inv(omega);     // comparable to your earlier draws
}
