#include	"data.h"

void		data_init(Data* d)
{
  XShip		xship;

  ctrls_init(&d->ctrls, KEYB_EN);
  sdldata_init(&d->sdldata);
  CList_init(&d->ships, NULL);
  CList_init(&d->ammos, NULL);

  xship_init(&d->sdldata, &xship);

  CList_push_back(&d->ships, &xship, sizeof xship);
  d->player = CList_data(CList_end(&d->ships));
}
