#ifndef		SOUND_H
#define		SOUND_H

#include	"fmod.h"
#include	"fmod_errors.h"

typedef		struct
{
  FMOD_SYSTEM*	system;
}		Sound;

int		sound_init(Sound*);

#endif
