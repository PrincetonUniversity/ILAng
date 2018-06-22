

        // ------------------------- Instruction: SW ------------------------------ //
        {
            auto instr = model.NewInstr("SW" NAME_SUFFIX);
            auto decode = ( opcode == STORE ) & ( funct3 == WORD ) & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);

            UPDATE_PC(nxt_pc);

            EXECUTE_IF_SPEC;
            auto store_value = CombineSlices( rs2_val, addr(1,0), CWORD, old_val );
            UPDATE_MEM(word_addr, store_value);

            RECORD_INST("SW" NAME_SUFFIX);
        }

        // ------------------------- Instruction: SH ------------------------------ //
        {
            auto instr = model.NewInstr("SH" NAME_SUFFIX);
            auto decode = ( opcode == STORE ) & ( funct3 == WORD )  & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);

            UPDATE_PC(nxt_pc);

            EXECUTE_IF_SPEC;
            auto store_value = CombineSlices( rs2_val, addr(1,0), CHALF, old_val );
            UPDATE_MEM(word_addr, store_value);

            RECORD_INST("SH" NAME_SUFFIX);
        }

        // ------------------------- Instruction: SB ------------------------------ //
        {
            auto instr = model.NewInstr("SB" NAME_SUFFIX);
            auto decode = ( opcode == STORE ) & ( funct3 == WORD ) & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);

            UPDATE_PC(nxt_pc);

            EXECUTE_IF_SPEC;
            auto store_value = CombineSlices( rs2_val, addr(1,0), CBYTE, old_val );
            UPDATE_MEM(word_addr, store_value);

            RECORD_INST("SB" NAME_SUFFIX);
        }

