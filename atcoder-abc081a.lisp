(let ((s (read-line)))
  (format t "~A~%"
          (loop for ch across s sum (- (char-code ch)
                                       (char-code #\0)))))
