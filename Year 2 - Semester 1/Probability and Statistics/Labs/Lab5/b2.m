x=[7 7 4 5 9 9 ...
   4 12 8 1 8 7 ...
   3 13 2 1 17 7 ...
   12 5 6 2 1 13 ...
   14 10 2 4 9 11 ...
   3 5 12 6 10 7] ;

n=length(x);
alpha=0.05;
m0=9;

[h1, p1, ci1, zstat1] = ttest(x, m0, 'alpha', alpha, 'tail', 'right')

RR1 = [tinv(1-alpha, n-1), inf]'
fprintf('Rejection region RR is (%1.1f, %1.1f)\n', RR1);


