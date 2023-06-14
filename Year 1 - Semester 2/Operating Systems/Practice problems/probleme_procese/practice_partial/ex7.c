#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv){
    int p1p2[2], p2p1[2];

    if (pipe(p1p2) == -1){
        printf("Create pipe p1p2 error.\n");
        return -1;
    }
    if (pipe(p2p1) == -1){
        printf("Create pipe p2p1 error.\n");
        return -1;
    }
    
    int id1 = fork();
    if (id1 != 0){
        //parent process//main program
        int id2 = fork();
        if (id2 != 0){
            //parent process//main program
            while (wait(NULL) != -1);
        }
        else{
            //process B //child 2 process
            close(p1p2[1]);
            close(p2p1[0]);
            srandom(getpid());
            while (1){
                int val1 = random() % 10 + 1;
                write(p2p1[1], &val1, sizeof(int));
                printf("Process B sent %d to A.\n", val1);
                int val2;
                read(p1p2[0], &val2, sizeof(int));
                printf("Process B got %d from A.\n", val2);
                if(val1 == 10 || val2 == 10){
                    break;
                }
            }
            close(p1p2[0]);
            close(p2p1[1]);
            exit(0);
        }
        while (wait(NULL) != -1); //wait processes to terminate
    }
    else{
        //process A//child 1 process
        close(p1p2[0]);
        close(p2p1[1]);
        srandom(getpid());
        while (1){
            int val1 = random() % 10 + 1;
            write(p1p2[1], &val1, sizeof(int));
            printf("Process A sent %d to B.\n", val1);
            int val2;
            sleep(1);
            read(p2p1[0], &val2, sizeof(int));
            printf("Process A received %d from B.\n", val2);
            if (val1 == 10 || val2 == 10){
                break;    
            }
        }
        close(p1p2[1]);
        close(p2p1[0]);
        exit(0);
    }
    return 0;
}

