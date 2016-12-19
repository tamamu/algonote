
;;; AtCoder Beginner Contest 048-B

(defun split (str delim)
  (let ((res (make-array 1 :element-type 'string
                           :fill-pointer 0
                           :adjustable t)))
    (loop for i from 0 below (length str)
          with start = 0
          when (eq (char str i) delim)
          do (vector-push-extend (subseq str start i) res)
             (setf start (1+ i))
          finally (let ((tail (subseq str start)))
                    (when tail
                      (vector-push-extend tail res))))
    res))

(let* ((in (split (read-line) #\Space))
       (a (parse-integer (aref in 0)))
       (b (parse-integer (aref in 1)))
       (x (parse-integer (aref in 2)))
       (a/x (ceiling (/ a x)))
       (b/x (floor (/ b x))))
  (format t "~A~%" (1+ (- b/x a/x))))