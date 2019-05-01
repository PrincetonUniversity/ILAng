# ---------------------------------------------------------------------------- #
# TARGET
# archive library 
# ---------------------------------------------------------------------------- #

set(JASPER_INV_CHECK_NAME  jg-inv-syn) 

add_executable(${JASPER_INV_CHECK_NAME} jg_inv_check.cc)

target_include_directories(${JASPER_INV_CHECK_NAME} 
  PUBLIC 
    $<INSTALL_INTERFACE:${ILANG_INCLUDE_INSTALL_DIR}>
    $<BUILD_INTERFACE:${ILANG_INCLUDE_BUILD_DIR}>
)

target_link_libraries(${JASPER_INV_CHECK_NAME} ${ILANG_LIB_NAME})
