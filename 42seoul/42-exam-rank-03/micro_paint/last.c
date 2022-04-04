#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdio.h>


typedef struct circle{
	char c;
	float left_up_x;
	float left_up_y;
	float right_down_x;
	float right_down_y;
	float width;
	float height;
	char character;
}circle;

circle * getCircle(FILE *istream)
{
	circle *ret = malloc(sizeof(circle));
	if (-1 == fscanf(istream, "%c %f %f %f %f %c", &ret->c, &ret->left_up_x, &ret->left_up_y, &ret->width, &ret->height, &ret->character))
	{
		free(ret);
		return NULL;
	}
	ret->right_down_x = ret->left_up_x + ret->width;
	ret->right_down_y = ret->left_up_y + ret->height;
	//에러체크
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
		if (p_circle->left_up_x <= x && x <= p_circle->right_down_x && p_circle->left_up_y <= y && y <= p_circle->right_down_y)
		{
			if (x - p_circle->left_up_x < 1.0 || p_circle->right_down_x - x < 1.0 || y - p_circle->left_up_y < 1.0 || p_circle->right_down_y - y < 1.0)
			{
				arr[i] = p_circle->character;
			}
			else if (p_circle->c == 'R')
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
