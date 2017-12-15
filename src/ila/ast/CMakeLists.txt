# path = root/src/ila/ast

file(GLOB AST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")

add_library(ast ${AST_SOURCES})

