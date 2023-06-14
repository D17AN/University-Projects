#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv){
    int p1p2[2], p2p1[2];
    if (pipe(p1p2) == -1){
        printf("p1p2 pipe create error.\n");
        return -1;
    }
    if (pipe(p2p1) == -1){
        printf("p2p1 pipe create error.\n");
        return -1;
    }
    int id = fork();
    if (id == -1){   
        printf("Fork create error.\n");
        return -1;
    }

    if (id == 0){
        //child process - process B
        close(p1p2[1]);
        close(p2p1[0]);
        int val;
        while(1){
            read(p1p2[0], &val, sizeof(int));
            printf("B got %d from A.\n", val);
            val /= 2;
            write(p2p1[1], &val, sizeof(int));
            printf("B sent %d to A.\n", val);
            if (val < 5)
                break;            
        }
    }
    else{
        //parent process - process A
        close(p1p2[0]);
        close(p2p1[1]);
        srandom(getpid());
        int val = random() % 151 + 50;
        printf("Process A generated %d.\n", val);
        while(1){
            if(val % 2 == 0){
                write(p1p2[1], &val, sizeof(int));
                printf("A sent %d to B.\n", val);
            }
            else{
                val++;
                write(p1p2[1], &val, sizeof(int));
                printf("A incremented %d, sent %d to B.\n", val - 1, val); 
            }
            read(p2p1[0], &val, sizeof(int));
            printf("A got %d from B.\n", val);
            
            if(val < 5){
                break;
            }
        } 
    }
    return 0;
}
