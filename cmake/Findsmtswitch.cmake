# FindSMT_SWITCH.cmake
# Finds the smt-switch library
#
# This will define the following variables
#
#   SMTSWITCH_FOUND
#   SMTSWITCH_INCLUDE_DIR
#   SMTSWITCH_LIBRARY
#
#   SMTSWITCH_BTOR_FOUND
#   SMTSWITCH_CVC4_FOUND
#   SMTSWITCH_MSAT_FOUND
#   SMTSWITCH_YICES2_FOUND
#
# and the following imported targets
#
#   smt-switch::smt-switch
#   smt-switch::smt-switch-btor
#   smt-switch::smt-switch-cvc4
#   smt-switch::smt-switch-msat
#   smt-switch::smt-switch-yices2
# 

# XXX smt-switch needs to be built with static type
# XXX @smt-switch config time, set SMT_SWITCH_LIB_TYPE to STATIC

find_package(PkgConfig)
pkg_check_modules(PC_SMTSWITCH QUIET SMTSWITCH)

##
## core smt-switch
##
find_path(SMTSWITCH_INCLUDE_DIR
  NAMES "smt-switch/smt.h"
  HINTS ${PC_SMTSWITCH_INCLUDEDIR} ${PC_SMTSWITCH_INCLUDE_DIRS}
  PATH_SUFFIXES smt-switch
)

find_library(SMTSWITCH_LIBRARY 
  NAMES smt-switch
  HINTS ${PC_SMTSWITCH_LIBDIR} ${PC_SMTSWITCH_LIBRARY_DIRS}
  PATH_SUFFIXES smt-switch
)

mark_as_advanced(SMTSWITCH_FOUND SMTSWITCH_INCLUDE_DIR STM_SWITCH_LIBRARY)

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(smtswitch DEFAULT_MSG 
  SMTSWITCH_INCLUDE_DIR 
  SMTSWITCH_LIBRARY
)

##
## solver backends
##

# boolector
find_library(SMTSWITCH_BTOR_LIBRARY
  NAMES smt-switch-btor
  HINTS ${PC_SMTSWITCH_LIBDIR} ${PC_SMTSWITCH_LIBRARY_DIRS}
  PATH_SUFFIXES smt-switch
)

if(SMTSWITCH_BTOR_LIBRARY)
  set(SMTSWITCH_BTOR_FOUND TRUE)
else()
  set(SMTSWITCH_BTOR_FOUND FALSE)
endif()

set(SMTSWITCH_BTOR_LIBRARY ${SMTSWITCH_BTOR_LIBRARY} ${SMTSWITCH_LIBRARY})
mark_as_advanced(SMTSWITCH_BTOR_FOUND)

# cvc4
find_library(SMTSWITCH_CVC4_LIBRARY
  NAMES smt-switch-cvc4
  HINTS ${PC_SMTSWITCH_LIBDIR} ${PC_SMTSWITCH_LIBRARY_DIRS}
  PATH_SUFFIXES smt-switch
)

if(SMTSWITCH_CVC4_LIBRARY)
  set(SMTSWITCH_CVC4_FOUND TRUE)
else()
  set(SMTSWITCH_CVC4_FOUND FALSE)
endif()

set(SMTSWITCH_CVC4_LIBRARY ${SMTSWITCH_CVC4_LIBRARY} ${SMTSWITCH_LIBRARY})
mark_as_advanced(SMTSWITCH_CVC4_FOUND)

# math SAT
find_library(SMTSWITCH_MSAT_LIBRARY
  NAMES smt-switch-msat
  HINTS ${PC_SMTSWITCH_LIBDIR} ${PC_SMTSWITCH_LIBRARY_DIRS}
  PATH_SUFFIXES smt-switch
)

if(SMTSWITCH_MSAT_LIBRARY)
  set(SMTSWITCH_MSAT_FOUND TRUE)
else()
  set(SMTSWITCH_MSAT_FOUND FALSE)
endif()

set(SMTSWITCH_MSAT_LIBRARY ${SMTSWITCH_MSAT_LIBRARY} ${SMTSWITCH_LIBRARY})
mark_as_advanced(SMTSWITCH_MSAT_FOUND)

# yices2
find_library(SMTSWITCH_YICES2_LIBRARY
  NAMES smt-switch-yices2
  HINTS ${PC_SMTSWITCH_LIBDIR} ${PC_SMTSWITCH_LIBRARY_DIRS}
  PATH_SUFFIXES smt-switch
)

if(SMTSWITCH_YICES2_LIBRARY)
  set(SMTSWITCH_YICES2_FOUND TRUE)
else()
  set(SMTSWITCH_YICES2_FOUND FALSE)
endif()

set(SMTSWITCH_YICES2_LIBRARY ${SMTSWITCH_YICES_LIBRARY} ${SMTSWITCH_LIBRARY})
mark_as_advanced(SMTSWITCH_YICES2_FOUND)

# create imported target smt-switch::smt-switch
if(SMTSWITCH_FOUND AND NOT TARGET smt-switch::smt-switch)
  add_library(smt-switch::smt-switch INTERFACE IMPORTED)
  set_property(
    TARGET smt-switch::smt-switch
    PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${SMTSWITCH_INCLUDE_DIR}
  )
  set_property(
    TARGET smt-switch::smt-switch
    PROPERTY INTERFACE_LINK_LIBRARIES ${SMTSWITCH_LIBRARY}
  )
endif()

# create imported target smt-switch::smt-switch-btor
if(SMTSWITCH_BTOR_FOUND AND NOT TARGET smt-switch::smt-switch-btor)
  add_library(smt-switch::smt-switch-btor INTERFACE IMPORTED)
  set_property(
    TARGET smt-switch::smt-switch-btor
    PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${SMTSWITCH_INCLUDE_DIR}
  )
  set_property(
    TARGET smt-switch::smt-switch-btor
    PROPERTY INTERFACE_LINK_LIBRARIES ${SMTSWITCH_BTOR_LIBRARY}
  )
endif()

# create imported target smt-switch::smt-switch-cvc4
if(SMTSWITCH_CVC4_FOUND AND NOT TARGET smt-switch::smt-switch-cvc4)
  add_library(smt-switch::smt-switch-cvc4 INTERFACE IMPORTED)
  set_property(
    TARGET smt-switch::smt-switch-cvc4
    PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${SMTSWITCH_INCLUDE_DIR}
  )
  set_property(
    TARGET smt-switch::smt-switch-cvc4
    PROPERTY INTERFACE_LINK_LIBRARIES ${SMTSWITCH_CVC4_LIBRARY}
  )
endif()

# create imported target smt-switch::smt-switch-msat
if(SMTSWITCH_MSAT_FOUND AND NOT TARGET smt-switch::smt-switch-msat)
  add_library(smt-switch::smt-switch-msat INTERFACE IMPORTED)
  set_property(
    TARGET smt-switch::smt-switch-msat
    PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${SMTSWITCH_INCLUDE_DIR}
  )
  set_property(
    TARGET smt-switch::smt-switch-msat
    PROPERTY INTERFACE_LINK_LIBRARIES ${SMTSWITCH_MSAT_LIBRARY}
  )
endif()

# create imported target smt-switch::smt-switch-yices2
if(SMTSWITCH_YICES2_FOUND AND NOT TARGET smt-switch::smt-switch-yices2)
  add_library(smt-switch::smt-switch-yices2 INTERFACE IMPORTED)
  set_property(
    TARGET smt-switch::smt-switch-yices2
    PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${SMTSWITCH_INCLUDE_DIR}
  )
  set_property(
    TARGET smt-switch::smt-switch-yices2
    PROPERTY INTERFACE_LINK_LIBRARIES ${SMTSWITCH_YICES2_LIBRARY}
  )
endif()

