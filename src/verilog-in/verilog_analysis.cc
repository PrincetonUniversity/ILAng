/// \file
/// Verilog Analyzer

#include <ilang/verilog-in/verilog_analysis.h>

#include <cstdio>
#include <sstream>
#include <string>

#include <ilang/util/container_shortcut.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/verilog-in/vlog_parser_util.h>

// extern int yy_flex_debug;
extern int yydebug;

namespace ilang {

unsigned VerilogAnalyzer::instance_count = 0;

// we need to use this, so vlg parser will record memory usage and free later
void* AllocCstr(const std::string& str) {
  char* ret = (char*)ast_calloc(str.size() + 1, sizeof(char));
  strcpy(ret, str.c_str());
  return (void*)ret;
}

template <class T1, class T2>
T2 GetMap(const std::map<T1, T2>& _map, const T1& k) {
  auto pos = _map.find(k);
  ILA_ASSERT(pos != _map.end());
  return pos->second;
}

template <class T1, class T2>
const T2& GetMapRef(const std::map<T1, T2>& _map, const T1& k) {
  auto pos = _map.find(k);
  ILA_ASSERT(pos != _map.end());
  return pos->second;
}

static void* ast_list_get_not_null(ast_list* list, unsigned int item) {
  void* ret = ast_list_get(list, item);
  ILA_NOT_NULL(ret);
  return ret;
}

std::string VerilogAnalyzer::get_module_name_of_net_name(
    const std::string& net_name) const {
  ILA_ERROR_IF(!S_IN(".", net_name))
      << net_name << " is not a net name, no '.'";
  auto levels = Split(net_name, ".");
  levels.pop_back(); // remove the last element
  auto mod_name = Join(levels, ".");
  ILA_ERROR_IF(check_hierarchical_name_type(mod_name) !=
               hierarchical_name_type::MODULE)
      << mod_name << " is not a module in the verilog";
  return mod_name;
}

bool VerilogAnalyzer::_bad_state_return() const {
  ILA_ERROR_IF(_bad_state)
      << "VerilogAnalyzer cannot proceed because of being in a bad state";
  return _bad_state;
}

VerilogAnalyzer::VerilogAnalyzer(const path_vec_t& include_path,
                                 const path_vec_t& srcs,
                                 const std::string& top_module_inst_name,
                                 const std::string& optional_top_module)
    : vlg_include_path(include_path), vlg_src_files(srcs),
      top_inst_name(top_module_inst_name), _bad_state(false) {
  // yydebug = 1;
  instance_count++;
  if (instance_count != 1) {
    _bad_state = true;
    ILA_ERROR << "Please don't keep multiple instances of analyzer, it will "
                 "mess up w. Verilog parser.";
    return; // do nothing
  }

  invoke_parser();
  if (_bad_state_return())
    return;
  check_resolve_modules(yy_verilog_source_tree);
  if (_bad_state_return())
    return;
  create_module_submodule_map(yy_verilog_source_tree);
  if (_bad_state_return())
    return;
  find_top_module(yy_verilog_source_tree, optional_top_module);
  if (_bad_state_return())
    return;

} // VerilogAnalyzer::VerilogAnalyzer

VerilogAnalyzer::~VerilogAnalyzer() {
  if (instance_count == 1) {
    ast_free_all();
    yy_preproc = NULL;
    yy_verilog_source_tree = NULL;
  }
  instance_count--;
}

void VerilogAnalyzer::invoke_parser() {
  // Initialise the parser.
  verilog_parser_init();

  for (auto&& dir : vlg_include_path) {
    ast_list_append(yy_preproc->search_dirs, AllocCstr(dir));
  }

  for (auto&& src : vlg_src_files) {

    std::FILE* fhandler = std::fopen(src.c_str(), "r");
    if (fhandler == NULL) {
      ILA_ERROR << "Verilog Analyzer cannot open file: " << src;
      _bad_state = true;
      return;
    }
    verilog_preprocessor_set_file(yy_preproc, (char*)AllocCstr(src));
    // yy_flex_debug = (1);
    int result = verilog_parse_file(fhandler);
    if (result != 0) {
      ILA_ERROR << "Verilog Analyzer encounters syntax error for " << src
                << ". Terminated.";
      _bad_state = true;
      return;
    }
    fclose(fhandler);
  }
  // derive the hierarchy.
  verilog_resolve_modules(yy_verilog_source_tree);
  ILA_NOT_NULL(yy_verilog_source_tree); // Parser returns empty AST
  ILA_ERROR_IF(yy_verilog_source_tree->modules == NULL)
      << "No Verilog module is found";
}

void VerilogAnalyzer::check_resolve_modules(verilog_source_tree* source) {
  ILA_NOT_NULL(source);
  ILA_NOT_NULL(source->modules);

  for (unsigned int m = 0; m < source->modules->items; m++) {

    ast_module_declaration* module =
        (ast_module_declaration*)ast_list_get_not_null(source->modules, m);

    ILA_NOT_NULL(module->identifier); // otherwise it is the parser bug

    auto mod_name = _ast_identifier_tostring(module->identifier);
    if (IN(mod_name,
           name_module_map)) { // the module has been encountered, redefinition
      std::stringstream outinfo;
      PrintMetaAst(outinfo << "Redeclaration of module @", module)
          << " . Ignored.";
      ILA_ERROR << outinfo.str();
      continue;
    }
    name_module_map.insert({mod_name, module});

    ILA_NOT_NULL(module->module_instantiations); // other wise it is parser bug
    if (module->module_instantiations->items == 0)
      continue;

    ILA_NOT_NULL(module->identifier);
    // ILA_NOT_NULL(module->module_instantiations);

    for (unsigned int sm = 0; sm < module->module_instantiations->items; sm++) {
      ast_module_instantiation* submod =
          (ast_module_instantiation*)ast_list_get_not_null(
              module->module_instantiations, sm);

      if (submod->resolved) { // Do Nothing
      } else
        ILA_WARN << "Verilog module "
                 << _ast_identifier_tostring(submod->module_identifer)
                 << "'s definition is not found.";
    }
  }
}

void VerilogAnalyzer::create_module_submodule_map(verilog_source_tree* source) {
  ILA_NOT_NULL(source);
  ILA_NOT_NULL(source->modules);

  for (auto&& nm_pos : name_module_map) {
    auto name = nm_pos.first;
    auto module_ast_ptr = nm_pos.second;

    modules_to_submodules_map[name] =
        mod_inst_t(); // at least we should have an empty list
    modules_to_submodule_inst_ast_map[name] =
        mod_inst_ast_t(); // at least we should have an empty list

    for (unsigned int sm = 0; sm < module_ast_ptr->module_instantiations->items;
         sm++) {
      ast_module_instantiation* submod =
          (ast_module_instantiation*)ast_list_get_not_null(
              module_ast_ptr->module_instantiations, sm);

      auto submod_name =
          submod->resolved
              ? _ast_identifier_tostring(submod->declaration->identifier)
              : _ast_identifier_tostring(submod->module_identifer);

      // get the instance names
      for (unsigned int si = 0; si < submod->module_instances->items; si++) {
        ast_module_instance* submod_inst =
            (ast_module_instance*)ast_list_get_not_null(
                submod->module_instances, si);
        ILA_NOT_NULL(submod_inst);
        auto submod_name_inst =
            _ast_identifier_tostring(submod_inst->instance_identifier);
        modules_to_submodules_map[name].insert({submod_name_inst, submod_name});
        modules_to_submodule_inst_ast_map[name].insert(
            {submod_name_inst, submod});

      } // for each instance of sub module
    }   // for each sub module
  }     // for each module
} // create_module_submodule_map

// extract the top module name
void VerilogAnalyzer::find_top_module(verilog_source_tree* source,
                                      const std::string& optional_top_module) {
  ILA_NOT_NULL(source);
  ILA_NOT_NULL(source->modules);
  for (auto&& nm_pos : name_module_map) {
    auto name = nm_pos.first;
    auto module_ast_ptr = nm_pos.second;

    for (unsigned int sm = 0; sm < module_ast_ptr->module_instantiations->items;
         sm++) {
      ast_module_instantiation* submod =
          (ast_module_instantiation*)ast_list_get_not_null(
              module_ast_ptr->module_instantiations, sm);

      auto submod_name =
          submod->resolved
              ? _ast_identifier_tostring(submod->declaration->identifier)
              : _ast_identifier_tostring(submod->module_identifer);

      module_to_whereuses_map[submod_name].push_back(name);
    }
  }

  std::set<std::string> top_module_candidates;
  for (auto&& nm_pos : name_module_map) {
    auto name = nm_pos.first;
    if (module_to_whereuses_map.find(name) ==
        module_to_whereuses_map.end()) { // if not used
      top_module_candidates.insert(name);
    }
  }
  unsigned candidate_cnt = top_module_candidates.size();
  if (candidate_cnt == 0) {
    ILA_ERROR
        << "VerilogAnalyzer thinks there is a loop in module instantiation.";
    _bad_state = true;
    return;
  } else if (optional_top_module != "") {
    if (!IN(optional_top_module, name_module_map)) {
      ILA_ERROR << "VerilogAnalyzer: the specified top module:"
                << optional_top_module << " is not found!";
      _bad_state = true;
      return;
    }
    ILA_WARN_IF(!IN(optional_top_module, top_module_candidates))
        << "VerilogAnalyzer: the specified top module:" << optional_top_module
        << " has instantiations. Please consider cleaning the source tree!";
    top_module_name = optional_top_module;
  } else {
    if (top_module_candidates.size() > 1) {
      ILA_WARN
          << "VerilogAnalyzer finds multiple top module candidates. They are:";
      for (auto&& n : top_module_candidates) {
        ILA_WARN << n;
      }
      ILA_WARN << "The first one will be used.";
    }
    top_module_name = *(top_module_candidates.begin());
  }

} // find_top_module

VerilogAnalyzer::hierarchical_name_type
VerilogAnalyzer::check_hierarchical_name_type(
    const std::string& net_name) const {
  if (_bad_state_return())
    return hierarchical_name_type::NONE;

  auto pos = name_type_buffer.find(net_name);
  if (pos != name_type_buffer.end())
    return pos->second;
  auto tp_ = _check_hierarchical_name_type(net_name);
  if (tp_ != hierarchical_name_type::NONE) // only cache if it really exists
    name_type_buffer.insert({net_name, tp_});
  return tp_;
}

VerilogAnalyzer::hierarchical_name_type
VerilogAnalyzer::_check_hierarchical_name_type(
    const std::string& net_name) const {
  std::vector<std::string> level_names = Split(net_name, ".");
  if (level_names[0] != top_inst_name)
    return hierarchical_name_type::NONE;
  if (level_names.size() ==
      1) { // already matched (so, we don't compare again) o.w. return above
    name_decl_buffer[net_name] = GetMap(name_module_map, top_module_name);
    return hierarchical_name_type::MODULE;
  }

  auto curr_mod_name = top_module_name;
  for (unsigned hId = 1; hId < level_names.size() - 1; hId++) {
    auto inst_name = level_names[hId];
    auto pos =
        GetMapRef(modules_to_submodules_map, curr_mod_name).find(inst_name);
    if (pos == GetMapRef(modules_to_submodules_map, curr_mod_name).end())
      return hierarchical_name_type::NONE; // this instance name does not exists

    curr_mod_name = pos->second;
  }
  auto last_level_name =
      level_names[level_names.size() - 1]; // level_names[level_names.size() -1]
  if (IN(last_level_name,
         GetMapRef(modules_to_submodules_map, curr_mod_name))) { // found
    // here we need to convert the instance name to the module name
    auto module_name = GetMap(
        GetMapRef(modules_to_submodules_map, curr_mod_name), last_level_name);
    name_decl_buffer[net_name] = GetMap(name_module_map, module_name);
    return hierarchical_name_type::MODULE;
  }

  ILA_ASSERT(IN(curr_mod_name, name_module_map));

  // check if it is an IO port
  bool isIO = false;
  bool isRegPort = false;
  ast_port_direction drt;
  ast_port_declaration* io_port = NULL;

  ast_module_declaration* mod_ast_ptr = GetMap(name_module_map, curr_mod_name);

  ILA_DLOG("VerilogAnalyzer._check_hierarchical_name_type")
      << "last level name:" << last_level_name;
  ILA_DLOG("VerilogAnalyzer._check_hierarchical_name_type") << "Check port";
  for (unsigned int mod_port_idx = 0;
       mod_port_idx < mod_ast_ptr->module_ports->items; mod_port_idx++) {
    ast_port_declaration* port_ptr =
        (ast_port_declaration*)ast_list_get_not_null(mod_ast_ptr->module_ports,
                                                     mod_port_idx);
    // traverse the names: should be just one
    for (unsigned int name_idx = 0; name_idx < port_ptr->port_names->items;
         ++name_idx) {

      void* ptr_from_list_ =
          ast_list_get_not_null(port_ptr->port_names, name_idx);
      ast_identifier port_id_ptr;
      if (!port_ptr->is_list_id) { // in this case, it is not a list of
                                   // ast_identifier
        // but a list of ast_single_assignment(ast_new_lvalue_id)
        ast_single_assignment* asm_ptr = (ast_single_assignment*)ptr_from_list_;
        ILA_ASSERT(asm_ptr->lval->type == ast_lvalue_type_e::NET_IDENTIFIER ||
                   asm_ptr->lval->type == ast_lvalue_type_e::VAR_IDENTIFIER);
        port_id_ptr = asm_ptr->lval->data.identifier;
      } else // otherwise it is a list of id
        port_id_ptr = (ast_identifier)ptr_from_list_;

      // if (port_id_ptr->)
      ILA_NOT_NULL(port_id_ptr);
      ILA_NOT_NULL(port_id_ptr->identifier);
      auto port_name = _ast_identifier_tostring(port_id_ptr);
      ILA_ASSERT(port_name != "")
          << "Get an empty port name from the verilog parser";
      if (port_name == last_level_name) {
        if (isIO) {
          std::stringstream outinfo;
          PrintMetaAst(outinfo
                           << "Signal:" << net_name
                           << " seems to have been mentioned multiple times.",
                       port_id_ptr);
          ILA_ERROR << outinfo.rdbuf();
        }
        isIO = true;
        io_port = port_ptr;
        isRegPort = port_ptr->is_reg;
        drt = port_ptr->direction;
      }
    } // for
  }   // check if it is port

  // let's find if there exists a wire/reg for it / not I/O
  bool internalDef = false;
  bool isReg = false;
  void* reg_or_wire_ptr = NULL;

  ILA_DLOG("VerilogAnalyzer._check_hierarchical_name_type") << "Check reg";
  for (unsigned int reg_decl_idx = 0;
       reg_decl_idx < mod_ast_ptr->reg_declarations->items; reg_decl_idx++) {
    ast_reg_declaration* reg_decl_ptr =
        (ast_reg_declaration*)ast_list_get_not_null(
            mod_ast_ptr->reg_declarations, reg_decl_idx);
    if (_ast_identifier_tostring(reg_decl_ptr->identifier) == last_level_name) {
      // now we know it is reg!
      if (internalDef) {
        std::stringstream outbuf;
        PrintMetaAst(outbuf << "Reg:" << net_name
                            << " seems to have been defined multiple times.",
                     reg_decl_ptr);
        ILA_ERROR << outbuf.rdbuf();
      }
      internalDef = true;
      isReg = true;
      reg_or_wire_ptr = reg_decl_ptr;
    }
  } // check if it is internal reg

  ILA_DLOG("VerilogAnalyzer._check_hierarchical_name_type") << "Check net";
  for (unsigned int net_decl_idx = 0;
       net_decl_idx < mod_ast_ptr->net_declarations->items; net_decl_idx++) {
    ast_net_declaration* net_decl_ptr =
        (ast_net_declaration*)ast_list_get_not_null(
            mod_ast_ptr->net_declarations, net_decl_idx);
    // this is double bug cancellation. (it's identifier is actually
    // ast_single_assignment)
    ast_single_assignment* asm_ptr =
        (ast_single_assignment*)(net_decl_ptr->identifier_assignment);

    if (_ast_identifier_tostring(asm_ptr->lval->data.identifier) ==
        last_level_name) {
      // now we know it is net!
      if (internalDef) {
        if (isReg) {
          ILA_WARN << "Reg:" << net_name
                   << " has been declare as a wire, ignoring...";
          continue;
        }
        // else
        std::stringstream outinfo;
        PrintMetaAst(outinfo << "Wire:" << net_name
                             << " has been declared multiple times",
                     net_decl_ptr);
        ILA_ERROR << outinfo.rdbuf();
      }
      internalDef = true;
      isReg = false;
      reg_or_wire_ptr = net_decl_ptr;
    }
  } // net declaration

  ILA_DLOG("VerilogAnalyzer._check_hierarchical_name_type") << "Check done";
  // let's decide what it is
  if (isIO) {
    if (internalDef) {
      // check for conflict
      if (isReg && (drt == ast_port_direction::PORT_INPUT ||
                    drt == ast_port_direction::PORT_INOUT)) {
        ILA_ERROR << net_name << " cannot be declared as both input and reg.";
        return hierarchical_name_type::OTHERS; // not able to decide
      }
      if (isRegPort && !isReg) {
        ILA_ERROR << net_name
                  << " declared reg at the port but wire internally.";
        return hierarchical_name_type::OTHERS; // not able to decide
      }

      // use its internal definition
      name_decl_buffer[net_name] = reg_or_wire_ptr;

      if (isReg)
        return hierarchical_name_type::O_REG_w_INTERNAL_DEF;

      switch (drt) {
      case ast_port_direction::PORT_INPUT:
        return hierarchical_name_type::I_WIRE_w_INTERNAL_DEF;
      case ast_port_direction::PORT_OUTPUT:
        return hierarchical_name_type::O_WIRE_w_INTERNAL_DEF;
      case ast_port_direction::PORT_INOUT:
        return hierarchical_name_type::IO_WIRE_w_INTERNAL_DEF;
      default:
        ILA_ERROR << "Unknown direction for port:" << net_name;
        return hierarchical_name_type::OTHERS;
      }
      return hierarchical_name_type::OTHERS;
    } // else no internal def

    // use its port definition
    name_decl_buffer[net_name] = io_port;

    if (isRegPort)
      return hierarchical_name_type::O_REG_wo_INTERNAL_DEF;
    // else
    switch (drt) {
    case ast_port_direction::PORT_INPUT:
      return hierarchical_name_type::I_WIRE_wo_INTERNAL_DEF;
    case ast_port_direction::PORT_OUTPUT:
      return hierarchical_name_type::O_WIRE_wo_INTERNAL_DEF;
    case ast_port_direction::PORT_INOUT:
      return hierarchical_name_type::IO_WIRE_wo_INTERNAL_DEF;
    default:
      ILA_ERROR << "Unknown direction for port:" << net_name;
      return hierarchical_name_type::OTHERS;
    }
    return hierarchical_name_type::OTHERS;
  } else if (internalDef) {
    // use its internal definition
    name_decl_buffer[net_name] = reg_or_wire_ptr;

    if (isReg)
      return hierarchical_name_type::REG;
    return hierarchical_name_type::WIRE;
  }
  // else
  return hierarchical_name_type::NONE; // not found
}

// it could return ast_module_declaration, ast_net_declaration,
// ast_reg_declaration, ast_port_declaration
void* VerilogAnalyzer::find_declaration_of_name(
    const std::string& net_name) const {
  if (_bad_state_return())
    return NULL;
  auto tp_ = check_hierarchical_name_type(net_name);
  if (tp_ == hierarchical_name_type::OTHERS) {
    ILA_ERROR << "Unknown type of " << net_name;
    return NULL;
  }
  if (tp_ == hierarchical_name_type::NONE) {
    ILA_ERROR << "Cannot find declaration: " << net_name;
    return NULL;
  }
  auto pos = name_decl_buffer.find(net_name);
  ILA_ASSERT(pos != name_decl_buffer.end())
      << "Implementation bug: " << net_name
      << " must exists in the declaration map.";
  return pos->second;
}

/// Return the location of a module instantiation
VerilogAnalyzer::vlg_loc_t
VerilogAnalyzer::get_module_inst_loc(const std::string& inst_name) const {
  if (_bad_state_return())
    return vlg_loc_t();

  std::vector<std::string> level_names = Split(inst_name, ".");
  if (level_names[0] != top_inst_name) {
    ILA_ERROR << inst_name << " not found.";
    return vlg_loc_t();
  }
  if (level_names.size() ==
      1) { // already matched (so, we don't compare again) o.w. return above
    name_decl_buffer[inst_name] = GetMap(name_module_map, top_module_name);
    ILA_ERROR << "Top module has no instance! Use the declaration location "
                 "instead.";
    return name2loc(inst_name);
  }

  // goes deep down the hierarchy
  auto curr_mod_name = top_module_name;
  for (unsigned hId = 1; hId < level_names.size() - 1; hId++) {
    auto inst_name_i = level_names[hId];
    auto pos =
        GetMapRef(modules_to_submodules_map, curr_mod_name).find(inst_name_i);
    if (pos == GetMapRef(modules_to_submodules_map, curr_mod_name).end()) {
      ILA_ERROR << inst_name_i << " not found.";
      return vlg_loc_t(); // this instance name does not exists
    }
    curr_mod_name = pos->second;
  }

  auto last_level_name = level_names[level_names.size() - 1]; // the last one
  if (!IN(last_level_name,
          GetMapRef(modules_to_submodules_map, curr_mod_name))) {
    ILA_ERROR << inst_name << " not found in the last level.";
    return vlg_loc_t(); // this instance name does not exists
  }

  auto module_name = GetMap(GetMapRef(modules_to_submodules_map, curr_mod_name),
                            last_level_name);

  ILA_ASSERT(IN(curr_mod_name, name_module_map));

  ast_module_declaration* module_ast_ptr =
      GetMap(name_module_map, curr_mod_name);

  for (unsigned int sm = 0; sm < module_ast_ptr->module_instantiations->items;
       sm++) {
    ast_module_instantiation* submod =
        (ast_module_instantiation*)ast_list_get_not_null(
            module_ast_ptr->module_instantiations, sm);
    // goes into the instantiation and iterate over the instance name
    for (unsigned int smi = 0; smi < submod->module_instances->items; smi++) {
      ast_module_instance* submod_inst =
          (ast_module_instance*)ast_list_get_not_null(submod->module_instances,
                                                      smi);
      auto submod_name_inst =
          _ast_identifier_tostring(submod_inst->instance_identifier);
      if (submod_name_inst == last_level_name)
        return Meta2Loc(submod_inst->instance_identifier->meta);
    } // for each instance in the instantiation
  }   // for each module instantiation

  ILA_ASSERT(false) << "Implementation bug:" << inst_name
                    << " not found in the instantiation.";
  return vlg_loc_t(); // this instance name does not exists
}

VerilogAnalyzer::vlg_loc_t
VerilogAnalyzer::name2loc(const std::string& net_name) const {
  if (_bad_state_return())
    return vlg_loc_t();
  auto tp_ = check_hierarchical_name_type(net_name);
  void* ptr_ = find_declaration_of_name(net_name);
  ILA_NOT_NULL(ptr_);

  if (is_module(tp_))
    return Meta2Loc(((ast_module_declaration*)ptr_)->identifier->meta);
  // here we should use identifier's location ^^^^
  if (no_internal_def(tp_))
    return Meta2Loc(((ast_port_declaration*)ptr_)->meta);
  if (is_reg(tp_))
    return Meta2Loc(((ast_reg_declaration*)ptr_)->meta);
  if (is_wire(tp_))
    return Meta2Loc(((ast_net_declaration*)ptr_)->meta);

  ILA_ASSERT(false)
      << "Implementation bug: name2loc: should not be reachable. Type:" << tp_;
  return vlg_loc_t("", 0);
}

/// Find a signal
SignalInfoBase VerilogAnalyzer::get_signal(
    const std::string& net_name,
    const std::map<std::string, int>* const width_info) const {
  SignalInfoBase bad_signal("", "", 0, hierarchical_name_type::NONE,
                            vlg_loc_t());

  if (_bad_state_return())
    return bad_signal;

  void* ast_ptr = find_declaration_of_name(net_name);
  auto tp_ = check_hierarchical_name_type(net_name);

  if (ast_ptr == NULL)
    return bad_signal;

  // auto mod_name = get_module_name_of_net_name(net_name);
  // ast_module_declaration* mod_ast_ptr =
  //    (ast_module_declaration*)find_declaration_of_name(mod_name);

  switch (tp_) {
  case I_WIRE_wo_INTERNAL_DEF:
  case O_WIRE_wo_INTERNAL_DEF:
  case IO_WIRE_wo_INTERNAL_DEF:
    return SignalInfoPort((ast_port_declaration*)ast_ptr, net_name, tp_,
                          width_info, this);

  case I_WIRE_w_INTERNAL_DEF:
  case O_WIRE_w_INTERNAL_DEF:
  case IO_WIRE_w_INTERNAL_DEF:
  case WIRE:
    return SignalInfoWire((ast_net_declaration*)ast_ptr, net_name, tp_,
                          width_info, this);

  case O_REG_wo_INTERNAL_DEF:
    return SignalInfoPort((ast_port_declaration*)ast_ptr, net_name, tp_,
                          width_info, this);
  case O_REG_w_INTERNAL_DEF:
  case REG:
    return SignalInfoReg((ast_reg_declaration*)ast_ptr, net_name, tp_,
                         width_info, this);
  case MODULE:
    ILA_ERROR << "Module instance:" << net_name << " is not a signal.";
    return bad_signal;
  default:
    ILA_ERROR << "Does not know how to handle:" << net_name
              << ", which is not a signal.";
    return bad_signal;
  }
  // should not be reachable
  return bad_signal;
}

/// Return top module signal
VerilogAnalyzer::module_io_vec_t VerilogAnalyzer::get_top_module_io(
    const std::map<std::string, int>* const width_info) const {

  module_io_vec_t retIoVec;
  if (_bad_state_return())
    return retIoVec;

  ILA_ASSERT(IN(top_module_name, name_module_map));
  const ast_module_declaration* top_module_ast =
      name_module_map.find(top_module_name)->second;
  ILA_NOT_NULL(top_module_ast);

  for (unsigned int mod_port_idx = 0;
       mod_port_idx < top_module_ast->module_ports->items; mod_port_idx++) {
    ast_port_declaration* port_ptr =
        (ast_port_declaration*)ast_list_get_not_null(
            top_module_ast->module_ports, mod_port_idx);
    // traverse the names: should be just one
    for (unsigned int name_idx = 0; name_idx < port_ptr->port_names->items;
         ++name_idx) {

      void* ptr_from_list_ =
          ast_list_get_not_null(port_ptr->port_names, name_idx);
      ast_identifier port_id_ptr;
      if (!port_ptr->is_list_id) { // in this case, it is not a list of
                                   // ast_identifier
        // but a list of ast_single_assignment(ast_new_lvalue_id)
        ast_single_assignment* asm_ptr = (ast_single_assignment*)ptr_from_list_;
        ILA_ASSERT(asm_ptr->lval->type == ast_lvalue_type_e::NET_IDENTIFIER ||
                   asm_ptr->lval->type == ast_lvalue_type_e::VAR_IDENTIFIER);
        port_id_ptr = asm_ptr->lval->data.identifier;
      } else
        port_id_ptr = (ast_identifier)ptr_from_list_;

      auto short_name = _ast_identifier_tostring(port_id_ptr);
      std::string port_name = top_inst_name + "." + short_name;

      auto tp_ = check_hierarchical_name_type(port_name);
      ILA_ASSERT(is_io_sig(tp_)) << "Implementation bug: port " << port_name
                                 << " seems not having I/O signal type!";

      void* ast_ptr = find_declaration_of_name(port_name);

      // auto mod_name = get_module_name_of_net_name(port_name);
      // ast_module_declaration* mod_ast_ptr =
      //    (ast_module_declaration*)find_declaration_of_name(mod_name);

      switch (tp_) {
      case I_WIRE_wo_INTERNAL_DEF:
      case O_WIRE_wo_INTERNAL_DEF:
      case IO_WIRE_wo_INTERNAL_DEF:
        retIoVec.insert(
            {short_name, SignalInfoPort((ast_port_declaration*)ast_ptr,
                                        port_name, tp_, width_info, this)});
        break;

      case I_WIRE_w_INTERNAL_DEF:
      case O_WIRE_w_INTERNAL_DEF:
      case IO_WIRE_w_INTERNAL_DEF:
        retIoVec.insert(
            {short_name, SignalInfoWire((ast_net_declaration*)ast_ptr,
                                        port_name, tp_, width_info, this)});
        break;

      case O_REG_wo_INTERNAL_DEF:
        retIoVec.insert(
            {short_name, SignalInfoPort((ast_port_declaration*)ast_ptr,
                                        port_name, tp_, width_info, this)});
        break;
      case O_REG_w_INTERNAL_DEF:
        retIoVec.insert(
            {short_name, SignalInfoReg((ast_reg_declaration*)ast_ptr, port_name,
                                       tp_, width_info, this)});
        break;
      default:
        ILA_ASSERT(false) << "Implementation bug.";
      }
    }
  }
  return retIoVec;
} // function get_top_module_io

/// Return the location of a module's endmodule statement
VerilogAnalyzer::vlg_loc_t
VerilogAnalyzer::get_endmodule_loc(const std::string& inst_name) const {
  if (_bad_state_return())
    return vlg_loc_t();
  auto tp_ = check_hierarchical_name_type(inst_name);
  void* ptr_ = find_declaration_of_name(inst_name);
  ILA_NOT_NULL(ptr_);
  if (!is_module(tp_)) {
    ILA_ERROR << inst_name
              << " should not be the argument of get_endmodule_loc, not a "
                 "module instance name.";
    return vlg_loc_t();
  }
  /*
  if( ((ast_module_declaration *)ptr_)->meta-> == NULL ) {
    vlg_loc_t tmp_loc;
    tmp_loc.
  } // this could happen, I don't know why // use the identifer's  meta
  */
  return Meta2Loc(((ast_module_declaration*)ptr_)->meta);
}

bool VerilogAnalyzer::get_hierarchy_from_full_name(
    const std::string& full_name,
    VerilogConstantExprEval::param_def_hierarchy& hier,
    ast_module_declaration** lowest_level) const {

  std::vector<std::string> level_names = Split(full_name, ".");
  level_names.pop_back(); // remove signal name
  if (level_names.empty())
    return false;
  if (level_names[0] != top_inst_name)
    return false;

  if (level_names.size() == 1) { // we don't need hierachy things
    *lowest_level = GetMap(name_module_map, top_module_name);
    return true;
  }

  // go down the hierarchy
  auto curr_mod_name = top_module_name;
  for (unsigned hId = 1; hId < level_names.size(); hId++) {
    auto inst_name = level_names[hId];
    auto pos_mod_decl =
        GetMapRef(modules_to_submodules_map, curr_mod_name).find(inst_name);
    auto pos_mod_inst_ast =
        GetMapRef(modules_to_submodule_inst_ast_map, curr_mod_name)
            .find(inst_name);

    if (pos_mod_decl ==
            GetMapRef(modules_to_submodules_map, curr_mod_name).end() ||
        pos_mod_inst_ast ==
            GetMapRef(modules_to_submodule_inst_ast_map, curr_mod_name).end())
      return false; // this instance name does not exists

    hier.push_back(std::make_pair(GetMap(name_module_map, curr_mod_name),
                                  pos_mod_inst_ast->second));

    curr_mod_name = pos_mod_decl->second; // move the module declaraion
  }
  *lowest_level = GetMap(name_module_map, curr_mod_name);
  return true;

} // get_hierarchy_from_full_name

// ------------------- signal info base ----------------------------------

unsigned range_to_width(ast_range* range, const std::string& full_name,
                        const VerilogAnalyzer* _ana, int width = -1) {
  if (range == NULL)
    return 1;
  ast_expression* left = range->upper;
  ast_expression* right = range->lower;

  VerilogConstantExprEval eval;
  VerilogConstantExprEval::param_def_hierarchy hierarchy;
  ast_module_declaration* mod;
  if (!(_ana->get_hierarchy_from_full_name(full_name, hierarchy, &mod))) {
    ILA_ERROR << full_name << " 's module is not found, cannot analyze width!";
    return 1;
  }
  eval.PopulateParameterDefByHierarchy(hierarchy, mod);

  unsigned lr = (unsigned)eval.Eval(left);
  unsigned rr = (unsigned)eval.Eval(right);
  unsigned analyzed_width = std::max(lr, rr) - std::min(lr, rr) + 1;

  // this will provide width when we cannot get width
  // or there is error, o.w. we will trust the width from
  if (width > 0) {
    ILA_WARN_IF(!eval.error())
        << "Overwriting width of signal: " << full_name << " to " << width
        << "(w=" << analyzed_width << " by analysis)";
    return width;
  }

  return analyzed_width;
}

SignalInfoPort::SignalInfoPort(
    ast_port_declaration* def, const std::string& full_name,
    VerilogAnalyzerBase::hierarchical_name_type tp,
    const std::map<std::string, int>* const width_info,
    const VerilogAnalyzer* _ana)
    : SignalInfoBase(Split(full_name, ".").back(), full_name,
                     range_to_width(def->range, full_name, _ana,
                                    width_info == NULL
                                        ? -1
                                        : (IN_p(full_name, width_info)
                                               ? width_info->at(full_name)
                                               : -1)),
                     tp, VerilogAnalyzer::Meta2Loc(def->meta)),
      _def(def) { // ILA_WARN_IF( def->range == NULL ) << "Verilog Analyzer:
                  // signal "<< full_name <<" has no range.";
  ILA_WARN_IF(_width == 0)
      << "Verilog Analyzer is not able to determine the width of signal:"
      << full_name << " @ " << _loc;
}

SignalInfoReg::SignalInfoReg(ast_reg_declaration* def,
                             const std::string& full_name,
                             VerilogAnalyzerBase::hierarchical_name_type tp,
                             const std::map<std::string, int>* const width_info,
                             const VerilogAnalyzer* _ana)
    : SignalInfoBase(Split(full_name, ".").back(), full_name,
                     range_to_width(def->range, full_name, _ana,
                                    width_info == NULL
                                        ? -1
                                        : (IN_p(full_name, width_info)
                                               ? width_info->at(full_name)
                                               : -1)),
                     tp, VerilogAnalyzer::Meta2Loc(def->meta)),
      _def(def) {
  ILA_WARN_IF(_width == 0)
      << "Verilog Analyzer is not able to determine the width of signal:"
      << full_name << " @ " << _loc;
}

SignalInfoWire::SignalInfoWire(
    ast_net_declaration* def, const std::string& full_name,
    VerilogAnalyzerBase::hierarchical_name_type tp,
    const std::map<std::string, int>* const width_info,
    const VerilogAnalyzer* _ana)
    : SignalInfoBase(Split(full_name, ".").back(), full_name,
                     range_to_width(def->range, full_name, _ana,
                                    width_info == NULL
                                        ? -1
                                        : (IN_p(full_name, width_info)
                                               ? width_info->at(full_name)
                                               : -1)),
                     tp, VerilogAnalyzer::Meta2Loc(def->meta)),
      _def(def) {
  ILA_WARN_IF(_width == 0)
      << "Verilog Analyzer is not able to determine the width of signal:"
      << full_name << " @ " << _loc;
}

}; // namespace ilang
