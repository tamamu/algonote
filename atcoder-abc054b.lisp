
;;; AtCoder Beginner Contest 054-B

(let* ((n (read))
       (m (read))
       (shift (- n m))
       (a (make-array n))
       (b (make-array m))
       (matchp nil))
  (dotimes (i n)
    (setf (aref a i) (read-line)))
  (dotimes (i m)
    (setf (aref b i) (read-line)))
  (loop for y from 0 to shift until matchp do
    (loop for x from 0 to shift until matchp do
      (setf matchp
            (loop for i from 0 below m always
                  (loop for j from 0 below m always
                        (eq (char (aref b i) j)
                            (char (aref a (+ i y)) (+ j x))))))))
  (format t "~A~%" (if matchp "Yes" "No")))
