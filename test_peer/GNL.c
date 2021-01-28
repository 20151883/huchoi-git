#include "get_next_line.h"
​
int		idx_newline(char *backup)
{
	int				i;
​
	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
​
int		split_buf(char **backup, int newline_idx, char **line)
{
	char	*temp;
​
	(*backup)[newline_idx] = '\0';   123\n123 123\0123  123\n456 -> 456 
	*line = ft_strdup(*backup); //인덱스 전까지 복사하고 널추가해서 저장하는 함수
	temp = ft_strdup(*backup + newline_idx + 1); //개행문자 이후를 temp 에 저장
	free(*backup); // backup free 해주기
	*backup = temp; //짧아진 backup 넣어주기!
	return (1);
}
​
int		is_backup(char **backup, char **line)
{
	*line = ft_strdup(*backup);
	free(*backup);
	return (0);
}
​
int		get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*backup[OPEN_MAX];
	int				read_size;
	int				newline_idx;
​
	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	if (!backup[fd])
		backup[fd] = ft_strdup("");
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf);
		if ((newline_idx = idx_newline(backup[fd])) >= 0)
			return (split_buf(&backup[fd], newline_idx, line)); //백업의 내용을 바꾸려면 이차원 배열을 써야한다는 걸 깜빡했군
	}
	if (read_size < 0)
		return (-1);
	if (backup[fd])
		return (is_backup(&backup[fd], line));
	free(backup[fd]);
	*line = ft_strdup("");
	return (0);
}