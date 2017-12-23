(let ((a (make-array 3))
      (b (make-array 3))
      (atotal 0)
      (btotal 0))
  (dotimes (i 3)
    (setf (aref a i) (read)))
  (dotimes (i 3)
    (setf (aref b i) (read)))
  (loop for ai across a
	for bi across b do
	(if (> ai bi)
	    (incf atotal)
	    (if (< ai bi)
	        (incf btotal))))
  (format t "~A ~A~%" atotal btotal))