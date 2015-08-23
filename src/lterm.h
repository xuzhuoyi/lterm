/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * lterm.h
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

#ifndef _LTERM_
#define _LTERM_

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define LTERM_TYPE_APPLICATION             (lterm_get_type ())
#define LTERM_APPLICATION(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), LTERM_TYPE_APPLICATION, Lterm))
#define LTERM_APPLICATION_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), LTERM_TYPE_APPLICATION, LtermClass))
#define LTERM_IS_APPLICATION(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), LTERM_TYPE_APPLICATION))
#define LTERM_IS_APPLICATION_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), LTERM_TYPE_APPLICATION))
#define LTERM_APPLICATION_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), LTERM_TYPE_APPLICATION, LtermClass))

typedef struct _LtermClass LtermClass;
typedef struct _Lterm Lterm;


struct _LtermClass
{
	GtkApplicationClass parent_class;
};

struct _Lterm
{
	GtkApplication parent_instance;

};

GType lterm_get_type (void) G_GNUC_CONST;
Lterm *lterm_new (void);

/* Callbacks */

G_END_DECLS

#endif /* _APPLICATION_H_ */

