(let ((a (read-line))
      (b (read-line)))
  (setf a (sort (copy-seq a) #'char<)
        b (sort (copy-seq b) #'char>))
  (format t "~A~%"
          (if (string< a b) "Yes" "No")))
