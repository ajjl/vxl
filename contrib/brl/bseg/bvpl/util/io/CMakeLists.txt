# contrib/brl/bseg/bvplutil//io/CMakeLists.txt

set(bvpl_util_io_sources
    bvpl_corner_pairs_io.h           bvpl_corner_pairs_io.cxx
    bvpl_bundler_features_2d_io.h    bvpl_bundler_features_2d_io.cxx
   )
aux_source_directory(Templates bvpl_util_io_sources)

add_library(bvpl_util_io ${bvpl_util_io_sources})
target_link_libraries(bvpl_util_io bvpl_util vbl_io vbl vsl)

if( BUILD_TESTING )
  add_subdirectory(tests)
endif()
