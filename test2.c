#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main ()
{
	char *str;
	int fd = open("file.txt", O_RDONLY);
	printf ("fd is : %d\n", fd);
	if (fd == -1)
		exit(1);
	str = get_next_line(fd);
	if (!str) {
		printf ("str failed !\n");
		exit(1);
	}
	printf ("str : %s\n", str);
	int i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			printf ("%d - new line \n", i);
		else
			printf ("%d - its '%c' \n", i, str[i]);
		i++;
	}
	if (str[i] == '\0')
		printf ("%d - null terminator \n", i);
	
}