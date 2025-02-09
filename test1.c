#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main (char **av)
{
	char *text = "file.txt";
	char str[5];
	char str2[5];

	int fd = open (text, O_RDONLY);
	ssize_t r = read (fd, str, 6);
	str[r] = '\0';
	printf ("str : %s\n", str);
	close (fd);
	int fd2 = open (text, O_RDONLY);
	printf ("fd2 : %d\n", fd2);
	// if (fd2 == -1) {
	// 	printf ("hahahahhhahahahahaha\n");
	// 	return 1;
	// }
	ssize_t rr = read (fd2, str2, 6);
	str2[rr] = '\0';
	printf ("str2 : %s\n", str2);
	printf ("r : %zd\n", r);
	printf ("rr : %zd\n", rr);
}