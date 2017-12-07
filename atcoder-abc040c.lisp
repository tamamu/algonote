(defun dp (n arr)
  (let* ((cost (make-array n :initial-element 0)))
    (setf (aref cost 1)
	  (abs (- (aref arr 0) (aref arr 1))))
    (loop for i from 2 below n do
	  (setf (aref cost i)
		(min (+ (abs (- (aref arr i) (aref arr (1- i))))
			(aref cost (1- i)))
		     (+ (abs (- (aref arr i) (aref arr (- i 2))))
			(aref cost (- i 2))))))
    (aref cost (1- n))))

(let* ((n (read))
       (a (make-array n)))
  (dotimes (i n)
    (setf (aref a i) (read)))
  (format t "~A~%" (dp n a)))

