#ifndef boxm_plane_ransac_h_
#define boxm_plane_ransac_h_

#include <vgl/vgl_infinite_line_3d.h>
#include <vgl/vgl_intersection.h>
#include <vgl/algo/vgl_intersection.h>
#include <vgl/vgl_plane_3d.h>
#include <vgl/vgl_distance.h>
#include <vgl/vgl_vector_3d.h>
#include <vgl/vgl_closest_point.h>
#include <boxm/boxm_apm_traits.h>
#include <boxm/boxm_edge_tangent_sample.h>
#include <vcl_cstdlib.h> // for rand()
#include <vcl_iostream.h>
#include <vcl_list.h>
#define ITER_MAX 100

template <class T>
bool boxm_plane_ransac(vcl_vector<boxm_edge_tangent_sample<T> > aux_samples,
                       vcl_vector<T> weights,
                       vgl_infinite_line_3d<T>& line,
                       T &min_res, vgl_box_3d<double> cell_global_box,
                       unsigned int threshold)
{
    unsigned int num_imgs = aux_samples.size();
    vgl_point_3d<T> local_origin((T)cell_global_box.centroid_x(),(T)cell_global_box.centroid_y(),(T)cell_global_box.centroid_z());
    vcl_list<vgl_plane_3d<T> > fit_planes;
    min_res=T(1e10);
    line=vgl_infinite_line_3d<T>(vgl_vector_2d<T>(-10000,-10000),vgl_vector_3d<T>(0,0,1));
    vcl_vector<T> ws;
    bool set=false;
    // this threhsold is to check participation from number of images
    if (num_imgs<=threshold)
        return set;

    for (unsigned iter=0; iter<ITER_MAX; iter++) {
        fit_planes.clear();
        ws.clear();
        // select two imgs randomly
        int index1 = vcl_rand() % num_imgs;
        int index2 = index1;
        while (index2==index1)
            index2=vcl_rand() % num_imgs;

        int index1_1 =vcl_rand() % aux_samples[index1].num_obs();
        int index2_1 =vcl_rand() % aux_samples[index2].num_obs();

        vgl_plane_3d<T> plane1 = aux_samples[index1].obs(index1_1).plane_;
        vgl_plane_3d<T> plane2 = aux_samples[index2].obs(index2_1).plane_;

        vgl_infinite_line_3d<T> inters_line;
        // form a hypothesis
        if (vgl_intersection(plane1, plane2, inters_line))
        {
            vgl_vector_3d<T> line_dir = inters_line.direction();
            vgl_point_3d<T> p=vgl_closest_point<T>(inters_line,local_origin);
            int cnt_imgs=0;
            // only if the hypothesis is close to the cell in consideration
            // can be made more tighter.
            if (vgl_distance<T>(p,local_origin)<0.67*cell_global_box.width())
            {
                for (unsigned i=0; i<aux_samples.size(); ++i) {
                    bool flag=false;
                    for (unsigned j=0;j<aux_samples[i].num_obs();j++)
                    {
                        vgl_plane_3d<T> plane = aux_samples[i].obs(j).plane_;
                        vgl_vector_3d<T> normal = plane.normal();
                        // see if the line direction and plane normal is perpendicular
                        T res = dot_product(normal,line_dir);
                        if (vcl_fabs(res) < 0.05)  {
                            // check to see if the line is close to the plane
                            if (plane.contains(p,cell_global_box.width()/8))
                            {
                                fit_planes.push_back(plane);
                                ws.push_back(weights[i]);
                                flag=true;
                            }
                        }
                    }
                    if (flag)
                        cnt_imgs++;
                }
            }

            // intersect the selected planes
            if (cnt_imgs > (int)threshold ) {
                T res=0;
                vgl_infinite_line_3d<T> l;
                bool good = vgl_intersection(fit_planes, ws, l, res);
                vgl_point_3d<double> p0,p1;
                vgl_vector_2d<double> x0(l.x0().x(), l.x0().y());
                vgl_vector_3d<double> dir(l.direction().x(), l.direction().y(), l.direction().z());

                if (good&&vgl_intersection<double>(cell_global_box, vgl_infinite_line_3d<double>(x0,dir), p0, p1)) {
                    if (res<min_res) {
                        min_res=res;
                        line=l;
                        set=true;
                    }
                }
            }
        }
    }

    return set;
}


#endif
