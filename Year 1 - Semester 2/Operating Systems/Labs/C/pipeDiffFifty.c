/*
Write a C program (we'll refer to it as A) that creates a child process B.
Process B generates one random number N between 100 and 1000.
Process A keeps generating and sending random numbers between 50 and 1050 to B until the absolute 
difference between the number generated by A and the number generated by B is less than 50. 
B prints the generated numbers and all the received numbers. 
A will print at the end the number of numbers generated until the stop condition was met.
*/
#include <stdio.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

int main (int argc, char **argv)
{
    signal(SIGCHLD, SIG_IGN);    
    int a2b[2], b2a[2];
    pipe(a2b);
    pipe(b2a);
    if (fork() == 0){
	//B
	close(a2b[1]);
	close(b2a[0]);
	srand(time(NULL)^getpid());
	int nr;
	nr = rand()%901+100;
	int guess;
	int flag = 0;
	printf("Process B has generated: %d.\n", nr);
	while (read(a2b[0], &guess, sizeof(int)) > 0){
	    int diff = abs(nr-guess);
	    printf("B received %d. Difference is %d.\n", guess, diff);
	    if (diff < 50)
		break;
	    write(b2a[1], &flag, sizeof(int));
	}
	close(a2b[0]);
	flag = 1;
	write(b2a[1], &flag, sizeof(int));
	close(b2a[1]);
	exit(0);
    }
    //A
    close(a2b[0]);
    close(b2a[1]);
    int guess, cnt = 0;
    srand(time(NULL)^getpid());
    while (1){
	guess = rand()%1001+50;
	if (write(a2b[1], &guess, sizeof(int)) <= 0)
	    break;
	++cnt;
	int flag;
	read(b2a[0], &flag, sizeof(int));
	if (flag == 1)
	    break;
    }
    close(a2b[1]);
    close(b2a[0]);
    printf("A has generated %d dudes.\n", cnt);
    return 0;
}

