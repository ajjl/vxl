# brl/bbas/bwm/reg/tests/CMakeLists.txt
include_directories( ${VXLCORE_INCLUDE_DIR} )
include_directories( ${GEL_INCLUDE_DIR})
include_directories( ${BRL_INCLUDE_DIR})

add_executable(bwm_reg_test_all
  test_driver.cxx
  test_champher.cxx
  test_matcher.cxx
  test_processor.cxx
)
target_link_libraries(bwm_reg_test_all bwm_reg vsol vnl vil vgl testlib)

add_test( NAME bwm_reg_test_champher COMMAND $<TARGET_FILE:bwm_reg_test_all> test_champher)
add_test( NAME bwm_reg_test_matcher COMMAND $<TARGET_FILE:bwm_reg_test_all> test_matcher)
add_test( NAME bwm_reg_test_processor COMMAND $<TARGET_FILE:bwm_reg_test_all> test_processor)

add_executable(bwm_reg_test_include test_include.cxx)
target_link_libraries(bwm_reg_test_include bwm_reg)
