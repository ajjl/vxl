# mul/msm/CMakeLists.txt
#
#   Tim Cootes
#

doxygen_add_library(contrib/mul/msm_utils
  DEPENDS contrib/mul/msm
  PACKAGE contrib/mul
  DESCRIPTION "Utils for Manchester's SM Library"
)

set(msm_utils_sources
  msm_draw_shape_to_eps.h       msm_draw_shape_to_eps.cxx
  msm_shape_mode_view.h         msm_shape_mode_view.cxx
)

# aux_source_directory(Templates msm_utils_sources)
add_library(msm_utils ${msm_utils_sources} )
target_link_libraries(msm_utils msm vgl)

if( BUILD_TESTING)
  add_subdirectory(tests)
endif()
