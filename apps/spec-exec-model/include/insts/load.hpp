
        // ------------------------- Instruction: LW ------------------------------ //
        {
            auto instr = model.NewInstr("LW" NAME_SUFFIX);
            auto decode = ( opcode == LOAD ) & ( funct3 == WORD ) &  interruptCondition()  &  EXEC_COND ;
            instr.SetDecode(decode);

            EXECUTE_IF_SPEC;
            UPDATE_PC(nxt_pc);
            UPDATE_R( rd, getSlice(lw_val, addr(1,0) , CWORD , 0 )  );
            
            RECORD_INST("LW" NAME_SUFFIX);
        }

        // ------------------------- Instruction: LH ------------------------------ //
        {
            auto instr = model.NewInstr("LH" NAME_SUFFIX);
            auto decode = ( opcode == LOAD ) & ( funct3 == HALF ) & interruptCondition()  &  EXEC_COND ;
            instr.SetDecode(decode);

            EXECUTE_IF_SPEC;
            UPDATE_PC(nxt_pc);
            UPDATE_R( rd, getSlice(lw_val, addr(1,0) , CHALF , 0 )  );
            
            RECORD_INST("LH" NAME_SUFFIX);
        }

        // ------------------------- Instruction: LB ------------------------------ //
        {
            auto instr = model.NewInstr("LB" NAME_SUFFIX);
            auto decode = ( opcode == LOAD ) & ( funct3 == BYTE) & interruptCondition()  &  EXEC_COND ;
            instr.SetDecode(decode);

            EXECUTE_IF_SPEC;
            UPDATE_PC(nxt_pc);
            UPDATE_R( rd, getSlice(lw_val, addr(1,0) , CBYTE , 0 )  );
            
            RECORD_INST("LB" NAME_SUFFIX);
        }
        // ------------------------- Instruction: LHU ------------------------------ //
        {
            auto instr = model.NewInstr("LHU" NAME_SUFFIX);
            auto decode = ( opcode == LOAD ) & ( funct3 == HALF)  & interruptCondition()  &  EXEC_COND ;
            instr.SetDecode(decode);

            EXECUTE_IF_SPEC;
            UPDATE_PC(nxt_pc);
            UPDATE_R( rd, getSlice(lw_val, addr(1,0) , CHALF , 1 )  );
            
            RECORD_INST("LHU" NAME_SUFFIX);
        }

        // ------------------------- Instruction: LBU ------------------------------ //
        {
            auto instr = model.NewInstr("LBU" NAME_SUFFIX);
            auto decode = ( opcode == LOAD ) & ( funct3 == BYTE ) & interruptCondition()  &  EXEC_COND ;
            instr.SetDecode(decode);

            EXECUTE_IF_SPEC;
            UPDATE_PC(nxt_pc);
            UPDATE_R( rd, getSlice(lw_val, addr(1,0) , CBYTE , 1 )  );
            
            RECORD_INST("LBU" NAME_SUFFIX);
        }
