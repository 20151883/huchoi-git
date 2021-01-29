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
	char *temp;
	int count;
	char *final[6];//final is not use malloc 
	char *buf = 0;
	int i = 0;
	char the_type;
	int my_case;
	char *arr;
	char two[2];
	
	two[1] = '\0';
	//temp = 0;
	while (str[i] != '\0')
	{
		if(str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			i++;
			continue;
		}
		i++;//this is correct
		my_case = 1;
		temp = ft_calloc(1, sizeof(char));
		//*temp = '\0';
		while(ft_strchr("cspdiuxX%", str[i]) == 0)
		{
			if (my_case != what_my_case(str[i], my_case))
			{
				if (case_changed(final, &temp, &my_case))
					return (0);// free is done in over func..
				/*final[my_case] = ft_strdup(temp);
				my_case++;
				ft_memset(temp, '\0', sizeof(char)*(ft_strlen(temp) + 1));
				*temp = '\0';*/
				continue;
			}
			if (str[i] == '.' || str[i] == '-' || str[i] == '0')
			{
				if (flag_precise(final, &temp, (char *)str, &i) == 1)
					continue;//it's good func...??? no!!!!
				else
					return (0);//free is done...!!
			}
			/*if(str[i] == '.')
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
			}*/
			if (str[i] != '*')
			{
				if (1 == not_star(final, (char *)str, &temp, &i))
					continue;
				else
					return (0);// free is done!!
			}
			/*if (str[i] != '*')
			{
				two[0] = str[i];
				temp = ft_strjoin(temp, two);
				i++;
				continue;
			}
			else
			{
				buf = ft_itoa(va_arg(ap, int));//malloc
				if (my_case == 2 && (ft_strchr(buf, '-')))
				{
					two[0] = '-';
					final[1] = ft_strjoin(final[1], two);
					buf[0] = '0';//minus is interchaned to '0'
				}
				temp = ft_strjoin(temp, buf);*/
			else
			{	
				buf = ft_itoa(va_arg(ap, int));
				if (0 == star(final, &temp, buf, my_case))
					return (0);//not continue...!!
				//free(buf);this done in star function
				buf = 0;//is it needed???
				i++;//this action is done in here (not in star func)
				if (what_my_case(str[i], my_case) == my_case)
					return (free_ret_zero(final, temp, NULL));
					//free(buf) is done in "star" func
			}
			//		******************************
			//	if reach here it means error ...!!!
			//	so.. return (0)?? no ..... not that way
		}
		final[my_case] = ft_strdup(temp);
		my_case++;
		while (my_case < 5)
			final[my_case++] = ft_strdup("");
		
		ft_memset(temp, '\0', ft_strlen(temp) + 1);
		*temp = '\0';
		the_type = str[i];//가독성을 위해 넣은것 나중엔 str[i]로 대체할수도 있음...
		if(the_type == 'c')
		{
			two[0] = (char)va_arg(ap, int);
			temp = ft_strjoin(temp, two);
		}
		else if(the_type == 's')
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
		else if (ft_strchr("di", the_type))//숫자 부분
			temp = ft_itoa(va_arg(ap, int));
		else
			temp = ft_itoa(va_arg(ap, unsigned int));//되나?
		//printf("%s\n%s\n%s\n%s\n",final[1], final[2], final[3], final[5]);
		final[5] = ft_strdup(temp);// c,s,p,%,숫자(5가지 경우이겠다.) 이렇게 분기했고, 이 라인에서 2진data에서 해석을 거친 값의 문자열표현이 temp에 들어가있다.
		ft_putstr_fd(make_string(final, the_type), 1);
        //지금까지 한 것 : %부터 변환문자까지 내용을 final배열에 저장을 마친 상태이다. 여기 *도 없고  변환문자도 없는 상태이다
        //순수한 문자열들의 집합이 된것이다.
		free_ret_zero(final, temp, 0);//if reach here... you must free the temp
		i++;
	}
	return (count);
}
