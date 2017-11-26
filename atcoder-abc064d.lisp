(defun count-left (str)
  (loop for ch across (reverse str)
        with rp = 0
        with id = 0 do
        (if (eq ch #\))
            (incf rp)
            (if (zerop rp)
                (incf id)
                (decf rp)))
        finally (return id)))

(defun count-right (str)
  (loop for ch across str
        with lp = 0
        with id = 0 do
        (if (eq ch #\()
            (incf lp)
            (if (zerop lp)
                (incf id)
                (decf lp)))
        finally (return id)))

(let* ((n (read-line))
       (s (read-line)))
  (declare (ignore n))
  (dotimes (i (count-right s))
    (princ #\())
  (princ s)
  (dotimes (i (count-left s))
    (princ #\)))
  (terpri))
