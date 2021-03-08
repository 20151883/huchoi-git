#include "gnl.h"

#define BUFFER_SIZE 100;

int	get_next_line(int fd, char **line)
{
	static char *backup;
	char *buf;
	int ret;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while(1)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = 0;
		if(ret == 0)
			return (case_zero(line, backup, buf));
		else if (0 < ret && ret <= BUFFER_SIZE)
		{
			ret = case_non_zero(line, backup, buf);
			if (ret == 42)
				continue;
			return (ret);
		}
	}
}
