add_executable( boct_test_all
  test_driver.cxx
  test_create_tree.cxx
  test_locate_point.cxx
  test_locate_region.cxx
  test_find_neighbors.cxx
  test_binary_io.cxx
  test_clone_tree.cxx
  test_tree_cell_reader.cxx
  test_bit_tree.cxx
  )

target_link_libraries( boct_test_all boct testlib vnl vgl_io vgl vpl)

add_test( NAME boct_test_locate_point COMMAND $<TARGET_FILE:boct_test_all> test_locate_point  )
add_test( NAME boct_test_create_tree COMMAND $<TARGET_FILE:boct_test_all> test_create_tree   )
add_test( NAME boct_test_locate_region COMMAND $<TARGET_FILE:boct_test_all> test_locate_region )
add_test( NAME boct_test_find_neighbors COMMAND $<TARGET_FILE:boct_test_all> test_find_neighbors)
add_test( NAME boct_test_binary_io COMMAND $<TARGET_FILE:boct_test_all> test_binary_io)
add_test( NAME boct_test_clone_tree COMMAND $<TARGET_FILE:boct_test_all> test_clone_tree   )
add_test( NAME boct_test_tree_cell_reader COMMAND $<TARGET_FILE:boct_test_all> test_tree_cell_reader   )
add_test( NAME boct_test_bit_tree COMMAND $<TARGET_FILE:boct_test_all> test_bit_tree )


add_executable( boct_test_include test_include.cxx )
target_link_libraries( boct_test_include boct vnl)
add_executable( boct_test_template_include test_template_include.cxx )
target_link_libraries( boct_test_template_include boct vnl)
