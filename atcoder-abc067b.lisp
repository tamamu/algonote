(let* ((n (read)) (k (read)) (l (loop repeat n collect (read))))
  (format t "~A~%" (loop for v in (subseq (sort (copy-list l) #'>) 0 k) sum v)))
