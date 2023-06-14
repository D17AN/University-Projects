n= input('n= ')
p = input('p= ')

k=0:n

p1 = binopdf(k, n, p)
p2 = poisspdf(k, n*p)

plot(k, p1, k, p2)
