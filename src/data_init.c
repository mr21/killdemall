#include	"data.h"

void		data_init(Data* d)
{
  XShip		xship;

  sdldata_init(&d->sdldata);

  menu_load(&d->menu);
  ctrls_init(&d->ctrls, KEYB_EN);
  SDLazy_ButtonSetState(d->menu.btn[BTN_MENU_KEYBOARD], d->ctrls.kb);

  CList_init(&d->ships);
  CList_init(&d->ammos);

  xship_init(&d->sdldata, &xship);

  CList_push_back(&d->ships, &xship, sizeof xship, NULL);
  d->player = CLink_data(CList_end(&d->ships));
}
