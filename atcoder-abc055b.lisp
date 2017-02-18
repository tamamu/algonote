

;;; AtCoder Beginner Contest 055-B

(let ((n (parse-integer (read-line)))
      (i 1))
  (loop for j from 2 upto n
        do (setf i (mod (* i j) 1000000007)))
  (format t "~A~%" i))
