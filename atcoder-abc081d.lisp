(let* ((n (read))
       (a (make-array n))
       (ope (list))
       (max 0)
       (min 0))
  (dotimes (i n)
    (setf (aref a i) (read)))
  (loop for i from 0 below n
        for ai = (aref a i) do
        (if (< (aref a max) ai)
            (setf max i))
        (if (< ai (aref a min))
            (setf min i)))
  (loop for i from 1 below n
        for ai = (aref a i)
        for ap = (aref a (1- i))
        with lmax = max
        with lmin = min do
        (loop while (< (aref a i) (aref a (1- i))) do
              (if (minusp (aref a lmax))
                  (progn
                    (incf (aref a (1- i)) (aref a lmin))
                    (push (cons (1+ lmin) i) ope))
                  (progn
                    (incf (aref a i) (aref a lmax))
                    (push (cons (1+ lmax) (1+ i)) ope)))
              (when (< (aref a lmax) (aref a i))
                (setf lmax i))
              (when (< (aref a (1- i)) (aref a lmin))
                (setf lmin (1- i)))))
  (format t "~A~%" (length ope))
  (dolist (o (reverse ope))
    (format t "~A ~A~%"
            (car o) (cdr o))))
