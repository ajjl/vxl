# brl/bseg/boxm/basic/CMakeLists.txt
include_directories( ${MUL_INCLUDE_DIR} )
set(boxm_basic_sources
    boxm_block_vis_graph_iterator.h     boxm_block_vis_graph_iterator.txx
    boxm_block_vis_graph_node.h
    boxm_cell_vis_graph_iterator.h      boxm_cell_vis_graph_iterator.txx
    boxm_raytrace_function.h
    boxm_seg_length_functor.h
    boxm_num_rays_functor.h
    boxm_util_data_types.h boxm_util_data_types.cxx
   )

aux_source_directory(Templates boxm_basic_sources)

add_library(boxm_basic ${boxm_basic_sources})

if( BUILD_TESTING )
  add_subdirectory(tests)
endif()

target_link_libraries(boxm_basic boxm boxm_util boxm_sample boxm_sample_algo boct vpgl vpgl_algo vgl_io vgl vil vul vbl_io vbl vcl)
