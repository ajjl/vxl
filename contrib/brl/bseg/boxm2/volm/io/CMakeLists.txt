# contrib/brl/bseg/boxm2/volm/io/CMakeLists.txt

set(boxm2_volm_io_sources
    boxm2_volm_io_locations.h boxm2_volm_io_locations.cxx
   )

aux_source_directory(Templates boxm2_volm_io_sources)

add_library(boxm2_volm_io ${boxm2_volm_io_sources})
target_link_libraries(boxm2_volm_io boxm2_volm vsl vbl vbl_io)

if( BUILD_TESTING )
  add_subdirectory(tests)
endif()
