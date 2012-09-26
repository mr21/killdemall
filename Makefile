NAME		=	killdemall

BIN		=	bin/
SRC		=	src/
INC		=	inc/

CC		=	gcc

CFLAGS		=	-Wall -Wextra -pedantic -ansi
CFLAGS		+=	-I$(INC)KillDemAll
CFLAGS		+=	-I$(INC)FmodEx
CFLAGS		+=	-I$(INC)SDLazy
CFLAGS		+=	-I$(INC)CList

LDFLAGS		=	-L.
LDFLAGS		+=	-lm
LDFLAGS		+=	$(BIN)libSDL-1.2.so.0
LDFLAGS		+=	$(BIN)libSDL_image-1.2.so.0
LDFLAGS		+=	$(BIN)libtiff.so.3
LDFLAGS		+=	$(BIN)libjpeg.so.62
LDFLAGS		+=	$(BIN)libSDLazy.so
LDFLAGS		+=	$(BIN)libCList.so
LDFLAGS		+=	$(BIN)libfmodex64.so
LDFLAGS		+=	-pthread

RM		=	@rm -f

OBJ		=	$(SRC)main.o
OBJ		+=	$(SRC)data_init.o
OBJ		+=	$(SRC)sdldata_init.o
OBJ		+=	$(SRC)sound.o
OBJ		+=	$(SRC)controls.o
OBJ		+=	$(SRC)menu.o
OBJ		+=	$(SRC)events.o
OBJ		+=	$(SRC)core.o
OBJ		+=	$(SRC)camera_focus.o
OBJ		+=	$(SRC)render.o
OBJ		+=	$(SRC)pos_onscreen.o
OBJ		+=	$(SRC)ship/ship.o
OBJ		+=	$(SRC)ship/ship_init.o
OBJ		+=	$(SRC)ship/ship_setters.o
OBJ		+=	$(SRC)ship/ship_move.o
OBJ		+=	$(SRC)ship/ship_recoil.o
OBJ		+=	$(SRC)ship/ships_blit.o
OBJ		+=	$(SRC)ship/xship/xship_init.o
OBJ		+=	$(SRC)ship/xship/xship_blit.o
OBJ		+=	$(SRC)ship/xship/xship_core.o
OBJ		+=	$(SRC)ship/xship/xship_move.o
OBJ		+=	$(SRC)ship/xship/xship_cannon_fire.o
OBJ		+=	$(SRC)ship/xship/xship_move_bases.o
OBJ		+=	$(SRC)ship/xship/xship_shoot.o
OBJ		+=	$(SRC)ship/kamship/kamship_init.o
OBJ		+=	$(SRC)ship/kamship/kamship_blit.o
OBJ		+=	$(SRC)ship/kamship/kamship_core.o
OBJ		+=	$(SRC)ammo/ammo_push.o
OBJ		+=	$(SRC)ammo/ammos_core.o
OBJ		+=	$(SRC)ammo/ammos_blit.o

$(NAME)		:	$(OBJ)
			$(CC) -o $(BIN)$(NAME) $(OBJ) $(LDFLAGS)

all		:	$(NAME)

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(BIN)$(NAME)

re		:	fclean $(NAME)

.PHONY		:	all clean fclean re
