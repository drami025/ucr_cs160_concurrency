#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>


void handler(int sig){
	printf(".");

	alarm(2);
}


int main(int argc, char** argv){

	//signal(SIGALRM, handler);
	//alarm(1);

	if(argv[1] == NULL){
		return;
	}

	printf("hello\n");

	

	while(1){
	
	}

	return 0;
}
