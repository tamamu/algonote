(let ((n (read))
      (a (make-hash-table)))
  (dotimes (i n)
    (let ((ai (read)))
      (setf (gethash ai a)
            (not (gethash ai a)))))
  (format t "~A~%" (loop for key being each hash-key of a
                         using (hash-value value)
                         when value count value)))
