SRC_FILES	=	init.c			colors.c	complex.c \
				julia.c			key_hooks.c	mouse_hook.c \
				mandelbrot.c	message.c	pixel_draw.c \
				burning_ship.c	utils.c		main.c

SRC_DIR		=	src/
LIB			= 	minilibx/
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I${LIB} -I${INCL_DIR}
NAME		=	fractol
SRC			=	${addprefix ${SRC_DIR}, ${SRC_FILES}}
OBJ			=	${SRC:%.c=%.o}
INCL_DIR	=	includes/
INCL_FILES	=	errors.h		fractol.h	keys.h
INCL		=	${addprefix ${INCL_DIR}, ${INCL_FILES}}
.PHONY:
	all re clean fclean bonus

%.o: %.c ${INCL}
	$(CC) ${CFLAGS} -c $< -o $@

$(NAME): $(SRC) ${INCL}
	$(CC) ${CFLAGS} -L${LIB} -lmlx -framework OpenGL -framework AppKit ${SRC} -o $(NAME)

all: ${NAME}
	
bonus: ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all
	