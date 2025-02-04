#include "header.h"

int main (int ac, char **av)
{
	t_file dafile;

	if (ac != 2)
		return (0);
	correct_map_file(dafile);
}