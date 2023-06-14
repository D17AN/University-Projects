member1(E,[E|_]).
member1(E,[_|L]) :-
  member1(E,L).

go1:-
  member1(1,[1,2,1,3,1,4]).

member2(E,[E|_]) :- !.
member2(E,[_|L]) :-
  member2(E,L).

go2:-
  member2(1,[1,2,1,3,1,4]).

member3(E,[_|L]) :- 
  member3(E,L).
member3(E,[E|_]).
