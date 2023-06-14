option = input('dist=', 's')
switch option
  case 'normal'
    niu = 1
    sigma = 5
    P1 = normcdf(0,niu,sigma)
    P2 = 1 - P1
    P3 = normcdf(1,niu,sigma) - normcdf(-1,niu,sigma)
    P4 = 1 - P3
    norminv(P1, niu, sigma)
    beta = 0.74
    norminv(1-beta, niu, sigma)
  case 'student'
    niu = 4
    p1 = tcdf(0,niu)
    p2 = 1 - p1
    p3 = tcdf(1,niu) - tcdf(-1,niu)
    p4 = 1 - p3
    tinv(p1, niu)
    beta = 0.74
    tinv(1-beta, niu)
  case 'fischer'
    m = input('niu=');
    n = input('sigma=');
    p1 = fcdf(0,m,n)
    p2 = 1 - p1
    p3 = fcdf(1, m, n) - fcdf(-1, m, n)
    p4 = 1 - p3
    finv(p1, m, n)
    beta = 0.74
    finv(1-beta, m, n)
  end

p = input('p=')
for n=1:3:100
  k = 0:n;
  prob=binopdf(k,n,p)
  plot(k,prob)
  %ylimp([0,50])
  pause(0.2)
endfor

n = input('n = ')
p = input('p = ')
lambda=n*p;
k=0:n
px1 = binopdf(k,n,p)
px2 = poisspdf(k,lambda)
plot(k, px1)
hold on
plot(k, px2)

