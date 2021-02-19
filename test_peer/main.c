#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    char *line;
    int fd = open("test.txt", O_RDONLY);

    get_next_line(fd, &line);
    printf("%s\n",line);//line = ""

    get_next_line(fd, &line);
    printf("%s\n",line);//new check..
    return (0);
}