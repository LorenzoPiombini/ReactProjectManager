#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "os_detection.h"
#include "jsfiletmplt.h"
#include "input_checks.h"
#include "macro.h"
#include "express_gen.h"
#include "commands.h"

int isNode(){
	if( system("node -v > /dev/null 2>&1") == 0){
		GREEN_TEXT("\nNode.js is installed.\n");
		return 1;
	}else{
		printf("Node.js is not installed.\n");
		return 0;
	}
}



int main(){
        
	headerWelcome();
	if(!isNode()){
        	printf("install Node before start working with React.");
        }
        
	
        int option = 0;
	
	printf("\nEnter an option(1,2,3): ");
	while(option < 1 || option > 3){	
	scanf("%d",&option);
        getchar();
	}


	switch(option){
	case 1: basicProject();
		break;
	default:
	break;
	}
        
	return 0;
}
