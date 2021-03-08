#include "gnl.h"

int case_non_zero(char **line, char *backup, char *buf)
{
	char *temp;
	char *p;

	temp = ft_strdup(backup, buf);
	free(backup);
	backup = temp;
	if (NULL != (p = ft_strchr(backup, '\n')))
	{
		//find_new_line(line, backup, buf);
		free(buf);
		*p = '\0';
		*line = ft_strdup(backup);
		temp = ft_strdup(p+1);
		free(backup);
		backup = temp;
		return (1);
	}
	else
		return (42);
}

int case_zero(char **line, char *backup, char *buf)
{
	char *temp;
	char *p;

	if (0 != (p = ft_strchr(backup, '\n')))
	{
		free(buf);
		*p = '\0';
		*line = ft_strdup(backup);
		temp = ft_strdup(p+1);
		free(backup);
		backup = temp;
		return (1);
	}
	else
	{
		line = ft_strdup(backup);
		free(buf);
		free(backup);
		return (0);
	}
}
