candidate([E|_],E).
candidate([_|T],E) :-
  candidate(T,E).

solution(L, N, Rez) :-
  candidate(L, E),
  E =< N,
  solution_aux(L, N, Rez, [E], E).

% param 4 collects the solution
% param 5 is sum of all elements in the collector
solution_aux(_, N, Rez, Rez, N) :- !.
solution_aux(L, N, Rez, [H | Col], S) :-
  candidate(L, E),
  E < H,
  S1 is S+E,
  S1 =< N,
  solution_aux(L, N, Rez, [E, H | Col], S1).
  