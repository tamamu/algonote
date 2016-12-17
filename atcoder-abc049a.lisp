
;;; AtCoder Beginner Contest 049-A UOIAUAI

(let ((c (char (read-line) 0)))
  (if (position c "aeiou")
    (format t "vowel~%")
    (format t "consonant~%")))
