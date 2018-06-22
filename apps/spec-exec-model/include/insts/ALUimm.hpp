
        // ------------------------- Instruction: ADDI ------------------------------ //
        {
            auto instr = model.NewInstr("ADDI" NAME_SUFFIX);
            auto decode = ( opcode == OPIMM ) & ( funct3 == ADDI ) & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);

            EXECUTE_IF_SPEC;
            UPDATE_PC(nxt_pc);
            UPDATE_R( rd,  rs1_val + immI );
            
            RECORD_INST("ADDI" NAME_SUFFIX);
        }
        // ------------------------- Instruction: SLTI ------------------------------ //
        {
            auto instr = model.NewInstr("SLTI" NAME_SUFFIX);
            auto decode = ( opcode == OPIMM ) & ( funct3 == SLTI ) & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);

            EXECUTE_IF_SPEC;
            UPDATE_PC(nxt_pc);
            UPDATE_R( rd,  Ite(rs1_val < immI , bv(1) , bv(0) ) ); // This is signed comparison
            
            RECORD_INST("SLTI" NAME_SUFFIX);
        }
        // ------------------------- Instruction: SLTIU ------------------------------ //
        {
            auto instr = model.NewInstr("SLTIU" NAME_SUFFIX);
            auto decode = ( opcode == OPIMM ) & ( funct3 == SLTIU ) & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);

            EXECUTE_IF_SPEC;
            UPDATE_PC(nxt_pc);
            UPDATE_R( rd,  Ite( Ult( rs1_val, immI ) , bv(1) , bv(0) ) );
            
            RECORD_INST("SLTIU" NAME_SUFFIX);
        }
        // ------------------------- Instruction: ANDI ------------------------------ //
        {
            auto instr = model.NewInstr("ANDI" NAME_SUFFIX);
            auto decode = ( opcode == OPIMM ) & ( funct3 == ANDI ) & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);

            EXECUTE_IF_SPEC;
            UPDATE_PC(nxt_pc);
            UPDATE_R( rd,  rs1_val & immI );
            
            RECORD_INST("ANDI" NAME_SUFFIX);
        }
        // ------------------------- Instruction: ORI ------------------------------ //
        {
            auto instr = model.NewInstr("ORI" NAME_SUFFIX);
            auto decode = ( opcode == OPIMM ) & ( funct3 == ORI ) & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);

            EXECUTE_IF_SPEC;
            UPDATE_PC(nxt_pc);
            UPDATE_R( rd,  rs1_val | immI );
            
            RECORD_INST("ORI" NAME_SUFFIX);
        }
        // ------------------------- Instruction: XORI ------------------------------ //
        {
            auto instr = model.NewInstr("XORI" NAME_SUFFIX);
            auto decode = ( opcode == OPIMM ) & ( funct3 == XORI ) & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);

            EXECUTE_IF_SPEC;
            UPDATE_PC(nxt_pc);
            UPDATE_R( rd,  rs1_val ^ immI );
            
            RECORD_INST("XORI" NAME_SUFFIX);
        }
        // ------------------------- Instruction: SLLI ------------------------------ //
        {
            auto instr = model.NewInstr("SLLI" NAME_SUFFIX);
            auto decode = ( opcode == OPIMM ) & ( funct3 == SLLI ) & (funct7 == SLLIfunct7) & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);

            EXECUTE_IF_SPEC;
            UPDATE_PC(nxt_pc);
            UPDATE_R( rd,  rs1_val << shamt );  // shift left
            
            RECORD_INST("SLLI" NAME_SUFFIX);
        }
        // ------------------------- Instruction: SRLI ------------------------------ //
        {
            auto instr = model.NewInstr("SRLI" NAME_SUFFIX);
            auto decode = ( opcode == OPIMM ) & ( funct3 == SRLI ) & (funct7 == SRLIfunct7) & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);

            EXECUTE_IF_SPEC;
            UPDATE_PC(nxt_pc);
            UPDATE_R( rd,  Lshr(rs1_val, shamt) ); // logic shift right
            
            RECORD_INST("SRLI" NAME_SUFFIX);
        }
        // ------------------------- Instruction: SRAI ------------------------------ //
        {
            auto instr = model.NewInstr("SRAI" NAME_SUFFIX);
            auto decode = ( opcode == OPIMM ) & ( funct3 == SRAI ) & (funct7 == SRAIfunct7) & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);

            EXECUTE_IF_SPEC;
            UPDATE_PC(nxt_pc);
            UPDATE_R( rd,  rs1_val >> shamt );  // arithmetic shift right
            
            RECORD_INST("SRAI" NAME_SUFFIX);
        }
