

;;; AtCoder Beginner Contest 055-C

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

(let* ((line (map 'vector #'parse-integer (split (read-line) #\Space)))
       (n (aref line 0))
       (m (truncate (aref line 1) 2))
       (res 0)
       (nmin (min n m)))
  (incf res nmin)
  (decf n nmin)
  (decf m nmin)
  (incf res (truncate m 2))
  (format t "~A~%" res))