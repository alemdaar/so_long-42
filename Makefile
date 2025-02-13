all:
	cc -lmlx -framework OpenGL -framework AppKit mandatory/main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
	./a.out map.ber