
;;; Dwango Pre 3-A

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

(let* ((nab (map 'vector #'parse-integer
                 (split (read-line) #\Space)))
       (n (aref nab 0))
       (a (aref nab 1))
       (b (aref nab 2))
       (c (- n (+ a b))))
  (format t "~A~%" (if (> c 0) 0 (abs c))))