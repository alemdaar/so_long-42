NAME = so_long

NAME_BONUS = so_long_bonus

CC = cc

SRC = mandatory/main.c mandatory/parcing/parcing1.c mandatory/parcing/parcing2.c \
	mandatory/parcing/parcing3.c mandatory/parcing/tools.c mandatory/parcing/map_name.c \
	mandatory/parcing/free.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	mandatory/game/draw_map.c mandatory/game/setup.c \
	mandatory/display/display.c mandatory/parcing/extra.c

SRC_BONUS = bonus/main_bonus.c bonus/parcing/parcing1_bonus.c bonus/parcing/parcing2_bonus.c \
	bonus/parcing/parcing3_bonus.c bonus/parcing/tools_bonus.c bonus/parcing/map_name_bonus.c \
	bonus/parcing/free_bonus.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	bonus/game/draw_map_bonus.c bonus/game/setup_bonus.c \
	bonus/display/display_bonus.c bonus/display/itoa_bonus.c bonus/parcing/extra_bonus.c

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	@$(CC) ${CFLAGS} -Imlx -c $< -o $@

all: ${NAME}

$(NAME): $(OBJ)
	@$(CC) ${CFLAGS} $(OBJ) ${MLX_FLAGS} -o $(NAME)
	@echo "compiled successfully !"

bonus : $(OBJ_BONUS)
	@$(CC) $(OBJ_BONUS) ${CFLAGS} ${MLX_FLAGS} -o $(NAME_BONUS)
	@echo "bonus compiled successfully !"
clean :
	@rm -f ${OBJ} ${OBJ_BONUS}
	@echo "cleaned successfully !"

fclean : clean
	@rm -f ${NAME} ${NAME_BONUS}
re : fclean all