#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define N 5
int main(int argc, char** argv){
    int pipes[N][2];
    for(int i = 0; i < N; i++){
       if(pipe(pipes[i]) == -1){
            printf("Something wrong went with pipe %d\n", (i+1));
            return -1;
        }
    }
    
    int pid[N];
    pid[0] = getpid();
    for(int i = 1; i < N; i++){
        if((pid[i] = fork()) == -1){
            printf("Something wrong happend with %d fork.\n", i);
            return -1;
        }
        if(pid[i] == 0){ 
            for(int j = 0; j < N; j++){
                if(i != j)
                    close(pipes[j][1]);
                if(i - 1 != j)
                    close(pipes[j][0]);
            }
            int x;
            read(pipes[i-1][0], &x, sizeof(int));
            printf("(%d) got %d\n", getpid(), x);
            x++;
            write(pipes[i][1], &x, sizeof(int));
            return 0;
        }
    }
    int x = 5;
    int i = 0;
    for(int j = 0; j < N; j++){
        if(i != j)
            close(pipes[j][1]);
        if(j != N - 1)
            close(pipes[j][0]);
    }
    write(pipes[0][1], &x, sizeof(int));
    while(wait(NULL) != -1);
    read(pipes[N-1][0], &x, sizeof(int));
    printf("(%d)The value of x is %d\n", getpid(), x);    
    
    return 0;
}
