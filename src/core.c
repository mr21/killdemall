#include	"core.h"
#include	"data.h"

void		core_camera_focus(SDLData* d, v2f* v)
{
#define		CAMSPD		4.0
  d->cam.x += (v->x - d->cam.x) * CAMSPD * SDLazy_GetFrameTime();
  d->cam.y += (v->y - d->cam.y) * CAMSPD * SDLazy_GetFrameTime();
}

void		core(void)
{
  Data*		d = SDLazy_GetData();

  core_entity_move(d, &d->player.entity);
  core_camera_focus(&d->sdldata, &d->player.entity.pos);
}
