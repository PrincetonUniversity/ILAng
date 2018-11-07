/// \file
/// Verilog Generator
#include <string>
#include "verilog-out/verilog_gen.h"

namespace ila {

#define toStr(x) (std::to_string(x))

VerilogGenerator::VerilogGenerator (const std::string &modName,const std::string &clk,const std::string &rst, const VlgExportConfig & config)
  : moduleName(modName)
  , clkName(clk)
  , rstName(rst)
  , idCounter(0)
  , cfg_(config)
{}

/// Check if a name is reserved (clk/rst/modulename/decodeName/ctrName)
bool VerilogGenerator::check_reserved_name(const vlg_name_t & n) const {
  if(n == modulename || n == clkName || n == rstName)
    return false;
  for(auto && sig : decodeName) {
    if( sig.first == n ) 
      return false;
  }
  return true;
}

// Currently not used, can be added to enforce sanity check
#define CHECK_NAME(s) (ILA_ERROR_IF( !check_reserved_name(s) ) << "Name "<<(s) << " is reserved, which should not be used" );
#define EXISTS_NAME(n,w)  ( all_valid_names.find( { (n), (w) } ) != all_valid_names.end() )
#define ADD_NAME(n,w)  all_valid_names.insert( { (n), (w) } )

/// Get the width of an ExprPtr, must be supported sort, NOTE: function is not an exp
/// Do we really need it?
int VerilogGenerator::get_width(const ExprPtr &n) const {
  if( n->sort()->is_bool() )
    return 1;
  if( n->sort()->is_bv() )
    return n->sort()->bit_width();
  if( n->sort()->is_mem() )
    return n->sort()->data_width(); // NOTE : here we get the data width

  ILA_ASSERT(false)<<"Unable to get the width for sort "<< n->sort();
}
/// convert a widith to a verilog string
std::string VerilogGenerator::width_to_vlg_range(int w) const {
  if(w>1)
    return std::string("[") + toStr(w-1) + ":0]";
  return "";
}
/// get a new id
vlg_name_t VerilogGenerator::new_id() {
  return "n" + toStr(idCounter++);
}
/// if the exprptr contains some meaning in its name, will try to incorporate that to the name;
vlg_name_t VerilogGenerator::new_id(const ExprPtr & e){ 
  if (!e)
    return new_id();

  auto name = e->name().str();
  auto pos = reference_name_set.find(name);
  if( pos == reference_name_set.end() ) // not registered to the refererence name set
    return new_id(); // just return the plain name
  return "n" + toStr(idCounter++) + "__" + pos.second;
}
//--------------------------------------------------------------------------

void VerilogGenerator::add_input(const vlg_name_t & n,int w)
{
  inputs.push_back(vlg_sig_t(n,w));
}
void VerilogGenerator::add_output(const vlg_name_t & n,int w)
{
  outputs.push_back(vlg_sig_t(n,w));
}
void VerilogGenerator::add_wire(const vlg_name_t & n,int w)
{
  wires.push_back(vlg_sig_t(n,w));
}
void VerilogGenerator::add_reg(const vlg_name_t & n,int w)
{
  regs.push_back(vlg_sig_t(n,w));
}
void VerilogGenerator::add_stmt(const vlg_stmt_t & s)
{
  statements.push_back(s);
}
void VerilogGenerator::add_always_stmt(const vlg_stmt_t & s)
{
  always_stmts.push_back(s);
}
void VerilogGenerator::add_init_stmt(const vlg_stmt_t & s)
{
  init_stmts.push_back(s);
}
void VerilogGenerator::add_ite_stmt(const vlg_stmt_t & cond, const vlg_stmt_t & tstmt, const vlg_stmt_t & fstmt)
{
  ite_stmts.push_back(std::make_tuple(cond,tstmt,fstmt));
}

// the mems to be created 
void VerilogGenerator::add_internal_mem(const vlg_name_t &mem_name, int addr_width,int data_width)
{
  mems_internal.push_back(vlg_mem_t(mem_name,addr_width,data_width));
}
void VerilogGenerator::add_external_mem(const vlg_name_t &mem_name, int addr_width,int data_width)
{
  mems_external.push_back(vlg_mem_t(mem_name,addr_width,data_width));
  vlg_name_t addr_name = mem_name + "_addr_" + NewId();
  vlg_name_t data_name = mem_name + "_data_" + NewId();
  mem_o.push_back( vlg_sig_t(addr_name, addr_width) );
  mem_i.push_back( vlg_sig_t(data_name, data_width) );
}
//--------------------------------------------------------------------------
void VerilogGenerator::addInput( const ExprPtr & input ) {
  ILA_ASSERT( input->is_var() );
  // we need to consider the case of an input memory
  if( input->is_mem() ) {
    ILA_ASSERT(false) << "NOT implemented"; //FIXME: add wires to read from external
    // when in expr parse, remember it is (EXTERNAL mem)
    add_external_mem( input->name().str(), // name
                      input->sort()->addr_width(), // addr_width
                      input->sort()->data_width() );
  }
  else{
    add_input( input->name().str() , get_width(input) );
    add_wire ( input->name().str() , get_width(input) );
  }
}

void VerilogGenerator::addState( const ExprPtr & state ) {
  ILA_ASSERT( state->is_var() );
  if( state->is_mem() ) { // depends on configuration, we choose to put into mem_external/mem_internal
    if( cfg_.extMem ) {
      add_external_mem( input->name().str(), // name
                        input->sort()->addr_width(), // addr_width
                        input->sort()->data_width() );
    }
    else {
      add_internal_mem( input->name().str(), // name
                        input->sort()->addr_width(), // addr_width
                        input->sort()->data_width() );
    }
  }
  else if( state->is_bv() ) {
    add_reg( state->name().str(), state->sort()->bit_width() );
  }
  else if(state->is_bool()  ) {
    add_reg( state->name().str(), 1 );
  }
  
}

//--------------------------------------------------------------------------


void VerilogGenerator::parseArg(const ExprPtr & e) {
  for (size_t i = 0; i != e->arg_num() ; ++ i) {
    ParseNonMemUpdateNode( e->arg(i) );
  }
}

void VerilogGenerator::getVlgFromExpr(const ExprPtr & e) {
  auto pos = nmap.find(e);
  ILA_ASSERT( pos != nmap.end() ) << "Expr:"<< (*e) << " has not been translated yet";
  return pos->second;
}
void VerilogGenerator::getArg(const ExprPtr & e, const size_t & i ) {
  auto arg_i = e->arg(i);
  return getVlgFromExpr(arg_i);
}



vlg_stmt_t VerilogGenerator::translateBoolOp( const ExprOp & e ) {
  vlg_stmt_t result_stmt;
  std::string op_name = e->op_name();
  size_t arg_num = e->arg_num()

  if (op_name == "APP") { // Function application
    // deal with the case with a function
    std::shared_ptr<ExprOpAppFunc> func_app_ptr_ = std::dynamic_pointer_cast<ExprOpAppFunc>(e);
    ILA_NOT_NULL(func_app_ptr_);

    #error  do something to help apply a function!

    func_ptr_set.insert( e->func() );
  }
  else if(arg_num == 1) {
    if( op_name == "NOT" )
      result_stmt = "~ ( " + getArg( e, 0 ) + " ) ";
    else
      ILA_ASSERT(false) << op_name << " is not supported by VerilogGenerator";
  }
  else if(arg_num == 2) {
    auto arg1 = getArg(e, 0);
    auto arg2 = getArg(e, 1);
    if (op_name == "AND")
      result_stmt = " ( " + arg1 + " ) & (" + arg2 + " ) ";
    else if(op_name == "OR")
      result_stmt = " ( " + arg1 + " ) | ( " +  arg2 + " ) ";
    else if(op_name == "XOR")
      result_stmt = " ( " + arg1 + " ) ^ ( " +  arg2 + " ) ";
    else if(op_name == "EQ")
      result_stmt = " ( " + arg1 + " ) == ( " +  arg2 + " ) ";
    else if(op_name == "IMPLY")
      result_stmt = " ( ~ ( " + arg1 + " ) | ( " +  arg2 + " ) )";
    else
      ILA_ASSERT(false) << op_name << " is not supported by VerilogGenerator";
  }
  else if(arg_num == 3) {
    if (op_name == "ITE")
    else
      ILA_ASSERT(false) << op_name << " is not supported by VerilogGenerator";

  }


}
//--------------------------------------------------------------------------
void VerilogGenerator::ParseNonMemUpdateNode( const ExprPtr & e ) { // will be used in parsing state update of non mem and decode function
  // memorize
  if( nmap.find(e) != nmap.end() ) return;

  if( e->is_bool() ) {
    if( e->is_var() )
      nmap[e] = e->name().str(); // just use its name
    else if( e->is_op() ) { // bool op
      // leaves first,
      parseArg(e);
      auto expr_op_ptr = std::dynamic_pointer_cast<ExprOp>( e );
      ILA_NOT_NULL(expr_op_ptr);
      translateBoolOp(expr_op_ptr);
    }
    else if( e->is_const() ) { // bool const
      vlg_name_t bcnst = vlg_name_t("1'b") + ( std::dynamic_pointer_cast<ExprConst>(e)->val_bool()->val() ? "1" : "0" );
      nmap[e] = bcnst;
    }
    else
      ILA_ASSERT(false) << "Expr sort: "<< *( e->sort() ) << " is not supported." ;
  }
  else if( e->is_bv() ) {
    if( e->is_var() )
      nmap[e] = e->name().str(); // just use its name
    else if( e->is_op() ) {
      // TODO:
      // leaves first
      parseArg(e);
      # error Not implemented yet
    }
    else if( e->is_const() ) {
      int width = get_width( e );
      vlg_name_t bvcnst = toStr(width) + "'d" + ( std::dynamic_pointer_cast<ExprConst>(e)->val_bv()->str() );
    }
    else
      ILA_ASSERT(false) << "Expr sort: "<< *( e->sort() ) << " is not supported." ;

  }
  else if( e->is_mem() ) {
    // TODO: ?
  }
  else 
    ILA_ASSERT(false) << "Expr sort: "<< *( e->sort() ) << " is not supported." ;

}

void VerilogGenerator::ParseNonMemUpdateExpr( const ExprPtr & e ) { // this will invoke the depthFirstVisit

}

//--------------------------------------------------------------------------
void VerilogGenerator::ParseIla( const InstrLvlAbsPtr & ila_ptr_ )
{
  ILA_ASSERT(false) <<"NOT implemented yet.";
}
void VerilogGenerator::ParseInstr( const InstrPtr & instr_ptr_ )
{
  // add inputs / states / functions
  // do remember to export its parents' state (hierarchically collect its parents)
  
  // try to convert inits, if not add to assumptions

  // add updates

  // add guard of valid signal to "else if"

  // make sure to generate decode/valid signal output
}

}; // namespace ila