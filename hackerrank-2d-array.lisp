(let ((a (make-array '(6 6)))
      (m -64))
  (dotimes (i 6)
    (dotimes (j 6)
      (setf (aref a i j) (read))))
  (loop for i from 0 to 3 do
	(loop for j from 0 to 3 do
	      (setf m (max m
			   (+ (aref a i j)
			      (aref a i (+ j 1))
			      (aref a i (+ j 2))
			      (aref a (+ i 1) (+ j 1))
			      (aref a (+ i 2) j)
			      (aref a (+ i 2) (+ j 1))
			      (aref a (+ i 2) (+ j 2)))))))
  (format t "~A~%" m))
