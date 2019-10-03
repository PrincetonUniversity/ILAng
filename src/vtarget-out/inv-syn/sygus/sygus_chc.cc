/// \file Invariant Synthesis -- SyGuS
/// to work with CVC4 (the latest version please)
/// The chc approach
/// (passing the whole transition function)
/// 
// Hongce Zhang (hongcez@princeton.edu)


#include <ilang/util/container_shortcut.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/inv-syn/sygus/sygus_chc.h>

#include <fstream>

namespace ilang {

std::string inv_syn_tmpl_sygus = R"***(
;---------------------------------------------------
;  Single Inductive Invariant Synthesis for SyGuS
;  Generated from ILAng
;---------------------------------------------------

(set-logic BV)

;------------------- SYNTAX ------------------------
%Syntax%

;------------------- DESIGN's SMT ------------------
%SmtLib2%


;--------------------- VAR DEFs --------------------
%BeforeInitVar%
%InitVar%
;(declare-var |__BI__state| Type)
;(declare-var |__I__state|  Type)

%State%
%StatePrime%
;(declare-var |__S__state| Type)
;(declare-var |__S'__state| Type)

; same for flattened

;---------------- CHC-like CONSTRAINTS ----------------

; init => inv
(constraint (=> (and 
  (|%WrapperName%_n rst| %BIs%) 
  (|%WrapperName%_h| %BIs%)
  (|%WrapperName%_h| %Is%)
  (|%WrapperName%_t| %BIs% %Is%)) 
  (INV %Is%)))

; inv /\ T => inv
(constraint (=> (and 
  (INV %Ss%) 
  (|%WrapperName%_u| %Ss%) 
  ;(|%WrapperName%_u| %Sps%) 
  (|%WrapperName%_h| %Ss%)
  ;(|%WrapperName%_h| %Sps%)
  (|%WrapperName%_t| %Ss% %Sps%)) 
  (INV %Sps%)))

; inv => p
(constraint (=> (and 
  (INV %Ss%)
  (|%WrapperName%_u| %Ss%) 
  (|%WrapperName%_h| %Ss%))
  (|%WrapperName%_a| %Ss%)))

(check-synth)


;---------------- ==END== ----------------
)***";

static std::string RewriteDatatypeSygusChc(
  const std::string & tmpl, const std::vector<smt::state_var_t> & dt,
  const std::string & wrapper_mod_name);

Cvc4SygusChcGenerator::Cvc4SygusChcGenerator(
  const smt::YosysSmtParser & smt_design_info,       // the design info is needed
  const std::vector<std::string> & inv_var_name_vec, // the variables we are going to consider
  const sygus_options_t & SygusOptions,           // the options
  const std::string & flattened_smt,
  const std::map<std::string,int> & additional_width_info,
  const Cvc4Syntax & syntax
  ) : Cvc4SygusBase(smt_design_info, inv_var_name_vec, SygusOptions, "%WrapperDataType%", additional_width_info, syntax),
      // not customize inv arg
      smt_converted(flattened_smt) { }


std::string Cvc4SygusChcGenerator::smt_var_trans() const {
  std::string wrapper_mod_name = design_info.get_module_def_orders().back();
  const auto & datatype_top_mod = design_info.get_module_flatten_dt(wrapper_mod_name);
  auto chc = ReplaceAll(
    inv_syn_tmpl_sygus, "%Syntax%", get_template()); // "%WrapperDataType%" will be available at this point
  return 
    ReplaceAll(RewriteDatatypeSygusChc(chc, datatype_top_mod, wrapper_mod_name),
      "%SmtLib2%", smt_converted);
}


void Cvc4SygusChcGenerator::ExportToFile(const std::string & fn) {
  std::ofstream fout(fn);
  if (not fout.is_open()) {
    ILA_ERROR << "Cannot open " << fn << " for write.";
    return;
  }
  // to do : add functions here
  // ignore those in dpts but not in inv_var_name_vec!
  fout << smt_var_trans();
}


// %WrapperName%
// %WrapperDataType%
// %BeforeInitVar%
// %InitVar%
// %State%
// %StatePrime%
// %BIs% %Is%  %Ss% %Sps%
static std::string RewriteDatatypeSygusChc(
  const std::string & tmpl, const std::vector<smt::state_var_t> & dt,
  const std::string & wrapper_mod_name) {
  
  std::string chc = tmpl;

  //std::vector<smt::var_type> inv_tps;
  //smt::YosysSmtParser::convert_datatype_to_type_vec(dt, inv_tps);
  std::string WrapperDataType; // = smt::var_type::toString(inv_tps);

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
      BIs += " "; Is  += " "; Ss  += " "; Sps += " "; WrapperDataType += " ";
    }
    first = false;
    BIs += "|BI_" + st_name + "|";
    Is  += "|I_"  + st_name + "|";
    Ss  += "|S_"  + st_name + "|";
    Sps += "|S'_" + st_name + "|";

    WrapperDataType += "(|"+st_name+"| " + type_string+")";
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
} // RewriteDatatypeSygusChc

}; // namespace ilang

