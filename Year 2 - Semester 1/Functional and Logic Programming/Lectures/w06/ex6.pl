% FIVE HOUSES

next_to(X,Y,[X,Y|_]).
next_to(X,Y,[_|L]) :-
  next_to(X,Y,L).

near(X,Y,L) :- next_to(X,Y,L).
near(X,Y,L) :- next_to(Y,X,L).

start:- 
  Sol = [_,_,_,_,_],                              % 1
	member([english,_,_,_,red],Sol), 		            % 2
	member([spanish,dog,_,_,_],Sol),  		          % 3
	member([_,_,_,coffee,green],Sol),		            % 4
	member([ukrainian,_,_,tea,_],Sol),		          % 5 
	near([_,_,_,_,white],[_,_,_,_,green], Sol),     % 6
	member([_,snake,winston,_,_],Sol), 		          % 7
	member([_,_,kool,_,yellow],Sol),		            % 8
	Sol= [_,_,[_,_,_,milk,_],_,_],			            % 9	
  Sol= [[norwegian,_,_,_,_],_,_,_,_],   	        % 10
	near([_,_,chesterfield,_,_],[_,fox,_,_,_],Sol), % 11
	near([_,_,kool,_,_],[_,horse,_,_,_], Sol),	    % 12
	member([_,_,lucky,juice,_],Sol),			          % 13
	member([japonese,_,kent,_,_],Sol),			        % 14
	near([norwegian,_,_,_,_],[_,_,_,_,blue],Sol), 	% 15
	member([_,_,_,water,_],Sol),  	                % someone drinks water
	member([_,zebra,_,_,_],Sol),	                  % someone has a zebra
	write(Sol).  			
