comb([H|_], 1, [H]).
comb([_|T], K, C) :-
  comb(T, K, C).
comb([H|T], K, [H|C]) :-
  K > 1,
  K1 is K-1,
  comb(T, K1, C).

sum([], 0).
sum([H|T], S) :-
  sum(T, S1),
  S is H + S1.

combSum(L, K, S, C) :-
	comb(L, K, C),
	sum(C, S).
