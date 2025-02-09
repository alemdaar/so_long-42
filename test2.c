#include <stdio.h>
#include <stdlib.h>
// #include "get_next_line.h"

int fain = 0;

char **fill_map(int count, int len)
{
	char **str;

	int i = 0;
	int j = 0;
	char c = '.';
	str = (char **) malloc (sizeof(char *) * count);
	if (!str)
		exit(1);
	while (i < count)
	{
		str[i] = (char *) malloc (sizeof(char) * len + 1);
		if (!str[i])
			exit(1);
		i++;
	}
	i = 0;
	// printf ("count : %d\n", count);
	// printf ("len : %d\n", len);
	// printf ("j : %d\n", j);
	// printf ("i : %d\n", i);
	while (i < count)
	{
		j = 0;
		while (j < len) {
			// printf ("j : %d\n", j);
			str[i][j++] = '1';
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < count)
	{
		j = 0;
		while (j < len)
			printf ("%c  ", str[i][j++]);
		printf ("\n");
		i++;
	}
	printf ("\n\n");
	
	// printf ("nb is     %d\n", i);
	str[1][1] = c;
	str[1][3] = c;
	str[1][5] = c;
	str[1][6] = c;
	str[1][7] = c;
	str[2][1] = c;
	str[2][2] = c;
	str[2][3] = 'C';
	str[2][6] = c;
	str[3][1] = c;
	str[3][2] = c;
	str[3][3] = c;
	// str[3][4] = c;
	str[3][5] = c;
	str[3][6] = c;
	str[3][7] = c;
	str[3][8] = c;
	str[4][5] = c;
	str[4][6] = 'C';
	str[4][7] = c;
	str[4][8] = c;
	str[5][1] = c;
	str[5][3] = c;
	str[5][4] = c;
	str[5][6] = c;
	str[5][7] = c;
	str[5][8] = c;
	str[6][6] = c;
	str[6][7] = c;
	str[6][8] = c;
	str[7][1] = c;
	str[7][2] = c;
	str[7][3] = c;
	str[7][6] = c;
	str[7][7] = c;
	str[7][8] = c;
	str[8][1] = 'C';
	str[8][2] = c;
	str[8][3] = c;
	str[8][4] = c;
	str[8][5] = c;
	str[8][6] = c;
	str[8][7] = c;
	str[8][8] = 'P';

	i = 0;
	j = 0;
	while (i < count)
	{
		j = 0;
		while (j < len)
			printf ("%c  ", str[i][j++]);
		printf ("\n");
		i++;
	}
	return str;
}

char ** copy_map(char **str, int count, int len)
{
	char **copy;

	int i = 0;
	int j = 0;
	char c = '.';
	copy = (char **) malloc (sizeof(char *) * count);
	if (!copy)
		exit(1);
	while (i < count)
	{
		copy[i] = (char *) malloc (sizeof(char) * len + 1);
		if (!copy[i])
			exit(1);
		i++;
	}
	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < len)
		{
			copy[i][j] = str[i][j];
			j++;
		}
		i++;
	}
	copy[1][1] = c;
	copy[1][3] = c;
	copy[1][5] = c;
	copy[1][6] = c;
	copy[1][7] = c;
	copy[2][1] = c;
	copy[2][2] = c;
	copy[2][3] = 'C';
	copy[2][6] = c;
	copy[3][1] = c;
	copy[3][2] = c;
	copy[3][3] = c;
	// copy[3][4] = c;
	copy[3][5] = c;
	copy[3][6] = c;
	copy[3][7] = c;
	copy[3][8] = c;
	copy[4][5] = c;
	copy[4][6] = 'C';
	copy[4][7] = c;
	copy[4][8] = c;
	copy[5][1] = c;
	copy[5][3] = c;
	copy[5][4] = c;
	copy[5][6] = c;
	copy[5][7] = c;
	copy[5][8] = c;
	copy[6][6] = c;
	copy[6][7] = c;
	copy[6][8] = c;
	copy[7][1] = c;
	copy[7][2] = c;
	copy[7][3] = c;
	copy[7][6] = c;
	copy[7][7] = c;
	copy[7][8] = c;
	copy[8][1] = 'C';
	copy[8][2] = c;
	copy[8][3] = c;
	copy[8][4] = c;
	copy[8][5] = c;
	copy[8][6] = c;
	copy[8][7] = c;
	copy[8][8] = 'P';
	printf ("\n\ndata is : %c\n\n", copy[8][8]);
	return copy;
}

void dfs(char **copy, int daline, int daindex, int count, int len)
{
	// printf ("daline : %d\n", daline);
	// printf ("daindex : %d\n", daindex);
	if (daline < 1 || daline > 8 || daindex < 1 || daindex > 8 || copy[daline][daindex] == '1' || copy[daline][daindex] == 'M')
		return ;
	copy[daline][daindex] = 'M';
	dfs(copy, daline + 1, daindex, count, len);
	dfs(copy, daline - 1, daindex, count, len);
	dfs(copy, daline, daindex + 1, count, len);
	dfs(copy, daline, daindex - 1, count, len);
	return ;
}

void algo(char **str, char **copy, int count, int len)
{
	// line 6 - index 7
	int daline = 6;
	int daindex = 7;
	dfs(copy, daline, daindex, count, len);
}

int main () {
	char	**str;
	char	**copy;
	int		count;
	int		len;
	int		i;
	int		j;

	count = 10;
	len = 10;
	str = fill_map (count, len);
	copy = copy_map(str, count, len);
	algo(str, copy, len, count);
	i = 0;
	j = 0;
	while (i < count)
	{
		j = 0;
		while (j < len)
			printf ("%c  ", copy[i][j++]);
		printf ("\n");
		i++;
	}
	printf ("\n\n");
}














