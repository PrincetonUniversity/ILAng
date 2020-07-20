# ---------------------------------------------------------------------------- #
# source 
# ---------------------------------------------------------------------------- #
target_sources(${ILANG_LIB_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/ilator.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/ilator_dfs.cc
)

if(${ILANG_BUILD_COSIM})
  target_sources(${ILANG_LIB_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/ast_fuse.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/dfs.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/ila_sim.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/sim_gen_decode.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/sim_gen_execute.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/sim_gen_init.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/sim_gen_input.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/sim_gen_state.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/sim_gen_state_update.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/sim_gen_utils.cc
  )
endif()
