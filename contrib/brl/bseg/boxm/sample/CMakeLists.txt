# brl/bseg/boxm/sample/CMakeLists.txt
include_directories( ${MUL_INCLUDE_DIR} )
set(boxm_sample_sources
    boxm_edge_sample.h                        boxm_edge_sample.txx
    boxm_edge_tangent_sample.h                boxm_edge_tangent_sample.txx
    boxm_inf_line_sample.h                    boxm_inf_line_sample.txx
    boxm_opt2_sample.h                        boxm_opt2_sample.txx
    boxm_opt3_sample.h                        boxm_opt3_sample.txx
    boxm_plane_obs.h                          boxm_plane_obs.txx
    boxm_rt_sample.h                          boxm_rt_sample.txx
    boxm_sample.h                             boxm_sample.txx
    boxm_sample_multi_bin.h                   boxm_sample_multi_bin.txx
    boxm_scalar_sample.h                      boxm_scalar_sample.txx
    boxm_vis_implicit_sample.h
    boxm_update_sample.h
    dummy.cxx
   )

aux_source_directory(Templates boxm_sample_sources)

add_library(boxm_sample ${boxm_sample_sources})
target_link_libraries(boxm_sample boxm vgl_io bsta vil vgl vbl vsl vcl)

if( BUILD_TESTING )
  add_subdirectory(tests)
endif()

#processors for the samples
add_subdirectory(algo)
