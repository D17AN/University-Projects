pair(A,[B|_],[A,B]):-
  A<B.

pair(A,[_|T],P):-
  pair(A,T,P).

pairs([H|T],P):-
  pair(H,T,P).

pairs([_|T],P):-
  pairs(T,P).

allPairs(L,LRes):-
  findall(X,pairs(L,X),LRez).
