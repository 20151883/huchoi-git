#ifndef __GET_NEXT_LINE__
#define __GET_NEXT_LINE__

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
char	*ft_strdup(char *src);
int ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
int     get_next_line(int fd, char **line);
char	*ft_strrchr(char *s, int c);
#endif
