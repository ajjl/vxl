# brl/bbas/bkml/CMakeLists.txt
# KML utilities for Brown University Libraries

set(bkml_sources
  bkml_write.h bkml_write.cxx
)

include( ${BRL_MODULE_PATH}/FindEXPAT.cmake )

if(EXPAT_FOUND)
 if(EXPATPP_FOUND)
  include_directories(${EXPAT_INCLUDE_DIRS} )
  include_directories(${EXPATPP_INCLUDE_DIRS} )
  set(bkml_sources ${bkml_sources}
     bkml_parser.cxx    bkml_parser.h
  )
 endif()
endif()

add_library(bkml  ${bkml_sources})

target_link_libraries(bkml vgl)

if(EXPAT_FOUND)
  target_link_libraries(bkml ${EXPAT_LIBRARIES})
  if(APPLE)
    target_link_libraries(bkml expat)
  endif()
  if(EXPATPP_FOUND)
    target_link_libraries(bkml ${EXPATPP_LIBRARIES})
  endif()
endif()

if( BUILD_TESTING )
  add_subdirectory(tests)
endif()

#add_subdirectory(pro)

install_targets(/lib bkml)
INSTALL_NOBASE_HEADER_FILES(/include/vxl/contrib/brl/bbas/bkml ${bkml_sources})
