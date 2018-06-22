
        // ------------------------- Instruction: BEQ ------------------------------ //
        {
            auto instr = model.NewInstr("BEQ" NAME_SUFFIX);
            auto decode = (opcode == BRANCH ) & (funct3 == BEQ ) & interruptCondition() & EXEC_COND;
            instr.SetDecode(decode);
																  // 1.		  2. RESOLVE	3. SPEC
            START_SPECULATION;									  // SPEC /     ---			/     ---
            UPDATE_PC( Ite( rs1_val == rs2_val , BTarget, NC ) ); // ---  / pc := new_val   / pc := non_det
            EXECUTE_IF_SPEC;									  // ---  / seflag := false / sc := sc + 1 
            RECORD_INST("BEQ" NAME_SUFFIX);
        }
        // ------------------------- Instruction: BNE ------------------------------ //
        {
            auto instr = model.NewInstr("BNE" NAME_SUFFIX);
            auto decode = (opcode == BRANCH ) & (funct3 == BNE ) & interruptCondition() & EXEC_COND;
            instr.SetDecode(decode);

            START_SPECULATION;
            UPDATE_PC( Ite( rs1_val != rs2_val , BTarget, NC ) );
            EXECUTE_IF_SPEC;
            RECORD_INST("BNE" NAME_SUFFIX);
        }
        // ------------------------- Instruction: BLT ------------------------------ //
        {
            auto instr = model.NewInstr("BLT" NAME_SUFFIX);
            auto decode = (opcode == BRANCH ) & (funct3 == BLT ) & interruptCondition() & EXEC_COND;
            instr.SetDecode(decode);

            START_SPECULATION;
            // this is the signed comparison
            UPDATE_PC( Ite( rs1_val < rs2_val , BTarget, NC ) );
            EXECUTE_IF_SPEC;
            RECORD_INST("BLT" NAME_SUFFIX);
        }
        // ------------------------- Instruction: BLTU ------------------------------ //
        {
            auto instr = model.NewInstr("BLTU" NAME_SUFFIX);
            auto decode = (opcode == BRANCH ) & (funct3 == BLTU ) & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);

            START_SPECULATION;
            // this is the unsigned comparison
            UPDATE_PC( Ite( Ult(rs1_val , rs2_val) , BTarget, NC ) );
            EXECUTE_IF_SPEC;
            RECORD_INST("BLTU" NAME_SUFFIX);
        }
        // ------------------------- Instruction: BGE ------------------------------ //
        {
            auto instr = model.NewInstr("BGE" NAME_SUFFIX);
            auto decode = (opcode == BRANCH ) & (funct3 == BGE ) & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);

            START_SPECULATION;
            UPDATE_PC( Ite( rs1_val >= rs2_val , BTarget, NC ) );
            EXECUTE_IF_SPEC;
            RECORD_INST("BGE" NAME_SUFFIX);
        }
        // ------------------------- Instruction: BGEU ------------------------------ //
        {
            auto instr = model.NewInstr("BGEU" NAME_SUFFIX);
            auto decode = (opcode == BRANCH ) & (funct3 == BGEU ) & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);

            START_SPECULATION;
            UPDATE_PC( Ite( Uge(rs1_val , rs2_val) , BTarget, NC ) );
            EXECUTE_IF_SPEC;
            RECORD_INST("BGEU" NAME_SUFFIX);
        }
