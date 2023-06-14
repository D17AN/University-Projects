#include <sys/types.h>
#include <sys/stat.h>                                             
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define fifo1 "myfifo1"
#define fifo2 "myfifo2"

int main(int argc, char** argv){
    if(argc < 2){
        printf("At least 1 command argument is requiered!\n");
        return -1;
    }
    
    if (mkfifo(fifo1, 0777) == -1){
        if (errno != EEXIST){
            printf("f1f2 create fifo error.\n");
            return -1;
         }
    }
    
    if (mkfifo(fifo2, 0770) == -1){
        if (errno != EEXIST){
            printf("f2f1 create fifo error.\n");
            return -1;
        }
    }
    
    int f1f2 = open(fifo1, O_WRONLY);
    int f2f1 = open(fifo2, O_RDONLY);
    int nr = argc - 1;
    int nrChars = 0;
    write(f1f2, &nr, sizeof(int));
    printf("A will send to B %d arguments.\n", nr);
    for(int i = 1; i < argc; i++){
        nr = strlen(argv[i]);
        nrChars += nr;
        write(f1f2, &nr, sizeof(int));
        write(f1f2, argv[i], nr * sizeof(char));
        printf("A sent to B %s.\n", argv[i]);
    }    
    close(f1f2);
    
    int n;
    read(f2f1, &n, sizeof(int));
    char s[nrChars + 1]; 
    for(int i = 0; i < n; i++){
        read(f2f1, &nr, sizeof(int));//read nr chars of string
        char aux[nr+1];
        read(f2f1, aux, nr * sizeof(char));
        aux[nr] = '\0';
        printf("A got %s from B.\n", aux);
        strcat(s, aux);
    }
    close(f2f1);
    printf("%s\n", s);
    unlink(fifo1);
    unlink(fifo2); 
}
