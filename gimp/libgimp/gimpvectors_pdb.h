/* LIBGIMP - The GIMP Library
 * Copyright (C) 1995-2003 Peter Mattis and Spencer Kimball
 *
 * gimpvectors_pdb.h
 *
 * This library is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

/* NOTE: This file is auto-generated by pdbgen.pl */

#if !defined (__GIMP_H_INSIDE__) && !defined (GIMP_COMPILATION)
#error "Only <libgimp/gimp.h> can be included directly."
#endif

#ifndef __GIMP_VECTORS_PDB_H__
#define __GIMP_VECTORS_PDB_H__

G_BEGIN_DECLS

/* For information look into the C source or the html documentation */


gint32                gimp_vectors_new                       (gint32                  image_ID,
                                                              const gchar            *name);
gint32                gimp_vectors_new_from_text_layer       (gint32                  image_ID,
                                                              gint32                  layer_ID);
gint32                gimp_vectors_copy                      (gint32                  vectors_ID);
gint*                 gimp_vectors_get_strokes               (gint32                  vectors_ID,
                                                              gint                   *num_strokes);
gdouble               gimp_vectors_stroke_get_length         (gint32                  vectors_ID,
                                                              gint                    stroke_id,
                                                              gdouble                 precision);
gboolean              gimp_vectors_stroke_get_point_at_dist  (gint32                  vectors_ID,
                                                              gint                    stroke_id,
                                                              gdouble                 dist,
                                                              gdouble                 precision,
                                                              gdouble                *x_point,
                                                              gdouble                *y_point,
                                                              gdouble                *slope,
                                                              gboolean               *valid);
gboolean              gimp_vectors_remove_stroke             (gint32                  vectors_ID,
                                                              gint                    stroke_id);
gboolean              gimp_vectors_stroke_close              (gint32                  vectors_ID,
                                                              gint                    stroke_id);
gboolean              gimp_vectors_stroke_translate          (gint32                  vectors_ID,
                                                              gint                    stroke_id,
                                                              gint                    off_x,
                                                              gint                    off_y);
gboolean              gimp_vectors_stroke_scale              (gint32                  vectors_ID,
                                                              gint                    stroke_id,
                                                              gdouble                 scale_x,
                                                              gdouble                 scale_y);
gboolean              gimp_vectors_stroke_rotate             (gint32                  vectors_ID,
                                                              gint                    stroke_id,
                                                              gdouble                 center_x,
                                                              gdouble                 center_y,
                                                              gdouble                 angle);
gboolean              gimp_vectors_stroke_flip               (gint32                  vectors_ID,
                                                              gint                    stroke_id,
                                                              GimpOrientationType     flip_type,
                                                              gdouble                 axis);
gboolean              gimp_vectors_stroke_flip_free          (gint32                  vectors_ID,
                                                              gint                    stroke_id,
                                                              gdouble                 x1,
                                                              gdouble                 y1,
                                                              gdouble                 x2,
                                                              gdouble                 y2);
GimpVectorsStrokeType gimp_vectors_stroke_get_points         (gint32                  vectors_ID,
                                                              gint                    stroke_id,
                                                              gint                   *num_points,
                                                              gdouble               **controlpoints,
                                                              gboolean               *closed);
gint                  gimp_vectors_stroke_new_from_points    (gint32                  vectors_ID,
                                                              GimpVectorsStrokeType   type,
                                                              gint                    num_points,
                                                              const gdouble          *controlpoints,
                                                              gboolean                closed);
gdouble*              gimp_vectors_stroke_interpolate        (gint32                  vectors_ID,
                                                              gint                    stroke_id,
                                                              gdouble                 precision,
                                                              gint                   *num_coords,
                                                              gboolean               *closed);
gint                  gimp_vectors_bezier_stroke_new_moveto  (gint32                  vectors_ID,
                                                              gdouble                 x0,
                                                              gdouble                 y0);
gboolean              gimp_vectors_bezier_stroke_lineto      (gint32                  vectors_ID,
                                                              gint                    stroke_id,
                                                              gdouble                 x0,
                                                              gdouble                 y0);
gboolean              gimp_vectors_bezier_stroke_conicto     (gint32                  vectors_ID,
                                                              gint                    stroke_id,
                                                              gdouble                 x0,
                                                              gdouble                 y0,
                                                              gdouble                 x1,
                                                              gdouble                 y1);
gboolean              gimp_vectors_bezier_stroke_cubicto     (gint32                  vectors_ID,
                                                              gint                    stroke_id,
                                                              gdouble                 x0,
                                                              gdouble                 y0,
                                                              gdouble                 x1,
                                                              gdouble                 y1,
                                                              gdouble                 x2,
                                                              gdouble                 y2);
gint                  gimp_vectors_bezier_stroke_new_ellipse (gint32                  vectors_ID,
                                                              gdouble                 x0,
                                                              gdouble                 y0,
                                                              gdouble                 radius_x,
                                                              gdouble                 radius_y,
                                                              gdouble                 angle);
#ifndef GIMP_DISABLE_DEPRECATED
gboolean              gimp_vectors_to_selection              (gint32                  vectors_ID,
                                                              GimpChannelOps          operation,
                                                              gboolean                antialias,
                                                              gboolean                feather,
                                                              gdouble                 feather_radius_x,
                                                              gdouble                 feather_radius_y);
#endif /* GIMP_DISABLE_DEPRECATED */
gboolean              gimp_vectors_import_from_file          (gint32                  image_ID,
                                                              const gchar            *filename,
                                                              gboolean                merge,
                                                              gboolean                scale,
                                                              gint                   *num_vectors,
                                                              gint32                **vectors_ids);
gboolean              gimp_vectors_import_from_string        (gint32                  image_ID,
                                                              const gchar            *string,
                                                              gint                    length,
                                                              gboolean                merge,
                                                              gboolean                scale,
                                                              gint                   *num_vectors,
                                                              gint32                **vectors_ids);
gboolean              gimp_vectors_export_to_file            (gint32                  image_ID,
                                                              const gchar            *filename,
                                                              gint32                  vectors_ID);
gchar*                gimp_vectors_export_to_string          (gint32                  image_ID,
                                                              gint32                  vectors_ID);


G_END_DECLS

#endif /* __GIMP_VECTORS_PDB_H__ */