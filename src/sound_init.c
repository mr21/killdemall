#include	<stdio.h>
#include	"sound.h"

int		sound_init(Sound* s)
{
  FMOD_RESULT	res;

  if ((res = FMOD_System_Create(&s->system)) != FMOD_OK)
    return printf("FMOD error! (%d) %s\n", res, FMOD_ErrorString(res));
  return 0;
}
