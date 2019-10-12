#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/smt-inout/yosys_smt_parser.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

struct name_value_width_t {
  std::string varname;
  std::string value;
  size_t width;
};

// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

void parseCex(std::istringstream & fin, std::vector<name_value_width_t> & var_val_list,
  const ilang::smt::datatypes_t & datatypes,
  const ilang::smt::data_type_order_t & datatype_order
  ) {
  std::string line;
  
  std::vector<const std::vector<ilang::smt::state_var_t> *> hierarchy_ptr; // stack 
  std::vector<std::string> hierarchy_names;
  std::vector<unsigned> hierarchy_idxs;

  std::vector<ilang::smt::state_var_t> topmodule;
  ilang::smt::state_var_t top_level_var;
  top_level_var._type._type= ilang::smt::var_type::Datatype;
  top_level_var._type.module_name="wrapper";
  topmodule.push_back(top_level_var);
  //hierarchy_ptr.push_back(&topmodule);
  //hierarchy_names.push_back("wrapper");

  const ilang::smt::state_var_t * p = &(topmodule[0]);
  const std::vector<ilang::smt::state_var_t> * current_datatype = &topmodule;
  unsigned idx = 0;


  while(fin>>line) {
    trim(line);
    bool has_l_parath = false;
    if (line.find('(') == 0) {
      ILA_ASSERT(p->_type.is_datatype()) << "Expecting datatype on (";
      auto pos = line.rfind("_mk");
      ILA_ASSERT(pos != line.npos);
      auto cex_module = line.substr(1,pos-1);
      const auto & modname = p->_type.module_name;
      ILA_ASSERT(cex_module == modname) << "cex mod : " << cex_module << " / smt-ast mod : " << modname;
      ILA_ASSERT(IN(modname, datatypes)) << "Module : " << modname << " not found in smt-ast";
      const std::vector<ilang::smt::state_var_t> * new_datatype_ptr = &(datatypes.at(modname));
      hierarchy_ptr.push_back(current_datatype);
      current_datatype = new_datatype_ptr;
      hierarchy_names.push_back(modname);
      hierarchy_idxs.push_back(idx);
      p = &((*new_datatype_ptr)[0]);
      idx = 0;
      has_l_parath = true;
      std::cout << "mod:" <<  modname << std::endl;
      continue;
    }
    if (line.find(')') != 0) {
      ILA_ASSERT(p) << "Expect end of datatype, get " << line;
      ILA_ASSERT (! p->_type.is_datatype())
       << "Expect datatype of module : " << p->_type.module_name << ", get " << line ;
      name_value_width_t var;
      var.varname = ilang::Join(hierarchy_names,".") + "." + (p->verilog_name.empty() ? p->internal_name  : p->verilog_name );
      var.value = ilang::ReplaceAll(line,")","");
      var.width = p->_type.GetBoolBvWidth();
      var_val_list.push_back(var);
      idx ++;
      // const std::vector<ilang::smt::state_var_t> * old_datatype_ptr = hierarchy_ptr.back();
      p = idx >= current_datatype->size() ? NULL : &(current_datatype->at(idx));
    }

    if (line.find(')') != line.npos) {
      ILA_ASSERT(!has_l_parath) << "() together!";
      ILA_ASSERT(p == NULL) << ") premature, expect " << p->internal_name << "/" << p->module_name << "/" << p->verilog_name <<"/" << p->_type.toString();
      const std::vector<ilang::smt::state_var_t> * old_datatype_ptr = hierarchy_ptr.back();
      current_datatype = old_datatype_ptr;
      hierarchy_ptr.pop_back();
      std::cout << "pop mod:" <<  hierarchy_names.back() << std::endl;
      hierarchy_names.pop_back();
      idx = hierarchy_idxs.back() + 1;
      hierarchy_idxs.pop_back();
      p = idx >= old_datatype_ptr->size() ? NULL : &(old_datatype_ptr->at(idx));
      if (hierarchy_ptr.empty()) {
        ILA_ASSERT(hierarchy_names.empty());
        break;
      }
    } // end of )

  } // end of while
  ILA_ASSERT(hierarchy_ptr.empty());
  ILA_ASSERT(hierarchy_names.empty());
}


int main(int argc, char ** argv) {
  if (argc < 3) {
    std::cout << "Usage : " << argv[0] << " smt2-file cex"<< std::endl;
    return 1;
  }
  std::ifstream smtfin (argv[1]);
  if (!smtfin.is_open()) {
    std::cout << "unable to read : " << argv[1] << std::endl;
    return 2;
  }
  std::stringstream buffer;
  buffer << smtfin.rdbuf();
  ilang::smt::YosysSmtParser design_info(buffer.str());
  const ilang::smt::datatypes_t & datatypes = design_info.GetRawSmtAst().datatypes;
  const ilang::smt::data_type_order_t & datatype_order = design_info.GetRawSmtAst().data_type_order;


  std::ifstream cexfin(argv[2]);
  if (!cexfin.is_open()) {
    std::cout << "unable to read : " << argv[2] << std::endl;
    return 2;
  }
  std::stringstream buffer2;
  buffer2 << cexfin.rdbuf();
  std::string cex_buf(buffer2.str());
  size_t old_len = cex_buf.length();
  do {
    old_len = cex_buf.length();
    cex_buf = ilang::ReplaceAll(cex_buf,"((", "( (");
    cex_buf = ilang::ReplaceAll(cex_buf,"))", ") )");
  } while(old_len != cex_buf.length());

  std::istringstream cex_parse_buf(cex_buf);
  std::vector<name_value_width_t> var_val_list;
  parseCex(cex_parse_buf, var_val_list, datatypes, datatype_order );
  // print it

  std::sort(var_val_list.begin(), var_val_list.end(),
    [](const name_value_width_t &lhs, const name_value_width_t & rhs) -> bool {
      return lhs.varname < rhs.varname;
    });
  for (auto && nvw : var_val_list) {
    std::cout << nvw.varname << "\t = " << nvw.value << std::endl;
  }

  return 0;
}
