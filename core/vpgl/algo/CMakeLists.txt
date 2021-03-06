# core/vpgl/algo/CMakeLists.txt
# Photogrammetry Algorithms Library.


set( vpgl_algo_sources
  vpgl_optimize_camera.h           vpgl_optimize_camera.cxx
  vpgl_calibration_matrix_compute.h vpgl_calibration_matrix_compute.cxx
  vpgl_camera_compute.h            vpgl_camera_compute.cxx
  vpgl_camera_convert.h             vpgl_camera_convert.cxx
  vpgl_camera_homographies.h        vpgl_camera_homographies.cxx
  vpgl_fm_compute_7_point.h        vpgl_fm_compute_7_point.cxx
  vpgl_fm_compute_8_point.h        vpgl_fm_compute_8_point.cxx
  vpgl_fm_compute_2_point.h        vpgl_fm_compute_2_point.cxx
  vpgl_em_compute_5_point.h        vpgl_em_compute_5_point.txx
  vpgl_lens_warp_mapper.h
  vpgl_invmap_cost_function.h      vpgl_invmap_cost_function.cxx
  vpgl_backproject.h               vpgl_backproject.cxx
  vpgl_ray.h                       vpgl_ray.cxx
  vpgl_ray_intersect.h              vpgl_ray_intersect.txx
  vpgl_ortho_procrustes.h          vpgl_ortho_procrustes.cxx
  vpgl_rational_adjust_onept.h     vpgl_rational_adjust_onept.cxx
  vpgl_rational_adjust.h           vpgl_rational_adjust.cxx
  vpgl_rational_adjust_multipt.h   vpgl_rational_adjust_multipt.cxx
  vpgl_triangulate_points.h        vpgl_triangulate_points.cxx
  vpgl_bundle_adjust.h             vpgl_bundle_adjust.cxx
  vpgl_bundle_adjust_lsqr.h        vpgl_bundle_adjust_lsqr.cxx
  vpgl_ba_fixed_k_lsqr.h           vpgl_ba_fixed_k_lsqr.cxx
  vpgl_ba_shared_k_lsqr.h          vpgl_ba_shared_k_lsqr.cxx
  vpgl_affine_rectification.h      vpgl_affine_rectification.cxx
  vpgl_camera_transform.h          vpgl_camera_transform.cxx
)

aux_source_directory(Templates vpgl_algo_sources)

add_library(vpgl_algo ${vpgl_algo_sources})

target_link_libraries(vpgl_algo vpgl vpgl_file_formats vgl_algo vnl_algo vnl vgl vil vul vbl)


if( BUILD_TESTING )
  add_subdirectory(tests)
endif()

if( BUILD_EXAMPLES )
  add_subdirectory(examples)
endif()

install_targets(/lib vpgl_algo)
INSTALL_NOBASE_HEADER_FILES(/include/vxl/core/vpgl/algo ${vpgl_algo_sources})
