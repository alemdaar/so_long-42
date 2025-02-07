#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int main () {
	char *str;
	int i = 0;
	int fd = open ("file.txt", O_RDONLY);
	str  = get_next_line(fd);
	if (!str) {
		printf ("not allocated !\n");
		return (1);
	}
	while (str[i])
		i++;
	printf ("i : %d\n", i);
	return 0;
}