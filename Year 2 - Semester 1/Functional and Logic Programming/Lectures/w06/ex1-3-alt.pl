candidate(E, [E|_]).
candidate(E, [_|T]) :-
  candidate(E, T).

% (i,i,i,i,i,i,o)
condition(L, K, S, LenRes, SumRes, HRes, E) :-
  LenRes < K,
  candidate(E, L),
  E < HRes,
  Sum1 is SumRes+E,
  Sum1 =< S.

combAux(_, K, S, C, K, S, C) :- !.
combAux(L, K, S, C, LenRes, SumRes, []):-
  condition(L, K, S, LenRes, SumRes, 999, E),
  Len1 is LenRes+1,
  Sum1 is SumRes+E,
  combAux(L, K, S, C, Len1, Sum1, [E]).
combAux(L, K, S, C, LenRes, SumRes, [HRes|TRes]):-
  condition(L, K, S, LenRes, SumRes, HRes, E),
  Len1 is LenRes+1,
  Sum1 is SumRes+E,
  combAux(L, K, S, C, Len1, Sum1, [E,HRes|TRes]).

% C is a combination of K elements of sum S from given list L
combSum(L, K, S, C) :-
  combAux(L, K, S, C, 0, 0, []).
