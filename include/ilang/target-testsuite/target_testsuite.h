// TODO(yuex) Describe this class

#ifndef ILANG_TARGET_TESTSUITE_TARGET_TESTSUITE_H__
#define ILANG_TARGET_TESTSUITE_TARGET_TESTSUITE_H__
#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/ila/ast_fuse.h>
#include <ilang/util/log.h>
#include <ilang/verification/unroller.h>
#include <ilang/target-testsuite/path_enumerator.h>
#include <iostream>
#include <sstream>

using namespace std;
namespace ilang {

class TargetTestSuite {
public:
  TargetTestSuite();
  TargetTestSuite(const InstrLvlAbsPtr &model_ptr);
  
  void set_instr_lvl_abs(const InstrLvlAbsPtr &model_ptr);
  void test_gen();

private:
  void golden_test_gen(z3::context& g_ctx, PathUnroll* g_unroller, z3::solver& g_solver, std::vector<InstrPtr>& instr_seq, std::set<ExprPtr> instr_state_set);
  void golden_test_state_must_change_constrain(PathUnroll* g_unroller, z3::solver& g_solver, std::vector<InstrPtr>& instr_seq);
  void golden_test_non_instr_state_constrain(PathUnroll* g_unroller, z3::solver& g_solver, std::vector<InstrPtr>& instr_seq, std::set<ExprPtr> instr_state_set);
  void test_gen_init_state(stringstream& testbench, string& indent, z3::context& g_ctx, PathUnroll* g_unroller, z3::model &g_model);
  void test_gen_tb_io(stringstream& testbench, string& indent);
  void test_gen_tb_stim(stringstream& testbench, string& indent, z3::context &g_ctx, PathUnroll* g_unroller, z3::model &g_model, std::vector<InstrPtr>& instr_seq);
  void test_gen_tb_start_stim(stringstream& testbench, string& indent);
  void test_gen_tb_class(stringstream& testbench, string& indent, z3::context& g_ctx, PathUnroll* g_unroller, z3::model& g_model, std::vector<InstrPtr>& instr_seq);
  void test_gen_sc_signal(stringstream& testbench, string& indent);
  void test_gen_connect_dut(stringstream& testbench, string& indent);
  void test_gen_connect_tb(stringstream& testbench, string& indent);

  void test_vec_gen(std::vector<InstrPtr>& instr_seq, int mode);
  void path_complete_test_gen(std::vector<InstrPtr>& instr_seq);
  void random_test_gen(std::vector<InstrPtr>& instr_seq);
  void test_program_gen(stringstream& testbench, string& indent);
  void export_test(stringstream& testbench, string test_file_name);
  void increase_indent(string &indent);
  void decrease_indent(string &indent);
  void get_ila_state_set();
  void get_ila_input_set();
  void diff_set(std::set<ExprPtr>& set_0, std::set<ExprPtr>& set_1, std::set<ExprPtr>& res_set);
  void dfs_collect_state(std::set<ExprPtr>& state_set, const ExprPtr& e);

  std::set<ExprPtr> input_set_;
  std::set<ExprPtr> state_set_;
  std::stringstream mk_file_;
  InstrLvlAbsPtr model_ptr_;

};
}
#endif
