# temporary include
include_directories(${OXL_INCLUDE_DIR})

add_executable( vpgl_algo_test_all
  test_driver.cxx
  test_optimize_camera.cxx
  test_fm_compute.cxx
  test_camera_compute.cxx
  test_camera_convert.cxx
  test_lens_warp_mapper.cxx
  test_backproject.cxx
  test_ray.cxx
  test_ray_intersect.cxx
  test_ortho_procrustes.cxx
  test_rational_adjust_onept.cxx
  test_rational_adjust.cxx
  test_em_compute_5_point.cxx
  test_triangulate.cxx
  test_ba_fixed_k_lsqr.cxx
  test_ba_shared_k_lsqr.cxx
  test_bundle_adjust.cxx
  test_affine_rectification.cxx
)

target_link_libraries( vpgl_algo_test_all vpgl_algo vgl_algo vgl vnl_algo vnl vil vul testlib )

add_test( NAME vpgl_algo_test_camera_compute COMMAND $<TARGET_FILE:vpgl_algo_test_all> test_camera_compute )
add_test( NAME vpgl_algo_test_camera_convert COMMAND $<TARGET_FILE:vpgl_algo_test_all> test_camera_convert )
add_test( NAME vpgl_algo_test_optimize_camera COMMAND $<TARGET_FILE:vpgl_algo_test_all> test_optimize_camera )
add_test( NAME vpgl_algo_test_fm_compute COMMAND $<TARGET_FILE:vpgl_algo_test_all> test_fm_compute )
add_test( NAME vpgl_algo_test_rational_adjust_onept COMMAND $<TARGET_FILE:vpgl_algo_test_all> test_rational_adjust_onept )
add_test( NAME vpgl_algo_test_rational_adjust COMMAND $<TARGET_FILE:vpgl_algo_test_all> test_rational_adjust )
add_test( NAME vpgl_algo_test_lens_warp_mapper COMMAND $<TARGET_FILE:vpgl_algo_test_all> test_lens_warp_mapper )
add_test( NAME vpgl_algo_test_backproject COMMAND $<TARGET_FILE:vpgl_algo_test_all> test_backproject )
add_test( NAME vpgl_algo_test_ray COMMAND $<TARGET_FILE:vpgl_algo_test_all> test_ray )
add_test( NAME vpgl_algo_test_ray_intersect COMMAND $<TARGET_FILE:vpgl_algo_test_all> test_ray_intersect )
add_test( NAME vpgl_algo_test_ortho_procrustes COMMAND $<TARGET_FILE:vpgl_algo_test_all> test_ortho_procrustes )
add_test( NAME vpgl_algo_test_em_compute_5_point COMMAND $<TARGET_FILE:vpgl_algo_test_all> test_em_compute_5_point )
add_test( NAME vpgl_algo_test_triangulate COMMAND $<TARGET_FILE:vpgl_algo_test_all> test_triangulate )
add_test( NAME vpgl_algo_test_bundle_adjust COMMAND $<TARGET_FILE:vpgl_algo_test_all> test_bundle_adjust )
add_test( NAME vpgl_algo_test_ba_fixed_k_lsqr COMMAND $<TARGET_FILE:vpgl_algo_test_all> test_ba_fixed_k_lsqr )
add_test( NAME vpgl_algo_test_ba_shared_k_lsqr COMMAND $<TARGET_FILE:vpgl_algo_test_all> test_ba_shared_k_lsqr )
add_test( NAME vpgl_algo_test_affine_rect COMMAND $<TARGET_FILE:vpgl_algo_test_all> test_affine_rect )

add_executable( vpgl_algo_test_include test_include.cxx )
target_link_libraries( vpgl_algo_test_include vpgl_algo )
add_executable( vpgl_algo_test_template_include test_template_include.cxx )
target_link_libraries( vpgl_algo_test_template_include vpgl_algo )
