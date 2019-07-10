#include <ilang/target-testsuite/target_testsuite.h>
#include <ilang/target-testsuite/path_enumerator.h>
#include <set>
#include <vector>
#include <stdlib.h>
#include <time.h>

namespace ilang {
TargetTestSuite::TargetTestSuite() {}

TargetTestSuite::TargetTestSuite(const InstrLvlAbsPtr& model_ptr) {
  model_ptr_ = model_ptr;
}

void TargetTestSuite::set_instr_lvl_abs(const InstrLvlAbsPtr& model_ptr) {
  model_ptr_ = model_ptr;
}

void TargetTestSuite::increase_indent(string& indent) {
  indent += "  ";
}

void TargetTestSuite::decrease_indent(string& indent) {
  indent.pop_back();
  indent.pop_back();
}

void TargetTestSuite::golden_test_state_must_change_constrain(PathUnroll* g_unroller, z3::solver& g_solver, std::vector<InstrPtr>& instr_seq) {
  std::set<string> updated_state_name_set;
  int seq_length = instr_seq.size();
  for (int i = 0; i < seq_length; i++) {
    auto tmp_state_name_set = instr_seq[i]->updated_states();
    updated_state_name_set.insert(tmp_state_name_set.begin(), tmp_state_name_set.end());
  } 
  {
    std::vector<z3::expr> state_change_constrains;
    for (auto iter = updated_state_name_set.begin(); iter != updated_state_name_set.end(); iter++) {
      auto start = g_unroller->CurrState(model_ptr_->state(*iter), 0);
      auto end = g_unroller->CurrState(model_ptr_->state(*iter), seq_length);
      if (iter == updated_state_name_set.begin()) {
	z3::expr tmp = (start != end);
	state_change_constrains.push_back(tmp);
      } else {
	z3::expr tmp = (state_change_constrains.back() || (start != end));
	state_change_constrains.push_back(tmp);
      }
    }
    g_solver.add(state_change_constrains.back());
  }
}

void TargetTestSuite::dfs_collect_state(std::set<ExprPtr>& state_set, const ExprPtr& e) {
  auto expr_uid = GetUidExpr(e);
  auto expr_sort_uid = GetUidSort(e->sort());
  if (expr_uid == AST_UID_EXPR::VAR) {
    if (expr_sort_uid == AST_UID_SORT::MEM) {
      ILA_WARN << "mem state is not supported for constrains";
    } else {
      state_set.insert(e);
    }
  } else if (expr_uid == AST_UID_EXPR::OP) {
    for (int i = 0; i < e->arg_num(); i++) {
      dfs_collect_state(state_set, e->arg(i));
    }
  } 
}

// This function is un-optimized.
// No need to optimize it, because:
//   1. the input sizes are very small
//   2. ths function is not critical 
void TargetTestSuite::diff_set(std::set<ExprPtr>& set_0, std::set<ExprPtr>& set_1, std::set<ExprPtr>& res_set) {
  for (auto iter_0 = set_0.begin(); iter_0 != set_0.end(); iter_0++) {
    bool flag = false;
    for (auto iter_1 = set_1.begin(); iter_1 != set_1.end(); iter_1++) {
      if ((*iter_0)->name() == (*iter_1)->name()) 
	flag = true;
    }
    if (!flag) 
      res_set.insert(*iter_0); 
  }
}

void TargetTestSuite::golden_test_non_instr_state_constrain(PathUnroll* g_unroller, z3::solver& g_solver, std::vector<InstrPtr>& instr_seq, std::set<ExprPtr> instr_state_set) {
  int seq_length = instr_seq.size();
  for (int i = 0; i < seq_length; i++) {
    auto decode_func = instr_seq[i]->decode();
    auto DfsCollectState = [this, &instr_state_set](const ExprPtr& e) { dfs_collect_state(instr_state_set, e);};
    decode_func->DepthFirstVisit(DfsCollectState);
  }
  // TODO(yuex) constrain_set is not complete
  std::set<ExprPtr> constrain_set;
  diff_set(state_set_, instr_state_set, constrain_set);
  diff_set(input_set_, instr_state_set, constrain_set);

  {
    std::vector<z3::expr> non_instr_state_constrains;
    for (auto iter = constrain_set.begin(); iter != constrain_set.end(); iter++) {
      ExprPtr state_or_input;
      auto unrolled_state = g_unroller->CurrState(*iter, 0);
      if ((*iter)->is_bool()) {
	bool rand_bool = (rand() % 2) == 1; 
	z3::expr tmp = (unrolled_state == rand_bool);
        non_instr_state_constrains.push_back(tmp);
      } else {
	int bv_width = (*iter)->sort()->bit_width();
	int n = bv_width / 31;
	int rand_bv;
	for (int i = 1; i <= n; i++) {
	  rand_bv = (rand() & 2147483647);
	  z3::expr tmp = (unrolled_state.extract(i*31-1, (i-1)*31) == rand_bv);
	  non_instr_state_constrains.push_back(tmp);
	}
	int rem = bv_width % 31;
	if (rem > 0) {
	  rand_bv = (rand() & ((1 << rem) - 1));
	  int hi = bv_width - 1;
	  z3::expr tmp = (unrolled_state.extract(bv_width - 1, n*31) == rand_bv);
	  non_instr_state_constrains.push_back(tmp);
	}
      }
    }
    for (auto iter = non_instr_state_constrains.begin(); iter != non_instr_state_constrains.end(); iter++)
    {
      g_solver.add(*iter);
      // cout << *iter << endl;
    }
  }
}

void TargetTestSuite::golden_test_gen(z3::context& g_ctx, PathUnroll* g_unroller, z3::solver& g_solver, std::vector<InstrPtr>& instr_seq, std::set<ExprPtr> instr_state_set) {
  // Add constrain from instruction
  auto g_instr_constrain = g_unroller->PathSubs(instr_seq); 
  g_solver.add(g_instr_constrain);
 
  // Add constrain for meaningful golden test (At least one state is updated by executing that instruction.
  // Case 0:
  // golden_test_state_must_change_constrain(g_unroller, g_solver, instr_seq);
  // Case 1: 
  golden_test_non_instr_state_constrain(g_unroller, g_solver, instr_seq, instr_state_set);
  g_solver.check();
}

void TargetTestSuite::test_gen_init_state(stringstream& testbench, string& indent, z3::context& g_ctx, PathUnroll* g_unroller, z3::model& g_model) {
  testbench << indent << "void dut_init(" << model_ptr_->name() << " &dut) {" << endl;
  increase_indent(indent);
  for (int i = 0; i < model_ptr_->state_num(); i++) {
    auto state = model_ptr_->state(i);
    auto state_sort_uid = GetUidSort(state->sort());
    if (state_sort_uid == AST_UID_SORT::MEM) {
      ILA_WARN << "mem state is not supported for initilization";
      continue;
    } 
    auto state_name_str = state->host()->name().str() + "_" + state->name().str();
    auto z3_state = g_unroller->CurrState(state, 0);
    auto init_val = g_model.eval(z3_state);
    string init_val_str = Z3_ast_to_string(g_ctx, init_val);
    init_val_str.replace(0, 1, "0");
    testbench << indent << "dut." << state_name_str << " = \"" << init_val_str << "\";" << endl;
  }
  decrease_indent(indent);
  testbench << indent << "}" << endl;
  testbench << endl;
}

void TargetTestSuite::test_gen_tb_io(stringstream& testbench, string& indent) {
  for (int i = 0; i < model_ptr_->input_num(); i++) {
    auto input_expr = model_ptr_->input(i);
    auto input_sort_uid = GetUidSort(input_expr->sort());
    string input_name_str = input_expr->host()->name().str() + "_" + input_expr->name().str(); 	
    if (input_sort_uid == AST_UID_SORT::MEM) {
      ILA_WARN << "Warning: mem is not supported as input."; 
    } else if (input_sort_uid == AST_UID_SORT::BOOL) {
      testbench << indent << "sc_out<bool> " << input_name_str << "_in;" << endl; 
    } else {
      testbench << indent << "sc_out< sc_biguint<" << input_expr->sort()->bit_width() << "> > " << input_name_str << "_in;" << endl;	
    }
  }
  for (int i = 0; i < model_ptr_->state_num(); i++) {
    auto state_expr = model_ptr_->state(i);
    auto state_sort_uid = GetUidSort(state_expr->sort());
    string state_name_str = state_expr->host()->name().str() + "_" + state_expr->name().str(); 	
    if (state_sort_uid == AST_UID_SORT::MEM) {
      ILA_WARN << "Warning: mem is not supported as input."; 
    } else if (state_sort_uid == AST_UID_SORT::BOOL) {
      testbench << indent << "sc_in<bool> " << state_name_str << "_out;" << endl; 
    } else {
      testbench << indent << "sc_in< sc_biguint<" << state_expr->sort()->bit_width() << "> > " << state_name_str << "_out;" << endl;	
    }
  }
}

void TargetTestSuite::test_gen_tb_stim(stringstream& testbench, string& indent, z3::context &g_ctx, PathUnroll* g_unroller, z3::model &g_model, int seq_length) {
  testbench << indent << "void test_vector_gen() {" << endl;
  increase_indent(indent);
  testbench << indent << "wait(SC_ZERO_TIME);" << endl;
  testbench << indent << "wait(SC_ZERO_TIME);" << endl;
  for (int i = 0; i < model_ptr_->input_num(); i++) {
    auto input = model_ptr_->input(i);
    auto input_sort_uid = GetUidSort(input->sort());
    if (input_sort_uid == AST_UID_SORT::MEM)
      ILA_WARN << "mem is not supported as input";
    auto input_name = input->host()->name().str() + "_" + input->name().str();
    auto z3_input = g_unroller->CurrState(input, 0);
    auto input_val = g_model.eval(z3_input);
    string input_val_str = Z3_ast_to_string(g_ctx, input_val);
    input_val_str.replace(0, 1, "0");
    testbench << indent << input_name << "_in.write(\"" << input_val_str << "\");" << endl;
  }
  testbench << indent << "wait(SC_ZERO_TIME);" << endl;
  testbench << indent << "wait(SC_ZERO_TIME);" << endl;
  for (int i = 0; i < model_ptr_->state_num(); i++) {
    auto state = model_ptr_->state(i);
    auto state_sort_uid = GetUidSort(state->sort());
    if (state_sort_uid == AST_UID_SORT::MEM) {
      ILA_WARN << "mem is not supported for assertion in test";
      continue;
    }
    string state_type;
    if (state_sort_uid == AST_UID_SORT::BOOL) 
      state_type = "sc_bool";
    else 
      state_type = "sc_biguint<" + to_string(state->sort()->bit_width()) + ">";

    auto state_name = state->host()->name().str() + "_" + state->name().str();
    auto z3_state = g_unroller->CurrState(state, seq_length);
    auto state_val = g_model.eval(z3_state);
    string state_val_str = Z3_ast_to_string(g_ctx, state_val);
    state_val_str.replace(0, 1, "0");
    testbench << indent << "assert(" << state_name << "_out.read() == " << state_type << "(\"" << state_val_str << "\"));" << endl;
  }

  testbench << indent << "sc_stop();" << endl; 
  decrease_indent(indent);
  testbench << indent << "}" << endl;
}

void TargetTestSuite::test_gen_tb_start_stim(stringstream& testbench, string& indent) {
  testbench << indent << "SC_CTOR(TB) {" << endl;
  increase_indent(indent);
  testbench << indent << "SC_THREAD(test_vector_gen);" << endl;
  testbench << indent << "}" << endl;
  decrease_indent(indent);
  testbench << indent << "};" << endl;
}

void TargetTestSuite::test_gen_tb_class(stringstream& testbench, string& indent, z3::context& g_ctx, PathUnroll* g_unroller, z3::model& g_model, int seq_length) {
  testbench << indent << "SC_MODULE(TB) {" << endl;
  increase_indent(indent);
  test_gen_tb_io(testbench, indent);
  testbench << endl;
  test_gen_tb_stim(testbench, indent, g_ctx, g_unroller, g_model, seq_length);
  test_gen_tb_start_stim(testbench, indent);
} 

void TargetTestSuite::test_vec_gen(std::vector<InstrPtr>& instr_seq, int mode) {
  if (mode == 0) {
    random_test_gen(instr_seq);
  } else if (mode == 1) {
    path_complete_test_gen(instr_seq);
  }
}

void TargetTestSuite::random_test_gen(std::vector<InstrPtr>& instr_seq) {
  stringstream testbench;
  string indent = "";
  testbench << indent << "#include <test.h>" << endl;
  testbench << indent << "#include <assert.h>" << endl;
 
  z3::context golden_ctx;
  auto golden_unroller = new PathUnroll(golden_ctx);
  z3::solver golden_solver(golden_ctx);

  int seq_length = instr_seq.size();
  std::set<ExprPtr> instr_state_set;
  golden_test_gen(golden_ctx, golden_unroller, golden_solver, instr_seq, instr_state_set);
  auto golden_model = golden_solver.get_model();
  test_gen_init_state(testbench, indent, golden_ctx, golden_unroller, golden_model);
  test_gen_tb_class(testbench, indent, golden_ctx, golden_unroller, golden_model, seq_length); 

  // interconnect wire with dut
  test_program_gen(testbench, indent);
  export_test(testbench, model_ptr_->instr(0)->name().str() + "_testbench");
}

void TargetTestSuite::path_complete_test_gen(std::vector<InstrPtr>& instr_seq) {
  auto updated_state_name_set = instr_seq[0]->updated_states();
  PathEnumerator* pe_list = new PathEnumerator[updated_state_name_set.size()]; 
  if(updated_state_name_set.size() < 1)
    return;
  int pe_i = 0;
  for (auto state_name_iter = updated_state_name_set.begin(); state_name_iter != updated_state_name_set.end(); state_name_iter++) {
    pe_list[pe_i].dfs(instr_seq[0]->update(*state_name_iter)); 
    pe_i++;
  }
  for (int pe_i = 1; pe_i < updated_state_name_set.size(); pe_i++)
    pe_list[0].cross_product(pe_list[pe_i]); 

  auto pe = pe_list[0];
  cout << "path size" << pe.path_collector_.size() << endl;
  int path_i = 0;
  for (auto path = pe.path_collector_.begin(); path < pe.path_collector_.end(); path++) {
    stringstream testbench;
    string indent = "";
    testbench << indent << "#include <test.h>" << endl;
    testbench << indent << "#include <assert.h>" << endl;

    z3::context golden_ctx;
    auto golden_unroller = new PathUnroll(golden_ctx);
    z3::solver golden_solver(golden_ctx);
    Z3ExprAdapter golden_adapter(golden_ctx);
    std::set<ExprPtr> instr_state_set;
    for (auto path_element = path->begin(); path_element < path->end(); path_element++) {
      auto path_cond = path_element->expr_ite->arg(0);
      auto z3_path_cond = golden_adapter.GetExpr(path_cond); 
      cout << z3_path_cond << "  " << path_element->ite_eval << endl;
      golden_solver.add(z3::implies(z3_path_cond, path_element->ite_eval) && z3::implies(path_element->ite_eval, z3_path_cond));
      dfs_collect_state(instr_state_set, path_cond);
    }
    cout << endl;
    golden_test_gen(golden_ctx, golden_unroller, golden_solver, instr_seq, instr_state_set);
    if (golden_solver.check() == z3::unsat)
      continue;
    auto golden_model = golden_solver.get_model();
    test_gen_init_state(testbench, indent, golden_ctx, golden_unroller, golden_model);
    test_gen_tb_class(testbench, indent, golden_ctx, golden_unroller, golden_model, instr_seq.size()); 
    // interconnect wire with dut
    test_program_gen(testbench, indent);
    export_test(testbench, model_ptr_->instr(0)->name().str() + "_testbench_" + to_string(path_i++));
  }
}


void TargetTestSuite::test_gen_sc_signal(stringstream& testbench, string& indent) {
  for (int i = 0; i < model_ptr_->input_num(); i++) {
    auto input_expr = model_ptr_->input(i);
    auto input_sort_uid = GetUidSort(input_expr->sort());
    string input_name_str = input_expr->host()->name().str() + "_" + input_expr->name().str(); 	
    if (input_sort_uid == AST_UID_SORT::MEM) {
      ILA_WARN << "Warning: mem is not supported as input." << endl; 
    } else if (input_sort_uid == AST_UID_SORT::BOOL) {
      testbench << indent << "sc_signal<bool> " << input_name_str << "_in;" << endl; 
    } else {
      testbench << indent << "sc_signal< sc_biguint<" << input_expr->sort()->bit_width() << "> > " << input_name_str << "_in;" << endl;	
    }
  }

  for (int i = 0; i < model_ptr_->state_num(); i++) {
    auto state_expr = model_ptr_->state(i);
    auto state_sort_uid = GetUidSort(state_expr->sort());
    string state_name_str = state_expr->host()->name().str() + "_" + state_expr->name().str(); 	
    if (state_sort_uid == AST_UID_SORT::MEM) {
      ILA_WARN << "Error: mem is not supported as input." << endl; 
    } else if (state_sort_uid == AST_UID_SORT::BOOL) {
      testbench << indent << "sc_signal<bool> " << state_name_str << "_out;" << endl; 
    } else {
      testbench << indent << "sc_signal< sc_biguint<" << state_expr->sort()->bit_width() << "> > " << state_name_str << "_out;" << endl;	
    }
  } 
}

void TargetTestSuite::test_gen_connect_dut(stringstream& testbench, string& indent) {
  testbench << indent << model_ptr_->name() << " dut(\"dut\");" << endl;   
  for (int i = 0; i < model_ptr_->input_num(); i++) {
    auto input_expr = model_ptr_->input(i);
    auto input_sort_uid = GetUidSort(input_expr->sort());
    string input_name_str = input_expr->host()->name().str() + "_" + input_expr->name().str(); 	
    if (input_sort_uid != AST_UID_SORT::MEM) {
      testbench << indent << "dut." << input_name_str << "_in(" << input_name_str << "_in);" << endl; 
    }
  }
  for (int i = 0; i < model_ptr_->state_num(); i++) {
    auto state_expr = model_ptr_->state(i);
    auto state_sort_uid = GetUidSort(state_expr->sort());
    string state_name_str = state_expr->host()->name().str() + "_" + state_expr->name().str(); 	
    if (state_sort_uid != AST_UID_SORT::MEM) {
      testbench << indent << "dut." << state_name_str << "_out(" << state_name_str << "_out);" << endl; 
    }
  }
  testbench << indent << "dut_init(dut);" << endl;
}

void TargetTestSuite::test_gen_connect_tb(stringstream& testbench, string& indent) {
  testbench << indent << "TB tb(\"tb\");" << endl;   
  for (int i = 0; i < model_ptr_->input_num(); i++) {
    auto input_expr = model_ptr_->input(i);
    auto input_sort_uid = GetUidSort(input_expr->sort());
    string input_name_str = input_expr->host()->name().str() + "_" + input_expr->name().str(); 	
    if (input_sort_uid != AST_UID_SORT::MEM) {
      testbench << indent << "tb." << input_name_str << "_in(" << input_name_str << "_in);" << endl; 
    }
  }
  for (int i = 0; i < model_ptr_->state_num(); i++) {
    auto state_expr = model_ptr_->state(i);
    auto state_sort_uid = GetUidSort(state_expr->sort());
    string state_name_str = state_expr->host()->name().str() + "_" + state_expr->name().str(); 	
    if (state_sort_uid != AST_UID_SORT::MEM) {
      testbench << indent << "tb." << state_name_str << "_out(" << state_name_str << "_out);" << endl; 
    }
  }
}

void TargetTestSuite::test_program_gen(stringstream& testbench, string& indent) {
  testbench << "int sc_main(int argc, char* argv[]) {" << endl; 
    
  increase_indent(indent);
  test_gen_sc_signal(testbench, indent);
  testbench << indent << endl;
  test_gen_connect_dut(testbench, indent);
  testbench << indent << endl;
  test_gen_connect_tb(testbench, indent);

  testbench << indent << endl;
  testbench << indent << "sc_start();" << endl;
  testbench << indent << "return 0;" << endl;
  decrease_indent(indent);
  testbench << indent << "}";
}

void TargetTestSuite::export_test(stringstream& testbench, string test_file_name) {
  ofstream testFile;
  testFile.open(test_file_name + ".cc");
  testFile << testbench.rdbuf();
  testFile.close(); 
  mk_file_ << "g++ -I. -o " << test_file_name << " " << test_file_name << ".cc -L. -l" << model_ptr_->name() << " -lsystemc"  << endl;
  mk_file_ << "./" << test_file_name << endl;
}

void TargetTestSuite::get_ila_state_set() {
  for (int i = 0; i < model_ptr_->state_num(); i++) {
    auto state_expr = model_ptr_->state(i);
    auto state_sort_uid = GetUidSort(state_expr->sort());
    if (state_sort_uid != AST_UID_SORT::MEM)
      state_set_.insert(model_ptr_->state(i));
  }  
}

void TargetTestSuite::get_ila_input_set() {
  for (int i = 0; i < model_ptr_->input_num(); i++) {
    auto input_expr = model_ptr_->input(i);
    auto input_sort_uid = GetUidSort(input_expr->sort());
    if (input_sort_uid != AST_UID_SORT::MEM)
      input_set_.insert(model_ptr_->input(i));
    // TODO (yuex): else ILA_ERROR
  }
}

void TargetTestSuite::test_gen() {
  srand(time(NULL));
  get_ila_state_set();
  get_ila_input_set();
  for (int i = 0; i < 1; i++) {//model_ptr_->instr_num(); i++) {
    std::vector<InstrPtr> instr_seq;
    instr_seq.push_back(model_ptr_->instr(i)); 
    test_vec_gen(instr_seq, 1); 
  }
  ofstream mkFile;
  mkFile.open("test_make.sh");
  mkFile << mk_file_.rdbuf();
  mkFile.close();
}
}
