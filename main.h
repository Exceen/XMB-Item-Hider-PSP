/*
	XMBIH (XrossMediaBar™ Item Hider)
	Copyright (C) 2011, Bubbletune
	Copyright (C) 2011, Total_Noob
	Copyright (C) 2008-2011, CompuPhase
	Copyright (C) 2011, Frostegater
	Copyright (C) 2011, codestation
	
	main.c: XMBIH main code
	
	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __MAIN_H__
#define __MAIN_H__

#define MAKE_CALL(a, f) _sw(0x0C000000 | (((u32)(f) >> 2) & 0x03FFFFFF), a);
#define FW(f) ((((f >> 8) & 0xF) << 24) | (((f >> 4) & 0xF) << 16) | ((f & 0xF) << 8) | 0x10)

char ini_path[128];
int patch[13];
int devkit;
int psp_model;

typedef struct
{
	char text[48];
	int play_sound;
	int action;
	int action_arg;
} SceContextItem;

/* On 6.xx change struct SceVshItem, because i use pre-cpu funcs for fixing changes. */
typedef struct
{
	int id;
	int relocate;
	int action;
	int action_arg;
	SceContextItem *context;
	char *subtitle;
	int unk;
	char play_sound;
	char memstick;
	char umd_icon;
#ifdef CONFIG_5xx
	char image[0x18];
	char image_shadow[0x18];
	char image_glow[0x18];
#elif CONFIG_6xx
	char image[4];
	char image_shadow[4];
	char image_glow[4];
#endif
	char text[0x25];
} SceVshItem;

#endif