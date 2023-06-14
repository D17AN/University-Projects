#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
void handleSIGUSR1(int sig){
    printf("(Hint) The number is the first prime number!\n");
}
int main(int argc, char** argv){
    int id;
    if((id = fork()) == -1){
        printf("Something wrong happend with fork 1.\n");
        return -1;
    }
    
    if(id != 0){
        //Process A - PARENT
        struct sigaction sa;
        sa.sa_handler = &handleSIGUSR1; 
        sa.sa_flags = SA_RESTART;
        sigaction(SIGUSR1, &sa, NULL);
        
        int n;
        printf("Enter number:\n");scanf("%d", &n);printf("\n"); 
        if(n == 2)
            printf("Right.\n");
        else
            printf("Wrong.\n");
        while(wait(NULL) != -1);
    }
    else{
        //Process B - CHILD
        sleep(5);
        kill(getppid(), SIGUSR1);
    }
    return 0;
}
