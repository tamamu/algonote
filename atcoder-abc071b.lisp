(defun alphabet-index (ch)
  (- (char-code ch) (char-code #\a)))

(let ((s (read-line))
      (seq (make-array 26 :initial-element nil)))
  (dotimes (i (length s))
    (let ((ch (char s i)))
      (setf (aref seq (alphabet-index ch))
            t)))
  (loop for i from 0 below 26
        unless (aref seq i) do
        (format t "~A~%" (code-char (+ (char-code #\a) i)))
        (return)
        finally (format t "None~%")))
