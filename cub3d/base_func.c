#include "cub3d.h"

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