## README

This is the summary of the ILA for RBM

- RBM: top level

    input:
        rst
        conf_done
        conf_num_*  (* = hidden, visible, user, loops, testusers, movies)
        rd/wr_grant
        data_in

    output:
        data_out
        rd_*        (* = request, index, length, )
        done
    reg:
        init_done
        num_*       (* = hidden, visible, user, loops, testusers, movies)
        rd_granted/wr_granted
    mem:
        data
        predict_result

    Instrctions:
        reset, confDone, rdGrant, wrGrant


- ComputeUABS: parent RBM <init_done == 1 & done == 0>
    reg:
        index
        loop_count
        upc
        train_input_done
        predict_input_done
    mem:
        edges

    Instructions:
        StartRead, WaitReadComplete, DecideTrainOrPredict, StartTrain, StartPredict, Finish

- LoadUABS: parent RBM (DMAload)  <rd_granted == 1>
    reg:
        i
    Instructions:
        (Read)

- TrainUABS parent ComputeUABS (train) <train_input_done == 1>
    reg:
        train_sum
        train_max
        jstate : (j : 0 - K-1)
        train_upc
        inner_loop_pc (per_v_pc)
        v_cnt
        h_cnt
        sumOfpow2
    mem: 
        hidden_unit
        visible_unit
        pos
        visibleEnergies
        pow2
    fun:
        sigmoid
        rand
        to_int_exp
        divide
    
    Instruction:
        1. SumEdge, 2. SumHidden, 3. StorePos 4. EdgeUpdate

    Instruction Semantics
        1.  v/h + 
                v(==nv) & h(==nh-1) -> exit,
            SUM:
                when v == 0, reset sum = 0
                always, sum += data[v]? edge[v][h] : 0
            hidden_unit:
                when v == nv , hidden_unit[h] <= sum_next (include data[nv],edge[nv])
                when exit, hidden_unit[nh] <+= 1 (extra store)

        2.  for(v,v+=4; )
            {
                for(j)
                    when j == 0,  reset max = -500 (fp)
                    for(h)
                        when h == 0 , reset sum to 0
                        sum += hidden[h] ? edge[v][h] : 0
                        when lastH, max = max (max, sum)
                for(j)
                    when j == 0, max -= 31
                    visibleEnergis[j] = visibleEnergies[j] - max

                for(j)
                    when j ==0, reset sumOfpow2
                    pow2[j] = to_int_exp( visibleEnergies[j] )
                    sumOfpow2 += sumOfpow2 + to_int_exp( visibleEnergies[j] )
                for(j)
                    visible_unit[v+j] = div(pow2[j], sumOfpow2 ) > rand() ? 1 : 0
                    when LastV & LastJ, visible_unit[nv] = 1
            }

        3. StorePos
            h/v+ -> exit
            pos[v][h] = (data[v] != 2)  ? ( data[v] && hidden_unit[h] )

        4. UpdateEdge
            h/v + -> hold
            _neg = hidden_unit[h] & visible_unit[v] 
            edge[v][h] = pos[v][h] & ~neg ? edge[v][h] + rate 
                         ~pos[v][h] & neg ? edge[v][h] - rate 

            set predict_input_done == 0


- PredictUABS parent ComputeUABS (predict) <predict_input_done == 1>
    reg:
        predict_sum
        predict_max
        per_v_pc
        predict_upc
        predict_v_cnt
        predict_h_cnt
        count
        jstate
        expectation
        prediction
        sumOfpow2
        pow2
        (*num_* *)

    mem:
        hidden_unit
        visibleEnergies
        predict_vector
        (*predict_result*)
        (*data*)
        (*edges*)

    fun:
        sigmoid
        rand
        to_int_exp
        round
        divide

    Instructions:
        SumEdge, SumHidden, GenResult, WaitForWrite







