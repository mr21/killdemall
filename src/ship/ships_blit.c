#include	"xship.h"
#include	"kamship.h"

static int	ship_blit(Ship* s)
{
  switch (s->type)
    {
    case XSHIP:   xship_blit((XShip*)s);     break;
    case KAMSHIP: kamship_blit((KamShip*)s); break;
    }
  return CLIST_CONTINUE;
}

void		ships_blit(CList* ships)
{
  CList_foreach(ships, ship_blit);
}
