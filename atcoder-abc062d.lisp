(defun make-pq (alist)
  (sort (copy-alist alist) (lambda (a b) (< (car a) (car b)))))

(define-modify-macro insert-pq (pair)
                     (lambda (pq pair) (sort (cons pair pq) (lambda (a b) (< (car a) (car b))))))

(define-modify-macro remove-pq-aux () cdr)

(defmacro remove-pq (pq)
  `(let ((aux (copy-alist ,pq)))
     (REMOVE-PQ-AUX ,pq)
     (car aux)))

(let* ((n (read))
       (alen (* 3 n))
       (seq (make-array alen :initial-contents (loop repeat alen collect (read))))
       (ibpq (make-pq (loop for i from 0 below n
                            for a = (aref seq i)
                            collect (cons a a))))
       (ispq (make-pq (loop for i from 0 below n
                            for a = (aref seq (- alen i 1))
                            collect (cons (- a) a))))
       (res 0))
  (setf res
    (loop for k from 0 to n
          with bpq = nil
          with spq = nil do
          (setq bpq (copy-alist ibpq)
                spq (copy-alist ispq))
          (dotimes (i k)
            (let ((a (aref seq (1- (+ n k)))))
              (insert-pq bpq `(,a . ,a))
              (remove-pq bpq)))
          (dotimes (i (- n k))
            (let ((a (aref seq (- (- alen n 1) i))))
              (insert-pq spq `(,(- a) . ,a))
              (remove-pq spq)))
          maximize (- (loop for (x . y) in bpq sum y)
                      (loop for (x . y) in spq sum y))))
  (format t "~A~%" res))
