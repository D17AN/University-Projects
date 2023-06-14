#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(int argc, char** argv){
    int n = 10; //nr processes
    
    for(int i = 0; i < n; i++){
        int cid = fork();
        if(cid == -1){
            printf("Something bad happend with fork %d.\n", i + 1);
        }
        if(cid == 0){
            //child processes
            printf("%d: Child process %d with parent id %d.\n", i + 1, getpid(), getppid());        
        }
        else{
            //parent process
            printf("%d: Parent process %d with child %d.\n", i + 1, getpid(), cid);
            while(wait(NULL) != -1);
            break;
        }
    }

    return 0;
}
