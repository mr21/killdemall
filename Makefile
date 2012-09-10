NAME		=	shmupsdl2d

BIN		=	bin/
SRC		=	src/

CC		=	gcc

CFLAGS		=	-Wall -Wextra -pedantic
CFLAGS		+=	-Iinc
CFLAGS		+=	-Iinc/FmodEx
CFLAGS		+=	-Iinc/SDLazy
CFLAGS		+=	-Iinc/SDLazy/CList

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
OBJ		+=	$(SRC)sound_init.o
OBJ		+=	$(SRC)controls.o
OBJ		+=	$(SRC)menu.o
OBJ		+=	$(SRC)events.o
OBJ		+=	$(SRC)core.o
OBJ		+=	$(SRC)camera_focus.o
OBJ		+=	$(SRC)render.o
OBJ		+=	$(SRC)pos_onscreen.o
OBJ		+=	$(SRC)ship.o
OBJ		+=	$(SRC)ship_move.o
OBJ		+=	$(SRC)ship_recoil.o
OBJ		+=	$(SRC)xship_init.o
OBJ		+=	$(SRC)xship_blit.o
OBJ		+=	$(SRC)xship_move.o
OBJ		+=	$(SRC)xship_move_bases.o
OBJ		+=	$(SRC)xship_shoot.o
OBJ		+=	$(SRC)ammo_push.o
OBJ		+=	$(SRC)ammos_core.o
OBJ		+=	$(SRC)ammos_blit.o

$(NAME)		:	$(OBJ)
			$(CC) -o $(BIN)$(NAME) $(OBJ) $(LDFLAGS)

all		:	$(NAME)

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean $(NAME)

.PHONY		:	all clean fclean re
