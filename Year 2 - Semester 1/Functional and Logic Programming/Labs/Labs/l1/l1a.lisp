; 5.
; a) Write twice the n-th element of a linear list. Example: for (10 20 30 40 50) and n=3 will produce 
; (10 20 30 30 40 50).

(defun twice (l n)
    (cond
        ((null l) nil)
        ((= n 1) (cons (car l) l))
        (T (cons (car l) (twice (cdr l) (- n 1))))
    )
)

(print (twice '(10 20 30 40 50) 3))
;=> (10 20 30 30 40 50)

;Mathematical model:
;twice(l, nr)={
;	       [], n = 0
;	       {l1} U {l1} U twice(l2...ln, nr), n = nr
;	       {l1} U twice(l2..ln, nr), otherwise
;	      }

;twice(l: list, n: the nr of the elem)
;flow model: (i, i)


; b) Write a function to return an association list with the two lists given as parameters.
; Example: (A B C) (X Y Z) --> ((A.X) (B.Y) (C.Z)).

(defun my_append (l k)
    (if (null l) 
        k
        (cons (car l) (my_append (cdr l) k))
    )
)

(defun association (l k)
    (cond
        ((and (null l) (null k)) nil)
        ((null l) (my_append (list (cons NIL (car k))) (association l (cdr k))))
        ((null k) (my_append (list (cons (car l) NIL)) (association (cdr l) k)))
        (T (my_append (list (cons (car l) (car k))) (association (cdr l) (cdr k))))
    )
)

(print (association '(A B C Q) '(X Y Z T U)))
;=> ((A . X) (B . Y) (C . Z) (Q . T) (NIL . U)) 

;Mathematical model
;my_append(l, k) = {
;			k, l = void set
;			l1 U my_append(l2...ln, k), otherwise
;		}
;my_append(l: list, k: list)
;flow model: (i, i)
;Mathematical model
;association(l, k) = {
;						NIL, if l = void set and k = void set
;						my_append({NIL,k1}, association(l, k2...kn)),l = void set
;						my_append({l1,NIL}, association(l2...ln, k)), k = void set
;						my_append({{l1,k1}, association(l2..ln, k2...kn), otherwise
;					 }
;association(l:list, k: list)
;flow model(i, i)

; c) Write a function to determine the number of all sublists of a given list, on any level.
;  A sublist is either the list itself, or any element that is a list, at any level. Example:
;  (1 2 (3 (4 5) (6 7)) 8 (9 10)) => 5 lists:
;  (list itself, (3 ...), (4 5), (6 7), (9 10)).

(defun countList (l)
    (cond
        ((atom l) 0)
        ((listp l) (+ 1 (apply '+ (mapcar 'countList l))))
    )
)
			
(print (countList '(1 2 (3 (4 5) (6 7)) 8 (9 10))))

;Mathematical model
;countList(l) = {
;		  			0, l not list
;		  			1 + countList(countlist(l1)...countlist(ln)), if l is a list
;			}
;countList(l: list or atom)
;flow model (i)

; d) Write a function to return the number of all numerical atoms in a list at superficial level.

(defun countNumbers (l)
    (cond
        ((null l) 0)
        ((numberp (car l)) (+ 1 (countNumbers (cdr l))))
        (T (countNumbers (cdr l)))
    )
)
;Mathematical model
;countNumbers(l) = {
;					0, n = 0
;					1 + countNumbers(l2..ln), if l1 is a number
;					countNumbers(l2...ln), otherwise
;countNumbers(l: list)
;flow model(i)

(print (countNumbers '(1 2 s 5 (6) fg 5)))
;=> 4