//Francisco Javier Romo Juárez
//A01643189
//13/10/2023

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
	pid_t pd;
	char cwd[1024];
	getcwd(cwd,sizeof(cwd));
	int exit = 0;
	while (exit != 1){
		char *arg[256];
		char instruction[256];
		int counter = 0;

		printf("->cdm JavierRomo: ");

		fgets(instruction,256,stdin);
		instruction[strlen(instruction)-1] = '\0';
		char *token = strtok(instruction," ");

		while (token != NULL){
			arg[counter] = token;
			counter++;
			token = strtok(NULL," ");
		}

		arg[counter] = NULL;

		if (strcmp(arg[0], "exit") == 0){
			return 0;
		}

		pd = fork();

       		if (pd == 0) {
          		execvp(arg[0], arg);
       		}

		else{
			wait(NULL);
       		}
	}
	return 0;

}

