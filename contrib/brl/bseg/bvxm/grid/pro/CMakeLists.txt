# This is contrib/brl/bseg/bvxm/pro/CMakeLists.txt
# bvxm's Process Library

# bprb depends on expat and bvxm_pro depends on bprb primarily
include( ${BRL_MODULE_PATH}/FindEXPAT.cmake )
if(EXPAT_FOUND)
  include_directories( ${BRL_INCLUDE_DIR}/bpro )
  include_directories( ${BRL_INCLUDE_DIR}/bpro/bprb )
  include(${VXL_CMAKE_DIR}/FindTIFF.cmake)
  if(TIFF_FOUND)
    include_directories(${TIFF_INCLUDE_DIR})
    include( ${VXL_CMAKE_DIR}/FindGEOTIFF.cmake)
    if(GEOTIFF_FOUND)
      include_directories(${GEOTIFF_INCLUDE_DIR})
    endif()
  endif()

  set(bvxm_grid_pro_sources
      bvxm_grid_processes.h
      bvxm_grid_register.h    bvxm_grid_register.cxx
     )
  aux_source_directory(Templates bvxm_grid_pro_sources)
  aux_source_directory(processes bvxm_grid_pro_sources)

  set(bvxm_grid_pro_sources ${bvxm_grid_pro_sources})

  add_library(bvxm_grid_pro ${bvxm_grid_pro_sources})

  target_link_libraries(bvxm_grid_pro bvxm_grid bvxm_grid_io bprb brdb vul vgl imesh vnl vbl_io)

  if( BUILD_TESTING )
    add_subdirectory(tests)
  endif()

endif()
