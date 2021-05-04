#include "libft.h"
#include <stdio.h>
int		parse(char *path)
{
	FILE *fp;
	fp = fopen(path, "r");
	char buf[1000];
	int a,b;
	char c;
	while (1)
	{
		fscanf(fp, "%d %d %c", &a, &b, &c);
		printf("%d %d %c", a, b, c);
		fclose(fp);
		return (0);
	}
	fclose(fp);
	return 1;
}
