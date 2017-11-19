(let ((n (read)))
  (loop for i from n downto 0
        for s = (sqrt i)
        when (= s (round s)) do
        (format t "~A~%" i)
        (return)))
