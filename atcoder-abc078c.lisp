(let ((n (read))
      (m (read)))
  (format t "~A~%"
	  (floor (* (+ (* 1900 m) (* 100 (- n m))) (expt 2 m)))))
