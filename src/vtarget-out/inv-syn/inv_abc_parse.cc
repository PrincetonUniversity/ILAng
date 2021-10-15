/// \file Parsing ABC invariant synthesis result
/// what we need are : blif file, clauses file
/// dut name and whether to discourage use of outside variable
// ---Hongce Zhang

#include <ilang/config.h>
#ifdef INVSYN_INTERFACE

#include <ilang/util/container_shortcut.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/inv-syn/inv_abc_parse.h>

#include <algorithm>
#include <fstream>
#include <sstream>

namespace ilang {

// ------------------ AbcInvariantParser ------------------
// the purpose of having blifname is to tell which state is a real state
void AbcInvariantParser::parseAigerResultWoGLA(
    const std::string& aig_map_fn, const std::string& abc_result_fn,
    InvariantInCnf& inv_cnf, const InvariantInCnf& ref_cnf,
    const std::string& blif_fn_name) {

  std::vector<std::string> aig_state_order;
  std::vector<std::pair<std::string, unsigned>> aig_literal;
  std::set<std::string> blif_valid_state_names;
  std::set<unsigned long long> invlatches;

  { // read blif for valid state names
    std::ifstream fin(blif_fn_name);
    if (!fin.is_open()) {
      ILA_ERROR << "Cannot read from: " << blif_fn_name;
      return;
    }
    std::string line;
    while (std::getline(fin, line)) {
      if (StrStartsWith(line, ".latch ")) {
        auto vec = SplitSpaceTabEnter(line);
        blif_valid_state_names.insert(vec.at(2));
      }
    }
  } // read blif for valid state names

  { // read aiger map
    std::ifstream fin(aig_map_fn);
    if (!fin.is_open()) {
      ILA_ERROR << "Cannot read from: " << aig_map_fn;
      return;
    }
    std::string line;
    while (std::getline(fin, line)) {
      auto vec = SplitSpaceTabEnter(line);
      // only focus on the registers
      if (StrStartsWith(line, "latch ") || StrStartsWith(line, "invlatch ")) {
        auto vec =
            SplitSpaceTabEnter(line); // latch/invlatch latchNo bitNo name
        auto latch_no = StrToULongLong(vec.at(1));
        if (StrStartsWith(line, "invlatch "))
          invlatches.insert(latch_no);
        const auto& bit_no = vec.at(2);
        const auto new_name = vec.at(3) + "[" + bit_no + ":" + bit_no + "]";
        const auto blif_ref_name = vec.at(3) + "[" + bit_no + "]";
        ILA_CHECK(aig_state_order.size() == latch_no ||
                  aig_state_order.size() == latch_no + 1)
            << new_name << " " << latch_no << " " << aig_state_order.size();
        if (IN(blif_ref_name, blif_valid_state_names) ||
            (IN(vec.at(3), blif_valid_state_names) && bit_no == "0")) {
          ILA_CHECK(aig_state_order.size() ==
                    latch_no); // insert to the right index
          aig_state_order.push_back(new_name);
          aig_literal.push_back(std::make_pair(vec.at(3), StrToInt(bit_no)));
        }
      } // if the line contains latch
    }   // while getline
  }     // read aiger map

  { // parse abc file
    std::ifstream fin(abc_result_fn);
    if (!fin.is_open()) {
      ILA_ERROR << "Cannot read from: " << abc_result_fn;
      return;
    }
    // you need to check whether there is negation there:

    std::string line;
    bool has_a_normal_cube = false;

    while (std::getline(fin, line)) {
      std::stringstream ss(line);
      unsigned long long flop;
      std::string cube;
      // bool cube_has_abnormal_var = false; // if the condition whether to
      // remove this cube "| 1'b0 " means do not add it
      bool remove_this_cube = false;
      InvariantInCnf::clause cl;

      while (ss >> flop) { // for each cube (line)
        int neg = flop & 0x1;
        unsigned long long flopno = flop >> 1;
        std::string literal;
        ILA_CHECK(aig_state_order.size() >=
                  flopno) // remeber : the last one should be one
            << "Referring #" << flopno
            << " flop, while size of blifstates:" << aig_state_order.size();

        if (flopno == aig_state_order.size()) {
          literal = (neg ? "~" : "") + std::string("1'b1"); // the extra reg
          remove_this_cube = remove_this_cube ||
                             neg; // if it is "& !1'b1", then this cube is 0
        } else {
          if (IN(flopno, invlatches))
            neg = !neg;
          const auto& ref_val_name = aig_state_order.at(flopno);
          const auto& lit =
              aig_literal.at(flopno); // first : var name , second : bit idx

          if (ref_val_name.find(dut_name + ".") == 0) {
            literal = (neg ? "~" : "") + ref_val_name;
            cl.push_back(
                InvariantInCnf::literal(bool(neg), lit.first, lit.second));
          } else {
            ILA_ERROR_IF(discourage_outside_var_ref)
                << "ABC inv referring to outside var:" << ref_val_name;
            if (replace_outside_var_ref) {
              if (ref_val_name == "__all_assumed_reg__[0:0]") {
                literal = (neg ? "~" : "") + std::string("1'b0");
                remove_this_cube = remove_this_cube ||
                                   !neg; // if it is "& 1'b0" this cube is 0
              } else if (ref_val_name.find(".") != ref_val_name.npos) {
                // keep it
                literal = (neg ? "~" : "") + ref_val_name;
                remove_this_cube = true; // remove this cube (we don't know what
                                         // to do actually)
              } else
                remove_this_cube = true;
            } else {
              literal = (neg ? "~" : "") + ref_val_name;
              cl.push_back(
                  InvariantInCnf::literal(bool(neg), lit.first, lit.second));
            }
          }
        }

        // refering to outside var
        if (cube.empty())
          cube = literal;
        else
          cube = cube + " & " + literal;
      } // end of a cube
      // cube = "( " +  cube + ") "

      // void the cube if abnormal
      if (remove_this_cube) // cube_has_abnormal_var ||
        cube = "1'b0";      // cube = "1'b0"; // under-approximate it : total
                            // under-approximate
      else { // if at least the cube has a normal var, it is a normal cube
        has_a_normal_cube = true;
        // only if this cube is not removed, we will add it
        if (parse_result.empty())
          parse_result = "(" + cube + ")";
        else
          parse_result = parse_result + " | (" + cube + ")";
        inv_cnf.InsertClauseNewerFromReference(cl, ref_cnf);
      }
    } // deal with a line ( a clause )
    ILA_ERROR_IF(has_a_normal_cube == false) << "No normal is deduced.";
    ILA_ERROR_IF(parse_result.empty()) << "No invariants are extracted!";
    if (!has_a_normal_cube || parse_result.empty()) {
      parse_result = "";
      parse_succeed = false;
    }

    parse_result = "~(" + parse_result + ")";
    parse_result = ReplaceAll(parse_result, "__all_assumed_reg__[0:0]", "1'b0");
  } // parse abc file

} // parseAigerResultWoGLA

void AbcInvariantParser::parseAigerResultWithGLA(
    const std::string& aig_map_fn, const std::string& abc_result_fn,
    const std::string& gla_map_fn, InvariantInCnf& inv_cnf,
    const InvariantInCnf& ref_cnf, const std::string& blif_fn_name) {

  std::vector<std::string> aig_state_order;
  std::vector<std::pair<std::string, unsigned>> aig_literal;
  std::set<std::string> blif_valid_state_names;
  std::set<int> invlatches;

  { // read blif for valid state names
    std::ifstream fin(blif_fn_name);
    if (!fin.is_open()) {
      ILA_ERROR << "Cannot read from: " << blif_fn_name;
      return;
    }
    std::string line;
    while (std::getline(fin, line)) {
      if (StrStartsWith(line, ".latch ")) {
        auto vec = SplitSpaceTabEnter(line);
        blif_valid_state_names.insert(vec.at(2));
      }
    }
  } // read blif for valid state names

  { // read aiger map
    std::ifstream fin(aig_map_fn);
    if (!fin.is_open()) {
      ILA_ERROR << "Cannot read from: " << aig_map_fn;
      return;
    }
    std::string line;
    while (std::getline(fin, line)) {
      auto vec = SplitSpaceTabEnter(line);
      // only focus on the registers
      if (StrStartsWith(line, "latch ") || StrStartsWith(line, "invlatch ")) {
        auto vec = SplitSpaceTabEnter(line);
        unsigned long long latch_no = StrToULongLong(vec.at(1));
        if (StrStartsWith(line, "invlatch "))
          invlatches.insert(latch_no);
        const auto& bit_no = vec.at(2);
        const auto new_name = vec.at(3) + "[" + bit_no + ":" + bit_no + "]";
        const auto blif_ref_name = vec.at(3) + "[" + bit_no + "]";
        ILA_CHECK(aig_state_order.size() == latch_no ||
                  aig_state_order.size() == latch_no + 1)
            << new_name << " " << latch_no << " " << aig_state_order.size();
        if (IN(blif_ref_name, blif_valid_state_names) ||
            (IN(vec.at(3), blif_valid_state_names) && bit_no == "0")) {
          ILA_CHECK(aig_state_order.size() ==
                    latch_no); // insert to the right index
          aig_state_order.push_back(new_name);
          aig_literal.push_back(std::make_pair(vec.at(3), StrToInt(bit_no)));
        }
      } // end if find latch/invlatch
    }   // while getline
  }     // read aiger map

  std::vector<unsigned> new_id_to_old_id;
  { // read gla map table
    std::ifstream fin(gla_map_fn);
    if (!fin.is_open()) {
      ILA_ERROR << "Cannot read from: " << gla_map_fn;
      return;
    }
    unsigned PiCount, good, newFlopCnt;
    unsigned OldGid, NewGid = 0, NewGidTmp;
    fin >> PiCount >> good >> newFlopCnt;
    ILA_CHECK(good) << "ABC result: Ro are not consecutive!";
    for (unsigned idx = 0; idx < newFlopCnt; ++idx) {
      fin >> OldGid >> NewGidTmp;
      ILA_CHECK(NewGidTmp > NewGid) << "ABC result : ff count bug!";
      NewGid = NewGidTmp;
      new_id_to_old_id.push_back(OldGid - PiCount - 1);
      ILA_CHECK(OldGid - PiCount - 1 <= aig_state_order.size());
    }
  }

  { // parse abc file
    std::ifstream fin(abc_result_fn);
    if (!fin.is_open()) {
      ILA_ERROR << "Cannot read from: " << abc_result_fn;
      return;
    }
    // you need to check whether there is negation there:

    std::string line;
    bool has_a_normal_cube = false;

    while (std::getline(fin, line)) {
      std::stringstream ss(line);
      unsigned long long flop;
      std::string cube;
      // bool cube_has_abnormal_var = false; // if the condition whether to
      // remove this cube "| 1'b0 " means do not add it
      bool remove_this_cube = false;
      InvariantInCnf::clause cl;

      while (ss >> flop) { // for each cube (line)
        int neg = flop & 0x1;
        unsigned long long flopno = flop >> 1;

        ILA_CHECK(new_id_to_old_id.size() > flopno)
            << "Referring #" << flopno
            << " flop, while size of abstract states:"
            << new_id_to_old_id.size();
        flopno = new_id_to_old_id[flopno]; // use the gla map
        if (IN(flopno, invlatches))
          neg = !neg;

        std::string literal;
        if (flopno == aig_state_order.size()) {
          literal = (neg ? "~" : "") + std::string("1'b1"); // the extra reg
          remove_this_cube = remove_this_cube ||
                             neg; // if it is "& !1'b1", then this cube is 0
        } else {
          const auto& ref_val_name = aig_state_order.at(flopno);
          const auto& lit =
              aig_literal.at(flopno); // first : var name , second : bit idx

          if (ref_val_name.find(dut_name + ".") == 0) {
            literal = (neg ? "~" : "") + ref_val_name;
            cl.push_back(
                InvariantInCnf::literal(bool(neg), lit.first, lit.second));
          } else {
            ILA_ERROR_IF(discourage_outside_var_ref)
                << "ABC inv referring to outside var:" << ref_val_name;
            if (replace_outside_var_ref) {
              if (ref_val_name == "__all_assumed_reg__[0:0]") {
                literal = (neg ? "~" : "") + std::string("1'b0");
                remove_this_cube = remove_this_cube ||
                                   !neg; // if it is "& 1'b0" this cube is 0
              } else if (ref_val_name.find(".") != ref_val_name.npos) {
                // keep it
                literal = (neg ? "~" : "") + ref_val_name;
                remove_this_cube = true; // remove this cube (we don't know what
                                         // to do actually)
              } else
                remove_this_cube = true;
            } else {
              literal = (neg ? "~" : "") + ref_val_name;
              cl.push_back(
                  InvariantInCnf::literal(bool(neg), lit.first, lit.second));
            }
          }
        }

        // refering to outside var
        if (cube.empty())
          cube = literal;
        else
          cube = cube + " & " + literal;
      } // end of a cube
      // cube = "( " +  cube + ") "

      // void the cube if abnormal
      if (remove_this_cube) // cube_has_abnormal_var ||
        cube = "1'b0";      // cube = "1'b0"; // under-approximate it : total
                            // under-approximate
      else { // if at least the cube has a normal var, it is a normal cube
        has_a_normal_cube = true;
        // only if this cube is not removed, we will add it
        if (parse_result.empty())
          parse_result = "(" + cube + ")";
        else
          parse_result = parse_result + " | (" + cube + ")";
        inv_cnf.InsertClauseNewerFromReference(cl, ref_cnf);
      }
    } // deal with a line ( a clause )
    ILA_ERROR_IF(has_a_normal_cube == false) << "No normal is deduced.";
    ILA_ERROR_IF(parse_result.empty()) << "No invariants are extracted!";
    if (!has_a_normal_cube || parse_result.empty()) {
      parse_result = "";
      parse_succeed = false;
    }

    parse_result = "~(" + parse_result + ")";
    parse_result = ReplaceAll(parse_result, "__all_assumed_reg__[0:0]", "1'b0");
  } // parse abc file

} // parseAigerResultWoGLA

static std::string handle_range_ref(const std::string& in) {
  // if there is only one [] , it must be bit selection
  // if there are multiple [], the last one is bit selection
  auto pos = in.rfind('[');
  if (pos == in.npos)
    return in;
  auto rpos = in.rfind(']');
  ILA_CHECK(pos < rpos) << "Unknown how to handle:" << in;
  auto idx = in.substr(pos + 1, rpos - (pos + 1));
  ILA_CHECK(!S_IN(":", idx));
  return in.substr(0, pos) + "[" + idx + ":" + idx + "]";
}

void AbcInvariantParser::parse(const std::string& blif_name,
                               const std::string& abc_result_fn) {

  std::vector<std::string> blif_state_order;
  std::vector<unsigned> blif_state_init;
  { // read blif
    std::ifstream fin(blif_name);
    if (!fin.is_open()) {
      ILA_ERROR << "Cannot read from: " << blif_name;
      return;
    }
    std::string line;
    while (std::getline(fin, line)) {
      if (StrStartsWith(line, ".latch ")) {
        auto vec = SplitSpaceTabEnter(line);
        blif_state_order.push_back(vec.at(2));
        blif_state_init.push_back(StrToInt(vec.at(5)));
      }
    }
  } // read blif

  { // parse abc file
    std::ifstream fin(abc_result_fn);
    if (!fin.is_open()) {
      ILA_ERROR << "Cannot read from: " << abc_result_fn;
      return;
    }
    // you need to check whether there is negation there:

    std::string line;
    bool has_a_normal_cube = false;

    while (std::getline(fin, line)) {
      std::stringstream ss(line);
      unsigned long long flop;
      std::string cube;
      // if the condition whether to remove this cube "| 1'b0 " means do not add
      // it bool cube_has_abnormal_var = false;
      bool remove_this_cube = false;
      while (ss >> flop) { // for each cube (line)
        int neg = flop & 0x1;
        unsigned long long flopno = flop >> 1;
        std::string literal;
        ILA_CHECK(blif_state_order.size() > flopno)
            << "Referring #" << flopno
            << " flop, while size of blifstates:" << blif_state_order.size();
        if (blif_state_init.at(flopno))
          neg = !neg; // if its initial value is 1...
        const auto& ref_val_name = blif_state_order.at(flopno);

        if (ref_val_name.find(dut_name + ".") == 0)
          literal = (neg ? "~" : "") + handle_range_ref(ref_val_name);
        else {
          ILA_ERROR_IF(discourage_outside_var_ref)
              << "ABC inv referring to outside var:" << ref_val_name;
          if (replace_outside_var_ref) {
            if (ref_val_name == "__all_assumed_reg__[0:0]") {
              literal = (neg ? "~" : "") + std::string("1'b0");
              remove_this_cube =
                  remove_this_cube || !neg; // if it is "& 1'b0" this cube is 0
            } else if (StrStartsWith(ref_val_name, "committed_inst")) {
              // cube_has_abnormal_var = true;
              literal = (neg ? "~" : "") + std::string("1'b1");
              remove_this_cube =
                  remove_this_cube || neg; // if it is "& ~1'b1" this cube is 0
              // literal = "1'b1"; // void the literal if abnormal
              // over-approximate it
            } else if (ref_val_name.find(".") != ref_val_name.npos) {
              // keep it
              literal = (neg ? "~" : "") + handle_range_ref(ref_val_name);
              remove_this_cube =
                  true; // remove this cube (we don't know what to do actually)
            } else
              remove_this_cube = true;
          } else {
            literal = (neg ? "~" : "") + handle_range_ref(ref_val_name);
          }
          /*
          if(replace_outside_var_ref && ref_val_name !=
          "__all_assumed_reg__[0:0]") { std::string new_var_name =
          ReplaceAll(ReplaceAll(ReplaceAll(ref_val_name, "." , "_dot_"), "[",
          "_"), "]","_"); outside_reference.insert(new_var_name); literal = (neg
          ? "~" : "") +  new_var_name; } else // o.w. it is okay literal = (neg
          ? "~" : "") +  handle_range_ref( ref_val_name );
          */
        } // refering to outside var
        if (cube.empty())
          cube = literal;
        else
          cube = cube + " & " + literal;
      } // end of a cube
      // cube = "( " +  cube + ") "

      // void the cube if abnormal
      if (remove_this_cube) // cube_has_abnormal_var ||
        cube = "1'b0";      // cube = "1'b0"; // under-approximate it : total
                            // under-approximate
      else { // if at least the cube has a normal var, it is a normal cube
        has_a_normal_cube = true;
        // only if this cube is not removed, we will add it
        if (parse_result.empty())
          parse_result = "(" + cube + ")";
        else
          parse_result = parse_result + " | (" + cube + ")";
      }
    } // deal with a line
    ILA_ERROR_IF(has_a_normal_cube == false) << "No normal is deduced.";
    ILA_ERROR_IF(parse_result.empty()) << "No invariants are extracted!";
    if (!has_a_normal_cube || parse_result.empty()) {
      parse_result = "";
      parse_succeed = false;
    }

    parse_result = "~(" + parse_result + ")";
    parse_result = ReplaceAll(parse_result, "__all_assumed_reg__[0:0]", "1'b0");
  } // parse abc file
}

void AbcInvariantParser::parse(const std::string& blif_name,
                               const std::string& abc_result_fn,
                               const std::string& gla_map_fn) {

  std::vector<std::string> blif_state_order;
  std::vector<unsigned> blif_state_init;
  { // read blif
    std::ifstream fin(blif_name);
    if (!fin.is_open()) {
      ILA_ERROR << "Cannot read from: " << blif_name;
      return;
    }
    std::string line;
    while (std::getline(fin, line)) {
      if (StrStartsWith(line, ".latch ")) {
        auto vec = SplitSpaceTabEnter(line);
        blif_state_order.push_back(vec.at(2));
        blif_state_init.push_back(StrToInt(vec.at(5)));
      }
    }
  } // read blif

  std::vector<unsigned> new_id_to_old_id;
  { // read gla map table
    std::ifstream fin(gla_map_fn);
    if (!fin.is_open()) {
      ILA_ERROR << "Cannot read from: " << gla_map_fn;
      return;
    }
    unsigned PiCount, good, newFlopCnt;
    unsigned OldGid, NewGid = 0, NewGidTmp;
    fin >> PiCount >> good >> newFlopCnt;
    ILA_CHECK(good) << "ABC result: Ro are not consecutive!";
    for (unsigned idx = 0; idx < newFlopCnt; ++idx) {
      fin >> OldGid >> NewGidTmp;
      ILA_CHECK(NewGidTmp > NewGid) << "ABC result : ff count bug!";
      NewGid = NewGidTmp;
      new_id_to_old_id.push_back(OldGid - PiCount - 1);
      ILA_CHECK(OldGid - PiCount - 1 < blif_state_order.size());
    }
  }

  { // parse abc file
    std::ifstream fin(abc_result_fn);
    if (!fin.is_open()) {
      ILA_ERROR << "Cannot read from: " << abc_result_fn;
      return;
    }
    // you need to check whether there is negation there:

    std::string line;
    bool has_a_normal_cube = false;
    while (std::getline(fin, line)) {
      std::stringstream ss(line);
      unsigned long long flop;
      std::string cube;
      // bool cube_has_abnormal_var = false;
      bool remove_this_cube = false;
      while (ss >> flop) {
        int neg = flop & 0x1;
        unsigned long long flopno = flop >> 1;
        ILA_CHECK(new_id_to_old_id.size() > flopno)
            << "Referring #" << flopno
            << " flop, while size of abstract states:"
            << new_id_to_old_id.size();

        if (blif_state_init.at(new_id_to_old_id[flopno]))
          neg = !neg; // if its initial value is 1...

        const auto& ref_val_name =
            blif_state_order.at(new_id_to_old_id[flopno]);
        std::string literal;
        if (ref_val_name.find(dut_name + ".") == 0)
          literal = (neg ? "~" : "") + handle_range_ref(ref_val_name);
        else {
          ILA_ERROR_IF(discourage_outside_var_ref)
              << "ABC inv referring to outside var:" << ref_val_name;
          if (replace_outside_var_ref) {
            if (ref_val_name == "__all_assumed_reg__[0:0]") {
              literal = (neg ? "~" : "") + std::string("1'b0");
              remove_this_cube =
                  remove_this_cube || !neg; // if it is "& 1'b0" this cube is 0
            } else if (StrStartsWith(ref_val_name, "committed_inst")) {
              // cube_has_abnormal_var = true;
              literal = (neg ? "~" : "") + std::string("1'b1");
              remove_this_cube =
                  remove_this_cube || neg; // if it is "& ~1'b1" this cube is 0
              // literal = "1'b1"; // void the literal if abnormal
              // over-approximate it
            } else if (ref_val_name.find(".") != ref_val_name.npos) {
              // keep it
              literal = (neg ? "~" : "") + handle_range_ref(ref_val_name);
              remove_this_cube =
                  true; // remove this cube (we don't know what to do actually)
            } else
              remove_this_cube = true;
          } else {
            literal = (neg ? "~" : "") + handle_range_ref(ref_val_name);
          }

          /*
          if(replace_outside_var_ref && ref_val_name !=
          "__all_assumed_reg__[0:0]") { std::string new_var_name =
          ReplaceAll(ReplaceAll(ReplaceAll(ref_val_name, "." , "_dot_"), "[",
          "_"), "]","_"); outside_reference.insert(new_var_name); literal = (neg
          ? "~" : "") +  new_var_name; } else // o.w. it is okay literal = (neg
          ? "~" : "") +  handle_range_ref( ref_val_name );
          */
        } // refering to outside var
        if (cube.empty())
          cube = literal;
        else
          cube = cube + " & " + literal;
      } // end of a cube
      // cube = "( " +  cube + ") "

      // void the cube if abnormal
      if (remove_this_cube) // cube_has_abnormal_var ||
        cube = "1'b0";      // cube = "1'b0"; // under-approximate it : total
                            // under-approximate
      else {
        has_a_normal_cube = true;
        if (parse_result.empty())
          parse_result = "(" + cube + ")";
        else
          parse_result = parse_result + " | (" + cube + ")";
      }
    }
    ILA_ERROR_IF(has_a_normal_cube == false) << "No normal is deduced.";
    ILA_ERROR_IF(parse_result.empty()) << "No invariants are extracted!";
    if (!has_a_normal_cube || parse_result.empty()) {
      parse_result = "";
      parse_succeed = false;
    }

    parse_result = "~(" + parse_result + ")";
    parse_result = ReplaceAll(parse_result, "__all_assumed_reg__[0:0]", "1'b0");
  } // parse abc file
}

AbcInvariantParser::AbcInvariantParser(
    const std::string& blif_name, const std::string& abc_result_fn,
    const std::string& _dut_name, bool discourage_outside_variable_reference,
    bool replace_outside_variable_reference, const std::string& gla_abs_fn,
    bool useAiger, const std::string& aiger_map_name, InvariantInCnf& inv_cnf,
    const InvariantInCnf& ref_cnf)
    : dut_name(_dut_name),
      discourage_outside_var_ref(discourage_outside_variable_reference),
      replace_outside_var_ref(replace_outside_variable_reference),
      parse_succeed(true) {

  ILA_CHECK(!blif_name.empty());
  if (useAiger) {
    ILA_CHECK(!aiger_map_name.empty())
        << "You must provide aiger name for `useAiger` flag.";
    if (gla_abs_fn.empty())
      parseAigerResultWoGLA(aiger_map_name, abc_result_fn, inv_cnf, ref_cnf,
                            blif_name);
    else
      parseAigerResultWithGLA(aiger_map_name, abc_result_fn, gla_abs_fn,
                              inv_cnf, ref_cnf, blif_name);
  } else { // for non-aiger this is the blif file
    ILA_CHECK(aiger_map_name.empty());
    if (gla_abs_fn.empty())
      parse(blif_name, abc_result_fn);
    else
      parse(blif_name, abc_result_fn, gla_abs_fn);
  }
}

}; // namespace ilang

#endif // INVSYN_INTERFACE
