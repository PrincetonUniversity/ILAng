# path = root/test 
include(CTest)
enable_testing()

# gtest
#add_executable(${TEST_MAIN} ${TESTFILES})
#add_dependencies(${TEST_MAIN} googletest engine)
#target_link_libraries(${TEST_MAIN} googletest engine pthread)
#add_custom_target(gtest 
#    COMMAND "${PROJECT_BINARY_DIR}/${TEST_MAIN}"
#    DEPENDS engine ${TEST_MAIN})
# standard test
#add_test(unit_tests ${PROJECT_BINARY_DIR}/${TEST_MAIN})
