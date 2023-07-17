// Seminar 12

// Напишите программу в которой два процесса общаются между собой через pipe в обе стороны

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int fd1[2];
    int fd2[2];
    char resstring[14];
    size_t size;

    if (pipe(fd1) < 0) {
        printf("Cannot create pipe 1\n");
        exit(-1);
    }
    if (pipe(fd2) < 0) {
        printf("Cannot create pipe 2\n");
        exit(-1);
    }

    pid_t pid;
    pid = fork();

    if (pid < 0) {
        printf("Cannot fork\n");
        exit(-1);
    }

    if (pid == 0) {
        printf("Child is running\n");
        
        close(fd1[1]);
        close(fd2[0]);

        size = write(fd2[1], "This is child", 14);
        if (size != 14) {
            printf("Cannot write all string\n");
            exit(-1);
        }

        close(fd2[1]);

        size = read(fd1[0], resstring, 14);
        if(size < 0){
            printf("Cannot read string\n"); 
            exit(-1); 
        } 
        printf("%s\n",resstring);

        printf("Child exit\n");

        close(fd2[1]);
    } else {
        printf("Parent is running\n");
        
        close(fd1[0]);
        close(fd2[1]);

        size = write(fd1[1], "This is parent", 14);
        if (size != 14) {
            printf("Cannot write all string\n");
            exit(-1);
        }

        close(fd1[1]);

        size = read(fd2[0], resstring, 14);
        if(size < 0){
            printf("Cannot read string\n"); 
            exit(-1); 
        } 
        printf("%s\n",resstring);

        printf("Parent exit\n");

        close(fd1[1]);
    }
    
    return 0;
}
