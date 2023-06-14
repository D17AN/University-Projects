add(E,[],[E]).

add(E,[H|T],[H|Rez]):-
  add(E,T,Rez).

even(L,Rez):-
  even_aux(L,Rez,[]).

even_aux([],Rez,Rez).

even_aux([H|T],Rez,Col):-
  H mod 2 =:= 0,
  !,
  add(H,Col,ColN),
  even_aux(T,Rez,ColN).

even_aux([_|T],Rez,Col):-
  even_aux(T,Rez,Col).
