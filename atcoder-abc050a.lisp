
;;; AtCoder Beginner Contest 050-A

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


(let* ((aopb (split (read-line) #\Space))
       (a (parse-integer (aref aopb 0)))
       (op (char (aref aopb 1) 0))
       (b (parse-integer (aref aopb 2))))
  (if (eq op #\+)
      (format t "~A~%" (+ a b))
      (format t "~A~%" (- a b))))