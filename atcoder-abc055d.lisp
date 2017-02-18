

;;; AtCoder Beginner Contest 055-D

(defun foo (n s l)
  (loop for i from 1 upto n
        for animal = (char l i)
        if (eq animal #\S)
        do (if (eq (aref s (1- i)) #\o)
               (setf (aref l (1+ i)) (aref l (1- i)))
               (setf (aref l (1+ i)) (if (eq (aref l (1- i)) #\S)
                                         #\W
                                         #\S)))
        else
        do (if (eq (aref s (1- i)) #\o)
               (setf (aref l (1+ i)) (if (eq (aref l (1- i)) #\S)
                                         #\W
                                         #\S))
               (setf (aref l (1+ i)) (aref l (1- i)))))
  l)

(let* ((n (parse-integer (read-line)))
       (s (read-line))
       (l1 (make-array (+ n 2) :element-type 'character :initial-element #\S))
       (l2 (make-array (+ n 2) :element-type 'character :initial-element #\W)))
  (setf l1 (foo n s l1))
  (setf l2 (foo n s l2))
  (if (eq (aref l1 0) (aref l1 (1+ n)))
      (format t "~A~%" (subseq l1 1 (1+ n)))
      (if (eq (aref l2 0) (aref l2 (1+ n)))
          (format t "~A~%" (subseq l2 1 (1+ n)))
          (format t "-1~%"))))