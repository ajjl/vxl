# This is mul/ipts/tools/CMakeLists.txt

link_libraries( ipts vimt_algo vimt vil_algo vil vgl vul )
add_executable( find_dog_peaks find_dog_peaks.cxx )
add_executable( find_scale_corners find_scale_corners.cxx )
add_executable( show_local_entropy show_local_entropy.cxx )
add_executable( show_orientation_entropy show_orientation_entropy.cxx )
add_executable( find_scale_entropy_peaks find_scale_entropy_peaks.cxx )
add_executable( find_scale_orient_entropy_peaks find_scale_orient_entropy_peaks.cxx )
