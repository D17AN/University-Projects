even([],[]).

even([H|T],[H|Rez]):-
  H mod 2 =:= 0,
  !,
  even(T,Rez).

even([_|T],Rez):-
  even(T,Rez).
