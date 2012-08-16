NAME		=	shmupsdl2d
CC		=	gcc
CFLAGS		=	-Wall -Wextra -pedantic
CFLAGS		+=	-Iinc -Iinc/SDLazy -Iinc/SDLazy/CList
LDFLAGS		=	-lSDL -lSDL_image -lm lib/libSDLazy.a lib/libCList.a
RM		=	@rm -f

SRC		=	src/main.c		\
			src/data_init.c		\
			src/sdldata_init.c	\
			src/events.c		\
			src/core.c		\
			src/core_ship_move.c	\
			src/render.c		\
			src/pos_onscreen.c	\
			src/ship.c		\
			src/xship_init.c	\
			src/ammo_push.c		\
			src/ammos_blit.c	\

OBJ		=	$(SRC:.c=.o)

$(NAME)		:	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

all		:	$(NAME)

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean $(NAME)

.PHONY		:	all clean fclean re
