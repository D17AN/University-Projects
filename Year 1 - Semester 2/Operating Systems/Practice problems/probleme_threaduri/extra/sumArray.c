#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;
int sum = 0;
int n;
int v[100];
typedef struct{
    int start, end;
}Range;

void* routine(void* arg){
    Range range = *(Range *)arg;
    for(int i = range.start; i < range.end; i++){
        pthread_mutex_lock(&mutex);
        sum += v[i];
        printf("%d was added to sum.\n", v[i]);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(int argc, char **argv){
    pthread_t t1, t2;
    pthread_mutex_init(&mutex, NULL);
    
    printf("n: "); scanf("%d", &n); printf("\n");
    for(int i = 0; i < n; i++){
        printf("v[%d]: ", i); scanf("%d", &v[i]); printf("\n");
    }
    
    Range range1;
    range1.start = 0; range1.end = n / 2;
    Range range2;
    range2.start = n / 2; range2.end = n;

    if (pthread_create(&t1, NULL, &routine, &range1)){
        printf("Something went wrong when creating t1.\n");
        return -1;
    }
    
    if (pthread_create(&t2, NULL, &routine, &range2)){
        printf("Something went wrong when creating t2.\n");
        return -1;
    }
    
    if (pthread_join(t1, NULL)){
        printf("Something went wrong when executing t1.\n");
        return -1;
    }
    
    if (pthread_join(t2, NULL)){
        printf("Something went wrong when executing the t2.\n");
        return -1;
    }    
    
    pthread_mutex_destroy(&mutex);
    printf("Sum is %d.\n", sum);
    return 0;
}

