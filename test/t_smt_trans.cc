/// \file
/// Unit test SMT translator

#include <ilang/util/str_util.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/smt-inout/yosys_smt_parser.h>

#include "unit-include/config.h"
#include "unit-include/util.h"

namespace ilang {

TEST(TestSmtTrans,ReplaceAndAddKeep) {

  auto fn = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/smt/pipeline_design.smt2";
  auto fo = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/smt/smt-out-trans.smt2";
  
  std::ifstream fin(fn);
  EXPECT_TRUE(fin.is_open());
  if (not fin.is_open()) {
    ILA_ERROR << "Unable to read from " << fn;
    return;
  }
  std::stringstream buffer;
  buffer << fin.rdbuf();

  smt::YosysSmtParser smt_in(buffer.str());
  smt_in.BreakDatatypes();
  smt_in.AddNoChangeStateUpdateFunction();

  {
    std::ofstream fout(fo);
    ILA_ERROR_IF(not fout.is_open()) << "Error writing to: " << fo;
    fout << smt_in.Export();
  }

}


static std::string RewriteDatatypeChc(
  const std::string & tmpl, const std::vector<smt::state_var_t> & dt,
  const std::string & wrapper_mod_name) {
  
  std::string chc = tmpl;

  std::vector<smt::var_type> inv_tps;
  smt::YosysSmtParser::convert_datatype_to_type_vec(dt, inv_tps);
  auto WrapperDataType = smt::var_type::toString(inv_tps);

  // %BeforeInitVar%
  // %InitVar%
  // %State%
  // %StatePrime%
  // declare-var s ...
  std::string BeforeInitVar;
  std::string InitVar;
  std::string State;
  std::string StatePrime;
  // %BIs% %Is%  %Ss% %Sps%
  std::string BIs;
  std::string Is;
  std::string Ss;
  std::string Sps;
  bool first = true;

  std::set<std::string> name_set; // avoid repetition
  for (auto && st : dt) {
    auto st_name = st.verilog_name.back() == '.' || st.verilog_name.empty() ? st.internal_name : st.verilog_name;
    st_name = ReplaceAll(st_name, "|", ""); // remove its ||
    // check no repetition is very important!
    ILA_ASSERT(not IN(st_name, name_set)) << "Bug: name repetition!";
    ILA_ASSERT(st._type._type != smt::var_type::tp::Datatype);
    name_set.insert(st_name);
    auto type_string = st._type.toString();
    BeforeInitVar += "(declare-var |BI_" + st_name + "| " + type_string + ")\n";
    InitVar       += "(declare-var |I_"  + st_name + "| " + type_string + ")\n";
    State         += "(declare-var |S_"  + st_name + "| " + type_string + ")\n";
    StatePrime    += "(declare-var |S'_" + st_name + "| " + type_string + ")\n";

    if(not first) {
      BIs += " "; Is  += " "; Ss  += " "; Sps += " ";
    }
    first = false;
    BIs += "|BI_" + st_name + "|";
    Is  += "|I_"  + st_name + "|";
    Ss  += "|S_"  + st_name + "|";
    Sps += "|S'_" + st_name + "|";
  }
  // Replacement
  chc = ReplaceAll(chc, "%WrapperName%",     wrapper_mod_name);
  chc = ReplaceAll(chc, "%WrapperDataType%", WrapperDataType);
  chc = ReplaceAll(chc, "%BeforeInitVar%",   BeforeInitVar);
  chc = ReplaceAll(chc, "%InitVar%",         InitVar);
  chc = ReplaceAll(chc, "%State%",           State);
  chc = ReplaceAll(chc, "%StatePrime%",      StatePrime);
  chc = ReplaceAll(chc, "%BIs%",             BIs);
  chc = ReplaceAll(chc, "%Is%",              Is);
  chc = ReplaceAll(chc, "%Ss%",              Ss);
  chc = ReplaceAll(chc, "%Sps%",             Sps);

  return chc;  
} // RewriteDatatypeChc

TEST(TestSmtTrans,SmtToIndividualBvChc) {

  auto fn = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/smt/rocket.smt2";
  auto fo = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/smt/smt_bv_chc.smt2";
  


  static std::string inv_syn_tmpl_wo_datatypes = R"***(
  ;----------------------------------------
  ;  Single Inductive Invariant Synthesis
  ;  Generated from ILAng
  ;----------------------------------------

  %%

  (declare-rel INV %WrapperDataType%)
  (declare-rel fail ())

  %BeforeInitVar%
  %InitVar%

  %State%
  %StatePrime%

  ; init => inv
  (rule (=> (and 
    (|%WrapperName%_n rst| %BIs%) 
    (|%WrapperName%_t| %BIs% %Is%)) 
    (INV %Is%)))

  ; inv /\ T => inv
  (rule (=> (and 
    (INV %Ss%) 
    (|%WrapperName%_u| %Ss%) 
    (|%WrapperName%_u| %Sps%) 
    (|%WrapperName%_t| %Ss% %Sps%)) 
    (INV %Sps%)))

  ; inv /\ ~p => \bot
  (rule (=> (and 
    (INV %Ss%)
    (|%WrapperName%_u| %Ss%) 
    (not (|%WrapperName%_a| %Ss%))) 
    fail))

  (query fail :print-certificate true)

  )***";

  std::stringstream ibuf;
  { // read file
    std::ifstream smt_fin( fn );
    if(not smt_fin.is_open()) {
      ILA_ERROR << "Cannot read from " << fn;
      return;
    }
    ibuf << smt_fin.rdbuf();
  } // end read file

  std::string smt_converted;
  smt::YosysSmtParser smt_in(ibuf.str());
  smt_in.BreakDatatypes();
  smt_converted = smt_in.Export();

  std::string wrapper_mod_name = smt_in.get_module_def_orders().back();
  
  std::string chc;
  const auto & datatype_top_mod = smt_in.get_module_flatten_dt(wrapper_mod_name);
  auto tmpl = inv_syn_tmpl_wo_datatypes;
  chc = RewriteDatatypeChc(
    tmpl,
    datatype_top_mod, wrapper_mod_name);
  chc = ReplaceAll(chc, "%%", smt_converted );
  { // write file
    std::ofstream chc_fout(fo);
    if (not chc_fout.is_open()) {
      ILA_ERROR << "Error writing to : "<< fo;
      return;
    }
    chc_fout << chc;
  } // end write file
}

}; // namespace ilang
