#include	"menu.h"

int		menu_mouseover(Menu* d)
{
  return SDLazy_Hover(d->srf[SRF_MENU_BG]);
}
