#include "cub3d.h"

static	void	my_clear(char **lst)
{
	int		i;
	char	*cur;
	char	*del;

	i = 0;
	del = lst[i];
	if (del == 0)
	{
		free(del);
		return ;
	}
	else
	{
		cur = lst[++i];
		free(del);
		while (cur != 0)
		{
			del = cur;
			cur = lst[++i];
			free(del);
		}
	}
}

static	int		get_start(char const *s1, char const c, int end)
{
	int ret;
	int i;

	ret = end + 1;
	if (s1[ret] == '\0')
		return (-1);
	i = 0;
	while (s1[ret + i] != '\0')
	{
		if (s1[ret + i] != c)
			return (ret + i);
		else
			i++;
	}
	return (-1);
}

static	int		get_end(char const *s1, char const c, int start)
{
	int ret;
	int i;

	if (start == -1)
		return (-1);
	ret = start;
	i = 0;
	while (s1[ret + i] != '\0')
	{
		if (c == (s1[ret + i]))
			return (ret + i - 1);
		else
			i++;
	}
	return (ret + i - 1);
}

static	char	**new_ret(char **ret, char const *s1, int start, int end)
{
	int		i;
	int		len;
	char	**return_value;
	char	*str;

	len = 0;
	while (ret[len] != 0)
		len++;
	return_value = (char **)malloc(sizeof(char *) * (len + 2));
	if (return_value == 0)
	{
		my_clear(ret);
		return (0);
	}
	i = -1;
	while (ret[++i] != '\0')
		return_value[i] = ret[i];
	free(ret);
	str = (char *)malloc(sizeof(char) * (end - start + 2));
	ft_strlcpy(str, &s1[start], end - start + 2);
	return_value[i++] = str;
	return_value[i] = 0;
	return (return_value);
}

char			**ft_split(char const *s1, char const c)
{
	char	**ret;
	int		start;
	int		end;

	ret = (char **)malloc(sizeof(char *) * 1);
	if (ret == 0)
		return (0);
	*ret = 0;
	start = get_start(s1, c, -1);
	end = get_end(s1, c, start);
	while (start != -1)
	{
		ret = new_ret(ret, s1, start, end);
		if (ret == 0)
			return (0);
		start = get_start(s1, c, end);
		end = get_end(s1, c, start);
	}
	return (ret);
}

int check_news_sprite(char **split)
{
    if (strcmp(split[0], "NO"))//먼저 변수에 저장된 값이 널인지 아닌지 체크하자.
    {

    }
    else if (strcmp(split[0], "SO"))
    {

    }
    else if (strcmp(split[0], "WE"))
    {

    }
    else if (strcmp(split[0], "EA"))
    {

    }
    else if (strcmp(split[0], "S"))
    {

    }
    else 
        return (-1);
    if (-1 == open(split[1], O_RDONLY))
        return (-1);
    return (1);
}

int check_r_f_c(char **split)
{
    if (*split[0] == 'S' && strlen(split) == 1)//먼저 해당변수에 저장된 값이 널인지 아닌지 체크하자.
    {
        if ((0 > ft_atoi(split[1]) || ft_stoi(split[1]) > 255))
            return (-1);
        if ((0 > ft_atoi(split[2]) || ft_stoi(split[2]) > 255))
            return (-1);
        if ((0 > ft_atoi(split[3]) || ft_stoi(split[3]) > 255))
            return (-1);
    }
    else if (*split[0] == 'F' && strlen(split) == 1)
    {
        if ((0 > ft_atoi(split[1]) || ft_stoi(split[1]) > 255))
            return (-1);
        if ((0 > ft_atoi(split[2]) || ft_stoi(split[2]) > 255))
            return (-1);
        if ((0 > ft_atoi(split[3]) || ft_stoi(split[3]) > 255))
            return (-1);
    }
    else if (*split[0] == 'C' && strlen(split) == 1)
    {
        if ((0 > ft_atoi(split[1]) || ft_stoi(split[1]) > 255))
            return (-1);
        if ((0 > ft_atoi(split[2]) || ft_stoi(split[2]) > 255))
            return (-1);
        if ((0 > ft_atoi(split[3]) || ft_stoi(split[3]) > 255))
            return (-1);
    }
    else
        return (-1);
    return (1);
}
int is_only_zero_blank_one(char *arr)
{
    int idx=0;
    while (arr[idx])
    {
        if (strchr("01 ", arr[idx]) == 0)
            return (-1);
    }
    return (1);
}
int par(void)
{
    int fd = open("test.txt", O_RDONLY);
    int count = 0;
    char *buf;
    char **split;
    int lenth = 0;
    while (get_next_line(fd, &buf))
    {
        if (strcmp(buf, "") == 0)
            continue;
        if (count == 8)
            break;
        if (is_only_zero_blank_one(buf) == 1)//count 가 8이 되기도 전에 맵이 나온상황이니 에러임.
            return (-1);
        split = ft_split(buf, ' ');
        while(split[lenth] != 0)
            lenth++;
        if (2 == lenth)
        {
            if (-1 == check_news_sprite(split))
                return -1; 
        }
        else if (lenth == 3)
        {
            if (-1 == (check_r_f_c(split)))
                return (-1);
        }
        else
            return (-1);
        count++;
    }
    if (count != 8)
        return (-1);
    if (-1 == (is_valid_map()))//해당함수에서 맵을 int 이차원 배열에 차곡차곡 저장해나가자 여기서 동적할당을 적극활용하면 된다.
        return (-1);
}