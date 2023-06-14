fact(N,F) :- 
  fact_aux(N,F,1,1).

fact_aux(N,F,N,F) :- !.

fact_aux(N,F,I,P) :- 
  NewI is I + 1,
  NewP is P * NewI,
  fact_aux(N,F,NewI,NewP).
  