# bvxm_algo Process Library

# bprb depends on expat and this process library depends on bprb
include( ${BRL_MODULE_PATH}/FindEXPAT.cmake )
 if(EXPAT_FOUND)
 if(EXPATPP_FOUND)
  include_directories( ${BRL_INCLUDE_DIR}/bpro )
  include_directories( ${BRL_INCLUDE_DIR}/bpro/bprb )
  include_directories( ${BRL_INCLUDE_DIR}/bseg )
  include_directories( ${EXPAT_INCLUDE_DIRS} )
  include_directories( ${EXPATPP_INCLUDE_DIRS} )

  set(bvxm_algo_pro_sources
      bvxm_algo_processes.h
      bvxm_algo_register.h   bvxm_algo_register.cxx
     )
  aux_source_directory(processes bvxm_algo_pro_sources)

  add_library(bvxm_algo_pro ${bvxm_algo_pro_sources} )
  target_link_libraries(bvxm_algo_pro bvxm_algo bvxm_grid_pro boxm boct bprb brdb vul vbl)

  if( BUILD_TESTING )
    add_subdirectory(tests)
  endif()

 endif()
endif()
