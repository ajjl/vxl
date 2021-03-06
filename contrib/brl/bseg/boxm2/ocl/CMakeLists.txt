#boxm2/ocl source dir
if(BUILD_BRL)
  set(BOXM2_OPENCL_SRC_DIR CACHE STRING "Location of OpenCL source files for brl/bseg/boxm2/ (defaults to source tree)" )
endif()

# Set up boxm2_ocl_where_root_dir.h to have a macro set to $BOXM2_OPENCL_SRC_DIR
configure_file(
  boxm2_ocl_where_root_dir.h.in
  ${vxl_BINARY_DIR}/contrib/brl/bseg/boxm2/ocl/boxm2_ocl_where_root_dir.h ESCAPE_QUOTES
)
include_directories( ${vxl_BINARY_DIR}/contrib/brl/bseg/boxm2/ocl/ )


#depends on OPENCL being found...
include( ${VXL_CMAKE_DIR}/NewCMake/FindOpenCL.cmake )
if(OPENCL_FOUND)

add_definitions(-DHAS_OPENCL=1)
include_directories( ${OPENCL_INCLUDE_PATH} )
include_directories( ${BRL_INCLUDE_DIR}/bbas )

set(boxm2_ocl_sources
    boxm2_opencl_cache.h     boxm2_opencl_cache.cxx
    boxm2_opencl_cache1.h     boxm2_opencl_cache1.cxx
    boxm2_ocl_util.h         boxm2_ocl_util.cxx
   )
aux_source_directory(Templates boxm2_ocl_sources)

add_library(boxm2_ocl ${boxm2_ocl_sources})
target_link_libraries(boxm2_ocl boxm2 boxm2_basic boxm2_io bocl boct bsta brdb expatpp vpgl vgl_xio vgl vil vnl_algo vnl vbl_io vbl vsl vcl)

#install the .h .txx and libs
install_targets(/lib boxm2_ocl)
INSTALL_NOBASE_HEADER_FILES(/include/vxl/contrib/brl/bseg/boxm2/ocl ${boxm2_ocl_sources})

#pro
add_subdirectory(pro)

#exe
add_subdirectory(exe)

#algo
add_subdirectory(algo)

#tests
if( BUILD_TESTING )
  add_subdirectory(tests)
endif()

endif()
