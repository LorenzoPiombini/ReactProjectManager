#ifndef _INPUT_CHECKS_H
#define _INPUT_CHECKS_H

#include "commands.h"
#include <stdlib.h>
#include <errno.h>

int endsWithSlash(char* path){
	int len = strlen(path);
	if(len > 0 && path[len - 1] == '/'){
		return 1;
	}
	
	return 0;
}

void addSlash(char* path){
	int len = strlen(path);
        path[len] = '/';
        path[len + 1] = '\0';
}


int isPathValid(char *path){
     size_t l = strlen(path) + strlen(CD) + strlen(NO_OUTPUT) + 1;
     char *result = (char *)malloc(l * sizeof(char));
     
	if( result == NULL){
          printf("Failed to allocate memory");
          return 0;
        }
     
     result[0]='\0';
     strcpy(result,CD);
     strcat(result,path);
     strcat(result,NO_OUTPUT);
    
     int valid = system(result) == 0; 
     free(result);
     return valid;
}

char* check_real_length_from_input(){
	char temp[600];
        
	clearerr(stdin);
       
        if(fgets(temp, sizeof(temp), stdin) == NULL){
	 	if (feof(stdin)) {
            fprintf(stderr, "EOF encountered\n");
        } else if (ferror(stdin)) {
            fprintf(stderr, "Error reading input: %s\n", strerror(errno));
        } else {
            fprintf(stderr, "Unknown error reading input\n");
        }
		return NULL;
	}

	//remove new line char '\n'
	temp[strcspn(temp, "\n")] = '\0';
	
	if (strlen(temp) == 0) {
        	return NULL;
    	}       
 
	size_t len = strlen(temp) + 1;
       
        char *dynamicInput = (char *)malloc(len  * sizeof(char));
	if (dynamicInput == NULL ){
		fprintf(stderr, "Memory allocation failed.");
      		return NULL;
	}
	
	strcpy(dynamicInput, temp);
        
	return dynamicInput;
}

#endif
