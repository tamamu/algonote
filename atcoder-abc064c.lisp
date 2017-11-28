(defvar +rate+
  '((399 . "gray")
    (799 . "brown")
    (1199 . "green")
    (1599 . "cyan")
    (1999 . "blue")
    (2399 . "yellow")
    (2799 . "orange")
    (3199 . "red")))

(defun select-color (point)
  (loop for (rate . color) in +rate+
        when (<= point rate)
        return color))

(let ((n (read))
      (a (make-hash-table))
      (any 0))
  (dotimes (i n)
    (let ((color (select-color (read))))
      (if color
          (setf (gethash color a)
                (1+ (gethash color a 0)))
          (incf any))))
  (let* ((count (loop for key being each hash-key of a
                      using (hash-value value)
                      count (< 0 value)))
         (mini (max count 1))
         (maxi (+ count any)))
    (format t "~A ~A~%" mini maxi)))
