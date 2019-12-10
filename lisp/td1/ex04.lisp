(defun lst_in_lst(x)
	(if (null x)
		nil
		(if (listp (car x)) t (lst_in_lst (cdr x)))
	)
)
