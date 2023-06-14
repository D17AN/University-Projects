N = input('Number of successes= ')
n = input('n= ')
p = input('p= ')

clear x
clear y

for i=1:n

  for j=1:N
    x(j) = 0;

    while rand >= p

      x(j) = x(j)+1

    endwhile

  endfor

  y(i)=sum(x);

endfor

k=0:20;

p_k = nbinpdf(k, N, p);

u_y = unique(y);

n_y = hist(y, length(u_y));

freq=n_y/n;

clf

plot(k, p_k, 'o', u_y, freq, '*');
