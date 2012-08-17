#include	"ammo.h"
#include	"data.h"
#include	"SDLazy.h"

void		ammo_push(Data* d, Ammo* am)
{
  am->created_time = SDLazy_GetTotalTime();
  am->duration_time += am->created_time;
  if (!CList_push_back(&d->ammos, am, sizeof *am))
    fprintf(stderr, "ammo_push > CList_push_back fail\n");
}
