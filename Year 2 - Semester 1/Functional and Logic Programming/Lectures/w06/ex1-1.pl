combSum([H|_], 1, H, [H]).
combSum([_|T], K, S, C) :-
combSum(T, K, S, C).
combSum([H|T], K, S, [H|C]) :-
  K > 1,
  S1 is S-H,
  S1 > 0,
  K1 is K-1,
  combSum(T, K1, S1, C).
