#include <stdio.h>
#include "libft.h"
#include <math.h>
#include "string.h"
int		parse(char *path);
int		is_border(float *center, float radias, float row, float col)
{
	float dist_x = powf(center[0] - row, 2.0);
	float dist_y = powf(center[1] - col, 2.0);
	float dist = dist_x + dist_y;
	//radias = powf(radias, 2);
	float diff = sqrtf(dist) - radias;
	if (0 <= diff && diff < 1.0)
	{
		return 1;
	}
	else if (0 > diff)
	{
		return (0);
	}
	else
		return (-1);
}
int main(int argc, char *argv[])
{
	float center[2] = {50, 50};
	char border_char = '_';
	char inside_char = '@';
	float radias = 30;
	char prac[100][100];
	memset(prac, '$', 10000);
	int i = 0;
	int j;
	parse(argv[1]);
	while (i < 100)
	{
		j = 0;
		while (j < 100)
		{
			int ret = is_border(center, radias, i, j);
			if (ret == 1)
				prac[i][j] = border_char;
			else if (ret == 0)
				prac[i][j] = inside_char;
			j++;
		}
		i++;
	}
	for (int count = 0;count <99;count++)
	{
		for (int sub = 0;sub < 99;sub++)
			printf("%c", prac[count][sub]);
		printf("\n");
	}
	return (0);
}
