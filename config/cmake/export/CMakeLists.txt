# This CMakeLists.txt file handles the creation of files needed by
# other client projects that use VXL.  Nothing is built by this
# CMakeLists.txt file.  This CMakeLists.txt file must be processed by
# CMake after all the other CMakeLists.txt files in the VXL tree,
# which is why the add_subdirectory(config/cmake/export) command is at the end
# of the top level CMakeLists.txt file.

# Needed to get non-cached variable settings used in VXLConfig.cmake.in
include( ${MODULE_PATH}/FindNetlib.cmake )
include( ${MODULE_PATH}/FindZLIB.cmake )
include( ${MODULE_PATH}/FindPNG.cmake )
include( ${MODULE_PATH}/FindJPEG.cmake )
include( ${MODULE_PATH}/FindTIFF.cmake )
include( ${MODULE_PATH}/FindGEOTIFF.cmake )
set( EXPAT_FIND_QUIETLY "YES" )
include( ${vxl_SOURCE_DIR}/contrib/brl/bmods/FindEXPAT.cmake )
set( EXPAT_FIND_QUIETLY )

# Save library dependencies.
set(VXL_CMAKE_DOXYGEN_DIR  ${vxl_SOURCE_DIR}/config/cmake/doxygen)

# Create the VXLConfig.cmake file for the build tree.
configure_file(${VXL_CMAKE_DIR}/VXLConfig.cmake.in
               ${vxl_BINARY_DIR}/VXLConfig.cmake @ONLY IMMEDIATE)

configure_file(${VXL_CMAKE_DIR}/VXLConfig_export.cmake.in
               ${vxl_BINARY_DIR}/config/cmake/export/VXLConfig.cmake
               @ONLY IMMEDIATE)

install(FILES
  ${vxl_BINARY_DIR}/config/cmake/export/VXLConfig.cmake
  ${VXL_CMAKE_DIR}/VXLStandardOptions.cmake
  ${VXL_CMAKE_DIR}/UseVXL.cmake
  ${VXL_CMAKE_DIR}/UseVGUI.cmake
  DESTINATION share/vxl/cmake
)
