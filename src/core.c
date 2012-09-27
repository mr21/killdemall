#include	"core.h"
#include	"data.h"
#include	"xship.h"

void		core(void)
{
  Data*		d = SDLazy_GetData();

  menu_core(&d->menu);
  camera_focus(&d->sdldata, &d->player->pos);

  ship_core(d->player);
  xship_core((XShip*)d->player);

  ammos_core(&d->ammos);
}
