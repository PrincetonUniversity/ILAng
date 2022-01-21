/// \file
/// Verilog Generator

#include <ilang/verilog-out/verilog_gen.h>

#include <cctype>
#include <cmath>
#include <iomanip>
#include <string>
#include <type_traits>

#include <ilang/ila/ast_hub.h>
#include <ilang/mcm/ast_helper.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

namespace ilang {

#define toStr(x) (std::to_string(x))

VerilogGeneratorBase::VerilogGeneratorBase(const VlgGenConfig& config,
                                           const std::string& modName,
                                           const std::string& clk,
                                           const std::string& rst)
    : moduleName(modName), clkName(clk), rstName(rst), idCounter(0),
      cfg_(config) {

  // clk, rst
  add_wire(clkName, 1);
  add_input(clkName, 1);
  add_wire(rstName, 1);
  add_input(rstName, 1);
  if (cfg_.start_signal) {
    startName = "__START__";
    add_wire(startName, 1);
    add_input(startName, 1);
  }
}

/// add memory annotation, please invoke right after constructor
void VerilogGeneratorBase::AnnotateMemory(
    const memory_export_annotation_t& annotation) {
  memory_export_annotation = annotation;
}

/// Check if a name is reserved (clk/rst/moduleName/decodeNames/ctrName)
bool VerilogGeneratorBase::check_reserved_name(const vlg_name_t& n) const {
  if (n == moduleName || n == clkName || n == rstName || n == validName ||
      n == counterName || n == startName)
    return false;
  for (auto&& sig : decodeNames) {
    if (sig == n)
      return false;
  }
  return true;
}

// static helper function
std::map<char, std::string> sanitizeTable({
    {'.', "__DOT__"},   {'<', "__LT__"},    {'>', "__GT__"},
    {'!', "__NOT__"},   {'~', "__NEG__"},   {'-', "__DASH__"},
    {'&', "__AND__"},   {'|', "__SEP__"},   {' ', "__SPACE__"},
    {'*', "__STAR__"},  {'%', "__PERC__"},  {'#', "__BANG__"},
    {'@', "__AT__"},    {'0', "__ZERO__"},  {'1', "__ONE__"},
    {'2', "__TWO__"},   {'3', "__THREE__"}, {'4', "__FOUR__"},
    {'5', "__FIVE__"},  {'6', "__SIX__"},   {'7', "__SEVEN__"},
    {'8', "__EIGHT__"}, {'9', "__NINE__"} //,  {'$', "__DOLLAR__"}
});

unsigned symbol_cnt = 0;
static std::string get_symbol_new() {
  return std::string("n") + std::to_string(symbol_cnt++);
}

VerilogGeneratorBase::vlg_name_t
VerilogGeneratorBase::sanitizeName(const vlg_name_t& n) {

  std::string outStr;
  for (unsigned idx = 0; idx < n.length(); ++idx) {
    char c = n[idx];
    if (idx == 0 && isdigit(c)) {
      outStr += sanitizeTable[c];
      continue;
    }

    if (isalnum(c) || c == '_' || c == '$') {
      outStr += c;
      continue;
    }
    auto pos = sanitizeTable.find(c);
    if (pos != sanitizeTable.end()) {
      outStr += pos->second;
      continue;
    }
    // not in table, add it
    auto newName = "_s_" + get_symbol_new() + "_s_";
    sanitizeTable.insert({c, newName});
    outStr += newName;
  }
  return outStr;
}
VerilogGeneratorBase::vlg_name_t
VerilogGeneratorBase::sanitizeName(const ExprPtr& n) {
  ILA_ASSERT(n->is_var()) << "Should not be used on node other than variables";
  return sanitizeName(n->name().str());
}

/// will force to be hex
VerilogGeneratorBase::vlg_const_t
VerilogGeneratorBase::ToVlgNum(IlaBvValType value, unsigned width) {
  // get right of the types

  { // range check assuming signed int
    static_assert(IlaBvValType(-1) > IlaBvValType(0),
                  "expecting BvValType to be unsigned value, o.w. this part of "
                  "code must be updated!");
    static_assert(sizeof(IlaBvValUnsignedType) == sizeof(IlaBvValType),
                  "IlaBvValUnsignedType in the header needs update to be sync "
                  "with IlaBvValType!");
    // if width >= sizeof(IlaBvValType) * 8, then this check is actually no use
    // because any value representable is within the range.
    IlaBvValType maxpos = (width >= sizeof(IlaBvValType) * 8)
                              ? IlaBvValType(-1)
                              : (((IlaBvValType)(1) << width) - 1);
    IlaBvValType minneg = 0;
    ILA_ASSERT((minneg <= value && maxpos >= value))
        << "value : " << value << " is out-of-range, min:" << minneg
        << " max:" << maxpos;
    ILA_DLOG("VerilogGen.ToVlgNum") << "width:" << width << ", min:" << minneg
                                    << ", max:" << maxpos << std::endl;
  }

  std::string valstr = IntToStrCustomBase(value, 16, false);
  return (toStr(width) + "'h" + valstr);
}

#if 0 
// the signed version

inline std::string OnesHexOfSuchWidth(unsigned width) {
  // you should not create a int and then convert as width can be larger than 128
  ILA_ASSERT(sizeof(unsigned int)>=4); // 4*2 = 16xF
  std::string ret;
  unsigned n_32bits = width/32;
  unsigned residual = width%32;
  for (unsigned i = 0; i< n_32bits; ++i)
    ret += "ffffffff";
  uint32_t remaining_ones = (1 << residual) - 1;
  ret += IntToStrCustomBase(remaining_ones, 16, false);
  return ret;  
}

/// will force to be hex
VerilogGeneratorBase::vlg_const_t VerilogGeneratorBase::ToVlgNum(IlaBvValType value, unsigned width) {
  // get right of the types

  { // range check assuming signed int
    static_assert(IlaBvValType(-1) < IlaBvValType(0) , 
      "expecting BvValType to be unsigned value, o.w. this part of code must be updated!");
    
    static_assert(sizeof(IlaBvValUnsignedType) == sizeof(IlaBvValType), 
      "you need to update IlaBvValUnsignedType in the header!");
    IlaBvValType maxpos = (1 << (width-1)) -1;
    IlaBvValType minneg = IlaBvValUnsignedType(-1) ^ ((1 << (width-1)) -1);
    ILA_WARN_IF(!(minneg <= value && maxpos >= value)) << "value : " << value 
      << " is out-of-range, min:" << minneg
      << " max:" << maxpos;
    std::cout << "width:" << width << ", min:" << minneg << ", max:" << maxpos << std::endl;
  }

  std::string valstr;
  if (value >= 0)
    valstr = IntToStrCustomBase((IlaBvValUnsignedType)value, 16 , false);
  else {
    IlaBvValUnsignedType unum_within_int = IlaBvValUnsignedType (value);
    if (width < (sizeof(IlaBvValType)*8))
      valstr = IntToStrCustomBase(unum_within_int, 16, false);
    else  { // width >= int_width
      size_t width_diff = width - (sizeof(IlaBvValType)*8);
      valstr = OnesHexOfSuchWidth(width_diff) + IntToStrCustomBase(unum_within_int, 16, false);
    }
    ILA_WARN << "Convert BvConst:" << value << " to its 2's complement:" << valstr;
  }
  return (toStr(width) + "'h" +valstr);
}
#endif

// Currently not used, can be added to enforce sanity check
#define CHECK_NAME(s)                                                          \
  (ILA_ERROR_IF(!check_reserved_name(s))                                       \
   << "Name " << (s) << " is reserved, which should not be used");
#define EXISTS_NAME(n, w)                                                      \
  (all_valid_names.find({(n), (w)}) != all_valid_names.end())
#define ADD_NAME(n, w) all_valid_names.insert({(n), (w)})

/// Get the width of an ExprPtr, must be supported sort, NOTE: function is not
/// an exp Do we really need it?
int VerilogGeneratorBase::get_width(const ExprPtr& n) {
  if (n->sort()->is_bool()) {
    return 1;

  } else if (n->sort()->is_bv()) {
    return n->sort()->bit_width();

  } else if (n->sort()->is_mem()) {
    return n->sort()->data_width(); // NOTE : here we get the data width

  } else {
    ILA_ASSERT(false) << "Unable to get the width for sort " << n->sort();
    return 0;
  }
}
/// convert a widith to a verilog string
std::string VerilogGeneratorBase::WidthToRange(int w) {
  ILA_ERROR_IF(w==0) << "Width should be > 0 !";
  if (w > 1)
    return std::string("[") + toStr(w - 1) + ":0]";
  return "";
}
/// get a new id
VerilogGeneratorBase::vlg_name_t VerilogGeneratorBase::new_id() {
  return "n" + toStr(idCounter++);
}
/// if the exprptr contains some meaning in its name, will try to incorporate
/// that to the name;
VerilogGeneratorBase::vlg_name_t
VerilogGeneratorBase::new_id(const ExprPtr& e) {
  if (!e)
    return new_id();

  auto name = e->name().str();
  auto pos = reference_name_set.find(name);

  if (cfg_.pass_node_name)
    return "n" + toStr(idCounter++) + "__" + sanitizeName(name);

  if (pos ==
      reference_name_set.end()) // not registered to the refererence name set
    return new_id();            // just return the plain name
  return "n" + toStr(idCounter++) + "__" + pos->second;
}
//--------------------------------------------------------------------------

void VerilogGeneratorBase::add_input(const vlg_name_t& n, int w) {
  if (inputs.find(n) != inputs.end()) {
    ILA_CHECK_EQ(inputs[n], w) << "Implementation bug: redeclare of " << n
                               << " width:" << w << " old:" << inputs[n];
    ILA_WARN << "Redeclaration of " << n << ", ignored.";
  }
  inputs.insert({n, w});
}
void VerilogGeneratorBase::add_output(const vlg_name_t& n, int w) {
  if (outputs.find(n) != outputs.end()) {
    ILA_CHECK_EQ(outputs[n], w) << "Implementation bug: redeclare of " << n
                                << " width:" << w << " old:" << outputs[n];
    ILA_WARN << "Redeclaration of " << n << ", ignored.";
  }
  outputs.insert({n, w});
}
void VerilogGeneratorBase::add_wire(const vlg_name_t& n, int w, bool keep) {
  if (wires.find(n) != wires.end()) {
    ILA_CHECK_EQ(wires[n], w) << "Implementation bug: redeclare of " << n
                              << " width:" << w << " old:" << wires[n];
    ILA_WARN << "Redeclaration of " << n << ", ignored.";
  }
  wires.insert({n, w});
  if (keep)
    wires_keep.insert({n, true});
}
void VerilogGeneratorBase::add_reg(const vlg_name_t& n, int w) {
  regs.push_back(vlg_sig_t(n, w));
}
void VerilogGeneratorBase::add_stmt(
    const vlg_stmt_t& s) // you need to put ';' but no need for \n
{
  statements.push_back(s);
}
void VerilogGeneratorBase::add_assign_stmt(const vlg_name_t& l,
                                           const vlg_name_t& r) {
  add_stmt("assign " + l + " = " + r + " ;");
}
void VerilogGeneratorBase::add_always_stmt(const vlg_stmt_t& s) {
  always_stmts.push_back(s);
}
void VerilogGeneratorBase::add_init_stmt(const vlg_stmt_t& s) {
  init_stmts.push_back(s);
}
void VerilogGeneratorBase::add_ite_stmt(const vlg_stmt_t& cond,
                                        const vlg_stmt_t& tstmt,
                                        const vlg_stmt_t& fstmt) {
  ite_stmts.push_back(std::make_tuple(cond, tstmt, fstmt));
}

// the mems to be created
void VerilogGeneratorBase::add_internal_mem(const vlg_name_t& mem_name,
                                            int addr_width, int data_width,
                                            int entry_num) {
  mems_internal.insert(
      {mem_name, vlg_mem_t(mem_name, addr_width, data_width, entry_num)});
}
void VerilogGeneratorBase::add_external_mem(const vlg_name_t& mem_name,
                                            int addr_width, int data_width,
                                            int entry_num) {
  mems_external.insert(
      {mem_name, vlg_mem_t(mem_name, addr_width, data_width, entry_num)});
  /* NO, this should not be done
  vlg_name_t addr_name = mem_name + "_addr_" + new_id();
  vlg_name_t data_name = mem_name + "_data_" + new_id();
  mem_o.push_back( vlg_sig_t(addr_name, addr_width) );
  mem_i.push_back( vlg_sig_t(data_name, data_width) );
  */
}

void VerilogGeneratorBase::add_preheader(const vlg_stmt_t& stmt) {
  preheader += stmt;
}

void VerilogGeneratorBase::DumpToFile(std::ostream& fout) const {
  if (preheader != "") {
    fout << "/* PREHEADER */\n";
    fout << preheader << "\n";
    fout << "/* END OF PREHEADER */\n";
  }
  // no need to worry about mem_i/o , already in i/o

  fout << "module " << moduleName << "(\n";

  std::string
      separator; // input will not be empty of course, output won't either

  for (auto const& sig_pair : inputs) {
    fout << separator << sig_pair.first; // sig_pair.first is the name
    separator = ",\n";
  }
  for (auto const& sig_pair : outputs)
    fout << ",\n" << sig_pair.first; // sig_pair.first is the name
  for (auto const& sig_pair : mem_i)
    fout << ",\n" << sig_pair.first; // sig_pair.first is the name
  for (auto const& sig_pair : mem_o)
    fout << ",\n" << sig_pair.first; // sig_pair.first is the name
  for (auto const& sig_pair : mem_probe_o)
    fout << ",\n" << sig_pair.first; // sig_pair.first is the name
  for (auto const& sig_pair : regs)
    fout << ",\n" << sig_pair.first;

  // let all registers to be output, so they can be acccessible from the port

  fout << "\n);\n";

  for (auto const& sig_pair : inputs)
    fout << "input " << std::setw(10) << WidthToRange(sig_pair.second) << " "
         << (sig_pair.first) << ";\n";
  for (auto const& sig_pair : mem_i)
    fout << "input " << std::setw(10) << WidthToRange(sig_pair.second) << " "
         << (sig_pair.first) << ";\n";
  for (auto const& sig_pair : outputs)
    fout << "output " << std::setw(10) << WidthToRange(sig_pair.second) << " "
         << (sig_pair.first) << ";\n";
  for (auto const& sig_pair : mem_o)
    fout << "output " << std::setw(10) << WidthToRange(sig_pair.second) << " "
         << (sig_pair.first) << ";\n";
  for (auto const& sig_pair : mem_probe_o)
    fout << "output " << std::setw(10) << WidthToRange(sig_pair.second) << " "
         << (sig_pair.first) << ";\n";
  for (auto const& sig_pair : regs)
    fout << "output reg " << std::setw(10) << WidthToRange(sig_pair.second)
         << " " << (sig_pair.first) << ";\n";
  for (auto const& sig_pair : wires) {
    auto pos = wires_keep.find(sig_pair.first);
    if (pos != wires_keep.end() && pos->second)
      fout << "(* keep *) ";
    fout << "wire " << std::setw(10) << WidthToRange(sig_pair.second) << " "
         << (sig_pair.first) << ";\n";
  }

  // now we deal w. the internal mems
  for (auto const& mem : mems_internal) { // mems.first is just a name
    int data_width = std::get<2>(mem.second);
    int addr_width = std::get<1>(mem.second);
    int entry_num_specified = std::get<3>(mem.second);
    int n_elem_allowed = std::pow(2, addr_width);
    int n_elem = n_elem_allowed;
    ILA_ERROR_IF(entry_num_specified != 0 &&
                 entry_num_specified > n_elem_allowed)
        << "Memory : " << std::get<0>(mem.second)
        << ", addr_width:" << addr_width << " is forced to have "
        << entry_num_specified << " entries, which is greater than "
        << "the maximum allowed entry count: " << n_elem_allowed;
    if (entry_num_specified != 0 && entry_num_specified <= n_elem_allowed)
      n_elem = entry_num_specified;
    if(cfg_.add_keep_for_internal_mem)
      fout << "(* keep *) "; // sometimes these regs will be optimized always
    fout << "reg " << std::setw(10) << WidthToRange(data_width) << " "
         << (std::get<0>(mem.second)) << WidthToRange(n_elem) << ";\n";
  }
  // we require that the statements must have ";" ending itself
  for (auto const& stmt : statements)
    fout << stmt << "\n";

  if (init_stmts.size() != 0 || always_stmts.size() != 0 ||
      ite_stmts.size() != 0) {
    fout << "always @(posedge " << clkName << ") begin\n";
    fout << "   if(" << rstName << ") begin\n";
    // init_stmts go in rst cycle
    for (auto const& stmt : init_stmts)
      fout << "       " << stmt << "\n";
    //
    fout << "   end\n";

    // whether to use start to control it
    if (!cfg_.start_signal)
      fout << "   else if(" << (validName == "" ? "1" : validName)
           << ") begin\n";
    else
      fout << "   else if(" << startName << " && " << validName << ") begin\n";

    for (auto const& stmt : always_stmts)
      fout << "       " << stmt << "\n";
    // we don't require ite statement has that
    for (auto const& stmt : ite_stmts) {
      fout << "       "
           << "if (" << std::get<0>(stmt) << ") begin\n";
      fout << "       "
           << "    " << std::get<1>(stmt) << " ;\n";
      fout << "       "
           << "end\n";
      if (std::get<2>(stmt) != "") {
        fout << "       "
             << "else begin\n            " << std::get<2>(stmt)
             << " ;\n        end\n";
      }
    }

    fout << "   end\n";
    fout << "end\n";
  }

  fout << "endmodule\n";
}

//--------------------------------------------------------------------------

VerilogGenerator::VerilogGenerator(const VlgGenConfig& config,
                                   const std::string& modName,
                                   const std::string& clk,
                                   const std::string& rst)
    : VerilogGeneratorBase(config, modName, clk, rst) {}

void VerilogGenerator::insertInput(const ExprPtr& input) {
  ILA_CHECK(input->is_var());
  // we need to consider the case of an input memory
  if (input->is_mem()) {
    ILA_CHECK(false) << "Cannot set memory as input"; // add wires to
                                                      // read from external
    // when in expr parse, remember it is (EXTERNAL mem)
    add_external_mem(sanitizeName(input),         // name
                     input->sort()->addr_width(), // addr_width
                     input->sort()->data_width(), asthub::GetMemSize(input));
  } else {
    add_input(sanitizeName(input), get_width(input));
    add_wire(sanitizeName(input), get_width(input));
  }
}

void VerilogGenerator::insertState(const ExprPtr& state) {
  ILA_ASSERT(state->is_var());
  if (state->is_mem()) { // depends on configuration, we choose to put into
                         // mem_external/mem_internal by default

    bool external = cfg_.extMem;
    if (IN(state->name().str(), memory_export_annotation))
      external = memory_export_annotation.at(state->name().str());
    // we can overwrite the default

    if (external) {
      add_external_mem(sanitizeName(state),         // name
                       state->sort()->addr_width(), // addr_width
                       state->sort()->data_width(), asthub::GetMemSize(state));
      ILA_DLOG("VerilogGen.insertState")
          << "insert emem:" << state->name().str();
    } else {
      add_internal_mem(sanitizeName(state),         // name
                       state->sort()->addr_width(), // addr_width
                       state->sort()->data_width(), asthub::GetMemSize(state));
      if (cfg_.expand_mem) { // vtg should put it to be true here
        // add output
        int n_elem_specified = asthub::GetMemSize(state);
        int addr_range = std::pow(2, state->sort()->addr_width());
        if (n_elem_specified != 0 && n_elem_specified <= addr_range)
          addr_range = n_elem_specified;
        int data_width = state->sort()->data_width();
        for (int idx = 0; idx < addr_range; ++idx) {
          auto probe_wire_name =
              sanitizeName(state) + "_" + std::to_string(idx);
          mem_probe_o.push_back(vlg_sig_t(probe_wire_name, data_width));
          add_wire(probe_wire_name, data_width);
          add_assign_stmt(probe_wire_name, sanitizeName(state) + "[" +
                                               std::to_string(idx) + "]");
        } // for each memory element
      }   // if expand memory
    }     // else (internal memory)
  } else if (state->is_bv()) {
    auto reg_name = sanitizeName(state);
    add_reg(reg_name, state->sort()->bit_width());
    if (cfg_.reg_random_init) {
      add_wire(reg_name + "_randinit", state->sort()->bit_width(), true);
      add_init_stmt(reg_name + " <= " + reg_name + "_randinit ;");
    }
  } else if (state->is_bool()) {
    auto reg_name = sanitizeName(state);
    add_reg(reg_name, 1);
    if (cfg_.reg_random_init) {
      add_wire(reg_name + "_randinit", 1, true);
      add_init_stmt(reg_name + " <= " + reg_name + "_randinit ;");
    }
  }
}

//
//  will export decode/start/...
//  reg [width-1:0] __COUNTER_start__id;  // 0 : WAIT TO START , 1 : First Cycle
//  after decode is true (init: __COUNTER__id )
//
//
//
//

void VerilogGenerator::addInternalCounter(vlg_name_t decode_sig_name,
                                          size_t width) {
  counterName = "__COUNTER_start__" + new_id();
  unsigned max_val = std::pow(2, width) - 1;
  auto inc_cond = "(" + counterName + " >= 1 ) && ( " + counterName + " < " +
                  toStr(max_val) + " )";
  add_reg(counterName, width);
  add_init_stmt(counterName + " <= 0;");

  // the statement will be a bit different
  vlg_stmt_t ctr_stmt = "if ( " + decode_sig_name + " ) begin \n           " +
                        counterName + " <= 1; end\n       " + "else if( " +
                        inc_cond + ") begin\n           " + counterName +
                        " <= " + counterName + " + 1; end";

  add_always_stmt(ctr_stmt);

  // add_ite_stmt( /*Cond*/ decode_sig_name , /*True*/ counterName + " <= 1"  ,
  // "" ); add_ite_stmt( /*Cond*/ inc_cond , /*True*/ counterName + " <= "+
  // counterName +" + 1"  , "" );
}

//--------------------------------------------------------------------------

void VerilogGenerator::parseArg(const ExprPtr& e) {
  for (size_t i = 0; i != e->arg_num(); ++i) {
    ParseNonMemUpdateExpr(e->arg(i));
  }
}

VerilogGenerator::vlg_name_t
VerilogGenerator::getVlgFromExpr(const ExprPtr& e) {

  auto pos = nmap.find(e);
  ILA_ASSERT(pos != nmap.end())
      << "Expr:" << (e) << " has not been translated yet";
  return pos->second;
}
VerilogGenerator::vlg_name_t VerilogGenerator::getArg(const ExprPtr& e,
                                                      const size_t& i) {
  auto arg_i = e->arg(i);
  return getVlgFromExpr(arg_i);
}

VerilogGenerator::vlg_name_t VerilogGenerator::translateApplyFunc(
    std::shared_ptr<ExprOpAppFunc> func_app_ptr_) {
  ILA_NOT_NULL(func_app_ptr_);
  vlg_stmt_t result_stmt;
  int width =
      func_app_ptr_->sort()->is_bool() ? 1 : func_app_ptr_->sort()->bit_width();
  auto func_name = sanitizeName(func_app_ptr_->func()->name().str());

  if (func_app_ptr_->arg_num() == 0) {
    // 0-arg should be treated as nondet (input) , this should be fine for both
    // Yosys and JasperGold
    result_stmt = "nondet_" + func_name + "_" + new_id();
    add_wire(result_stmt, width);
    add_input(result_stmt, width);

    ila_func_app.push_back(
        function_app_t(vlg_sig_t({result_stmt, width}), func_name));
  } else {
    func_ptr_set.insert(
        func_app_ptr_->func()); // record that we have met this function, later
                                // may need to declare a module if internal
    if (cfg_.fcOpt == VlgGenConfig::funcOption::Internal) {
      // here we create a module to do this
      result_stmt = new_id(func_app_ptr_);
      add_wire(result_stmt, width);
      vlg_stmt_t funcInstantiation =
          "fun_" + func_name + "  " + "applyFunc_" + new_id() + "(\n";
      size_t arity = func_app_ptr_->arg_num();
      for (size_t i = 0; i != arity; i++) {
        ILA_ASSERT(func_app_ptr_->arg(i)->is_bool() ||
                   func_app_ptr_->arg(i)->is_bv())
            << "unable to translate f(mem, ...)";
        funcInstantiation +=
            "    .arg" + toStr(i) + "( " + getArg(func_app_ptr_, i) + " ),\n";
      }
      funcInstantiation += "    .result( " + result_stmt + " )\n";
      funcInstantiation += ");";
      add_stmt(funcInstantiation);
      // we need to remember that later we will need to put a module :
      // fun_(funName) (arg0-argn, result)
    } else if (cfg_.fcOpt == VlgGenConfig::funcOption::External) {
      // here we need to generate the input/output
      vlg_name_t prefix = "fun_" +
                          sanitizeName(func_app_ptr_->func()->name().str()) +
                          "_applyFunc_" + new_id();
      vlg_name_t resultName = prefix + "_result";
      add_input(resultName, width);
      add_wire(resultName, width);
      result_stmt = resultName;

      ila_func_app.push_back(
          function_app_t(vlg_sig_t({result_stmt, width}), func_name));

      size_t arity = func_app_ptr_->arg_num();
      for (size_t i = 0; i != arity; i++) {
        vlg_name_t argOutName = prefix + "_arg" + toStr(i);
        ILA_ASSERT(func_app_ptr_->arg(i)->is_bool() ||
                   func_app_ptr_->arg(i)->is_bv())
            << "unable to translate f(mem, ...)";
        int argWidth = get_width(func_app_ptr_->arg(i));
        add_wire(argOutName, argWidth);
        add_output(argOutName, argWidth);
        add_assign_stmt(argOutName, getArg(func_app_ptr_, i));

        ila_func_app.back().args.push_back({argOutName, argWidth});
      }
    } else
      ILA_ASSERT(false) << "Unsupported function export option:" << cfg_.fcOpt;
  }
  return result_stmt;
}

// will be used by ParseNonMemUpdateExpr, will not be directly called by
// ParseMemUpdateNode the later will call the former first
VerilogGenerator::vlg_name_t
VerilogGenerator::translateBoolOp(const std::shared_ptr<ExprOp>& e) {

  vlg_stmt_t result_stmt;
  std::string op_name = e->op_name();
  size_t arg_num = e->arg_num();

  if (op_name == "APP") { // Function application
    // deal with the case with a function
    std::shared_ptr<ExprOpAppFunc> func_app_ptr_ =
        std::dynamic_pointer_cast<ExprOpAppFunc>(e);
    result_stmt = translateApplyFunc(func_app_ptr_);
  } else if (arg_num == 1) {
    if (op_name == "NOT")
      result_stmt = "~ ( " + getArg(e, 0) + " ) ";
    else
      ILA_ASSERT(false) << op_name << " is not supported by VerilogGenerator";
  } else if (arg_num == 2) {
    auto arg1 = getArg(e, 0);
    auto arg2 = getArg(e, 1);
    if (op_name == "AND")
      result_stmt = " ( " + arg1 + " ) & (" + arg2 + " ) ";
    else if (op_name == "OR")
      result_stmt = " ( " + arg1 + " ) | ( " + arg2 + " ) ";
    else if (op_name == "XOR")
      result_stmt = " ( " + arg1 + " ) ^ ( " + arg2 + " ) ";
    else if (op_name == "EQ")
      result_stmt = " ( " + arg1 + " ) == ( " + arg2 + " ) ";
    else if (op_name == "IMPLY")
      result_stmt = " ( ~ ( " + arg1 + " ) | ( " + arg2 +
                    " ) )"; // do we need to support boolean comparison?
    else if (op_name == "LT")
      result_stmt =
          vlg_stmt_t(" $signed( ") + arg1 + " ) < $signed( " + arg2 + " ) ";
    else if (op_name == "GT")
      result_stmt =
          vlg_stmt_t(" $signed( ") + arg1 + " ) > $signed( " + arg2 + " ) ";
    else if (op_name == "ULT")
      result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) < ( " + arg2 + " ) ";
    else if (op_name == "UGT")
      result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) > ( " + arg2 + " ) ";
    else
      ILA_ASSERT(false) << op_name << " is not supported by VerilogGenerator";
  } else if (arg_num == 3) {
    auto arg1 = getArg(e, 0);
    auto arg2 = getArg(e, 1);
    auto arg3 = getArg(e, 2);
    if (op_name == "ITE")
      result_stmt = " ( " + arg1 + " ) ? ( " + arg2 + " ) : ( " + arg3 + " ) ";
    else
      ILA_ASSERT(false) << op_name << " is not supported by VerilogGenerator";
  }
  vlg_name_t result_var = new_id(e);
  add_wire(result_var, 1);
  add_assign_stmt(result_var, result_stmt);
  return result_var;
}

// will be used by ParseNonMemUpdateExpr, will not be directly called by
// ParseMemUpdateNode the later will call the former first
VerilogGenerator::vlg_name_t
VerilogGenerator::translateBvOp(const std::shared_ptr<ExprOp>& e) {

  vlg_stmt_t result_stmt;
  std::string op_name = e->op_name();
  size_t arg_num = e->arg_num();

  if (op_name == "APP") { // Function application
    // deal with the case with a function
    // deal with the case with a function
    std::shared_ptr<ExprOpAppFunc> func_app_ptr_ =
        std::dynamic_pointer_cast<ExprOpAppFunc>(e);
    result_stmt = translateApplyFunc(func_app_ptr_);
  } else if (arg_num == 1) {
    vlg_name_t arg0 = getArg(e, 0);
    if (op_name == "NEGATE") // negate : 2's complement
      result_stmt = vlg_stmt_t("( ~ ( ") + arg0 + " ) + 1'b1 )";
    else if (op_name == "COMPLEMENT") // 1's complement
      result_stmt = vlg_stmt_t("~ ( ") + arg0 + " )";
    else if (op_name == "EXTRACT") {
      int hi = e->param(0);
      int lo = e->param(1);
      result_stmt = arg0 + "[" + toStr(hi) + ":" + toStr(lo) + "]";
    } else if (op_name == "ZERO_EXTEND") {
      int outw = e->param(0);
      int inw = get_width(e->arg(0));
      if (outw == inw)
        result_stmt = arg0;
      else
        result_stmt =
            vlg_stmt_t(" {") + toStr(outw - inw) + "'d0 , " + arg0 + "} ";
    } else if (op_name == "SIGN_EXTEND") {
      int outw = e->param(0);
      int inw = get_width(e->arg(0));
      if (outw == inw)
        result_stmt = arg0;
      else if (e->arg(0)->is_const() && inw == 1) {
        result_stmt = vlg_stmt_t(" { {") + toStr(outw - inw) + "{" + arg0 +
                      "} }, " + arg0 + "} ";
      } else
        result_stmt = vlg_stmt_t(" { {") + toStr(outw - inw) + "{" + arg0 +
                      "[" + toStr(inw - 1) + "]} }, " + arg0 + "} ";
    } else if (op_name == "RIGHT_ROTATE") {
      // {x[i-1:0], x[w-1:i]}
      int rotw = e->param(0);
      int inw = get_width(e->arg(0));
      result_stmt = vlg_stmt_t(" { ( ") + arg0 + "[" + toStr(rotw - 1) +
                    ":0] ), ( " + arg0 + "[" + toStr(inw - 1) + ":" +
                    toStr(rotw) + "] ) } ";
    } else if (op_name == "LEFT_ROTATE") {
      // {x[w-1-i:0], x[w-1:w-i]}
      int rotw = e->param(0);
      int inw = get_width(e->arg(0));
      result_stmt = vlg_stmt_t(" { ( ") + arg0 + "[" + toStr(inw - 1 - rotw) +
                    ":0] ), ( " + arg0 + "[" + toStr(inw - 1) + ":" +
                    toStr(inw - rotw) + "] ) } ";
    } else
      ILA_ASSERT(false) << op_name << " is not supported by VerilogGenerator";
  } // else if(arg_num == 1)
  else if (arg_num == 2) {
    vlg_name_t arg1 = getArg(e, 0);
    vlg_name_t arg2 = getArg(e, 1);
    if (op_name == "AND")
      result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) & ( " + arg2 + " ) ";
    else if (op_name == "OR")
      result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) | ( " + arg2 + " ) ";
    else if (op_name == "XOR")
      result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) ^ ( " + arg2 + " ) ";
    else if (op_name == "SHL") // only shift, use 0 on the right
      result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) << ( " + arg2 + " ) ";
    else if (op_name == "ASHR") // arithmetic shift right
      result_stmt =
          vlg_stmt_t(" ( $signed( ") + arg1 + " ) >>> ( " + arg2 + " )) ";
    else if (op_name == "LSHR")
      result_stmt = vlg_stmt_t(" ( ( ") + arg1 + " ) >> ( " + arg2 + " )) ";
    else if (op_name == "ADD")
      result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) + ( " + arg2 + " ) ";
    else if (op_name == "SUB")
      result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) - ( " + arg2 + " ) ";
    else if (op_name == "MUL")
      result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) * ( " + arg2 + " ) ";
    else if (op_name == "DIV")
      result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) / ( " + arg2 + " ) ";
    else if (op_name == "UREM")
      result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) % ( " + arg2 + " ) ";
    else if (op_name == "CONCAT")
      result_stmt = vlg_stmt_t(" { ( ") + arg1 + " ) , ( " + arg2 + " ) } ";
    else if (op_name == "LOAD") {
      // arg1 should be the memvar // arg2 should be the address
      // in the future, we may need to avoid the leaves first traverse to
      // account for the LOAD(STORE) LOAD(ITE)
      ILA_ASSERT(e->arg(0)->is_var()) << "Implementation bug: unable to handle "
                                         "LOAD(STORE/ITE/MEMCONST) pattern";
      auto mem_var_name = sanitizeName(e->arg(0));
      auto pos = mems_external.find(mem_var_name);
      ILA_DLOG("VerilogGen.translateBvOp")
          << "finding mem in external record:" << mem_var_name;
      if (pos != mems_external.end()) {
        // should generate signals (for mem_i/mem_o)
        ILA_DLOG("VerilogGen.translateBvOp") << "Found.";
        int addr_width = std::get<1>(pos->second);
        int data_width = std::get<2>(pos->second);
        vlg_name_t addr_name = arg1 + "_addr_" + new_id();
        vlg_name_t data_name = arg1 + "_data_" + new_id();
        mem_o.push_back(vlg_sig_t(addr_name, addr_width));
        mem_i.push_back(vlg_sig_t(data_name, data_width));
        add_wire(addr_name, addr_width);
        add_wire(data_name, data_width);

        unsigned new_size_id = ila_rports[mem_var_name].size();
        ila_rports[mem_var_name][new_size_id].raddr = addr_name;
        ila_rports[mem_var_name][new_size_id].rdata = data_name;
        ila_rports[mem_var_name][new_size_id].ren = "__START__";

        add_assign_stmt(addr_name, arg2);

        result_stmt = data_name;
      } // if( pos != mems_external.end() )
      else {
        result_stmt = vlg_stmt_t(" (  ") + mem_var_name + "[" + arg2 + "] ) ";

        ILA_DLOG("VerilogGen.translateBvOp") << "Not found.";
      }
    } // end of else if(op_name == "LOAD")
    else
      ILA_ASSERT(false) << op_name << " is not supported by VerilogGenerator";
  } // end of else if(arg_num == 2)
  else if (arg_num == 3) {
    vlg_name_t arg1 = getArg(e, 0);
    vlg_name_t arg2 = getArg(e, 1);
    vlg_name_t arg3 = getArg(e, 2);
    if (op_name == "ITE")
      result_stmt =
          vlg_stmt_t(" ( ") + arg1 + " ) ? ( " + arg2 + " ) : ( " + arg3 + " )";
    else
      ILA_ASSERT(false) << op_name << " is not supported by VerilogGenerator";
  } // else if(arg_num == 3)
  else
    ILA_ASSERT(false) << op_name << " is not supported by VerilogGenerator";

  vlg_name_t result_var = new_id(e);
  add_wire(result_var, get_width(e));
  add_assign_stmt(result_var, result_stmt);
  return result_var;
}

//--------------------------------------------------------------------------
// used in general for an expression (not the update of a memvar)
void VerilogGenerator::ParseNonMemUpdateExpr(
    const ExprPtr& e) { // will be used in parsing state update of non mem and
                        // decode function
  // memorize

  ILA_DLOG("VerilogGen.ParseNonMemUpdateExpr") << "Parsing:" << e;
  if (nmap.find(e) != nmap.end()) {
    ILA_DLOG("VerilogGen.ParseNonMemUpdateExpr") << "Cached.";
    return;
  }

  if (e->is_bool()) {
    if (e->is_var()) {
      nmap[e] = sanitizeName(e); // just use its name
      ILA_DLOG("VerilogGen.ParseNonMemUpdateExpr")
          << "BoolVar: " << e->name().str();
    } else if (e->is_op()) { // bool op
      // leaves first,
      ILA_DLOG("VerilogGen.ParseNonMemUpdateExpr") << "BoolOp, leaves-first ";
      parseArg(e);
      std::shared_ptr<ExprOp> expr_op_ptr =
          std::dynamic_pointer_cast<ExprOp>(e);
      ILA_NOT_NULL(expr_op_ptr);
      nmap[e] = translateBoolOp(expr_op_ptr);
    } else if (e->is_const()) { // bool const
      vlg_name_t bcnst =
          vlg_name_t("1'b") +
          (std::dynamic_pointer_cast<ExprConst>(e)->val_bool()->val() ? "1"
                                                                      : "0");
      ILA_DLOG("VerilogGen.ParseNonMemUpdateExpr") << "BoolConst: " << bcnst;
      nmap[e] = bcnst;
    } else
      ILA_ASSERT(false) << "Expr sort: " << (e->sort()) << " is not supported.";
  } else if (e->is_bv()) {
    if (e->is_var()) {
      nmap[e] = sanitizeName(e); // just use its name
      ILA_DLOG("VerilogGen.ParseNonMemUpdateExpr") << "BV: " << e->name().str();
    } else if (e->is_op()) {
      // leaves first
      std::shared_ptr<ExprOp> expr_op_ptr =
          std::dynamic_pointer_cast<ExprOp>(e);
      ILA_NOT_NULL(expr_op_ptr);

      ILA_DLOG("VerilogGen.ParseNonMemUpdateExpr") << "BVop, leaves-first ";
      parseArg(e); // if not LOAD, leaf-first
      // BTW, you cannot cache the LOAD(STORE/ITE/MEMCONST) pattern
      nmap[e] = translateBvOp(expr_op_ptr);
    } else if (e->is_const()) {
      int width = get_width(e);
      ILA_ASSERT(width > 0);
      IlaBvValType value =
          (std::dynamic_pointer_cast<ExprConst>(e)->val_bv()->val());
      vlg_name_t result_var;

      auto pos = cmap.find(std::make_pair(value, (unsigned)width));
      if (pos == cmap.end()) { // not found
        vlg_const_t bvcnst = ToVlgNum(value, (unsigned)width);
        result_var = "bv_" + toStr(width) + "_" +
                     toStr(IlaBvValUnsignedType(value)) + "_" + new_id(e);
        add_wire(result_var, get_width(e));
        add_assign_stmt(result_var, bvcnst);

        ILA_DLOG("VerilogGen.ParseNonMemUpdateExpr")
            << "BVconst: " << bvcnst << " as " << result_var;
        cmap.insert(
            std::make_pair(std::make_pair(value, (unsigned)width), result_var));
      } else { // found
        result_var = pos->second;
      }
      nmap[e] = result_var;
    } else
      ILA_ASSERT(false) << "Expr sort: " << (e->sort()) << " is not supported.";

  } else if (e->is_mem()) {
    // TODO: ?
    if (e->is_var())
      nmap[e] = sanitizeName(e); // should not be used
    else if (e->is_const())
      nmap[e] = sanitizeName(e); // should not be used, currently unsupported
    else if (e->is_op())
      ILA_ASSERT(false)
          << "Implementation bug, do not support mem_op ( "
             "LOAD(STORE/ITE/MEMCONST) pattern ) in non-mem-update expression";
    // NOTE: EVEN when we later implement the three LOAD(STORE/ITE/MEMCONST)
    // pattern it should not come to this point, because the load will do a
    // root-first traversal it should not come to this point first
    else
      ILA_ASSERT(false) << "Expr sort: " << (e->sort()) << " is not supported.";
    // (Yes we may encounter the var case), just return its name (but I think it
    // will not be used anyway) (Yes we may encounter the memconst case),
    // currently not handled, so just return its name is fine
  } else
    ILA_ASSERT(false) << "Expr sort: " << (e->sort()) << " is not supported.";
}
// One more note:
//    If you have the load(MemIte(var1,var2), addr)
//    please rewrite it as BvIte(load(var1,addr), load(var2,addr))
//    we always enforce the requirement that MemIte must talk about the same mem

// (for the update of a memvar)
// we support patterns like store(ite) ite(store) and their combination
// but we require that all must refer to the same mem_var (CheckMemUpdateNode
// will check AST) for the memconst, we can support by initial condition, like
//     a) memvar == memstore(memstore(memstore))
//       - but memvar must be an internal memory*
//      M1: can be converted to : if(rst) { memvar[?] <= ... ; memvar[?] <=  }
//        or
//      M2: we can try replace the
//      * restriction may be lifted, if we create an internal mem,
//        and use condition to say which to read (internal/external) where we
//        read the
//
//     b) memvar == memconst
//     this is more difficult as it has the default value requirement
//
// currently, let's not worry about initialization
// as we are verify just one instruction
// for the child-abs, their initial condition should be set by the
// parent instruction
bool VerilogGenerator::CheckMemUpdateNode(const ExprPtr& e,
                                          const std::string& mem_var_name) {
  ILA_ASSERT(e->is_mem()) << mem_var_name << " has sort: "
                          << e->sort(); // require it to be memory
  if (e->is_const())
    return false;
  else if (e->is_var()) {
    if (sanitizeName(e) == mem_var_name)
      return true;
    // else
    return false;
  } else if (e->is_op()) {
    std::shared_ptr<ExprOp> expr_op_ptr = std::dynamic_pointer_cast<ExprOp>(e);
    ILA_NOT_NULL(expr_op_ptr);
    if (expr_op_ptr->op_name() == "STORE")
      return CheckMemUpdateNode(
          expr_op_ptr->arg(0),
          mem_var_name); // it depends if its subtree conforms to the pattern.
    if (expr_op_ptr->op_name() == "ITE")
      return CheckMemUpdateNode(expr_op_ptr->arg(1), mem_var_name) &&
             CheckMemUpdateNode(expr_op_ptr->arg(2), mem_var_name);
    return false;
  } // ITE/STORE
  // else
  return false;
}

// Traverse this update expr
// root first
// collect writes and their conditions
void VerilogGenerator::VisitMemNodes(
    const ExprPtr& e, const ExprPtr& cond,
    mem_write_entry_list_stack_t& writesStack) {
  // ILA_ASSERT( e->is_var() || e->is_op() )

  if (e->is_var()) {
    // we reach the leaf, summary the conditions and writes so far and save them
    mem_write_entry_list_t writes = writesStack.back();
    mem_write_t mw = {cond, writes};
    current_writes.push_back(mw);
  } else {
    // ILA_ASSERT( e->is_op() );
    std::shared_ptr<ExprOp> expr_op_ptr = std::dynamic_pointer_cast<ExprOp>(e);
    ILA_NOT_NULL(expr_op_ptr);
    if (expr_op_ptr->op_name() == "ITE") {
      ExprPtr ctrue = asthub::And(
          cond, expr_op_ptr->arg(0)); // the writes in the true-branch conforms
                                      // to these conditions
      ExprPtr cfalse = asthub::And(
          cond,
          asthub::Not(expr_op_ptr->arg(0))); // the writes in the false-branch
                                             // conforms to these conditions

      mem_write_entry_list_t writes = writesStack.back();
      writesStack.push_back(
          writes); // make a copy of the top the stack and push it
      VisitMemNodes(expr_op_ptr->arg(1), ctrue, writesStack);
      writesStack.pop_back();
      writesStack.push_back(
          writes); // recover the top of the stack to be the copy we have
      VisitMemNodes(expr_op_ptr->arg(2), cfalse, writesStack);
      writesStack.pop_back();
    }      // if (ITE)
    else { // ILA_ASSERT ( expr_op_ptr->op_name()== "STORE" )
      mem_write_entry_t mw = {e->arg(1), e->arg(2)};
      mem_write_entry_list_t& writes = writesStack.back();
      writes.push_back(mw);
      VisitMemNodes(e->arg(0), cond, writesStack);
    }
  } // is memop
} // VerilogGenerator::VisitMemNodes

void VerilogGenerator::ExportFuncDefs() {
  // we don't have the option of verilog function here, becase we don't think
  // this useful for verification
  if (cfg_.fcOpt == VlgGenConfig::funcOption::External)
    return; // if they are external we don't care how they will be implemented
  for (auto&& func_ptr : func_ptr_set) {
    // because we don't add 0-arg func here, there is no need to worry about it
    auto func_name = sanitizeName(func_ptr->name().str());
    vlg_stmt_t funcModDef = "module fun_" + func_name + " (\n";
    for (size_t argIdx = 0; argIdx < func_ptr->arg_num(); ++argIdx) {
      auto arg_sort_ptr = func_ptr->arg(argIdx);
      funcModDef +=
          "    input " +
          WidthToRange(arg_sort_ptr->is_bool() ? 1
                                               : arg_sort_ptr->bit_width()) +
          " arg" + toStr(argIdx) + ",\n";
    }
    funcModDef += "    output " +
                  WidthToRange(func_ptr->out()->is_bool()
                                   ? 1
                                   : func_ptr->out()->bit_width()) +
                  " result\n";
    funcModDef += ");\n";
    funcModDef += "//TODO: Add the specific function HERE.\n";
    funcModDef += "endmodule\n";
    add_preheader(funcModDef);
  }
}

void VerilogGenerator::ExportCondWrites(const ExprPtr& mem_var,
                                        const mem_write_list_t& writeList) {
  // count the maximum ports needed, that is for a single condition what's max
  // size of mem_write_entry_list_t
  bool this_mem_external = cfg_.extMem;
  if (IN(mem_var->name().str(), memory_export_annotation))
    this_mem_external = memory_export_annotation.at(mem_var->name().str());

  auto name = sanitizeName(mem_var);
  auto addr_width = mem_var->sort()->addr_width();
  auto data_width = mem_var->sort()->data_width();

  unsigned max_port_no = 0;
  for (const auto& mw : writeList)
    if (max_port_no < mw.writes.size())
      max_port_no = mw.writes.size();
  for (unsigned portIdx = 0; portIdx < max_port_no; ++portIdx) {
    add_wire(name + "_addr" + toStr(portIdx), addr_width);
    add_wire(name + "_data" + toStr(portIdx), data_width);
    add_wire(name + "_wen" + toStr(portIdx), 1);
    if (this_mem_external) {
      mem_o.push_back(vlg_sig_t(name + "_addr" + toStr(portIdx), addr_width));
      mem_o.push_back(vlg_sig_t(name + "_data" + toStr(portIdx), data_width));
      mem_o.push_back(vlg_sig_t(name + "_wen" + toStr(portIdx), 1));
      // record the mem io
      auto new_size_id = ila_wports[name].size();
      ila_wports[name][new_size_id].waddr = name + "_addr" + toStr(portIdx);
      ila_wports[name][new_size_id].wdata = name + "_data" + toStr(portIdx);
      ila_wports[name][new_size_id].wen = name + "_wen" + toStr(portIdx);
    }
  }
  std::vector<vlg_stmt_t> addrStmt(max_port_no, "0");
  std::vector<vlg_stmt_t> dataStmt(
      max_port_no, "'d0"); // "'dx"); our parser dislikes this, though it is
                           // okay for other parsers
  std::vector<vlg_stmt_t> enabStmt(max_port_no, "1'b0");
  // Note the reverse here!
  for (auto mw_pos = writeList.rbegin(); mw_pos != writeList.rend(); ++mw_pos) {
    const auto& mw = *mw_pos;
    ParseNonMemUpdateExpr(mw.cond);
    vlg_name_t cond = getVlgFromExpr(mw.cond);
    int portIdx = 0;
    for (const auto& wr : mw.writes) {
      ParseNonMemUpdateExpr(wr.addr);
      vlg_name_t addr = getVlgFromExpr(wr.addr);
      ParseNonMemUpdateExpr(wr.data);
      vlg_name_t data = getVlgFromExpr(wr.data);
      addrStmt[portIdx] =
          cond + " ? (" + addr + ") : (" + addrStmt[portIdx] + ")";
      dataStmt[portIdx] =
          cond + " ? (" + data + ") : (" + dataStmt[portIdx] + ")";
      std::string wen_start;
      if (cfg_.start_signal)
        wen_start = "&&" + startName;
      enabStmt[portIdx] = "(" + cond + ")" + wen_start + " ? ( 1'b1 ) : (" +
                          enabStmt[portIdx] + ")";

      portIdx++;
    }
  } // accumulate the final expression, if it is external, then no need to dp
    // anything here

  for (unsigned portIdx = 0; portIdx < max_port_no; ++portIdx) {
    // add statements
    vlg_name_t addrWireName = name + "_addr" + toStr(portIdx);
    vlg_name_t dataWireName = name + "_data" + toStr(portIdx);
    vlg_name_t enabWireName = name + "_wen" + toStr(portIdx);
    add_assign_stmt(addrWireName, addrStmt[portIdx]);
    add_assign_stmt(dataWireName, dataStmt[portIdx]);
    add_assign_stmt(enabWireName, enabStmt[portIdx]);
    // add memory updates in the always block
    if (this_mem_external) {
      // DO NOTHING
    } else {
      vlg_stmt_t assignment =
          name + " [ " + addrWireName + " ] " + "<= " + dataWireName;
      vlg_stmt_t condition = enabWireName;
      add_ite_stmt(condition, assignment, ""); // no else statement
    }
  }
} // VerilogGenerator::ExportCondWrites

// This function is used to parse a expr used as memvar's update
// will first collect the writes & conditions
// and then translate to verilog, the same idiom could be used to handle
// LOAD(STORE/ITE/MEMC)
void VerilogGenerator::ParseMemUpdateNode(const ExprPtr& cond, const ExprPtr& e,
                                          const std::string& mem_var_name) {
  ILA_ASSERT(CheckMemUpdateNode(e, mem_var_name))
      << "Unsupported Expr structure";

  // no we prepare to start to traverse // build initial condition for that
  mem_write_entry_list_stack_t writesStack;
  mem_write_entry_list_t empty_write_entry_list;
  writesStack.push_back(empty_write_entry_list);

  for (const auto& w : current_writes)
    past_writes.push_back(w); // have a container to hold them so will not be
                              // garbarge collected before used

  current_writes.clear();
  VisitMemNodes(e, cond, writesStack);

  // Commented the line below, becasuse this function is not intended to really
  // does the write ExportCondWrites(name,addr_width,data_width,current_writes);
  //
}

//--------------------------------------------------------------------------

// 1. please use the ExtrDeptModl to extract the dependent model
// 2. then, use FlattenIla to get a flatten ILA model
// Export a whole ila,
// you need to put together their update model.

void VerilogGenerator::ExportIla(const InstrLvlAbsPtr& ila_ptr_) {
  ILA_NOT_NULL(ila_ptr_);

  ILA_WARN_IF(ila_ptr_->init_num() != 0)
      << "Currently, it does not translate the initial conditions";

  if (moduleName == "")
    moduleName = sanitizeName(ila_ptr_->name().str());

  // Inputs
  for (size_t idx = 0; idx != ila_ptr_->input_num(); ++idx)
    insertInput(ila_ptr_->input(idx));
  // States
  for (size_t idx = 0; idx != ila_ptr_->state_num(); ++idx)
    insertState(ila_ptr_->state(idx));

  // add valid signal
  auto valid_ptr = ila_ptr_->valid();
  if (!valid_ptr) {
    valid_ptr = asthub::BoolConst(true);
    ILA_WARN << "Valid condition for ILA: " << ila_ptr_->name().str()
             << " is unset";
  }
  ParseNonMemUpdateExpr(valid_ptr);
  vlg_name_t valid_sig_name = getVlgFromExpr(valid_ptr);
  if (validName == "")
    validName = "__ILA_" + sanitizeName(ila_ptr_->name().str()) + "_valid__";
  add_wire(validName, 1);
  add_output(validName, 1);
  add_assign_stmt(validName, valid_sig_name);

  grantAccName = {"__ILA_" + sanitizeName(ila_ptr_->name().str()) + "_grant__",
                  ila_ptr_->instr_num()};
  decodeAccName = {"__ILA_" + sanitizeName(ila_ptr_->name().str()) +
                       "_acc_decode__",
                   ila_ptr_->instr_num()};
  // add grants inputs
  add_wire(grantAccName.first, ila_ptr_->instr_num());
  add_input(grantAccName.first, ila_ptr_->instr_num());
  add_wire(decodeAccName.first, ila_ptr_->instr_num());
  add_output(decodeAccName.first, ila_ptr_->instr_num());

  // export the decode conditions
  // decode conditions
  for (size_t instIdx = 0; instIdx < ila_ptr_->instr_num(); instIdx++) {
    auto instr_ptr_ = ila_ptr_->instr(instIdx);
    auto decode_ptr = instr_ptr_->decode();
    if (!decode_ptr) { // make sure decode is not null
      decode_ptr = asthub::BoolConst(true);
      ILA_WARN << "Decode condition for instr: " << (instr_ptr_->name().str())
               << " is unset";
    }
    ParseNonMemUpdateExpr(decode_ptr);
    vlg_name_t decode_sig_name = getVlgFromExpr(decode_ptr);

    auto decodeName = "__ILA_" + sanitizeName(ila_ptr_->name().str()) +
                      "_decode_of_" + sanitizeName(instr_ptr_->name().str()) +
                      "__";
    decodeNames.push_back(decodeName);
    add_wire(decodeName, 1);
    add_output(decodeName, 1);
    add_assign_stmt(decodeName, decode_sig_name);
    add_assign_stmt(decodeAccName.first + "[" + toStr(instIdx) + "]",
                    decodeName);
    // grant name will be put together
  }

  // output state update functions
  for (size_t stateIdx = 0; stateIdx < ila_ptr_->state_num(); ++stateIdx) {
    auto state = ila_ptr_->state(stateIdx);
    if (state->is_mem()) {
      // put together an expression
      ExprPtr mem_update_expr = state;
      for (size_t instIdx = 0; instIdx < ila_ptr_->instr_num(); instIdx++) {
        auto update_expr = ila_ptr_->instr(instIdx)->update(
            state->name().str()); // explicitly use name to index
        if (!update_expr)
          continue; // will not generate state <= state; // no use
        auto decode_cond = ila_ptr_->instr(instIdx)->decode();
        mem_update_expr =
            asthub::Ite(decode_cond, update_expr, mem_update_expr);
      } // end for all instructions
      ParseMemUpdateNode(asthub::BoolConst(true), mem_update_expr,
                         state->name().str());
      ExportCondWrites(state, current_writes);
      // done export memory
    } else {
      std::string end_else_if; // ""
      for (size_t instIdx = 0; instIdx < ila_ptr_->instr_num(); instIdx++) {
        // for all instructions, find their update to the state
        auto update_expr = ila_ptr_->instr(instIdx)->update(
            state->name().str()); // explicitly use name to index
        if (!update_expr)
          continue; // will not generate state <= state; // no use

        ParseNonMemUpdateExpr(update_expr);
        vlg_name_t result = getVlgFromExpr(update_expr);

        auto decode_name = decodeNames[instIdx];
        auto grant_name = grantAccName.first + "[" + toStr(instIdx) + "]";

        add_always_stmt(end_else_if + "if ( " + decode_name + " && " +
                        grant_name + " ) begin");
        add_always_stmt("    " + sanitizeName(state) + " <= " + result + ";");

        end_else_if = "end else ";
      }
      if (end_else_if != "")
        add_always_stmt("end"); // the final end
    }                           // end of memvar/bool/bv
  }                             // for all states
  // we may need to collect the state update function : yes!

  // Func Defs
  ExportFuncDefs();
}


// get valid signal name in advace
std::string VerilogGenerator::GetValidSignalName(const InstrPtr& instr_ptr_) const {

  auto ila_ptr_ = instr_ptr_->host();
  return "__ILA_" + sanitizeName(ila_ptr_->name().str()) + "_valid__";
}

// get decode signal name in advace
std::string VerilogGenerator::GetDecodeSignalName(const InstrPtr& instr_ptr_) const {

  auto ila_ptr_ = instr_ptr_->host();
  return "__ILA_" + sanitizeName(ila_ptr_->name().str()) +
                    "_decode_of_" + sanitizeName(instr_ptr_->name().str()) +
                    "__";
}

// here we will add all updates, those not touched will be update to itself
// add inputs / states / functions
// do remember to export its parents' state (hierarchically collect its parents)
// try to convert inits, if not add to assumptions
// add updates
// add guard of VALID signal to "else if"
// make sure to generate decode/valid signal output
// internal counter
void VerilogGenerator::ExportTopLevelInstr(const InstrPtr& instr_ptr_) {
  ILA_NOT_NULL(instr_ptr_);
  ILA_WARN_IF(instr_ptr_->host()->parent())
      << "This ExportTopLevelInstr does not put flatten states and "
         "instructions in child-ILA, please be aware.";
  ILA_WARN_IF(instr_ptr_->host()->init_num() != 0)
      << "For exporting a single instruction, the initial conditions are not "
         "exported, please be aware.";
  auto ila_ptr_ = instr_ptr_->host();

  if (moduleName == "")
    moduleName = sanitizeName(ila_ptr_->name().str()) + "__DOT__" +
                 sanitizeName(instr_ptr_->name().str());

  // Inputs
  for (size_t idx = 0; idx != ila_ptr_->input_num(); ++idx)
    insertInput(ila_ptr_->input(idx));
  // States
  for (size_t idx = 0; idx != ila_ptr_->state_num(); ++idx)
    insertState(ila_ptr_->state(idx));
  // clk, rst -- done in the beginning

  // add valid signal
  auto valid_ptr = ila_ptr_->valid();
  if (!valid_ptr) {
    valid_ptr = asthub::BoolConst(true);
    ILA_WARN << "Valid condition for ILA: " << ila_ptr_->name().str()
             << " is unset";
  }
  ParseNonMemUpdateExpr(valid_ptr);
  vlg_name_t valid_sig_name = getVlgFromExpr(valid_ptr);
  if (validName == "")
    validName = GetValidSignalName(instr_ptr_);
  add_wire(validName, 1);
  add_output(validName, 1);
  add_assign_stmt(validName, valid_sig_name);
  // decode conditions
  auto decode_ptr = instr_ptr_->decode();
  if (!decode_ptr) {
    decode_ptr = asthub::BoolConst(true);
    ILA_WARN << "Decode condition for instr: " << (instr_ptr_->name().str())
             << " is unset";
  }
  ParseNonMemUpdateExpr(decode_ptr);
  vlg_name_t decode_sig_name = getVlgFromExpr(decode_ptr);
  auto decodeName = GetDecodeSignalName(instr_ptr_);
  decodeNames.push_back(decodeName);
  add_wire(decodeName, 1);
  add_output(decodeName, 1);
  add_assign_stmt(decodeName, decode_sig_name);

  addInternalCounter(decodeName); // maybe no need (width = 8)

  // add updates
  for (size_t idx = 0; idx != ila_ptr_->state_num(); ++idx) {
    auto var = ila_ptr_->state(idx);
    auto update = instr_ptr_->update(var);
    if (!update)
      update = var; // if not updated, make it to self
    if (var->is_mem()) {
      ParseMemUpdateNode(decode_ptr, update, var->name().str());
      ExportCondWrites(var, current_writes);
    } else { // bv/bool
      ParseNonMemUpdateExpr(update);
      vlg_name_t result = getVlgFromExpr(update);
      add_ite_stmt(decodeName, sanitizeName(var) + " <= " + result, "");
    } // else

    ExprPtr c, v;
    if (cfg_.collect_ite_unknown_update && getIteUnknownCondVal(update, c, v)) {
      auto original_cond_sig = getVlgFromExpr(c);
      auto sig_name = "__ite_ukn_cond_" + original_cond_sig;
      auto reg_name = "__ite_ukn_cond_reg_" + original_cond_sig;
      state_update_ite_unknown.insert(
          std::make_pair(var->name().str(), state_update_unknown(sig_name)));
      add_output(sig_name, 1);
      add_wire(sig_name, 1);
      add_assign_stmt(sig_name, reg_name);
      add_ite_stmt(decodeName, reg_name + " <= " + original_cond_sig, "");
    }

  } // for (size_t idx = 0;  ...

  // Func Defs
  ExportFuncDefs();

} // VerilogGenerator::ExportTopLevelInstr

// parse a dummy ILA where we have
// I, and all child (as insts)
// multi-inst case, which to trigger? and their priority?
//# error the above question is unsolved

// this function could be used to export Instr w. (some/all) their childs, but
// there should be an external step that assemble these part together as Verilog
// Generator, it does not do this internally
// void VerilogGenerator::ExportIla( const InstrPtr & instr_ptr_ )
//{
// add inputs / states / functions
// do remember to export its parents' state (hierarchically collect its parents)

// try to convert inits, if not add to assumptions

// add updates

// add guard of valid signal to "else if"

// make sure to generate decode/valid signal output
//}

}; // namespace ilang
