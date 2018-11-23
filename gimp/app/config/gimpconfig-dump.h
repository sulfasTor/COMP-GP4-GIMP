/* GIMP - The GNU Image Manipulation Program
 * Copyright (C) 1995-1997 Spencer Kimball and Peter Mattis
 *
 * Copyright (C) 2003  Sven Neumann <sven@gimp.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GIMP_CONFIG_DUMP_H__
#define __GIMP_CONFIG_DUMP_H__


typedef enum
{
  GIMP_CONFIG_DUMP_NONE,
  GIMP_CONFIG_DUMP_GIMPRC,
  GIMP_CONFIG_DUMP_GIMPRC_SYSTEM,
  GIMP_CONFIG_DUMP_GIMPRC_MANPAGE
} GimpConfigDumpFormat;


gboolean  gimp_config_dump (GimpConfigDumpFormat  format);


#endif  /* __GIMP_CONFIG_DUMP_H__ */
