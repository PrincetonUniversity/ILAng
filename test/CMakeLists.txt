# ---------------------------------------------------------------------------- #
# External dependency
# ---------------------------------------------------------------------------- #
add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest" "extern/googletest" 
  EXCLUDE_FROM_ALL)

##
## To keep cache clean
##
mark_as_advanced(
  BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
  gmock_build_tests gtest_build_samples gtest_build_tests
  gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

##
## Keep IDEs that support folders clean
##
set_target_properties(gtest PROPERTIES FOLDER extern)
set_target_properties(gtest_main PROPERTIES FOLDER extern)
set_target_properties(gmock PROPERTIES FOLDER extern)
set_target_properties(gmock_main PROPERTIES FOLDER extern)

##
## Macro for adding new test
##
macro(package_add_test TESTNAME)
  add_executable(${TESTNAME} ${ARGN})
  target_link_libraries(${TESTNAME} gtest gmock gtest_main)
  add_test(${TESTNAME} ${TESTNAME})
  set_target_properties(${TESTNAME} PROPERTIES FOLDER test)
endmacro()

# ---------------------------------------------------------------------------- #
# TARGET
# unit tests 
# ---------------------------------------------------------------------------- #
set(ILANG_TEST_MAIN unit_tests)

package_add_test(${ILANG_TEST_MAIN} 
  unit-src/eq_ilas.cc
  unit-src/simple_cpu.cc
  unit-src/stream_buffer.cc
  unit-src/mcm_ilas.cc
  t_api.cc
  t_crr.cc
  t_eq_check.cc
  t_expr.cc
  t_expr_const.cc
  t_expr_fuse.cc
  t_expr_op.cc
  t_expr_var.cc
  t_func.cc
  t_hash_ast.cc
  t_ila.cc
  t_instr.cc
  t_instr_seq.cc
  t_jsonio.cc
  t_keyvec.cc
  t_legacy_bmc.cc
  t_log.cc
  t_main.cc
  t_mapset.cc
  t_op_sanity.cc
  t_sort.cc
  t_symbol.cc
  t_unroll_seq.cc
  t_verilog.cc
  t_verilog_gen.cc
  t_z3adapter.cc
  t_z3sanity.cc
  t_mcm.cc
)

if(${ILANG_BUILD_SYNTH})

  target_sources(${ILANG_TEST_MAIN} PRIVATE
    t_synth_import.cc
  )

  configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/unit-data/aes_v/all
    ${CMAKE_CURRENT_BINARY_DIR}/unit-data/aes_v/all
  )

  configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/unit-data/aes_v/allu
    ${CMAKE_CURRENT_BINARY_DIR}/unit-data/aes_v/allu
  )

endif()

target_link_libraries(${ILANG_TEST_MAIN} ${ILANG_LIB_NAME})

add_custom_target(run_test
  COMMAND "${CMAKE_CURRENT_BINARY_DIR}/${ILANG_TEST_MAIN}"
)


# ---------------------------------------------------------------------------- #
# TARGET
# building test
# ---------------------------------------------------------------------------- #
add_test(
  NAME
    ExampleCMakeBuild
  COMMAND
    "${CMAKE_CTEST_COMMAND}"
      --build-and-test  "${PROJECT_SOURCE_DIR}/examples/simple"
                        "${CMAKE_CURRENT_BINARY_DIR}/simple"
      --build-generator "${CMAKE_GENERATOR}"
      --test-command    "${CMAKE_CTEST_COMMAND}"
)

