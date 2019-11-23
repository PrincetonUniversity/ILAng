cmake_minimum_required(VERSION 3.8)

project(smtparser VERSION 1.0 LANGUAGES C)

option(SMT_PARSER_BUILD_DOCS "Build documents." OFF)
option(SMT_PARSER_EXPORT_PACAKGE "Export package if enabled." OFF)
option(SMT_PARSER_BUILD_YICES "Build Yices if enabled." OFF)

# ------------------------------------------------------------------------
set(SMT_PARSER_TARGET_NAME                 ${PROJECT_NAME})
set(SMT_PARSER_CONFIG_INSTALL_DIR          "lib/cmake/${PROJECT_NAME}" CACHE INTERNAL "")
set(SMT_PARSER_INCLUDE_INSTALL_DIR         "include")
set(SMT_PARSER_INCLUDE_BUILD_DIR           "${PROJECT_SOURCE_DIR}/include")
set(SMT_PARSER_TARGETS_EXPORT_NAME         "${PROJECT_NAME}Targets")
set(SMT_PARSER_CMAKE_CONFIG_TEMPLATE       "cmake/config.cmake.in")
set(SMT_PARSER_CMAKE_CONFIG_DIR            "${CMAKE_CURRENT_BINARY_DIR}")
set(SMT_PARSER_CMAKE_VERSION_CONFIG_FILE   "${SMT_PARSER_CMAKE_CONFIG_DIR}/${PROJECT_NAME}ConfigVersion.camke")
set(SMT_PARSER_CMAKE_PROJECT_CONFIG_FILE   "${SMT_PARSER_CMAKE_CONFIG_DIR}/${PROJECT_NAME}Config.cmake")
set(SMT_PARSER_CMAKE_PROJECT_TARGETS_FILE  "${PROJECT_NAME}Targets.cmake")


# ------------------------------------------------------------------------

set(LIBRARY_NAME ${PROJECT_NAME}) 

add_subdirectory(./src)


# ------------------------------------------------------------------------
# install

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  ${SMT_PARSER_CMAKE_VERSION_CONFIG_FILE}
  COMPATIBILITY AnyNewerVersion
)

configure_file(
  ${SMT_PARSER_CMAKE_CONFIG_TEMPLATE}
  ${SMT_PARSER_CMAKE_PROJECT_CONFIG_FILE}
  @ONLY
)

install(
  FILES ${SMT_PARSER_CMAKE_PROJECT_CONFIG_FILE} ${SMT_PARSER_CMAKE_VERSION_CONFIG_FILE}
  DESTINATION ${SMT_PARSER_CONFIG_INSTALL_DIR}
)



install(
  EXPORT ${SMT_PARSER_TARGETS_EXPORT_NAME}
  DESTINATION ${SMT_PARSER_CONFIG_INSTALL_DIR}
  NAMESPACE ${PROJECT_NAME}::
  FILE ${SMT_PARSER_PROJECT_TARGETS_FILE}
)


export(
  TARGETS ${LIBRARY_NAME}
  NAMESPACE ${PROJECT_NAME}::
  FILE ${SMT_PARSER_CMAKE_PROJECT_TARGETS_FILE}
)

if(${SMT_PARSER_EXPORT_PACKAGE})
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

