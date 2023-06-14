#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
int id;
void handleSIGINT(){
    srand(time(0));
    int rollDice = rand() % 2;
    printf("The dice is %d\n", rollDice);
    if(rollDice == 1){
        printf("You're fate has been decided...\n");
        kill(id, SIGKILL);
    }
    else{
        printf("Seems, you're still surving, but not for much...\n");
    }
}
int main(int argc, char **argv){
    if((id = fork()) == -1){
        printf("Something went wrong with fork 1.\n");
        return -1;
    }
    if(id == 0){
        //Child process
        while(1){
            kill(getppid(), SIGINT);
            sleep(3);
        }
    }
    else{
        signal(SIGINT, &handleSIGINT);
        while(wait(NULL) != -1);
        printf("I killed my child :'(\n");
    }
    return 0;
}
