/// \file verilog_rfmap.cc Verilog Refinement Map Handling
///  First pass : JSON -> rfmap object

#include <ilang/rfmap-in/verilog_rfmap.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

#include <fstream>

#include "vexpparser/interpreter.h"
#include "nlohmann/json.hpp"

namespace ilang {
namespace rfmap {

// return npos if no comments in
static size_t find_comments(const std::string& line) {
  enum state_t { PLAIN, STR, LEFT } state, next_state;
  state = PLAIN;
  size_t ret = 0;
  for (const auto& c : line) {
    if (state == PLAIN) {
      if (c == '/')
        next_state = LEFT;
      else if (c == '"')
        next_state = STR;
      else
        next_state = PLAIN;
    } else if (state == STR) {
      if (c == '"' || c == '\n')
        next_state = PLAIN;
      // the '\n' case is in case we encounter some issue to find
      // the ending of a string
      else
        next_state = STR;
    } else if (state == LEFT) {
      if (c == '/') {
        ILA_CHECK(ret > 0);
        return ret - 1;
      } else
        next_state = PLAIN;
    }
    state = next_state;
    ++ret;
  }
  return std::string::npos;
}

// load_json and remove the comment, if succeed return true
static bool load_json(const std::string& fname, nlohmann::json& j) {
  std::ifstream fin(fname);

  if (!fin.is_open()) {
    ILA_ERROR << "Cannot read from file:" << fname;
    return false;
  }

  // remove the comments
  std::string contents;
  std::string line;
  while (std::getline(fin, line)) {
    auto comment_begin = find_comments(line);
    if (comment_begin != std::string::npos)
      contents += line.substr(0, comment_begin);
    else
      contents += line;
    contents += "\n";
  }
  j = nlohmann::json::parse(contents);
  return true;
} // load_json

static bool ParseRfExprErrFlag = false;

RfExpr VerilogRefinementMap::ParseRfExprFromString(const std::string& in) {
  Vexp::Interpreter intp;
  std::stringstream ss;
  ss << in;
  intp.switchInputStream(&ss);
  try {
    intp.parse();
  } catch (verilog_expr::VexpException& e) {
    return nullptr;
  }

  if (intp.HasError())
    return nullptr;
  return intp.GetAstRoot();
}

RfExpr ParseRfMapExpr(const std::string& in) {
  // TODO
  auto ret = VerilogRefinementMap::ParseRfExprFromString(in);
  ILA_ERROR_IF(ret == nullptr) << "Parsing string: `" << in << "` failed.";
  if (ret == nullptr)
    ParseRfExprErrFlag = true;
  return ret;
}

RfExpr ParseRfMapExprJson(nlohmann::json& in) {
  if(in.is_null())
    return ParseRfMapExpr("1'b1 == 1'b1"); // true
  return ParseRfMapExpr(in.get<std::string>());
}

bool JsonRfmapParseCond(SingleVarMap& cond_map, nlohmann::json& json_array) {
  assert(json_array.is_array());
  bool succ = true;
  for (const auto& idx_array_pair : json_array.items()) {
    succ = succ && idx_array_pair.value().is_array() &&
           idx_array_pair.value().size() == 2;
    if (!idx_array_pair.value().is_array() ||
        idx_array_pair.value().size() != 2)
      continue;

    RfExpr cond, mapping;
    for (const auto& index_map_pair : idx_array_pair.value().items()) {
      if (index_map_pair.key() == "0") {
        cond = ParseRfMapExprJson(index_map_pair.value());
      } else if (index_map_pair.key() == "1") {
        mapping = ParseRfMapExprJson(index_map_pair.value());
      }
    }
    assert(cond.get() != nullptr && mapping.get() != nullptr);
    cond_map.cond_map.push_back(std::make_pair(cond, mapping));
  } // for each array_element
  return succ;
} // JsonRfmapParseCond

bool JsonRfmapParseSingleOrCond(SingleVarMap& sc_map,
                                nlohmann::json& json_single_or_array) {
  if (json_single_or_array.is_array())
    return JsonRfmapParseCond(sc_map, json_single_or_array);
  assert(json_single_or_array.is_string());
  sc_map.single_map = ParseRfMapExprJson(json_single_or_array);
  return sc_map.single_map != nullptr;
}

bool JsonRfmapParseMem(ExternalMemPortMap& mem_rfmap,
                       nlohmann::json& json_obj) {
  assert(json_obj.is_object());

  bool succ = true;

  if (json_obj.contains("wen"))
    succ =
        succ && JsonRfmapParseSingleOrCond(mem_rfmap.wen_map, json_obj["wen"]);
  if (json_obj.contains("waddr"))
    succ = succ &&
           JsonRfmapParseSingleOrCond(mem_rfmap.waddr_map, json_obj["waddr"]);
  if (json_obj.contains("wdata"))
    succ = succ &&
           JsonRfmapParseSingleOrCond(mem_rfmap.wdata_map, json_obj["wdata"]);
  if (json_obj.contains("ren"))
    succ =
        succ && JsonRfmapParseSingleOrCond(mem_rfmap.ren_map, json_obj["ren"]);
  if (json_obj.contains("raddr"))
    succ = succ &&
           JsonRfmapParseSingleOrCond(mem_rfmap.raddr_map, json_obj["raddr"]);
  if (json_obj.contains("rdata"))
    succ = succ &&
           JsonRfmapParseSingleOrCond(mem_rfmap.rdata_map, json_obj["rdata"]);

  mem_rfmap.rport_mapped = json_obj.contains("ren");
  mem_rfmap.wport_mapped = json_obj.contains("wen");
  if (mem_rfmap.rport_mapped)
    succ = succ && json_obj.contains("raddr") && json_obj.contains("rdata");
  if (mem_rfmap.wport_mapped)
    succ = succ && json_obj.contains("waddr") && json_obj.contains("wdata");

  return (succ && (json_obj.contains("ren") || json_obj.contains("wen")));
} // JsonRfmapParseMem

char inline to_space(char in) { return ((in == '-' || in == '_') ? ' ' : in); }

bool SectionNameRelaxedMatch(const std::string& in1, const std::string& in2) {
  if (in1.length() != in2.length())
    return false;
  for (size_t idx = 0; idx < in1.length(); ++idx) {
    if (tolower(in1.at(idx)) != tolower(in2.at(idx)) &&
        (to_space(in1.at(idx)) != to_space(in2.at(idx))))
      return false;
  }
  return true;
} // SectionNameRelaxedMatch

nlohmann::json* GetJsonSection(nlohmann::json& in,
                               const std::set<std::string>& sec_names,
                               bool allow_dup = false) {
  nlohmann::json* ret = NULL;
  if (!in.is_object())
    return NULL;
  for (const auto& n : sec_names) {
    for (const auto& n_v : in.items()) {
      if (SectionNameRelaxedMatch(n_v.key(), n)) {

        ILA_ERROR_IF(ret) << "Section " << n << " is duplicated.";
        if (ret && !allow_dup)
          return NULL;

        ret = &(in.at(n_v.key()));
      }
    }
  }
  return ret;
} // GetJsonSection

bool JsonRfmapParseSingleSequence(OneBitSignalSequence& out,
                                  nlohmann::json& seq) {

  auto get_multipler = [](const std::string& in) -> unsigned {
    if (in.length() < 2)
      return 0;
    if (in.at(0) != '*')
      return 0;
    auto sub = in.substr(1);
    return StrToInt(sub, 10);
  };

  if (!seq.is_array())
    return false;
  OneBitSignalSequence tmp_seq;
  bool the_last_encountered = false;
  for (auto& elem : seq.items()) {
    if (the_last_encountered)
      return false;
    auto& e = elem.value();
    if (!(e.is_number_unsigned() || e.is_array() || e.is_string()))
      return false;
    if (e.is_number_unsigned())
      tmp_seq.push_back(e.get<unsigned>());
    else if (e.is_array()) {
      if (!JsonRfmapParseSingleSequence(tmp_seq, e))
        return false;
    } else if (e.is_string()) {
      // duplicate the tmp_sequence
      auto mult = e.get<std::string>();
      unsigned n_count = get_multipler(mult);
      unsigned length = tmp_seq.size();
      if (length == 0 || n_count == 0)
        return false;
      for (unsigned iter = 0; iter < n_count; ++iter) {
        for (unsigned idx = 0; idx < length; ++idx) {
          tmp_seq.push_back(tmp_seq.at(idx));
        }
      }
      the_last_encountered = true;
    } // if mult
  }   // end of for
  out.insert(out.end(), tmp_seq.begin(), tmp_seq.end());
  return true;
} // JsonRfmapParseSingleSequence

bool JsonRfmapParseSequence(std::map<std::string, OneBitSignalSequence>& out,
                            nlohmann::json& in) {
  if (!in.is_object())
    return false;

  for (const auto& n_seq_pair : in.items()) {
    const auto& name = n_seq_pair.key();
    auto& seq = n_seq_pair.value();
    if (!seq.is_array())
      return false;
    if (IN(name, out))
      return false;
    auto insert_ret = out.insert(std::make_pair(name, OneBitSignalSequence()));
    //   [pos (name, seq) , bool]
    auto& seq_ref = insert_ret.first->second;
    bool succ = JsonRfmapParseSingleSequence(seq_ref, seq);
    if (!succ)
      return false;
  }
  return true;
} // JsonRfmapParseSequence

bool JsonRfmapParseClockFactor(
    std::map<std::string, ClockSpecification::factor>& out,
    nlohmann::json& in) {
  if (!in.is_object())
    return false;
  for (const auto& n_obj_pair : in.items()) {
    const auto& n = n_obj_pair.key();
    auto& obj = n_obj_pair.value();
    if (IN(n, out))
      return false;
    if (!obj.is_object())
      return false;
    ClockSpecification::factor f;
    auto* high = GetJsonSection(obj, {"high"});
    auto* low = GetJsonSection(obj, {"low"});
    auto* offset = GetJsonSection(obj, {"offset"});
    if (!(high && low))
      return false;

    if (high) {
      if (!high->is_number_unsigned())
        return false;
      f.high = high->get<unsigned>();
    }

    if (low) {
      if (!low->is_number_unsigned())
        return false;
      f.low = low->get<unsigned>();
    }

    if (offset) {
      if (!offset->is_number_unsigned())
        return false;
      f.offset = offset->get<unsigned>();
    }
    out[n] = f;
  } // end for
  return true;
} // JsonRfmapParseClockFactor

unsigned gcd(unsigned a, unsigned b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

// least common multiplier
unsigned lcm(const std::vector<unsigned>& in) {
  unsigned ans = in.at(0);
  for (size_t i = 1; i < in.size(); ++i) {
    ans = ((in.at(i) * ans) / gcd(in.at(i), ans));
  }
  return ans;
}

bool JsonRfmapConvertFactorToSeq(
    const std::map<std::string, ClockSpecification::factor>& in,
    std::map<std::string, OneBitSignalSequence>& out) {
  if (in.size() == 0)
    return false;
  std::map<std::string, OneBitSignalSequence> seq_no_dup;
  std::vector<unsigned> cycles;
  for (const auto& n_factor_pair : in) {
    const auto& n = n_factor_pair.first;
    const auto& factor_obj = n_factor_pair.second;
    auto n_cycle = factor_obj.high + factor_obj.low;
    cycles.push_back(n_cycle);
    seq_no_dup[n].resize(factor_obj.high, true);
    seq_no_dup[n].insert(seq_no_dup.at(n).end(), factor_obj.low, false);
  } // for each factor

  auto len = lcm(cycles);
  for (const auto& n_factor_pair : in) {
    const auto& n = n_factor_pair.first;
    const auto& factor_obj = n_factor_pair.second;
    auto n_cycle = factor_obj.high + factor_obj.low;
    assert(len % n_cycle == 0);
    auto n_copy = len / n_cycle;
    auto offset = factor_obj.offset;

    unsigned idx = offset;
    unsigned idx_copy = 0;
    while (!(idx == offset && idx_copy == n_copy)) {

      out[n].push_back(seq_no_dup[n][idx]);

      if (idx + 1 == n_cycle)
        ++idx_copy;
      idx = (idx + 1) % n_cycle;
    }
    assert(out[n].size() == len);
  }
  return true;
} // JsonRfmapConvertFactorToSeq

#define ERRIF(cond, s)                                                         \
  do {                                                                         \
    if (cond)                                                                  \
      return (s);                                                              \
  } while (0)
#define ENSURE(cond, s) ERRIF(!(cond), (s))
std::string JsonRfMapParseVarDefs(
    std::map<std::string, GeneralVerilogMonitor::VarDef>& var_defs,
    nlohmann::json& def_field) {

  ENSURE(def_field.is_array(),
         "`defs` field should be list of [[name, width, type], ...]");
  for (auto& one_def : def_field) {
    ENSURE(one_def.is_array(),
           "`defs` field should be list of [[name, width, type], ...]");
    auto pos = one_def.begin();

    ENSURE(pos != one_def.end() && pos->is_string(),
           "`defs` field should be list of [[name, width, type], ...]");
    auto var_name = pos->get<std::string>();
    ENSURE(!IN(var_name, var_defs), "var " + var_name + " has been defined");

    ++pos;
    ENSURE(pos != one_def.end() && pos->is_number_unsigned(),
           "`defs` field should be list of [[name, width, type], ...]");
    var_defs[var_name].width = pos->get<unsigned>();
    ERRIF(var_defs[var_name].width == 0,
          "Definition of " + var_name + " has 0 width");

    ++pos;
    ENSURE(pos != one_def.end() && pos->is_string(),
           "`defs` field should be list of [[name, width, type], ...]");
    auto tp = pos->get<std::string>();
    ENSURE(SectionNameRelaxedMatch(tp, "reg") ||
               SectionNameRelaxedMatch(tp, "wire"),
           "`defs` field should be list of [name, width, type (wire/reg)]");

    var_defs[var_name].type =
        SectionNameRelaxedMatch(tp, "reg")
            ? GeneralVerilogMonitor::VarDef::var_type::REG
            : GeneralVerilogMonitor::VarDef::var_type::WIRE;
    ++pos;
    ENSURE(pos == one_def.end(), "`defs` expects 3-element tuple");
  }
  return "";
}

std::string JsonRfmapParsePhaseTracker(PhaseTracker& tracker,
                                       nlohmann::json& monitor,
                                       const std::string& tracker_name) {
  auto* event_alias = GetJsonSection(monitor, {"event-alias", "signal-alias"});
  auto* rules = GetJsonSection(monitor, {"rules"});
  auto* aux_var = GetJsonSection(monitor, {"aux-var"});
  ERRIF(rules == NULL, "`phase tracker` needs `rules` field");
  if (event_alias) {
    ERRIF(!event_alias->is_object(), "`event-alias` expects map:name->expr");
    for (auto& name_val_pair : event_alias->items()) {
      const auto& vn = name_val_pair.key();
      ERRIF(IN(vn, tracker.event_alias), "`" + vn + "` is already defined.");
      ERRIF(!name_val_pair.value().is_string(),
            "expecting string in event-alias");
      tracker.event_alias.emplace(vn,
                                  ParseRfMapExprJson(name_val_pair.value()));
    }
  }

  if (aux_var) {
    auto errmsg = JsonRfMapParseVarDefs(tracker.var_defs, *aux_var);
    ENSURE(errmsg.empty(), errmsg);
  }

  assert(rules);
  ENSURE(rules->is_array(), "`rules` field should be list of objects");
  size_t sidx = 0;
  for (auto& stage : *rules) {
    ENSURE(stage.is_object(), "`rules` field should be list of objects");
    auto* enter = GetJsonSection(stage, {"enter"});
    auto* exit = GetJsonSection(stage, {"exit"});
    auto* stage_name = GetJsonSection(stage, {"name"});
    ENSURE(enter || exit,
           "`rules` object must contain `enter` or `exit` events");
    if(enter) {
      ENSURE(enter->is_object() || enter->is_string(),
            "`enter` should contain `event` and (optional) `action`");
    }
    if(exit) {
      ENSURE(exit->is_object() || exit->is_string(),
            "`exit` should contain `event` and (optional) `action`");
    }
    
    nlohmann::json* enter_event  = NULL; 
    nlohmann::json* enter_action = NULL;
    nlohmann::json* exit_event   = NULL;  
    nlohmann::json* exit_action  = NULL; 

    if (enter) {
      if(enter->is_object()) {
        enter_event  = GetJsonSection(*enter, {"event"});
        enter_action = GetJsonSection(*enter, {"action"});
      } else { // is string
        enter_event = enter;
      }
    }
    if (exit) {
      if(exit->is_object()) {
        exit_event   = GetJsonSection(*exit, {"event"});
        exit_action  = GetJsonSection(*exit, {"action"});
      } else
        exit_event = exit;
    }

    ERRIF( enter_event == NULL , "the current stage has no `entering` event, please check!" );
    ERRIF( (enter_event == NULL && enter_action != NULL), "if you specify `enter->action`, you must provide `enter->event`." );
    ERRIF( (exit_event == NULL && exit_action != NULL), "if you specify `exit->action`, you must provide `exit->event`." );
    
    ENSURE(enter_event,
           "`enter` should contain `event` and (optional) `action`");
    ENSURE(enter_event->is_string(), "`enter` -> `event` should be a string");
    if(exit) {
      ENSURE(exit_event, "`exit` should contain `event` and (optional) `action`");
      ENSURE(exit_event->is_string(), "`exit` -> `event` should be a string");
    }

    tracker.rules.push_back(PhaseTracker::Rule());
    auto& ws = tracker.rules.back();
    if (stage_name) {
      ENSURE(stage_name->is_string(), "`name` of a phase should be string");
      ws.stage_name = tracker_name + "_" + stage_name->get<std::string>();
    } else {
      ws.stage_name = tracker_name + "_stage" + std::to_string(sidx++);
    }
    
    ws.enter_rule = ParseRfMapExprJson(*enter_event);
    if(exit_event) {
      ws.exit_rule = ParseRfMapExprJson(*exit_event);
    }
 
    if (enter_action) {
      ENSURE(enter_action->is_string(), "`action` should be a string");
      auto action_str = enter_action->get<std::string>();
      auto actions = Split(action_str, ";");
      for (auto& a : actions) {
        StrTrim(a);
        if (a.empty())
          continue;
        auto pos = a.find("<=");
        ERRIF(pos == std::string::npos,
              "`action` should be `LHS <= RHS ; ...`");
        auto LHS = a.substr(0, pos);
        auto RHS = a.substr(pos + 2);
        PhaseTracker::Assignment assign;
        StrTrim(LHS); // you don't need to trim RHS (parsing will help)
        assign.LHS = LHS;
        assign.RHS = ParseRfMapExpr(RHS);
        ws.enter_action.push_back(assign);
      } // for each action
    }   // if (enter_action)

    if (exit_action) {
      ENSURE(exit_action->is_string(), "`action` should be a string");
      auto action_str = exit_action->get<std::string>();
      auto actions = Split(action_str, ";");
      for (auto& a : actions) {
        StrTrim(a);
        if (a.empty())
          continue;
        auto pos = a.find("<=");
        ERRIF(pos == std::string::npos,
              "`action` should be `LHS <= RHS ; ...`");
        auto LHS = a.substr(0, pos);
        auto RHS = a.substr(pos + 2);
        PhaseTracker::Assignment assign;
        StrTrim(LHS);
        assign.LHS = LHS;
        assign.RHS = ParseRfMapExpr(RHS);
        ws.exit_action.push_back(assign);
      } // for each action
    }   // exit_action
  }     // for each stage

  return "";
}

std::string JsonRfmapParseValueRecorder(ValueRecorder& tracker,
                                        nlohmann::json& monitor) {
  auto* cond = GetJsonSection(monitor, {"condition", "cond"});
  auto* val = GetJsonSection(monitor, {"value", "val"});
  auto* width = GetJsonSection(monitor, {"width", "w"});
  ENSURE(cond && cond->is_string(), "`cond` field should be a string");
  ENSURE(val && val->is_string(), "`val` field should be a string");
  tracker.condition = ParseRfMapExprJson(*cond);
  tracker.value = ParseRfMapExprJson(*val);
  if (width && width->is_number_unsigned()) {
    tracker.width = width->get<unsigned>();
  } // if you don't write width or use a string then it is 0
  else
    tracker.width = 0;
  return "";
}

#undef ENSURE
#undef ERRIF

// ------------------------------------------------------------------------------

#define ERRIF(cond, str)                                                       \
  do {                                                                         \
    ILA_ERROR_IF(cond) << str;                                                 \
    if (cond)                                                                  \
      return;                                                                  \
  } while (false)
#define ENSURE(cond, str) ERRIF(!(cond), str)

VerilogRefinementMap::VerilogRefinementMap(
    const std::string& varmap_json_file,
    const std::string& instcond_json_file) {

  ParseRfExprErrFlag = false;

  // this is the first pass
  nlohmann::json rf_vmap;
  nlohmann::json rf_cond;
  load_json(varmap_json_file, rf_vmap);
  load_json(instcond_json_file, rf_cond);
  { // deprecated warning messages
    nlohmann::json* model_name = GetJsonSection(
        rf_vmap, {"model", "models", "model name", "model names"});
    ERRIF(model_name != NULL,
          "model names are not supported. Use `ILA` and `RTL`.");
    nlohmann::json* instmap =
        GetJsonSection(rf_vmap, {"instruction mapping", "instruction map"});
    ERRIF(instmap != NULL, "instruction mapping is no longer supported");
    nlohmann::json* interface =
        GetJsonSection(rf_vmap, {"interface mapping", "interface map"});
    ERRIF(interface != NULL, "interface mapping is no longer supported. Use "
                             "`input mapping` and `RTL interface connection`");
  }

  // now json to -> Rfmap
  { // state mapping
    nlohmann::json* state_mapping =
        GetJsonSection(rf_vmap, {"state mapping", "state map"});
    ERRIF(state_mapping == NULL, "state var mapping is duplicated or missing");
    for (auto& i : state_mapping->items()) {
      IlaVarMapping svmp;
      auto sname = i.key(); // ila state name
      if (i.value().is_null()) {
        svmp.type = IlaVarMapping::StateVarMapType::SINGLE;
        svmp.single_map.single_map = ParseRfMapExprJson(i.value()); // 1'b1 == 1'b1
      }
      else if (i.value().is_string()) {
        svmp.type = IlaVarMapping::StateVarMapType::SINGLE;
        svmp.single_map.single_map = ParseRfMapExprJson(i.value());
      } else if (i.value().is_object()) {
        // External Mem
        svmp.type = IlaVarMapping::StateVarMapType::EXTERNMEM;
        svmp.externmem_map.push_back(ExternalMemPortMap());

        auto& extmem_ports = i.value();
        bool succ = JsonRfmapParseMem(svmp.externmem_map.back(), extmem_ports);
        ENSURE(succ, "fail to parse external memory map");

      } else if (i.value().is_array()) {
        ERRIF(i.value().empty(), ("Empty list for " + sname));
        bool are_memports = false;
        if (i.value().begin()->is_object()) {
          are_memports = true;
        } else if (i.value().begin()->is_array()) {
          are_memports = false;
        } else
          ERRIF(true, "Expecting array of list or objects for " + sname);

        if (are_memports) {
          svmp.type = IlaVarMapping::StateVarMapType::EXTERNMEM;
          for (const auto& idx_obj_pair : i.value().items()) {
            ENSURE(idx_obj_pair.value().is_object(),
                   "Expecting array of objects for " + sname);

            svmp.externmem_map.push_back(ExternalMemPortMap());

            auto& extmem_ports = idx_obj_pair.value();
            bool succ =
                JsonRfmapParseMem(svmp.externmem_map.back(), extmem_ports);
            ENSURE(succ, "fail to parse external memory map");
          }
        } else {
          svmp.type = IlaVarMapping::StateVarMapType::CONDITIONAL;
          JsonRfmapParseCond(svmp.single_map, i.value());
        }

      } // if array of array / array of object
      ILA_ERROR_IF(IN(sname, ila_state_var_map))
          << "ILA state var : " << sname << " has duplicated mapping";
      ila_state_var_map.emplace(sname, svmp);
    } // for each state
  }   // state mapping

  { // input mapping
    // TODO: add things here
    nlohmann::json* input_mapping =
        GetJsonSection(rf_vmap, {"input mapping", "input map"});
    if (input_mapping) {
      for (auto& i : input_mapping->items()) {
        IlaVarMapping ivmp;
        auto sname = i.key(); // ila state name
        ERRIF(i.value().is_object(), "input array is not supported");
        if (i.value().is_string()) {
          ivmp.type = IlaVarMapping::StateVarMapType::SINGLE;
          ivmp.single_map.single_map = ParseRfMapExprJson(i.value());
        } else if (i.value().is_array()) {
          ERRIF(i.value().empty(), ("Empty list for " + sname));
          ENSURE(i.value().begin()->is_array(), "Expect array of array");
          ivmp.type = IlaVarMapping::StateVarMapType::CONDITIONAL;
          JsonRfmapParseCond(ivmp.single_map, i.value());

        } // if array of array / array of object
        ILA_ERROR_IF(IN(sname, ila_input_var_map))
            << "ILA state var : " << sname << " has duplicated mapping";
        ila_input_var_map.emplace(sname, ivmp);
      } // for each input var
    }
  } // input mapping

  { // interface map
    nlohmann::json* rtl_if_map = GetJsonSection(
        rf_vmap, {"RTL interface connection", "RTL interface connect"});
    ERRIF(rtl_if_map == nullptr,
          "`RTL interface connection` is duplicated or missing");
    nlohmann::json* clock_domains =
        GetJsonSection(*rtl_if_map, {"CLOCK"}, true);
    nlohmann::json* reset_list = GetJsonSection(*rtl_if_map, {"RESET"}, true);
    nlohmann::json* nreset_list = GetJsonSection(*rtl_if_map, {"NRESET"}, true);
    nlohmann::json* reset_domains =
        GetJsonSection(*rtl_if_map, {"CUSTOMRESET"}, true);
    nlohmann::json* input_ports = GetJsonSection(*rtl_if_map, 
      {"INPUT", "INPORT", "INPUTS", "INPORTS", "INPUT-PORT", "INPUT-PORTS"}, false);
    if (clock_domains) {
      ENSURE(clock_domains->is_array() || clock_domains->is_string() ||
                 clock_domains->is_object(),
             "clock specification in RTL interface connection should be "
             "string/list of string/map:string->list(string)");
      if (clock_domains->is_string())
        rtl_interface_connection.clock_domain_defs["default"].insert(
            clock_domains->get<std::string>());
      else if (clock_domains->is_array()) {
        auto clk_pins = clock_domains->get<std::vector<std::string>>();
        for (const auto& clk_pin : clk_pins)
          rtl_interface_connection.clock_domain_defs["default"].insert(clk_pin);
      } else { // is_object
        for (const auto& n_l_pair : clock_domains->items()) {
          const auto& domain_name = n_l_pair.key();
          std::set<std::string> pins;
          ENSURE(n_l_pair.value().is_string() || n_l_pair.value().is_array(),
                 "expect string/array in RTL interface connection");
          if (n_l_pair.value().is_string()) {
            pins.insert(n_l_pair.value().get<std::string>());
          } else {
            auto pin_vec = n_l_pair.value().get<std::vector<std::string>>();
            pins = std::set<std::string>(pin_vec.begin(), pin_vec.end());
          }
          rtl_interface_connection.clock_domain_defs.emplace(domain_name, pins);
        }
      } // if is_object
    }   // if (clock_domain)

    if (reset_list) {
      if (reset_list->is_string())
        rtl_interface_connection.reset_pins.insert(
            reset_list->get<std::string>());
      else if (reset_list->is_array()) {
        auto reset_pins = reset_list->get<std::vector<std::string>>();
        for (const auto& pin : reset_pins)
          rtl_interface_connection.reset_pins.insert(pin);
      }
    }

    if (nreset_list) {
      if (nreset_list->is_string())
        rtl_interface_connection.nreset_pins.insert(
            nreset_list->get<std::string>());
      else if (nreset_list->is_array()) {
        auto nreset_pins = nreset_list->get<std::vector<std::string>>();
        for (const auto& pin : nreset_pins)
          rtl_interface_connection.nreset_pins.insert(pin);
      }
    }
    if (reset_domains) {
      ENSURE(reset_domains->is_array() || reset_domains->is_string() ||
                 reset_domains->is_object(),
             "clock specification in RTL interface connection should be "
             "string/list of string/map:string->list(string)");
      if (reset_domains->is_string())
        rtl_interface_connection.custom_reset_domain_defs["default"].push_back(
            reset_domains->get<std::string>());
      else if (reset_domains->is_array()) {
        rtl_interface_connection.custom_reset_domain_defs.insert(
            std::make_pair(std::string("default"),
                           reset_domains->get<std::vector<std::string>>()));
      } else { // is_object
        for (const auto& n_l_pair : reset_domains->items()) {
          const auto& domain_name = n_l_pair.key();
          std::vector<std::string> pins;
          ENSURE(n_l_pair.value().is_string() || n_l_pair.value().is_array(),
                 "expect string/array in RTL interface connection");
          if (n_l_pair.value().is_string()) {
            pins.push_back(n_l_pair.value().get<std::string>());
          } else {
            pins = n_l_pair.value().get<std::vector<std::string>>();
          }
          rtl_interface_connection.custom_reset_domain_defs.emplace(domain_name,
                                                                    pins);
        }
      } // if is_object
    }   // if reset custom domain
    if(input_ports) {
      ENSURE(input_ports->is_object(), "Expecting `input-port` to be a map of string->string");
      for (const auto& n_l_pair : input_ports->items()) {
        ENSURE(n_l_pair.value().is_string(), "Expecting `input-port` to be a map of string->string");
        auto rfe = ParseRfMapExprJson( n_l_pair.value() );
        auto port_name = n_l_pair.key();
        ENSURE(rtl_interface_connection.input_port_connection.find(port_name) == rtl_interface_connection.input_port_connection.end(),
          ("Error: port name " + port_name + " has been assigned already") );
        rtl_interface_connection.input_port_connection.emplace(port_name, rfe);        
      }
    }
  }     // interface map

  { // reset section parsing
    nlohmann::json* reset_section = GetJsonSection(rf_vmap, {"reset"});
    if (reset_section) {
      nlohmann::json* initial_state =
          GetJsonSection(*reset_section, {"initial-state"});
      nlohmann::json* cycle = GetJsonSection(*reset_section, {"cycles"});
      nlohmann::json* customreset =
          GetJsonSection(*reset_section, {"custom-seq"});
      if (initial_state) {
        ENSURE(initial_state->is_object(),
               "initial state should be map:name->value");
        for (const auto& n_v_pair : initial_state->items()) {
          const auto& sn = n_v_pair.key();
          RfExpr val = ParseRfMapExprJson(n_v_pair.value());
          ERRIF(IN(sn, reset_specification.initial_state),
                "duplicated sname for initial-state in reset");
          reset_specification.initial_state[sn] = val;
        }
      } // initial state

      if (cycle) {
        ENSURE(cycle->is_number_unsigned(),
               "cycles in reset should be unsigned integer");
        reset_specification.reset_cycle = cycle->get<unsigned>();
      } else
        reset_specification.reset_cycle = 1;

      if (customreset) {
        bool succ = JsonRfmapParseSequence(
            reset_specification.custom_reset_sequence, *customreset);
        ENSURE(succ, "Custom Reset Sequence error!");
      }

    } // if reset_section
  }   // reset

  { // clock section
    nlohmann::json* clock_section = GetJsonSection(rf_vmap, {"clock"});
    if (clock_section) {
      nlohmann::json* factor_section =
          GetJsonSection(*clock_section, {"factor"}, true);
      nlohmann::json* custom_section =
          GetJsonSection(*clock_section, {"custom"}, true);
      ENSURE(factor_section || custom_section,
             "clock section must contain factor/custom field");
      ERRIF(factor_section && custom_section,
            "Cannot have both `factor` and `custom` section");
      if (custom_section) {
        nlohmann::json* length = GetJsonSection(*custom_section, {"length"});
        ENSURE(length, "`length` field is needed for custom section");
        ENSURE(length->is_number_unsigned(),
               "length field must be unsigned integer");
        clock_specification.gcm_period = length->get<unsigned>();
        nlohmann::json* clocks = GetJsonSection(*custom_section, {"clocks"});
        ENSURE(clocks, "`clocks` field is needed for custom section");
        bool succ = JsonRfmapParseSequence(
            clock_specification.custom_clock_sequence, *clocks);
        ENSURE(succ, "Custom Clock error!");
      } else {
        // factor_section
        bool succ = JsonRfmapParseClockFactor(
            clock_specification.custom_clock_factor, *factor_section);
        succ = succ && JsonRfmapConvertFactorToSeq(
                           clock_specification.custom_clock_factor,
                           clock_specification.custom_clock_sequence);
        ENSURE(succ, "Custom clock sequence error");
      }
    } // if clock section
  }   // clock

  { // uf section
    nlohmann::json* func_section = GetJsonSection(
        rf_vmap, {"functions", "function", "uf", "ufs",
                  "uninterpreted function", "uninterpreted functions"});
    if (func_section) {
      ENSURE(func_section->is_object(),
             "Expect `functions` to be map:name->list of invocation ");
      for (auto& n_invocation_pair : func_section->items()) {
        const auto& n = n_invocation_pair.key();
        auto& invocations = n_invocation_pair.value();
        auto ret = uf_application.insert(
            std::make_pair(n, UninterpretedFunctionApplication()));
        auto& apply_obj =
            ret.first->second; // point to the UninterpretedFunctionApplication
                               // object
        ENSURE(invocations.is_array(),
               "Expect `functions` to be map:name->list of invocation");
        for (auto& elem : invocations) {
          ENSURE(
              elem.is_object(),
              "Expect `functions` to be map:name->list of invocation(object)");
          auto* result = GetJsonSection(elem, {"result"});
          auto* arg = GetJsonSection(elem, {"arg", "args"});
          ENSURE(result,
                 "Expect invocation object has `result` and `arg` field");
          ENSURE(result->is_string(),
                 "Expect type string in `result` field of invocation object");
          if(arg) {
          ENSURE(
              arg->is_array(),
              "Expect type list(string) in `arg` field of invocation object");
          }
          apply_obj.func_applications.push_back(
              UninterpretedFunctionApplication::Apply());
          auto& curr_invocation = apply_obj.func_applications.back();
          curr_invocation.result_map = ParseRfMapExprJson(*result);
          if(arg) {
            std::vector<std::string> argList =
                arg->get<std::vector<std::string>>();
            for (const auto& arg : argList)
              curr_invocation.arg_map.push_back(ParseRfMapExpr(arg));
          }
        }
      } // for each invocation
    }   // if func_section
  }     // uf section
  {     // additional mapping & assumptions
    {
      nlohmann::json* mapping_control =
          GetJsonSection(rf_vmap, {"mapping control"});
      ERRIF(mapping_control != NULL,
            "please rename `mapping control` to `additional mapping`");
    }

    nlohmann::json* additonal_section =
        GetJsonSection(rf_vmap, {"additional mapping"});
    if (additonal_section) {
      ENSURE(additonal_section->is_array(),
             "`additional mapping` section should be a list of string");
      for (auto& pstr : *additonal_section) {
        ENSURE(pstr.is_string(),
               "`additional mapping` section should be a list of string");
        additional_mapping.push_back(ParseRfMapExprJson(pstr));
      }
    } // if additional mapping

    nlohmann::json* assumption_section =
        GetJsonSection(rf_vmap, {"assumptions"});
    if (assumption_section) {
      ENSURE(assumption_section->is_array(),
             "`assumptions` section should be a list of string");
      for (auto& pstr : *assumption_section) {
        ENSURE(pstr.is_string(),
               "`assumptions` section should be a list of string");
        assumptions.push_back(ParseRfMapExprJson(pstr));
      }
    }
  } // additional mapping & assumptions

  { // phase tracker, value recorder, customized ones
    nlohmann::json* monitor_section = GetJsonSection(rf_vmap, {"monitor", "monitors"});
    if (monitor_section) {
      ENSURE(monitor_section->is_object(), "`monitor` section should be a map");
      for (auto& name_monitor_pair : monitor_section->items()) {
        auto name = name_monitor_pair.key();

        ERRIF(IN(name, customized_monitor),
              "monitor `" + name + "` has been defined.");
        ERRIF(IN(name, phase_tracker),
              "monitor `" + name + "` has been defined.");
        ERRIF(IN(name, value_recorder),
              "monitor `" + name + "` has been defined.");
        ERRIF(IN(name, direct_aux_vars),
              "monitor `" + name + "` has been defined.");

        auto& monitor = name_monitor_pair.value();
        if (monitor.is_string()) {
          direct_aux_vars.emplace(name, AuxVar(name));
          auto ret = ParseRfMapExpr(monitor.get<std::string>());
          ILA_NOT_NULL(ret);
          direct_aux_vars.at(name).val = ret;
        } else {
          auto* template_field = GetJsonSection(monitor, {"template"});
          if (template_field) {
            ENSURE(template_field->is_string(),
                  "`template` field should be string");
            auto template_name = template_field->get<std::string>();
            if (SectionNameRelaxedMatch(template_name, "phase tracker") ||
                SectionNameRelaxedMatch(template_name, "stage tracker") ) {
              phase_tracker.emplace(name, PhaseTracker());
              std::string errmsg = JsonRfmapParsePhaseTracker(
                  phase_tracker.at(name), monitor, name);
              ENSURE(errmsg.empty(), errmsg);
            } else if (SectionNameRelaxedMatch(template_name, "value recorder")) {
              value_recorder.emplace(name, ValueRecorder());
              std::string errmsg =
                  JsonRfmapParseValueRecorder(value_recorder.at(name), monitor);
              ENSURE(errmsg.empty(), errmsg);
            } else {
              ERRIF(true,
                    "template name `" + template_name + "` is not recognized.");
            }
            // end if has template field
          } else {
            customized_monitor.emplace(name, GeneralVerilogMonitor());
            auto& mnt_ref = customized_monitor.at(name);
            { // inline verilog
              // has no template
              auto* verilog_field = GetJsonSection(monitor, {"verilog"});
              auto* verilog_file_field =
                  GetJsonSection(monitor, {"verilog-from-file"});
              auto* keep_inv = GetJsonSection(
                  monitor, {"keep-for-invariant", "keep-for-invariants"});

              ERRIF(
                  verilog_field && verilog_file_field,
                  "`verilog` or `verilog-from-file` fields are mutual exclusive");
              if (keep_inv) {
                ENSURE(keep_inv->is_boolean(),
                      "`keep-for-invariant` should be Boolean");
                mnt_ref.keep_for_invariant = keep_inv->get<bool>();
              }

              if (verilog_field) {
                if (verilog_field->is_string()) {
                  mnt_ref.verilog_inline = verilog_field->get<std::string>();
                } else {
                  ENSURE(verilog_field->is_array(),
                        "`verilog` field should be a list of string");
                  for (auto& ps : *verilog_field) {
                    ENSURE(ps.is_string(),
                          "`verilog` field should be a list of string");
                    mnt_ref.verilog_inline += ps.get<std::string>() + "\n";
                  }
                }
              } else if (verilog_file_field) {
                ENSURE(verilog_file_field->is_string(),
                      "`verilog-from-file` expects a string (file name)");
                auto fname = verilog_file_field->get<std::string>();
                std::ifstream fin(fname);
                ENSURE(fin.is_open(), "Cannot read from " + fname);
                {
                  std::stringstream buffer;
                  buffer << fin.rdbuf();
                  mnt_ref.verilog_inline = buffer.str();
                }
              } // verilog_file_field : from file
            }   // inline verilog

            { // append verilog outside the module
              // has no template
              auto* verilog_field = GetJsonSection(monitor, {"append-verilog"});
              auto* verilog_file_field =
                  GetJsonSection(monitor, {"append-verilog-from-file"});

              ERRIF(verilog_field && verilog_file_field,
                    "`append-verilog` or `append-verilog-from-file` fields are "
                    "mutual exclusive");

              if (verilog_field) {
                if (verilog_field->is_string()) {
                  mnt_ref.verilog_append =
                      verilog_field->get<std::string>() + "\n";
                } else {
                  ENSURE(verilog_field->is_array(),
                        "`append-verilog` field should be a list of string");
                  for (auto& ps : *verilog_field) {
                    ENSURE(ps.is_string(),
                          "`append-verilog` field should be a list of string");
                    mnt_ref.verilog_append += ps.get<std::string>() + "\n";
                  }
                }
              } else if (verilog_file_field) {
                ENSURE(verilog_file_field->is_string(),
                      "`append-verilog-from-file` expects a string (file name)");
                auto fname = verilog_file_field->get<std::string>();
                std::ifstream fin(fname);
                ENSURE(fin.is_open(), "Cannot read from " + fname);
                {
                  std::stringstream buffer;
                  buffer << fin.rdbuf();
                  mnt_ref.verilog_append = buffer.str() + "\n";
                }
              } // append-verilog_file_field : from file
            }   // verilog_append verilog

            auto* ref_field = GetJsonSection(monitor, {"refs"});
            if (ref_field) { // refs
              ENSURE(ref_field->is_array(),
                    "`refs` field should be a list of string");
              for (auto& p : *ref_field) {
                ENSURE(p.is_string(), "`refs` field should be a list of string");
                auto var_name = p.get<std::string>();
                ILA_WARN_IF(IN(var_name, mnt_ref.var_uses))
                    << "`" + var_name + "` has been declared already in `refs`";
                mnt_ref.var_uses.insert(p.get<std::string>());
              }
            } // if ref_field

            auto* def_field = GetJsonSection(monitor, {"defs"});
            if (def_field) { // defs
              auto err_msg = JsonRfMapParseVarDefs(mnt_ref.var_defs, *def_field);
              ENSURE(err_msg.empty(), err_msg);
            } // if def_field
          }   // else if it is verilog monitor (general)
        } // end of if is_string()--else       
      }     // for each monitor
    }       // if has monitor field
  }         // monitor block

  // ---------------- inst_cond ------------------------ //
  {
    auto* instrs = GetJsonSection(rf_cond, {"instructions"});
    auto* invariants = GetJsonSection(rf_cond, {"global invariants"});
    if (instrs) {
      ENSURE(instrs->is_array(), "`instructions` should be array of object");
      for (auto& instr : *instrs) {
        ENSURE(instr.is_object(), "`instructions` should be array of object");
        auto* instr_name = GetJsonSection(instr, {"instruction"});
        auto* ready_bnd = GetJsonSection(instr, {"ready-bound"});
        auto* ready_signal = GetJsonSection(instr, {"ready-signal"});
        auto* max_bound = GetJsonSection(instr, {"max-bound"});
        auto* start_condition = GetJsonSection(instr, {"start-condition"});
        ENSURE(instr_name && instr_name->is_string(),
               "`instruction` field should be a string");
        ERRIF(ready_bnd && ready_signal,
              "`ready bound` and `ready signal` are mutual exclusive");
        ENSURE(ready_bnd || ready_signal,
               "You must specify one of `ready bound` and `ready signal`");
        auto iname = instr_name->get<std::string>();
        inst_complete_cond.emplace(iname, InstructionCompleteCondition());
        auto& ws = inst_complete_cond.at(iname);

        ws.instruction_name = iname;
        if (ready_bnd) {
          ENSURE(ready_bnd->is_number_unsigned(),
                 "`ready-bound` should be an unsigned number");
          ws.ready_bound = ready_bnd->get<unsigned>();
          ws.type = InstructionCompleteCondition::ConditionType::BOUND;
        } else { // ready_signal
          ENSURE(ready_signal->is_string(),
                 "`ready-signal` should be a string");
          ws.ready_signal = ParseRfMapExprJson(*ready_signal);
          ws.type = InstructionCompleteCondition::ConditionType::SIGNAL;
        }

        if (max_bound) {
          ENSURE(max_bound->is_number_unsigned(),
                 "`max_bound` should be an unsigned number");
          ws.max_bound = max_bound->get<unsigned>();
        } else
          ws.max_bound = 0;

        if (start_condition) {
          if (start_condition->is_string()) {
            ws.start_condition.push_back(ParseRfMapExprJson(*start_condition));
          } else {
            ENSURE(start_condition->is_array(),
                   "`start_condition` should be a string or array of strings");
            for (auto& cond : *start_condition) {
              ENSURE(
                  cond.is_string(),
                  "`start_condition` should be a string or array of strings");
              ws.start_condition.push_back(ParseRfMapExprJson(cond));
            }
          } // end if start condition is string
        }   // end if start condition
      }     // for each instr`
    }       // if instrs

    if (invariants) {
      ENSURE(invariants->is_array(),
             "`global-invariants` should be an array of strings");
      for (auto& inv : *invariants) {
        ENSURE(inv.is_string(),
               "`global-invariants` should be an array of strings");
        global_invariants.push_back(ParseRfMapExprJson(inv));
      }
    } // if invariant
  }   // inst cond

  // ---------------- supplementary_info ------------------------ //
  {
    auto* annotation = GetJsonSection(rf_vmap, {"annotation", "annotations"});
    if (annotation) {
      auto* width_anno = GetJsonSection(*annotation, {"width"});
      if (width_anno && width_anno->is_object()) {
        for (auto&& nw : width_anno->items()) {
          width_info.insert(std::make_pair(nw.key(), nw.value().get<int>()));
          ERRIF(nw.value().get<int>() <= 0 , (nw.key() + "'s width <=0"));
        }
      }
      auto* range_anno = GetJsonSection(*annotation, {"range"});
      if (range_anno && range_anno->is_object()) {
        for (auto&& nw : range_anno->items()) {
          range_info.insert(std::make_pair(nw.key(), nw.value().get<int>()));
          ERRIF(nw.value().get<int>() <= 0 , (nw.key() + "'s range <=0"));
        }
      }
    } // end of annotation
  }   // end of supplementary_info

  ERRIF(ParseRfExprErrFlag, "error occur in refinement expression parsing");

} // VerilogRefinementMap::VerilogRefinementMap

bool is_valid_id_name(const std::string& in) {
  if (in.empty())
    return false;
  if (!isalpha(in.at(0)) && in.at(0) != '_')
    return false;
  for (size_t idx = 1; idx < in.size(); ++idx)
    if (!isalnum(in.at(idx)))
      return false;
  return true;
}

#undef ERRIF
#undef ENSURE
#define ERRIF(cond, str)                                                       \
  do {                                                                         \
    ILA_ERROR_IF(cond) << str;                                                 \
    if (cond)                                                                  \
      return false;                                                            \
  } while (false)
#define ENSURE(cond, str) ERRIF(!(cond), str)

bool VerilogRefinementMap::SelfCheckField() const {
  // check module name
  ERRIF(ParseRfExprErrFlag, "Error in parsing refinement expressions");

  for (const auto& n_map : ila_state_var_map) {
    ENSURE(!(n_map.second.externmem_map.empty()) ||
               (n_map.second.single_map.single_map.get() != nullptr) ||
               !(n_map.second.single_map.cond_map.empty()),
           "state var map cannot be empty for " + n_map.first);
    ERRIF(!(n_map.second.externmem_map.empty()) &&
              (n_map.second.single_map.single_map.get() != nullptr),
          "duplicate state var map for " + n_map.first);
    ERRIF(!(n_map.second.single_map.cond_map.empty()) &&
              (n_map.second.single_map.single_map.get() != nullptr),
          "duplicate state var map for " + n_map.first);
    ERRIF(!(n_map.second.externmem_map.empty()) &&
              (!n_map.second.single_map.cond_map.empty()),
          "duplicate state var map for " + n_map.first);
  }

  std::set<std::string> custom_reset_seq_name;
  std::set<std::string> custom_clock_seq_name;
  { // for reset, valid name, domain names are defs
    unsigned seq_len = 0;
    for (const auto& n_seq : reset_specification.custom_reset_sequence) {
      ERRIF(!is_valid_id_name(n_seq.first),
            "Custom reset sequence name " << n_seq.first << " is not valid");
      ERRIF(IN(n_seq.first, custom_reset_seq_name),
            "reset sequence name " + n_seq.first +
                "has been used multiple times");

      custom_reset_seq_name.insert(n_seq.first);

      ERRIF(n_seq.second.size() == 0,
            "Empty reset sequence for " + n_seq.first);
      if (seq_len == 0)
        seq_len = n_seq.second.size();
      ERRIF(seq_len != reset_specification.reset_cycle,
            "Customized reset sequence does not match the cycle count");

      ERRIF(seq_len != n_seq.second.size(),
            "Reset sequence should be of same length");
    }
  }

  { // for clock, valid name, check no empty sequence, sequence of the same
    // length
    unsigned seq_len = 0;
    for (const auto& n_seq : clock_specification.custom_clock_sequence) {
      ERRIF(!is_valid_id_name(n_seq.first),
            "Custom clock sequence name " << n_seq.first << " is not valid");
      ERRIF(IN(n_seq.first, custom_clock_seq_name),
            "clock sequence name " + n_seq.first +
                "has been used multiple times");

      custom_clock_seq_name.insert(n_seq.first);

      ERRIF(n_seq.second.size() == 0,
            "Empty clock sequence for " + n_seq.first);
      if (seq_len == 0)
        seq_len = n_seq.second.size();
      ERRIF(seq_len != clock_specification.gcm_period,
            "Customized clock does not match the specified length requirement");

      ERRIF(seq_len != n_seq.second.size(),
            "Clock sequence should be of same length");
    }
  }

  {
    for (const auto& clkd : custom_clock_seq_name) {
      ERRIF(IN(clkd, custom_reset_seq_name),
            "Name " + clkd + " has been used multiple times");
    }
    for (const auto& rstd : custom_reset_seq_name) {
      ERRIF(IN(rstd, custom_clock_seq_name),
            "Name " + rstd + " has been used multiple times");
    }
  }

  { // for each interface check domain names are good
    for (const auto& n_clks : rtl_interface_connection.clock_domain_defs) {
      ERRIF(!IN(n_clks.first, custom_clock_seq_name),
            "clock domain " + n_clks.first + " is not found");
    }
    for (const auto& n_rsts :
         rtl_interface_connection.custom_reset_domain_defs) {
      ERRIF(!IN(n_rsts.first, custom_reset_seq_name),
            "reset domain " + n_rsts.first + " is not found");
    }
  }

  // check trackers, recorders, monitor names are okay

  { // GeneralVerilogMonitor, for ids are okay, no bad names
    std::set<std::string> var_def_names;
    for (const auto& n_st : phase_tracker) {
      // const auto & phase_tracker_name = n_st.first;
      for (const auto& var_def : n_st.second.event_alias) {
        ERRIF(!is_valid_id_name(var_def.first),
              "Monitor name " + var_def.first + " is not valid");
        ERRIF(IN(var_def.first, var_def_names),
              "Variable " + n_st.first + " has been defined already");
        var_def_names.insert(var_def.first);
      }
      for (const auto& var_def : n_st.second.var_defs) {
        ERRIF(!is_valid_id_name(var_def.first),
              "Monitor name " + var_def.first + " is not valid");
        ERRIF(IN(var_def.first, var_def_names),
              "Variable " + n_st.first + " has been defined already");
        var_def_names.insert(var_def.first);
      }
      for (const auto& st : n_st.second.rules) {
        ERRIF(!is_valid_id_name(st.stage_name),
            "stage name " + st.stage_name + " is not valid");
        
        ERRIF(IN(st.stage_name, var_def_names),
              "Variable " + n_st.first + " has been defined already");
        var_def_names.insert(st.stage_name);
      }
    }
    
    for (const auto& n_expr : direct_aux_vars) {
      ERRIF(!is_valid_id_name(n_expr.first),
            "Monitor name " + n_expr.first + " is not valid");
      ERRIF(IN(n_expr.first, var_def_names),
            "Monitor name " + n_expr.first + " has been used");
      var_def_names.insert(n_expr.first);
    }

    for (const auto& n_st : value_recorder) {
      ERRIF(!is_valid_id_name(n_st.first),
            "Monitor name " + n_st.first + " is not valid");
      ERRIF(IN(n_st.first, var_def_names),
            "Monitor name " + n_st.first + " has been used");
      var_def_names.insert(n_st.first);
    }
    for (const auto& n_st : customized_monitor) {
      ERRIF(!is_valid_id_name(n_st.first),
            "Monitor name " + n_st.first + " is not valid");
      ERRIF(IN(n_st.first, var_def_names),
            "Monitor name " + n_st.first + " has been used");
      var_def_names.insert(n_st.first);

      for (const auto& var_def : n_st.second.var_defs) {
        ERRIF(IN(var_def.first, var_def_names),
              "Variable " + n_st.first + " has been defined already");
        var_def_names.insert(var_def.first);
      }
    }
  }
  return true;
  // no need to check for inst_cond
} // bool VerilogRefinementMap::SelfCheck() const

#undef ERRIF
#undef ENSURE

} // namespace rfmap
} // namespace ilang
