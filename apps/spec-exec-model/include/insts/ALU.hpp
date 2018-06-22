
        // ------------------------- Instruction: ADD ------------------------------ //
        {
            auto instr = model.NewInstr("ADD" NAME_SUFFIX);
            auto decode = ( opcode == OP ) & ( funct3 == ADD ) & (funct7 == funct7_NM ) & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);

            EXECUTE_IF_SPEC;
            UPDATE_PC(nxt_pc);
            UPDATE_R( rd, rs1_val + rs2_val );

            RECORD_INST("ADD" NAME_SUFFIX);
        }
        // ------------------------- Instruction: AND ------------------------------ //
        {
            auto instr = model.NewInstr("AND" NAME_SUFFIX);
            auto decode = ( opcode == OP ) & ( funct3 == AND ) & (funct7 == funct7_NM ) & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);

            EXECUTE_IF_SPEC;
            UPDATE_PC(nxt_pc);
            UPDATE_R( rd, rs1_val & rs2_val );

            RECORD_INST("AND" NAME_SUFFIX);
        }
        // ------------------------- Instruction: OR ------------------------------ //
        {
            auto instr = model.NewInstr("OR" NAME_SUFFIX);
            auto decode = ( opcode == OP ) & ( funct3 == OR ) & (funct7 == funct7_NM ) & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);

            EXECUTE_IF_SPEC;
            UPDATE_PC(nxt_pc);
            UPDATE_R( rd, rs1_val | rs2_val );

            RECORD_INST("OR" NAME_SUFFIX);
        }

        // ------------------------- Instruction: XOR ------------------------------ //
        {
            auto instr = model.NewInstr("XOR" NAME_SUFFIX);
            auto decode = ( opcode == OP ) & ( funct3 == XOR ) & (funct7 == funct7_NM ) & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);

            EXECUTE_IF_SPEC;
            UPDATE_PC(nxt_pc);
            UPDATE_R( rd, rs1_val ^ rs2_val );

            RECORD_INST("XOR" NAME_SUFFIX);
        }

        // ------------------------- Instruction: SLL ------------------------------ //
        {
            auto instr = model.NewInstr("SLL" NAME_SUFFIX);
            auto decode = ( opcode == OP ) & ( funct3 == SLL ) & (funct7 == funct7_NM ) & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);

            EXECUTE_IF_SPEC;
            UPDATE_PC(nxt_pc);
            UPDATE_R( rd, rs1_val << shamt );   // shift left

            RECORD_INST("SLL" NAME_SUFFIX);
        }
        // ------------------------- Instruction: SRL ------------------------------ //
        {
            auto instr = model.NewInstr("SRL" NAME_SUFFIX);
            auto decode = ( opcode == OP ) & ( funct3 == SRL ) & (funct7 == funct7_NM ) & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);

            EXECUTE_IF_SPEC;
            UPDATE_PC(nxt_pc);
            UPDATE_R( rd, Lshr(rs1_val, shamt)  ); // logical shift right

            RECORD_INST("SRL" NAME_SUFFIX);
        }

        // ------------------------- Instruction: SUB ------------------------------ //
        {
            auto instr = model.NewInstr("SUB" NAME_SUFFIX);
            auto decode = ( opcode == OP ) & ( funct3 == SUB ) & (funct7 == funct7_PM ) & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);

            EXECUTE_IF_SPEC;
            UPDATE_PC(nxt_pc);
            UPDATE_R( rd, rs1_val - rs2_val );

            RECORD_INST("SUB" NAME_SUFFIX);
        }

        // ------------------------- Instruction: SRA ------------------------------ //
        {
            auto instr = model.NewInstr("SRA" NAME_SUFFIX);
            auto decode = ( opcode == OP ) & ( funct3 == SRA ) & (funct7 == funct7_PM ) & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);

            EXECUTE_IF_SPEC;
            UPDATE_PC(nxt_pc);
            UPDATE_R( rd, rs1_val >> shamt ); // arithmetic shift right

            RECORD_INST("SRA" NAME_SUFFIX);
        }

        // ------------------------- Instruction: SLT ------------------------------ //
        {
            auto instr = model.NewInstr("SLT" NAME_SUFFIX);
            auto decode = ( opcode == OP ) & ( funct3 == SLT ) & (funct7 == funct7_NM ) & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);

            EXECUTE_IF_SPEC;
            UPDATE_PC(nxt_pc);
            UPDATE_R( rd, Ite(rs1_val < rs2_val , bv(1), bv(0) ) );
            
            RECORD_INST("SLT" NAME_SUFFIX);
        }
        // ------------------------- Instruction: SLTU ------------------------------ //
        {
            auto instr = model.NewInstr("SLTU" NAME_SUFFIX);
            auto decode = ( opcode == OP ) & ( funct3 == SLTU ) & (funct7 == funct7_NM ) & interruptCondition() & EXEC_COND ;
            instr.SetDecode(decode);

            EXECUTE_IF_SPEC;
            UPDATE_PC(nxt_pc);
            UPDATE_R( rd, Ite( Ult(rs1_val , rs2_val ) , bv(1), bv(0) ) );
            
            RECORD_INST("SLTU" NAME_SUFFIX);
        }
