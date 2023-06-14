confLevel = input('conf level (in (0,1) = '); %1 - alpha
alpha = confLevel;

X=[7 7 4 5 9 9 ...
   4 12 8 1 8 7 ...
   3 13 2 1 17 7 ...
   12 5 6 2 1 13 ...
   14 10 2 4 9 11 ...
   3 5 12 6 10 7];
sigma = 5;
n = length(X);
xbar = mean(X);

q1 = norminv(1 - alpha/2, 0, 1);

ci1 = xbar - (sigma/(sqrt(n))) * q1;
ci2 = xbar + (sigma/(sqrt(n))) * q1;
fprintf('Confidence interval for the population mean, miu, where sigma = %d is (%3.5f, %3.5f)\n', sigma, ci1, ci2);
