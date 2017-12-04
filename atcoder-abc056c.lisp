(let ((n (read)))
  (loop for i from 0 below n
        while (< (/ (* i (1+ i)) 2) n)
        finally (format t "~A~%" i)))
