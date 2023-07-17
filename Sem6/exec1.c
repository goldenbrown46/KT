#include <stdio.h>
#include <unistd.h>

int main() {
  printf("This is called by exec()\n");

  int pid = getpid();
  printf("%d\n", pid);
  return 0;
}