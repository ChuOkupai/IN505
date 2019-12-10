(defun summit (liste)
	(if (null liste)
		0
		(let ((X (car liste)))
			(if (null X)
				(summit (cdr liste))
				(+ X (summit (cdr liste)))
			)
		)
	)
)