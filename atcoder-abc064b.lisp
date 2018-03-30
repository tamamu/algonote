(let* ((n (read))
       (a (make-array n)))
  (dotimes (i n)
    (setf (aref a i) (read)))
  (format t "~A~%"
	  (loop for ai across a
		with min = 1000
		with max = 0 do
		(when (< ai min)
		  (setf min ai))
		(when (< max ai)
		  (setf max ai))
		finally (return (- max min)))))
