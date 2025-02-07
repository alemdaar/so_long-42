#ifndef SO_LONG_H
# define SO_LONG_H

#define TRUE 1
#define FALSE 0

typedef struct s_indexes {
	int	i;
	int	j;
	int	k;
	int	c;
	int	r;
	int	f;
}	t_indexes;

typedef struct s_first_last {
	int	first;
	int	last;
}	t_first_last;

typedef struct s_file {
	char	*file_name;
	int		fd;
	char	*current_gnl;
	char	*previous_gnl;
	char	*next_gnl;
	int		line_chars;
	int		count_lines;
	int		count_lines_tmp;
	int		total_count;
	int		helper;
}	t_file;

typedef struct s_map {
	char **map;
	char **tmp_map;
	
}	t_map



#include "../get_next_line/get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int mystrlen(char *str);



int	correct_map_file(t_file dafile);

# endif