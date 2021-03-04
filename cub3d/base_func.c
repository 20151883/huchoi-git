#include "cub3d.h"

void	message_exit(void)
{
	printf("error\nwhy you paly this game...???");
	exit(0);
}

int		is_only_zero_blank_one(char *arr)
{
	int idx;

	idx = 0;
	while (arr[idx])
	{
		if (strchr("012 NEWS", arr[idx++]) == 0)
			return (-1);
	}
	return (1);
}

int		check_first(char *buf, int *p_flag)
{
	if (strchr(buf, '0') != 0)
		message_exit();
	return (1);
}

int		check_last(char *buf)
{
	int i;
	int j;

	i = 0;
	while (buf[i])
	{
		if (buf[i++] != '1')
			message_exit();
	}
	return (1);
}
