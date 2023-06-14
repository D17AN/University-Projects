x=[7 7 4 5 9 9 4 12 8 1 8 7 3 13 2 1 17 7 12 5 6 2 1 13 14 10 2 4 9 11 3 5 12 6 10 7];

miu = 9;

sigma = 5;

alpha = 0.01;

[h, p, ci, zstat ] = ztest(x, miu, sigma, 'alpha', alpha, 'tail', 'left')

if h == 1
  fprintf('Hypothesis is rejected\n')
else
  fprintf('Hypothesis is accepted\n')
endif

fprintf('The value of the statistic =  %4.4f\n', zstat)

fprintf('The p value = %4.4f\n', p)

RR = [-inf, norminv(alpha)];

fprintf('The rejection region = (%1.1f, %1.1f)\n', RR)

miu = 5.52

[h, p, ci, tstat ] = ttest(x, miu,'alpha', alpha, 'tail', 'right');

tstat.sd

if h == 1
  fprintf('Hypothesis is rejected\n')
else
  fprintf('Hypothesis is accepted\n')
endif

fprintf('The value of the statistic =  %4.4f\n', zstat)

fprintf('The p value = %4.4f\n', p)

RR = [tinv(1-alpha, length(x)-1), inf]

fprintf('The rejection region = (%1.1f, %1.1f)\n', RR)

