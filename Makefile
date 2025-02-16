NAME = so_long
CC = cc 
SRC = mandatory/main.c mandatory/parcing/parcing1.c mandatory/parcing/parcing2.c \
	mandatory/parcing/parcing3.c mandatory/parcing/tools.c mandatory/parcing/map_name.c \
	mandatory/parcing/free.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	mandatory/game/draw_map.c mandatory/game/setup.c \
	mandatory/display/display.c
OBJ = ${SRC:.c=.o}
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) ${CFLAGS} -Imlx -c $< -o $@

all: ${NAME}

$(NAME): $(OBJ)
	$(CC) $(OBJ) ${CFLAGS} ${MLX_FLAGS} -o $(NAME)

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f ${NAME}

re : fclean all