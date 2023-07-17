#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  pid_t pid;
  pid = fork();

  if (pid == 0) {
    //int pid = getpid();
    //printf("%d\n", pid);

    char* arg[] = {"./exec1", NULL};
    execvp(arg[0], arg);

  } else {
    wait(NULL);
    printf("This is parent process\n");

    int pid = getpid();
    printf("%d\n", pid);
  }

  return 0;
}