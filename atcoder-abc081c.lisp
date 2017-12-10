(let* ((n (read))
       (k (read))
       (a (make-array n))
       (cnt (make-hash-table))
       (diff (list))
       (dcnt 0))
  (dotimes (i n)
    (setf (aref a i) (read)))
  (loop for ai across a do
        (multiple-value-bind (v p)
          (gethash ai cnt 0)
          (unless p
            (push ai diff)
            (incf dcnt))
          (setf (gethash ai cnt)
                (1+ v))))
  (let* ((del (- dcnt k))
         (least (sort diff #'(lambda (x y) (< (gethash x cnt)
                                              (gethash y cnt))))))
    (format t "~A~%"
            (loop repeat del
                  for l in least
                  sum (gethash l cnt)))))
