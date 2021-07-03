/// \file
/// Unit test for refinement expression to smt-lib2

#include <ilang/rfmap-in/rfexpr_to_smt.h>

#include "unit-include/config.h"
#include "unit-include/util.h"

// use rfmap::VerilogRefinementMap::ParseRfExprFromString
// to parse a refinement expression
// and use rfmap::RfExpr2Smt::to_smt2 to translate to smt-lib2
// but you need type annotation first
// this flow is used in array handling with pono

namespace ilang {


#define PRINT_SMT(s, b) do { \
	std::string rfstr = (s); \
	auto rfexpr = rfmap::VerilogRefinementMap::ParseRfExprFromString(rfstr); \
	annotator.AnnotateType(rfexpr); \
	std::cout << RfExpr2Smt::to_smt2(rfexpr, (b)) << std::endl; \
} while(0)

TEST(TestRfexpr, ToSmt) {
  // 1. construct var to rf_var_type map
  //    and the function to map that
  // 2. annotate the type 
  // 3. convert
	std::map<std::string, rfmap::RfMapVarType> var_type = 
	{
		{"a", rfmap::RfMapVarType(16) },
		{"b", rfmap::RfMapVarType(8) },
		{"c", rfmap::RfMapVarType(1) },
		{"array1", rfmap::RfMapVarType(16,8) },
		{"array2", rfmap::RfMapVarType(16,8) },
		{"array3", rfmap::RfMapVarType(8,16) }
	};

  auto check_var_type = 
  	[&var_type](const std::string & n) -> rfmap::RfVarTypeOrig {
  		RfVarTypeOrig ret;
  		auto pos = var_type.find(n);
  		if(pos != var_type.end())
  			ret.type = pos->second;
  		return ret;
  	};
  
  rfmap::TypeAnalysisUtility annotator(check_var_type);


	PRINT_SMT("a[4] == b[4]" , true);
	PRINT_SMT("a[5:4] + c[4:3] != array1[a][2:1]" , true);
	PRINT_SMT(" c ? array1 : array2 " , false);
	PRINT_SMT(" c == 1'b1? array1 : array2 " , false);
	PRINT_SMT(" array3[b+1] " , false);



} // TEST(TestRfexpr, ToSmt)

} // namespace ilang

