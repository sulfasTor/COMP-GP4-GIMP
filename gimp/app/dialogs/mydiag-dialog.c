/* GIMP - The GNU Image Manipulation Program
 * Copyright (C) 1995 Spencer Kimball and Peter Mattis
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

#include "config.h"

#include <gtk/gtk.h>

#include "libgimpbase/gimpbase.h"
#include "libgimpwidgets/gimpwidgets.h"

#include "dialogs-types.h"

#include "config/gimpguiconfig.h"

#include "core/gimp.h"

#include "mydiag-dialog.h"

#include "gimp-intl.h"

enum
  {
   RESPONSE_PREVIOUS = 1,
   RESPONSE_NEXT     = 2
  };

static void  mydiag_dialog_response (GtkWidget     *dialog,
				   gint           response);
static void  mydiag_dialog_destroy  (GtkWidget     *widget,
				   GimpGuiConfig *config);
static void  more_button_clicked  (GtkWidget     *button,
				   Gimp          *gimp);


static GtkWidget *tips_dialog = NULL;
static GtkWidget *tip_label   = NULL;
static GtkWidget *more_button = NULL;

GtkWidget *
mydiag_dialog_create (Gimp *gimp)
{
  GimpGuiConfig *config;
  GtkWidget     *vbox;
  GtkWidget     *hbox;
  GtkWidget     *button;
  GtkWidget     *image;

  g_return_val_if_fail (GIMP_IS_GIMP (gimp), NULL);


  tips_dialog = gimp_dialog_new (_("GIMP Generic Dialog"),
				 "gimp-tip-of-the-day",
				 NULL, 0, NULL, NULL,
				 NULL);

  button = gtk_dialog_add_button (GTK_DIALOG (tips_dialog),
                                  _("_Previous Tip"), RESPONSE_PREVIOUS);
  gtk_button_set_image (GTK_BUTTON (button),
                        gtk_image_new_from_stock (GTK_STOCK_GO_BACK,
                                                  GTK_ICON_SIZE_BUTTON));

  button = gtk_dialog_add_button (GTK_DIALOG (tips_dialog),
                                  _("_Next Tip"), RESPONSE_NEXT);
  gtk_button_set_image (GTK_BUTTON (button),
                        gtk_image_new_from_stock (GTK_STOCK_GO_FORWARD,
                                                  GTK_ICON_SIZE_BUTTON));

  gtk_dialog_set_response_sensitive (GTK_DIALOG (tips_dialog),
                                     RESPONSE_NEXT, 1);
  gtk_dialog_set_response_sensitive (GTK_DIALOG (tips_dialog),
                                     RESPONSE_PREVIOUS, 0);

  g_signal_connect (tips_dialog, "response",
                    G_CALLBACK (mydiag_dialog_response),
                    NULL);
  g_signal_connect (tips_dialog, "destroy",
                    G_CALLBACK (mydiag_dialog_destroy),
                    config);

  vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 12);
  gtk_container_set_border_width (GTK_CONTAINER (vbox), 12);
  gtk_box_pack_start (GTK_BOX (gtk_dialog_get_content_area (GTK_DIALOG (tips_dialog))),
                      vbox, TRUE, TRUE, 0);
  gtk_widget_show (vbox);

  hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 6);
  gtk_container_set_border_width (GTK_CONTAINER (hbox), 6);
  gtk_box_pack_start (GTK_BOX (vbox), hbox, TRUE, TRUE, 0);
  gtk_widget_show (hbox);

  vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 6);
  gtk_box_pack_start (GTK_BOX (hbox), vbox, TRUE, TRUE, 0);
  gtk_widget_show (vbox);

  image = gtk_image_new_from_stock (GIMP_STOCK_INFO, GTK_ICON_SIZE_DIALOG);
  gtk_misc_set_alignment (GTK_MISC (image), 0.5, 0.0);
  gtk_box_pack_start (GTK_BOX (hbox), image, FALSE, FALSE, 0);
  gtk_widget_show (image);

  gtk_container_set_focus_chain (GTK_CONTAINER (hbox), NULL);

  tip_label = gtk_label_new (NULL);
  gtk_label_set_selectable (GTK_LABEL (tip_label), TRUE);
  gtk_label_set_justify (GTK_LABEL (tip_label), GTK_JUSTIFY_LEFT);
  gtk_label_set_line_wrap (GTK_LABEL (tip_label), TRUE);
  gtk_misc_set_alignment (GTK_MISC (tip_label), 0.5, 0.0);
  gtk_box_pack_start (GTK_BOX (vbox), tip_label, TRUE, TRUE, 0);
  gtk_widget_show (tip_label);

  hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);
  gtk_widget_show (hbox);

  more_button = gtk_link_button_new_with_label ("http://univ-paris8.fr/",
						/*  a link to the related section in the user manual  */
                                                _("Université Paris VIII"));
  gtk_widget_show (more_button);
  gtk_box_pack_start (GTK_BOX (hbox), more_button, FALSE, FALSE, 0);

  g_signal_connect (more_button, "clicked",
                    G_CALLBACK (more_button_clicked),
                    gimp);

  return tips_dialog;
}

static void
mydiag_dialog_destroy (GtkWidget     *widget,
                     GimpGuiConfig *config)
{
  tips_dialog = NULL;
}

static void
mydiag_dialog_response (GtkWidget *dialog,
                      gint       response)
{
  switch (response)
    {
    case RESPONSE_PREVIOUS:
      break;

    case RESPONSE_NEXT:
      break;

    default:
      break;
    }
}

static void
more_button_clicked (GtkWidget *button,
                     Gimp      *gimp)
{}
