function [m1, m2] = confint2(x, alpha)
  s = std(x);
  m1 = mean(x)-(s/sqrt(length(x))) * tinv(1-alpha/2, length(x)-1);
  m2 = mean(x)+(s/sqrt(length(x))) * tinv(1-alpha/2, length(x)-1);
