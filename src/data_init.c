#include	"data.h"
#include	"xship.h"
#include	"kamship.h"

static void	tmp(Data* d)
{
  XShip		xship;
  KamShip	kamship;

  xship_init(&xship);
  kamship_init(&kamship);
  ship_setpos((Ship*)&kamship, v2f_(50, 50));

  CList_push_back(&d->ships, &xship, sizeof xship, NULL);
  CList_push_back(&d->ships, &kamship, sizeof kamship, NULL);

  d->player = CLink_data(CList_begin(&d->ships));
  /*d->player = CLink_data(CList_end(&d->ships));*/
}

void		data_init(Data* d)
{
  sdldata_init(&d->sdldata);
  sound_init(&d->sound);
  menu_init(&d->menu);
  ctrls_init(&d->ctrls);
  SDLazy_ButtonSetState(d->menu.btn[BTN_MENU_KEYBOARD], d->ctrls.kb);
  CList_init(&d->ships);
  CList_init(&d->ammos);
  tmp(d);
}
