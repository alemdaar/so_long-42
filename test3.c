#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"


int main () {
	char *str;

	int fd = open ("file.txt", O_RDONLY);
	printf ("fd : %d\n", fd);
	str = get_next_line(fd);
	if (!str) {
		printf ("failed !\n");
		return (1);
	}
	printf ("str : %s\n", str);
	int i = 0;
	while (str[i])
		i++;
	printf ("len : %d\n", i);
}