# ---------------------------------------------------
#  CHC Counterexample Handler
# ---------------------------------------------------

# ---------------------------------------------------------------------------- #
# TARGET
# archive library 
# ---------------------------------------------------------------------------- #

set(CHC_CEX_INTERPRET  chc-cex-interpret) 

add_executable(${CHC_CEX_INTERPRET} chc_cex_interpret.cc)

target_include_directories(${CHC_CEX_INTERPRET} 
  PUBLIC 
    $<INSTALL_INTERFACE:${ILANG_INCLUDE_INSTALL_DIR}>
    $<BUILD_INTERFACE:${ILANG_INCLUDE_BUILD_DIR}>
)

target_link_libraries(${CHC_CEX_INTERPRET} ${ILANG_LIB_NAME})
