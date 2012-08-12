NAME		=	shmupsdl2d
CC		=	gcc
CFLAGS		=	-Wall -Wextra -pedantic -Iinc/
LDFLAGS		=	-lSDL -lSDL_image -lm lib/libSDLazy.a lib/libCList.a
RM		=	@rm -f

SRC		=	src/main.c		\
			src/events.c		\
			src/core.c		\
			src/core_entity_move.c	\
			src/render.c		\
			src/player_init.c	\
			src/entity.c		\

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
