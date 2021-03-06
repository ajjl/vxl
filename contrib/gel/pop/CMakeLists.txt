# gel/pop/CMakeLists.txt

doxygen_add_library(contrib/gel/pop
  DEPENDS core/vgl core/vnl
  PACKAGE contrib/gel
  )

if(WIN32)
 add_definitions(-D_AFXDLL)
 set(CMAKE_MFC_FLAG 6)
endif()

set(pop_sources
    pop_edge.cxx                    pop_edge.h
    pop_geometric_cost_function.cxx pop_geometric_cost_function.h
    pop_geometric_object.cxx        pop_geometric_object.h
    pop_graph_cost_function.cxx     pop_graph_cost_function.h
    pop_homography_2d.cxx           pop_homography_2d.h
    pop_manager.cxx                 pop_manager.h
    pop_object.cxx                  pop_object.h
    pop_parameter.cxx               pop_parameter.h
    pop_point_2d.cxx                pop_point_2d.h
    pop_point_3d.cxx                pop_point_3d.h
    pop_projective.cxx              pop_projective.h
    pop_rigid_3d.cxx                pop_rigid_3d.h
    pop_transform.cxx               pop_transform.h
    pop_vertex.cxx                  pop_vertex.h
)

add_library(pop ${pop_sources})
install_targets(/lib pop)
INSTALL_NOBASE_HEADER_FILES(/include/vxl/contrib/gel/pop ${pop_sources})
target_link_libraries( pop vcl vnl vgl vnl_algo vgl_algo)

if( BUILD_TESTING )
  add_subdirectory(tests)
endif()

if( BUILD_EXAMPLES )
  add_subdirectory(examples)
endif()
