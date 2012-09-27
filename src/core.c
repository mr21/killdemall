#include	"core.h"
#include	"data.h"

void		core(void)
{
  Data*		d = SDLazy_GetData();

  menu_core(&d->menu);
  camera_focus(&d->sdldata, &d->player->pos);
  ships_core(&d->ships);
  ammos_core(&d->ammos);
}
