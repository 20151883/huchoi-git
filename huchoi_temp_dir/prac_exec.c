#include "../minishell.h"
#include <stdio.h>

int main(void)
{
    pid_t p1, p2;
    char **args;
    char **args2;
    int status;
    int fd[2];
    pipe(fd);
    
    if (0 == (p1 = fork()))
    {
        args = ft_split("ls -al", ' ');
        close(fd[0]);
        dup2(fd[1], 1);
        //dup2(input ,0);
        close(fd[1]);
        execve("/bin/ls", args, NULL);
    }
    else
    {
        waitpid(p1, &status, 0);
        if (0 == (p2 = fork()))
        {
            args2 = ft_split("grep a", ' ');
            close(fd[1]);
            dup2(fd[0], 0);
            close(fd[0]);
            execve("/usr/bin/grep", args2, NULL);
        }
        else
        {
            close(fd[0]);
            close(fd[1]);
            waitpid(p2, &status, 0);
            ft_putstr_fd("reach!!", 1);
        }
    }
    return (0);
}