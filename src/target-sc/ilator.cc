/// \file
/// Implementation of the class Ilator.

#include <ilang/target-sc/ilator.h>

#include <fstream>

#include <fmt/format.h>
#include <z3++.h>

#include <ilang/config.h>
#include <ilang/ila-mngr/pass.h>
#include <ilang/ila-mngr/u_abs_knob.h>
#include <ilang/ila/ast_hub.h>
#include <ilang/target-smt/z3_expr_adapter.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>

/// \namespace ilang
namespace ilang {

//
// static helpers/members
//

static const std::string kDirApp = "app";
static const std::string kDirSrc = "src";
static const std::string kDirInclude = "include";
static const std::string kDirExtern = "extern";

static std::unordered_map<size_t, size_t> kPivotalId;

size_t GetPivotalId(const size_t& id) {
  if (auto pos = kPivotalId.find(id); pos == kPivotalId.end()) {
    auto new_id = kPivotalId.size();
    kPivotalId.insert({id, new_id});
    return new_id;
  } else {
    return pos->second;
  }
}

void WriteFile(const std::string& file_path, const fmt::memory_buffer& buff) {
  std::ofstream fw(file_path);
  ILA_ASSERT(fw.is_open()) << "Fail opening file " << file_path;
  fw << to_string(buff);
  fw.close();
}

bool HasLoadFromStore(const ExprPtr& expr) {
  auto monitor = false;
  auto LoadFromStore = [&monitor](const ExprPtr& e) {
    if (e->is_op()) {
      if (asthub::GetUidExprOp(e) == AstUidExprOp::kLoad) {
        monitor |= e->arg(0)->is_op();
      }
    }
  };
  expr->DepthFirstVisit(LoadFromStore);
  return monitor;
}

//
// Ilator implementation
//

Ilator::Ilator(const InstrLvlAbsPtr& m) : m_(m) {}

Ilator::~Ilator() { Reset(); }

void Ilator::Generate(const std::string& dst, bool opt) {
  // sanity checks and initialize
  if (!SanityCheck() || !Bootstrap(dst, opt)) {
    return;
  }

  auto status = true;
  ILA_INFO << "Start generating SystemC simulator of " << m_;

  // non-instruction basics
  status &= GenerateIlaBasics(os_portable_append_dir(dst, kDirSrc));

  // instruction semantics (decode and updates)
  for (auto& instr : absknob::GetInstrTree(m_)) {
    status &= GenerateInstrContent(instr, os_portable_append_dir(dst, kDirSrc));
  }

  // memory updates
  status &= GenerateMemoryUpdate(os_portable_append_dir(dst, kDirSrc));

  // constant memory
  status &= GenerateConstantMemory(os_portable_append_dir(dst, kDirSrc));

  // initial condition setup
  status &= GenerateInitialSetup(os_portable_append_dir(dst, kDirSrc));

  // execution kernel
  status &= GenerateExecuteKernel(os_portable_append_dir(dst, kDirSrc));

  // shared header (input, state, func., etc.)
  status &= GenerateGlobalHeader(os_portable_append_dir(dst, kDirInclude));

  // cmake support, e.g., recipe and templates
  status &= GenerateBuildSupport(dst);

  // clean up if something went wrong
  if (status) {
    ILA_INFO << "Sucessfully generate SystemC simulator at " << dst;
  } else {
    ILA_ERROR << "Fail generating simulator at " << dst;
#ifdef NDEBUG
    os_portable_remove_directory(dst);
#endif // NDEBUG
  }
}

void Ilator::Reset() {
  // functions
  for (auto f : functions_) {
    delete f.second;
  }
  functions_.clear();

  // externs
  for (auto f : externs_) {
    delete f.second;
  }
  externs_.clear();

  // memory updates
  for (auto f : memory_updates_) {
    delete f.second;
  }
  memory_updates_.clear();

  // others
  source_files_.clear();
  const_mems_.clear();
  global_vars_.clear();
}

bool Ilator::SanityCheck() const {
  // add new check here
  return true;
}

bool Ilator::Bootstrap(const std::string& root, bool opt) {
  Reset();
  auto status = true;

  // light-weight preprocessing
  if (opt) {
    status &= pass::SimplifySyntactic(m_);
    status &= pass::RewriteConditionalStore(m_);
  }

  // create/structure project directory
  status &= os_portable_mkdir(root);
  status &= os_portable_mkdir(os_portable_append_dir(root, kDirApp));
  status &= os_portable_mkdir(os_portable_append_dir(root, kDirExtern));
  status &= os_portable_mkdir(os_portable_append_dir(root, kDirInclude));
  status &= os_portable_mkdir(os_portable_append_dir(root, kDirSrc));
  if (!status) {
    os_portable_remove_directory(root);
  }

  ILA_ERROR_IF(!status) << "Fail bootstraping";
  return status;
}

bool Ilator::GenerateIlaBasics(const std::string& dir) {
  StrBuff buff;

  // include headers
  fmt::format_to(buff, "#include <{}.h>\n", GetProjectName());

  // generate valid func for each ILA
  auto PerIla = [this, &buff](const InstrLvlAbsCnstPtr& m) {
    ILA_NOT_NULL(m);
    auto valid_expr = m->valid();
    if (!valid_expr) {
      valid_expr = asthub::BoolConst(true);
      ILA_WARN << "Use default (true) valid for " << m;
    }
    auto valid_func = RegisterFunction(GetValidFuncName(m), valid_expr);
    BeginFuncDef(valid_func, buff);
    ExprVarMap lut;
    ILA_CHECK(RenderExpr(valid_expr, buff, lut));
    fmt::format_to(buff, "auto& {universal_name} = {local_name};\n",
                   fmt::arg("universal_name", GetCxxName(valid_expr)),
                   fmt::arg("local_name", LookUp(valid_expr, lut)));
    EndFuncDef(valid_func, buff);
  };

  // traverse the hierarchy
  m_->DepthFirstVisit(PerIla);

  // record and write to file
  CommitSource("all_valid_funcs_in_hier.cc", dir, buff);
  return true;
}

bool Ilator::GenerateInstrContent(const InstrPtr& instr,
                                  const std::string& dir) {
  StrBuff buff;
  ExprVarMap lut;

  // include headers
  fmt::format_to(buff, "#include <{}.h>\n", GetProjectName());

  // decode function
  auto decode_expr = instr->decode();
  auto decode_func = RegisterFunction(GetDecodeFuncName(instr), decode_expr);
  BeginFuncDef(decode_func, buff);
  lut.clear();
  if (!RenderExpr(decode_expr, buff, lut)) {
    return false;
  }
  fmt::format_to(buff, "auto& {universal_name} = {local_name};\n",
                 fmt::arg("universal_name", GetCxxName(decode_expr)),
                 fmt::arg("local_name", LookUp(decode_expr, lut)));
  EndFuncDef(decode_func, buff);

  // next state
  auto update_func = RegisterFunction(GetUpdateFuncName(instr));
  BeginFuncDef(update_func, buff);
  lut.clear();
  std::set<ExprPtr> visited;
  auto updated_states = instr->updated_states();
  for (const auto& s : updated_states) {
    // check if visited
    auto update_expr = instr->update(s);
    if (auto pos = visited.find(update_expr); pos == visited.end()) {
      visited.insert(update_expr);
    } else {
      continue;
    }

    // create placeholder
    if (auto update_expr = instr->update(s); !update_expr->is_mem()) {
      if (!RenderExpr(update_expr, buff, lut)) {
        return false;
      }
      fmt::format_to(buff, "auto {local_var}_nxt_holder = {local_var};\n",
                     fmt::arg("local_var", LookUp(update_expr, lut)));
    } else { // memory (one copy for performance, require special handling)
      if (HasLoadFromStore(update_expr)) {
        return false;
      }
      auto placeholder = GetLocalVar(lut);
      auto [it, status] = lut.try_emplace(update_expr, placeholder);
      ILA_ASSERT(status);
      auto mem_update_func = RegisterMemoryUpdate(update_expr);
      fmt::format_to(buff,
                     "{mem_type} {placeholder};\n"
                     "{mem_update_func}({placeholder});\n",
                     fmt::arg("mem_type", GetCxxType(update_expr)),
                     fmt::arg("mem_update_func", mem_update_func->name),
                     fmt::arg("placeholder", placeholder));
      // dummy traverse collect related memory operation
      StrBuff dummy_buff;
      ExprVarMap dummy_lut;
      if (!RenderExpr(update_expr, dummy_buff, dummy_lut)) {
        return false;
      }
    }
  }
  // update state
  for (auto& s : updated_states) {
    auto curr = instr->host()->state(s);
    auto next = instr->update(s);
    if (!curr->is_mem()) {
      fmt::format_to(buff, "{current} = {next_value}_nxt_holder;\n",
                     fmt::arg("current", GetCxxName(curr)),
                     fmt::arg("next_value", LookUp(next, lut)));
    } else {
      fmt::format_to(buff,
                     "for (auto& it : {next_value}) {{\n"
                     "  {current}[it.first] = it.second;\n"
                     "}}\n",
                     fmt::arg("current", GetCxxName(curr)),
                     fmt::arg("next_value", LookUp(next, lut)));
    }
  }

  // add update states logging
  fmt::format_to(buff, "#ifdef ILATOR_VERBOSE\n");
  fmt::format_to(buff, "instr_update_log << \"No.\" << std::dec << GetInstrCntr() << '\\t' << "
                  "\"{instr_name} state updates:\" << std::endl;\n",
                  fmt::arg("instr_name", instr->name().str()));
  for (auto& s : updated_states) {
    auto curr = instr->host()->state(s);
    if (!curr->is_mem()) {
      fmt::format_to(buff,
                     "instr_update_log << \"    {state_name} => \" << "
                     "std::hex << \"0x\" << {state_name} << std::endl; \n",
                     fmt::arg("state_name", GetCxxName(curr)));
    } else {
      fmt::format_to(buff,
                     "instr_update_log << \"    {state_name} get updated\" "
                     "<< std::endl;\n",
                     fmt::arg("state_name", GetCxxName(curr)));
    }
  }
  fmt::format_to(buff, "instr_update_log << std::endl;\n");
  fmt::format_to(buff, "#endif\n");

  EndFuncDef(update_func, buff);

  // record and write to file
  CommitSource(fmt::format("idu_{}.cc", instr->name().str()), dir, buff);
  return true;
}

bool Ilator::GenerateMemoryUpdate(const std::string& dir) {

  // helper for traversing memory updates
  class MemUpdateVisiter {
  public:
    MemUpdateVisiter(Ilator* h, StrBuff& b, ExprVarMap& l)
        : host(h), buff_ref(b), lut_ref(l) {}

    bool pre(const ExprPtr& expr) {
      // stop traversing when reaching memory ITE (stand-alone func)
      if (expr->is_mem() && expr->is_op() &&
          asthub::GetUidExprOp(expr) == AstUidExprOp::kIfThenElse) {
        host->DfsExpr(expr, buff_ref, lut_ref);
        return true;
      } else {
        return false;
      }
    }

    void post(const ExprPtr& expr) { host->DfsExpr(expr, buff_ref, lut_ref); }

    Ilator* host;
    StrBuff& buff_ref;
    ExprVarMap lut_ref;
  };

  auto RenderMemUpdate = [this](const ExprPtr& e, StrBuff& b, ExprVarMap& l) {
    auto mem_visiter = MemUpdateVisiter(this, b, l);
    e->DepthFirstVisitPrePost(mem_visiter);
  };

  // helpers for managing files
  int file_cnt = 0;
  auto GetMemUpdateFile = [&file_cnt]() {
    return fmt::format("memory_update_functions_{}.cc", file_cnt++);
  };

  StrBuff buff;
  auto StartNewFile = [this, &buff]() {
    buff.clear();
    fmt::format_to(buff, "#include <{}.h>\n", GetProjectName());
  };

  // start generating
  StartNewFile();
  ExprVarMap lut;

  for (auto mem_update_func_it : memory_updates_) {
    auto& mem_update_func = mem_update_func_it.second;
    ILA_NOT_NULL(mem_update_func);
    auto& mem = mem_update_func->target;

    lut.clear();

    BeginFuncDef(mem_update_func, buff);

    if (asthub::GetUidExprOp(mem) == AstUidExprOp::kStore) {
      RenderMemUpdate(mem, buff, lut);
    } else { // ite
      RenderExpr(mem->arg(0), buff, lut);
      auto lut_local_true = lut;
      auto& lut_local_false = lut; // reuse

      fmt::format_to(buff, "if ({}) {{\n", LookUp(mem->arg(0), lut));
      RenderMemUpdate(mem->arg(1), buff, lut_local_true);
      fmt::format_to(buff, "}} else {{\n");
      RenderMemUpdate(mem->arg(2), buff, lut_local_false);
      fmt::format_to(buff, "}}\n");
    }

    EndFuncDef(mem_update_func, buff);

    if (buff.size() > 50000) {
      CommitSource(GetMemUpdateFile(), dir, buff);
      StartNewFile();
    }
  }

  CommitSource(GetMemUpdateFile(), dir, buff);
  return true;
}

bool Ilator::GenerateConstantMemory(const std::string& dir) {
  StrBuff buff;
  fmt::format_to(buff, "#include <{}.h>\n", GetProjectName());

  for (auto& mem : const_mems_) {
    auto const_mem = std::dynamic_pointer_cast<ExprConst>(mem);
    const auto& val_map = const_mem->val_mem()->val_map();
    std::vector<std::string> addr_data_pairs;
    for (auto& it : val_map) {
      addr_data_pairs.push_back(fmt::format("  {{{addr}, {data}}}",
                                            fmt::arg("addr", it.first),
                                            fmt::arg("data", it.second)));
    }
    fmt::format_to(
        buff,
        "{var_type} {project}::{var_name} = {{\n"
        "{addr_data_pairs}\n"
        "}};\n",
        fmt::arg("var_type", GetCxxType(mem)),
        fmt::arg("project", GetProjectName()),
        fmt::arg("var_name", GetCxxName(mem)),
        fmt::arg("addr_data_pairs", fmt::join(addr_data_pairs, ",\n")));
  }

  CommitSource("constant_memory_def.cc", dir, buff);
  return true;
}

bool Ilator::GenerateInitialSetup(const std::string& dir) {
  // conjunct all initial condition
  auto init = asthub::BoolConst(true);
  auto ConjInit = [&init](const InstrLvlAbsCnstPtr& m) {
    for (size_t i = 0; i < m->init_num(); i++) {
      init = asthub::And(init, m->init(i));
    }
  };
  m_->DepthFirstVisit(ConjInit);

  // get value for referred vars
  z3::context ctx;
  z3::solver solver(ctx);
  Z3ExprAdapter gen(ctx);
  solver.add(gen.GetExpr(init));
  auto res = solver.check();
  if (res != z3::sat) {
    ILA_ERROR << "Fail finding assignment satisfying initial condition";
    return false;
  }

  std::map<ExprPtr, uint64_t> init_values;
  auto model = solver.get_model();
  auto refer_vars = absknob::GetVar(init);
  for (const auto& var : refer_vars) {
    auto var_value = model.eval(gen.GetExpr(var));
    try {
#ifndef Z3_LEGACY_API
      auto value_holder = var_value.get_numeral_uint64();
#else
      __uint64 value_holder;
      Z3_get_numeral_uint64(ctx, var_value, &value_holder);
#endif
      init_values.emplace(var, value_holder);
    } catch (...) {
      ILA_ERROR << "Fail getting " << var_value;
      return false;
    }
  }

  // gen file
  auto init_func = RegisterFunction("setup_initial_condition");
  StrBuff buff;
  fmt::format_to(buff, "#include <{}.h>\n", GetProjectName());
  BeginFuncDef(init_func, buff);
  for (auto pair : init_values) {
    fmt::format_to(buff, "{var_name} = {var_value};\n",
                   fmt::arg("var_name", GetCxxName(pair.first)),
                   fmt::arg("var_value", pair.second));
  }
  EndFuncDef(init_func, buff);
  CommitSource("setup_initial_condition.cc", dir, buff);
  return true;
}

bool Ilator::GenerateExecuteKernel(const std::string& dir) {
  StrBuff buff;

  fmt::format_to( // headers
      buff,
      "#include <iomanip>\n"
      "#include <{project}.h>\n",
      fmt::arg("project", GetProjectName()));

  fmt::format_to( // logging
      buff,
      "static int instr_cntr = 0;\n"
      "int {project}::GetInstrCntr() {{\n"
      "  return instr_cntr;\n"
      "}}\n"
      "void {project}::IncrementInstrCntr() {{\n"
      "  instr_cntr++;\n"
      "}}\n"
      "void {project}::LogInstrSequence(const std::string& instr_name) {{\n"
      "  instr_log << \"Instr No.\" << std::setw(5) << GetInstrCntr() << '\\t';\n"
      "  instr_log << instr_name << \" is activated\\n\";\n"
      "  IncrementInstrCntr();\n"
      "}}\n",
      fmt::arg("project", GetProjectName()));

  fmt::format_to(buff, "static bool g_initialized = false;\n");

  auto kernel_func = RegisterFunction("compute");
  BeginFuncDef(kernel_func, buff);

  // setup initial condition
  fmt::format_to(buff, "if (!g_initialized) {{\n"
                       "  setup_initial_condition();\n"
                       "  g_initialized = true;\n"
                       "}}\n");

  // read in input value
  for (size_t i = 0; i < m_->input_num(); i++) {
    fmt::format_to(buff, "{input_name} = {input_name}_in.read();\n",
                   fmt::arg("input_name", GetCxxName(m_->input(i))));
  }

  // instruction execution
  auto ExecInstr = [this, &buff](const InstrPtr& instr, bool child) {
    fmt::format_to(
        buff,
        "if ({valid_func_name}() && {decode_func_name}()) {{\n"
        "  {update_func_name}();\n"
        "  {child_counter}"
        "#ifdef ILATOR_VERBOSE\n"
        "  LogInstrSequence(\"{instr_name}\");\n"
        "#endif\n"
        "}}\n",
        fmt::arg("valid_func_name", GetValidFuncName(instr->host())),
        fmt::arg("decode_func_name", GetDecodeFuncName(instr)),
        fmt::arg("update_func_name", GetUpdateFuncName(instr)),
        fmt::arg("child_counter", (child ? "schedule_counter++;\n" : "")),
        fmt::arg("instr_name", instr->name().str()));
  };

  auto top_instrs = absknob::GetInstr(m_);
  auto all_instrs = absknob::GetInstrTree(m_);

  // top-level instr
  for (auto& instr : top_instrs) {
    ExecInstr(instr, false);
  }

  // child instr
  fmt::format_to(buff, "while (1) {{\n"
                       "  int schedule_counter = 0;\n");
  std::set<InstrPtr> tops(top_instrs.begin(), top_instrs.end());
  for (auto& instr : all_instrs) {
    if (tops.find(instr) == tops.end()) {
      ExecInstr(instr, true);
    }
  }
  fmt::format_to(buff, "  if (schedule_counter == 0) {{\n"
                       "    break;\n"
                       "  }}\n"
                       "}}\n");

  // done
  EndFuncDef(kernel_func, buff);

  CommitSource("compute.cc", dir, buff);
  return true;
}

bool Ilator::GenerateGlobalHeader(const std::string& dir) {
  StrBuff buff;

  fmt::format_to(buff,
                 "#include <fstream>\n"
                 "#include <systemc.h>\n"
#ifdef ILATOR_PRECISE_MEM
                 "#include <map>\n"
#else
                 "#include <unordered_map>\n"
#endif
                 "SC_MODULE({project}) {{\n"
                //  "  extern int instr_cntr;\n"
                 "  std::ofstream instr_log;\n"
                 "  std::ofstream instr_update_log;\n" // add instruction state update logging
                 "  int GetInstrCntr();\n"
                 "  void IncrementInstrCntr();\n"
                 "  void LogInstrSequence(const std::string& instr_name);\n",
                 fmt::arg("project", GetProjectName()));

  // input
  for (auto& var : absknob::GetInp(m_)) {
    fmt::format_to(buff,
                   "  sc_in<{var_type}> {var_name}_in;\n"
                   "  {var_type} {var_name};\n",
                   fmt::arg("var_type", GetCxxType(var)),
                   fmt::arg("var_name", GetCxxName(var)));
  }

  // state and global vars (e.g., CONCAT)
  for (auto& var : absknob::GetSttTree(m_)) {
    fmt::format_to(buff, "  {var_type} {var_name};\n",
                   fmt::arg("var_type", GetCxxType(var)),
                   fmt::arg("var_name", GetCxxName(var)));
  }
  for (auto& var : global_vars_) {
    fmt::format_to(buff, "  {var_type} {var_name};\n",
                   fmt::arg("var_type", GetCxxType(var)),
                   fmt::arg("var_name", GetCxxName(var)));
  }

  // memory constant
  for (auto& mem : const_mems_) {
    fmt::format_to(buff, "  static {var_type} {var_name};\n",
                   fmt::arg("var_type", GetCxxType(mem)),
                   fmt::arg("var_name", GetCxxName(mem)));
  }

  // function declaration
  for (auto& func : functions_) {
    WriteFuncDecl(func.second, buff);
  }
  for (auto& func : externs_) {
    WriteFuncDecl(func.second, buff);
  }
  for (auto& func : memory_updates_) {
    WriteFuncDecl(func.second, buff);
  }

  // invoke
  fmt::format_to(buff,
                 "  SC_HAS_PROCESS({project});\n"
                 "  {project}(sc_module_name name_) : sc_module(name_) {{\n"
                 "    SC_METHOD(compute);\n"
                 "    sensitive",
                 fmt::arg("project", GetProjectName()));
  for (auto& var : absknob::GetInp(m_)) {
    fmt::format_to(buff, " << {input_name}_in",
                   fmt::arg("input_name", GetCxxName(var)));
  }
  fmt::format_to(buff, ";\n"
                       "  }}\n");

  // done
  fmt::format_to(buff, "}};\n");

  // write to file
  auto file_path = os_portable_append_dir(dir, GetProjectName() + ".h");
  WriteFile(file_path, buff);
  return true;
}

bool Ilator::GenerateBuildSupport(const std::string& dir) {
  // CMakeLists.txt
  static const char* kCmakeRecipeTemplate =
      "# CMakeLists.txt for {project}\n"
      "cmake_minimum_required(VERSION 3.14.0)\n"
      "project({project} LANGUAGES CXX)\n"
      "\n"
      "option(ILATOR_VERBOSE \"Enable instruction sequence logging\" OFF)\n"
      // "option(ILATOR_INSN_VERBOSE \"Enable instruction state updates logging\" OFF)\n"
      "option(JSON_SUPPORT \"Build JSON parser support\" OFF)\n"
      "\n"
      "find_package(SystemCLanguage CONFIG REQUIRED)\n"
      "set(CMAKE_CXX_STANDARD ${{SystemC_CXX_STANDARD}})\n"
      "\n"
      "aux_source_directory(extern extern_src)\n"
      "add_executable({project}\n"
      "  ${{CMAKE_CURRENT_SOURCE_DIR}}/{dir_app}/main.cc\n"
      "  ${{extern_src}}\n"
      "{source_files}\n"
      ")\n"
      "\n"
      "target_include_directories({project} PRIVATE {dir_include})\n"
      "target_link_libraries({project} SystemC::systemc)\n"
      "if(${{ILATOR_VERBOSE}})\n"
      "  target_compile_definitions({project} PRIVATE ILATOR_VERBOSE)\n"
      "endif()\n"
      // "if(${{ILATOR_INSN_VERBOSE}})\n"
      // "  target_compile_definitions({project} PRIVATE ILATOR_INSN_VERBOSE)\n"
      // "endif()\n"
      "if(${{JSON_SUPPORT}})\n"
      "  include(FetchContent)\n"
      "  FetchContent_Declare(\n"
      "    json\n"
      "    GIT_REPOSITORY https://github.com/nlohmann/json.git\n"
      "    GIT_TAG        v3.8.0\n"
      "  )\n"
      "  FetchContent_MakeAvailable(json)\n"
      "  target_link_libraries({project} nlohmann_json::nlohmann_json)\n"
      "endif()\n";

  std::vector<std::string> src_files;
  for (auto& f : source_files_) {
    src_files.push_back(
        fmt::format("  ${{CMAKE_CURRENT_SOURCE_DIR}}/{dir}/{file}",
                    fmt::arg("dir", kDirSrc), fmt::arg("file", f)));
  }

  StrBuff buff;
  fmt::format_to(buff, kCmakeRecipeTemplate,
                 fmt::arg("project", GetProjectName()),
                 fmt::arg("dir_app", kDirApp),
                 fmt::arg("source_files", fmt::join(src_files, "\n")),
                 fmt::arg("dir_include", kDirInclude));

  WriteFile(os_portable_append_dir(dir, "CMakeLists.txt"), buff);

  // dummy main function if not exist
  static const char* kSimEntryTemplate =
      "#include <{project}.h>\n\n"
      "int sc_main(int argc, char* argv[]) {{\n"
      "  return 0; \n"
      "}}\n";

  auto entry_path =
      os_portable_append_dir(os_portable_append_dir(dir, kDirApp), "main.cc");

  if (!os_portable_exist(entry_path)) {
    buff.clear();
    fmt::format_to(buff, kSimEntryTemplate,
                   fmt::arg("project", GetProjectName()));
    WriteFile(entry_path, buff);
  }

  return true;
}

bool Ilator::RenderExpr(const ExprPtr& expr, StrBuff& buff, ExprVarMap& lut) {

  class ExprDfsVisiter {
  public:
    ExprDfsVisiter(Ilator* hi, StrBuff& bi, ExprVarMap& li)
        : host(hi), b(bi), l(li) {}
    bool pre(const ExprPtr& e) { return l.find(e) != l.end(); }
    void post(const ExprPtr& e) { host->DfsExpr(e, b, l); }

    Ilator* host;
    StrBuff& b;
    ExprVarMap& l;
  };

  try {
    auto visiter = ExprDfsVisiter(this, buff, lut);
    expr->DepthFirstVisitPrePost(visiter);
  } catch (std::exception& err) {
    ILA_ERROR << err.what();
    return false;
  }
  return true;
}

Ilator::CxxFunc* Ilator::RegisterFunction(const std::string& func_name,
                                          ExprPtr return_expr) {
  auto func = new CxxFunc(func_name, return_expr);
  auto [it, status] = functions_.insert({func->name, func});
  ILA_ASSERT(status);
  return func;
}

Ilator::CxxFunc* Ilator::RegisterExternalFunc(const FuncPtr& func) {
  auto func_cxx = new CxxFunc(func->name().str(), func->out());
  auto [it, status] = externs_.insert({func_cxx->name, func_cxx});
  // uninterpreted function can have multiple occurrence
  if (status) {
    for (size_t i = 0; i < func->arg_num(); i++) {
      it->second->args.push_back(func->arg(i));
    }
  } else {
    delete func_cxx;
  }
  return it->second;
}

Ilator::CxxFunc* Ilator::RegisterMemoryUpdate(const ExprPtr& mem) {
  auto func_cxx = new CxxFunc(GetMemoryFuncName(mem), NULL, mem);
  auto [it, status] = memory_updates_.insert({func_cxx->name, func_cxx});
  // memory updates can have multiple occurrence
  if (!status) {
    delete func_cxx;
  }
  return it->second;
}

void Ilator::BeginFuncDef(Ilator::CxxFunc* func, StrBuff& buff) const {
  ILA_ASSERT(func->args.empty()); // no definition for uninterpreted funcs

  auto type = (func->ret) ? GetCxxType(func->ret) : GetCxxType(func->ret_type);
  auto args = (func->target)
                  ? fmt::format("{}& tmp_memory", GetCxxType(func->target))
                  : "";

  fmt::format_to(buff, "{return_type} {project}::{func_name}({argument}) {{\n",
                 fmt::arg("return_type", type),
                 fmt::arg("project", GetProjectName()),
                 fmt::arg("func_name", func->name), fmt::arg("argument", args));
}

void Ilator::EndFuncDef(Ilator::CxxFunc* func, StrBuff& buff) const {
  if (func->ret) {
    fmt::format_to(buff, "return {};\n", GetCxxName(func->ret));
  }
  fmt::format_to(buff, "}}\n");
}

void Ilator::WriteFuncDecl(Ilator::CxxFunc* func, StrBuff& buff) const {
  auto type = (func->ret) ? GetCxxType(func->ret) : GetCxxType(func->ret_type);
  auto args = (func->target)
                  ? fmt::format("{}& tmp_memory", GetCxxType(func->target))
                  : "";
  if (!func->args.empty()) { // uninterpreted func only
    ILA_NOT_NULL(func->ret_type);
    std::vector<std::string> arg_list;
    for (const auto& a : func->args) {
      arg_list.push_back(GetCxxType(a));
    }
    args = fmt::format("{}", fmt::join(arg_list, ", "));
  }

  fmt::format_to(buff, "  {return_type} {func_name}({argument});\n",
                 fmt::arg("return_type", type),
                 fmt::arg("func_name", func->name), fmt::arg("argument", args));
}

void Ilator::CommitSource(const std::string& file_name, const std::string& dir,
                          const StrBuff& buff) {
  auto file_path = os_portable_append_dir(dir, file_name);
  auto [it, ret] = source_files_.insert(file_name);
  ILA_ASSERT(ret) << "Duplicated source file name " << file_name;

  WriteFile(file_path, buff);
}

std::string Ilator::GetCxxType(const SortPtr& sort) {
  if (!sort) {
    return "void";
  } else if (sort->is_bool()) {
    return "bool";
  } else if (sort->is_bv()) {
    return fmt::format("sc_biguint<{}>", sort->bit_width());
  } else {
    ILA_ASSERT(sort->is_mem());
#ifdef ILATOR_PRECISE_MEM
    return fmt::format(
        "std::map<sc_biguint<{addr_width}>, sc_biguint<{data_width}>>",
        fmt::arg("addr_width", sort->addr_width()),
        fmt::arg("data_width", sort->data_width()));
#else
    return "std::unordered_map<int, int>";
#endif
  }
}

std::string Ilator::GetCxxName(const ExprPtr& expr) {
  if (expr->is_var()) {
    return fmt::format("{}_{}", expr->host()->name().str(), expr->name().str());
  } else {
    return fmt::format("univ_var_{}", GetPivotalId(expr->name().id()));
  }
}

std::string Ilator::GetValidFuncName(const InstrLvlAbsCnstPtr& m) {
  return fmt::format("valid_{host}", fmt::arg("host", m->name().str()));
}

std::string Ilator::GetDecodeFuncName(const InstrPtr& instr) {
  return fmt::format("decode_{host}_{instr}",
                     fmt::arg("host", instr->host()->name().str()),
                     fmt::arg("instr", instr->name().str()));
}

std::string Ilator::GetUpdateFuncName(const InstrPtr& instr) {
  return fmt::format("update_{host}_{instr}",
                     fmt::arg("host", instr->host()->name().str()),
                     fmt::arg("instr", instr->name().str()));
}

std::string Ilator::GetMemoryFuncName(const ExprPtr& expr) {
  ILA_ASSERT(expr->is_mem());
  if (asthub::GetUidExprOp(expr) == AstUidExprOp::kIfThenElse) {
    return fmt::format("ite_{}", GetPivotalId(expr->name().id()));
  } else {
    return fmt::format("store_{}", GetPivotalId(expr->name().id()));
  }
}

} // namespace ilang
