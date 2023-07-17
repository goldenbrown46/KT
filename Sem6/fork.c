#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int add(int a, int b) {
  return a + b;
}

int mult(int a, int b) {
  return a * b;
}

int main() {
  int a, b;
  int res;
  scanf("%d%d", &a, &b);
  
  pid_t pid;
  pid = fork();
  if (pid == 0) {
    res = add(a, b);
  } else {
    wait(NULL);
    res = mult(a, b);
  }

  printf("%d\n", res);

  return 0;
}