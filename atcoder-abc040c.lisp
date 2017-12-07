(defun bfs (arr len idx acc)
  (cond
    ((= idx (1- len)) acc)
    ((= idx (- len 2))
     (bfs arr len (1+ idx) (+ acc
			      (abs (- (aref arr idx)
				      (aref arr (1+ idx)))))))
    (t (min (bfs arr len (1+ idx) (+ acc
				    (abs (- (aref arr idx)
					    (aref arr (1+ idx))))))
	    (bfs arr len (+ 2 idx) (+ acc
				      (abs (- (aref arr idx)
					      (aref arr (+ 2 idx))))))))))

(let* ((n (read))
       (a (make-array n)))
  (dotimes (i n)
    (setf (aref a i) (read)))
  (format t "~A~%" (bfs a (length a) 0 0)))

