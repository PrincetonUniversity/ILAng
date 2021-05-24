/// \file Header for generating decode for each instruction
// --- Hongce Zhang (hongcez@princeton.edu)

#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/mcm/ast_helper.h>
#include <ilang/aqed-out/aqed_vlog_out.h>

#include <algorithm>

namespace ilang{

#define ILA_VAR_PREFIX "__ILA_VAR_"
#define DECODE_NAME(ila_ptr_, instr_ptr_)  \
                      ("__ILA_" + sanitizeName(ila_ptr_->name().str()) + \
                      "_decode_of_" + sanitizeName(instr_ptr_->name().str()) + \
                      "__")

VerilogDecodeForAQedGenerator::VerilogDecodeForAQedGenerator(const VlgGenConfig& config,
                                   const std::string& modName,
                                   const std::string& clk,
                                   const std::string& rst)
    : VerilogGenerator(config, modName, clk, rst) {}



/// Handle function application , Caller: translateBoolOp, translateBvOp
VerilogDecodeForAQedGenerator::vlg_name_t 
VerilogDecodeForAQedGenerator::translateApplyFunc(
  std::shared_ptr<ExprOpAppFunc> func_app_ptr_) {
    ILA_ASSERT(false) << "Function application not supported.";
}


void VerilogDecodeForAQedGenerator::GenSequenceAssumtionsAny() {
  // TODO: 
  add_stmt("// START OF ASSUMPTIONS : SequenceAssumtionsAny //");
  add_stmt("any_valid_instr : assume property ( !__ISSUE__ || ("+ Join(all_decode_signals, "||")+") );");
}

void VerilogDecodeForAQedGenerator::GenSequenceOneAtATime() {
  // TODO: 
  add_stmt("// START OF ASSUMPTIONS : GenSequenceOneAtATime //");
  for (auto i = all_decode_signals.begin(); i != all_decode_signals.end() ; ++ i) {
    for (auto j = i+1; j != all_decode_signals.end(); ++j) {
      add_stmt("assume property ( !__ISSUE__ || (! ("+ *i +"&&"+ *j +") ) );");
    }
  }
}

#if 0 // not implemented
void VerilogDecodeForAQedGenerator::GenValidSequenceAssumption(const InstrLvlAbsCnstPtr& ila_ptr_) {
  ILA_NOT_NULL(ila_ptr_);
  // check if there is such need for sequence
  bool no_sequence = true;
  for (size_t instIdx = 0; instIdx < ila_ptr_->instr_num(); instIdx++)  {
      auto instr_ptr_ = ila_ptr_->instr(instIdx);
      auto node_ptr = ila_ptr_->trans(instr_ptr_);
      if (node_ptr != nullptr) {
        no_sequence = false;
        break;
      }
  }
  if (no_sequence)
    return; // no need for the following sequence generation

  // create registers for each decode
  // we don't grow the bound but just use more states
  // in the future
  std::vector<std::string> delayed_decode_neg;
  for (auto && decode_sig : all_decode_signals) {
    auto reg_name = decode_sig + "_D_"; // + std::to_string(bidx+1);
    delayed_decode_neg.push_back("!" + reg_name);
    add_reg(reg_name, 1);
    // add_output(reg_name, 1);
    add_init_stmt(reg_name + " <= 1'b0; ");
    add_ite_stmt("__ISSUE__" , reg_name + " <= " + decode_sig + " ;", "" );
  } // for each decode signal

  // now add assumptions
  // for all nodes find its source and the edges
  // assume if we see it now, it must have been like its src
  // and satisfiy its trans condition (currently only true)
  // otherwise, you will need to take record of the conditions.
  // which will record ila's state and map it to verilog's
  // currently we don't handle that
  
  add_stmt("// START OF ASSUMPTIONS : Valid Sequences //");

  auto null_condition = "(" + Join(delayed_decode_neg, "&&") + ")";
  for (size_t instIdx = 0; instIdx < ila_ptr_->instr_num(); instIdx++)  {
      auto instr_ptr_ = ila_ptr_->instr(instIdx);
      auto node_ptr = ila_ptr_->trans(instr_ptr_);
      if (node_ptr == nullptr)
        continue;
      auto prev_num = node_ptr->prev_num();
      auto decode_name = DECODE_NAME(ila_ptr_, instr_ptr_);
      std::vector<std::string> prev_decode_vec;
      for (size_t prev_i = 0; prev_i < prev_num ; ++ prev_i) {
        auto prev_node = node_ptr->prev(prev_i);
        auto prev_instr_ = prev_node->instr();
        if (prev_instr_ == nullptr) {
          prev_decode_vec.push_back(null_condition);
          continue;
        }
        auto prev_decode_name = DECODE_NAME(ila_ptr_, prev_instr_) + "_D_";
        prev_decode_vec.push_back(prev_decode_name);
      }
      // decode_name |-> ( prev_decode_1 ||  prev_decode_2 || ... )
      auto seq = "(~ " + decode_name + "|| (" + Join(prev_decode_vec, "||") + ") )";
      add_stmt("assume property ( !__ISSUE__ || " + seq + " );");
  }
} // GenValidSequenceAssumption
#endif

void VerilogDecodeForAQedGenerator::ExportDecode(
    const InstrLvlAbsCnstPtr& ila_ptr_, std::set<ExprPtr> & used_vars_in_decodes) 
{
  ILA_NOT_NULL(ila_ptr_);

  ILA_WARN_IF(ila_ptr_->init_num() != 0)
      << "Currently, it does not translate the initial conditions";

  if (moduleName == "")
    moduleName = sanitizeName(ila_ptr_->name().str());

  add_input("__ISSUE__", 1);
  add_wire ("__ISSUE__", 1);

  { // add used vars in the set as module inputs
    // VarUseFinder<ExprPtr>::VarUseList used_vars_in_decodes;
    VarUseFinder<ExprPtr> used_vars_finder(
        [](const ExprPtr& e) {return e;}
    );

    for (size_t instIdx = 0; instIdx < ila_ptr_->instr_num(); instIdx++)  {
        auto instr_ptr_ = ila_ptr_->instr(instIdx);
        auto decode_ptr = instr_ptr_->decode();
        used_vars_finder.Traverse(decode_ptr, used_vars_in_decodes);
    }
    
    { // check if it uses anything that is not input
      
    }

    { // check if any input has not been used

    }

    for (auto && v : used_vars_in_decodes) {
      ILA_CHECK(v->is_var());

      if (v->is_mem()) {
        ILA_ERROR << "mem as input : not implemented";
      } else {
        add_output(ILA_VAR_PREFIX + sanitizeName(v), get_width(v));
        add_wire(ILA_VAR_PREFIX + sanitizeName(v), get_width(v), true);
      }
    }
  } // add used vars in the set

  // -- get the var used in each decode of instructions

  std::vector<std::tuple<std::string,std::string>> decode_signals;
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

    auto decodeName = DECODE_NAME(ila_ptr_, instr_ptr_);
    decodeNames.push_back(decodeName);
    add_wire(decodeName, 1);
    add_output(decodeName, 1);
    decode_signals.push_back({decodeName, decode_sig_name});
    all_decode_signals.push_back(decodeName);
    // recode the list of all the decode --- to be used in the valid sequence
    // the naive sequence is just allowing all vars
    // grant name will be put together
  }
  add_stmt("// START OF DECODES //");
  for (auto && decode : decode_signals)
    add_assign_stmt(std::get<0>(decode), std::get<1>(decode));

} // insertInput

// used in general for an expression (not the update of a memvar)
void VerilogDecodeForAQedGenerator::ParseNonMemUpdateExpr(
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
      nmap[e] = ILA_VAR_PREFIX + sanitizeName(e); // just use its name
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
      nmap[e] = ILA_VAR_PREFIX + sanitizeName(e); // just use its name
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
        result_var = "bv_" + std::to_string(width) + "_" +
                     std::to_string(IlaBvValUnsignedType(value)) + "_" + new_id(e);
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
      nmap[e] = ILA_VAR_PREFIX + sanitizeName(e); // should not be used
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
} // ParseNonMemUpdateExpr


// will be used by ParseNonMemUpdateExpr, will not be directly called by
// ParseMemUpdateNode the later will call the former first
VerilogDecodeForAQedGenerator::vlg_name_t
VerilogDecodeForAQedGenerator::translateBoolOp(const std::shared_ptr<ExprOp>& e) {

  vlg_stmt_t result_stmt;
  std::string op_name = e->op_name();
  size_t arg_num = e->arg_num();

  if (op_name == "APP") { // Function application
    // deal with the case with a function
    ILA_ASSERT(false) << "APP not supported";
    result_stmt = "**ERROR**";
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
VerilogDecodeForAQedGenerator::vlg_name_t
VerilogDecodeForAQedGenerator::translateBvOp(const std::shared_ptr<ExprOp>& e) {

  vlg_stmt_t result_stmt;
  std::string op_name = e->op_name();
  size_t arg_num = e->arg_num();

  if (op_name == "APP") { // Function application
    // deal with the case with a function
    ILA_ASSERT(false) << "APP not supported";
    result_stmt = "**ERROR**";
  } else if (arg_num == 1) {
    vlg_name_t arg0 = getArg(e, 0);
    if (op_name == "NEGATE") // negate : 2's complement
      result_stmt = vlg_stmt_t("( ~ ( ") + arg0 + " ) + 1'b1 )";
    else if (op_name == "COMPLEMENT") // 1's complement
      result_stmt = vlg_stmt_t("~ ( ") + arg0 + " )";
    else if (op_name == "EXTRACT") {
      int hi = e->param(0);
      int lo = e->param(1);
      result_stmt = arg0 + "[" + std::to_string(hi) + ":" + std::to_string(lo) + "]";
    } else if (op_name == "ZERO_EXTEND") {
      int outw = e->param(0);
      int inw = get_width(e->arg(0));
      if (outw == inw)
        result_stmt = arg0;
      else
        result_stmt =
            vlg_stmt_t(" {") + std::to_string(outw - inw) + "'d0 , " + arg0 + "} ";
    } else if (op_name == "SIGN_EXTEND") {
      int outw = e->param(0);
      int inw = get_width(e->arg(0));
      if (outw == inw)
        result_stmt = arg0;
      else if (e->arg(0)->is_const() && inw == 1) {
        result_stmt = vlg_stmt_t(" { {") + std::to_string(outw - inw) + "{" + arg0 +
                      "} }, " + arg0 + "} ";
      } else
        result_stmt = vlg_stmt_t(" { {") + std::to_string(outw - inw) + "{" + arg0 +
                      "[" + std::to_string(inw - 1) + "]} }, " + arg0 + "} ";
    } else if (op_name == "RIGHT_ROTATE") {
      // {x[i-1:0], x[w-1:i]}
      int rotw = e->param(0);
      int inw = get_width(e->arg(0));
      result_stmt = vlg_stmt_t(" { ( ") + arg0 + "[" + std::to_string(rotw - 1) +
                    ":0] ), ( " + arg0 + "[" + std::to_string(inw - 1) + ":" +
                    std::to_string(rotw) + "] ) } ";
    } else if (op_name == "LEFT_ROTATE") {
      // {x[w-1-i:0], x[w-1:w-i]}
      int rotw = e->param(0);
      int inw = get_width(e->arg(0));
      result_stmt = vlg_stmt_t(" { ( ") + arg0 + "[" + std::to_string(inw - 1 - rotw) +
                    ":0] ), ( " + arg0 + "[" + std::to_string(inw - 1) + ":" +
                    std::to_string(inw - rotw) + "] ) } ";
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
      ILA_ASSERT(e->arg(0)->is_var()) << "Implementation bug: unable to handle "
                                          "LOAD(STORE/ITE/MEMCONST) pattern";
      auto mem_var_name = sanitizeName(e->arg(0));
      ILA_ERROR << "LOAD not supported";
      result_stmt = "**LOAD_from_|" + mem_var_name + "|**";
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



}; // namespace ilang