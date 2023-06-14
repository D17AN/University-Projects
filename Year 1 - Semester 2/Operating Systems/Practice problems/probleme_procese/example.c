#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<time.h>
#include<sys/wait.h>
int main(int argc, char** argv){
    int a[] = {1, 2, 3, 4}, f;
    if(mkfifo("bine", 0777) == -1){
        if(errno != EEXIST){
            printf("Something went bad\n");
            return -1;
        }
    }
    int id = fork();
    if(id == 0){
        f = open("bine", O_WRONLY);
        a[0] += a[1];
        write(f, &a[0], sizeof(int));
        printf("Child sends to its parent.\n");
        exit(0);
        close(f);
    }
    else{
        f = open("bine", O_RDONLY);
        a[2]+=a[3];
        read(f, &a[0], sizeof(int));
        a[0]+=a[2];
        printf("suma e %d\n", a[0]);
        while(wait(NULL) != -1);
        close(f);
        
        if(unlink("bine") == -1){
            printf("Something went bad at unlink\n");
            return -1;
        }
 
    }
    return 0;
}
