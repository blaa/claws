/*
 * Sylpheed -- a GTK+ based, lightweight, and fast e-mail client
 * Copyright (C) 2005-2007 Colin Leroy <colin@colino.net> & the Claws Mail team
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

/*
 * This is a (quite naive) timer, to help determine the speed of various
 * functions of Claws. By default START_TIMING() and END_TIMING() are NOPS,
 * so that nothing gets printed out. If you change the #if, however, you'll
 * be able to get functions timing information. As the implementation is
 * naive, START_TIMING("message"); must be present just at the end of a
 * declaration block (or compilation would fail with gcc 2.x), and the
 * END_TIMING() call must be in the same scope.
 */
#ifndef __TIMING_H__
#define __TIMING_H__

#include <sys/time.h>
#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include "utils.h"
# define mytimersub(a, b, result)                                             \
  do {                                                                        \
    (result)->tv_sec = (a)->tv_sec - (b)->tv_sec;                             \
    (result)->tv_usec = (a)->tv_usec - (b)->tv_usec;                          \
    if ((result)->tv_usec < 0) {                                              \
      --(result)->tv_sec;                                                     \
      (result)->tv_usec += 1000000;                                           \
    }                                                                         \
  } while (0)

#if 0 /* set to 0 to measure times at various places */
#define START_TIMING(str) do {} while(0);
#define END_TIMING() do {} while(0);
#else
/* no {} by purpose */
#define START_TIMING(str) 						\
	struct timeval start;						\
	struct timeval end;						\
	struct timeval diff;						\
	const char *timing_name=str;					\
	gettimeofday(&start, NULL);					\

#ifdef __GLIBC__
#define END_TIMING()							\
	gettimeofday(&end, NULL);					\
	mytimersub(&end, &start, &diff);				\
	debug_print("TIMING %s %s: %ds%03dms\n", 			\
		__FUNCTION__,						\
		timing_name, (unsigned int)diff.tv_sec, 		\
		(unsigned int)diff.tv_usec/1000);			
#else
#define END_TIMING()							\
	gettimeofday(&end, NULL);					\
	mytimersub(&end, &start, &diff);				\
	debug_print("TIMING %s: %ds%03dms\n", 				\
		timing_name, (unsigned int)diff.tv_sec, 		\
		(unsigned int)diff.tv_usec/1000);			
#endif

#endif 
#endif 
