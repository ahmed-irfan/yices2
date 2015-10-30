(set-logic QF_NIA)
(set-info :smt-lib-version 2.0)
(declare-fun x () Int)
(declare-fun y () Int)
(assert (= (* x y) 7))
(assert (> x 1))
(assert (> y 1))
(assert (< x 7))
(assert (< y 7))
(check-sat)
(exit)
