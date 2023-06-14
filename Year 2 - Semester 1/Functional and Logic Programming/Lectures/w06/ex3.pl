candidate(N, N).
candidate(N, I) :-
  N > 1,
  N1 is N-1, 
  candidate(N1, I).

permutations(N, V, L) :-
  candidate(N, I),
  permutations_aux(N, V, L, 1, [I]).

permutations_aux(N, _, Col, N, Col) :- !.
permutations_aux(N, V, L, Lg, [H|T]) :-
  candidate(N, I),
  abs(H-I) >= V,
  \+ member(I, [H|T]), % (i, i)
  Lg1 is Lg + 1, 
  permutations_aux(N, V, L, Lg1, [I,H|T]).
