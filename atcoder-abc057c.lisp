(let ((n (read))
      (res 11))
  (loop for i = 1 then (1+ i) while (<= (* i i) n) do
        (if (zerop (mod n i))
            (setf res (min res
                           (length (write-to-string (truncate n i)))))))
  (format t "~A~%" res))
