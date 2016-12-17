
;;; AtCoder Beginner Contest 049-B Thin

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
       (h (parse-integer (aref in 0))))
  (loop for i from 0 below h
        for line = (read-line)
        do (format t "~A~%~A~%" line line)))
