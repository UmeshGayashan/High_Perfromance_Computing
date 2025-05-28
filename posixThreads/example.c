#include<stdio.h>
#include<pthread.h>

#define THREAD_COUNT 2

void *childThread(void *arg){
    int i;
    for(i = 0; i < 5; i++){
        printf("Child Thread %ld :%d\n", pthread_self(), i);
    }
    return NULL;
}

int main(){
    pthread_t threads[THREAD_COUNT];
    int n;
    printf("Enter the final number: ");
    scanf("%d", &n);

    for(int i = 0; i < THREAD_COUNT; i++){
        if(pthread_create(&threads[i], NULL, childThread, NULL) != 0){
            perror("Failed to create thread");
            return 1;
        }
    }
    for(int i = 0; i < n; i++){
        printf("Parent Thread %d\n", i);
    }

    for(int i = 0; i < THREAD_COUNT; i++){
        if(pthread_join(threads[i], NULL) != 0){
            perror("Failed to join thread");
            return 1;
        }
    }

    printf("All threads completed. There are %d number of threads.\n", THREAD_COUNT);
    printf("Thread IDs: \n\t");
    for(int i = 0; i < THREAD_COUNT; i++){
        printf("%ld \n\t", threads[i]);
    }
    printf("\n");
    return 0;
}