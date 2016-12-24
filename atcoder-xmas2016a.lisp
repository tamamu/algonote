
;;; Xmas Contest 2016-A: Array Sum

(defun near-pow2 (n)
  (if (<= n 0)
      0
      (if (zerop (logand n (1- n)))
          n
          (let ((ret 1))
            (loop while (> n 1)
                  do (setf ret (ash ret 1)
                           n (ash n -1)))
            ret))))

(defmacro geti ()
  `(parse-integer (read-line)))

(defun qs (start n)
  (if (zerop n)
      0
      (let ((be (near-pow2 n)))
        (format t "? ~A ~A~%" start (+ start be))
        (let ((sum-to-be (geti)))
          (+ sum-to-be (qs (+ start be) (- n be)))))))

(let* ((n (parse-integer (read-line)))
       (ans (qs 0 n)))
  (format t "! ~A~%" ans)
  (finish-output))