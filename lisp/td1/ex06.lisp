; renvoie vrai si la liste contient un élément nul
(defun enigme(X)
	(and
		(not (null X))
		(or
			(null (car X))
			(enigme (cdr X))
		)
	)
)

; renvoie la position dans la liste Y où l'élémént est égal au premier élément
; de X
(defun mystere (X Y)
	(if
		(null Y)
		nil
		(if (eql (car Y) X)
			0
			(let ((Z (mystere X (cdr Y))))
			(and Z (+ Z 1)))
		)
	)
)
