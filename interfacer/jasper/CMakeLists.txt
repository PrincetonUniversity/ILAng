# ---------------------------------------------------------------------------- #
# TARGET
# archive library 
# ---------------------------------------------------------------------------- #

set(JASPER_IF_NAME  jg-pushpull) 

add_executable(${JASPER_IF_NAME} jg_pushpull.cc)

target_include_directories(${JASPER_IF_NAME} 
  PUBLIC 
    $<INSTALL_INTERFACE:${ILANG_INCLUDE_INSTALL_DIR}>
    $<BUILD_INTERFACE:${ILANG_INCLUDE_BUILD_DIR}>
)

target_link_libraries(${JASPER_IF_NAME} ${ILANG_LIB_NAME})
