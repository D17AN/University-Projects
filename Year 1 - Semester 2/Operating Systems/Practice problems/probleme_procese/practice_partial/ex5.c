#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
int containsDigit(int val, int digit){
    do{
        if(val % 10 == digit){
            return 1;
        }
        val /= 10;
    }while(val != 0);
    return 0;
}

int isBoltz(int val){
    return val % 7 == 0 || containsDigit(val, 7) == 1; 
}

int main(int argc, char **argv){
    int n;
    printf("n = "); scanf("%d", &n); printf("\n");
    srandom(getpid());
    int val = random() % 100;
    printf("Boltz game starts with value %d.\n", val);        
    int (*pipes)[2] = malloc(n * sizeof(int [2]));
    for(int i = 0; i < n; i++){
        if(pipe(pipes[i]) == -1){
            printf("Something bad happend when creating pipe %d.\n", i);
        return -1;
        }
    }
    int isRunning[2];
    if(pipe(isRunning) == -1){
        printf("Something bad happend when creating pipe isRunning.\n");
    }
    int run = 1;
    write(isRunning[1], &run, sizeof(int));
    int i = 0;
    write(pipes[n - 1][1], &val, sizeof(int));
    while (run){
        int id = fork();
        if (id == 0){
            close(isRunning[0]);
            for (int j = 0; j < n; j++){
                if (((i - 1 != -1)?i - 1 : n - 1) != j){
                    close(pipes[j][0]);
                }
                if (i != j){
                    close(pipes[j][1]);
                }
            }
            int x;
            read(pipes[(i - 1 != -1)?i - 1 : n - 1][0], &x, sizeof(int));
            printf("Process %d got %d from process %d.\n", i, x, (i - 1 != -1)?i - 1 : n - 1);
            x = x + 1;
            write(pipes[i][1], &x, sizeof(int));
            printf("Process %d sent %d to process %d.\n", i, x, (i + 1) % n);
            if (isBoltz(x)){
                srandom(getpid());
                if(random() % 3 == 0){
                    run = 0;    
                    printf("Failed to print boltz. End Game!\n");
                }
                else{
                    printf("Boltz.\n");
                }
            }
            close(pipes[(i - 1 != -1)?i - 1 : n - 1][0]);
            close(pipes[i][1]);
            free(pipes);
            write(isRunning[1], &run, sizeof(int));
            close(isRunning[1]);
            exit(0);
        }
        else{
            read(isRunning[0], &run, sizeof(int));                            if(run == 0)                                                          break;
            while (wait(NULL) != -1);
        }
        i = (i + 1) % n;
    }
    
    close(isRunning[1]);
    close(isRunning[0]);
    for(int j = 0; j < n; j++){                                           close(pipes[j][0]);                                               close(pipes[j][1]);                                           }  
    free(pipes);
    return 0;
}
