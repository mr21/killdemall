#include	"core.h"
#include	"data.h"
#include	"xship.h"

void		core(void)
{
  Data*		d = SDLazy_GetData();

  menu_core(&d->menu);
  camera_focus(&d->sdldata, &d->player->pos);

  ship_move(d, d->player);
  xship_move_bases((XShip*)d->player);
  xship_shoot(d, (XShip*)d->player);
  xship_core((XShip*)d->player);

  ammos_core(&d->ammos);
}
