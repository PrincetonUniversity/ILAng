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


std::string VlgSglTgtGen::ReplExpr(const rfmap::RfExpr & in) {
  bool replace_dot = _backend != VlgSglTgtGen::backend_selector::JASPERGOLD;
  
  auto new_node = refinement_map.ReplacingRtlIlaVar(in, replace_dot);
  return new_node->to_verilog();
}

std::string VlgSglTgtGen::TranslateMap(const rfmap::RfExpr & in, const std::string & ila_vn) {
  if(refinement_map.IsLastLevelBooleanOp(in))
    return ReplExpr(in);
  auto vnode = verilog_expr::VExprAst::MakeVar("ILA."+ila_vn);
  auto eq_node = verilog_expr::VExprAst::MakeBinaryAst(verilog_expr::voperator::L_EQ, vnode, in);
  return ReplExpr(eq_node);
}

void VlgSglTgtGen::Gen_varmap_assumpt_assert(const std::string& ila_state_name,
  const rfmap::IlaVarMapping &vmap, const std::string & problem_name, bool true_for_assumpt_false_for_assert,
  const std::string & prefix, const std::string & suffix) {
  
#define ADD_CONSTR(p1) do{ \
  if(true_for_assumpt_false_for_assert)  \
     add_an_assumption(prefix + (p1) + suffix, problem_name);  \
  else   \
     add_an_assertion(prefix + (p1) + suffix, problem_name); \
  }while(0)
  
  bool is_mem = _host->state(ila_state_name)->is_mem();
  if(!is_mem) {
    ILA_ERROR_IF(vmap.type == rfmap::IlaVarMapping::StateVarMapType::EXTERNMEM)
      << "ila sv " << ila_state_name << " is not memory!";
    if(vmap.type == rfmap::IlaVarMapping::StateVarMapType::SINGLE) {
      ADD_CONSTR(TranslateMap(vmap.single_map.single_map, ila_state_name));
    } else if (vmap.type == rfmap::IlaVarMapping::StateVarMapType::CONDITIONAL) {
      std::vector<std::string> all_mappings;
      std::string prev_neg; // make sure it is a priority condition lists
      for (const auto & cond_map_pair : vmap.single_map.cond_map) {
        std::string cond_expr = ReplExpr(cond_map_pair.first);
        std::string vmap_expr = TranslateMap(cond_map_pair.second, ila_state_name);

        all_mappings.push_back("~ (" + prev_neg + "(" + cond_expr + ") ) || (" +
                               vmap_expr + ")");
        prev_neg += "~(" + cond_expr + ")&&";
      } // end for each condition map item
      ILA_ERROR_IF(all_mappings.empty()) << "Conditional map is empty!";
      auto map_str = "(" + Join(all_mappings, " )&&( ") + ")";
      ADD_CONSTR(map_str);
    } // end map type
  } else {
    if(vmap.type == rfmap::IlaVarMapping::StateVarMapType::EXTERNMEM) {
      // TODO: (note: multiple ports!)
      //  assume : START |-> 
      //         ( ila.ren && rtl.renexpr && (ila.raddr == rtl.raddrexpr) |->
      //             (ila.rdata === rtl.rdataexpr) )

      //  assert : IEND |->
      //         ( ila.wen_d1 == rtl.wenexpr && ( ila.wen |-> 
      //             (ila.wdata_d1 == rtl.wdataexpr) && (ila.waddr_d1 == rtl.waddrexpr) ) )


    } // same for jg/non-jg
    else {
      bool is_jg = _backend == backend_selector::JASPERGOLD;
      bool is_pono = _backend == backend_selector::PONO;
      if(is_jg) {
        // same as non-mem var
        if(vmap.type == rfmap::IlaVarMapping::StateVarMapType::SINGLE) {
          ADD_CONSTR(TranslateMap(vmap.single_map.single_map, ila_state_name));
        } else if (vmap.type == rfmap::IlaVarMapping::StateVarMapType::CONDITIONAL) {
          std::vector<std::string> all_mappings;
          std::string prev_neg; // make sure it is a priority condition lists
          for (const auto & cond_map_pair : vmap.single_map.cond_map) {
            std::string cond_expr = ReplExpr(cond_map_pair.first);
            std::string vmap_expr = TranslateMap(cond_map_pair.second, ila_state_name);

            all_mappings.push_back("~ (" + prev_neg + "(" + cond_expr + ") ) || (" +
                                  vmap_expr + ")");
            prev_neg += "~(" + cond_expr + ")&&";
          } // end for each condition map item
          ILA_ERROR_IF(all_mappings.empty()) << "Conditional map is empty!";
          auto map_str = "(" + Join(all_mappings, " )&&( ") + ")";
          ADD_CONSTR(map_str);
        } // end map type
      } else {
         //TODO: to smt-lib2
         ILA_CHECK(is_pono) << "Only PONO/JG backend can handle array eq property";
         if ()

      } // end of is_jg / else
    } // end of is_extmem / else
  } // end for memory-case

#undef ADD_CONSTR
} // end of Gen_varmap_assumpt_assert

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

void VlgSglTgtGen::handle_start_condition(const std::vector<rfmap::RfExpr> & dc) {
  for (const auto & c : dc) {
    auto cond = ReplExpr(c);
    cond = ReplaceAll(ReplaceAll(cond, "$decode", vlg_ila.decodeNames[0]),
                      "$valid", vlg_ila.validName);
    add_an_assumption("(~ __START__) || (" + cond +")", "start_condition");
  }
} // handle_start_condition


}; // namespace ilang
