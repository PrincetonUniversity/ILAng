add_library (ila SHARED
abstraction.cpp ast.cpp cppsimgen.cpp ext.cpp logging.cpp rewriter.cpp smt.cpp synthesizer.cpp util.cpp exception.cpp imexport.cpp memvalues.cpp simplify.cpp synrewriter.cpp type.cpp Unroller.cpp EqvChecker.cpp)
add_library(ast SHARED
ast/bitvec.cpp ast/bool.cpp ast/node.cpp ast/choice.cpp ast/bvinrange.cpp ast/mem.cpp ast/node.cpp)

set (EXT_LIBRARIES ${Z3_LIBRARY})

target_link_libraries (ila
  ast
  ${EXT_LIBRARIES}
  ${Boost_LIBRARIES})

include_directories(${CMAKE_CURRENT_BINARY_DIR})
set(AVY_BUILD_MODE ${CMAKE_BUILD_TYPE})
set_target_properties(ila PROPERTIES PREFIX "")
