//
// Created by a on 6/17/20.
//
#include "cpp2c_inheritance_defs.h"
#include <string.h>

void get_exe_files(char* files2exe, const char* suffix){

    char* touch[]={"touch", "test.txt", NULL};
    char* ls[]={"ls", ">", "test.txt", NULL};
    char* rm[]={"rm", "test.txt", NULL};

    FILE* files_name;
    int i=0;

    execvp(touch[0], touch);
    execvp(ls[0], ls);

    if(!strcmp(suffix, "c")) {
        files2exe[i++] = "gcc";
    }
    else if(!strcmp(suffix, "cpp")) {
        files2exe[i++] = "g++";
    }
    files2exe[i++] = "-ansi";
    files2exe[i++] = "-pedantic";

    files_name = fopen("test.txt", "r");

    while(1) {
        fscanf(files_name, "%s", files2exe[i]);
        if(files2exe[i][strlen((char*)files2exe[i]) + 1] == EOF){
            break;
        }
        if(!strcmp(suffix, "c") && strlen((char*)files2exe[i]) > 3 && files2exe[i][strlen((char*)files2exe[i]) - 1] == 'c' && files2exe[i][strlen((char*)files2exe[i]) - 2] == '.' && !strcmp(files2exe[i],"test.c")){
            ++i;
        }
        else if(!strcmp(suffix, "cpp") && strlen(files2exe[i]) > 5 && files2exe[i][strlen((char*)files2exe[i]) - 1] == 'p' && files2exe[i][strlen((char*)files2exe[i]) - 2] == 'p' && files2exe[i][(char*)strlen(files2exe[i]) - 3] == 'c'&& files2exe[i][strlen((char*)file2exe[i]) - 4] == '.' ){
            ++i;
        }
    }
    fclose(files_name);
    execvp(rm[0], rm);
    files2exe[i] = NULL;

}

int main(){

    char* files2exe[20];
    char* touch[]={"touch", "c_output.txt", NULL};
    char* rm[]={"rm", "c_output.txt", NULL};
    char* c_output[]={"./a.out", ">", "c_output.txt", NULL};
    char* cpp_output[]={"./a.out", ">", "cpp_output.txt", NULL};


    execvp(touch[0], touch);
    get_exe_files(files2exe, "c");
    execvp(files2exe[0], files2exe);
    execvp(c_output[0], c_output);

    touch[1] = "cpp_output.txt";
    execvp(touch[0], touch);
    get_exe_files(files2exe, "cpp");
    execvp(files2exe[0], files2exe);
    execvp(cpp_output[0], cpp_output);


    /*execvp(rm[0], rm);
    rm[1] = "cpp_output.txt";
    execvp(rm[0], rm);*/

}
