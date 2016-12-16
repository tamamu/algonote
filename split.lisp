(require :asdf)
(require :prove)
(in-package :cl-user)
(defpackage split-test
  (:use :cl
        :prove))
(in-package :split-test)


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


(let ((answer #("" "" "a" "b" "" "c" "d" "" ""))
      (seq (split ",,a,b,,c,d,," #\,)))
  (plan (length answer))
  (loop for i from 0 below (length seq)
        do (is (aref answer i) (aref seq i))))

(finalize)
