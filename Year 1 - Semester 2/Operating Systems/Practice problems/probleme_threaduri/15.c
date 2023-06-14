#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

typedef struct {
    int nrLetters;
    int nrDigits;
    int nrSpecialCharacters;
} Occurences;

pthread_barrier_t barrier;

void *routine(void* arg){
    char* str = (char *)arg;
    Occurences *res = malloc(sizeof(Occurences));
    res->nrLetters = 0; 
    res->nrDigits = 0;
    res->nrSpecialCharacters = 0;
    for(int i = 0; i < strlen(str); i++){
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')){
           res->nrLetters++;
        }
        else if(str[i] >= '1' && str[i] <= '9'){
            res->nrDigits++;
        }    
        else{
            res->nrSpecialCharacters++;
        }
    }
    pthread_barrier_wait(&barrier);
    return (void *)res;
}

int main(int argc, char **argv){
    if (argc < 2){
        printf("At least 1 command line argument is requiered.\n");
        return -1;
    }
    
    pthread_barrier_init(&barrier, NULL, argc - 1);
    pthread_t th[argc - 1];
    for(int i = 1; i < argc; i++){
        pthread_create(&th[i - 1], NULL, &routine, argv[i]); 
    }    
    
    Occurences* res[argc - 1];
    for(int i = 1; i < argc; i++){
        pthread_join(th[i - 1], (void **)& res[i - 1]);
    }
    
    int totalLetters = 0, totalDigits = 0; 
    int totalSpecialCharacters = 0;
    for(int i = 1; i < argc; i++){
        totalLetters += res[i - 1]->nrLetters;
        totalDigits += res[i - 1]->nrDigits;
        totalSpecialCharacters += res[i - 1]->nrSpecialCharacters;
        free(res[i - 1]);
    }
    pthread_barrier_destroy(&barrier);
    printf("Total letters: %d.\nTotal digits: %d.\nTotal special charcters: %d.\n", totalLetters, totalDigits, totalSpecialCharacters);

    return 0;
}
