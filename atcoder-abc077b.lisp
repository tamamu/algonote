(let ((n (read)))
  (loop for i from 1 to n
        if (< n (expt (1+ i) 2)) do
        (format t "~A~%" (expt i 2))
        (return)))
