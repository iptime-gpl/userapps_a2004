/*
 * Digital Beep Input Interface for HD-audio codec
 *
 * Author: Matthew Ranostay <mranostay@embeddedalley.com>
 * Copyright (c) 2008 Embedded Alley Solutions Inc
 *
 *  This driver is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This driver is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 */

#ifndef __SOUND_HDA_BEEP_H
#define __SOUND_HDA_BEEP_H

#include "hda_codec.h"

/* beep information */
struct hda_beep {
	struct input_dev *dev;
	struct hda_codec *codec;
	char phys[32];
	int tone;
	int nid;
	int enabled;
	struct work_struct beep_work; /* scheduled task for beep event */
};

#ifdef CONFIG_SND_HDA_INPUT_BEEP
int snd_hda_attach_beep_device(struct hda_codec *codec, int nid);
void snd_hda_detach_beep_device(struct hda_codec *codec);
#else
#define snd_hda_attach_beep_device(...)		0
#define snd_hda_detach_beep_device(...)
#endif
#endif
