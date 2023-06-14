#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define file_name "matrix.txt"

typedef struct{
    int* v;
    int size;
}Array;

void* routine(void* arg){
    Array a = *(Array *)arg;
    int* sum = malloc(sizeof(int));
    *sum = 0;
    for(int i = 0; i < a.size; i++){
        *sum = *sum + a.v[i];
    }
    
    return (void *)sum;
}

int main(int argc, char **argv){
    int n = 1, m = 1;
    FILE *fd = fopen(file_name, "r");
    if (fd == NULL){
        printf("Error opening the file.\n");
        return -1;
    }

    fscanf(fd, "%d", &n);
    fscanf(fd, "%d", &m);
    printf("n: %d.\nm: %d.\n", n, m);
    int matrix[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            fscanf(fd, "%d", &matrix[i][j]);
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    fclose(fd); 
    
    pthread_t t[n];
    Array *arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = malloc(sizeof(Array));
        arr[i]->v = matrix[i];
        arr[i]->size = m;
        pthread_create(&t[i], NULL, &routine, (void *)arr[i]);
    }    
    
    int *res[n];
    for (int i = 0; i < n; i++){
        pthread_join(t[i], (void**)& res[i]);
    }

   
    for(int i = 0; i < n; i++){
        printf("Sum on row %d is %d.\n", i, *res[i]);
        free(res[i]);
        free(arr[i]);
     }
    return 0;
}

