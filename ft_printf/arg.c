#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void ft_putstr_fd(char *s, int fd);
void ft_putchar_fd(char c, int fd);

void	ft_printf(const char * str, ...)
{
	va_list ap;
	va_start(ap, str);
	int i = 0;
	char *temp;
	char ch;

	while(str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			continue;
		}
		if (str[i-1] != '%')
			ft_putchar_fd(str[i++], 1);
		else
		{
			if (str[i] == 'c')
			{
			/*	temp = &(va_arg(ap, char));*/
				ch = (char)va_arg(ap, int);
				ft_putchar_fd(ch,1);
			}
			else if (str[i] == 's')
			{
				temp = va_arg(ap, char *);
				ft_putstr_fd(temp,1);
			}
			else
				printf("wrong!!!");
			i++;
		}
	}
}

int main(void)
{
	ft_printf("my %c %s printf", 'a', "love");
   return (0);
}   
