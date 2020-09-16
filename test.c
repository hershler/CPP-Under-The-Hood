#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>


int testCpp2c(char* type){

	char gcc5[100], gcc6[100], gpp5[100], gpp6[100];
	char* touch[] = {"touch", "outc.txt", "outcpp.txt", NULL};
    	char* gcc[] = {"gcc", "-ansi", "-pedantic", "-o", "outc", "", "", NULL};
	char* outc[] = {"./outc", "outc.txt", NULL};
	char* gpp[] = {"g++", "-ansi", "-pedantic", "-o", "outcpp", "", "", NULL};
	char* outcpp[] = {"./outcpp", "outcpp.txt", NULL};
	char* diff[] = {"diff", "outc.txt", "outcpp.txt", NULL};
	char* rm[] = {"rm", "outc.txt", "outcpp.txt", "outc", "outcpp", NULL};
	char** commands[] = {touch, gcc, outc, gpp, outcpp, diff, rm};
	int status;
	int commandsLen = 7;

	gcc5[0] = '\0';
	gcc[5] = strcat(strcat(strcat(strcat(gcc5, type), "/c/cpp2c_"), type), ".c");
	gcc6[0] = '\0';
	gcc[6] = strcat(strcat(strcat(strcat(gcc6, type), "/c/cpp2c_"), type), "_defs.c");
	gpp5[0] = '\0';
	gpp[5] = strcat(strcat(strcat(strcat(gpp5, type), "/cpp/cpp2c_"), type), ".cpp");
	gpp6[0] = '\0';
	gpp[6] = strcat(strcat(strcat(strcat(gpp6, type), "/cpp/cpp2c_"), type), "_defs.cpp");

	for(int i = 0; i < commandsLen; ++i){

		pid_t pid = fork();

		if(-1 == pid){
			printf("error\n");
			exit(-1);
		}
		if(0 == pid){
			if(commands[i] != outc && commands[i] != outcpp){
				execvp(commands[i][0], commands[i]);
			}
			else{
				int fd;

				if((fd = open(commands[i][0] == "./outc"? "outc.txt": "outcpp.txt", O_RDWR | O_CREAT))==-1){
				  perror("open");
				  return 1;
				}

				dup2(fd,STDOUT_FILENO);
				dup2(fd,STDERR_FILENO);
				close(fd);
				execvp(commands[i][0], commands[i]);
			}
		}
		else{
			waitpid(pid, &status, 0);
		}

	}
	return 0;
}

int testPolymorphism(){

	printf("\n\n\t\t\tWe are testing the polymorphism\n\
			Now you'll see all differences (should be nothing...) cpp program vs c program\n\
			If you see warnings just ignore them, it's under the hood, don't worry... ;)\n\n\n");
	if(testCpp2c("polymorphism")){
		printf("oops something got wrong\n");
	}
}

int testInheritance(){

	printf("\n\n\t\t\tWe are testing the inheritane\n\
			Now you'll see all differences (should be nothing...) cpp program vs c program\n\
			If you see warnings just ignore them, it's under the hood, don't worry... ;)\n\n\n");
	if(testCpp2c("inheritance")){
		printf("oops something got wrong\n");
	}
}

void testEncapsulation(){

	printf("\n\n\t\t\tWe are testing the encapsulation\n\
			Now you'll see all differences (should be nothing...) cpp program vs c program\n\
			If you see warnings just ignore them, it's under the hood, don't worry... ;)\n\n\n");
	if(testCpp2c("encapsulation")){
		printf("oops something got wrong\n");
	}
}


int main(){

	testPolymorphism();
	testInheritance();
	testEncapsulation();
	return 0;
}
