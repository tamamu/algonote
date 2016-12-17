
;; AtCoder Beginner Contest 049-C Daydream

(defmacro let-if (nv c true false)
  `(let (,nv) (if ,c ,true ,false)))

(defun daydream-with (str start)
  (let-if
   (len (- (length str) start))
   (< len 5)
   nil
   (let-if
    (dream (string= #.(reverse "dream")
                    (subseq str start (+ start 5))))
    dream 5
    (let-if
     (erase (string= #.(reverse "erase")
                     (subseq str start (+ start 5))))
     erase 5
     (if (< len 6)
         nil
         (let-if
          (eraser (string= #.(reverse "eraser")
                           (subseq str start (+ start 6))))
          eraser 6
          (if (< len 7)
              nil
              (let-if
               (dreamer (string= #.(reverse "dreamer")
                                 (subseq str start (+ start 7))))
               dreamer 7
               nil))))))))

(let* ((s (reverse (read-line)))
       (len (length s))
       (r 0))
  (loop for i = (daydream-with s r)
        if (null i) do (return)
        else do (incf r i)
        while (>= len r))
  (if (>= r len)
    (format t "YES~%")
    (format t "NO~%")))
