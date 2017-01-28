
;;; AtCoder Beginner Contest 053-C

(let ((in (parse-integer (read-line))))
  (format t "~A~%"
          (multiple-value-bind (q r)
              (truncate in 11)
            (cond
              ((> r 6) (+ (* q 2) 2))
              ((= r 0) (* q 2))
              (t (1+ (* q 2)))))))