(defun b (i)
  (loop for ch across (write-to-string i)
        sum (- (char-code ch) #.(char-code #\0))))

(let ((n (read))
      (a (read))
      (b (read)))
  (format t "~A~%"
          (loop for i from 1 to n
                if (<= a (b i) b)
                sum i)))
