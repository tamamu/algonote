
;;; AtCoder Beginner Contest 053-B

(let* ((in (read-line))
       (ap 0)
       (zp (1- (length in))))
  (loop while (not (eq (char in ap) #\A))
        do (incf ap))
  (loop while (not (eq (char in zp) #\Z))
        do (decf zp))
  (format t "~A~%" (1+ (- zp ap))))