#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#define fifo1 "myfifo1"

int main(int argc, char** argv){
    if (mkfifo(fifo1, 0777) == -1){
        if (errno != EEXIST){
            printf("Fifo1 create error.\n");
            return -1;
        }
    }
    int f1f2;
    f1f2 = open(fifo1, O_WRONLY);
    
    while(1){
        char s[100];
        printf("s = "); fgets(s, sizeof(s), stdin); printf("\n");
        s[strlen(s)-1] = '\0';
        int size = strlen(s);
        write(f1f2, &size, sizeof(int));
        write(f1f2, s, size * sizeof(char));
        printf("A sent to B %s of length %d.\n", s, size);
        if(strcmp(s, "stop") == 0){
            break;
        }
    }
    close(f1f2);
    unlink(fifo1);
    return 0;
} 
