#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include <fcntl.h>
int main(int argc, char** argv){
    printf("Hey, I'm B.\n");
    int fd = open("myfifo1", O_RDONLY);
    int isRunning = 1;
    while(isRunning){
        char txt[100];
        int nr;
        read(fd, &nr, sizeof(int));
        read(fd, &txt, nr);
        txt[nr] = '\0';
        printf("Received %d and %s\n", nr, txt);
        if(strcmp(txt, "stop") == 0)
            isRunning = 0;
    }
    close(fd);
    return 0;
}
