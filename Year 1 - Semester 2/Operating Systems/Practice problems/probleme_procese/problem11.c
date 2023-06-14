#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>
int generateNr(int start, int end){
    sleep(1);
    srand(time(0));
    int n = rand() % end + 1;
    while(n < start){
        n = rand() % end + 1;
    }
    return n;
}

int main(int argc,char** argv){
    int f1f2[2], f2f1[2], id;
    if(pipe(f1f2) == -1){
        printf("Something went wrong when creating pipe 1.\n");
        return -1;
    }
    if(pipe(f2f1) == -1){
        printf("Something went wrong when creating pipe 2.\n");
        return -1;
    }
    if((id = fork()) == -1){
        printf("Something went wrong when creating fork 1.\n");
        return -1;
    }
    if(id != 0){
        //Process A - parent
        close(f1f2[0]);
        close(f2f1[1]);
        int isRunning = 1, i = 0;
        while(isRunning){
            int n = generateNr(50, 1050);
            write(f1f2[1], &n, sizeof(int));
            i++;
            int res;
            read(f2f1[0], &res, sizeof(int));
            if(res < 50){
                isRunning = 0;
            }
        }
        printf("Process A has generated %d numbers.\n", i);
        while(wait(NULL) != -1);
        close(f1f2[1]);
        close(f2f1[0]);
    }
    else{
        close(f1f2[1]);
        close(f2f1[0]);
        int a;
        a = generateNr(100, 1000);
        printf("Process B has generated %d.\n", a);
        int isRunning = 1;
        while(isRunning){
            int b;
            read(f1f2[0], &b, sizeof(int));
            printf("B received %d;", b);
            int diff = abs(a - b);
            printf("difference %d.\n", diff);
            write(f2f1[1], &diff, sizeof(int));
            if(diff < 50){
                isRunning = 0;
            }
            
        }
        close(f1f2[0]);
        close(f2f1[1]);
    }
    return 0;
}
