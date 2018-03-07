# path = root/test 
include(CTest)
enable_testing()

set(TEST_MAIN test_main)
set(ILA_TOOLS ila++)
file(GLOB TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc"
                       "${CMAKE_CURRENT_SOURCE_DIR}/unit-src/*.cc"
    )
set(EXTRA_LIBS gtest_main ${ILA_TOOLS})
add_executable(${TEST_MAIN} ${TEST_SOURCES})
add_dependencies(${TEST_MAIN} ${EXTRA_LIBS})
target_link_libraries(${TEST_MAIN} ${EXTRA_LIBS})

macro (ADD_MORE_TEST test_file_name) 
  add_executable(${test_file_name} "${test_file_name}.cc")
  add_dependencies(${test_file_name} gtest_main ${ILA_TOOLS})
  target_link_libraries(${test_file_name} gtest_main ${ILA_TOOLS})
  add_test(NAME ${test_file_name} 
           COMMAND ${EXECUTABLE_OUTPUT_PATH}/${test_file_name})
endmacro (ADD_MORE_TEST)

# Define each test below (with prefix "test_")
#ADD_MORE_TEST(test_main)

add_custom_target(run_test 
  COMMAND "${EXECUTABLE_OUTPUT_PATH}/${TEST_MAIN}"
)

