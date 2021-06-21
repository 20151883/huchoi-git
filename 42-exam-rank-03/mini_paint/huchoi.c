#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct circle{
	int is_fill;
	float center_x;
	float center_y;
	float radius;
	char character;
}circle;

circle *parsing(FILE *istream, char *arr)
{
	char c, character;
	float x,y,radius;
	char *test = malloc(1025);
	if (fscanf(istream, "%c %f %f %f %c\n", &c, &x, &y, &radius, &character) == -1)//**********
		return 0;
	if (c == 'c' || c == 'C')
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
	if (c == 'c')
		ret->is_fill = 0;
	else
		ret->is_fill = 1;
	ret->center_x = x;
	ret->center_y = y;
	ret->radius = radius;
	ret->character = character;
	return ret;
}

void draw_circle(char *arr, circle *p_circle, int width, int height)
{
	float lenth;
	int size = width * height;
	int x,y;
	for (int idx = 0; idx < size ; idx++)
	{
		x = idx % width;
		y = idx / width;
		lenth = sqrtf(powf(x - p_circle->center_x, 2.0) + powf(y - p_circle->center_y, 2.0));
		float diff = lenth - p_circle->radius;//추상화: 원의중심점과 점 사이의 거리(원과 점의 위치관계)
		if (-1 < diff && diff <= 0)//원 위의점, 원의 위의점이라고 볼수 있는 점
			arr[idx] = p_circle->character;
		else if (lenth < p_circle->radius && p_circle->is_fill == 1)
			arr[idx] =  p_circle->character;
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

int main(void)
{
	FILE *istream = fopen("./examples/2", "r");
	//FILE *istream = fopen("example_", "r");
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
	}//위 블럭이 중요

	print_circle(arr, width, height);//문자 출력하고, 적절한 시기에 개행 출력
	free(arr);
	fclose(istream);
	return (0);
}
