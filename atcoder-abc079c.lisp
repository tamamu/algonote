(defvar pm
  (list '+ '-))

(let* ((line (read-line))
       (a (parse-integer (subseq line 0 1)))
       (b (parse-integer (subseq line 1 2)))
       (c (parse-integer (subseq line 2 3)))
       (d (parse-integer (subseq line 3 4))))
  (tagbody
    start
    (loop for i in pm do
      (loop for j in pm do
        (loop for k in pm do
          (when (= 7
                   (funcall (symbol-function k) (funcall (symbol-function j) (funcall (symbol-function i) a b) c) d))
            (format t "~A~A~A~A~A~A~A=7"
                    a (symbol-name i)
                    b (symbol-name j)
                    c (symbol-name k)
                    d)
            (go finish)))))
    finish))
