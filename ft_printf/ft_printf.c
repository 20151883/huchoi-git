#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
//va_strat
//va_arg
//va_copy
//va_end
int ft_printf(const char* str, ...)
{
	va_list ap;//va_list *ap is not correct
	va_start(ap, str);//just init!!
	//va_arg(ap, char *) -> (ap가 가리키는 대상 x)
	//문자열에서 str 포인터가 가리키는값을 char *로 해석참조해서 그 값을 반환한다.
	//이때, 참조만 하는거기 때문에 포인터의 변화, data의 변화등등은 없을것이다.
	//그러니까 char *parr = va_args(ap, char *) 이렇게 쓰는게 맞을것이다.
	char* arr;
	char ch;
	int	num;

	while (*str)
	{
		if (strncmp(str, "%s",2) == 0)
		{
			tmp = va_arg(ap, char*);
			while (*tmp)
				putchar(*tmp++);
			str = str + 2;
		}
		else if (strncmp(str, "%c", 2) == 0)
		{
			ch = va_arg(ap, char);
			putchar(ch)
				str = str + 2
		}
		else if (strncmp(str, "%d", 2) == 0)
		{
			num = va_arg(ap, int);
			ft_putnbr(num);//to stdout...
			str = str + 2;
		}
		else
		{
			putchar(*str);
			str++;
		}
	}


}
