#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv){
    if (argc < 2){
        printf("Too few arguments.\n");
        return -1;
    }
    int p1p2[2], p2p1[2];

    if (pipe(p1p2) == -1){
       printf("Create pipe p1p2 error.\n"); 
       return -1;
    }
    if (pipe(p2p1) == -1){
        printf("Create pipe p2p1 error.\n");
        return -1;
    }
    int cid = fork();
    if (cid == -1){
        printf("Create new process error.\n");
        return -1;
    }
    
    if (cid == 0){
        //child process
        close(p1p2[1]);
        close(p2p1[0]);
        int n;
        read(p1p2[0], &n, sizeof(int)); //get nr of values
        printf("Process 2 will receive %d values from process 1.\n", n);
        int sum = 0, val;
        for(int i = 0; i < n; i++){
           read(p1p2[0], &val, sizeof(int));
           printf("Process 2 received %d.\n", val);
           sum += val;
        }
        close(p1p2[0]);
        int average = sum / n;
        write(p2p1[1], &average, sizeof(int));
        printf("Process 2 sent the values average, which is %d.\n", average);
        close(p2p1[1]);
        exit(0);
    }
    else{
        //parent process
        int n = atoi(argv[1]); // get the value
        int val;
        close(p1p2[0]);
        close(p2p1[1]);
        write(p1p2[1], &n, sizeof(int)); //send number of values
        printf("Process 1 is sending %d values to process 2.\n", n);
        srandom(getpid());
        for(int i = 0; i < n; i++){
            val = random() % 100;
            write(p1p2[1], &val, sizeof(int));
            printf("Process 1 sent %d to process 2.\n", val);
        }
        int average;
        close(p1p2[1]);
        read(p2p1[0], &average, sizeof(int));
        printf("The average of the values is %d.\n", average);
        close(p2p1[0]);        
    }
    return 0; 
}
