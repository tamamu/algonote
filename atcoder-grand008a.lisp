
;;; AtCoder Grand Contest 008-A

(defun split (str delim)
  (let ((res (make-array 0 :element-type 'string
                           :fill-pointer 0
                           :adjustable t)))
    (loop for i from 0 below (length str)
          with start = 0
          when (eq (char str i) delim)
          do (vector-push-extend (subseq str start i) res)
             (setf start (1+ i))
          finally (let ((tail (subseq str start)))
                    (when tail
                      (vector-push-extend tail res))))
    res))

(let* ((in (map 'vector #'parse-integer (split (read-line) #\Space)))
       (x (aref in 0))
       (y (aref in 1))
       (xplus (plusp x))
       (yplus (plusp y)))
  (if (= x y)
      (format t "~A~%" 0)
      (if (= x 0)
          (if yplus
              (format t "~A~%" (abs y))
              (format t "~A~%" (1+ (abs y))))
          (if (= y 0)
              (if xplus
                  (format t "~A~%" (1+ x))
                  (format t "~A~%" (abs x)))
              (if (eq xplus yplus)
                  (if (> x y)
                      (format t "~A~%" (+ (- x y) 2))
                      (format t "~A~%" (- y x)))
                  (if xplus
                      (if (> (abs x) (abs y))
                          (format t "~A~%" (1+ (+ x y)))
                          (format t "~A~%" (1+ (-(+ x y)))))
                      (if (> (abs x) (abs y))
                          (format t "~A~%" (1+ (- (+ x y))))
                          (format t "~A~%" (1+ (+ x y))))))))))
