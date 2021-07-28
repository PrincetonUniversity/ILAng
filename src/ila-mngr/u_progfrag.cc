/// \file
/// Utilities for handling program fragments

#include <ilang/ila-mngr/u_progfrag.h>

#include <sstream>

#include <ilang/ila-mngr/u_abs_knob.h>

namespace ilang {

namespace pfast {

  bool operator==(const ProgramFragment& a, const ProgramFragment& b) {
    // [TODO] check == operator on unordered sets
    return (a.params == b.params) && (a.body == b.body);
  }

  std::string to_string(const Stmt& s) { 
    PrettyPrinter pp {};
    std::visit(pp, s);
    return pp.str();
  }

  std::string to_string(const ProgramFragment& pf) { 
    PrettyPrinter pp {};
    pp(pf);
    return pp.str();
  }

  std::string to_string(const Block& b) { 
    PrettyPrinter pp {};
    pp(b);
    return pp.str(); 
  }

  void PrettyPrinter::operator()(const ProgramFragment& pf) {
    buf_ << reserved_word("main") << "(";
    bool first = true;
    for (const auto& param : pf.params) {
      if (first) first = false;
      else buf_ << ", ";
      buf_ << param;
    }
    buf_ << ") ";

    this->indent_ = 0;
    (*this)(pf.body);
    
    buf_ << "\n";
  }

  void PrettyPrinter::operator()(const Block& b) {
    buf_ << "{\n";
    this->indent_ += 2;
    for (int i = 0; i != b.size(); ++i) {
      buf_ << indent_str();
      std::visit(*this, b[i]);
      buf_ << "\n";
    }
    this->indent_ -= 2;
    buf_ << indent_str() << "}";
  }

  void PrettyPrinter::operator()(const Assert& a) {
    buf_ << reserved_word("assert") << " " << a.assertion;
  }

  void PrettyPrinter::operator()(const Assume& a) {
    buf_ << reserved_word("assert") << " " << a.assumption;
  }

  void PrettyPrinter::operator()(const Call& c) {
    buf_ << reserved_word("call") << " " << c.instr->name().str();
    if (c.input_constraint) {
      buf_ << " where " << c.input_constraint;
    }
  }

  void PrettyPrinter::operator()(const Update& u) {
    buf_ << reserved_word("update");
    bool first = true;
    for (const auto& [x, v] : u) {
      buf_ << (first ? " " : ", ")
           << x << " = " << v;
      first = false;
    }
  }

  void PrettyPrinter::operator()(const While& w) {
    buf_ << reserved_word("while") << " " 
         << w.loop_condition << " ";
    (*this)(w.body);
  }

  std::string PrettyPrinter::reserved_word(const std::string& word) { 
    std::string res = word;
    for (auto & c: res) c = toupper(c);
    return res;
  }

  std::string PrettyPrinter::indent_str() { return std::string(this->indent_, ' '); }

}

}