#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define fifo1 "myfifo1"
#define fifo2 "myfifo2"
int main(int argc, char** argv){
   int f1, f2;
   f1 = open(fifo1, O_RDONLY);
   f2 = open(fifo2, O_WRONLY);
   srandom(getpid());
   while (1){
        int val2;
        read(f1, &val2, sizeof(int));
        printf("B got %d from A.\n", val2);
        
        int val1 = random() % 10 + 1;
        write(f2, &val1, sizeof(int));
        printf("B sent %d to A.\n", val1);
        if(val1 == 10 || val2 == 10){
            break;
        }
   }
   close(f1);
   close(f2);
   return 0;
}
