
;; AtCoder Beginner Contest 049-C Daydream

(defmacro let-if (nv c true false)
  `(let (,nv) (if ,c ,true ,false)))

(defun daydream-with (str start)
  (let-if (len (- (length str) start))
    (< len 5)
    nil
    (let-if (dream (string= #.(reverse "dream")
                       (subseq str start (+ start 5))))
      dream 5
      (let-if (erase (string= #.(reverse "erase")
                       (subseq str start (+ start 5))))
        erase 5
        (if (< len 6)
          nil
          (let-if (eraser (string= #.(reverse "eraser")
                            (subseq str start (+ start 6))))
            eraser 6
            (if (< len 7)
              nil
              (let-if (dreamer (string= #.(reverse "dreamer")
                                 (subseq str start (+ start 7))))
                dreamer 7
                ;;; -*- coding:utf-8; mode:Lisp -*-

(in-package :lem)

(setf (attribute-fg-color *syntax-variable-attribute*) "yellow")
(define-key *global-keymap* "M-s M-n" 'other-window)
(define-key *global-keymap* "M-s M-q" 'delete-current-window)
(define-key *global-keymap* "M-s M-v" 'split-active-window-horizontally)
(define-key *global-keymap* "M-s M-s" 'split-active-window-vertically)
(define-key *global-keymap* "M-;" 'grow-window)
(define-key *global-keymap* "M--" 'shrink-window)
(define-key *global-keymap* "M-<" 'shrink-window-horizontally)
(define-key *global-keymap* "M->" 'grow-window-horizontally)
(define-key *global-keymap* "M-l" 'start-lisp-repl)

(in-package :lem.lisp-mode)

(define-key *lisp-mode-keymap* "M-," 'lisp-eval-defun)
(define-key *lisp-mode-keymap* "M-i" 'lisp-indent-sexp)

(define-command lisp-eval-buffer () ()
  (save-excursion
    (move-to-beginning-of-buffer)
    (mark-set)
    (move-to-end-of-buffer)
    (lisp-eval-region)
    (keyboard-quit)))

(define-key *lisp-mode-keymap* "C-c C-c" 'lisp-eval-buffer)nil))))))))

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
