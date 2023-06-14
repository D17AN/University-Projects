%5
%a. Substitute all occurrences of an element of a list with all the elements of another list.
%Eg. subst([1,2,1,3,1,4],1,[10,11],X) produces
%X=[10,11,2,10,11,3,10,11,4].
%Mathematical model
%insert(l1...ln, InitL) = {
%       InitL, if List is empty
%       l1 U insert(l2...ln, InitL) otherwise
%  }
%
%substitue_elem(l1...ln, Elem, RList) = {
%               [], if list is empty
%               insert(RList, substitue_elem(l2...ln, Elem, RList)), if
%               l1 = Elem
%               l1 U substitue(l2...ln, Elem, RList) otherwise

%insert(List: list, InitialList: list, Result: list)
%List: the list which must be inserted
%InitialList: the list to which the given List needs to be inserted
%Result: the resulted InitialList after which List was inserted
%flow model: (i, i, o)
insert([], L, L).
insert([H|T], L, [H|R]):-
    insert(T, L, R).

% substitue_elem(List: list, ReplacedElem: int, NewElem: list,
% Res: list)
% flow model: (i, i, i, o)
substitue_elem([], _, _, []).
substitue_elem([H|T], E, List, R) :-
    H =:= E,
    insert(List, T, RI),
    substitue_elem(RI, E, List, R).
substitue_elem([H|T], E, List, [H|R]) :-
    H =\= E,
    substitue_elem(T, E, List, R).


%b.For a heterogeneous list, formed from integer numbers and list of numbers,
% replace in every sublist all occurrences of the first element from
% sublist it a new given list.
%Eg.: [1, [4, 1, 4], 3, 6, [7, 10, 1, 3, 9], 5, [1, 1, 1], 7] si [11, 11] =>
% [1, [11, 11, 1, 11, 11], 3, 6, [11, 11, 10, 1, 3, 9], 5, [11 11 11 11
% 11 11], 7]

%Mathematical model:
%heterList(l1...ln, Rlist) = {
%          [], n = 0
%          substitute_elem(l1, FirstEl, RList) U heterList(l2...ln,
%          RList), if is_list(l1)
%          l1 U heterList(l2...ln, RList), otherwise


%heterList(List: list, ReplacementList: list, Res: list)
%flow model: (i, i, o)
%List - initial list
%Replacement List: the List to be replaced with the element
%Res: The final list


heterList([], _, []).
heterList([[H|HT]|T], E, [HR|R]) :-
    substitue_elem([H|HT], H, E, HR),
    heterList(T, E, R).
heterList([H|T], E, [H|R]) :- number(H),
    heterList(T, E, R).
