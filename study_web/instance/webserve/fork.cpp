# include <iostream>
# include <map>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
#include <fcntl.h>

std::string cgi_process()
{
    std::string ret;
    char    *argv[3];
    int     pip[2];
    argv[0] = _info.url_abs_path;
    argv[1] = _info.cgi_path.c_str();
    //argv[0] = "";
    //argv[1] = _info.url_abs_path;
    argv[0] = strdup("/bin/ls");
    argv[1] = NULL;
    argv[2] = NULL;
    char **env = ft::env("length", _info.extention, _info.url_abs_path, _info.query,\
    		_info.method,_info.host, std::to_string(_info.port), _info.version).get_env();
    int nbytes;
    char inbuf[200];
    if (pipe(pip) != 0)
    {   
        std::cout << "pipe() error" << std::endl; 
        return 0;
    }
    pid_t pid = fork();
    if (pid == 0) 
    {
        dup2(pip[1], 1);
        close(pip[0]);
        close(pip[1]);
        if (-1 == execve(argv[0], argv, env))
            std::cout << "execve error" << std::endl;
        exit(-1);
    }
    else if (pid > 0) 
    {
        int status;
        close(pip[1]);
        while ((nbytes = read(pip[0], inbuf, 199)) != 0)
        {
            inbuf[nbytes] = 0;
            ret += inbuf;
        }
        close(pip[0]);
        waitpid(pid, &status, 0);
    }
    else
    {
        std::cout << "fork error " << std::endl;
        exit (1);
    }
    /*free(argv[0]);
    free(argv[1]);
    for (int i = 0; i < 18; i++)
        free(env[i]);*/
    std::string::size_type idx = 0;
    while (idx < ret.size())
    {
        idx = ret.find_first_of("\n", idx);
        if (ret[idx + 1] == '\n')
        {
            ret.erase(0, idx + 2);
            break;
        }
        idx++;
    }
    std::cout << ret << std::endl;
    return ret;
}

int main()
{
    cgi_process();
    //std::cout << cgi_process() << std::endl;;
}