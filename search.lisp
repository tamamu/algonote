
(defparameter +graph+
  (list '(:A . :B)
        '(:B . :C)
        '(:B . :D)
        '(:A . :E)
        '(:D . :F)
        '(:E . :G)
        '(:E . :H)
        '(:C . :I)))

(defun bfs (graph start goal)
  "Breadth-first search"
  (let ((olist '())
        (clist '()))
    (push start olist)
    (loop while (not (equalp (car olist) goal))
          when (null olist) do (return) end
          do (let ((cur (pop olist)))
               (unless (member cur clist)
                 (push cur clist))
               (let ((alist (loop for node in graph
                                  for s = (car node)
                                  for e = (cdr node)
                                  when (equalp s cur)
                                  collect e)))
                 (setf olist (append olist alist)))))
    (print (reverse clist))))

(bfs +graph+ :A :H)