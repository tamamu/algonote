(let* ((a (read))
       (b (read))
       (p (* a b)))
  (format t "~A~%" (if (evenp p) "Even" "Odd")))
