#include	"ammo.h"

static SDLData*	g_sdldata;

static void	_blit(Ammo* b)
{
  
}

void		ammos_blit(SDLData* d, CList* ammos)
{
  g_sdldata = d;
  CList_foreach(ammos, _blit);
}
