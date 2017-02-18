
;;; AtCoder Beginner Contest 055-A

(let ((n (parse-integer (read-line))))
  (format t "~A~%"
          (- (* n 800) (* 200 (floor (/ n 15))))))