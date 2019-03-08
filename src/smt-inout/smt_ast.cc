/// \file SMT AST
/// used to hold parsed ast, in this file
/// you should see some constructors/desctructors
/// smt_ast is meant to hold only data structures
/// also the ParseFromString should be interesting
/// --- Hongce Zhang (hongcez@princeton.edu)

#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/smt-inout/smt_ast.h>

namespace ilang {

// remember datatype could be defining other datatype ...

str_iterator::str_iterator(const std::string &_buf, unsigned _pnt) :
  buf(_buf), pnt(_pnt) { }

str_iterator::str_iterator(const str_iterator &_) :
  buf(_.buf), pnt(_.pnt) { }

void str_iterator::jump_to_next(const std::string &c) {
  auto iter = buf.find(c, pnt);
  pnt = iter;
}

/// accept a token (expect and skip)
void str_iterator::accept(const std::string &s) {
  expect(s);
  skip_m(s);
}


bool str_iterator::is_end() const { return is_end(pnt); }

bool str_iterator::is_end(unsigned pos) const {
  return pos >= buf.length() or pos == std::string::npos;
}


void str_iterator::expect(const std::string &c) const {
  ILA_ASSERT( buf.find(c,pnt) == pnt ) << "Expect '"<< c 
    << "', but get " << head_word();
}


/// returns the next non space pos
unsigned str_iterator::next_non_space_pos(const std::string &s, unsigned pos) const {
  if (is_end(pos)) return pos;
  while (!is_end(pos)) {
    if( S_IN( buf.at(pos) , s ) )
      pos ++;
    else
      break;
  } // while
  return pos;
} // next_non_space_pos


unsigned str_iterator::next_non_space_pos(const std::string &s) const {
  return next_non_space_pos(s, pnt); 
}

unsigned str_iterator::next(const std::string & s, unsigned pos) const {
  return buf.find(s,pos);
}

/// get the closest occurance of s from current point
unsigned str_iterator::next(const std::string & s) const {
  return next(s, pnt);
}

/// skip some single charactor symbol
void str_iterator::skip(const std::string &s) {
  pnt = next_non_space_pos(s);
}

/// skip a symbol (w. blank also)
void str_iterator::skip_m(const std::string &s) {
  skip(); // skip spaces
  if(buf.find(s,pnt) == pnt)
    pnt += s.length();
}

/// return the first 
char str_iterator::head() const {
  ILA_ASSERT(not is_end()) << "string index out of range";
  return buf.at(pnt);
}
/// return the head_word (if it the end, then empty string)
std::string str_iterator::head_word(const std::string &s ) const {
  if (is_end())
    return "";

  auto pos = next_non_space_pos(s); // from the next non-space pos
  auto start = pos;

  while (!is_end(pos)) {
    if( not S_IN( buf.at(pos) , s ) )
      pos ++;
    else
      break;
  } // while
  
  return buf.substr( start, pos - start );
} // head_word(const std::string &s ) 


std::string str_iterator::accept_current_and_read_untill(const std::string & delimiter) {
  if(is_end()) return "";
  if(is_end(pnt + 1 )) return "";

  auto start = pnt; // will include the current one
  auto pos = pnt + 1;

  while (!is_end(pos)) {
    if( not S_IN( buf.at(pos) , delimiter ) )
      pos ++;
    else {
      pos ++; // will include the delimiter
      break;
    }
  } // while
  
  pnt = pos; // will set the pointer !!!
  return buf.substr( start, pos - start );
}

std::string str_iterator::read_till_pos(unsigned pos) {
  std::string ret ;
  if (pos >= buf.length())
    ret = buf.substr(pnt,std::string::npos);
  else
    ret = buf.substr(pnt, pos - pnt);
  pnt = pos;
  return ret;
}


std::string str_iterator::extract_untill_stack_empty(char push_symbol, char pop_symbol) {
  skip();
  unsigned stack = 0;
  auto start = pnt;
  do {
    if(head() == push_symbol)
      stack ++;
    else if(head() == pop_symbol)
      stack --;
    pnt ++ ;
  } while(! ( is_end() || stack == 0) );
  ILA_ERROR_IF(stack != 0) << "Error reading from string, unmatched " << push_symbol;
  return buf.substr(start, pnt - start);
}

std::string line_comment::toString() const {
  return comment;
}

var_type var_type::ParseFromString(str_iterator & it) {
  var_type ret;

  it.skip(); // skip spaces
  if(it.head() == '(') {
    // bitvector
    it.accept("(_ Bitvec ");
    auto width = it.head_word(")");
    it.skip_m(width);
    it.accept(")");
    ret._type = tp::BV;
    ret._width = StrToInt(width);
  }
  else if(it.head() == '|') {
    auto dtname = it.accept_current_and_read_untill("|");
    ret._type = tp::Datatype;
    ret.module_name = dtname.substr(1, dtname.length() - 4);
  }
  else {
    it.accept("Bool");
    ret._type = tp::Bool;
  }
  return ret;
} // ParseFromString

std::string var_type::ToString() const {
  if(_type == tp::Bool) return "Bool";
  else if(_type == tp::BV)
    return "(_ BitVec " + std::to_string(_width) +")";
  else if(_type == tp::Datatype)
    return "|" + module_name + "_s|";
  ILA_ASSERT(false) << "Unknown type";
  return "";
}

// something like this : (|counter__DOT__INC_is| Bool)
// or (|counter__DOT__INC#0| (_ BitVec 8)) ; \__COUNTER_start__n1
state_var_t state_var_t::ParseFromString(str_iterator &it) {
  state_var_t ret;

  it.skip();
  it.accept("(");
  auto raw_name = it.head_word();
  it.skip_m(raw_name);
  ret._type = var_type::ParseFromString(it);
  it.skip();
  it.accept(")");

  ret.internal_name = raw_name;
  unsigned pos_end = raw_name.find("#");
  if(pos_end == raw_name.npos)
    pos_end = raw_name.find("_is|");
  ILA_ASSERT(pos_end != raw_name.npos);

  // to extract the module name here
  ret.module_name = raw_name.substr(1,pos_end-1);

  auto next_line_break = it.next("\n");
  next_line_break = it.next("\r") < next_line_break ? it.next("\r") : next_line_break;
  auto next_semicolon = it.next(";");

  if( next_line_break < next_semicolon ) {
    // no comment
  }
  else { // from comment, extract state
    it.jump_to_next(";");
    it.accept("; \\");
    auto state_name = it.head_word();
    it.skip_m(state_name);
    ret.verilog_name = state_name;
  }
  return ret;
} // ParseFromString

void func_def_t::ParseFromString(str_iterator & it, func_def_t & f) {
  it.skip(); // skip space
  it.accept("(define-fun ");
  it.skip();
  it.expect("|");
  f.func_name = it.accept_current_and_read_untill("|");
  /// initially we will just read the args_text
  it.skip();
  it.expect("((state "); // not reading in
  auto text_end_pos = it.next("))");
  f.args_text = it.read_till_pos(text_end_pos + 2);
  f.ret_type = var_type::ParseFromString(it);
  it.skip();
  f.func_body = it.extract_untill_stack_empty('(',')');

  it.jump_to_next(")");
  it.accept(")");
  // extra_comment
  auto next_line_break = it.next("\n");
  next_line_break = it.next("\r") < next_line_break ? it.next("\r") : next_line_break;
  auto next_semicolon = it.next(";");

  if( next_line_break < next_semicolon ) {
    // no comment
  }
  else { // from comment, extract state
    it.jump_to_next(";");
    it.accept(";");
    f.extra_comment = it.accept_current_and_read_untill("\n\r");
  } // handle the comment
  // compute the module name
  auto end_pos = f.func_name.find("|",1);
  auto space_pos = f.func_name.find(" ",1);
  end_pos = end_pos < space_pos ? end_pos : space_pos;
  end_pos -= 3; // "_n " or "_u|" or similar
  f.func_module = f.func_name.substr(1, end_pos-1);
} // ParseFromString

std::string func_def_t::toString() const {
  /// it also depends on whether this function has been re-written or not
  std::string ret = "(define-fun ";
  ret += func_name + " ";
  // args
  if ( this->args.empty() ) { // not converted yet
    ret += args_text;
  }
  else {
    ret += "(";
    std::vector<std::string> vec_arg;
    for (auto && arg : args)
      vec_arg.push_back("(" + arg.arg_name + " " + arg.arg_type.ToString() + ")");
    ret += Join(vec_arg," ");
    ret += ")";
  }
  ret += " " + ret_type.ToString();
  ret += " " + func_body;
  ret += ")";

  return ret;
}

void ParseFromString(str_iterator & it, datatypes_t & dtype) {
 it.skip();
 it.accept("(declare-datatype ");
 auto mod_name = it.head_word();
 auto module_name = mod_name.substr(1,mod_name.length()-3-1); // remove | _s|
 it.skip();
 it.accept( "((" + mod_name.substr(0,mod_name.length()-2) + "mk|" );
 it.skip();
 std::vector<state_var_t> & l = dtype[module_name];
 while( it.head() == '(') {
   auto state_var_def = state_var_t::ParseFromString(it); // it could be datatype
   it.skip();
   // processing
   l.push_back(state_var_def);
 }
 it.accept(")))");
}

void ParseFromString(str_iterator & it, smt_file & smt) {
  it.skip();
  while(not it.is_end()) {
    auto h = it.head_word();
    if (h == ";") {
      std::shared_ptr<line_comment> ptr =
        std::make_shared<line_comment>();
      ptr->comment = it.accept_current_and_read_untill("\n\r");
      smt.items.push_back(ptr);
    }
    else if (h == "(declare-datatype") {
      ParseFromString(it,smt.datatypes);
    }
    else if (h == "(declare-fun") {
      std::shared_ptr<func_def_t> ptr =
        std::make_shared<func_def_t>();
      func_def_t::ParseFromString(it,*ptr);
      smt.items.push_back(ptr);
    }
    else {
      ILA_ERROR << "Unrecognized:" << h <<". Ignored.";
    }
  }
} // ParseFromString

std::string smt_file::toString() const {
  ILA_WARN << "SMT gen will ignore datatypes."
    << " If not converted, this info will be lost.";
  std::string ret;
  for (auto && smt : items) {
    auto line = smt->toString();
    ret += line + 
      ( (line.back() == '\n') ? "" : "\n" );
  }
  return ret;
}

}; // namespace ilang