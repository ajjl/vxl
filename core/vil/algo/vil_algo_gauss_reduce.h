// This is mul/vil2/algo/vil2_algo_gauss_reduce.h
#ifndef vil2_algo_gauss_reduce_h_
#define vil2_algo_gauss_reduce_h_
//: \file
//  \brief Functions to smooth and sub-sample image in one direction
//  \author Tim Cootes
//  These are not templated because
//  - Each type tends to need a slightly different implementation
//  - Let's not have too many templates.

#include <vil/vil_byte.h>
#include <vil2/vil2_image_view.h>

//: Smooth and subsample src_im to produce dest_im
//  Applies 1-5-8-5-1 smoothing filter in x and y, then samples every other pixel.
//  work_im provides workspace
// \relates vil2_image_view
template<class T>
void vil2_algo_gauss_reduce(vil2_image_view<T>& dest,
                            const vil2_image_view<T>& src,
                            vil2_image_view<T>& work_im);

//: Smooth and subsample src_im to produce dest_im
//  Applies 1-2-1 smoothing filter in x and y, then samples every other pixel.
//  work_im provides workspace
// \relates vil2_image_view
template<class T>
void vil2_algo_gauss_reduce_121(vil2_image_view<T>& dest,
                                const vil2_image_view<T>& src,
                                vil2_image_view<T>& work_im);

//: Smooth and subsample single plane src_im in x to produce dest_im
//  Applies 1-5-8-5-1 filter in x, then samples
//  every other pixel.  Fills [0,(nx+1)/2-1][0,ny-1] elements of dest
//  Assumes dest_im has suffient data allocated.
//
//  This is essentially a utility function, used by mil_gauss_pyramid_builder
//
//  By applying twice we can obtain a full gaussian smoothed and
//  sub-sampled 2D image
void vil2_algo_gauss_reduce(vil_byte* dest_im,
                            int d_x_step, int d_y_step,
                            const vil_byte* src_im,
                            int src_nx, int src_ny,
                            int s_x_step, int s_y_step);

//: Smooth and subsample single plane src_im in x to produce dest_im
//  Applies 1-5-8-5-1 filter in x, then samples
//  every other pixel.  Fills [0,(nx+1)/2-1][0,ny-1] elements of dest
//  Assumes dest_im has suffient data allocated.
//
//  This is essentially a utility function, used by mil_gauss_pyramid_builder
//
//  By applying twice we can obtain a full gaussian smoothed and
//  sub-sampled 2D image.
void vil2_algo_gauss_reduce(float* dest_im,
                            int d_x_step, int d_y_step,
                            const float* src_im,
                            int src_nx, int src_ny,
                            int s_x_step, int s_y_step);


//: Smooth and subsample single plane src_im in x to produce dest_im
//  Applies 1-5-8-5-1 filter in x, then samples
//  every other pixel.  Fills [0,(nx+1)/2-1][0,ny-1] elements of dest
//  Assumes dest_im has suffient data allocated.
//
//  This is essentially a utility function, used by mil_gauss_pyramid_builder
//
//  By applying twice we can obtain a full gaussian smoothed and
//  sub-sampled 2D image.
void vil2_algo_gauss_reduce(int* dest_im,
                            int d_x_step, int d_y_step,
                            const int* src_im,
                            int src_nx, int src_ny,
                            int s_x_step, int s_y_step);

//: Smooth and subsample single plane src_im in x to produce dest_im using 121 filter in x and y
//  Smooths with a 3x3 filter and subsamples
void vil2_algo_gauss_reduce_121(vil_byte* dest_im,
                               int d_x_step, int d_y_step,
                               const vil_byte* src_im,
                               int src_nx, int src_ny,
                               int s_x_step, int s_y_step);

//: Smooth and subsample single plane src_im in x to produce dest_im using 121 filter in x and y
//  Smooths with a 3x3 filter and subsamples
void vil2_algo_gauss_reduce_121(float* dest_im,
                                int d_x_step, int d_y_step,
                                const float* src_im,
                                int src_nx, int src_ny,
                                int s_x_step, int s_y_step);

//: Smooth and subsample single plane src_im in x to produce dest_im using 121 filter in x and y
//  Smooths with a 3x3 filter and subsamples
void vil2_algo_gauss_reduce_121(int* dest_im,
                                int d_x_step, int d_y_step,
                                const int* src_im,
                                int src_nx, int src_ny,
                                int s_x_step, int s_y_step);

#endif // vil2_algo_gauss_reduce_h_
