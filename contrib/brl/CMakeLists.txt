# brl/CMakeLists.txt
# Mutual dependencies:  bbas --> bseg  and  bbas --> bmvl

project( brl )

doxygen_add_package(contrib/brl "Brown University Libraries")

# In contrib/brl there is sometimes an "extra" level in the directory structure
# (.../contrib/brl/{bbas,bseg,bmvl}/foo/foo.h)
# Setting BRL_INCLUDE_DIR in this way allows #include <foo/foo.h> without
# having to know the internal directory structure.
# The root directory should be listed last in case anyone tries to append to this path
set( BRL_INCLUDE_DIR "${brl_SOURCE_DIR}/bbas;${brl_BINARY_DIR}/bbas;${brl_SOURCE_DIR}/bseg;${brl_SOURCE_DIR}/bpro;${brl_SOURCE_DIR}" CACHE STATIC "Brown University package include files" FORCE )
set( BRL_BINARY_DIR "${brl_BINARY_DIR}")
set( BRL_INSTALL_INCLUDE_DIR
  ${CMAKE_INSTALL_PREFIX}/include/vxl/contrib/brl
  ${CMAKE_INSTALL_PREFIX}/include/vxl/contrib/brl/bbas
  ${CMAKE_INSTALL_PREFIX}/include/vxl/contrib/brl/bseg
  ${CMAKE_INSTALL_PREFIX}/include/vxl/contrib/brl/bpro
  CACHE INTERNAL "Brown University package include files"
)

# Location of brl's private FindXXX.cmake CMake modules.
set( BRL_CMAKE_DIR ${vxl_SOURCE_DIR}/contrib/brl/bmods )
# This is identical to BRL_CMAKE_DIR.  Perhaps we should eliminate BRL_MODULE_PATH?
set( BRL_MODULE_PATH ${vxl_SOURCE_DIR}/contrib/brl/bmods )

include_directories( ${VXLCORE_INCLUDE_DIR} )
include_directories( ${BRL_INCLUDE_DIR} )

# basic services package
add_subdirectory(bbas)

if( BUILD_GEL )
  # segmentation package
  add_subdirectory(bseg)
endif()

# process libraries
add_subdirectory(bpro)

# 3rd party libraries
add_subdirectory(b3p)

# cvg library
add_subdirectory(cvg)

