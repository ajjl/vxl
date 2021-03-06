# temporary include
include_directories(${OXL_INCLUDE_DIR})

add_executable( bpgl_algo_test_all
  test_driver.cxx
  test_optimize_camera.cxx
  test_fm_compute.cxx
  test_interpolate.cxx
  test_camera_homographies.cxx
  test_camera_from_box.cxx
  test_construct_cameras.cxx
  test_project.cxx
)

target_link_libraries( bpgl_algo_test_all bpgl_algo vpgl_algo vgl_algo vgl vnl_algo vnl vil vul testlib )

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/07JAN27.RPB ${CMAKE_CURRENT_BINARY_DIR}/07JAN27.RPB )

# the ransac implementations use rpl/rrel
if(BUILD_RPL)
add_test( NAME bpgl_algo_test_fm_compute COMMAND $<TARGET_FILE:bpgl_algo_test_all> test_fm_compute )
endif()

add_test( NAME bpgl_algo_test_construct_cameras COMMAND $<TARGET_FILE:bpgl_algo_test_all> test_construct_cameras )
add_test( NAME bpgl_algo_test_optimize_camera COMMAND $<TARGET_FILE:bpgl_algo_test_all> test_optimize_camera )
add_test( NAME bpgl_algo_test_interpolate COMMAND $<TARGET_FILE:bpgl_algo_test_all> test_interpolate )
add_test( NAME bpgl_algo_test_camera_homographies COMMAND $<TARGET_FILE:bpgl_algo_test_all> test_camera_homographies )
add_test( NAME bpgl_algo_test_camera_from_box COMMAND $<TARGET_FILE:bpgl_algo_test_all> test_camera_from_box )
add_test( NAME bpgl_algo_test_project COMMAND $<TARGET_FILE:bpgl_algo_test_all> test_project )

add_executable( bpgl_algo_test_include test_include.cxx )
target_link_libraries( bpgl_algo_test_include bpgl_algo )
add_executable( bpgl_algo_test_template_include test_template_include.cxx )
target_link_libraries( bpgl_algo_test_template_include bpgl_algo )
