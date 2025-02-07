#include "header.h"

void intial_filename(t_file dafile, char **av)
{
	int i;

	i = 0;
	while (av[1][i])
	{
		dafile.file_name[i] = av[1][i];
		i++;
	}
	dafile.file_name[i] = 0;
}

int main (int ac, char **av)
{
	t_file dafile;

	if (ac != 2)
		return (0);
	intial_filename(dafile, av);
	correct_map_file(&dafile);
}