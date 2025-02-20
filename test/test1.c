#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char *str;

	str = NULL;
    printf ("str : %p", str);
    free(str);
}