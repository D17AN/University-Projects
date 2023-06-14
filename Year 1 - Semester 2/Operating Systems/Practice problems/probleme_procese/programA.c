#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include <fcntl.h>
int main(int argc, char** argv){
    printf("Hey, I'm A.\n");
    if(mkfifo("myfifo1", 0770) == -1){
        if(errno != EEXIST){
            printf("Something wrong went with the creation of the FIFO.\n");
         }
    }
    int fd = open("myfifo1", O_WRONLY);
    int isRunning = 1;
   
    while(isRunning){
        char txt[100];
        printf("Text: "); scanf("%s", txt); printf("\n");
        int nr = strlen(txt);
        write(fd, &nr, sizeof(int));
        write(fd, &txt, sizeof(char) * strlen(txt));
        if(strcmp(txt, "stop") == 0)
            isRunning = 0;
    }
    close(fd);
    return 0;
}
