
;;; Dwango Pre 2-B

(eval-when (:execute)
  (proclaim '(optimize (speed 3) (debug 0) (safety 0))))


(defun split (str delim)
  (let ((res (make-array 1 :element-type 'string
                           :fill-pointer 0
                           :adjustable t)))
    (loop for i from 0 below (length str)
          with start = 0
          when (eq (char str i) delim)
          do (vector-push-extend (subseq str start i) res)
             (setf start (1+ i))
          finally (let ((tail (subseq str start)))
                    (when tail
                      (vector-push-extend tail res))))
    res))

(defun pencil (k)
  (let ((l (make-array (1+ (length k)) :element-type 'fixnum
                                       :initial-element 1000000000))
        (len (length k)))
    (loop for i from 0 below len
          for n = (parse-integer (aref k i))
          do (setf (aref l (1+ i)) n)
          when (> (aref l i) n)
          do (setf (aref l i) n))
    l))

(read-line)
(let ((k (split (read-line) #\Space)))
  (let ((l (pencil k)))
    (loop for i from 0 below (1- (length l))
        do (format t "~A " (aref l i))
        finally (format t "~A~%" (aref l i)))))
