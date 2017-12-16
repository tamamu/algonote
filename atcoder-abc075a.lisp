(let ((a (read))
      (b (read))
      (c (read)))
  (format t "~A~%"
	  (if (= a b)
	      c
	      (if (= b c)
		  a
		  b))))
