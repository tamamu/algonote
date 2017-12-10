(defun count-div (v)
  (if (zerop v)
      0
      (multiple-value-bind (q r)
        (truncate v 2)
        (if (= 0 r)
            (1+ (count-div q))
            0))))

(let* ((n (read))
       (a (make-array n)))
  (dotimes (i n)
    (setf (aref a i) (read)))
  (format t "~A~%"
          (loop for ai across a
                minimize (count-div ai))))
