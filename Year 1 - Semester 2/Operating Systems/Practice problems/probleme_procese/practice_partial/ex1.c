#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char** argv){
    
    int n = 10; // number child processes
    for(int i = 0; i < n; i++){
        int cid;
        if ((cid = fork()) == -1){
            printf("Something bad happend when creating fork %d.\n", i);
            return -1;
        }

        if (cid == 0){
            //child process
            printf("%d: Child process %d with parent id %d.\n", i + 1, getpid(), getppid()); 
        }
        else{
            //parent process
            printf("%d: Parent process %d with child with child id %d.\n", i + 1, getpid(), cid);
            while(wait(NULL) != -1);
            break;
        }
    }
    return 0;
}
