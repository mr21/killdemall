#ifndef		SDLDATA_H
#define		SDLDATA_H

#include	"SDLazy.h"
#include	"sdldata_typedef.h"
#include	"ammo.h"

enum
{
  BG0,
  NB_BGS
};

enum
{
  SRF_SHIP_NO, SRF_SHIP_NE, SRF_SHIP_SO, SRF_SHIP_SE,
  SRF_SHIP_TURRET, SRF_SHIP_REACTOR,
  SRF_SHIP_BASE, SRF_SHIP_TOP,
  NB_SRF_SHIP
};

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

struct			SDLData
{
  SDLazy_Surface*	srf_bg[NB_BGS];
  SDLazy_Surface*	srf_ship[NB_SRF_SHIP];
  SDLazy_Surface*	srf_ammo[NB_AMMOS];
  SDLazy_Surface*	srf_menu[NB_SRF_MENU];
  SDLazy_Button*	btn_menu[NB_BTN_MENU];
  v2f			cam;
};

void			sdldata_init(SDLData*);

#endif
