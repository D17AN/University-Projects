#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define FILE_NAME "matrix.txt"

int sum = 0;
pthread_mutex_t mutex;

typedef struct {
    int* v;
    int size;
}Array;

void *routine(void *arg){
    Array arr = *(Array *)arg;
    int* partial_sum = malloc(sizeof(int));
    *partial_sum = 0;
    for(int i = 0; i < arr.size; i++){
        *partial_sum += arr.v[i];
    }
    pthread_mutex_lock(&mutex);
    sum += *partial_sum;
    pthread_mutex_unlock(&mutex);
    return (void *)partial_sum;
}
int main(int argc, char** argv){
    int n, m;
    FILE* fd = fopen(FILE_NAME, "r");
    if (fd == NULL){
        printf("The file couldn't be opened.\n");
        return -1;
    }
    fscanf(fd, "%d %d", &n, &m);
    printf("n = %d and m = %d.\n", n, m);
    int matrix[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            fscanf(fd, "%d", &matrix[i][j]);
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    fclose(fd);
    
    pthread_mutex_init(&mutex, NULL);

    Array *arr[n];
    pthread_t th[n];
    for(int i = 0; i < n; i++){
        arr[i] = malloc(sizeof(Array));
        arr[i]->v = matrix[i];
        arr[i]->size = m;
        pthread_create(&th[i], NULL, &routine, (void *)arr[i]);
    }
    
    int* res[n]; 
    for(int i = 0; i < n; i++){
        pthread_join(th[i], (void **)&res[i]);
    }
    
    for(int i = 0; i < n; i++){
        printf("Partial sum of row %d is %d.\n", i, *res[i]);
        free(arr[i]);
        free(res[i]);
    }
    printf("Sum of the matrix is %d.\n", sum);
    pthread_mutex_destroy(&mutex);
    return 0;

}
