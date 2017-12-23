(let ((left (+ (read) (read)))
      (right (+ (read) (read))))
  (format t "~A~%"
          (cond
            ((> left right) "Left")
            ((< left right) "Right")
            (t "Balanced"))))
