confLevel = input('conf level (in (0,1) = '); %1 - alpha
alpha = confLevel;

X=[7 7 4 5 9 9 ...
   4 12 8 1 8 7 ...
   3 13 2 1 17 7 ...
   12 5 6 2 1 13 ...
   14 10 2 4 9 11 ...
   3 5 12 6 10 7];

svar = var(X);
n = length(X);

q1 = chi2inv(1 - alpha/2, n - 1);
q2 = chi2inv(alpha/2, n - 1);

ci1 = sqrt(((n - 1) * svar) / q1) ;
ci2 = sqrt(((n - 1) * svar) / q2);
fprintf('Confidence Interval for the population variance sigma is (% 3.5f, %3.5f)\n',ci1,ci2)
