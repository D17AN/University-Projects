add1(E,[],[E]).

add1(E,[H|T],[H|Rez]):-
  add1(E,T,Rez).

% add1(E,[H|T],Rez):-
%   add1(E,T,L),Rez=[H|L].

add2([],E,[E]).

add2([H|T],E,[H|Rez]):-
  add2(T,E,Rez).

% add2([H|T],E,Rez):-
%   add2(T,E,L),Rez=[H|L].
