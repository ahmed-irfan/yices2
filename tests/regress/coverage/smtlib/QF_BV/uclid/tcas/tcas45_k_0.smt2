(set-logic QF_BV)
(set-info :source |  Induction based Symbolic Bounded Model Checking of LLHA. Converted from UCLID model of Traffic Collision Avoidance System (Jha-Brady-Seshia, Formal Modelling and Analysis of Timed Systems  07)  |)
(set-info :smt-lib-version 2.0)
(set-info :category "industrial")
(set-info :status unsat)
(declare-fun x_r_init () (_ BitVec 33))
(declare-fun y_r_init () (_ BitVec 33))
(declare-fun t_elapse_cruise () (_ BitVec 33))
(declare-fun tsd_elapse_cruise () (_ BitVec 33))
(declare-fun tad_elapse_cruise () (_ BitVec 33))
(declare-fun t_elapse_left () (_ BitVec 33))
(declare-fun tsd_elapse_left () (_ BitVec 33))
(declare-fun tad_elapse_left () (_ BitVec 33))
(declare-fun t_elapse_straight () (_ BitVec 33))
(declare-fun tsd_elapse_straight () (_ BitVec 33))
(declare-fun tad_elapse_straight () (_ BitVec 33))
(declare-fun t_elapse_right () (_ BitVec 33))
(declare-fun tsd_elapse_right () (_ BitVec 33))
(declare-fun tad_elapse_right () (_ BitVec 33))
(declare-fun v_1 () (_ BitVec 33))
(declare-fun v_2 () (_ BitVec 33))
(declare-fun d () (_ BitVec 33))
(assert (let ((?v_4 ((_ sign_extend 31) ((_ extract 1 0) (_ bv0 32)))) (?v_0 ((_ extract 32 0) (bvshl ((_ sign_extend 26) ((_ extract 6 0) (_ bv50 32))) (_ bv16 33)))) (?v_1 ((_ extract 32 0) (bvshl ((_ sign_extend 23) ((_ extract 9 0) (_ bv260 32))) (_ bv16 33)))) (?v_6 ((_ extract 32 0) (bvshl ((_ sign_extend 28) ((_ extract 4 0) (_ bv10 32))) (_ bv16 33)))) (?v_2 (bvsle d ((_ extract 32 0) (bvshl ((_ sign_extend 17) ((_ extract 15 0) (_ bv27780 32))) (_ bv16 33))))) (?v_41 (bvadd t_elapse_right tad_elapse_right)) (?v_8 ((_ sign_extend 16) v_2)) (?v_11 ((_ sign_extend 16) (bvsub t_elapse_cruise tsd_elapse_cruise)))) (let ((?v_9 ((_ sign_extend 16) (bvadd (bvsub ?v_4 v_1) ((_ extract 48 16) (bvmul ?v_8 ((_ sign_extend 16) (bvshl ?v_4 (_ bv16 33)))))))) (?v_12 ((_ sign_extend 16) ((_ extract 48 16) (bvmul ?v_8 ((_ sign_extend 16) (bvshl ((_ sign_extend 31) ((_ extract 1 0) (_ bv1 32))) (_ bv16 33))))))) (?v_15 ((_ sign_extend 16) (bvadd t_elapse_cruise tad_elapse_cruise)))) (let ((?v_18 (bvadd x_r_init ((_ extract 48 16) (bvmul ?v_15 ?v_9)))) (?v_17 ((_ sign_extend 16) ((_ sign_extend 16) ((_ extract 16 0) (_ bv46160 32))))) (?v_20 ((_ sign_extend 16) (bvsub t_elapse_left tsd_elapse_left)))) (let ((?v_23 ((_ extract 48 16) (bvmul ((_ sign_extend 16) ((_ extract 48 16) (bvmul ((_ sign_extend 16) v_1) ?v_17))) ?v_20))) (?v_24 ((_ extract 48 16) (bvmul ((_ sign_extend 16) ((_ extract 48 16) (bvmul ?v_8 ?v_17))) ?v_20))) (?v_21 ((_ sign_extend 22) ((_ extract 10 0) (_ bv1000 32)))) (?v_22 ((_ sign_extend 21) ((_ extract 11 0) (_ bv2000 32)))) (?v_7 ((_ sign_extend 16) (bvshl ((_ sign_extend 27) ((_ extract 5 0) (_ bv30 32))) (_ bv16 33)))) (?v_3 ((_ sign_extend 16) x_r_init)) (?v_5 ((_ sign_extend 16) y_r_init)) (?v_14 ((_ sign_extend 16) ?v_18)) (?v_16 ((_ sign_extend 16) (bvadd y_r_init ((_ extract 48 16) (bvmul ?v_15 ?v_12)))))) (let ((?v_19 ((_ extract 48 16) (bvmul ?v_16 ?v_17)))) (let ((?v_25 (bvadd ((_ extract 48 16) (bvmul ?v_14 ?v_17)) ?v_19)) (?v_26 (bvadd ((_ extract 48 16) (bvmul ((_ sign_extend 16) (bvsub ?v_4 ?v_18)) ?v_17)) ?v_19)) (?v_27 ((_ sign_extend 16) (bvadd t_elapse_left tad_elapse_left))) (?v_10 ((_ sign_extend 16) (bvadd x_r_init ((_ extract 48 16) (bvmul ?v_11 ?v_9))))) (?v_13 ((_ sign_extend 16) (bvadd y_r_init ((_ extract 48 16) (bvmul ?v_11 ?v_12)))))) (let ((?v_29 ((_ extract 48 16) (bvmul ((_ sign_extend 16) (bvadd ?v_25 ((_ extract 48 16) (bvmul ?v_27 ?v_9)))) ?v_17))) (?v_30 ((_ extract 48 16) (bvmul ((_ sign_extend 16) (bvadd ?v_26 ((_ extract 48 16) (bvmul ?v_27 ?v_12)))) ?v_17)))) (let ((?v_32 (bvsub ?v_29 ?v_30)) (?v_34 (bvadd ?v_29 ?v_30)) (?v_35 ((_ sign_extend 16) (bvsub t_elapse_straight tsd_elapse_straight))) (?v_39 ((_ sign_extend 16) (bvadd t_elapse_straight tad_elapse_straight)))) (let ((?v_38 ((_ sign_extend 16) (bvadd ?v_32 ((_ extract 48 16) (bvmul ?v_39 ?v_9)))))) (let ((?v_42 ((_ extract 48 16) (bvmul ?v_38 ?v_17))) (?v_43 ((_ sign_extend 16) ?v_41))) (let ((?v_45 (bvadd (bvsub ?v_42 ?v_30) ((_ extract 48 16) (bvmul ?v_43 ?v_9)))) (?v_28 ((_ sign_extend 16) ?v_32)) (?v_31 ((_ sign_extend 16) ?v_34)) (?v_37 ((_ sign_extend 16) (bvshl ((_ sign_extend 25) ((_ extract 7 0) (_ bv120 32))) (_ bv16 33)))) (?v_33 ((_ sign_extend 16) (bvadd ?v_32 ((_ extract 48 16) (bvmul ?v_35 ?v_9))))) (?v_36 ((_ sign_extend 16) (bvadd ?v_34 ((_ extract 48 16) (bvmul ?v_35 ?v_12))))) (?v_40 ((_ sign_extend 16) (bvadd ?v_34 ((_ extract 48 16) (bvmul ?v_39 ?v_12))))) (?v_46 ((_ extract 48 16) (bvmul ((_ sign_extend 16) (bvadd (bvadd ?v_42 ?v_30) ((_ extract 48 16) (bvmul ?v_43 ?v_12)))) ?v_17)))) (let ((?v_44 ((_ sign_extend 16) (bvadd ((_ extract 48 16) (bvmul ((_ sign_extend 16) ?v_45) ?v_17)) ?v_46))) (?v_47 ((_ sign_extend 16) (bvadd ((_ extract 48 16) (bvmul ((_ sign_extend 16) (bvsub ?v_4 ?v_45)) ?v_17)) ?v_46)))) (not (=> (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (bvsle v_1 ?v_0) (bvsle v_1 ?v_1)) (bvsle v_2 ?v_0)) (bvsle v_2 ?v_1)) (or ?v_2 ?v_2)) (and (bvsle (bvsub ((_ extract 48 16) (bvmul ?v_3 ?v_3)) ?v_6) ((_ extract 48 16) (bvmul ?v_7 ((_ sign_extend 16) ((_ extract 48 16) (bvmul ?v_3 ?v_9)))))) (bvsle (bvsub ((_ extract 48 16) (bvmul ?v_5 ?v_5)) ?v_6) ((_ extract 48 16) (bvmul ?v_7 ((_ sign_extend 16) ((_ extract 48 16) (bvmul ?v_5 ?v_12)))))))) (and (and (and (bvsle (bvsub ((_ extract 48 16) (bvmul ?v_10 ?v_10)) ?v_6) ((_ extract 48 16) (bvmul ?v_7 ((_ sign_extend 16) ((_ extract 48 16) (bvmul ?v_10 ?v_9)))))) (bvsle (bvsub ((_ extract 48 16) (bvmul ?v_13 ?v_13)) ?v_6) ((_ extract 48 16) (bvmul ?v_7 ((_ sign_extend 16) ((_ extract 48 16) (bvmul ?v_13 ?v_12))))))) (bvsle tsd_elapse_cruise ?v_21)) (bvsle tsd_elapse_cruise ?v_22))) (and (bvslt ((_ extract 48 16) (bvmul ?v_7 ((_ sign_extend 16) ((_ extract 48 16) (bvmul ?v_14 ?v_9))))) (bvsub ((_ extract 48 16) (bvmul ?v_14 ?v_14)) ?v_6)) (bvslt ((_ extract 48 16) (bvmul ?v_7 ((_ sign_extend 16) ((_ extract 48 16) (bvmul ?v_16 ?v_12))))) (bvsub ((_ extract 48 16) (bvmul ?v_16 ?v_16)) ?v_6)))) (and (bvsle d ?v_25) (bvsle d ?v_26))) (and (and (or (bvsle d ?v_23) (bvsle d ?v_24)) (bvsle tsd_elapse_left ?v_21)) (bvsle tsd_elapse_left ?v_22))) (and (bvslt ?v_23 d) (bvslt ?v_24 d))) (and (bvsle (bvsub ((_ extract 48 16) (bvmul ?v_28 ?v_28)) ?v_6) ((_ extract 48 16) (bvmul ?v_7 ((_ sign_extend 16) ((_ extract 48 16) (bvmul ?v_28 ?v_9)))))) (bvsle (bvsub ((_ extract 48 16) (bvmul ?v_31 ?v_31)) ?v_6) ((_ extract 48 16) (bvmul ?v_7 ((_ sign_extend 16) ((_ extract 48 16) (bvmul ?v_31 ?v_12)))))))) (and (and (and (bvsle (bvsub ((_ extract 48 16) (bvmul ?v_33 ?v_33)) ?v_6) ((_ extract 48 16) (bvmul ?v_37 ((_ sign_extend 16) ((_ extract 48 16) (bvmul ?v_33 ?v_9)))))) (bvsle (bvsub ((_ extract 48 16) (bvmul ?v_36 ?v_36)) ?v_6) ((_ extract 48 16) (bvmul ?v_37 ((_ sign_extend 16) ((_ extract 48 16) (bvmul ?v_36 ?v_12))))))) (bvsle tsd_elapse_straight ?v_21)) (bvsle tsd_elapse_straight ?v_22))) (and (bvsle (bvsub ((_ extract 48 16) (bvmul ?v_38 ?v_38)) ?v_6) ((_ extract 48 16) (bvmul ?v_37 ((_ sign_extend 16) ((_ extract 48 16) (bvmul ?v_38 ?v_9)))))) (bvsle (bvsub ((_ extract 48 16) (bvmul ?v_40 ?v_40)) ?v_6) ((_ extract 48 16) (bvmul ?v_37 ((_ sign_extend 16) ((_ extract 48 16) (bvmul ?v_40 ?v_12)))))))) (bvsle (bvsub t_elapse_right tsd_elapse_right) t_elapse_left)) (bvslt t_elapse_left ?v_41)) (and (bvsle (bvsub ((_ extract 48 16) (bvmul ?v_44 ?v_44)) ?v_6) ((_ extract 48 16) (bvmul ?v_7 ((_ sign_extend 16) ((_ extract 48 16) (bvmul ?v_44 ?v_9)))))) (bvsle (bvsub ((_ extract 48 16) (bvmul ?v_47 ?v_47)) ?v_6) ((_ extract 48 16) (bvmul ?v_7 ((_ sign_extend 16) ((_ extract 48 16) (bvmul ?v_47 ?v_12))))))))))))))))))))))
(check-sat)
(exit)