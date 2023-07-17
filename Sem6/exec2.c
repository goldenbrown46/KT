#include <stdio.h>
#include <unistd.h>

int main() {  
  char* arg[] = {"./exec1", NULL};
  execvp(arg[0], arg);

  printf("Hello there\n");

  return 0;
}