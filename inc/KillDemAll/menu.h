#ifndef		MENU_H
#define		MENU_H

#include	"SDLazy.h"

enum
{
  SRF_MENU_BG,
  SRF_MENU_FULLSCREEN,
  SRF_MENU_KEYBOARD,
  SRF_MENU_COMMANDS,
  SRF_MENU_OPEN,
  NB_SRF_MENU
};

enum
{
  BTN_MENU_FULLSCREEN,
  BTN_MENU_KEYBOARD,
  BTN_MENU_COMMANDS,
  BTN_MENU_OPEN,
  NB_BTN_MENU
};

typedef			struct
{
  SDLazy_Surface*	srf[NB_SRF_MENU];
  SDLazy_Button*	btn[NB_BTN_MENU];
  char			status;
}			Menu;

void			menu_init(Menu*);
void			menu_blit(Menu*);
void			menu_core(Menu*);
void			menu_open(Menu*);
void			menu_close(Menu*);
void			menu_toggle(void);
int			menu_mouseover(Menu* d);

#endif
