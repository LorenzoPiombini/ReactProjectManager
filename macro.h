#ifndef _MACRO_H_
#define _MACRO_H_

#include <stdio.h>
#include <stdlib.h>
#include "commands.h"


#define GREEN_TEXT(text) printf("\033[0;32m%s\033[0m", text);
#define RED_TEXT(text) printf("\033[31m%s\033[0m", text);
#define FACE_WITH_GLASSES \xF0\x9F\x98\x8E\n

void headerWelcome(){
        system("clear");
	printf("\n\t========================= Welcome to React Generation Project ===========================\n");
	printf("\t= select options:	 			     			                =\n");
	printf("\t= 1) basic project  -Simple expo project with organized directories e.i. src/screen     =\n");
	printf("\t= 2) express server -Create a separate folder, complitely wired into your project       =\n");
        printf("\t=    - need Ngrok intalled and a Mongodb profile and db 				=\n");
        printf("\t= 3) project with a sign in and out option already wired in with Express server         =\n");
	printf("\t=    - need Ngrok intalled and a Mongodb profile and db                                 =\n");
	printf("\t= 4) simple screen generator, you provide only the  path and the title.                 =\n");
	printf("\t=========================================================================================\n");
}


void buildTheScreens(char* path){
	int screens = 0;
	char* fileName = NULL;
        

        if(!endsWithSlash(path)){
		addSlash(path);
	}
	
	printf("\nHow many Screens: ");
        scanf("%d", &screens);
        getchar();                                                                                                     

        if(screens ==  1){                                                                                             

                printf("\nenter name of the file: ");                                                                  
                fileName = check_real_length_from_input();
                screen(fileName,path); // from jsfiletmplt.h                                                           
        
        } else if(screens > 1){                                                                                        
                char screenNames[screens][200];                                                                        
                printf("\nEnter %d screens names:\n", screens);                                                        
		
		int i;
                for(i = 0; i < screens; i++){                                                                      
                        printf("\nScreen %d: ", i+1);                                                                  
                        
			fgets(screenNames[i], sizeof(screenNames[i]), stdin);                                          
                        
			//taking the new line cahr out                                                                 
			screenNames[i][strcspn(screenNames[i], "\n")] = '\0';                                                           
                        
			int j;
			for(j = 0; j < screens; j++){                                                                      
                        screen(screenNames[j],path); // from jsfiletmplt.h                                             
                        }                                                                                                      
        	}
      }
}


void generateScreens(){
 	char *path = NULL;

        printf("\nEnter path  of the project: ");
        path = check_real_length_from_input();  
        
        while(path == NULL || !isPathValid(path)){
        printf("\nYou must enter a valid path: ");
        path = check_real_length_from_input();
	}
	
	buildTheScreens(path);

	free(path);
}

void basicProject(){
        char *projectName = NULL;
        char *path = NULL;
        char *basePath = NULL;
        char *fileName = NULL;	


	printf("\nEnter name of the project: ");
        projectName = check_real_length_from_input();

        printf("\nEnter path  of the project: (press enter to use the current directory) ");
        path = check_real_length_from_input();	
        


        //if the user do not provide a path the software set the path from the pwd
	// LNX macro from os_detection.h
	if(path == NULL && (LNX || APL)){
		path = getPwd();
	}
         

	if(!endsWithSlash(path)){
		addSlash(path);
	}
        
        basePath =  createProjectDirectory(path,projectName);
        createProjectStructure(basePath);

	buildTheScreens(basePath);

	free(path);
        free(projectName);
        free(basePath);
	
}
#endif


