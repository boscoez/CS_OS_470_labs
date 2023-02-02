#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(void) {
	for(int i = 0; i <= 200; i++) {
	pid_t pid = fork();
		if(pid == 0) {
			printf("\nI am the child process PID = %d , PPID = %d \t\n", getpid(), getppid());
			printf("Interupt, process active in 'CRITICAL REGION'...\n");
			exit(0);
		} else {
			printf("I am the parent process PPID = %d, PID = %d \n", getppid(), getpid());	
			wait(NULL);
		}}
	printf("\nEnd of the program.\n");
	return EXIT_SUCCESS;
}
