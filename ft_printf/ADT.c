#include "ft_pritnf.h"

void put_unsignd_x(size_t num)
{
    char *arr;
    size_t i;

    i = 0;
    arr = (char *)malloc(sizeof(char) * 32);
    while ((num / 10) != 0)
    {
        arr[i]  = (num % 10) + '0';
        i++;
        num = num / 10;
    }
    arr[i] = (num % 10) + '0';
    while(i >= 0)
    {
        putchar(arr[i--]);
    }
    free(arr);
}

void put_signed_x(int num)
{
    if(num < 0)
    {
        puchar('-');
        num = num * (-1);
    }
    put_unsigned_x((size_t)num);
}

void c_case(va_list *app, const char **pstr)
{
    va_list ap;
    char *str;
    char temp;

    ap = *app;
    str = *pstr;
    temp = va_arg(ap, char);
    puchar(temp);
    str = str + 2;
}

void s_case(va_list *app, const char **pstr)
{
    char *temp;

    temp = va_arg(*app, char);
    while(*temp)
    {
        putchar(*temp++);
    }     
}

void p_case(va_list *app)
{
    //void *temp;
    unsigned int temp;

    temp = va_arg(*app, unsigned int);
    put_unsigned_x(temp);//부호없는 16진수 출력
}

void d_case(va_list *app)
{
    int temp;

    temp = va_arg(ap, int);
    ft_putnbr(temp);
}

void i_case(va_list *app)
{
    int temp;

    temp = va_arg(*app, int);
    ft_putnbr(temp);
}
//over this line... all function promisse minus sign...
void u_case(va_list *app)
{
    unsigned int temp;

    temp = va_arg(*app, unsigned int);
    ft_put_unsigend_nbr(temp);//ft_putnbr로는 커버가 안된다.
}

void x_case(va_list *app)
{
    unsigned int temp;

    temp = va_arg(*app, unsigned int);
    put_signed_x(temp);
}

void X_case(va_list *app)
{
    unsigned int temp;

    temp = va_arg(*app, unsigned int);
    put_unsigned_x(temp);//대문자로 출력해야하는데...?
    *pstr = *pstr + 2;
}

//if (strncmp(str, "%%", 2) == 0)
void percent_case(void)
{
    putchar('%');
    //*pstr = *pstr + 2 이거 처리 위에도 해줘야함...
    //그냥 ft_printf에서 진행하자.
}