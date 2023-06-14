#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#define fifo1 "myfifo1"
#define fifo2 "myfifo2"

int main(int argc, char **argv){
    int f1f2 = open(fifo1, O_RDONLY);
    int f2f1 = open(fifo2, O_WRONLY);
    
    int n;
    read(f1f2, &n, sizeof(int));
    printf("B will get %d strings from A.\n", n);
    write(f2f1, &n, sizeof(int));
    printf("B will send %d strings to B.\n", n);
    for(int i = 0; i < n; i++){
        int nrChars;
        read(f1f2, &nrChars, sizeof(int));
        char aux[nrChars+1];
        read(f1f2, aux, nrChars * sizeof(char));
        aux[nrChars] = '\0';
        printf("B got %s with %d chars from A.\n", aux, nrChars);
        for(int i = 0; i < strlen(aux); i++){
            if(aux[i] >= 'a' && aux[i] <= 'z'){
                aux[i] = aux[i] - 32;
            }
        }
        write(f2f1, &nrChars, sizeof(int));
        write(f2f1, aux, nrChars * sizeof(char));
        printf("B sent to A %s with %d chars.\n", aux, nrChars);
    }
    close(f1f2);
    close(f2f1);
    return 0;
}
