#include	"ammo.h"

Ammo*		ammo_push(Data* d, Ammo* am)
{
  CLink*	ln = CList_push_back(&d->ammos, am, sizeof *am);

  if (!ln)
    fprintf(stderr, "ammo_push > CList_push_back fail\n");
  return CList_data(ln);
}
