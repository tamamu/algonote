
;;; AtCoder Beginner Contest 049-D Connectivity
;;; Fail


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

(defun dfs (pmat start)
  (let ((con '())
        (olst `(,start))
        (clst '()))
    (loop while (not (null olst))
          for a = (pop olst)
          for nodes = (loop for i from 0 below (array-dimension pmat 1)
                            unless (null (aref pmat a i)) collect i)
          do (push a clst)
          do (loop for city in nodes
                   when (and (null (member city clst))
                             (null (member city olst)))
                   do (push city con)
                      (push city olst)))
    con))


(let* ((nkl (map 'vector #'parse-integer (split (read-line) #\Space)))
       (n (aref nkl 0))
       (k (aref nkl 1))
       (l (aref nkl 2))
       (roads (make-array `(,n ,n) :initial-element nil))
       (rails (make-array `(,n ,n) :initial-element nil))
       (result '()))
  (dotimes (i k)
    (let ((line (map 'vector
                     (lambda (x) (1- (parse-integer x)))
                     (split (read-line) #\Space))))
      (setf (aref roads (aref line 0) (aref line 1)) t
            (aref roads (aref line 1) (aref line 0)) t)))
  (dotimes (i l)
    (let ((line (map 'vector
                     (lambda (x) (1- (parse-integer x)))
                     (split (read-line) #\Space))))
      (setf (aref rails (aref line 0) (aref line 1)) t
            (aref rails (aref line 1) (aref line 0)) t)))
  (dotimes (i n)
    (let ((rocon (dfs roads i))
          (racon (dfs rails i)))
      (push (1+ (loop for c in rocon
                      count (member c racon)))
            result)))
  (format t "~{~A~^ ~}~%" (reverse result)))