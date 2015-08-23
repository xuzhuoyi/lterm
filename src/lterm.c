/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * lterm.c
 * Copyright (C) 2015 LDE Team <xzy476386434@vip.qq.com>
 * 
 * lterm is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * lterm is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "lterm.h"

#include <glib/gi18n.h>
#include <vte/vte.h>
#include <glib.h>




G_DEFINE_TYPE (Lterm, lterm, GTK_TYPE_APPLICATION);

/* ANJUTA: Macro LTERM_APPLICATION gets Lterm - DO NOT REMOVE */

/* Create a new window loading a file */
static void
lterm_new_window (GApplication *app,
                           GFile        *file)
{
	GtkWidget *window;
	GtkWidget *vte;
	char *argv[3];
	gboolean option_login = FALSE;

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), "lterm");

	argv[0]=g_strdup(g_getenv("SHELL"));
	if (option_login) {
		argv[1]=g_strdup_printf("-%s", g_getenv("SHELL"));
	} else {
		argv[1]=g_strdup(g_getenv("SHELL"));
	}
	argv[2]=NULL;
	
	
	gtk_window_set_application (GTK_WINDOW (window), GTK_APPLICATION (app));
	vte = vte_terminal_new ();
	vte_terminal_spawn_sync (VTE_TERMINAL(vte), VTE_PTY_DEFAULT, NULL,
	                         argv, NULL,
	                         G_SPAWN_SEARCH_PATH|G_SPAWN_FILE_AND_ARGV_ZERO,
	                         NULL, NULL, NULL, NULL, NULL);
	gtk_container_add (GTK_CONTAINER(window), vte);
	if (file != NULL)
	{
		/* TODO: Add code here to open the file in the new window */
	}

	gtk_widget_show_all (GTK_WIDGET (window));
}


/* GApplication implementation */
static void
lterm_activate (GApplication *application)
{
	lterm_new_window (application, NULL);
}

static void
lterm_open (GApplication  *application,
                     GFile        **files,
                     gint           n_files,
                     const gchar   *hint)
{
	gint i;

	for (i = 0; i < n_files; i++)
		lterm_new_window (application, files[i]);
}

static void
lterm_init (Lterm *object)
{
}

static void
lterm_finalize (GObject *object)
{
	G_OBJECT_CLASS (lterm_parent_class)->finalize (object);
}

static void
lterm_class_init (LtermClass *klass)
{
	G_APPLICATION_CLASS (klass)->activate = lterm_activate;
	G_APPLICATION_CLASS (klass)->open = lterm_open;

	G_OBJECT_CLASS (klass)->finalize = lterm_finalize;
}

Lterm *
lterm_new (void)
{
	return g_object_new (lterm_get_type (),
	                     "application-id", "org.gnome.lterm",
	                     "flags", G_APPLICATION_HANDLES_OPEN,
	                     NULL);
}

