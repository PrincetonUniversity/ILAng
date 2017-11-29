# path = root/src/ila_ir

# build libraries for sub-components
add_subdirectory(ast)

include_directories("${CMAKE_SOURCE_DIR}/include")

#file(GLOB ILA_IR_SRC "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")
#add_library(ila_ir ${ILA_IR_SRC})

