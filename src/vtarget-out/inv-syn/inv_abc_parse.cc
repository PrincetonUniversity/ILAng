/// \file Parsing ABC invariant synthesis result
/// what we need are : blif file, clauses file
/// dut name and whether to discourage use of outside variable
// ---Hongce Zhang

#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/vtarget-out/inv-syn/inv_abc_parse.h>

#include <fstream>
#include <sstream>

namespace ilang {

bool replace_everything_not_dut = true;

static std::string handle_range_ref(const std::string & in) {
  // if there is only one [] , it must be bit selection
  // if there are multiple [], the last one is bit selection
  auto pos = in.rfind('[');
  if (pos == in.npos)
    return in;
  auto rpos = in.rfind(']');
  ILA_ASSERT(pos < rpos) << "Unknown how to handle:" << in;
  auto idx = in.substr(pos+1,rpos-(pos+1));
  ILA_ASSERT(not S_IN(":", idx));
  return in.substr(0,pos) + "[" + idx + ":" + idx +"]";
}

void AbcInvariantParser::parse(
    const std::string & blif_name,
    const std::string & abc_result_fn) {
  
  std::vector<std::string> blif_state_order;
  { // read blif
    std::ifstream fin(blif_name);
    if (! fin.is_open()) {
      ILA_ERROR << "Cannot read from: " <<blif_name;
      return;
    }
    std::string line;
    while(std::getline(fin,line)) {
      if (line.find(".latch ") == 0) {
        auto vec = SplitSpaceTabEnter(line);
        blif_state_order.push_back(vec.at(2));
      }
    }
  } // read blif

  { // parse abc file
    std::ifstream fin(abc_result_fn);
    if (! fin.is_open()) {
      ILA_ERROR << "Cannot read from: " <<abc_result_fn;
      return;
    }
    // you need to check whether there is negation there:

    std::string line;
    bool has_a_normal_cube = false;

    while(std::getline(fin,line)) {
      std::stringstream ss(line);
      int flop;
      std::string cube;
      bool cube_has_abnormal_var = false; // if the condition whether to remove this cube "| 1'b0 " means do not add it
      bool remove_this_cube = false;
      while(ss>>flop) { // for each cube (line)
        int neg = flop & 0x1;
        int flopno = flop >> 1;
        ILA_ASSERT(blif_state_order.size() > flopno)
          << "Referring #" << flopno << " flop, while size of blifstates:" << blif_state_order.size() ;
        const auto & ref_val_name = blif_state_order.at(flopno);
        std::string literal;
        if (ref_val_name.find(dut_name+".") == 0)
          literal = (neg ? "~" : "") +  handle_range_ref(ref_val_name);
        else {
          ILA_ERROR_IF(discourage_outside_var_ref) << "ABC inv referring to outside var:" << ref_val_name;
          if ( ref_val_name == "__all_assumed_reg__" ) {
            literal = (neg ? "~" : "") + std::string("1'b0");
            remove_this_cube = !neg; // if it is "& 1'b0" this cube is 0
          }
          else if (ref_val_name.find("committed_inst") == 0) {
            cube_has_abnormal_var = true; 
            literal = (neg ? "~" : "") +  std::string("1'b1");
            remove_this_cube = neg; // if it is "& ~1'b1" this cube is 0
            // literal = "1'b1"; // void the literal if abnormal
            // over-approximate it
          } else if (ref_val_name.find(".") != ref_val_name.npos) {
            // keep it
            literal = (neg ? "~" : "") +  handle_range_ref(ref_val_name);
            remove_this_cube = true; // remove this cube (we don't know what to do actually)
          } else 
            remove_this_cube = true;
          /*
          if(replace_outside_var_ref && ref_val_name != "__all_assumed_reg__") {
            std::string new_var_name = ReplaceAll(ReplaceAll(ReplaceAll(ref_val_name, "." , "_dot_"), "[", "_"), "]","_");
            outside_reference.insert(new_var_name);
            literal = (neg ? "~" : "") +  new_var_name;
          } else // o.w. it is okay
            literal = (neg ? "~" : "") +  handle_range_ref( ref_val_name );
          */
        } // refering to outside var
        if(cube.empty())
          cube = literal;
        else
          cube = cube + " & "  + literal;
      } // end of a cube
      // cube = "( " +  cube + ") "

      // void the cube if abnormal
      if( remove_this_cube) // cube_has_abnormal_var ||
        cube = "1'b0" ; //cube = "1'b0"; // under-approximate it : total under-approximate
      else {// if at least the cube has a normal var, it is a normal cube
        has_a_normal_cube = true;
        // only if this cube is not removed, we will add it 
        if (parse_result.empty())
          parse_result =  "(" + cube + ")";
        else
          parse_result = parse_result + " | (" + cube + ")";
      }
    } // deal with a line
    ILA_ERROR_IF(has_a_normal_cube == false) << "No normal is deduced.";
    ILA_ERROR_IF(parse_result.empty()) << "No invariants are extracted!";
    if (!has_a_normal_cube || parse_result.empty() ) {
      parse_result = "";
      parse_succeed = false;
    }
    
    parse_result = "~("  + parse_result + ")";
    parse_result = ReplaceAll(parse_result, "__all_assumed_reg__", "1'b0");
  } // parse abc file
}



void AbcInvariantParser::parse(
    const std::string & blif_name,
    const std::string & abc_result_fn,
    const std::string & gla_map_fn) {
  
  std::vector<std::string> blif_state_order;
  { // read blif
    std::ifstream fin(blif_name);
    if (! fin.is_open()) {
      ILA_ERROR << "Cannot read from: " <<blif_name;
      return;
    }
    std::string line;
    while(std::getline(fin,line)) {
      if (line.find(".latch ") == 0) {
        auto vec = SplitSpaceTabEnter(line);
        blif_state_order.push_back(vec.at(2));
      }
    }
  } // read blif

  std::vector<unsigned> new_id_to_old_id;
  { // read gla map table
    std::ifstream fin(gla_map_fn);
    if (! fin.is_open()) {
      ILA_ERROR << "Cannot read from: " <<gla_map_fn;
      return;
    }
    unsigned PiCount, good, newFlopCnt;
    unsigned OldGid, NewGid = 0, NewGidTmp;
    fin >> PiCount >> good >> newFlopCnt; 
    ILA_ASSERT(good) << "ABC result: Ro are not consecutive!";
    for(unsigned idx = 0; idx < newFlopCnt; ++ idx) {
      fin >> OldGid >> NewGidTmp;
      ILA_ASSERT(NewGidTmp > NewGid) << "ABC result : ff count bug!";
      NewGid = NewGidTmp;
      new_id_to_old_id.push_back(OldGid - PiCount -1 );
      ILA_ASSERT(OldGid - PiCount -1 < blif_state_order.size());
    }
  }

  { // parse abc file
    std::ifstream fin(abc_result_fn);
    if (! fin.is_open()) {
      ILA_ERROR << "Cannot read from: " <<abc_result_fn;
      return;
    }
    // you need to check whether there is negation there:

    std::string line;
    bool has_a_normal_cube = false;
    while(std::getline(fin,line)) {
      std::stringstream ss(line);
      int flop;
      std::string cube;
      bool cube_has_abnormal_var = false;
      bool remove_this_cube = false;
      while(ss>>flop) {
        int neg = flop & 0x1;
        int flopno = flop >> 1;
        ILA_ASSERT(new_id_to_old_id.size() > flopno)
          << "Referring #" << flopno << " flop, while size of abstract states:" << new_id_to_old_id.size() ;
        const auto & ref_val_name = blif_state_order.at(new_id_to_old_id[flopno]);
        std::string literal;
        if (ref_val_name.find(dut_name+".") == 0)
          literal = (neg ? "~" : "") +  handle_range_ref(ref_val_name);
        else {
          ILA_ERROR_IF(discourage_outside_var_ref) << "ABC inv referring to outside var:" << ref_val_name;
          if ( ref_val_name == "__all_assumed_reg__" ) {
            literal = (neg ? "~" : "") + std::string("1'b0");
            remove_this_cube = !neg; // if it is "& 1'b0" this cube is 0
          }
          else if (ref_val_name.find("committed_inst") == 0) {
            cube_has_abnormal_var = true; 
            literal = (neg ? "~" : "") +  std::string("1'b1");
            remove_this_cube = neg; // if it is "& ~1'b1" this cube is 0
            // literal = "1'b1"; // void the literal if abnormal
            // over-approximate it
          } else if (ref_val_name.find(".") != ref_val_name.npos) {
            // keep it
            literal = (neg ? "~" : "") +  handle_range_ref(ref_val_name);
            remove_this_cube = true; // remove this cube (we don't know what to do actually)
          } else 
            remove_this_cube = true;
          /*
          if(replace_outside_var_ref && ref_val_name != "__all_assumed_reg__") {
            std::string new_var_name = ReplaceAll(ReplaceAll(ReplaceAll(ref_val_name, "." , "_dot_"), "[", "_"), "]","_");
            outside_reference.insert(new_var_name);
            literal = (neg ? "~" : "") +  new_var_name;
          } else // o.w. it is okay
            literal = (neg ? "~" : "") +  handle_range_ref( ref_val_name );
          */
        } // refering to outside var
        if(cube.empty())
          cube = literal;
        else
          cube = cube + " & "  + literal;
      } // end of a cube
      // cube = "( " +  cube + ") "

      // void the cube if abnormal
      if(remove_this_cube) // cube_has_abnormal_var ||
        cube = "1'b0"; //cube = "1'b0"; // under-approximate it : total under-approximate
      else {
        has_a_normal_cube = true;
        if (parse_result.empty())
          parse_result =  "(" + cube + ")";
        else
          parse_result = parse_result + " | (" + cube + ")";
      }
    }
    ILA_ERROR_IF(has_a_normal_cube == false) << "No normal is deduced.";
    ILA_ERROR_IF(parse_result.empty()) << "No invariants are extracted!";
    if (!has_a_normal_cube || parse_result.empty() ) {
      parse_result = "";
      parse_succeed = false;
    }
    
    parse_result = "~("  + parse_result + ")";
    parse_result = ReplaceAll(parse_result, "__all_assumed_reg__", "1'b0");
  } // parse abc file
}

AbcInvariantParser::AbcInvariantParser(
  const std::string & blif_name,
  const std::string & abc_result_fn,
  const std::string & _dut_name,
  bool discourage_outside_variable_reference,
  bool replace_outside_variable_reference,
  const std::string & gla_abs_fn):
    dut_name(_dut_name),
    discourage_outside_var_ref(discourage_outside_variable_reference),
    replace_outside_var_ref(replace_outside_variable_reference),
    parse_succeed(true) {

  if (gla_abs_fn.empty())
    parse(blif_name, abc_result_fn);
  else
    parse(blif_name, abc_result_fn, gla_abs_fn);
}

}; // namespace ilang