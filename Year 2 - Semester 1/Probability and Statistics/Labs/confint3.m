function [m1, m2] = confint3(x, alpha)
  ss = var(x);
  n = length(x);
  X = chi2inv(1-alpha/2, n-1);
  X2 = chi2inv(alpha/2, n-1);
  m1 = ((n-1)*ss)/X;
  m2 = ((n-1)*ss)/X2;
