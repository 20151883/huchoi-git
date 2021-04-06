#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
int global_var = 0;
int main()
{
  pid_t fork_ret, child;
  int local_var = 0;
  int state;
  fork_ret = fork();
  if(fork_ret < 0)
  {
    printf("fork() error\n");
    exit(1);
  }
  else if(fork_ret == 0)
  {
    global_var++;
    local_var++;
    printf(" CHILD - my PID : %d parent's PID : %d \n", getpid(),getppid());
    sleep(10);
  }
  else
  {
    global_var += 5;
    local_var += 5;
    printf("PARENT - my PID : %d child's PID : %d \n", getpid(),fork_ret);
    do
    {
      sleep(3);
      puts("3초 대기");
      child = waitpid(-1, &state, WNOHANG);
    }while(child == 0);
    printf("\t 종료된 자식 프로세스 ID = %d \n", child);
  }
  printf("\t global_var : %d \n", global_var);
  printf("\t local_var : %d \n", local_var);
  return 0;
}