(let* ((s (read-line))
       (slen (length s)))
  (format t "~A~A~A~%"
	  (char s 0)
	  (- slen 2)
	  (char s (1- slen))))
