
;;; Dwango Pre 3-B
;;; Fail

(defun 25range (str src)
  (let ((start src)
        (end src))
    (when (eq #\? (aref str src))
      (setf (aref str src) #\2))
    (loop for i from src downto 0
          for c = (char str i)
          and b = nil then c
          when b
          do (when (eq c #\?)
               (if (eq b #\2)
                   (setf c #\5)
                   (setf c #\2)))
             (if (and (or (eq c #\5) (eq c #\2))
                          (not (eq b c)))
                 (setf start i)
                 (return)))
    (loop for i from src below (length str)
          for c = (char str i)
          and b = nil then c
          when b
          do (if (or (and (or (eq c #\5) (eq c #\2))
                          (not (eq b c)))
                     (eq c #\?))
                 (setf end i)
                 (return)))
    (if (eq (char str src) #\2)
        (progn
          (when (not (integerp (/ (- src start) 2)))
            (incf start))
          (when (integerp (/ (- end src) 2))
            (decf end)))
        (progn
          (when (integerp (/ (- src start) 2))
            (incf start))
          (when (not (integerp (/ (- end src) 2)))
            (decf end))))
    (1+ (- end start))))

(defun maxx (lst)
  (let ((max (car lst)))
    (dolist (a lst)
      (if (< max a)
          (setf max a)))
    max))

(let* ((dat (read-line))
       (level (loop for i from 0 below (length dat)
                         for c = (char dat i)
                         when (or (eq c #\2) (eq c #\5) (eq c #\?))
                         collect (25range dat i))))
  (format t "~A~%" (maxx level)))