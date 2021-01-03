/// \file SMT AST
/// used to hold parsed ast, in this file
/// you should see some constructors/desctructors
/// smt_ast is meant to hold only data structures
/// also the ParseFromString should be interesting
/// --- Hongce Zhang (hongcez@princeton.edu)

#include <ilang/smt-inout/smt_ast.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

namespace ilang {
namespace smt {
// remember datatype could be defining other datatype ...

str_iterator::str_iterator(const std::string& _buf, size_t _pnt)
    : buf(_buf), pnt(_pnt) {}

str_iterator::str_iterator(const str_iterator& _) : buf(_.buf), pnt(_.pnt) {}

void str_iterator::jump_to_next(const std::string& c) {
  auto iter = buf.find(c, pnt);
  pnt = iter;
}

/// accept a token (expect and skip)
void str_iterator::accept(const std::string& s) {
  expect(s);
  skip_m(s);
}

bool str_iterator::is_end() const { return is_end(pnt); }

bool str_iterator::is_end(size_t pos) const {
  return pos >= buf.length() || pos == std::string::npos;
}

void str_iterator::expect(const std::string& c) const {
  auto substr = buf.substr(pnt, 10);
  ILA_ASSERT(buf.find(c, pnt) == pnt)
      << "Expect '" << c << "', but get '" << substr << "'";
}

/// returns the next non space pos
size_t str_iterator::next_non_space_pos(const std::string& s,
                                        size_t pos) const {
  if (is_end(pos))
    return pos;
  while (!is_end(pos)) {
    if (S_IN(buf.at(pos), s))
      pos++;
    else
      break;
  } // while
  return pos;
} // next_non_space_pos

std::string str_iterator::readline_no_eol() {
  if (is_end())
    return "";
  auto start = pnt;
  auto end = buf.length();
  while (!is_end()) {
    if (head() != '\n' && head() != '\r')
      pnt++;
    else {
      end = pnt;
      while (!is_end() && (head() == '\n' || head() == '\r'))
        ++pnt;
      break;
    }
  } // while
  return buf.substr(start, end - start);
}

size_t str_iterator::next_non_space_pos(const std::string& s) const {
  return next_non_space_pos(s, pnt);
}

size_t str_iterator::next(const std::string& s, size_t pos) const {
  return buf.find(s, pos);
}

/// get the closest occurance of s from current point
size_t str_iterator::next(const std::string& s) const { return next(s, pnt); }

/// skip some single charactor symbol
void str_iterator::skip(const std::string& s) { pnt = next_non_space_pos(s); }

/// skip a symbol (w. blank also)
void str_iterator::skip_m(const std::string& s) {
  skip(); // skip spaces
  if (buf.find(s, pnt) == pnt)
    pnt += s.length();
}

/// return the first
char str_iterator::head() const {
  ILA_ASSERT(!is_end()) << "string index out of range";
  return buf.at(pnt);
}
/// return the head_word (if it the end, then empty string)
std::string str_iterator::head_word(const std::string& s) const {
  if (is_end())
    return "";

  auto pos = next_non_space_pos(s); // from the next non-space pos
  auto start = pos;

  while (!is_end(pos)) {
    if (!S_IN(buf.at(pos), s))
      pos++;
    else
      break;
  } // while

  return buf.substr(start, pos - start);
} // head_word(const std::string &s )

std::string
str_iterator::accept_current_and_read_untill(const std::string& delimiter) {
  if (is_end())
    return "";
  if (is_end(pnt + 1))
    return "";

  auto start = pnt; // will include the current one
  auto pos = pnt + 1;

  while (!is_end(pos)) {
    if (!S_IN(buf.at(pos), delimiter))
      pos++;
    else {
      pos++; // will include the delimiter
      break;
    }
  } // while

  pnt = pos; // will set the pointer !!!
  return buf.substr(start, pos - start);
}

std::string str_iterator::read_till_pos(size_t pos) {
  std::string ret;
  if (pos >= buf.length())
    ret = buf.substr(pnt, std::string::npos);
  else
    ret = buf.substr(pnt, pos - pnt);
  pnt = pos;
  return ret;
}

std::string str_iterator::extract_untill_stack_empty(char push_symbol,
                                                     char pop_symbol) {
  skip();

  if (head() == push_symbol) {
    unsigned stack = 0;
    auto start = pnt;
    do {
      if (head() == push_symbol)
        stack++;
      else if (head() == pop_symbol) {
        ILA_ASSERT(stack > 0);
        stack--;
      }
      pnt++;
    } while (!(is_end() || stack == 0));
    ILA_ASSERT(stack == 0) << "Error reading from string, unmatched "
                           << push_symbol;
    return buf.substr(start, pnt - start);
  }                          // else
  ILA_ASSERT(head() != '|'); // not handling this case
  auto word = head_word(") \n\t\r");
  skip_m(word);
  return word;
}

std::string line_comment::toString() const { return comment; }

unsigned var_type::GetBoolBvWidth() const {
  if (is_bv())
    return _width;
  else if (is_bool())
    return 1;
  ILA_ASSERT(false) << "Does not support vlog width on type:" << _type;
  return 0;
}

/// test if it is array
bool var_type::is_array() const { return _type == tp::Array; }
/// test if it is bv
bool var_type::is_bv() const { return _type == tp::BV; }
/// test if it is bool
bool var_type::is_bool() const { return _type == tp::Bool; }
/// test if it is dataype
bool var_type::is_datatype() const { return _type == tp::Datatype; }

bool var_type::eqtype(const var_type& l, const var_type& r) {
  if (l.is_bool()) {
    if (r.is_bool())
      return true;
    return false;
  } else if (l.is_bv()) {
    if (r.is_bv() && l._width == r._width)
      return true;
    return false;
  } else if (l.is_array()) {
    return (r.is_array() && 
      l.data_width == r.data_width &&
      l.addr_width == r.addr_width);
  }
  // else datatype
  return l.module_name == r.module_name;
}
// ------------- CONSTRUCTOR ---------------- //
// default constructor
var_type::var_type() {}
// constructor for bitvector/bool
var_type::var_type(tp vtype, unsigned width, const std::string mod_name)
    : _type(vtype), _width(width), module_name(mod_name) {}
// constructor for array
var_type::var_type(tp vtype, unsigned addr_width, unsigned data_width, const std::string mod_name)
    : _type(vtype), addr_width(addr_width), data_width(data_width), module_name(mod_name) {}
// copy constructor
var_type::var_type(const var_type& vp)
    : _type(vp._type), _width(vp._width), module_name(vp.module_name) {}

var_type var_type::ParseFromString(str_iterator& it) {
  var_type ret;

  it.skip(); // skip spaces
  if (it.head() == '(') {
    // bitvector or array
    if (it.head_word() == "(Array") {
      it.accept("(Array");
      it.skip();
      it.accept("(_ BitVec ");
      auto addr_width = it.head_word(")");
      it.skip_m(addr_width);
      it.accept(")");

      it.skip();
      it.accept("(_ BitVec ");
      auto data_width = it.head_word(")");
      it.skip_m(data_width);
      it.accept(")");
      it.skip();
      it.accept(")");
      ret._type = tp::Array;
      ret.addr_width = StrToInt(addr_width);
      ret.data_width = StrToInt(data_width);
    } else {
      it.accept("(_ BitVec ");
      auto width = it.head_word(")");
      it.skip_m(width);
      it.accept(")");
      ret._type = tp::BV;
      ret._width = StrToInt(width);
    }
  } else if (it.head() == '|') {
    auto dtname = it.accept_current_and_read_untill("|");
    ret._type = tp::Datatype;
    ret.module_name = dtname.substr(1, dtname.length() - 4);
  } else {
    it.accept("Bool");
    ret._type = tp::Bool;
  }
  return ret;
} // ParseFromString

std::string var_type::toString() const {
  if (is_bool())
    return "Bool";
  else if (is_bv())
    return "(_ BitVec " + std::to_string(_width) + ")";
  else if (is_array())
    return "(Array (_ BitVec " + std::to_string(addr_width)+
           ") (_ BitVec " +  std::to_string(data_width) + "))";
  else if (is_datatype())
    return "|" + module_name + "_s|";
  ILA_ASSERT(false) << "Unknown type";
  return "";
}

std::string var_type::toString(const std::vector<var_type>& tp_vec) {
  std::vector<std::string> tp_str_vec;
  for (auto&& tp : tp_vec)
    tp_str_vec.push_back(tp.toString());
  return "(" + Join(tp_str_vec, " ") + ")";
}

arg_t::arg_t(const std::string& name, const var_type& type)
    : arg_name(name), arg_type(type) {}

arg_t arg_t::ParseFromString(str_iterator&) {
  ILA_ASSERT(false) << "not implemented.";
  return arg_t("", var_type());
}

std::string arg_t::toString() const {
  ILA_ERROR_IF(arg_type.is_datatype())
      << "Should not be used on unconverted datatype";
  return "(" + arg_name + " " + arg_type.toString() + ")";
}

std::string arg_t::toString(const std::vector<arg_t>& va) {
  std::vector<std::string> retv;
  for (auto&& v : va)
    retv.push_back(v.toString());
  return "(" + Join(retv, " ") + ")";
}

// something like this : (|counter__DOT__INC_is| Bool)
// or (|counter__DOT__INC#0| (_ BitVec 8)) ; \__COUNTER_start__n1
state_var_t
state_var_t::ParseFromString(str_iterator& it,
                             const std::string& default_module_name) {
  state_var_t ret;

  it.skip();
  it.accept("(");
  it.skip();

  std::string raw_name;
  if (it.head() == '|')
    raw_name = it.accept_current_and_read_untill("|");
  else {
    raw_name = it.head_word();
    it.accept(raw_name);
  }

  ILA_DLOG("Smt.Parse") << "Parse state:" << raw_name;
  ret._type = var_type::ParseFromString(it);
  it.skip();
  it.accept(")");

  ret.internal_name = raw_name;
  // if it is a module
  if (ret._type.is_datatype()) {
    // use the backup modulename (won't determine from inside)
    ret.module_name = default_module_name;
  } else {
    size_t pos_end = raw_name.find("#");
    size_t end_2 = raw_name.find("_is|");
    pos_end = pos_end < end_2 ? pos_end : end_2;
    ILA_ASSERT(pos_end != raw_name.npos);

    // to extract the module name here
    ret.module_name = raw_name.substr(1, pos_end - 1);
  }

  auto next_line_break = it.next("\n");
  next_line_break =
      it.next("\r") < next_line_break ? it.next("\r") : next_line_break;
  auto next_semicolon = it.next(";");

  if (next_line_break < next_semicolon) {
    // no comment
  } else { // from comment, extract state
    it.jump_to_next(";");
    std::string state_name;
    auto w = it.head_word("\n\r");
    if (StrStartsWith(w, "; $")) {
      it.accept("; $");
      state_name = it.readline_no_eol();
    } else if (StrStartsWith(w, "; {")) {
      it.accept("; ");
      state_name = it.readline_no_eol();
      state_name = ReplaceAll(state_name, "{ \\", "{");
      state_name = ReplaceAll(state_name, " \\", ",");
    } else if (StrStartsWith(w, "; \\")) {
      it.accept("; \\");
      state_name = it.readline_no_eol();
    } else {
      ILA_ASSERT(false) << "Unexpected:" << w;
    }
    // todo : read a line
    auto pos = state_name.find("\n");
    ILA_ASSERT(pos == std::string::npos);
    ret.verilog_name = state_name;
  }
  return ret;
} // ParseFromString

void func_def_t::ParseFromString(str_iterator& it, func_def_t& f) {
  it.skip(); // skip space
  it.accept("(define-fun ");
  it.skip();
  it.expect("|");
  f.func_name = it.accept_current_and_read_untill("|");
  /// initially we will just read the args_text
  it.skip();
  it.expect("((state "); // not reading in
  // auto text_end_pos = it.next("))");
  // f.args_text = it.read_till_pos(text_end_pos + 2);
  f.args_text = it.extract_untill_stack_empty('(', ')');
  f.ret_type = var_type::ParseFromString(it);
  it.skip();
  f.func_body = it.extract_untill_stack_empty('(', ')');

  it.jump_to_next(")");
  it.accept(")");
  // extra_comment
  auto next_line_break = it.next("\n");
  next_line_break =
      it.next("\r") < next_line_break ? it.next("\r") : next_line_break;
  auto next_semicolon = it.next(";");

  if (next_line_break < next_semicolon) {
    // no comment
  } else { // from comment, extract state
    it.jump_to_next(";");
    it.accept(";");
    f.extra_comment = it.readline_no_eol();
  } // handle the comment
  // compute the module name
  auto end_pos = f.func_name.find("|", 1);
  auto space_pos = f.func_name.find(" ", 1);
  auto bang_pos = f.func_name.find("#", 1);
  if (bang_pos == std::string::npos) {
    end_pos = end_pos < space_pos ? end_pos : space_pos;
    end_pos -= 2; // "_n " or "_u|" or similar
    f.func_module = f.func_name.substr(1, end_pos - 1);
  } else { // #nnn|
    f.func_module = f.func_name.substr(1, bang_pos - 1);
  }
} // ParseFromString

std::string func_def_t::toString() const {
  /// it also depends on whether this function has been re-written or not
  std::string ret = "(define-fun ";
  ret += func_name + " ";
  // args
  if (args.empty()) // not converted yet
    ret += args_text;
  else
    ret += arg_t::toString(args);

  ret += " " + ret_type.toString();
  ret += " " + func_body;
  ret += ")";

  if (!extra_comment.empty())
    ret += " ; " + extra_comment;

  return ret;
}

std::string ParseFromString(str_iterator& it, datatypes_t& dtype) {
  it.skip();
  it.accept("(declare-datatype ");
  std::string mod_name;
  if (it.head() == '|') {
    mod_name = it.accept_current_and_read_untill("|");
  } else {
    mod_name = it.head_word();
    it.skip_m(mod_name);
  }
  auto module_name =
      mod_name.substr(1, mod_name.length() - 3 - 1); // remove | _s|

  it.skip();
  it.accept("((" + mod_name.substr(0, mod_name.length() - 2) + "mk|");
  it.skip();
  std::vector<state_var_t>& l = dtype[module_name];
  while (it.head() == '(') {
    auto state_var_def =
        state_var_t::ParseFromString(it, module_name); // it could be datatype
    it.skip();
    // processing
    l.push_back(state_var_def);
  }
  it.accept(")))");
  return module_name;
}

void ParseFromString(str_iterator& it, smt_file& smt) {
  it.skip();
  while (!it.is_end()) {
    auto h = it.head_word();
    if (StrStartsWith(h, ";")) {
      std::shared_ptr<line_comment> ptr = std::make_shared<line_comment>();
      ptr->comment = it.readline_no_eol();
      smt.items.push_back(ptr);
      ILA_DLOG("Smt.Parse") << "Parsed comment:" << ptr->comment;

    } else if (h == "(declare-datatype") {
      smt.data_type_order.push_back(ParseFromString(it, smt.datatypes));
    } else if (h == "(define-fun") {
      std::shared_ptr<func_def_t> ptr = std::make_shared<func_def_t>();
      func_def_t::ParseFromString(it, *ptr);
      smt.items.push_back(ptr);
      ILA_DLOG("Smt.Parse") << "Parsed func:" << ptr->func_name;
    } else {
      ILA_ERROR << "Unrecognized:" << h << ". Stop.";
      break;
    }
    it.skip();
  }
} // ParseFromString

std::string smt_file::toString() const {
  ILA_WARN << "SMT gen will ignore datatypes."
           << " If not converted, this info will be lost.";
  std::string ret;
  for (auto&& smt : items) {
    auto line = smt->toString();
    ret += line + ((line.back() == '\n') ? "" : "\n");
  }
  return ret;
}

std::string convert_to_binary(unsigned v, unsigned w) {
  std::string ret;
  for (unsigned i = 0; i < w; ++i) {
    ret = std::to_string(v & 1) + ret;
    v = v >> 1;
  }
  ILA_ASSERT(v == 0);
  ILA_ASSERT(ret.size() == w);
  return "#b" + ret;
}

std::string convert_to_binary(const std::string& v, unsigned radix,
                              unsigned w) {
  ILA_ASSERT(radix == 2) << "Please fix this, future work!";

  std::string ret = v;
  if (v.length() == w)
    return "#b" + ret;
  if (v.length() < w) {
    for (unsigned i = 0; i < w - v.length(); i++)
      ret = "0" + ret;
    return "#b" + ret;
  }
  if (v.length() > w) {
    ILA_ERROR << "string : " << v << "(" << v.length()
              << ") cast to width:" << w;
    return "#b" + v.substr(v.length() - w);
  }
  return "";
}

}; // namespace smt
}; // namespace ilang