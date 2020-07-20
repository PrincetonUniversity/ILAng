/// \file Source for Verilog Target Generation Utilities
/// Store some functions that the vtarget_gen_impl.cc
/// needes, but not that important so does not need to
/// go in the same file and make it that long.
// --- Hongce Zhang

#include <ilang/vtarget-out/vtarget_gen_impl.h>

#include <cmath>

#include <ilang/ila/ast_hub.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

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

#define SIN(sub, s) (s.find(sub) != std::string::npos)

/// signals generated in the wrapper,
/// it is normal that you cannot find
/// them in the verilog
std::set<std::string> wrapper_signals = {
    "__START__",    "__IEND__",       "__ISSUE__",
    "__STARTED__",  "__RESETED__",    "__ENDED__",
    "__ENDFLUSH__", "__FLUSHENDED__", "__CYCLE_CNT__"};

// for ila state: add __ILA_SO_
// for verilog signal: keep as it is should be fine
// btw, record all referred vlg name
std::string
VlgSglTgtGen::ModifyCondExprAndRecordVlgName(const VarExtractor::token& t) {
  // modify name and ...
  const auto& token_tp = t.first;
  const auto& sname = t.second;

  if (token_tp == VarExtractor::token_type::UNKN_S) {
    ILA_WARN_IF(!IN(sname, wrapper_signals) && !IN(sname, vlg_wrapper.wires))
        << "In refinement relations: unknown reference to name:" << sname
        << " keep unchanged.";
    return sname;
  } else if (token_tp == VarExtractor::token_type::KEEP)
    return sname; // NC
  else if (token_tp == VarExtractor::token_type::NUM) {
    /*
    if (_backend == backend_selector::COSA) {
      if (SIN("'", sname)) {
        auto l = Split(sname, "'");

        auto& num_l = l.back();
        auto num = num_l.substr(1); // [1:]
        int base = 16;
        if (num_l[0] == 'd')
          base = 10;
        else if (num_l[0] == 'h')
          base = 16;
        else if (num_l[0] == 'b')
          base = 2;
        else if (num_l[0] == 'o')
          base = 8;
        else
          ILA_ERROR << "unknown base in " << sname << ", assuming 16";

        unsigned n = StrToInt(num, base);
        unsigned int w;
        if (l.size() == 2) {
          w = StrToInt(l[0]);
        } else {
          w = ((unsigned int)std::floor(std::log2(n))) + 1;
          ILA_WARN << sname << " is considered to be of width " << w;
        }
        return IntToStr(n) + "_" + IntToStr(w);
      } else {
        if (SIN("_", sname))
          return sname; // already changed to 0_1
        else {
          auto n = StrToInt(sname);
          unsigned int w = ((unsigned int)std::floor(std::log2(n))) + 1;
          ILA_WARN << sname << " is considered to be of width " << w;
          return IntToStr(n) + "_" + IntToStr(w);
        }
      }
    } else if (_backend == backend_selector::JASPERGOLD) {
      if (SIN("'", sname))
        return sname;
      else {
        if (SIN("_", sname)) {
          return Split(sname, "_")
              .front(); // remove the bitwidth, let jaspergold itself decide
        } else
          return sname;
      }
    }*/
    // else -- only leave it here
    return sname; // NC
  } else if (token_tp == VarExtractor::token_type::ILA_S) {
    std::string quote = "";
    auto left_p = sname.find('[');
    auto check_s = sname.substr(0, left_p);
    auto range_s = left_p != std::string::npos ? sname.substr(left_p) : "";
    // if (_backend == backend_selector::COSA)
    //  quote = "'";
    // if it refers to ILA state
    if (_host->state(check_s))
      return quote + "__ILA_SO_" + check_s + quote + range_s;
    // if it uses the reference it self
    auto hierName = Split(check_s, ".");
    if (hierName.size() == 2) // maybe it contains an unnecessary head
      if ((hierName[0] == _ila_mod_inst_name || hierName[0] == "ILA") &&
          _host->state(hierName[1]))
        return quote + "__ILA_SO_" + hierName[1] + quote + range_s;
    // should not reachable
    ILA_CHECK(false)
        << "Implementation bug: should not be reachable. token_tp: ILA_S";
    return sname;
  } else if (token_tp == VarExtractor::token_type::ILA_IN) {
    auto left_p = sname.find('[');
    auto check_s = sname.substr(0, left_p);
    auto range_s = left_p != std::string::npos ? sname.substr(left_p) : "";

    std::string quote = "";
    // if (_backend == backend_selector::COSA)
    //  quote = "'";
    // if it refers to ILA state
    if (_host->input(check_s))
      return quote + "__ILA_I_" + check_s + quote + range_s;
    // if it uses the reference it self
    auto hierName = Split(check_s, ".");
    if (hierName.size() == 2) // maybe it contains an unnecessary head
      if ((hierName[0] == _ila_mod_inst_name || hierName[0] == "ILA") &&
          _host->input(hierName[1]))
        return quote + "__ILA_I_" + hierName[1] + quote + range_s;
    // should not reachable
    ILA_CHECK(false)
        << "Implementation bug: should not be reachable. token_tp: ILA_IN";
    return sname;
  } else if (token_tp == VarExtractor::token_type::VLG_S) {

    // do nothing for JasperGold
    // will not add to the all_referred name, so will not modify verilog
    if (_backend == backend_selector::JASPERGOLD)
      return sname;

    std::string quote = "";
    auto left_p = sname.find('[');
    auto check_s = sname.substr(0, left_p);
    auto range_s = left_p != std::string::npos ? sname.substr(left_p) : "";
    auto range_underscore = ReplaceAll(ReplaceAll(range_s, "[", "_"), "]", "_");
    // if (_backend == backend_selector::COSA)
    //  quote = "'";

    if (vlg_info_ptr->check_hierarchical_name_type(check_s) !=
        VerilogInfo::hierarchical_name_type::NONE) {
      _all_referred_vlg_names.insert({check_s + range_s, ex_info_t(range_s)});
      auto remove_dot_name = ReplaceAll(check_s, ".", "__DOT__");
      // Convert the check_s to
      return quote + remove_dot_name + quote + range_underscore;
    }
    if (vlg_info_ptr->check_hierarchical_name_type(_vlg_mod_inst_name + "." +
                                                   check_s) !=
        VerilogInfo::hierarchical_name_type::NONE) {
      _all_referred_vlg_names.insert(
          {_vlg_mod_inst_name + "." + check_s + range_s, ex_info_t(range_s)});
      auto remove_dot_name = ReplaceAll(check_s, ".", "__DOT__");
      return quote + _vlg_mod_inst_name + "__DOT__" + remove_dot_name + quote +
             range_underscore;
    }
    ILA_CHECK(false)
        << "Implementation bug: should not be reachable. token_type: VLG_S";
    return sname;
  }
  ILA_CHECK(false)
      << "Implementation bug: should not reachable. Caused by token_type:"
      << token_tp;
  return sname;
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

// static function
bool isEqu(const std::string& c) { return (c.find("=") != std::string::npos); }

// will create new variables "m?" and return it
// 1.  "ila-state":"**MEM**.?"
// 2a. "ila-state":"statename"  --> PerStateMap
// 2b. "ila-state":"(cond)&map"   --> PerStateMap
// 3.  "ila-state":[ "cond&map" ]
// 4.  "ila-state":[ {"cond":,"map":}, ]

// Replace an expr's variable name
std::string VlgSglTgtGen::ReplExpr(const std::string& expr,
                                   bool force_vlg_sts) {
  return _vext.Replace(expr, force_vlg_sts,
                       [this](const VarExtractor::token& t) {
                         return ModifyCondExprAndRecordVlgName(t);
                       });
}

std::string VlgSglTgtGen::PerStateMap(const std::string& ila_state_name,
                                      const std::string& vlg_st_name) {
  if (vlg_st_name.size() == 0) {
    ILA_INFO << "Skip mapping ila state:" << ila_state_name;
    return VLG_TRUE;
  }

  if (isEqu(vlg_st_name)) { // is equ
    // not using re here
    auto new_expr = ReplExpr(vlg_st_name);

    if (_backend == backend_selector::JASPERGOLD and
        new_expr.find('[') != new_expr.npos) {
      // this is a jasper gold bug
      return new_expr;
    }

    std::string map_sig = new_mapping_id();
    vlg_wrapper.add_wire(map_sig, 1, true);
    vlg_wrapper.add_output(map_sig, 1);
    add_wire_assign_assumption(map_sig, new_expr, "vmap");
    return map_sig;
  }
  // else it is a vlg signal name
  auto ila_state = TryFindIlaVarName(ila_state_name);
  if (!ila_state)
    return VLG_TRUE;
  if (ila_state->sort()->is_mem()) {
    // we need to decide if this memory is internal/external;
    bool external = _vlg_cfg.extMem;
    if (IN(ila_state_name, supplementary_info.memory_export))
      external = supplementary_info.memory_export.at(ila_state_name);

    if (!external) { // if internal
      // if you choose to expand the array then we are able to handle with out
      // MEM directive
      int addr_range = std::pow(2, ila_state->sort()->addr_width()); // 2^N
      int specify_range = asthub::GetMemSize(ila_state);
      ILA_ERROR_IF(specify_range > addr_range)
          << "For memory state: " << ila_state_name << ", its address width is"
          << ila_state->sort()->addr_width() << " which can hold " << addr_range
          << " addrs"
          << ", but range: " << specify_range
          << " is specified with SetEntryNum";
      if (specify_range != 0)
        addr_range = specify_range;
      // construct expansion expression
      std::string map_expr;
      for (int idx = 0; idx < addr_range; ++idx) {
        if (!map_expr.empty())
          map_expr += "&&";
        map_expr +=
            "( __ILA_SO_" + ila_state_name + "_" + std::to_string(idx) +
            " == " +
            ReplExpr(vlg_st_name + "[" + std::to_string(idx) + "]", true) + ")";
      }

      std::string map_sig = new_mapping_id();
      vlg_wrapper.add_wire(map_sig, 1, true);
      vlg_wrapper.add_output(map_sig, 1);
      add_wire_assign_assumption(map_sig, map_expr, "vmap");
      return map_sig;
    } else {
      ILA_ERROR
          << "Please use **MEM**.? directive for memory state matching of "
          << ila_state_name;
      return VLG_TRUE;
    }
  }
  // check for state match -- (no '=' inside at this step)
  std::string vlg_state_name = vlg_st_name;
  if (vlg_state_name.find(".") == std::string::npos &&
      vlg_state_name.find("#") == std::string::npos) {
    vlg_state_name = _vlg_mod_inst_name + "." + vlg_state_name;
  } // auto-add module name

  { // handle []
    auto pos = vlg_state_name.find('[');
    auto vlg_state_name_wo_idx = vlg_state_name;
    if (pos != vlg_state_name.npos)
      vlg_state_name_wo_idx = vlg_state_name_wo_idx.substr(0, pos);

    if (vlg_info_ptr->check_hierarchical_name_type(vlg_state_name_wo_idx) !=
        VerilogInfo::hierarchical_name_type::NONE) {
      // if this is truly a state name
      auto vlg_sig_info = vlg_info_ptr->get_signal(
          vlg_state_name_wo_idx, supplementary_info.width_info);
      ILA_ERROR_IF(!TypeMatched(ila_state, vlg_sig_info))
          << "ila state:" << ila_state_name
          << " has mismatched type w. verilog signal:" << vlg_state_name_wo_idx;
    } else {
      ILA_INFO_IF(!S_IN('#', vlg_state_name_wo_idx))
          << "rfmap: treating: " << vlg_state_name_wo_idx
          << " as an expression.";
    }
  }

  // add signal -- account for jg's bug
  if (_backend == backend_selector::JASPERGOLD &&
      vlg_state_name.find('[') != vlg_state_name.npos)
    return ReplExpr(vlg_state_name, true) + " == __ILA_SO_" +
           ila_state->name().str();

  std::string map_sig = new_mapping_id();
  vlg_wrapper.add_wire(map_sig, 1, true);
  vlg_wrapper.add_output(map_sig, 1);
  add_wire_assign_assumption(map_sig,
                             ReplExpr(vlg_state_name, true) + " == __ILA_SO_" +
                                 ila_state->name().str(),
                             "vmap");
  return map_sig;
} // PerStateMap

// ila-state -> ref (json)
// return a verilog verilog, that should be asserted to be true for this purpose
std::string VlgSglTgtGen::GetStateVarMapExpr(const std::string& ila_state_name,
                                             nlohmann::json& m,
                                             bool is_assert) {
  if (m.is_null())
    return VLG_TRUE;
  if (m.is_string()) {
    std::string rfm = m.get<std::string>();
    if (_sdr.isSpecialStateDir(rfm)) {
      // currently we only support **MEM** as state directive
      if (!_sdr.isSpecialStateDirMem(rfm)) {
        ILA_ERROR << "Unsupported state directive:" << rfm;
        return VLG_TRUE;
      }
      ILA_DLOG("VlgSglTgtGen.GetStateVarMapExpr")
          << "map mem:" << ila_state_name;

      bool external = _vlg_cfg.extMem;
      if (IN(ila_state_name, supplementary_info.memory_export))
        external = supplementary_info.memory_export.at(ila_state_name);

      ILA_ERROR_IF(!external)
          << "Should not use MEM directive since this memory is internal:"
          << ila_state_name;
      // may be we need to log them here
      if (is_assert == false) {
        _idr.SetMemName(rfm, ila_state_name, _vtg_config.MemAbsReadAbstraction);
        return VLG_TRUE; // no need for assumptions on memory
      }
      // handle memory: map vlg_ila.ila_wports && vlg_ila.ila_rports with
      // _idr.abs_mems

      auto ila_state = TryFindIlaVarName(ila_state_name);
      if (!ila_state) {
        ILA_ERROR << ila_state_name << " does not exist in ILA.";
        return VLG_TRUE;
      }
      if (!ila_state->sort()->is_mem()) {
        ILA_ERROR << ila_state_name << " is not memory, not compatible w. "
                  << rfm;
        return VLG_TRUE;
      }
      // if expand memory, it will not reach this point
      // but will on the per_state_map branch
      auto mem_eq_assert = _idr.ConnectMemory(
          rfm, ila_state_name, vlg_ila.ila_rports[ila_state_name],
          vlg_ila.ila_wports[ila_state_name], ila_state->sort()->addr_width(),
          ila_state->sort()->data_width(), _vtg_config.MemAbsReadAbstraction);
      // wire will be added by the absmem
      return mem_eq_assert;
    } else {
      // return the mapping variable
      return PerStateMap(ila_state_name, rfm);
    }
  }                   /* else */
  if (m.is_array()) { // array of string or array of object/array
    std::vector<std::string> all_mappings;
    std::string prev_neg; // make sure it is a priority condition lists

    for (auto& num_item_pair : m.items()) {
      auto& item = num_item_pair.value();
      if (item.is_string()) {
        auto mapping = ReplExpr(item.get<std::string>());
        all_mappings.push_back(mapping);
      } else if (item.is_array() ||
                 item.is_object()) { // it should only by size of 2
        std::string cond(VLG_TRUE), vmap(VLG_TRUE);
        for (const auto& i : (item).items()) {
          if (i.key() == "0" || i.key() == "cond") {
            if (i.value().is_null())
              continue;
            else if (i.value().is_string()) {
              cond = ReplExpr(i.value().get<std::string>()); // set the condtion
              continue;
            } else {
              ILA_ERROR
                  << "Expecting the first element/`cond` to be a string/null";
              continue;
            }
          }
          if (i.key() == "1" || i.key() == "map") {
            if (i.value().is_null())
              continue;
            else if (i.value().is_string()) {
              vmap = PerStateMap(ila_state_name, i.value().get<std::string>());
              continue; // set the mapping
            } else {
              ILA_ERROR
                  << "Expecting the second element/`map` to be a string/null";
              continue;
            }
          }
          ILA_ERROR << "mapping for statename:" << ila_state_name
                    << " contains unsupported construct.";
          break;
        }
        // cond ==> vmap    i.e.  ~cond || vmap
        all_mappings.push_back("~ (" + prev_neg + "(" + cond + ") ) || (" +
                               vmap + ")");
        prev_neg += "~(" + cond + ")&&";
      } else {
        ILA_ERROR << "Unable to handle this piece of JSON input:" << item;
        return VLG_TRUE;
      }
    } // for (item in m)

    if (all_mappings.size() == 0) {
      ILA_ERROR << "Variable mapping for " << ila_state_name << " is empty!";
      return VLG_TRUE;
    }

    return "(" + Join(all_mappings, " )&&( ") + ")";
  } // if it is an array

  // fall-through case
  ILA_ERROR << "Unable to handle this piece of JSON input:" << m;
  return VLG_TRUE;
} // GetStateVarMapExpr

void VlgSglTgtGen::handle_start_condition(nlohmann::json& dc) {
  if (!dc.is_array()) {
    ILA_ERROR << " not enforcing start condition: expect an array of strings.";
    return;
  }
  for (auto&& pr : dc.items()) {
    if (!pr.value().is_string()) {
      ILA_ERROR
          << " not enforcing start condition: expect an array of strings.";
      continue;
    }
    auto cond = pr.value().get<std::string>();
    cond = ReplaceAll(ReplaceAll(cond, "$decode$", vlg_ila.decodeNames[0]),
                      "$valid$", vlg_ila.validName);
    add_an_assumption("(~ __START__) || " + ReplExpr(cond), "start_condition");
    // ReplExpr: Yes, you need to translate it to the vlg names
  }
} // handle_start_condition

// use instruction pointer and the rf_cond to get it (no need to provide)
nlohmann::json& VlgSglTgtGen::get_current_instruction_rf() {
  if (_instr_ptr == nullptr)
    return empty_json;
  auto& instrs = rf_cond["instructions"];
  for (auto&& instr : instrs) {
    if (instr["instruction"] == _instr_ptr->name().str())
      return instr;
  }
  return empty_json;
}

}; // namespace ilang
