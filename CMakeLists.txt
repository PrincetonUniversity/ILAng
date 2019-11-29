cmake_minimum_required(VERSION 3.8)

project(vcdparser VERSION 1.0 LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 11)

option(VCD_PARSER_BUILD_DOCS "Build documents." OFF)
option(VCD_PARSER_EXPORT_PACAKGE "Export package if enabled." OFF)

# ------------------------------------------------------------------------
set(VCD_PARSER_TARGET_NAME                 ${PROJECT_NAME})
set(VCD_PARSER_CONFIG_INSTALL_DIR          "lib/cmake/${PROJECT_NAME}" CACHE INTERNAL "")
set(VCD_PARSER_INCLUDE_INSTALL_DIR         "include")
set(VCD_PARSER_INCLUDE_BUILD_DIR           "${PROJECT_SOURCE_DIR}/include")
set(VCD_PARSER_TARGETS_EXPORT_NAME         "${PROJECT_NAME}Targets")
set(VCD_PARSER_CMAKE_CONFIG_TEMPLATE       "cmake/config.cmake.in")
set(VCD_PARSER_CMAKE_CONFIG_DIR            "${CMAKE_CURRENT_BINARY_DIR}")
set(VCD_PARSER_CMAKE_VERSION_CONFIG_FILE   "${VCD_PARSER_CMAKE_CONFIG_DIR}/${PROJECT_NAME}ConfigVersion.camke")
set(VCD_PARSER_CMAKE_PROJECT_CONFIG_FILE   "${VCD_PARSER_CMAKE_CONFIG_DIR}/${PROJECT_NAME}Config.cmake")
set(VCD_PARSER_CMAKE_PROJECT_TARGETS_FILE  "${PROJECT_NAME}Targets.cmake")


# ------------------------------------------------------------------------

set(LIBRARY_NAME ${PROJECT_NAME})
set(EXECUTABLE_NAME ${LIBRARY_NAME}exec)

add_subdirectory(./src)

# ------------------------------------------------------------------------
# install

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  ${VCD_PARSER_CMAKE_VERSION_CONFIG_FILE}
  COMPATIBILITY AnyNewerVersion
)

configure_file(
  ${VCD_PARSER_CMAKE_CONFIG_TEMPLATE}
  ${VCD_PARSER_CMAKE_PROJECT_CONFIG_FILE}
  @ONLY
)

install(
  FILES ${VCD_PARSER_CMAKE_PROJECT_CONFIG_FILE} ${VCD_PARSER_CMAKE_VERSION_CONFIG_FILE}
  DESTINATION ${VCD_PARSER_CONFIG_INSTALL_DIR}
)

install(
  EXPORT ${VCD_PARSER_TARGETS_EXPORT_NAME}
  DESTINATION ${VCD_PARSER_CONFIG_INSTALL_DIR}
  NAMESPACE ${PROJECT_NAME}::
  FILE ${VCD_PARSER_PROJECT_TARGETS_FILE}
)

export(
  TARGETS ${LIBRARY_NAME}
  NAMESPACE ${PROJECT_NAME}::
  FILE ${VCD_PARSER_CMAKE_PROJECT_TARGETS_FILE}
)

if(${VCD_PARSER_EXPORT_PACKAGE})
  export(PACKAGE ${PROJECT_NAME})
endif()


# ---------------------------------------------------------------------------- #
# UNINSTALL
# uninstall files listed in install_manifest.txt
# ---------------------------------------------------------------------------- #
if(NOT TARGET uninstall)
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake/cmake_uninstall.cmake"
    IMMEDIATE @ONLY
  )

  add_custom_target(uninstall
    COMMAND 
      ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake/cmake_uninstall.cmake
  )

endif()


# ------------------------------------------------------------------------

