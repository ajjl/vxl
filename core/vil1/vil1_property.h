#ifndef vil_property_h_
#define vil_property_h_
#ifdef __GNUC__
#pragma interface
#endif
// This is vxl/vil/vil_property.h

//:
// \file
//
// There is no class called vil_property.
//
// The image class vil_image has the methods :
// \verbatim
//   bool get_property(char const *tag, void *property_value = 0) const;
//   bool set_property(char const *tag, void const *property_value = 0)
// \endverbatim
// which allow format extensions to be added without cluttering the
// interface to vil_image. The idea is that properties can be
// identified by a "tag" (some name or other textual description)
// through which clients can obtain or manipulate extra properties.
//
// A false return value means that the underlying image does not
// understand the given property or that the given data was invalid.
// A true return value means it does understand the property and has
// used the supplied data according to the relevant protocol.
// Passing a null pointer as the second argument can be useful for
// protocols for manipulating boolean properties (i.e when there is
// no data to be passed).
//
// To make this work in practice, it is necessary to avoid name clashes
// and to make sure everyone agrees on the meaning of the property data.
// That is the purpose of this file. The set of tags is a namespace in
// the general sense of the word. We only have one namespace, so try
// not to clutter it. All property tags described in this file should
// begin with "vil_property_" and that chunk of the namespace is reserved.
//
// packing of rgb(a) colours in the data produced by get_section().
// tags:
// - "vil_property_r_packing"
// - "vil_property_g_packing"
// - "vil_property_b_packing"
// - "vil_property_a_packing"
// type: three ints
//
// If supported, the returned values describe the index of the
// red/green/blue/alpha part of the pixel in plane p, row i, column j
// of the whole image. E.g. to fill a 256x256 3-plane memory image from
// a 256x256 disk image which supports r,g,b packing:
// \verbatim
//   char buf[3][256][256]
//   char bif[3*256*256];
//   image.get_section(bif, 0, 0, 256, 256);
//   int a[3];
//   char const *tag[] = {
//     "vil_propery_r_packing",
//     "vil_propery_g_packing",
//     "vil_propery_b_packing"
//   };
//   for (int p=0; p<3; ++p) {
//     image.get_property(, a);
//     for (int i=0; i<256; ++i)
//       for (int j=0; j<256; ++j)
//         buf[p][i][j] = bif[ a[0]*p + a[1]*i + a[2]*j ];
//   }
// \endverbatim
// preferred direction for access.
// tags:
// - "vil_property_preferred_x_direction"
// - "vil_property_preferred_y_direction"
// type: int
// If supported, the returned property value is
// - "-1" if the preferred direction is decreasing.
// - " 0" if there is no preferred direction.
// - "+1" if the preferred direction is increasing.
//
// \author  fsm@robots.ox.ac.uk

#endif // vil_property_h_
