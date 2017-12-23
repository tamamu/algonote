(defun f (s)
  (loop for ch across s
        until (eq ch #\1)
        count ch))

(let ((x (read-line)))
  (format t "~A~%"
          (- (length x) (max 1 (f x)))))
