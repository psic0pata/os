#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
void main(){
	int id, childid;
	id = getpid();
	if((childid = fork()) > 0){
		printf("I am in the Parent Process : %d\n", id);
		printf("I am in the Parent Process : %d\n", getpid());
		printf("I am in the Parent Process : %d\n", getppid());
	}
	else{
		printf("\nI am in the Child Process : %d\n", id);
		printf("I am in the Child Process : %d\n", getpid());
		printf("I am in the Child Process : %d\n", getppid());
	}
}
