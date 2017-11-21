(let ((s (read-line)))
  (loop for i from 0 below (length s) by 2 do
        (princ (char s i)))
  (terpri))
