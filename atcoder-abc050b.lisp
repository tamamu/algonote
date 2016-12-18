
;;; AtCoder Beginner Contest 050-B

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

(let* ((n (parse-integer (read-line)))
       (tin (map 'vector #'parse-integer (split (read-line) #\Space)))
       (m (parse-integer (read-line)))
       (px (loop for i from 0 below m
                 collect (split (read-line) #\Space)))
       (s (reduce #'+ tin)))
  (loop for i in px
        for p = (1- (parse-integer (aref i 0)))
        do (format t "~A~%"
                   (+ (- s (aref tin p))
                      (parse-integer (aref i 1))))))