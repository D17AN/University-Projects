%a) Write a predicate to compute the union of 2 sets.
%unionSets(L1-list, L2-list, L3-obtained list)
%flow model(i, i, i) (i, i, o)
unionSets([H|T],Z,W):-
    list_member(H,Z), unionSets(T,Z,W).

unionSets([H|T],Z,[H|W]):-
    \+ list_member(H,Z), unionSets(T,Z,W).
unionSets([],Z,Z).

list_member(H,[H|_]).
list_member(H,[_|T]):-
    list_member(H,T).


% b) Write a predicate to determine the set of all the pair of elements
% in a list.

pair_in(T,H1-H2):-
    list_member(H1,T),
    list_member(H2,T),
    H1<H2.

%pairs_in(L-list, R-resulted list of pairs)
%flow model (i, i) (i, o)
pairs_in(T,R):-
    findall(P,pair_in(T,P),R).
