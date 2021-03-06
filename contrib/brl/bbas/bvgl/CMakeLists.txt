# Brown basic geometry library
# brl/bbas/bvgl/CMakeLists.txt

doxygen_add_library(contrib/brl/bbas/bvgl
  DEPENDS core/vgl core/vnl
  PACKAGE contrib/brl
  )

include_directories(${BRL_INCLUDE_DIR})
include_directories(${BRL_INCLUDE_DIR}/bbas )
include_directories(${GEL_INCLUDE_DIR})

set(bvgl_sources
 bvgl_articulated_poly.h bvgl_articulated_poly.cxx bvgl_articulated_poly_sptr.h
 bvgl_change_obj.h   bvgl_change_obj.cxx
 bvgl_change_obj_sptr.h
 bvgl_changes.h      bvgl_changes.cxx
 bvgl_changes_sptr.h
 bvgl_point_3d_cmp.h
 bvgl_triangle_interpolation_iterator.h  bvgl_triangle_interpolation_iterator.txx
 bvgl_intersection.h                     bvgl_intersection.txx
 bvgl_triangle_3d.h                      bvgl_triangle_3d.txx
 bvgl_volume_of_intersection.h           bvgl_volume_of_intersection.txx
 bvgl_ray_pyramid.h                      bvgl_ray_pyramid.cxx
 bvgl_param_curve.h                      # EMPTY FILE bvgl_param_curve.cxx
 bvgl_cross_section.h                    bvgl_cross_section.cxx
 bvgl_gen_cylinder.h                     bvgl_gen_cylinder.cxx
 bvgl_grid_index_3d.h                    bvgl_grid_index_3d.cxx
)
aux_source_directory(Templates bvgl_sources)


#find expatpp library for
include( ${BRL_MODULE_PATH}/FindEXPAT.cmake )
if(EXPAT_FOUND)
  include_directories( ${EXPAT_INCLUDE_DIR} )
  include_directories( ${BRL_INCLUDE_DIR}/b3p/expatpp )
  set(bvgl_sources ${bvgl_sources}
      bvgl_labelme_parser.h                   bvgl_labelme_parser.cxx
     )
endif()

#Create BVGL library
add_library(bvgl ${bvgl_sources})
install_targets(/lib bvgl)
INSTALL_NOBASE_HEADER_FILES(/include/vxl/contrib/brl/bbas/bvgl ${bvgl_sources})
target_link_libraries(bvgl bvrml vsol vgl_algo vgl_io vgl vnl_algo vnl vil vbl)
if(EXPAT_FOUND)
target_link_libraries(bvgl expatpp)
endif()

if( BUILD_TESTING )
  add_subdirectory(tests)
endif()

# geometric algorithm related
add_subdirectory(algo)
