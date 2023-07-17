#include <stdio.h>
#include <sys/dir.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>

void ls(const char *dir) {
  DIR* my_dir = opendir(dir);
  if (my_dir == NULL) {
    perror("ERROR");
    exit(1);
  }

  struct dirent* current_dir;
  while((current_dir = readdir(my_dir)) != NULL) {
    if (current_dir->d_name[0] != '.') {
      printf("%s\n", current_dir->d_name);
      //printf("%ld\n", current_dir->d_ino);
    }
  }
}

int main() {
  ls(".");

  return 0;
}