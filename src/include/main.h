/*
 * $Header$
 *
 */

/*
 *  main.h - General definitions
 *
 *  Basilisk II (C) 1997-2000 Christian Bauer
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef MAIN_H
#define MAIN_H

#include "sysdeps.h"

// CPU type (0 = 68000, 1 = 68010, 2 = 68020, 3 = 68030, 4 = 68040/060)
extern int CPUType;

// FPU type (0 = no FPU, 1 = 68881, 2 = 68882)
extern int FPUType;

// 68k register structure (for Execute68k())
struct M68kRegisters {
	uint32 d[8];
	memptr a[8];
	uint16 sr;
};

// General functions
extern bool InitAll(void);
extern void ExitAll(void);
extern void invoke200HzInterrupt(void);
#ifdef OS_irix
extern void setactvdebug();
#else
extern void setactvdebug(int);
#endif

// Platform-specific functions
extern void QuitEmulator(void);				// Quit emulator

#endif


/*
 * $Log$
 * Revision 1.17  2002/10/07 23:00:42  joy
 * CPU back in the main thread
 *
 * Revision 1.15  2002/06/24 17:08:48  standa
 * The pointer arithmetics fixed. The memptr usage introduced in my code.
 *
 * Revision 1.14  2002/04/22 18:30:50  milan
 * header files reform
 *
 * Revision 1.13  2002/02/23 13:43:11  joy
 * input related code separated from main.cpp
 *
 * Revision 1.12  2002/01/09 19:14:12  milan
 * Preliminary support for SGI/Irix
 *
 * Revision 1.11  2001/11/06 20:36:54  milan
 * MMU's corrections
 *
 * Revision 1.10  2001/10/29 08:15:45  milan
 * some changes around debuggers
 *
 * Revision 1.9  2001/09/25 00:04:17  milan
 * cleaning of memory managment
 *
 * Revision 1.8  2001/09/21 14:23:33  joy
 * little things just to make it compilable
 *
 * Revision 1.7  2001/09/10 15:21:57  joy
 * virtualInterrupt, will be called with 200 Hz freq.
 *
 * Revision 1.6  2001/08/10 18:41:24  milan
 * Some patches, see ChangeLog (CPU API etc.), debianized
 *
 * Revision 1.5  2001/07/24 13:58:52  joy
 * grabMouse() called from uae debugger
 *
 * Revision 1.4  2001/07/20 22:48:19  milan
 * mmu_op use only set/longjmp now, first step for ndebug integration, signals
 * and pthread checks removed, cleaning etc.
 *
 * Revision 1.3  2001/06/18 13:21:55  standa
 * Several template.cpp like comments were added.
 * HostScreen SDL encapsulation class.
 *
 *
 */
