alpha = input('alpha= ')
beta = input('beta= ')

option=input('dist= ', 's')

switch option

case 'normal'

niu = input('niu= ')
sigma = input('sigma= ')

p1 = normcdf(0, niu, sigma)

p2 = 1 - p1

p3 = normcdf(1, niu, sigma) - normcdf(-1, niu, sigma)

p4 = 1 - p3

p5 = norminv(alpha, niu, sigma)

fprintf("%1.4f\n", p5)

p6 = norminv(1 - beta, niu, sigma)

fprintf("%1.4f\n", p6)

case 'student'

n = input('n= ')

p1 = tcdf(0, n)

p2 = 1 - p1

p3 = tcdf(1, n) - tcdf(-1, n)

p4 = 1 - p3

p5 = tinv(alpha, n)

fprintf("%1.4f\n", p5)

p6 = tinv(1 - beta, n)

fprintf("%1.4f\n", p6)

case 'fischer'

n = input('n= ')
m = input('m= ')

p1 = fcdf(0, m, n)

p2 = 1 - p1

p3 = fcdf(1, m, n) - fcdf(-1, m, n)

p4 = 1 - p3

p5 = finv(alpha, m, n)

p6 = finv(1 - beta, m, n)


endswitch

fprintf("Pronbability at a) is: %1.4f and %1.4f\n", p1, p2)
fprintf("Pronbability at b) is: %1.4f and %1.4f\n", p3, p4)
fprintf("Pronbability at c) is: %1.4f\n", p5)
fprintf("Pronbability at d) is: %1.4f\n", p6)
