include_directories( ${BRL_INCLUDE_DIR}/bseg )
include_directories( ${BRL_INCLUDE_DIR}/bpro/core )
include_directories( ${MUL_INCLUDE_DIR} )
set(bstm_cpp_pro_sources
    bstm_cpp_register.h                              bstm_cpp_register.cxx
    bstm_cpp_processes.h
   )
aux_source_directory(processes bstm_cpp_pro_sources)
add_library(bstm_cpp_pro  ${bstm_cpp_pro_sources})

target_link_libraries(bstm_cpp_pro bbas_pro boct bprb bstm_cpp_algo bstm bstm_io boxm2 brdb vpgl vil vgl vul vbl vcl)

if( BUILD_TESTING )
  add_subdirectory(tests)
endif()
