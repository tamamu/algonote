
;;; AtCoder Beginner Contest 053-A

(let ((in (parse-integer (read-line))))
  (format t "~A~%"
          (if (< in 1200)
              "ABC"
              "ARC")))