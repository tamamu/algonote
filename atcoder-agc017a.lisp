(let* ((n (read))
       (p (read))
       (a (loop repeat n collect (read)))
       (e (loop for ai in a always (evenp ai))))
  (if e
      (if (= p 0)
          (prin1 (expt 2 n))
          (prin1 0))
      (prin1 (expt 2 (1- n))))
  (terpri))
