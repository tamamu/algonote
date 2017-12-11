(defconstant modulo 1000000007)

(let* ((n (read))
       (tbl (make-array 1005 :initial-element 0 :element-type 'fixnum)))
  (loop for k from 1 to n do
	(loop with i = 2
	      with v = k
	      while (< 1 v) do
	      (if (zerop (mod v i))
		  (setf v (/ v i)
			(aref tbl i) (1+ (aref tbl i)))
		  (incf i))))
  (format t "~A~%" (loop for c across tbl
			 for acc = 1 then (mod (* acc (1+ c)) modulo)
			 finally (return acc))))
