n= input('n= ')

for i=1:3:100

  k = 0:i

  p1 = binopdf(k, i, p)

  plot(k, p1)

  xlim([0, 101])
  ylim([0, 0.2])

  pause(0.2)

endfor

