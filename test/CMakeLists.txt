# path = root/test 
include(CTest)
enable_testing()

add_subdirectory(unit-ast)
# gtest
#add_executable(${TEST_MAIN} ${TESTFILES})
#add_dependencies(${TEST_MAIN} googletest engine)
#target_link_libraries(${TEST_MAIN} googletest engine pthread)
add_custom_target(gtest 
  COMMAND "${EXECUTABLE_OUTPUT_PATH}/${TEST_NAME}"
  DEPENDS ila ${TEST_NAME})
# standard test
add_test(unit_ast ${EXECUTABLE_OUTPUT_PATH}/${TEST_NAME})
