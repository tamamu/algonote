
;;; AtCoder Beginner Contest 054-A

(defun split (str delim)
  (let ((res (make-array 0 :element-type 'string
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

(let* ((l (map 'vector 'parse-integer (split (read-line) #\ )))
       (a (aref l 0))
       (b (aref l 1)))
  (when (= a 1) (setf a 14))
  (when (= b 1) (setf b 14))
  (if (= a b)
      (format t "Draw~%")
      (if (> a b)
          (format t "Alice~%")
          (format t "Bob~%"))))
