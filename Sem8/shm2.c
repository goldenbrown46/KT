// Семинар 8

// Напишите программу, которая создает область разделяемой памяти, использует ее двумя
// разными процессами и после этого корректно удаляет разделяемую память.



// This program attaches itself to the shared memory and reads the content of the shared memory 

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main()
{
  char *array;
  int shmid;
  char buff[100];
  char path[] = "shm1.c";
  key_t key;

  if((key = ftok(path,0)) < 0){
    perror("Cannot generate key\n");
    exit(-1);
  }

  if((shmid = shmget(key, 3*sizeof(int), 0666|IPC_CREAT|IPC_EXCL)) < 0){
    if(errno != EEXIST){
      perror("Cannot create shared memory\n");
      exit(-1);
    } else {
      if((shmid = shmget(key, 3*sizeof(int), 0)) < 0){
        perror("Cannot find shared memory\n");
        exit(-1);
      }
    }
  }
  if((array = (char *)shmat(shmid, NULL, 0)) == (char *)(-1)){
    perror("Cannot attach shared memory\n");
    exit(-1);
  }

  printf("Data read from shared memory is : %s\n",(char *)array);

  if(shmdt(array) < 0){
    perror("Cannot detach shared memory\n");
    exit(-1);
  }

  return 0;
}