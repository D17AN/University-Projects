invers(L,Rez) :-
  invers_aux([],L,Rez).

invers_aux(Col,[],Col).
invers_aux(Col,[H|T],Rez):-
  invers_aux([H|Col],T,Rez).
