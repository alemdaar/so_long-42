#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main ()
{
	char text[] = "file.txt";
	char str[5];
	char str2[5];

	int fd = open (text, O_RDONLY);
	ssize_t r = read (fd, str, 5);
	str[r] = '\0';
	printf ("str : %s\n", str);
	
	fd = open (text, O_RDONLY);
	if (fd == -1)
		perror("faild : ");
	ssize_t rr = read (fd, str2, 5);
	str2[r] = '\0';
	printf ("str2 : %s\n", str2);
	printf ("r : %zd\n", r);
	printf ("rr : %zd\n", rr);
}