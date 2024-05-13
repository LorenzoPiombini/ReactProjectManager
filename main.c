#include <stdlib.h>
#include <stdio.h>
#include "os_detection.h"
#include "jsfiletmplt.h"

int isNode(){
	if( system("node -v > /dev/null 2>&1") == 0){
           	printf("\033[0;32m");
		printf("Node.js is installed.\n");
		printf("\033[0m");
		fflush(stdout);
		return 1;
	}else{
		printf("Node.js is not installed.\n");
		return 0;
	}
}



int main(){

	char buffer[250];
        char fileName[200];

	if(!isNode()){
        	printf("install Node before start working with React.");
        }

	checkOS();//from os_detection.h

	printf("\nenter name of the file: ");
	scanf("%s", fileName);

	screen(fileName,buffer); // from jsfiletmplt.h

	return 0;
}
