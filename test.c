//
// Created by a on 6/17/20.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int testCpp2c(char* type){

	char path[25];
    char* gcc[] = {"gcc", "-ansi", "-pedantic", "-o", "outc", "", "", NULL};
	char* outc[] = {"./outc", ">", "out_c.txt", NULL};
	char* gpp[] = {"g++", "-ansi", "-pedantic", "-o", "outcpp", "", "", NULL};
	char* outcpp[] = {"./outcpp", ">", "out_cpp.txt", NULL};
	char* diff[] = {"diff", "out_c.txt", "out_cpp.txt", NULL};
	char** commands[] = {gcc, outc, gpp, outcpp};
	int status;
	int commandsLen = 5;

	path[0] = '\0';
	gcc[5] = strcat(strcat(strcat(strcat(path, type), "/c/cpp2c_"), type), ".c");
	path[0] = '\0';
	gcc[6] = strcat(strcat(strcat(strcat(path, type), "/c/cpp2c_"), type), "_defs.c");
	path[0] = '\0';
	gpp[5] = strcat(strcat(strcat(strcat(path, type), "/cpp/cpp2c_"), type), ".cpp");
	path[0] = '\0';
	gpp[6] = strcat(strcat(strcat(strcat(path, type), "/cpp/cpp2c_"), type), "_defs.cpp");

	for(int i = 0; i < commandsLen; ++i){
		pid_t pid = fork();

		if(-1 == pid){
			printf("error\n");
			exit(-1);
		}
		if(0 == pid){
			execvp(commands[i][0], commands[i]);
		}
		else{
			waitpid(pid, &status, 0);
		}

	}
	return 0;
}

int testPolymorphism(){
	return testCpp2c("polymorphism");
}

int testInheritance(){
	return testCpp2c("inheritance");
}

int testEncapsulation(){
	return testCpp2c("encapsulation");
}


int main(){

	printf("%d\n", testPolymorphism());
	printf("%d\n", testInheritance());
	printf("%d\n", testEncapsulation());

}
