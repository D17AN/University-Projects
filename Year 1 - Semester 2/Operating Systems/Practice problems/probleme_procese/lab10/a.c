#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <unistd.h>
int main(int argc, char** argv){
    int a, b;
    int a2b, b2a;
    
    if((a2b = open("a2b", O_WRONLY)) <= 0){
        printf("a2b couldn't be open\n");
        return -1;
    }
     
    if((b2a = open("b2a", O_RDONLY)) <= 0){
        printf("b2a couldn't be open\n");
        return -1;
    }
    
    while(1){
        printf("a: "); scanf("%d", &a); printf("\n");
        printf("b: "); scanf("%d", &b); printf("\n");

        write(a2b, &a, sizeof(int));
        write(a2b, &b, sizeof(int));

        int sum, prod;

        read(b2a, &sum, sizeof(int));
        read(b2a, &prod, sizeof(int));
        
        printf("Sum is %d and product is %d\n", sum, prod);

        if(sum == prod){
            break;
        }
    }
    close(a2b);
    close(b2a);
    return 0;

}
