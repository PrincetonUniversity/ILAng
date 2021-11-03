/// \file Source for Verilog Target Generation Utilities
/// Store some functions that the vtarget_gen_impl.cc
/// needes, but not that important so does not need to
/// go in the same file and make it that long.
// --- Hongce Zhang

#include <ilang/vtarget-out/vtarget_gen_impl.h>

#include <cmath>

#include <ilang/rtl_verify.h>
#include <ilang/ila/ast_hub.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

#include <ilang/rfmap-in/rfexpr_shortcut.h>

namespace ilang {

#define VLG_TRUE "`true"
#define VLG_FALSE "`false"

#define IntToStr(x) (std::to_string(x))

std::string VlgSglTgtGen::new_mapping_id() {
  return std::string("__m") + IntToStr(mapping_counter++) + "__";
}
std::string VlgSglTgtGen::new_property_id() {
  return std::string("__p") + IntToStr(mapping_counter++) + "__";
}

const ExprPtr VlgSglTgtGen::IlaGetState(const std::string& sname) const {
  auto ptr = _host->state(sname);
  ILA_ERROR_IF(ptr == nullptr)
      << "Cannot find state:" << sname << " in ila:" << _host->name().str();
  return ptr;
}
const ExprPtr VlgSglTgtGen::IlaGetInput(const std::string& sname) const {
  auto ptr = _host->input(sname);
  ILA_ERROR_IF(ptr == nullptr)
      << "Cannot find input:" << sname << " in ila:" << _host->name().str();
  return ptr;
}

std::pair<unsigned, unsigned>
VlgSglTgtGen::GetMemInfo(const std::string& ila_mem_name) const {
  auto ptr_ = _host->state(ila_mem_name);
  if (ptr_ == nullptr)
    return std::pair<unsigned, unsigned>({0, 0});
  if (!ptr_->sort()->is_mem())
    return std::pair<unsigned, unsigned>({0, 0});
  return std::pair<unsigned, unsigned>(
      {ptr_->sort()->addr_width(), ptr_->sort()->data_width()});
}

bool VlgSglTgtGen::TryFindIlaState(const std::string& sname) {
  if (_host->state(sname))
    return true;
  // if it uses the reference it self
  auto hierName = Split(sname, ".");
  if (hierName.size() == 2) { // maybe it contains an unnecessary head
    if ((hierName[0] == _ila_mod_inst_name || hierName[0] == "ILA") &&
        _host->state(hierName[1]))
      return true;
    return false;
  }
  return false;
}

bool VlgSglTgtGen::TryFindIlaInput(const std::string& sname) {
  if (_host->input(sname))
    return true;
  // if it uses the reference it self
  auto hierName = Split(sname, ".");
  if (hierName.size() == 2) { // maybe it contains an unnecessary head
    if ((hierName[0] == _ila_mod_inst_name || hierName[0] == "ILA") &&
        _host->input(hierName[1]))
      return true;
    return false;
  }
  return false;
}

ExprPtr VlgSglTgtGen::TryFindIlaVarName(const std::string& sname) {
  if (_host->input(sname))
    return _host->input(sname);
  if (_host->state(sname))
    return _host->state(sname);
  auto hierName = Split(sname, ".");
  if (hierName.size() == 2) { // maybe it contains an unnecessary head
    if ((hierName[0] == _ila_mod_inst_name || hierName[0] == "ILA") &&
        _host->input(hierName[1]))
      return _host->input(hierName[1]);
    if ((hierName[0] == _ila_mod_inst_name || hierName[0] == "ILA") &&
        _host->state(hierName[1]))
      return _host->state(hierName[1]);
  }
  return NULL;
}

bool VlgSglTgtGen::TryFindVlgState(const std::string& sname) {

  if (vlg_info_ptr->check_hierarchical_name_type(sname) !=
      VerilogInfo::hierarchical_name_type::NONE)
    return true;
  if (vlg_info_ptr->check_hierarchical_name_type(_vlg_mod_inst_name + "." +
                                                 sname) !=
      VerilogInfo::hierarchical_name_type::NONE)
    return true;
  return false;
}

// static function
unsigned VlgSglTgtGen::TypeMatched(const ExprPtr& ila_var,
                                   const SignalInfoBase& vlg_var) {

  if (ila_var == nullptr) {
    ILA_ERROR << "Not able to check type for unknown ila signal";
    return 0;
  }

  auto ila_sort = ila_var->sort();
  if (vlg_var.get_width() == 0) {
    ILA_ERROR << "Cannot determine type-match for vlg signal"
              << vlg_var.get_hierarchical_name();
    return 0;
  }
  if (ila_sort->is_bool()) {
    if (vlg_var.get_width() == 1)
      return 1;
    ILA_ERROR << "ila w:1, vlg w:" << vlg_var.get_width();
    /*else*/ return 0; /*mismatch*/
  }                    /*else*/
  if (ila_sort->is_bv()) {
    if ((unsigned)ila_sort->bit_width() == vlg_var.get_width())
      return vlg_var.get_width();
    ILA_ERROR << "ila w:" << ila_sort->bit_width()
              << ", vlg w:" << vlg_var.get_width();
    /*else*/ return 0; /*mismatch*/
  }                    /*else*/
  if (ila_sort->is_mem()) {
    if ((unsigned)ila_sort->data_width() == vlg_var.get_width())
      return vlg_var.get_width();
    ILA_ERROR << "ila w:" << ila_sort->data_width()
              << ", vlg w:" << vlg_var.get_width();
    /*else*/ return 0; /*mismatch*/
  }
  ILA_CHECK(false) << "Implementation bug: unknown sort";
  return 0;
}
// static function
unsigned VlgSglTgtGen::get_width(const ExprPtr& n) {
  ILA_WARN_IF(n->sort()->is_mem())
      << "Using data width for " << n->name().str();
  return VerilogGeneratorBase::get_width(n);
}

rfmap::RfVarTypeOrig
VlgSglTgtGen::VarTypeCheckForRfExprParsing(const std::string& vname) {

  if (StrStartsWith(vname, "ILA.")) {
    rfmap::RfVarTypeOrig ret;
    if (TryFindIlaInput(vname)) {
      const ExprPtr ila_input_ptr = IlaGetInput(vname.substr(4));
      ret.var_ref_type = rfmap::RfVarTypeOrig::VARTYPE::ILAI;

      ret.type = rfmap::RfMapVarType(
          ila_input_ptr->is_bool() ? 1 : ila_input_ptr->sort()->bit_width());
      return ret;
    } else if (TryFindIlaState(vname)) {
      const ExprPtr ila_sv_ptr = IlaGetState(vname.substr(4));
      ret.var_ref_type = rfmap::RfVarTypeOrig::VARTYPE::ILAS;
      if (ila_sv_ptr->is_bool())
        ret.type = rfmap::RfMapVarType(1);
      else if (ila_sv_ptr->is_bv())
        ret.type = rfmap::RfMapVarType(ila_sv_ptr->sort()->bit_width());
      else {
        ILA_ASSERT(ila_sv_ptr->is_mem());
        ret.type = rfmap::RfMapVarType(ila_sv_ptr->sort()->addr_width(),
                                       ila_sv_ptr->sort()->data_width());
      }
      return ret;
    }
    ILA_ERROR << "Cannot find ila var: " << vname;
    return ret;
  } // else if
  if (StrStartsWith(vname, "RTL.")) {
    ILA_ERROR_IF(!TryFindVlgState(vname)) << "Cannot find rtl var: " << vname;
    auto sig_info = vlg_info_ptr->get_signal(vname,
      refinement_map.width_info,
      refinement_map.range_info);
    auto aw_range = sig_info.get_addr_range_size();
    auto dw = sig_info.get_width();

    rfmap::RfVarTypeOrig ret;
    ret.var_ref_type = rfmap::RfVarTypeOrig::VARTYPE::RTLV;
    if (aw_range == 0) // not an array
      ret.type = rfmap::RfMapVarType(dw);
    else {
      unsigned aw = (unsigned)(std::ceil(std::log2(aw_range)));
      // [15:0] -> aw_range == 16 -> 4 -> ceil (4) == 4
      ret.type = rfmap::RfMapVarType(aw, dw);
    }
    return ret;
  }

  // if(!StrStartsWith(vname,"ILA.") && !StrStartsWith(vname,"RTL."))
  return rfmap::RfVarTypeOrig(); // unknown
} // VarTypeCheckForRfExprParsing

rfmap::VarReplacement
VlgSglTgtGen::CreateVarReplacement(const rfmap::RfVar& var,
                                   bool replace_internal_names) {
  const auto n = var->get_name();

  rfmap::RfVarTypeOrig tp;
  { // retrieve its old type
    auto anno = var->get_annotation<rfmap::TypeAnnotation>();
    if (anno)
      tp = *anno;
  }

  auto pos_def_var = refinement_map.all_var_def_types.find(n.first);

  if (n.second) { // if it is special name
    if (pos_def_var != refinement_map.all_var_def_types.end()) {
      tp.var_ref_type = rfmap::RfVarTypeOrig::VARTYPE::DEFINE_VAR;
      tp.type = rfmap::RfMapVarType(pos_def_var->second.width);
    } else {
      auto rtl_ila_tp = VarTypeCheckForRfExprParsing(n.first);
      tp = rtl_ila_tp;
    }
  } else { // if it is not special name
    auto rtl_ila_tp = VarTypeCheckForRfExprParsing(n.first);
    if (!rtl_ila_tp.type.is_unknown())
      tp = rtl_ila_tp;
    else if (pos_def_var != refinement_map.all_var_def_types.end()) {
      tp.var_ref_type = rfmap::RfVarTypeOrig::VARTYPE::DEFINE_VAR;
      tp.type = rfmap::RfMapVarType(pos_def_var->second.width);
    }
  }
  ILA_WARN_IF(tp.type.is_unknown()) << "type of var: " << (n.second ? "#" : "")
                                    << n.first << " is still unknown.";

  if (tp.var_ref_type == rfmap::RfVarTypeOrig::VARTYPE::RTLV) {

    bool is_array = tp.type.is_array(); // you can never connect an array out
    if (!replace_internal_names || is_array) {
      auto ret_copy = std::make_shared<verilog_expr::VExprAstVar>(*var);
      ret_copy->set_annotation(std::make_shared<rfmap::TypeAnnotation>(tp));
      return rfmap::VarReplacement(var, ret_copy);
    }

    auto new_name = ReplaceAll(n.first, ".", "__DOT__");
    auto new_node = verilog_expr::VExprAst::MakeSpecialName(new_name);
    new_node->set_annotation(std::make_shared<rfmap::TypeAnnotation>(tp));
    return rfmap::VarReplacement(var, new_node);

  } else if (tp.var_ref_type == rfmap::RfVarTypeOrig::VARTYPE::ILAI) {
    const auto& ila_sn = n.first;
    auto dotpos = ila_sn.find('.');
    ILA_ASSERT(ila_sn.substr(0, dotpos + 1) == "ILA.");

    bool is_array = tp.type.is_array(); // you can never connect an array out
    ILA_CHECK(!is_array)
        << "Implementation bug: currently does not support array as input";

    auto new_name = "__ILA_I_" + ila_sn.substr(dotpos + 1);
    auto new_node = verilog_expr::VExprAst::MakeSpecialName(new_name);
    new_node->set_annotation(std::make_shared<rfmap::TypeAnnotation>(tp));
    return rfmap::VarReplacement(var, new_node);
  } else if (tp.var_ref_type == rfmap::RfVarTypeOrig::VARTYPE::ILAS) {
    const auto& ila_sn = n.first;
    auto dotpos = ila_sn.find('.');
    ILA_ASSERT(ila_sn.substr(0, dotpos + 1) == "ILA.");

    bool is_array = tp.type.is_array(); // you can never connect an array out
    // so there should not be such things like: __ILA_SO_array
    if (is_array) { // basically no replacement
      auto ret_copy = std::make_shared<verilog_expr::VExprAstVar>(*var);
      ret_copy->set_annotation(std::make_shared<rfmap::TypeAnnotation>(tp));
      return rfmap::VarReplacement(var, ret_copy);
    }

    auto new_name = "__ILA_SO_" + ila_sn.substr(dotpos + 1);
    auto new_node = verilog_expr::VExprAst::MakeSpecialName(new_name);
    new_node->set_annotation(std::make_shared<rfmap::TypeAnnotation>(tp));
    return rfmap::VarReplacement(var, new_node);
  } else if (tp.var_ref_type == rfmap::RfVarTypeOrig::VARTYPE::INTERNAL ||
             tp.var_ref_type == rfmap::RfVarTypeOrig::VARTYPE::DEFINE_VAR) {
    ILA_ERROR_IF(StrStartsWith(n.first, "$"))
        << "Creating non replace-able var " << n.first;
    if (var->get_annotation<rfmap::TypeAnnotation>() == nullptr) {
      var->set_annotation(std::make_shared<rfmap::TypeAnnotation>(tp));
    }
    return rfmap::VarReplacement(var, var);
  }

  ILA_ERROR << "Unknown how to replace var: " << n.first << " will keep it";
  auto ret_copy = std::make_shared<verilog_expr::VExprAstVar>(*var);
  ret_copy->set_annotation(std::make_shared<rfmap::TypeAnnotation>(tp));
  return rfmap::VarReplacement(var, ret_copy);
}

rfmap::RfExpr VlgSglTgtGen::ReplExpr(const rfmap::RfExpr& in) {
  bool replace_dot = _backend != ModelCheckerSelection::JASPERGOLD;

  std::unordered_map<std::string, rfmap::RfVar> vars;
  refinement_map.GetVars(in, vars);
  for (const auto& v : vars) {
    rfmap::VarReplacement* repl = refinement_map.CheckReplacement(v.first);
    if (repl == NULL) {
      rfmap::VarReplacement new_repl =
          CreateVarReplacement(v.second, replace_dot);

      ILA_DLOG("gen_util.create_var_replacement")
          << new_repl.origvar->to_verilog() << " --> "
          << new_repl.newvar->to_verilog();

      refinement_map.RegisterInternalVariableWithMapping(v.first, new_repl);
      repl = refinement_map.CheckReplacement(v.first);
    }
    ILA_NOT_NULL(repl);
    ILA_DLOG("gen_util.use_var_replacement")
        << repl->origvar->to_verilog() << " --> " << repl->newvar->to_verilog();
  }

  auto new_node = refinement_map.ReplacingRtlIlaVar(in);
  // AnnotateType requires all
  refinement_map.AnnotateType(new_node);
  return new_node;
}

rfmap::RfExpr VlgSglTgtGen::TranslateMap(const rfmap::RfExpr& in,
                                         const std::string& ila_vn) {
  if (refinement_map.IsLastLevelBooleanOp(in))
    return in;
  auto vnode = rfmap_var("ILA." + ila_vn);
  auto eq_node = rfmap_eq(vnode, in);
  return eq_node;
}

rfmap::RfExpr VlgSglTgtGen::condition_map_to_rfexpr(
    const std::vector<std::pair<rfmap::RfExpr, rfmap::RfExpr>>& cond_map,
    const std::string& ila_state_name) {
  std::vector<rfmap::RfExpr> all_mappings;
  rfmap::RfExpr prev_neg; // make sure it is a priority condition lists
  for (const auto& cond_map_pair : cond_map) {
    rfmap::RfExpr cond = cond_map_pair.first;
    if (prev_neg != nullptr)
      cond = rfmap_and(prev_neg, cond);
    rfmap::RfExpr single_map =
        TranslateMap(cond_map_pair.second, ila_state_name);
    all_mappings.push_back(rfmap_imply(cond, single_map));
    if (prev_neg == nullptr)
      prev_neg = rfmap_not(cond);
    else
      prev_neg = rfmap_and(prev_neg, rfmap_not(cond));
  } // end of for each cond_map pair
  ILA_CHECK(!all_mappings.empty());
  return rfmap_and(all_mappings);
} // end of condition_map_to_str

rfmap::RfExpr VlgSglTgtGen::condition_map_bv_to_rfexpr(
    const std::vector<std::pair<rfmap::RfExpr, rfmap::RfExpr>>& cond_map) {
  rfmap::RfExpr ret;
  for (auto pos = cond_map.rbegin(); pos != cond_map.rend(); ++pos) {
    if (ret == nullptr)
      ret = pos->second;
    else
      ret = rfmap_ite(pos->first, pos->second, ret);
  }
  return ret;
} // end of condition_map_to_str

rfmap::RfExpr
VlgSglTgtGen::singlemap_bv_to_rfexpr(const rfmap::SingleVarMap& single_map) {
  if (single_map.single_map != nullptr) {
    return single_map.single_map;
  } else {
    return condition_map_bv_to_rfexpr(single_map.cond_map);
  } // end map type
}

rfmap::RfExpr
VlgSglTgtGen::singlemap_to_rfexpr(const rfmap::SingleVarMap& single_map,
                                  const std::string& ila_state_name) {
  if (single_map.single_map != nullptr) {
    return (TranslateMap(single_map.single_map, ila_state_name));
  } else {
    auto map_str = condition_map_to_rfexpr(single_map.cond_map, ila_state_name);
    return (map_str);
  } // end map type
} // non_mem_map_to_str

// compared to Gen_varmap_assumpt_assert
// problem_name, true_for_assumpt_false_for_assert
// prefix, suffix are all fixed
void VlgSglTgtGen::Gen_input_map_assumpt(const std::string& ila_input_name,
                                         const rfmap::IlaVarMapping& imap,
                                         const std::string& problem_name) {

  bool is_mem = _host->input(ila_input_name)->is_mem();
  ILA_ERROR_IF(is_mem) << "Mem as input is not supported yet";

  ILA_ERROR_IF(imap.type == rfmap::IlaVarMapping::StateVarMapType::EXTERNMEM)
      << "ila sv " << ila_input_name << " cannot be mapped as external mem!";
  // NOTE:   non_mem_map_to_str will use translate map
  //         but it should be able to distinguish input from state var
  auto map_rfexpr = singlemap_to_rfexpr(imap.single_map, ila_input_name);
  add_an_assumption(rfmap_imply(rfmap_var("decode"), map_rfexpr), problem_name);
}

void VlgSglTgtGen::Gen_varmap_assumpt_assert(
    const std::string& ila_state_name, const rfmap::IlaVarMapping& vmap,
    const std::string& problem_name, bool true_for_assumpt_false_for_assert) {
  // NOTE: prefix has ( ~ __START__ || ...
  //       and suffix has .. )

#define ADD_CONSTR(p1)                                                         \
  do {                                                                         \
    if (true_for_assumpt_false_for_assert)                                     \
      add_an_assumption(rfmap_imply(rfmap_var("decode"), (p1)), problem_name); \
    else                                                                       \
      add_an_assertion(rfmap_imply(rfmap_var("commit"), (p1)), problem_name);  \
  } while (0)

  bool is_mem = _host->state(ila_state_name)->is_mem();
  if (vmap.type != rfmap::IlaVarMapping::StateVarMapType::EXTERNMEM) {
    auto map_str = singlemap_to_rfexpr(vmap.single_map, ila_state_name);
    ADD_CONSTR(map_str);
  } else {
    // if(vmap.type == rfmap::IlaVarMapping::StateVarMapType::EXTERNMEM) {
    // TODO: (note: multiple ports!)
    //  assume : START |->
    //         ( ila.ren && rtl.renexpr && (ila.raddr == rtl.raddrexpr) |->
    //             (ila.rdata === rtl.rdataexpr) )

    ILA_ERROR_IF(!is_mem) << "ila sv " << ila_state_name << " is not memory!";

    if (true_for_assumpt_false_for_assert) {
      // mem read assumption
      if (vlg_ila.ila_rports.find(ila_state_name) != vlg_ila.ila_rports.end()) {
        const auto& read_ports = vlg_ila.ila_rports.at(ila_state_name);
        unsigned rfmap_node_idx = 0;

        for (const auto& rport : read_ports) {
          size_t no = rport.first;

          auto ila_raddr = rfmap_var("__IMEM_" + ila_state_name + "_" +
                                     IntToStr(no) + "_raddr");
          auto ila_rdata = rfmap_var("__IMEM_" + ila_state_name + "_" +
                                     IntToStr(no) + "_rdata");

          while (!(vmap.externmem_map.at(rfmap_node_idx).rport_mapped) &&
                 rfmap_node_idx < vmap.externmem_map.size())
            ++rfmap_node_idx;

          ILA_ERROR_IF(rfmap_node_idx >= vmap.externmem_map.size())
              << "#ila.read-port=" << read_ports.size()
              << " does not match #rfmap.read-port"
              << ", and this is a mismatch for sname:" << ila_state_name;

          const auto& rfmap_rport = vmap.externmem_map.at(rfmap_node_idx);

          // expect bit-vector rather than booleans
          auto rtl_ren = singlemap_bv_to_rfexpr(rfmap_rport.ren_map);
          auto rtl_raddr = singlemap_bv_to_rfexpr(rfmap_rport.raddr_map);
          auto rtl_rdata = singlemap_bv_to_rfexpr(rfmap_rport.rdata_map);

          auto constr =
              rfmap_imply(rfmap_and({rtl_ren, rfmap_eq(ila_raddr, rtl_raddr)}),
                          rfmap_eq(ila_rdata, rtl_rdata));

          ADD_CONSTR(constr);

          ++rfmap_node_idx;

        } // for each read port
      }   // if there is such port
    } else {
      //  assert : IEND |->
      //         ( ila.wen_d1 == rtl.wenexpr && ( ila.wen |->
      //             (ila.wdata_d1 == rtl.wdataexpr) && (ila.waddr_d1 ==
      //             rtl.waddrexpr) ) )

      // mem write assertion
      // vlg_ila.ila_wports
      if (vlg_ila.ila_wports.find(ila_state_name) != vlg_ila.ila_wports.end()) {
        const auto& write_ports = vlg_ila.ila_wports.at(ila_state_name);
        unsigned rfmap_node_idx = 0;

        for (const auto& wport : write_ports) {
          // the reason for _d1: see ConstructWrapper_get_ila_module_inst
          // in single_target_connect.cc
          size_t no = wport.first;
          auto ila_wen = rfmap_var("__IMEM_" + ila_state_name + "_" +
                                   IntToStr(no) + "_wen" + "_d1");
          auto ila_waddr = rfmap_var("__IMEM_" + ila_state_name + "_" +
                                     IntToStr(no) + "_waddr" + "_d1");
          auto ila_wdata = rfmap_var("__IMEM_" + ila_state_name + "_" +
                                     IntToStr(no) + "_wdata" + "_d1");

          while (!(vmap.externmem_map.at(rfmap_node_idx).wport_mapped) &&
                 rfmap_node_idx < vmap.externmem_map.size())
            ++rfmap_node_idx;

          ILA_ERROR_IF(rfmap_node_idx >= vmap.externmem_map.size())
              << "#ila.write-port=" << write_ports.size()
              << " does not match #rfmap.write-port"
              << ", and this is a mismatch for sname:" << ila_state_name;

          const auto& rfmap_wport = vmap.externmem_map.at(rfmap_node_idx);

          auto rtl_wen = singlemap_bv_to_rfexpr(rfmap_wport.wen_map);
          auto rtl_waddr = singlemap_bv_to_rfexpr(rfmap_wport.waddr_map);
          auto rtl_wdata = singlemap_bv_to_rfexpr(rfmap_wport.wdata_map);

          auto constr = rfmap_and(
              rfmap_eq(ila_wen, rtl_wen),
              rfmap_imply(ila_wen, rfmap_and(rfmap_eq(ila_waddr, rtl_waddr),
                                             rfmap_eq(ila_wdata, rtl_wdata))));

          ADD_CONSTR(constr);

          ++rfmap_node_idx;
        } // for each write port
      }   // end of if wport found
    }     // end of if assume else assert
  }
#undef ADD_CONSTR
} // end of Gen_varmap_assumpt_assert

void VlgSglTgtGen::handle_start_condition(
    const std::vector<rfmap::RfExpr>& dc) {
  for (const auto& c : dc) {
    // cond = ReplaceAll(ReplaceAll(cond, "$decode", vlg_ila.decodeNames[0]),
    //                  "$valid", vlg_ila.validName);
    add_an_assumption(rfmap_imply(rfmap_var("__START__"), c),
                      "start_condition");
  }
} // handle_start_condition

/// register a reg in refinement_map.all_var_def_type
void VlgSglTgtGen::rfmap_add_internal_reg(const std::string& n,
                                          unsigned width) {
  rfmap::TypedVerilogRefinementMap::VarDef def;
  def.type = rfmap::TypedVerilogRefinementMap::VarDef::var_type::REG;
  def.width = width;
  refinement_map.all_var_def_types.emplace(n, def);
}

/// register a wire in refinement_map.all_var_def_type
void VlgSglTgtGen::rfmap_add_internal_wire(const std::string& n,
                                           unsigned width) {
  rfmap::TypedVerilogRefinementMap::VarDef def;
  def.type = rfmap::TypedVerilogRefinementMap::VarDef::var_type::WIRE;
  def.width = width;
  refinement_map.all_var_def_types.emplace(n, def);
}

/// register a replacement in refinement_map
/// this will affect ReplExpr's behavior
/// (Note 1: ReplExpr will also create replacement, but it will not use
/// this function. 2: will require that the new one has been registered
/// in refinement_map.all_var_def_type)
/// !!! should only be used to add
///   decode -> __START__
///   commit -> __IEND__
///   $decode -> vlg_ila.decode_signal
///   $valid -> vlg_ila.valid_signal
/// !!! whose var_def are include in refinement_map

void VlgSglTgtGen::rfmap_add_replacement(const std::string& old,
                                         const std::string& n) {
  auto def_pos = refinement_map.all_var_def_types.find(n);
  ILA_CHECK(def_pos != refinement_map.all_var_def_types.end());
  auto oldexpr = rfmap_var(old);
  auto newexpr = rfmap_var(n);
  auto tp = std::make_shared<rfmap::TypeAnnotation>();
  tp->type = rfmap::RfMapVarType(def_pos->second.width);
  tp->var_ref_type = rfmap::RfVarTypeOrig::VARTYPE::INTERNAL;
  newexpr->set_annotation(tp);
  refinement_map.RegisterInternalVariableWithMapping(
      old, rfmap::VarReplacement(oldexpr, newexpr));
} // rfmap_add_replacement

}; // namespace ilang
