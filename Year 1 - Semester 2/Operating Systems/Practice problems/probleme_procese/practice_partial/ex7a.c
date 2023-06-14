#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#define fifo1 "myfifo1"
#define fifo2 "myfifo2"
int main(int argc, char** argv){
    if (mkfifo(fifo1, 0777) == -1){
        if (errno != EEXIST){
            printf("Error creating the fifo1.\n");
            return -1;
        }
    }
    if (mkfifo(fifo2, 0777) == -1){
        if (errno != EEXIST){
            printf("Error creating the fifo2.\n");
            return -1;
        }
    }
    int f1 = open(fifo1, O_WRONLY);
    int f2 = open(fifo2, O_RDONLY);
    srandom(getpid());//set the seed for the random
    while(1){
        int val1 = random() % 10 + 1;
        write(f1, &val1, sizeof(int));
        printf("A sent %d to B.\n", val1);
        
        int val2;
        read(f2, &val2, sizeof(int));
        printf("A got %d from B.\n", val2);
        
        if(val1 == 10 || val2 == 10){
            break;
        }
    }
 
    close(f1);
    close(f2);
    if (unlink(fifo1) == -1){
        printf("Unlink fifo1 error.\n");
    }
    if (unlink(fifo2) == -1){
        printf("Unlink fifo2 error.\n");
    } 
    return 0;
}
