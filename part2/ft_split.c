#include <stdlib.h>
#include <stdio.h>

static int is_deli(const char c, char deli)
{
	if(c == deli)
		return (1);
	else
		return (0);
}

static int get_next_head(char const *s, int idx, char deli)
{
	while(is_deli(s[idx], deli))
	{
		if(s[idx] == 0)
			return (-1);
		idx++;
	}
	return (idx);
}

static int get_next_deli(char const *s, int idx, char deli)
{
	while(is_deli(s[idx], deli) == 0)
	{
		if(s[idx] == 0)
			return (-1);
		idx++;
	}
	return (idx);
}

static char *sub_str(char const *s, int start, int end)
{
	int i;
	char *ret;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (end - start + 1));
	while(start <= end)
		ret[i++] = s[start++];
	ret[i] = '\0';
	return (ret);
}

static char **renewer(char **p, char *new_str)
{
	int count;
	int idx;
	char **ret;

	count = 0;
	while(p[count] != 0)
		count++;
	ret = malloc(sizeof(char *) * (count + 2));
	idx = 0;
	while(p[idx] != 0)
		ret[idx++] = p[idx];
	free(p);
	ret[idx++] = new_str;
	ret[idx] = 0;
	return (ret);
}

char **ft_split(char const*s, char c)
{
	int start;
	int end;
	char **ret;

	start = get_next_head(s, 0, c);
	printf("%d\n",start);
	end =  get_next_deli(s, start, c);
	printf("%d\n",end);
	ret = (char **)malloc(sizeof(char *) * 2);
	if(ret == 0)
		return (0);
	ret[0] = sub_str(s, start, end - 1);
	printf("%s\n", ret[0]);
	ret[1] = 0;

	while(1)
	{
		start = get_next_head(s, end, c);
		if(start == -1)
			break;
		end = get_next_deli(s, start, c);
		if(end == -1)
			break;
		ret = renewer(ret, sub_str(s, start, end - 1));
	}
	return (ret);
}

int main(void)
{
	char *arr = "koreaiiiappleicoffeeii";
	char deli = 'i';
	char *s = sub_str(arr, 1, 5);
	printf("%s\n",s);
	char **p = ft_split(arr, deli);
	printf("%s\n%s\n", p[0], p[1]);
	return (0);
}
