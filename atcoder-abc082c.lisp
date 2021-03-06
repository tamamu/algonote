(let* ((n (read))
       (a (make-array n))
       (cnt (make-hash-table))
       (total 0))
  (dotimes (i n)
    (let ((ai (read)))
      (setf (aref a i) ai
            (gethash ai cnt) (1+ (gethash ai cnt 0)))))
  (maphash
    (lambda (key val)
      (if (< key val)
          (incf total (- val key))
          (when (> key val) (incf total val))))
    cnt)
  (format t "~A~%" total))
