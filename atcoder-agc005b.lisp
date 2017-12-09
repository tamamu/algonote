(let* ((n (read))
       (a (make-array n))
       (total 0))
  (dotimes (i n)
    (setf (aref a i) (read)))
  (dotimes (i n)
    (let ((c (aref a i))
          (left 0)
          (right 0))
      (loop for l from i downto 0
            for v = (aref a l)
            until (< v c) do
            (incf left))
      (loop for r from i below n
            for v = (aref a r)
            until (< v c) do
            (incf right))
      (incf total (* c left right))))
  (format t "~A~%" total))
