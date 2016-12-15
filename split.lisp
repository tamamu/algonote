(require :asdf)
(require :prove)
(in-package :cl-user)
(defpackage split-test
  (:use :cl
        :prove))
(in-package :split-test)

(defun split (str delim)
  (loop for start = 0 then (1+ finish)
        for finish = (position delim str :start start)
        collect (subseq str start finish)
        until (null finish)))

(plan 1)

(is (split "a,b,c,d" #\,) '("a" "b" "c" "d"))

(finalize)
