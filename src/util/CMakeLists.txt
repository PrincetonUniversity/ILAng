# ---------------------------------------------------------------------------- #
# TARGET
# object library ${ILANG_LIB_OBJ_UTIL}
# ---------------------------------------------------------------------------- #
add_library(${ILANG_LIB_OBJ_UTIL} OBJECT 
  log.cc
  str_util.cc
)

target_compile_features(${ILANG_LIB_OBJ_UTIL} PUBLIC cxx_std_11)

target_include_directories(${ILANG_LIB_OBJ_UTIL} 
  PRIVATE ${PROJECT_SOURCE_DIR}/include
) 

