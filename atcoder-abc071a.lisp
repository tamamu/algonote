(let ((x (read))
      (a (read))
      (b (read)))
  (format t "~A~%"
	  (if (< (abs (- x a)) (abs (- x b)))
	      "A" "B")))
