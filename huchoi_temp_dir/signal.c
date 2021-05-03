#include "../minishell.h"
t_data data; 

void    sigfunc(int signal)
{
    printf("this is parents\n");
}

int main(void)
{
    pid_t p;
    signal(SIGINT, sigfunc);
    //signal(SIGINT, SIG_IGN);
    data.temp = 0;//항상 0으로 초기화되어있어야함.
    if (0 == (p = fork()))
    {
        char **cmd;
        //signal(SIGINT, sigfunc);
        signal(SIGINT, SIG_IGN);
        cmd = ft_split("sleep 10", ' ');
        execve("/bin/sleep", cmd, NULL);
    }
    else
    {
        int status;
        //signal(SIGINT, sigfunc);
        waitpid(p, &status, 0);
        //printf("reach\n");
        if (status == 2)
        {
            if (data.temp == 'I')
            {
                data.status = 130;
                t.temp_status = 0;
            }
        }
        printf("status = %d\n", data.status);
        //printf("reach\n");
        
    }
    return (0);
}