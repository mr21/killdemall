#ifndef		MENU_H
#define		MENU_H

#include	"SDLazy.h"

enum
{
  SRF_MENU_BG,
  SRF_MENU_KEYBOARD,
  NB_SRF_MENU
};

enum
{
  BTN_MENU_KEYBOARD,
  NB_BTN_MENU
};

typedef			struct
{
  SDLazy_Surface*	srf[NB_SRF_MENU];
  SDLazy_Button*	btn[NB_BTN_MENU];
}			Menu;

void			menu_load(Menu*);
void			menu_blit(Menu*);
void			menu_core(Menu*);

#endif
