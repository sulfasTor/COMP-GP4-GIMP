/* LIBGIMP - The GIMP Library
 * Copyright (C) 1995-2003 Peter Mattis and Spencer Kimball
 *
 * gimppaths_pdb.c
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

#include "config.h"

#include <string.h>

#include "gimp.h"
#undef GIMP_DISABLE_DEPRECATED
#undef __GIMP_PATHS_PDB_H__
#include "gimppaths_pdb.h"


/**
 * SECTION: gimppaths
 * @title: gimppaths
 * @short_description: Deprecated operations related to paths.
 *
 * Deprecated operations related to paths.
 **/


/**
 * gimp_path_list:
 * @image_ID: The image to list the paths from.
 * @num_paths: The number of paths returned.
 *
 * Deprecated: Use gimp_image_get_vectors() instead.
 *
 * Returns: List of the paths belonging to this image.
 **/
gchar **
gimp_path_list (gint32  image_ID,
                gint   *num_paths)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gchar **path_list = NULL;
  gint i;

  return_vals = gimp_run_procedure ("gimp-path-list",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_END);

  *num_paths = 0;

  if (return_vals[0].data.d_status == GIMP_PDB_SUCCESS)
    {
      *num_paths = return_vals[1].data.d_int32;
      path_list = g_new (gchar *, *num_paths);
      for (i = 0; i < *num_paths; i++)
        path_list[i] = g_strdup (return_vals[2].data.d_stringarray[i]);
    }

  gimp_destroy_params (return_vals, nreturn_vals);

  return path_list;
}

/**
 * gimp_path_get_current:
 * @image_ID: The image to get the current path from.
 *
 * Deprecated: Use gimp_image_get_active_vectors() instead.
 *
 * Returns: The name of the current path.
 **/
gchar *
gimp_path_get_current (gint32 image_ID)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gchar *name = NULL;

  return_vals = gimp_run_procedure ("gimp-path-get-current",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_END);

  if (return_vals[0].data.d_status == GIMP_PDB_SUCCESS)
    name = g_strdup (return_vals[1].data.d_string);

  gimp_destroy_params (return_vals, nreturn_vals);

  return name;
}

/**
 * gimp_path_set_current:
 * @image_ID: The image in which a path will become current.
 * @name: The name of the path to make current.
 *
 * Deprecated: Use gimp_image_set_active_vectors() instead.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_path_set_current (gint32       image_ID,
                       const gchar *name)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-path-set-current",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_STRING, name,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}

/**
 * gimp_path_delete:
 * @image_ID: The image to delete the path from.
 * @name: The name of the path to delete.
 *
 * Deprecated: Use gimp_image_remove_vectors() instead.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_path_delete (gint32       image_ID,
                  const gchar *name)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-path-delete",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_STRING, name,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}

/**
 * gimp_path_get_points:
 * @image_ID: The image to list the paths from.
 * @name: The name of the path whose points should be listed.
 * @path_closed: Return if the path is closed. (0 = path open, 1 = path closed).
 * @num_path_point_details: The number of points returned. Each point is made up of (x, y, pnt_type) of floats.
 * @points_pairs: The points in the path represented as 3 floats. The first is the x pos, next is the y pos, last is the type of the pnt. The type field is dependant on the path type. For beziers (type 1 paths) the type can either be (1.0 = BEZIER_ANCHOR, 2.0 = BEZIER_CONTROL, 3.0 = BEZIER_MOVE). Note all points are returned in pixel resolution.
 *
 * Deprecated: Use gimp_vectors_stroke_get_points() instead.
 *
 * Returns: The type of the path. Currently only one type (1 = Bezier) is supported.
 **/
gint
gimp_path_get_points (gint32        image_ID,
                      const gchar  *name,
                      gint         *path_closed,
                      gint         *num_path_point_details,
                      gdouble     **points_pairs)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gint path_type = 0;

  return_vals = gimp_run_procedure ("gimp-path-get-points",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_STRING, name,
                                    GIMP_PDB_END);

  *num_path_point_details = 0;

  if (return_vals[0].data.d_status == GIMP_PDB_SUCCESS)
    {
      path_type = return_vals[1].data.d_int32;
      *path_closed = return_vals[2].data.d_int32;
      *num_path_point_details = return_vals[3].data.d_int32;
      *points_pairs = g_new (gdouble, *num_path_point_details);
      memcpy (*points_pairs,
              return_vals[4].data.d_floatarray,
              *num_path_point_details * sizeof (gdouble));
    }

  gimp_destroy_params (return_vals, nreturn_vals);

  return path_type;
}

/**
 * gimp_path_set_points:
 * @image_ID: The image to set the paths in.
 * @name: The name of the path to create. If it exists then a unique name will be created - query the list of paths if you want to make sure that the name of the path you create is unique. This will be set as the current path.
 * @ptype: The type of the path. Currently only one type (1 = Bezier) is supported.
 * @num_path_points: The number of elements in the array, i.e. the number of points in the path * 3. Each point is made up of (x, y, type) of floats. Currently only the creation of bezier curves is allowed. The type parameter must be set to (1) to indicate a BEZIER type curve. Note that for BEZIER curves, points must be given in the following order: ACCACCAC... If the path is not closed the last control point is missed off. Points consist of three control points (control/anchor/control) so for a curve that is not closed there must be at least two points passed (2 x,y pairs). If (num_path_points/3) % 3 = 0 then the path is assumed to be closed and the points are ACCACCACCACC.
 * @points_pairs: The points in the path represented as 3 floats. The first is the x pos, next is the y pos, last is the type of the pnt. The type field is dependant on the path type. For beziers (type 1 paths) the type can either be (1.0 = BEZIER_ANCHOR, 2.0 = BEZIER_CONTROL, 3.0= BEZIER_MOVE). Note all points are returned in pixel resolution.
 *
 * Deprecated: Use gimp_vectors_stroke_new_from_points() instead.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_path_set_points (gint32         image_ID,
                      const gchar   *name,
                      gint           ptype,
                      gint           num_path_points,
                      const gdouble *points_pairs)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-path-set-points",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_STRING, name,
                                    GIMP_PDB_INT32, ptype,
                                    GIMP_PDB_INT32, num_path_points,
                                    GIMP_PDB_FLOATARRAY, points_pairs,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}

/**
 * gimp_path_stroke_current:
 * @image_ID: The image which contains the path to stroke.
 *
 * Deprecated: Use gimp_edit_stroke_vectors() instead.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_path_stroke_current (gint32 image_ID)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-path-stroke-current",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}

/**
 * gimp_path_get_point_at_dist:
 * @image_ID: The image the paths belongs to.
 * @distance: The distance along the path.
 * @y_point: The y position of the point.
 * @slope: The slope (dy / dx) at the specified point.
 *
 * Deprecated: Use gimp_vectors_stroke_get_point_at_dist() instead.
 *
 * Returns: The x position of the point.
 **/
gint
gimp_path_get_point_at_dist (gint32   image_ID,
                             gdouble  distance,
                             gint    *y_point,
                             gdouble *slope)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gint x_point = 0;

  return_vals = gimp_run_procedure ("gimp-path-get-point-at-dist",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_FLOAT, distance,
                                    GIMP_PDB_END);

  if (return_vals[0].data.d_status == GIMP_PDB_SUCCESS)
    {
      x_point = return_vals[1].data.d_int32;
      *y_point = return_vals[2].data.d_int32;
      *slope = return_vals[3].data.d_float;
    }

  gimp_destroy_params (return_vals, nreturn_vals);

  return x_point;
}

/**
 * gimp_path_get_tattoo:
 * @image_ID: The image.
 * @name: The name of the path whose tattoo should be obtained.
 *
 * Deprecated: Use gimp_vectors_get_tattoo() instead.
 *
 * Returns: The tattoo associated with the named path.
 **/
gint
gimp_path_get_tattoo (gint32       image_ID,
                      const gchar *name)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gint tattoo = 0;

  return_vals = gimp_run_procedure ("gimp-path-get-tattoo",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_STRING, name,
                                    GIMP_PDB_END);

  if (return_vals[0].data.d_status == GIMP_PDB_SUCCESS)
    tattoo = return_vals[1].data.d_int32;

  gimp_destroy_params (return_vals, nreturn_vals);

  return tattoo;
}

/**
 * gimp_path_set_tattoo:
 * @image_ID: The image.
 * @name: the name of the path whose tattoo should be set.
 * @tattovalue: The tattoo associated with the name path. Only values returned from 'path_get_tattoo' should be used here.
 *
 * Deprecated: Use gimp_vectors_set_tattoo() instead.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_path_set_tattoo (gint32       image_ID,
                      const gchar *name,
                      gint         tattovalue)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-path-set-tattoo",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_STRING, name,
                                    GIMP_PDB_INT32, tattovalue,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}

/**
 * gimp_get_path_by_tattoo:
 * @image_ID: The image.
 * @tattoo: The tattoo of the required path.
 *
 * Deprecated: Use gimp_image_get_vectors_by_tattoo() instead.
 *
 * Returns: The name of the path with the specified tattoo.
 **/
gchar *
gimp_get_path_by_tattoo (gint32 image_ID,
                         gint   tattoo)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gchar *name = NULL;

  return_vals = gimp_run_procedure ("gimp-get-path-by-tattoo",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_INT32, tattoo,
                                    GIMP_PDB_END);

  if (return_vals[0].data.d_status == GIMP_PDB_SUCCESS)
    name = g_strdup (return_vals[1].data.d_string);

  gimp_destroy_params (return_vals, nreturn_vals);

  return name;
}

/**
 * gimp_path_get_locked:
 * @image_ID: The image.
 * @name: The name of the path whose locked status should be obtained.
 *
 * Deprecated: Use gimp_vectors_get_linked() instead.
 *
 * Returns: TRUE if the path is locked, FALSE otherwise.
 **/
gboolean
gimp_path_get_locked (gint32       image_ID,
                      const gchar *name)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean locked = FALSE;

  return_vals = gimp_run_procedure ("gimp-path-get-locked",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_STRING, name,
                                    GIMP_PDB_END);

  if (return_vals[0].data.d_status == GIMP_PDB_SUCCESS)
    locked = return_vals[1].data.d_int32;

  gimp_destroy_params (return_vals, nreturn_vals);

  return locked;
}

/**
 * gimp_path_set_locked:
 * @image_ID: The image.
 * @name: the name of the path whose locked status should be set.
 * @locked: Whether the path is locked.
 *
 * Deprecated: Use gimp_vectors_set_linked() instead.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_path_set_locked (gint32       image_ID,
                      const gchar *name,
                      gboolean     locked)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-path-set-locked",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_STRING, name,
                                    GIMP_PDB_INT32, locked,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}

/**
 * gimp_path_to_selection:
 * @image_ID: The image.
 * @name: The name of the path which should be made into selection.
 * @op: The desired operation with current selection.
 * @antialias: Antialias selection.
 * @feather: Feather selection.
 * @feather_radius_x: Feather radius x.
 * @feather_radius_y: Feather radius y.
 *
 * Deprecated: Use gimp_vectors_to_selection() instead.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_path_to_selection (gint32          image_ID,
                        const gchar    *name,
                        GimpChannelOps  op,
                        gboolean        antialias,
                        gboolean        feather,
                        gdouble         feather_radius_x,
                        gdouble         feather_radius_y)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-path-to-selection",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_STRING, name,
                                    GIMP_PDB_INT32, op,
                                    GIMP_PDB_INT32, antialias,
                                    GIMP_PDB_INT32, feather,
                                    GIMP_PDB_FLOAT, feather_radius_x,
                                    GIMP_PDB_FLOAT, feather_radius_y,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}

/**
 * gimp_path_import:
 * @image_ID: The image.
 * @filename: The name of the SVG file to import.
 * @merge: Merge paths into a single vectors object.
 * @scale: Scale the SVG to image dimensions.
 *
 * Deprecated: Use gimp_vectors_import_from_file() instead.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_path_import (gint32       image_ID,
                  const gchar *filename,
                  gboolean     merge,
                  gboolean     scale)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-path-import",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_STRING, filename,
                                    GIMP_PDB_INT32, merge,
                                    GIMP_PDB_INT32, scale,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}
