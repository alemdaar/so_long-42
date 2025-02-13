#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>

#define TRUE 1
#define FALSE 0
#define FAILED 1
#define SUCCEFULL 0

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
	char	*file_name_copy;
	int		fd;
	char	*current_gnl;
	int		line_chars;
	int		count_lines;
	int		total_count;
	int		helper;

}	t_file;

typedef struct s_map {
	char **map;
	char **tmp_map;
	
}	t_map;



#include "../get_next_line/get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>


# endif