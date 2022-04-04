#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdio.h>


typedef struct circle{
	char c;
	float center_x;
	float center_y;
	float radius;
	char character;
}circle;

circle * getCircle(FILE *istream)
{
	circle *ret = malloc(sizeof(circle));
	if (-1 == fscanf(istream, "%c %f %f %f %c", &ret->c, &ret->center_x, &ret->center_y, &ret->radius, &ret->character))
	{
		free(ret);
		return NULL;
	}
	return ret;
}

void draw_circle(char *arr, circle *p_circle, int width, int height)
{
	int x;
	int y;
	float lenth;
	for(int i = 0;i < width * height; i++)
	{
		x = i % width;
		y = i / width;
		lenth = sqrtf(powf(x - p_circle->center_x, 2.0) + powf(y - p_circle->center_y, 2.0));
		if (lenth <= p_circle->radius)
		{
			if (p_circle->radius - lenth < 1)
			{
				arr[i] = p_circle->character;
			}
			else if (p_circle->c == 'C')
			{
				arr[i] = p_circle->character;
			}
		}
	}
}

void print_circle(char *arr, int width, int height)
{
	for (int i = 0;i < width * height; i++)
	{
		write(1, &arr[i], 1);
		if (i % width == width - 1)
			write(1, "\n", 1);
	}
}
int main(int argc, char *argv[])
{
	if (argc != 2)
		write(2, "error\n", 6);
	int width, height;
	char back_character;
	FILE * istream = fopen(argv[1], "r");
	fscanf(istream, "%d %d %c\n", &width, &height, &back_character);
	char *arr = malloc(sizeof(char) * width * height);
	memset(arr, back_character, width * height);

	circle *p_circle;
	while (NULL != (p_circle = getCircle(istream)))
	{
		draw_circle(arr, p_circle, width, height);
		free(p_circle);
	}
	print_circle(arr, width, height);
	free(arr);
	fclose(istream);
	return (0);
}
