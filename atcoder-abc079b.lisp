
(defun lucas (n)
  (loop
    with a = 1
    and  b = 2
    repeat (1- n) do (shiftf b a (+ a b))
    finally (return a)))

(let ((n (read)))
  (format t "~A~%" (lucas n)))
