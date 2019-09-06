#include <ilang/target-sc/ila_sim.h>

#include <ilang/ila/ast_fuse.h>
#include <ilang/util/log.h>

namespace ilang {

void IlaSim::create_decode(const InstrPtr& instr_expr) {
  std::stringstream decode_function;
  std::string indent = "";
  std::string decode_func_name;
  if (readable_)
    decode_func_name = "decode_" + instr_expr->host()->name().str() + "_" +
                       instr_expr->name().str();
  else
    decode_func_name =
        "decode_" + std::to_string(instr_expr->decode()->name().id());
  auto decode_expr = instr_expr->decode();
  decode_decl(decode_function, indent, decode_func_name);
  auto valid_expr = instr_expr->host()->valid();
  auto DfsKernel = [this, &decode_function, &indent](const ExprPtr& e) {
    dfs_kernel(decode_function, indent, e);
  };
  valid_expr->DepthFirstVisit(DfsKernel);
  decode_check_valid(decode_function, indent, valid_expr, instr_expr);
  decode_expr->DepthFirstVisit(DfsKernel);
  decode_return(decode_function, indent, decode_expr, instr_expr);

  decrease_indent(indent);
  decode_function << indent << "};" << std::endl;
  decode_export(decode_function, decode_func_name);
  decode_mk_file(decode_func_name);
  return;
}

void IlaSim::decode_decl(std::stringstream& decode_function,
                         std::string& indent, std::string& decode_func_name) {
  if (!qemu_device_)
    decode_function << "#include \"systemc.h\"" << std::endl;
  decode_function << "#include \"" << model_ptr_->name() << ".h\"" << std::endl;

  decode_function << indent << "bool " << model_ptr_->name()
                  << "::" << decode_func_name << "() {" << std::endl;
  increase_indent(indent);
  searched_id_set_.clear();
  header_ << header_indent_ << "bool " << decode_func_name << "();"
          << std::endl;
}

void IlaSim::decode_check_valid(std::stringstream& decode_function,
                                std::string& indent, const ExprPtr& valid_expr,
                                const InstrPtr& instr_expr) {
  std::string valid_str;
  auto valid_expr_uid = GetUidExpr(valid_expr);
  if (valid_expr_uid == AST_UID_EXPR::VAR)
    valid_str =
        instr_expr->host()->name().str() + "_" + valid_expr->name().str();
  else if (valid_expr_uid == AST_UID_EXPR::OP)
    valid_str = "c_" + std::to_string(valid_expr->name().id());
  else {
    auto valid_expr_const = std::dynamic_pointer_cast<ExprConst>(valid_expr);
    valid_str = std::to_string(valid_expr_const->val_bool()->val());
  }
  decode_function << indent << "if (!" << valid_str << ") {" << std::endl;
  decode_function << indent << "  return false;" << std::endl;
  decode_function << indent << "}" << std::endl;
}

void IlaSim::decode_return(std::stringstream& decode_function,
                           std::string& indent, const ExprPtr& decode_expr,
                           const InstrPtr& instr_expr) {
  std::string decode_str;
  auto decode_expr_uid = GetUidExpr(decode_expr);
  if (decode_expr_uid == AST_UID_EXPR::VAR)
    decode_str =
        instr_expr->host()->name().str() + "_" + decode_expr->name().str();
  else if (decode_expr_uid == AST_UID_EXPR::OP)
    decode_str = "c_" + std::to_string(decode_expr->name().id());
  else {
    auto decode_expr_const = std::dynamic_pointer_cast<ExprConst>(decode_expr);
    decode_str = std::to_string(decode_expr_const->val_bool()->val());
  }
  decode_function << indent << "return " << decode_str << ";" << std::endl;
}

void IlaSim::decode_export(std::stringstream& decode_function,
                           std::string& decode_func_name) {
  std::ofstream outFile;
  std::stringstream out_file;
  outFile.open(export_dir_ + decode_func_name + ".cc");
  outFile << decode_function.rdbuf();
  outFile.close();
}

void IlaSim::decode_mk_file(std::string& decode_func_name) {
  if (qemu_device_)
    mk_script_ << "g++ -I./ -c -o " << decode_func_name << ".o "
               << decode_func_name << ".cc" << std::endl;
  else
    mk_script_ << "g++ -I. -I " << systemc_path_ << "/include/ "
               << "-L. -L " << systemc_path_ << "/lib-linux64/ "
               << "-Wl,-rpath=" << systemc_path_ << "/lib-linux64/ -std=c++11 "
               << "-c -o " << decode_func_name << ".o " << decode_func_name
               << ".cc "
               << "-lsystemc" << std::endl;
  obj_list_ << decode_func_name << ".o ";
}

} // namespace ilang
