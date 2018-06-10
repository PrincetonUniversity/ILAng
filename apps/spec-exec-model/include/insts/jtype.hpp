		// J-type is not speculative under current model
        // ------------------------- Instruction: JAL ------------------------------ //
        {
            auto instr = model.NewInstr("JAL" NAME_SUFFIX);
            auto decode = (opcode == JAL )  & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);

            UPDATE_PC( pc + immJ ); // will set spc if executed speculatively
            UPDATE_R( rd, NC);
            EXECUTE_IF_SPEC;
            
            RECORD_INST("JAL" NAME_SUFFIX);
        }
        // ------------------------- Instruction: JALR ------------------------------ //
        {
            auto instr = model.NewInstr("JALR" NAME_SUFFIX);
            auto decode = (opcode == JALR )  & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);


            UPDATE_PC( (rs1_val + immI) & bv(0xFFFFFFFE) ); // will set spc if executed speculatively
            UPDATE_R( rd, NC);
            EXECUTE_IF_SPEC;
            
            RECORD_INST("JALR" NAME_SUFFIX);
        }
