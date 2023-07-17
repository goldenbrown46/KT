//Seminar 9

//Напишите программу, которая создает очередь сообщений и посылает-принимает сообщения в две стороны.
//Те один из процессов создает очередь, отправляет сообщение и ждет сообщение для себя.
//Второй процесс считывает сообщение, отправляет сообщение первому потоку. Так происходит
//несколько раз, пока не появятся сообщение завершать.

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define LAST_MESSAGE 255

int main()
{
    int msqid;
    char path[] = "msq1.c";
    key_t key;
    int i, len, maxlen;
    struct mymsgbuf
    { 
        long mtype;
        char mtext[81];
    } mybuf;

    if((key = ftok(path,0)) < 0) {
        perror("Cannot generate key\n");
        exit(-1);
    }

    if((msqid = msgget(key, 0666 | IPC_CREAT)) < 0) {
        perror("Cannot get msqid\n");
        exit(-1);
    }

    for (i = 1; i <= 100; i++) {
        mybuf.mtype = 1;
        strcpy(mybuf.mtext, "This is message from msq2");
        len = strlen(mybuf.mtext)+1;

        if (msgsnd(msqid, (struct msbuf *) &mybuf, len, 0) < 0) {
        perror("Cannot send message to queue\n");
        msgctl(msqid, IPC_RMID, (struct msqid_ds *) NULL);
        exit(-1);
        }
        msgrcv(msqid, (struct mybuf *)&mybuf, 81, 2, 0);

        if (mybuf.mtype == LAST_MESSAGE) {
            msgctl(msqid, IPC_RMID, (struct msqid_ds *)NULL);
            exit(0);
        }

        printf("%s(%d times)\n", mybuf.mtext, i);
    }

    mybuf.mtype = LAST_MESSAGE;
    msgsnd(msqid, (struct msbuf *)&mybuf, len, 0);

    return 0;
}