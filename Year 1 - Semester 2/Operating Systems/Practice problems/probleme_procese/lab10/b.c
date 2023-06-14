#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <unistd.h>
int main(int argc, char** argv){
    int a, b;
    int a2b, b2a;
    if((a2b = open("a2b", O_RDONLY)) <= 0){
        printf("a2b couldn't be open\n");
        return -1;
    }
    
    if((b2a = open("b2a", O_WRONLY)) <= 0){
        printf("b2a couldn't be open\n");
        return -1;
    }

    while(1){
        read(a2b, &a, sizeof(int));
        read(a2b, &b, sizeof(int));
        printf("a: %d\nb: %d\n", a, b);
        
        int sum, prod;
        sum = a + b;
        prod = a * b;
        
        write(b2a, &sum, sizeof(int));
        write(b2a, &prod, sizeof(int));
        if(sum == prod){
            break;
        }       
    }
    close(a2b);
    close(b2a);
    return 0;
}
