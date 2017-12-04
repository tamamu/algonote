(defun dfs (graph v n visited)
  (let ((all-visited-p t))
    (dotimes (i n)
      (if (null (aref visited i))
          (setf all-visited-p nil)))
    (if all-visited-p
        1
        (let ((res 0))
          (dotimes (i n)
            (if (and (aref graph v i)
                     (null (aref visited i)))
                (setf (aref visited i) t
                      res (+ res (dfs graph i n visited))
                      (aref visited i) nil)))
          res))))

(let* ((n (read))
       (m (read))
       (graph (make-array `(,n ,n) :initial-element nil))
       (visited (make-array n :initial-element nil)))
  (dotimes (i m)
    (let ((a (1- (read)))
          (b (1- (read))))
      (setf (aref graph a b) t
            (aref graph b a) t)))
  (setf (aref visited 0) t)
  (format t "~A~%" (dfs graph 0 n visited)))
