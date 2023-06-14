; Write a function that computes the sum of even numbers and 
; the decrease the sum of odd numbers, at any level of a list.
; Mathematical model
; solve(l) = { 
			 ; l1 + solve(l2...ln), l1 mod 2 = 0
			 ; l1 - solve(l2...ln), l1 mod 2 = 1
			 ; 0, n = 0
		   ; }
; solve(l: list)
; flow model (i)

(defun solve(l)
    (cond
        ((and (numberp l) (eq (mod l 2) 0)) l)
        ((and (numberp l) (eq (mod l 2) 1)) (* -1 l))
        ((listp l) (apply #'+ (mapcar #' solve l)))
        (t 0)
        )
    )
(print(solve '(2 2 3 2(3 2 (3)))))


