
;;; AtCoder Beginner Contest 047-A

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

(let* ((in (map 'vector #'parse-integer (split (read-line) #\Space)))
       (a (aref in 0))
       (b (aref in 1))
       (c (aref in 2))
       (a+b (+ a b))
       (b+c (+ b c))
       (c+a (+ c a)))
  (if (or (= a+b c)
          (= b+c a)
          (= c+a b))
    (format t "Yes~%")
    (format t "No~%")))
