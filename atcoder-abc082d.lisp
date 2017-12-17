(defun tsplit (s)
  (let ((n 0)
        (cnt (list)))
    (loop for c across s do
          (if (eq c #\F)
              (incf n)
              (progn
                (push n cnt)
                (setf n 0)))
          finally (if (< 0 n) (push n cnt)))
    (make-array (length cnt) :initial-contents (reverse cnt))))

(defun just (a b now)
  (let* ((blen (length b))
         (dp (make-array (list blen 2) :initial-element 0)))
    (loop for i from 0 below blen
          for v in b
          if (zerop i) do (setf (aref dp 0 0) v
                                (aref dp 0 1) (- v))
          else do (setf (aref dp i 0)
                        (+ v (aref dp (1- i) 0))
                        (aref dp i 1)
                        (+ v (aref ))))))

(let* ((s (tsplit (read-line)))
       (slen (length s))
       (gx (- (read) (aref s 0)))
       (gy (read)))
  (format t "~A~%"
          (if (and (just gx (loop for i from 2 below slen by 2
                                  collect (aref s i)) 0)
                   (just gy (loop for i from 1 below slen by 2
                                  collect (aref s i)) 0))
              "Yes" "No")))
