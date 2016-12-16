
;;; Dwango Pre 2-A

(format t "~A~%"
  (let ((n (parse-integer (read-line)))
        (cnt 0))
    (if (< n 25)
      0
      (progn
        (loop for i from 25 upto n by 25
              when (= (mod i 25) 0)
              do (incf cnt))
        cnt))))

