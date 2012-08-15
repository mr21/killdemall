#include	"data.h"

void		data_init(Data* d)
{
  sdldata_init(&d->sdldata);
  player_init(&d->sdldata, &d->player);
  CList_init(&d->ammos, NULL);
}
