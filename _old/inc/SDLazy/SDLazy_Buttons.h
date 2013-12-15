#ifndef			SDLAZY_BUTTONS_H
# define		SDLAZY_BUTTONS_H

# include		"CList.h"
# include		"SDLazy_Surfaces.h"
# include		"SDLazy_ObjHeader.h"
# include		"SDLazy_TinySprite.h"
# include		"myMath.h"

typedef			enum
  {
    BUTTON_MOUSEOVER, BUTTON_MOUSEOUT,
    BUTTON_CLICDOWN, BUTTON_CLICUP,
    NB_BUTTON_EVENTS
  }			eButtonEvent;

typedef			struct
{
  SDLazy_ObjHeader	header;
  SDLazy_TinySprite**	tinySp_tab;
  void			(*f[NB_BUTTON_EVENTS])();
  Uint16		nb_states;
  Uint16		curr_state;
  Uint8			enable;
  Uint8			pressed;
  Uint8			hover;
}			SDLazy_Button;

typedef			struct
{
  CList			list;
}			SDLazy_Buttons;

void			SDLazy_InitButtons(SDLazy_Buttons*);
void			SDLazy_FreeButtons(SDLazy_Buttons*);

SDLazy_Button*		SDLazy_ButtonCreate(SDLazy_Surface*, Uint16 nb_states);
void			SDLazy_ButtonDestroy(SDLazy_Button* b);

/* Enable / Disable */
void			SDLazy_ButtonEnable(SDLazy_Button*);
void			SDLazy_ButtonDisable(SDLazy_Button*);

/* Fonction Callback */
void			SDLazy_ButtonSetFun(SDLazy_Button*, eButtonEvent, void (*f)());

/* State */
void			SDLazy_ButtonSetState(SDLazy_Button*, Uint16 state);
Uint16			SDLazy_ButtonGetState(SDLazy_Button*);

/* Events */
void			SDLazy_ButtonMouseMove(void);
void			SDLazy_ButtonClicDown(void);
void			SDLazy_ButtonClicUp(void);

#endif
