#include	"xship.h"
#include	"kamship.h"

static int	ship_blit(Ship* s)
{
  s->blit(s);
  return CLIST_CONTINUE;
}

void		ships_blit(CList* ships)
{
  CList_foreach(ships, ship_blit);
}
