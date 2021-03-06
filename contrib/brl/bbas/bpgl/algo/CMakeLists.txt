# bpgl/algo/CMakeLists.txt
# Photogrammetry Algorithms Library.

include_directories(${VXLCORE_INCLUDE_DIR})
include_directories( ${GEL_INCLUDE_DIR} )

set( bpgl_algo_sources
  bpgl_construct_cameras.h         bpgl_construct_cameras.cxx
  bpgl_vsol_lens_warp.h            bpgl_vsol_lens_warp.cxx
  bpgl_list.h                      bpgl_list.txx
  bpgl_interpolate.h               bpgl_interpolate.cxx
  bpgl_camera_homographies.h       bpgl_camera_homographies.cxx
  bpgl_nitf_camera_coverage.h      bpgl_nitf_camera_coverage.cxx
  bpgl_camera_from_box.h           bpgl_camera_from_box.cxx
  bpgl_bundle_rolling_shutter_adjust.h  bpgl_bundle_rolling_shutter_adjust.cxx
  bpgl_project.h                   bpgl_project.cxx
  bpgl_transform_camera.h                   bpgl_transform_camera.cxx
)

# the ransac implementations use rpl/rrel
if(BUILD_RPL)
  include_directories(${RPL_INCLUDE_DIR})
  set(bpgl_algo_sources ${bpgl_algo_sources}
      bpgl_fm_compute_ransac.h         bpgl_fm_compute_ransac.cxx
      bpgl_fm_compute_reg_ransac.h     bpgl_fm_compute_reg_ransac.cxx
      bpgl_fm_compute_affine_ransac.h  bpgl_fm_compute_affine_ransac.cxx
     )
endif()


aux_source_directory(Templates bpgl_algo_sources)

add_library(bpgl_algo ${bpgl_algo_sources})

target_link_libraries(bpgl_algo bpgl vpgl vpgl_file_formats vsol vgl_algo vnl_algo vnl vgl vil vul vbl)

if(BUILD_RPL)
  target_link_libraries(bpgl_algo rrel)
endif()

if( BUILD_TESTING )
  add_subdirectory(tests)
endif()

if( BUILD_EXAMPLES )
#  add_subdirectory(examples)
endif()

install_targets(/lib bpgl_algo)
INSTALL_NOBASE_HEADER_FILES(/include/vxl/contrib/brl/bbas/bpgl/algo ${bpgl_algo_sources})
