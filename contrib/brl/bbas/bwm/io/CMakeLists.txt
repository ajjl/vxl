# brl/bbas/bwm/io/CMakeLists.txt

set(bwm_io_sources
   bwm_io_structs.h
   bwm_site.h                  bwm_site.cxx
   bwm_site_sptr.h
)
aux_source_directory(Templates bwm_io_sources)

include( ${BRL_MODULE_PATH}/FindEXPAT.cmake )

if(EXPAT_FOUND)
 if(EXPATPP_FOUND)
  include_directories(${EXPAT_INCLUDE_DIRS} )
  include_directories(${EXPATPP_INCLUDE_DIRS} )
  set(bwm_io_sources ${bwm_io_sources}
     bwm_io_config_parser.cxx    bwm_io_config_parser.h
     bwm_io_kml_parser.cxx    bwm_io_kml_parser.h
     bwm_io_kml_camera.cxx     bwm_io_kml_camera.h
  )
 endif()
endif()

add_library(bwm_io ${bwm_io_sources})

target_link_libraries(bwm_io vsol vsl vbl)

if(EXPAT_FOUND)
  target_link_libraries(bwm_io ${EXPAT_LIBRARIES})
  if(APPLE)
    target_link_libraries(bwm_io expat)
  endif()
  if(EXPATPP_FOUND)
    target_link_libraries(bwm_io ${EXPATPP_LIBRARIES})
  endif()
endif()

if( BUILD_TESTING )
  add_subdirectory(tests)
endif()

#install the .h .txx and libs
install_targets(/lib bwm_io)
INSTALL_NOBASE_HEADER_FILES(/include/vxl/contrib/brl/bbas/bwm/io ${bwm_io_sources})
