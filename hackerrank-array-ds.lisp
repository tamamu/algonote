(let* ((n (read))
       (a (make-array n)))
  (dotimes (i n)
    (setf (aref a i) (read)))
  (loop for i from (1- n) downto 0
        for ai = (aref a i)
        if (= i 0) do (format t "~A~%" ai)
        else do (format t "~A " ai)))
