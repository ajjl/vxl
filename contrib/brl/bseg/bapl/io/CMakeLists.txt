#brl/bbas/bapl/io/CMakeLists.txt

set( bapl_io_sources
     bapl_io_dsift.h      bapl_io_dsift.cxx
   )
aux_source_directory( Templates bapl_io_sources )

include_directories( ${BRL_INCLUDE_DIR}/bseg)

add_library( bapl_io ${bapl_io_sources} )
target_link_libraries( bapl_io bapl vbl vbl_io)

if( BUILD_TESTING )
  add_subdirectory(tests)
endif()
