# v3p/zlib/CMakeLists.txt

project( zlib C )

include(${VXL_CMAKE_DIR}/FindZLIB.cmake)

if(NOT VXL_USING_NATIVE_ZLIB)

set( zlib_sources
  zlib.h
  zconf.h

  adler32.c
  compress.c
  crc32.c
  gzio.c
  uncompr.c
  deflate.c deflate.h
  trees.c trees.h
  zutil.c zutil.h
  inflate.c
  infblock.c infblock.h
  inftrees.c inftrees.h
  infcodes.c infcodes.h
  infutil.c infutil.h
  inffast.c inffast.h
            inffixed.h
)


if(CMAKE_COMPILER_IS_GNUCXX)
  set_source_files_properties(deflate.c PROPERTIES COMPILE_FLAGS -O1)
endif()

add_library( z ${zlib_sources} )
install_targets( /lib z )

endif()

