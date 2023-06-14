#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;
long f[10] = {0};

void* routine(void *arg){
    int* val = (int *)arg;
    do{
        pthread_mutex_lock(&mutex);
        f[*val % 10]++;
        pthread_mutex_unlock(&mutex);
        *val /= 10;
    }while(*val != 0);
    free(val);
    return NULL;
}

int main(int argc, char** argv){
    if (argc < 2){
        printf("At least 1 command line argument is required.\n");
        return -1;
    }
    
    pthread_mutex_init(&mutex, NULL);

    pthread_t th[argc - 1];
    for (int i = 1; i < argc; i++){
        int* val = malloc(sizeof(int));
        *val = atoi(argv[i]); 
        pthread_create(&th[i - 1], NULL, &routine, (void *)val);
    }

    for (int i = 1; i < argc; i++){
        pthread_join(th[i - 1], NULL);
    }
    
    for (int i = 0; i < 10; i++){
        printf("Digit %d has %ld occurrences.\n", i, f[i]);
    } 
    pthread_mutex_destroy(&mutex);    
    return 0;
}
