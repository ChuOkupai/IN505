;Prend un entier positif et imprime autant de points
(defun print_points(n)
	(do ((i 0 (+ i 1))) ((= i n) (values))
		(format t ".")
	)
)

(defun afficher (n)
	(do ((i 0 (+ i 1))) ((= i n) 'Done) ; Done facultatif
		(format t ".")
	)
)

(defun afficher (n)
	(if (plusp n)
		(progn
			(afficher(- n 1))
			(format t ".")
		)
	)
)

;Prend une liste et renvoie le nombre de fois le symbole ’a’ apparaît dans
;cette liste

(defun compter (lst)
	(do ((ls1 lst (cdr ls1))
		(n 0 (+
			n
			(if (eq (car ls1) 'a) 1 0)
		)))
		((not ls1) n)
	)
)

(defun compter (lst)
	(if lst
		(+
			(if (eq (car lst) 'a) 1 0)
			(compter (cdr lst))
		)
		0
	)
)
