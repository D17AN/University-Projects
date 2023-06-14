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
    int f2f1 = open(fifo1, O_RDONLY);
    while(1){
        int size;
        read(f2f1, &size, sizeof(int));
        char s[size + 1];
        read(f2f1, s, size * sizeof(char));
        s[size] = '\0';
        printf("B got %s from A.\n", s);
        if(strcmp(s, "stop") == 0){
            break;
        }
    }
    close(f2f1);
    return 0;
}
