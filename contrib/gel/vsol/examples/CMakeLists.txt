include_directories( ${VXLCORE_INCLUDE_DIR} )

add_executable( vsol_spatial_object_example vsol_spatial_object_example.cxx )
target_link_libraries( vsol_spatial_object_example vsol )

add_executable( vsol_point_example vsol_point_example.cxx )
target_link_libraries( vsol_point_example vsol )

add_executable( vsol_conic_example vsol_conic_example.cxx )
target_link_libraries( vsol_conic_example vsol vgl_algo vgl )
