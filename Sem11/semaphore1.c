// Семинар 11

// При использовании разделяемой памяти необходимо синхронизировать запись в нее, чтобы не
// возникало коллизий
// Напишите программу, которая создает с помощью семафоров критическую зону вокруг записи
// в разделяемую память
// Необходимо создать массив семафоров, разделяемую память, провести с ними необходимые
// манипуляции и корректно их удалить

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/sem.h>

int main() {
  int *buffer;
  int semid;
  key_t key;
  char path[] = "semaphore1.c";
  struct sembuf mybuf;
  key_t sem_key;

  sem_key = ftok("semaphore2.c", 0);

  if (semid = semget(sem_key, 1, 0666 | IPC_CREAT) < 0) {
    perror("Cannot get semid\n");
    exit(-1);
  }

  mybuf.sem_op = 1;
  mybuf.sem_flg = 0;
  mybuf.sem_num = 0;
  semop(semid, &mybuf, 1);

  if ((key = ftok(path,0)) < 0) {
    perror("Cannot generate key\n");
    exit(-1);
  }
  
  if ((semid = shmget(key, 3*sizeof(int), IPC_CREAT|IPC_EXCL|0666)) < 0) {
    if(errno != EEXIST){
      perror("Cannot create shm\n");
      exit(-1);
    } else {
      if((semid = shmget(key, 3*sizeof(int), 0)) < 0){
        perror("Cannot find shm\n");
        exit(-1);
      }
    }
  }

  if((buffer = (int *)shmat(semid, NULL, 0)) == (int *)(-1)){
    perror("Cannot attach shm\n");
    exit(-1);
  }

  mybuf.sem_op = -1;
  semop(semid, &mybuf, 1);
  printf("Program 1 is running\n");
  printf("%d\n", buffer[0]);
  buffer[0] += 1;

  mybuf.sem_op = 1;
  printf("End program 1\n");
  semop(semid, &mybuf, 1);

  return 0;
}