# brl/bbas/bvgl/tests/CMakeLists.txt

set(bvgl_test_sources
  test_driver.cxx
  test_bvgl_changes.cxx
  test_bvgl_volume_of_intersection.cxx
  test_bvgl_ray_pyramid.cxx
  test_bvgl_intersection.cxx
  test_gen_cylinder.cxx
  test_grid_index_3d.cxx
)

#Make sure expat library is found
include( ${BRL_MODULE_PATH}/FindEXPAT.cmake )
if(EXPAT_FOUND)
  set(bvgl_test_sources ${bvgl_test_sources} test_bvgl_labelme_parser.cxx)
endif()

add_executable(bvgl_test_all ${bvgl_test_sources})
target_link_libraries(bvgl_test_all bvgl vgl vnl testlib)

add_test( NAME bvgl_test_changes COMMAND $<TARGET_FILE:bvgl_test_all> test_bvgl_changes)
add_test( NAME bvgl_test_volume_of_intersection COMMAND $<TARGET_FILE:bvgl_test_all> test_bvgl_volume_of_intersection)
add_test( NAME bvgl_test_ray_pyramid COMMAND $<TARGET_FILE:bvgl_test_all> test_bvgl_ray_pyramid)
add_test( NAME bvgl_test_intersection COMMAND $<TARGET_FILE:bvgl_test_all> test_bvgl_intersection)
add_test( NAME bvgl_test_gen_cylinder COMMAND $<TARGET_FILE:bvgl_test_all> test_gen_cylinder)
add_test( NAME bvgl_test_grid_index_3d COMMAND $<TARGET_FILE:bvgl_test_all> test_grid_index_3d)

if(EXPAT_FOUND)
  add_test( NAME bvgl_test_labelme_parser COMMAND $<TARGET_FILE:bvgl_test_all> test_bvgl_labelme_parser)
endif()

add_executable( bvgl_test_include test_include.cxx )
target_link_libraries( bvgl_test_include bvgl )
add_executable( bvgl_test_template_include test_template_include.cxx )
target_link_libraries( bvgl_test_template_include bvgl )
