confLevel = input('conf level (in (0,1) = '); %1 - alpha
alpha = confLevel;

X=[7 7 4 5 9 9 ...
   4 12 8 1 8 7 ...
   3 13 2 1 17 7 ...
   12 5 6 2 1 13 ...
   14 10 2 4 9 11 ...
   3 5 12 6 10 7];

s = std(X);
n = length(X);
xbar = mean(X);

q1 = tinv(1 - alpha/2, n - 1);
q2 = tinv(alpha/2, n - 1);

cl1 = xbar - (s / sqrt(n)) * q1;
cl2 = xbar + (s / sqrt(n)) * q1;
fprintf('Confidence interval for population mean, miu, where sigma is unknown is (%3.5f, %3.5f)\n', cl1, cl2)
