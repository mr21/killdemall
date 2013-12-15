#include	"SDLazy.h"
#include	"sdldata.h"

#define		CAMSPD		4.0

void		camera_focus(SDLData* d, v2f* v)
{
  d->cam.x += (v->x - d->cam.x) * CAMSPD * SDLazy_GetFrameTime();
  d->cam.y += (v->y - d->cam.y) * CAMSPD * SDLazy_GetFrameTime();
}
