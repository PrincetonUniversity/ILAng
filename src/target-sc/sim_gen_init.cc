#include <ilang/target-sc/ila_sim.h>

#include <fmt/format.h>

#include <ilang/util/fs.h>
#include <ilang/util/log.h>

#include "ast_fuse.h"

namespace ilang {

void IlaSim::create_init(const InstrLvlAbsPtr& ila) {
  std::stringstream init_function;
  std::string indent = "";
  std::string init_func_name;
  init_func_name = "init_" + ila->name().str();

  auto valid_expr = ila->valid();
  init_decl(init_function, indent, init_func_name);

  auto DfsKernel = [this, &init_function, &indent](const ExprPtr& e) {
    dfs_kernel(init_function, indent, e);
  };
  valid_expr->DepthFirstVisit(DfsKernel);
  init_check_valid(init_function, indent, valid_expr, ila);

  for (unsigned int i = 0; i < ila->init_num(); i++) {
    auto init_expr = ila->init(i);
    if (GetUidExpr(init_expr) != AST_UID_EXPR::OP) {
      ILA_ERROR << "init condition must be a comparison";
    }
    if (GetUidExprOp(init_expr) != AST_UID_EXPR_OP::EQ) {
      ILA_ERROR << "init_condition must be an EQ comparison";
    }
    auto arg0 = init_expr->arg(0);
    auto arg1 = init_expr->arg(1);
    if (GetUidExpr(arg0) != AST_UID_EXPR::VAR) {
      ILA_ERROR << "init_condition must constrain states";
    }
    arg1->DepthFirstVisit(DfsKernel);
    std::string arg0_str = get_arg_str(arg0);
    std::string arg1_str = get_arg_str(arg1);
    init_function << indent << arg0_str << " = " << arg1_str << ";\n";
  }
  init_return(init_function, indent);

  decrease_indent(indent);
  init_function << indent << "};\n";
  init_export(init_function, init_func_name);
  init_mk_file(init_func_name);
  return;
}

void IlaSim::init_decl(std::stringstream& init_function, std::string& indent,
                       std::string& init_func_name) {
  if (!qemu_device_) {
    init_function << "#include \"systemc.h\"\n";
  }
  auto model_name = model_ptr_->name().str();
  init_function << fmt::format("#include \"{}.h\"\n", model_name);
  init_function << indent;
  init_function << fmt::format("void {}::{}() {{\n", model_name,
                               init_func_name);

  increase_indent(indent);
  searched_id_set_.clear();
  header_ << header_indent_ << "void " << init_func_name << "();\n";
}

void IlaSim::init_check_valid(std::stringstream& init_function,
                              std::string& indent, const ExprPtr& valid_expr,
                              const InstrLvlAbsPtr& ila) {
  std::string valid_str;
  auto valid_expr_uid = GetUidExpr(valid_expr);
  if (valid_expr_uid == AST_UID_EXPR::VAR) {
    valid_str = ila->name().str() + "_" + valid_expr->name().str();
  } else if (valid_expr_uid == AST_UID_EXPR::OP) {
    valid_str = "c_" + std::to_string(valid_expr->name().id());
  } else {
    auto valid_expr_const = std::dynamic_pointer_cast<ExprConst>(valid_expr);
    valid_str = std::to_string(valid_expr_const->val_bool()->val());
  }
  init_function << indent << "if (!" << valid_str << ") {\n";
  init_function << indent << "  return;\n";
  init_function << indent << "}\n";
}

void IlaSim::init_return(std::stringstream& init_function,
                         std::string& indent) {
  init_function << indent << "return;\n";
}

void IlaSim::init_export(std::stringstream& init_function,
                         std::string& init_func_name) {
  std::ofstream outFile;

  auto file_name = fmt::format("{}.cc", init_func_name);
  if (cmake_support_) {
    file_name = os_portable_append_dir("src", file_name);
  }

  outFile.open(os_portable_append_dir(export_dir_, file_name));
  outFile << init_function.rdbuf();
  outFile.close();
}

void IlaSim::init_mk_file(std::string& init_func_name) {
  if (qemu_device_)
    mk_script_ << "g++ -I./ -c -o " << init_func_name << ".o " << init_func_name
               << ".cc\n";
  else
    mk_script_ << "g++ -I. -I " << systemc_path_ << "/include/ "
               << "-L. -L " << systemc_path_ << "/lib-linux64/ "
               << "-Wl,-rpath=" << systemc_path_ << "/lib-linux64/ -std=c++11 "
               << "-g -c -o " << init_func_name << ".o " << init_func_name
               << ".cc "
               << "-lsystemc\n";
  obj_list_ << init_func_name << ".o ";

  if (cmake_support_) {
    source_file_list_.push_back(fmt::format("{}.cc", init_func_name));
  }
}

} // namespace ilang
