include_directories( ${VXLCORE_INCLUDE_DIR} )
include_directories( ${MUL_INCLUDE_DIR} )

if(WIN32 AND VXL_USE_LFS)
#This is a hack since win32 doesn't have transparent Large File Support.
add_definitions( -DBVXM_USE_FSTREAM64 )
  # so we can include vil_stream_fstream64
add_definitions( -DVIL_USE_FSTREAM64 )
endif()

set(bvxm_grid_sources
    bvxm_memory_chunk.h               bvxm_memory_chunk.cxx
    bvxm_voxel_slab_base.h
    bvxm_voxel_slab.h                 bvxm_voxel_slab.txx
    bvxm_voxel_storage.h
    bvxm_voxel_storage_disk.h         bvxm_voxel_storage_disk.txx
    bvxm_voxel_storage_disk_cached.h  bvxm_voxel_storage_disk_cached.txx
    bvxm_voxel_storage_mem.h          bvxm_voxel_storage_mem.txx
    bvxm_voxel_storage_slab_mem.h     bvxm_voxel_storage_slab_mem.txx
    bvxm_voxel_slab_iterator.h        bvxm_voxel_slab_iterator.txx
    bvxm_voxel_grid_base.h            bvxm_voxel_grid_base_sptr.h
    bvxm_voxel_grid.h                 bvxm_voxel_grid.txx
    bvxm_voxel_grid_basic_ops.h       bvxm_voxel_grid_basic_ops.cxx
    bvxm_opinion.h
    bvxm_voxel_grid_opinion_basic_ops.h bvxm_voxel_grid_opinion_basic_ops.cxx
)

aux_source_directory(Templates bvxm_grid_sources)

add_library( bvxm_grid ${bvxm_grid_sources})

target_link_libraries( bvxm_grid vpgl vnl vil vil_algo vul vbl vsl vgl vgl_algo vil3d vil3d_algo vcl)

add_subdirectory(io)
add_subdirectory(pro)

if( BUILD_TESTING )
  add_subdirectory(tests)
endif()
