(let ((n (read-line)))
  (format t "~A~%"
	  (if (some (lambda (ch) (eq ch #\9)) n)
	    "Yes" "No")))
