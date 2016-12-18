
;;; AtCoder Beginner Contest 050-C

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
       (a (map 'vector #'parse-integer (split (read-line) #\Space)))
       (pos (make-array n :initial-element 0)))
  (loop for i from 0 below n
        for p = (aref a i)
        do (incf (aref pos p)))
  (if (or (and (evenp n)
               (/= (aref pos 0) 0))
          (and (oddp n)
               (/= (aref pos 0) 1)))
      (format t "0~%")
      (if (and (> n 1)
               (loop for i from 1 below n
                     for p = (aref pos i)
                     when (not (integerp (/ p 2)))
                     do (return t)
                     finally (return nil)))
          (format t "0~%")
          (format t "~A~%"
                  (mod (expt 2 (/ (if (oddp n)
                                      (1- n)
                                      n)
                                  2))
                       1000000007)))))