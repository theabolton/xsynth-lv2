/* Xsynth DSSI software synthesizer GUI
 *
 * Copyright (C) 2004, 2009 Sean Bolton
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the Free
 * Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "gui_images.h"

#include "bitmap_about.xpm"

#include "bitmap_logo.xpm"

#include "bitmap_waveform0.xpm"
#include "bitmap_waveform1.xpm"
#include "bitmap_waveform2.xpm"
#include "bitmap_waveform3.xpm"
#include "bitmap_waveform4.xpm"
#include "bitmap_waveform5.xpm"
#include "bitmap_waveform6.xpm"

static const char **waveform_xpms[7] = {
    (const char **)waveform0_xpm,
    (const char **)waveform1_xpm,
    (const char **)waveform2_xpm,
    (const char **)waveform3_xpm,
    (const char **)waveform4_xpm,
    (const char **)waveform5_xpm,
    (const char **)waveform6_xpm
};

static GdkPixbuf *waveform_pixbufs[7];

GtkWidget *
create_about_image(void)
{
    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_xpm_data(bitmap_about_xpm);

    return gtk_image_new_from_pixbuf(pixbuf);
}

GtkWidget *
create_logo_image(void)
{
    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_xpm_data(bitmap_logo_xpm);

    return gtk_image_new_from_pixbuf(pixbuf);
}

void
create_waveform_gdk_pixbufs(void)
{
    int i;

    for (i = 0; i <= 6; i++) {
        waveform_pixbufs[i] = gdk_pixbuf_new_from_xpm_data(waveform_xpms[i]);
        if (waveform_pixbufs[i] == NULL) {
            g_error ("Couldn't create waveform pixbuf %d", i);
        }
    }
}

void
free_waveform_gdk_pixbufs(void)
{
    int i;
    for (i = 0; i <= 6; i++) {
        if (waveform_pixbufs[i] != NULL)
            g_object_unref (waveform_pixbufs[i]);
        waveform_pixbufs[i] = NULL;
    }
}

GtkWidget *
create_waveform_gtk_image(void)
{
    return gtk_image_new_from_pixbuf(waveform_pixbufs[0]);
}

void
set_waveform_image(GtkWidget *widget, int waveform)
{
    if (waveform >=0 && waveform <= 6)
        gtk_image_set_from_pixbuf(GTK_IMAGE(widget), waveform_pixbufs[waveform]);
}
