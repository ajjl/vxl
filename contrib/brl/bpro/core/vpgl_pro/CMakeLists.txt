# brl/bpro/core/vpgl_pro/CMakeLists.txt
# Brown vpgl processes

include_directories( ${BRL_INCLUDE_DIR} )
include_directories( ${BRL_INCLUDE_DIR}/bpro )
include_directories( ${BRL_INCLUDE_DIR}/bpro/core )
include_directories( ${GEL_INCLUDE_DIR})
if(EXPAT_FOUND)
 if(EXPATPP_FOUND)
  include_directories(${EXPAT_INCLUDE_DIRS} )
  include_directories(${EXPATPP_INCLUDE_DIRS} )
 endif()
endif()

set( vpgl_pro_sources
  vpgl_processes.h
  vpgl_register.h      vpgl_register.cxx
)
aux_source_directory(Templates vpgl_pro_sources)
aux_source_directory(processes vpgl_pro_sources)

add_library(vpgl_pro ${vpgl_pro_sources})
target_link_libraries(vpgl_pro bprb vsph bpgl bpgl_algo vpgl_io vpgl vpgl_algo vnl vil vgl vbl_io vul bkml brad bbas_pro vsol)

install_targets(/lib vpgl_pro)
INSTALL_NOBASE_HEADER_FILES(/include/vxl/contrib/brl/bpro/core/vpgl_pro ${vpgl_pro_sources})

if( BUILD_TESTING )
  add_subdirectory(tests)
endif()
