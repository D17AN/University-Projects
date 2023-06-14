#{
#1
p=input('p=')
N=input('N=')
for i=1:N
  r=rand(1,N);
  x=(r<p);
endfor
u_x=unique(x)
n_x=hist(x,length(u_x))
freq=n_x/N
#}

#2
#{
p=input('p=')
n=input('n=')
N=input('N=')
r=rand(n,N);
x=sum(r<p);
k=0:n;
p_b=binopdf(k,n,p);
u_x=unique(x);
n_x=hist(x,length(u_x));
freq=n_x/N
clf
plot(k,p_b,'o',u_x,freq,'*')
#}
#{
p=input('p=')
N=input('N=')
for i=1:N
  x(i)=0;
  while rand>=p
    x(i)=x(i)+1;
  endwhile
endfor
k=0:20;
p_k=geopdf(k,p);
u_x=unique(x);
n_x=hist(x,length(u_x));
clf
plot(k,p_k,'o',u_x,n_x,'*')
#}
clear x
clear y
p=input('p=');
n=input('n=');
N=input('N=');
for i=1:N
  for j=1:n
    x(j)=0;
    while rand>=p
      x(j)=x(j)+1;
    endwhile
  endfor
  y(i)=sum(x);
endfor
k=0:20;
p_k=nbinpdf(k,n,p);
u_y=unique(y);
n_y=hist(y,length(u_y));
freq=n_y/N;
clf
plot(k,p_k,'o',u_y,freq,'*')

