#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
typedef struct {
    int* data;
    int curr_index;
    int n;
}Vector;

pthread_mutex_t mutex;
int turn = 1;
void* routine1(void* arg){
    //even routine
    Vector* a = (Vector *)arg;
   
    while(a->curr_index < a->n){
        int val = random() % 1000;
        if (val % 2 == 1){
            val++;
        }
        pthread_mutex_lock(&mutex);
        if (turn == 1){
            a->data[a->curr_index++] = val;
            turn = 2;
        }
        pthread_mutex_unlock(&mutex);
    }
    
    return NULL;
}

void* routine2(void *arg){
    //odd routine
    Vector* a = (Vector *)arg;
    
    while(a->curr_index < a->n){
        int val = random() % 1000;
        if (val % 2 == 0){
            val++;
        }
        pthread_mutex_lock(&mutex);
        if (turn == 2){
            a->data[a->curr_index++] = val;
            turn = 1;
        }
        pthread_mutex_unlock(&mutex);
    }
    
    return NULL;
}

int main(int argc, char** argv){
    int n;
    printf("Enter n: "); scanf("%d", &n); printf("\n");
    int arr[n];
    Vector a;
    a.data = arr;
    a.curr_index = 0;
    a.n = n;
    
    pthread_mutex_init(&mutex, NULL);
    pthread_t th1, th2;
    pthread_create(&th1, NULL, &routine1, (void *)&a);
    pthread_create(&th2, NULL, &routine2, (void *)&a);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    pthread_mutex_destroy(&mutex);
    
    for (int i = 0; i < a.n; i++){
        printf("v[%d] = %d\n", i, a.data[i]);
    }
    
    return 0;
}
