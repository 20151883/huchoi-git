#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
​
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
​
# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 1000
# endif
​
# ifndef OPEN_MAX
#	define OPEN_MAX 32
# endif
​
int		get_next_line(int fd, char **line);
int		ft_strlen(char *str);
char	*ft_strdup(const char *src);
char	*ft_strndup(const char *src, int index);
void	*ft_memcpy(void *dest, const void *src, unsigned int n);
char	*ft_strjoin(char const *s1, char const *s2);
​
#endif