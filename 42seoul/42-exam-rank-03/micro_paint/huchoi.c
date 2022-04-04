#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct circle{
	int is_fill;
	float left_up_x;
	float left_up_y;
	float right_down_x;
	float right_down_y;
	float width;
	float height;
	char character;
}circle;

typedef struct paper{
	int width;
	int height;

}paper;

char * init(FILE *istream)
{
	int width;
	int height;
	char background;
	fscanf(istream, "%d %d %c", &width, &height, &background);
	char *ret = malloc(sizeof(int) * width * height);
	return ret;
}
circle *parsing(FILE *istream, char *arr)
{
	char c, character;
	float width, height;
	float x,y,radius;
	char *test = malloc(1025);
	if (fscanf(istream, "%c %f %f %f %f %c\n", &c, &x, &y, &width,&height, &character) == -1)
		return 0;
	//fscanf(istream, "%[^\n] ", test);
	if (c == 'r' || c == 'R')
	{

	}
	else
	{
		write(2, &c, 1);
		write(2, "this", 4);
		write(2, "errinparsing\n", 13);
	}
	if (radius <= 0.0 || (0 <= character && character <= 31))
	{
		write(2, "that", 4);
		write(2, "errinparsing\n", 13);
	}
	circle *ret = malloc(sizeof(circle) * 1);
	if (c == 'r')
		ret->is_fill = 0;
	else
		ret->is_fill = 1;
	ret->left_up_x = x;
	ret->right_down_x = x + width;
	ret->left_up_y = y;
	ret->right_down_y = y + height;
	ret->width = width;
	ret->height = height;
	ret->character = character;
	return ret;
}
void draw_circle(char *arr, circle *p_circle, int width, int height)
{
	float lenth;
	int size = width * height;
	int x,y;
	for (int idx = 0; idx < size ; idx++)
	{//추상화: 어떠한 점이 사각형의 범위(****)에 들어가 있는지   범위가 핵심
		x = idx % width;
		y = idx / width;
		if (p_circle->left_up_x <= x && x <= p_circle->right_down_x && p_circle->left_up_y <= y && y <= p_circle->right_down_y)
		{//일단 사각형 위의 점이거나 내부의 점.
			if (((x - p_circle->left_up_x < 1.0 || 1.0 > p_circle->right_down_x  - x) || (y - p_circle->left_up_y < 1.0 || 1.0 > p_circle->right_down_y  - y)))
				arr[idx] = p_circle->character;//사각형 위의 점 or 사각형 위의 점이라고 간주할수 있는 점
			else if (p_circle->is_fill)//논리적으로 else이면은 사각형 위의점이라고 말할수없는 내부의 점
				arr[idx] = p_circle->character;
		}
	}
}

void print_circle(char *arr, int width, int height)
{
	for (int idx=0;idx < width * height ; idx++)
	{
		write(1, &arr[idx], 1);
		if (idx % width == (width - 1))
		{
			write(1, "\n", 1);
		}
	}
}

int main(int argc, char *argv[])
{
	FILE *istream = fopen(argv[1], "r");
	int width;
	int height;
	char background;
	fscanf(istream, "%d %d %c\n", &width, &height, &background);
	char *arr = malloc(sizeof(int) * width * height);
	memset(arr, background, width*height);

	circle *temp;
	while (NULL != (temp = parsing(istream, arr)))
	{
		draw_circle(arr, temp, width, height);
		free (temp);
	}
	print_circle(arr, width, height);
	free(arr);
	fclose(istream);
	return (0);
}
