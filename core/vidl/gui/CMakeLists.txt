# core/vidl/gui/CMakeLists.txt
# This library adds vgui features to vidl

include( ${VXL_CMAKE_DIR}/UseVGUI.cmake )

if( HAS_VGUI )

set(vidl_gui_sources
    vidl_gui_param_dialog.cxx   vidl_gui_param_dialog.h

    vidl_capture_tableau.cxx    vidl_capture_tableau.h     vidl_capture_tableau_sptr.h
   )

add_library(vidl_gui ${vidl_gui_sources})
install_targets(/lib vidl_gui)
INSTALL_NOBASE_HEADER_FILES(/include/vxl/core/vidl/gui ${vidl_gui_sources})
target_link_libraries( vidl_gui vidl vgui vil )

if( BUILD_TESTING )
  add_subdirectory(tests)
endif()

endif()
