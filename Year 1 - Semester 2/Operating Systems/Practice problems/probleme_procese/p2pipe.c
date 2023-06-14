#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(int argc, char** argv){  
    int id1;
    if((id1 = fork()) == -1){
        printf("Fork call 1 error occured.\n");
        return -1;
    }
    
    if(id1 != 0){
        //parent process
        while(wait(NULL) != -1); // all the childs need to finish
    
    }
    else{
        //child process 1
        int f1f2[2], f2f1[2]; //file descriptors

        if(pipe(f1f2) == -1){
            printf("Pipe 2 creation error occured.\n");
            return -1;
        }
        if(pipe(f2f1) == -1){
            printf("Pipe 2 creation error occured.\n");
            return -1;
        }
        

        int id2;
        if((id2 = fork()) == -1){
            printf("Fork call 2 error occured.\n");
        }

        if(id2 != 0){
            //parent process
            close(f1f2[0]);
            close(f2f1[1]);
            int isRunning = 1, nrSent, nrReceived;
            srand(getpid());
            while(isRunning){
                nrSent = rand() % 11;
                write(f1f2[1], &nrSent, sizeof(int));//sending the number in the pipe
                printf("Process %d sent number %d to process %d.\n", getpid(), nrSent, id2);
                read(f2f1[0], &nrReceived, sizeof(int));//getting the number from the pipe
                printf("Process %d received number %d from process %d.\n", getpid(), nrReceived, id2);
                if(nrSent == 10 || nrReceived == 10){
                    isRunning = 0;
                }    
            }
            wait(NULL);
            close(f1f2[1]);
            close(f2f1[0]);
        }
        else{
            //child process
            close(f1f2[1]);
            close(f2f1[0]); 
            int isRunning = 1, nrSent, nrReceived;
            srand(getpid());
            while(isRunning){
                nrSent = rand() % 11;
                read(f1f2[0], &nrReceived, sizeof(int));//getting the number from the pipe
                printf("Process %d received number %d from process %d.\n", getpid(), nrReceived, getppid());
                write(f2f1[1], &nrSent, sizeof(int));//sending the number in the pipe
                printf("Process %d sent number %d to process %d.\n", getpid(), nrSent, getppid());
                if(nrSent == 10 || nrReceived == 10){
                    isRunning = 0;
                }
            }
            close(f1f2[0]);
            close(f2f1[1]);
        }
    }
    return 0;      
}
