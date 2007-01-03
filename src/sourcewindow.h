/*
 * Sylpheed -- a GTK+ based, lightweight, and fast e-mail client
 * Copyright (C) 1999-2007 Hiroyuki Yamamoto and the Claws Mail team
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef __SOURCEWINDOW_H__
#define __SOURCEWINDOW_H__

#include <glib.h>
#include <gtk/gtkwidget.h>

#include "procmsg.h"

typedef struct _SourceWindow	SourceWindow;

struct _SourceWindow
{
	GtkWidget *window;
	GtkWidget *scrolledwin;
	GtkWidget *text;
	
	gboolean updating;
	gboolean deferred_destroy;
};

SourceWindow *source_window_create	(void);
void source_window_show			(SourceWindow	*sourcewin);
void source_window_destroy		(SourceWindow	*sourcewin);
void source_window_show_msg		(SourceWindow	*sourcewin,
					 MsgInfo	*msginfo);
void source_window_append		(SourceWindow	*sourcewin,
					 const gchar	*str);

#endif /* __SOURCEWINDOW_H__ */
