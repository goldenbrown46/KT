// Семинар 12

// Напишите программу в которой происходит корректное увеличение переменной в несколько потоков

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int a, b, res;

void *mythread(void *dummy)
{
    pthread_t mythid = pthread_self();
    for (int i = 0; i < 10000; i++) {
        b = b + 1;
    }
    printf("Thread %ld, Calculation result = %d\n", mythid, a);
    return NULL;
}

int main()
{
    pthread_t thid, mythid;

    for (int i = 0; i < 10000; i++) {
    int result = pthread_create( &thid, (pthread_attr_t *)NULL, mythread, NULL);
        if(result != 0){
            printf ("Error on thread create, return value = %d\n", result);
            exit(-1);
        }
        printf("Thread created, thid = %ld\n", thid);
        mythid = pthread_self();
        a = a + 1;
        printf("Thread %ld, Calculation result = %d\n", mythid, a);
        pthread_join(thid, (void **)NULL);

        res = a + b;
        printf("%d\n", res);
    }


    return 0;
}