x=[7 7 4 5 9 9 ...
   4 12 8 1 8 7 ...
   3 13 2 1 17 7 ...
   12 5 6 2 1 13 ...
   14 10 2 4 9 11 ...
   3 5 12 6 10 7] ;

n=length(x);
sigma=5;
alpha=0.05;
m0=9;

[h1, p1, ci1, zstat1] = ztest(x, m0, sigma, 'alpha',alpha,'tail','left')

RR = [-inf, norminv(alpha)];
fprintf('Rejection region RR is (%1.1f, %1.1f)\n', RR);


% Define data
standard = [46 37 39 48 47 44 35 31 44 37];
new = [35 33 31 35 34 30 27 32 31 31];

% Perform t-test
[h,p,ci,stats] = ttest2(standard,new,0.05,'both','unequal');
fprintf("95%% Confidence interval for the difference of the average assembling times: [%f, %f]\n", ci(1), ci(2))

