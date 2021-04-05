#include "main.h"

int main(int argc, char *arv[])
{
    char inputstring[100], *parsed[10];
    char *parsed_pipe[10];

    init_shell();
    exec_flag;//초기화 필요없지 않나?
    while (1)
    {
        put_prompt();
        if (get_command(inputstring))
            continue;
        exec_flag = parse_string(inputstring, parse, parsed_pipe)
        
        if (exec_flag == 0)
            exec_args(parsed);
        else if (exec_flag = 1)
            exec_piped_args(parsed_pipe);
        else
            continue;
    }
    return (0);
)