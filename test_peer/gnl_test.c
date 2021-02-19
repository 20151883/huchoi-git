#include <unistd.h>
#define BUFFER_SIZE  3
#define BUFFER_SIZE 4//5

int get_next_line(int fd, char **p_line)
{
    char *save;
    char *buf = malloc(sizeof(cahr) * (BUFFER_SIZE + 1));
    int num;
    BUFFER_SIZE = 5;
    static char *arr;//arr ="ne"
    //파일로부터 문자 읽어들이기
    raed(fd, buf, 3); // 결과 buf = "hec"//   arr = "new check(EOF)"
    //개행문자 유무 체크
    if (is_newline(buf) == TRUE)
    {
        buf[3] = '\0';
       *p_line = ft_strdup(buf);//new
       arr = strdup(sdasdas);
       return (1);
    }
    else
    {
        buf[3] = '\0';
        save = ft_strdup(buf);//
    }
}