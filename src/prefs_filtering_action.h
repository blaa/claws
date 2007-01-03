/*
 * Sylpheed -- a GTK+ based, lightweight, and fast e-mail client
 * Copyright (C) 1999-2007 Hiroyuki Yamamoto
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

#ifndef __PREFS_FILTERING_ACTION_H__
#define __PREFS_FILTERING_ACTION_H__

#include "matcher.h"

typedef void PrefsFilteringActionSignal	(GSList *action_list);

void prefs_filtering_action_open		(GSList *action_list,
				 PrefsFilteringActionSignal *cb);
void prefs_filtering_action_exec_info	(void);

#endif /* __PREFS_FILTER_H__ */
