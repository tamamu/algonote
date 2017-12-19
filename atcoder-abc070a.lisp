(let ((n (read-line)))
  (format t "~A~%"
	  (if (string= n (reverse n))
	      "Yes" "No")))

