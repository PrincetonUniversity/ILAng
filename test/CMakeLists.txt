# path = root/test 
include(CTest)
enable_testing()

macro (ADD_MORE_TEST test_file_name) 
  add_executable(${test_file_name} "${test_file_name}.cc")
  add_dependencies(${test_file_name} gtest_main ila)
  target_link_libraries(${test_file_name} gtest_main ila)
  add_test(NAME ${test_file_name} 
           COMMAND ${EXECUTABLE_OUTPUT_PATH}/${test_file_name})
endmacro (ADD_MORE_TEST)

# Define each test below (with prefix "unit_")

ADD_MORE_TEST(test_ila)

add_custom_target(run 
  COMMAND "${EXECUTABLE_OUTPUT_PATH}/test_ila"
)

