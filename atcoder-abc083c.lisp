(let ((x (read))
      (y (read)))
  (format t "~A~%"
          (loop for i = x then (* 2 i)
                until (< y i)
                count i)))
