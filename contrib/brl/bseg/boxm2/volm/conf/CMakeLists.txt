#This is boxm2/volm/conf/CMakeLists.txt
# volumetric configurational matcher library

include_directories( ${BRL_INCLUDE_DIR} )
include_directories( ${BRL_INCLUDE_DIR}/bbas/volm )

set(boxm2_volm_conf_sources
  boxm2_volm_conf_matcher.h       boxm2_volm_conf_matcher.cxx
)

add_library(boxm2_volm_conf ${boxm2_volm_conf_sources})

target_link_libraries(boxm2_volm_conf boxm2_volm boxm2 boxm2_io volm volm_conf vul vgl vcl)

if(BUILD_TESTING)
  add_subdirectory(tests)
endif()

add_subdirectory(exe)
