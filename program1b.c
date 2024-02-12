#include <stdio.h>
#include <sys/types.h>
void main(int argc, char *argv[]){
	printf("Before execv\n");
	execv("/bin/ls", argv);
	printf("After execv\n");
}
