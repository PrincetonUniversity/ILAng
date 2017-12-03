# path = root/test/unit-ast

set(TEST_NAME unit_ast)

file(GLOB TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")
add_executable(${TEST_NAME} ${TEST_SOURCES})
add_dependencies(${TEST_NAME} googletest ila)
target_link_libraries(${TEST_NAME} googletest pthread ila)
