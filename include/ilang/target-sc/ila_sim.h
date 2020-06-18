/// \file
/// The header for the class IlaSim

#ifndef ILANG_TARGET_SC_ILA_SIM_H__
#define ILANG_TARGET_SC_ILA_SIM_H__

#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include <ilang/ila/instr_lvl_abs.h>

#define EXTERNAL_MEM 0

namespace ilang {

// TODO(yuex): change id to instruction name for decode&state_update function

/// \brief A class to generate SystemC simulator model from ILA model
/// Example Use:
/// - InstrLvlAbsPtr your_ila_model_ptr;
/// - IlaSim ila_sim;
/// - ila_sim.set_instr_lvl_abs(your_ila_model_ptr);
/// - ila_sim.sim_gen("./");
class IlaSim {
public:
  /// TODO
  typedef struct {
    std::string mem_str;
    std::string addr_str;
    std::string dest_str;
  } ld_info;

  /// TODO
  typedef struct {
    std::string mem_str;
    std::string mem_map;
  } st_info;

  /// Default constructor.
  IlaSim();
  /// Construct with the target ILA model.
  IlaSim(const InstrLvlAbsPtr& model_ptr);
  /// Set the target ILA model.
  void set_instr_lvl_abs(const InstrLvlAbsPtr& model_ptr);
  /// (To be deprecated) set the path to SystemC library.
  void set_systemc_path(std::string systemc_path);

  /// Set to CMake build mode.
  void enable_cmake_support();

  /// Generate the simulator.
  void sim_gen(std::string export_dir, bool external_mem = false,
               bool readable = false, bool qemu_device = false);

private:
  // Initialize all member variables for a new simulator generation pass.
  void sim_gen_init(std::string export_dir, bool external_mem, bool readable,
                    bool qemu_device);
  // Create initial lines for the simulator's header file
  void sim_gen_init_header();
  void sim_gen_input();
  void sim_gen_state();
  void sim_gen_init();
  void sim_gen_decode();
  void sim_gen_state_update();
  void sim_gen_execute_kernel();
  void sim_gen_execute_invoke();
  void sim_gen_export();

  void create_input(const ExprPtr& input_expr);
  void create_bool_input(const ExprPtr& expr);
  void create_bv_input(const ExprPtr& expr);

  void create_state(const ExprPtr& state_expr);
  void create_child_state(const ExprPtr& state_expr);
  void create_mem_state(const ExprPtr& expr);
  void create_bool_state(const ExprPtr& expr, bool child = false);
  void create_bv_state(const ExprPtr& expr, bool child = false);
  void create_external_mem_port(const ExprPtr& expr);

  void create_init(const InstrLvlAbsPtr& ila);
  void init_decl(std::stringstream& valid_function, std::string& indent,
                 std::string& valid_func_name);
  void init_check_valid(std::stringstream& init_function, std::string& indent,
                        const ExprPtr& valid_expr, const InstrLvlAbsPtr& ila);
  void init_return(std::stringstream& init_function, std::string& indent);
  void init_export(std::stringstream& init_function,
                   std::string& init_func_name);
  void init_mk_file(std::string& init_func_name);

  void create_decode(const InstrPtr& instr_expr);
  void decode_decl(std::stringstream& decode_function, std::string& indent,
                   std::string& decode_func_name);
  void decode_check_valid(std::stringstream& decode_function,
                          std::string& indent, const ExprPtr& valid_expr,
                          const InstrPtr& instr_expr);
  void decode_return(std::stringstream& decode_function, std::string& indent,
                     const ExprPtr& decode_expr, const InstrPtr& instr_expr);
  void decode_export(std::stringstream& decode_function,
                     std::string& decode_func_name);
  void decode_mk_file(std::string& decode_func_name);

  void create_state_update(const InstrPtr& instr_expr);
  void state_update_decl(std::stringstream& state_update_function,
                         std::string& indent, const ExprPtr& updated_state,
                         const ExprPtr& update_expr,
                         std::string& state_update_func_name);
  void state_update_return(std::stringstream& state_update_function,
                           std::string& indent, const ExprPtr& updated_state,
                           const ExprPtr& update_expr);
  void state_update_export(std::stringstream& state_update_function,
                           std::string& state_update_func_name);
  void state_update_mk_file(std::string& state_update_func_name);
  void mem_state_update_decl(std::stringstream& state_update_function,
                             std::string& indent, const ExprPtr& expr);

  void execute_init(std::stringstream& execute_kernel, std::string& indent);
  void execute_parent_instructions(std::stringstream& execute_kernel,
                                   std::string& indent);
  void execute_child_instructions(std::stringstream& execute_kernel,
                                  std::string& indent);
  void execute_instruction(std::stringstream& execute_kernel,
                           std::string& indent, const InstrPtr& instr_expr,
                           bool child = false);
  void execute_decode(std::stringstream& execute_kernel, std::string& indent,
                      const InstrPtr& instr_expr);
  void execute_state_update_func(std::stringstream& execute_kernel,
                                 std::string& indent,
                                 const InstrPtr& instr_expr,
                                 const ExprPtr& updated_state);
  void execute_update_state(std::stringstream& execute_kernel,
                            std::string& indent, const InstrPtr& instr_expr,
                            const ExprPtr& updated_state);
  void execute_external_mem_load_begin(std::stringstream& execute_kernel,
                                       std::string& indent,
                                       const InstrPtr& instr_expr);
  void execute_external_mem_load_end(std::stringstream& execute_kernel,
                                     std::string& indent);
  void execute_read_external_mem(std::stringstream& execute_kernel,
                                 std::string& indent);
  void execute_write_external_mem(std::stringstream& execute_kernel,
                                  std::string& indent);
  void execute_external_mem_before_input(std::stringstream& execute_kernel,
                                         std::string& indent);
  void execute_external_mem_after_output(std::stringstream& execute_kernel,
                                         std::string& indent);
  void execute_external_mem_return(std::stringstream& execute_kernel,
                                   std::string& indent);
  void execute_read_input(std::stringstream& execute_kernel,
                          std::string& indent);
  void execute_write_output(std::stringstream& execute_kernel,
                            std::string& indent);
  void execute_kernel_export(std::stringstream& execute_kernel);
  void execute_kernel_mk_file();
  void execute_kernel_header();

  void dfs_store_op(const ExprPtr& expr);
  void dfs_load_from_store(const ExprPtr& expr);
  void dfs_int_var_width(const ExprPtr& expr);
  void dfs_external_mem_load(const ExprPtr& expr);
  void dfs_kernel(std::stringstream& dfs_simulator, std::string& indent,
                  const ExprPtr& expr);
  void dfs_uninterpreted_func_decl(const FuncPtr& func);
  void dfs_const_node(std::stringstream& dfs_simulator, std::string& indent,
                      const ExprPtr& expr);
  void dfs_unary_op(std::stringstream& dfs_simulator, std::string& indent,
                    const ExprPtr& expr);
  void dfs_unary_op_check(const ExprPtr& expr);
  void dfs_binary_op_bool_out(std::stringstream& dfs_simulator,
                              std::string& indent, const ExprPtr& expr);
  void dfs_binary_op_bool_out_check(const ExprPtr& expr);
  void dfs_binary_op_non_mem(std::stringstream& dfs_simulator,
                             std::string& indent, const ExprPtr& expr);
  void dfs_binary_op_non_mem_check(const ExprPtr& expr);
  void dfs_binary_op_mem(std::stringstream& dfs_simulator, std::string& indent,
                         const ExprPtr& expr);
  void dfs_extract_op(std::stringstream& dfs_simulator, std::string& indent,
                      const ExprPtr& expr);
  void dfs_ext_op(std::stringstream& dfs_simulator, std::string& indent,
                  const ExprPtr& expr);
  void dfs_func_op(std::stringstream& dfs_simulator, std::string& indent,
                   const ExprPtr& expr);
  void dfs_func_op_check(const ExprPtr& expr);
  void dfs_ite_op(std::stringstream& dfs_simulator, std::string& indent,
                  const ExprPtr& expr);
  std::string get_type_str(const ExprPtr& expr);

  std::string get_arg_str(const ExprPtr& arg);
  void increase_indent(std::string& indent);
  void decrease_indent(std::string& indent);
  int get_update_state_num(const InstrPtr& instr_expr);
  bool load_from_store_analysis(const ExprPtr& expr);
  void declare_variable_with_id(size_t id, const std::string& v_type,
                                const std::string& v_name);
  void int_var_width_scan();

  /// Generate files required by CMake
  void generate_cmake_support();

  std::string export_dir_;
  std::string systemc_path_;

  std::stringstream header_;
  std::stringstream mk_script_;
  std::stringstream obj_list_;
  std::string header_indent_;

  bool cmake_support_ = false;
  std::vector<std::string> source_file_list_;
  std::vector<std::string> header_file_list_;

  std::set<size_t> searched_id_set_;
  std::set<size_t> store_ite_set_;
  std::set<size_t> const_mem_set_;
  std::set<size_t> declared_id_set_;
  std::set<std::string> func_set_;
  std::set<size_t> defined_store_ite_set_;
  std::set<size_t> defined_state_set_;
  std::set<int> dfs_ld_search_set_;
  std::vector<ld_info> external_ld_set_;
  std::vector<st_info> external_st_set_;
  int ld_st_counter_ = 0;
  bool EXTERNAL_MEM_ = false;
  const int MEM_MAP_ARRAY_DIV = 16;
  std::set<int> int_var_width_set_;

  // Readable_ is used to control whether the generated function name is
  // huname-readable. When being set true, function will be named based on the
  // instruction name and the updated state name. However, there is a potential
  // same-name bug if setting true.
  bool readable_ = true;
  bool qemu_device_ = false;

  InstrLvlAbsPtr model_ptr_;
};

}; // namespace ilang

#endif // ILANG_TARGET_SC_ILA_SIM_H__
