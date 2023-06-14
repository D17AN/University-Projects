% THREE HOUSES

solve1(N, A, T) :- 
  candidates(N, A, T), 
  constraints(N, A, T).

solve2(N, A, T) :- 
  constraints(N, A, T),
  candidates(N, A, T).

solve3(N, A, T) :- 
  constraints(N, A, T).

candidates(N, A, T) :- 
  perm([eng, spa, rus], N),
	perm([dog, wolf, horse], A),
	perm([lm, kent, ls], T).

constraints(N, A, T) :- 
  aux(N, A, T, eng, _, _, 1),
	aux(N, A, T, _, wolf, _, Nr1),
	right(Nr1, Nr2),
	aux(N, A, T, _, _, ls, Nr2),
	aux(N, A, T, spa, _, kent, _),
	aux(N, A, T, rus, horse, _, _),
  aux(N, A, T, _, dog, _, _),     % why do we need this?
  aux(N, A, T, _, _, lm, _).      % why do we need this?

right(I, J) :- 
  J is I + 1.

aux([N1, _, _], [A1, _, _], [T1, _, _], N1, A1, T1,1).
aux([_, N2, _], [_, A2, _], [_, T2, _], N2, A2, T2,2).
aux([_, _, N3], [_, _, A3], [_, _, T3], N3, A3, T3,3).

insert(E, L, [E | L]).
insert(E, [H | L], [H | T]) :- 
  insert(E, L, T).

perm([], []).
perm([H | T], L) :- 
  perm(T, P), 
  insert(H, P, L).
