/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:38:52 by oelhasso          #+#    #+#             */
/*   Updated: 2025/03/06 12:14:08 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "../get_next_line/get_next_line.h"
// RULES
# define TRUE 1
# define FALSE 0
# define FAILED 1
# define SUCCEFULL 0
# define WIN_RULE 40
// DIRECTIONS
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125
// ALPHA_DIRECTIONS
# define D_KEY 2
# define A_KEY 0
# define W_KEY 13
# define S_KEY 1
// MAP_TOOLS
# define WALL 49
# define EMPTY 48
# define COLLECT 67
# define EXIT 69
# define PLAYER 80
// EXIT_KEY
# define ESC_KEY 53

typedef struct s_indexes {
	int	i;
	int	j;
	int	k;
	int	c;
	int	p;
	int	e;

}	t_indexes;

typedef struct s_file {
	char	*file_name;
	int		fd;
	char	*current_gnl;
	int		line_chars;
	int		count_lines;
	int		total_count;
	int		helper;

}	t_file;

typedef struct s_map {
	char	**map;
	char	**tmp_map;
}	t_map;

typedef struct game {
	void	*mlx;
	void	*win;
	void	*wall_img;
	void	*empty_img;
	void	*player_img;
	void	*coin_img;
	void	*exit_img;
	int		img_width;
	int		img_height;
	int		posx;
	int		posy;
	char	**map;
	int		count_lines;
	int		collects;
	int		move;
}	t_game;

// parcing part
// parcing1
int		correct_map_file(char *input_name, t_map **maps, t_file *dafile);
void	correct_map(t_file *dafile, t_map **maps);
int		count_lines(t_file *dafile, t_map **maps);
int		count_lines_p2(t_file *dafile, t_map **maps);
int		check_lines(char *str, int first_count, t_map **maps, char *filename);
// parcing2
int		make_map(t_map *maps, t_file *dafile);
int		copy_map(t_map *maps, t_file dafile);
void	check_map(t_map *maps, t_file dafile);
int		line_is_1(char *line);
int		checkcen(char *line, int count, t_map *maps, t_file dafile);
// parcing3
int		check_elements(t_map *maps, t_file dafile);
int		check_elements2(t_indexes index, t_map *maps, t_file dafile);
void	fill_map(t_map maps, t_file dafile);
void	flood_fill(t_map maps, t_file dafile, int daline, int daindex);
int		can_reach(t_map *maps, t_file dafile);
// map name
int		map_name(char *input_name);
int		find_extention(char *str, int ind, char *word);
// tools
int		mystrlen(char *str);
int		open_fd(char *file_name);
char	*remove_nl(char *current_gnl);
int		map_symbols(char symbol);
void	fill_copy(t_map *maps, t_indexes *index);
// free
void	free_maps(t_map *maps, int last);
void	free_maps_c(t_map *maps, int last);
void	free_gmap(t_game *game, int last);
void	free_mlx(t_game *game);
void	why_exit(char *str, int operation);
// extra
void	make_map2(t_map *maps, t_file *dafile, t_indexes *index);
void	copy_map2(t_map *maps, t_file dafile, t_indexes *index);
void	checkcen2(char *line, t_map *maps, t_file dafile, t_indexes *index);
// game part
// setup
int		set_up(t_game	*game, t_file dafile);
void	find_player(t_game *game);
void	calculate_collect(t_game *game);
// draw map
void	draw_map(t_game game);
void	moveplayer(t_game *game, int x, int y);
int		last_move(t_game *game, int x, int y);
// display
void	myputchar(char c);
void	myputstr(char *str);
void	myputnbr(int n);
// main
int		close_window(t_game *game);

#endif