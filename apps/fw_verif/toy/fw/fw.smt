(set-info :original "toy.bc")
(set-info :authors "SeaHorn v.0.1.0-rc3")
(declare-rel verifier.error (Bool Bool Bool ))
(declare-rel HW_REG_WRITE@_1 ((Array Int Int) Int Int ))
(declare-rel HW_REG_WRITE@.split ((Array Int Int) (Array Int Int) Int Int ))
(declare-rel HW_REG_WRITE (Bool Bool Bool (Array Int Int) (Array Int Int) Int Int ))
(declare-rel writecWrap@_1 (Bool (Array Int Int) Int Int Int ))
(declare-rel writecWrap@_5 (Bool (Array Int Int) Int Int Int ))
(declare-rel writecWrap@_call (Bool (Array Int Int) Int Int Int ))
(declare-rel writecWrap@_9 (Bool (Array Int Int) Int Int Int ))
(declare-rel writecWrap@.split (Bool (Array Int Int) (Array Int Int) Int Int Int ))
(declare-rel writecWrap (Bool Bool Bool (Array Int Int) (Array Int Int) Int Int Int ))
(declare-rel startAcc@_1 (Bool Int (Array Int Int) ))
(declare-rel startAcc@_7 (Bool Int (Array Int Int) (Array Int Int) ))
(declare-rel startAcc@_br3 (Bool Int (Array Int Int) (Array Int Int) ))
(declare-rel startAcc@_call4 (Bool Int (Array Int Int) (Array Int Int) ))
(declare-rel startAcc (Bool Bool Bool (Array Int Int) (Array Int Int) Int ))
(declare-rel main@_1 (Bool (Array Int Int) ))
(declare-rel main@_call3 (Bool ))
(declare-rel main@_11 (Bool Int (Array Int Int) ))
(declare-rel main@_call7 (Bool ))
(declare-rel main@_call8 (Bool ))
(declare-rel main@UnifiedUnreachableBlock (Bool ))
(declare-var HW_REG_WRITE@%_3_0 Int )
(declare-var HW_REG_WRITE@%data_0 Int )
(declare-var HW_REG_WRITE@%addr_0 Int )
(declare-var HW_REG_WRITE@%_2_0 (Array Int Int) )
(declare-var HW_REG_WRITE@%_store_0 (Array Int Int) )
(declare-var writecWrap@%_10_0 Int )
(declare-var writecWrap@%data_0 Int )
(declare-var writecWrap@%_6_0 Int )
(declare-var writecWrap@%_br1_0 Bool )
(declare-var writecWrap@%_3_0 Int )
(declare-var writecWrap@%_br_0 Bool )
(declare-var writecWrap@%_2_0 (Array Int Int) )
(declare-var writecWrap@%_call2_0 (Array Int Int) )
(declare-var writecWrap@%addr_0 Int )
(declare-var @acc_ptr_0 Int )
(declare-var error.flag_0 Bool )
(declare-var error.flag_1 Bool )
(declare-var startAcc@%_call2_0 Int )
(declare-var startAcc@%_9_0 Int )
(declare-var startAcc@%_10_0 Int )
(declare-var startAcc@%_br_0 Bool )
(declare-var startAcc@%_3_0 Int )
(declare-var startAcc@%_call_0 (Array Int Int) )
(declare-var startAcc@%_5_0 Int )
(declare-var startAcc@%_2_0 (Array Int Int) )
(declare-var startAcc@%_call1_0 (Array Int Int) )
(declare-var error.flag_2 Bool )
(declare-var main@%_12_0 Int )
(declare-var main@%_store_0 (Array Int Int) )
(declare-var main@%_call4_0 (Array Int Int) )
(declare-var main@%_call5_0 Int )
(declare-var main@%_16_0 Int )
(declare-var main@%_17_0 Int )
(declare-var main@%_br6_0 Bool )
(declare-var main@%_3_0 Int )
(declare-var main@%_call_0 Bool )
(declare-var main@%_call1_0 Int )
(declare-var main@%_6_0 Int )
(declare-var main@%_7_0 Int )
(declare-var main@%_call2_0 Bool )
(declare-var main@%_br_0 Bool )
(declare-var main@%_2_0 (Array Int Int) )
(rule (verifier.error false false false))
(rule (verifier.error false true true))
(rule (verifier.error true false true))
(rule (verifier.error true true true))
(rule (HW_REG_WRITE true
              true
              true
              HW_REG_WRITE@%_2_0
              HW_REG_WRITE@%_store_0
              HW_REG_WRITE@%addr_0
              HW_REG_WRITE@%data_0))
(rule (HW_REG_WRITE false
              true
              true
              HW_REG_WRITE@%_2_0
              HW_REG_WRITE@%_store_0
              HW_REG_WRITE@%addr_0
              HW_REG_WRITE@%data_0))
(rule (HW_REG_WRITE false
              false
              false
              HW_REG_WRITE@%_2_0
              HW_REG_WRITE@%_store_0
              HW_REG_WRITE@%addr_0
              HW_REG_WRITE@%data_0))
(rule (HW_REG_WRITE@_1 HW_REG_WRITE@%_2_0 HW_REG_WRITE@%data_0 HW_REG_WRITE@%addr_0))
(rule (=> (and (HW_REG_WRITE@_1 HW_REG_WRITE@%_2_0
                          HW_REG_WRITE@%data_0
                          HW_REG_WRITE@%addr_0)
         true
         (= HW_REG_WRITE@%_3_0 HW_REG_WRITE@%data_0)
         (= HW_REG_WRITE@%_store_0
            (store HW_REG_WRITE@%_2_0 HW_REG_WRITE@%addr_0 HW_REG_WRITE@%_3_0)))
    (HW_REG_WRITE@.split
      HW_REG_WRITE@%_2_0
      HW_REG_WRITE@%_store_0
      HW_REG_WRITE@%data_0
      HW_REG_WRITE@%addr_0)))
(rule (=> (HW_REG_WRITE@.split
      HW_REG_WRITE@%_2_0
      HW_REG_WRITE@%_store_0
      HW_REG_WRITE@%data_0
      HW_REG_WRITE@%addr_0)
    (HW_REG_WRITE true
                  false
                  false
                  HW_REG_WRITE@%_2_0
                  HW_REG_WRITE@%_store_0
                  HW_REG_WRITE@%addr_0
                  HW_REG_WRITE@%data_0)))
(rule (writecWrap true
            true
            true
            writecWrap@%_2_0
            writecWrap@%_call2_0
            writecWrap@%addr_0
            writecWrap@%data_0
            @acc_ptr_0))
(rule (writecWrap false
            true
            true
            writecWrap@%_2_0
            writecWrap@%_call2_0
            writecWrap@%addr_0
            writecWrap@%data_0
            @acc_ptr_0))
(rule (writecWrap false
            false
            false
            writecWrap@%_2_0
            writecWrap@%_call2_0
            writecWrap@%addr_0
            writecWrap@%data_0
            @acc_ptr_0))
(rule (=> (not error.flag_0)
    (writecWrap@_1 error.flag_0
                   writecWrap@%_2_0
                   writecWrap@%data_0
                   writecWrap@%addr_0
                   @acc_ptr_0)))
(rule (let ((a!1 (and (writecWrap@_1 error.flag_0
                               writecWrap@%_2_0
                               writecWrap@%data_0
                               writecWrap@%addr_0
                               @acc_ptr_0)
                (not error.flag_0)
                (= writecWrap@%_3_0 (+ @acc_ptr_0 (* 0 20) 0))
                (or (<= @acc_ptr_0 0) (> writecWrap@%_3_0 0))
                (= writecWrap@%_br_0 (= writecWrap@%addr_0 writecWrap@%_3_0))
                (or error.flag_0 writecWrap@%_br_0))))
  (=> a!1
      (writecWrap@_9 error.flag_0
                     writecWrap@%_2_0
                     writecWrap@%data_0
                     writecWrap@%addr_0
                     @acc_ptr_0))))
(rule (let ((a!1 (and (writecWrap@_1 error.flag_0
                               writecWrap@%_2_0
                               writecWrap@%data_0
                               writecWrap@%addr_0
                               @acc_ptr_0)
                (not error.flag_0)
                (= writecWrap@%_3_0 (+ @acc_ptr_0 (* 0 20) 0))
                (or (<= @acc_ptr_0 0) (> writecWrap@%_3_0 0))
                (= writecWrap@%_br_0 (= writecWrap@%addr_0 writecWrap@%_3_0))
                (or error.flag_0 (not writecWrap@%_br_0)))))
  (=> a!1
      (writecWrap@_5 error.flag_0
                     writecWrap@%_2_0
                     writecWrap@%data_0
                     writecWrap@%addr_0
                     @acc_ptr_0))))
(rule (let ((a!1 (and (writecWrap@_5 error.flag_0
                               writecWrap@%_2_0
                               writecWrap@%data_0
                               writecWrap@%addr_0
                               @acc_ptr_0)
                (not error.flag_0)
                (= writecWrap@%_6_0 (+ @acc_ptr_0 (* 0 20) 1))
                (or (<= @acc_ptr_0 0) (> writecWrap@%_6_0 0))
                (= writecWrap@%_br1_0 (= writecWrap@%addr_0 writecWrap@%_6_0))
                (or error.flag_0 writecWrap@%_br1_0))))
  (=> a!1
      (writecWrap@_9 error.flag_0
                     writecWrap@%_2_0
                     writecWrap@%data_0
                     writecWrap@%addr_0
                     @acc_ptr_0))))
(rule (let ((a!1 (and (writecWrap@_5 error.flag_0
                               writecWrap@%_2_0
                               writecWrap@%data_0
                               writecWrap@%addr_0
                               @acc_ptr_0)
                (not error.flag_0)
                (= writecWrap@%_6_0 (+ @acc_ptr_0 (* 0 20) 1))
                (or (<= @acc_ptr_0 0) (> writecWrap@%_6_0 0))
                (= writecWrap@%_br1_0 (= writecWrap@%addr_0 writecWrap@%_6_0))
                (or error.flag_0 (not writecWrap@%_br1_0))
                (verifier.error true error.flag_0 error.flag_1))))
  (=> a!1
      (writecWrap@_call error.flag_1
                        writecWrap@%_2_0
                        writecWrap@%data_0
                        writecWrap@%addr_0
                        @acc_ptr_0))))
(rule (=> (and (writecWrap@_9 error.flag_0
                        writecWrap@%_2_0
                        writecWrap@%data_0
                        writecWrap@%addr_0
                        @acc_ptr_0)
         (not error.flag_0)
         (= writecWrap@%_10_0 writecWrap@%data_0)
         (HW_REG_WRITE true
                       error.flag_0
                       error.flag_1
                       writecWrap@%_2_0
                       writecWrap@%_call2_0
                       writecWrap@%addr_0
                       writecWrap@%_10_0))
    (writecWrap@.split
      error.flag_1
      writecWrap@%_2_0
      writecWrap@%_call2_0
      writecWrap@%data_0
      writecWrap@%addr_0
      @acc_ptr_0)))
(rule (=> (and (writecWrap@_1 error.flag_0
                        writecWrap@%_2_0
                        writecWrap@%data_0
                        writecWrap@%addr_0
                        @acc_ptr_0)
         error.flag_0)
    (writecWrap@.split
      error.flag_0
      writecWrap@%_2_0
      writecWrap@%_call2_0
      writecWrap@%data_0
      writecWrap@%addr_0
      @acc_ptr_0)))
(rule (=> (and (writecWrap@_5 error.flag_0
                        writecWrap@%_2_0
                        writecWrap@%data_0
                        writecWrap@%addr_0
                        @acc_ptr_0)
         error.flag_0)
    (writecWrap@.split
      error.flag_0
      writecWrap@%_2_0
      writecWrap@%_call2_0
      writecWrap@%data_0
      writecWrap@%addr_0
      @acc_ptr_0)))
(rule (=> (and (writecWrap@_call error.flag_0
                           writecWrap@%_2_0
                           writecWrap@%data_0
                           writecWrap@%addr_0
                           @acc_ptr_0)
         error.flag_0)
    (writecWrap@.split
      error.flag_0
      writecWrap@%_2_0
      writecWrap@%_call2_0
      writecWrap@%data_0
      writecWrap@%addr_0
      @acc_ptr_0)))
(rule (=> (and (writecWrap@_9 error.flag_0
                        writecWrap@%_2_0
                        writecWrap@%data_0
                        writecWrap@%addr_0
                        @acc_ptr_0)
         error.flag_0)
    (writecWrap@.split
      error.flag_0
      writecWrap@%_2_0
      writecWrap@%_call2_0
      writecWrap@%data_0
      writecWrap@%addr_0
      @acc_ptr_0)))
(rule (=> (and (writecWrap@.split
           error.flag_0
           writecWrap@%_2_0
           writecWrap@%_call2_0
           writecWrap@%data_0
           writecWrap@%addr_0
           @acc_ptr_0)
         (not error.flag_0))
    (writecWrap true
                false
                false
                writecWrap@%_2_0
                writecWrap@%_call2_0
                writecWrap@%addr_0
                writecWrap@%data_0
                @acc_ptr_0)))
(rule (=> (and (writecWrap@.split
           error.flag_0
           writecWrap@%_2_0
           writecWrap@%_call2_0
           writecWrap@%data_0
           writecWrap@%addr_0
           @acc_ptr_0)
         error.flag_0)
    (writecWrap true
                false
                true
                writecWrap@%_2_0
                writecWrap@%_call2_0
                writecWrap@%addr_0
                writecWrap@%data_0
                @acc_ptr_0)))
(rule (startAcc true true true startAcc@%_2_0 startAcc@%_call1_0 @acc_ptr_0))
(rule (startAcc false true true startAcc@%_2_0 startAcc@%_call1_0 @acc_ptr_0))
(rule (startAcc false false false startAcc@%_2_0 startAcc@%_call1_0 @acc_ptr_0))
(rule (=> (not error.flag_0) (startAcc@_1 error.flag_0 @acc_ptr_0 startAcc@%_2_0)))
(rule (let ((a!1 (= startAcc@%_3_0 (+ (+ @acc_ptr_0 (* 0 20)) 0)))
      (a!2 (= startAcc@%_5_0 (+ (+ @acc_ptr_0 (* 0 20)) 1))))
  (=> (and (startAcc@_1 error.flag_0 @acc_ptr_0 startAcc@%_2_0)
           (not error.flag_0)
           a!1
           (or (<= @acc_ptr_0 0) (> startAcc@%_3_0 0))
           (writecWrap true
                       error.flag_0
                       error.flag_1
                       startAcc@%_2_0
                       startAcc@%_call_0
                       startAcc@%_3_0
                       1
                       @acc_ptr_0)
           a!2
           (or (<= @acc_ptr_0 0) (> startAcc@%_5_0 0))
           (writecWrap true
                       error.flag_1
                       error.flag_2
                       startAcc@%_call_0
                       startAcc@%_call1_0
                       startAcc@%_5_0
                       1
                       @acc_ptr_0))
      (startAcc@_7 error.flag_2 @acc_ptr_0 startAcc@%_2_0 startAcc@%_call1_0))))
(rule (let ((a!1 (and (startAcc@_7 error.flag_0
                             @acc_ptr_0
                             startAcc@%_2_0
                             startAcc@%_call1_0)
                (not error.flag_0)
                (= startAcc@%_call2_0 (+ @acc_ptr_0 (* 0 20) 1))
                (or (<= @acc_ptr_0 0) (> startAcc@%_call2_0 0))
                (> @acc_ptr_0 0)
                (= startAcc@%_9_0
                   (select startAcc@%_call1_0 startAcc@%_call2_0))
                (= startAcc@%_10_0 startAcc@%_9_0)
                (= startAcc@%_br_0 (not (= startAcc@%_10_0 0)))
                (or error.flag_0 startAcc@%_br_0))))
  (=> a!1
      (startAcc@_br3 error.flag_0 @acc_ptr_0 startAcc@%_2_0 startAcc@%_call1_0))))
(rule (let ((a!1 (and (startAcc@_7 error.flag_0
                             @acc_ptr_0
                             startAcc@%_2_0
                             startAcc@%_call1_0)
                (not error.flag_0)
                (= startAcc@%_call2_0 (+ @acc_ptr_0 (* 0 20) 1))
                (or (<= @acc_ptr_0 0) (> startAcc@%_call2_0 0))
                (> @acc_ptr_0 0)
                (= startAcc@%_9_0
                   (select startAcc@%_call1_0 startAcc@%_call2_0))
                (= startAcc@%_10_0 startAcc@%_9_0)
                (= startAcc@%_br_0 (not (= startAcc@%_10_0 0)))
                (or error.flag_0 (not startAcc@%_br_0)))))
  (=> a!1
      (startAcc@_call4 error.flag_0
                       @acc_ptr_0
                       startAcc@%_2_0
                       startAcc@%_call1_0))))
(rule (=> (and (startAcc@_br3 error.flag_0
                        @acc_ptr_0
                        startAcc@%_2_0
                        startAcc@%_call1_0)
         (not error.flag_0))
    (startAcc@_7 error.flag_0 @acc_ptr_0 startAcc@%_2_0 startAcc@%_call1_0)))
(rule (=> (and (startAcc@_1 error.flag_0 @acc_ptr_0 startAcc@%_2_0) error.flag_0)
    (startAcc@_call4 error.flag_0 @acc_ptr_0 startAcc@%_2_0 startAcc@%_call1_0)))
(rule (=> (and (startAcc@_7 error.flag_0 @acc_ptr_0 startAcc@%_2_0 startAcc@%_call1_0)
         error.flag_0)
    (startAcc@_call4 error.flag_0 @acc_ptr_0 startAcc@%_2_0 startAcc@%_call1_0)))
(rule (=> (and (startAcc@_br3 error.flag_0
                        @acc_ptr_0
                        startAcc@%_2_0
                        startAcc@%_call1_0)
         error.flag_0)
    (startAcc@_call4 error.flag_0 @acc_ptr_0 startAcc@%_2_0 startAcc@%_call1_0)))
(rule (=> (and (startAcc@_call4 error.flag_0
                          @acc_ptr_0
                          startAcc@%_2_0
                          startAcc@%_call1_0)
         (not error.flag_0))
    (startAcc true false false startAcc@%_2_0 startAcc@%_call1_0 @acc_ptr_0)))
(rule (=> (and (startAcc@_call4 error.flag_0
                          @acc_ptr_0
                          startAcc@%_2_0
                          startAcc@%_call1_0)
         error.flag_0)
    (startAcc true false true startAcc@%_2_0 startAcc@%_call1_0 @acc_ptr_0)))
(rule (=> (not error.flag_0) (main@_1 error.flag_0 main@%_2_0)))
(rule (let ((a!1 (and (main@_1 error.flag_0 main@%_2_0)
                (not error.flag_0)
                (= main@%_3_0 65024)
                (= main@%_call_0 (= main@%_3_0 @acc_ptr_0))
                (or error.flag_0 main@%_call_0)
                (= main@%_call1_0 (+ @acc_ptr_0 (* 0 20) 1))
                (or (<= @acc_ptr_0 0) (> main@%_call1_0 0))
                (> @acc_ptr_0 0)
                (= main@%_6_0 (select main@%_2_0 main@%_call1_0))
                (= main@%_7_0 main@%_6_0)
                (= main@%_call2_0 (= main@%_7_0 0))
                (or error.flag_0 main@%_call2_0)
                (= main@%_br_0 (= 0 0))
                (or error.flag_0 main@%_br_0))))
  (=> a!1 (main@_11 error.flag_0 @acc_ptr_0 main@%_2_0))))
(rule (let ((a!1 (and (main@_1 error.flag_0 main@%_2_0)
                (not error.flag_0)
                (= main@%_3_0 65024)
                (= main@%_call_0 (= main@%_3_0 @acc_ptr_0))
                (or error.flag_0 main@%_call_0)
                (= main@%_call1_0 (+ @acc_ptr_0 (* 0 20) 1))
                (or (<= @acc_ptr_0 0) (> main@%_call1_0 0))
                (> @acc_ptr_0 0)
                (= main@%_6_0 (select main@%_2_0 main@%_call1_0))
                (= main@%_7_0 main@%_6_0)
                (= main@%_call2_0 (= main@%_7_0 0))
                (or error.flag_0 main@%_call2_0)
                (= main@%_br_0 (= 0 0))
                (or error.flag_0 (not main@%_br_0)))))
  (=> a!1 (main@_call3 error.flag_0))))
(rule (=> (and (main@_call3 error.flag_0)
         (not error.flag_0)
         (verifier.error true error.flag_0 error.flag_1))
    (main@UnifiedUnreachableBlock error.flag_1)))
(rule (let ((a!1 (= main@%_12_0 (+ (+ @acc_ptr_0 (* 0 20)) 12)))
      (a!2 (= main@%_call5_0 (+ (+ @acc_ptr_0 (* 0 20)) 1))))
  (=> (and (main@_11 error.flag_0 @acc_ptr_0 main@%_2_0)
           (not error.flag_0)
           a!1
           (or (<= @acc_ptr_0 0) (> main@%_12_0 0))
           (> @acc_ptr_0 0)
           (= main@%_store_0 (store main@%_2_0 main@%_12_0 3))
           (startAcc true
                     error.flag_0
                     error.flag_1
                     main@%_store_0
                     main@%_call4_0
                     @acc_ptr_0)
           a!2
           (or (<= @acc_ptr_0 0) (> main@%_call5_0 0))
           (> @acc_ptr_0 0)
           (= main@%_16_0 (select main@%_call4_0 main@%_call5_0))
           (= main@%_17_0 main@%_16_0)
           (= main@%_br6_0 (= main@%_17_0 0))
           (or error.flag_1 main@%_br6_0))
      (main@_call8 error.flag_1))))
(rule (let ((a!1 (= main@%_12_0 (+ (+ @acc_ptr_0 (* 0 20)) 12)))
      (a!2 (= main@%_call5_0 (+ (+ @acc_ptr_0 (* 0 20)) 1))))
  (=> (and (main@_11 error.flag_0 @acc_ptr_0 main@%_2_0)
           (not error.flag_0)
           a!1
           (or (<= @acc_ptr_0 0) (> main@%_12_0 0))
           (> @acc_ptr_0 0)
           (= main@%_store_0 (store main@%_2_0 main@%_12_0 3))
           (startAcc true
                     error.flag_0
                     error.flag_1
                     main@%_store_0
                     main@%_call4_0
                     @acc_ptr_0)
           a!2
           (or (<= @acc_ptr_0 0) (> main@%_call5_0 0))
           (> @acc_ptr_0 0)
           (= main@%_16_0 (select main@%_call4_0 main@%_call5_0))
           (= main@%_17_0 main@%_16_0)
           (= main@%_br6_0 (= main@%_17_0 0))
           (or error.flag_1 (not main@%_br6_0)))
      (main@_call7 error.flag_1))))
(rule (=> (and (main@_call7 error.flag_0)
         (not error.flag_0)
         (verifier.error true error.flag_0 error.flag_1))
    (main@UnifiedUnreachableBlock error.flag_1)))
(rule (=> (and (main@_1 error.flag_0 main@%_2_0) error.flag_0)
    (main@_call8 error.flag_0)))
(rule (=> (and (main@_call3 error.flag_0) error.flag_0) (main@_call8 error.flag_0)))
(rule (=> (and (main@_11 error.flag_0 @acc_ptr_0 main@%_2_0) error.flag_0)
    (main@_call8 error.flag_0)))
(rule (=> (and (main@_call7 error.flag_0) error.flag_0) (main@_call8 error.flag_0)))
(rule (=> (and (main@UnifiedUnreachableBlock error.flag_0) error.flag_0)
    (main@_call8 error.flag_0)))
(query (main@_call8 true))

