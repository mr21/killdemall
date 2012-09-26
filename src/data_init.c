#include	"data.h"
#include	"xship.h"
#include	"kamship.h"

void		data_init(Data* d)
{
  XShip		xship;
  KamShip	kamship;

  sdldata_init(&d->sdldata);
  sound_init(&d->sound);

  menu_init(&d->menu);
  ctrls_init(&d->ctrls);
  SDLazy_ButtonSetState(d->menu.btn[BTN_MENU_KEYBOARD], d->ctrls.kb);

  CList_init(&d->ships);
  CList_init(&d->ammos);

  xship_init(&xship);
  CList_push_back(&d->ships, &xship, sizeof xship, NULL);
  d->player = CLink_data(CList_end(&d->ships));

  kamship_init(&kamship);
  CList_push_back(&d->ships, &kamship, sizeof kamship, NULL);
}
