#include "ft_printf.h"

int what_my_case(char c, int now_case)//처리의 목적을 밝히시오....
{
    if (c == '-' || c == '0')
    {
		if (now_case <= 1)
			return (1);
	}
    if(('0' <= c && c <= '9') || c == '*')
    {    if ((now_case <= 2))
			return (2);
	}
    if(('0' <= c && c <= '9') || c == '.' || c == '*')
    {
	    if (now_case <= 3)
			return (3);
	}
    if (ft_strchr("cspdiuxX%", c) != 0)
        return (5);
    return (-1);
}

int ft_printf(const char* str, ...)
{
	va_list ap;
	va_start(ap, str);
	char* arr;
	char *temp;
	char ch;
	int	num;
	int count;
	char **final = malloc(sizeof(char *) * 6);
	char *buf = 0;
	char two[2];
	int i = 0;
	int j;
	char the_type;
	int my_case;
	two[1] = '\0';
	temp = 0;
	while (str[i] != '\0')
	{
		if(str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			i++;
			continue;
		}
		i++;
		my_case = 1;
		if (temp != 0)
			free(temp);
		temp = malloc(sizeof(char) * 1);
		*temp = '\0';
		while(ft_strchr("cspdiuxX%", str[i]) == 0)
		{
			if (my_case != what_my_case(str[i], my_case))
			{
				final[my_case] = ft_strdup(temp);
				my_case++;
				ft_memset(temp, '\0', sizeof(char)*(ft_strlen(temp) + 1));
				*temp = '\0';
				continue;
			}
			if(str[i] == '.')
			{	
				i++;
				continue;
			}
			if (str[i] == '-' || str[i] == '0')
			{
				two[0] = str[i];
				temp = ft_strjoin(temp, two);
				i++;
				continue;
			}
			if (str[i] != '*')
			{
				two[0] = str[i];
				temp = ft_strjoin(temp, two);
				i++;
				continue;
			}
			else
			{
				buf = ft_itoa(va_arg(ap, int));
				temp = ft_strjoin(temp, buf);
				free(buf);
				buf = 0;
				i++;
				if (what_my_case(str[i], my_case) == my_case)
					return (-1);
				continue;
			}
		}
		final[my_case] = ft_strdup(temp);
		my_case++;
		while (my_case < 5)
		{
			final[my_case] = ft_strdup("");
			my_case++;
		}
		ft_memset(temp, '\0', ft_strlen(temp) + 1);
		*temp = '\0';
		the_type = str[i];
		if(the_type == 'c')
		{
			two[0] = (char)va_arg(ap, int);
			temp = ft_strjoin(temp, two);
		}
		if(the_type == 's')
		{
			arr = va_arg(ap, char *);
			temp = ft_strdup(arr);
		}
		else if(the_type == 'p')
		{
			return (-1);
		}
		else if(the_type == '%')
		{
			two[0] = '%';
			temp = ft_strjoin(temp, two);
		}
		else//숫자 부분
		{
			temp = ft_itoa(va_arg(ap, int));
		}
		final[5] = ft_strdup(temp);// c,s,p,%,숫자 이렇게 분기했고, 이 라인에서 2진data에서 해석을 거친 값의 문자열표현이 temp에 들어가있다.
		printf("*final[5] = %c", *final[5]);
		ft_putstr_fd(make_string(final, the_type), 1);
        //지금까지 한 것 : %부터 변환문자까지 내용을 final배열에 저장을 마친 상태이다. 여기 *도 없고  변환문자도 없는 상태이다
        //순수한 문자열들의 집합이 된것이다.
		i++;
	}
	return (count);
}
