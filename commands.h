#ifndef _COMMANDS_H_
#define _COMMANDS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NO_OUTPUT " > /dev/null 2>&1"
#define MK_DIR "mkdir "
#define RM_DIR "rm -r "
#define CD "cd "
#define PWD "pwd"
#define EXPO "npx create-expo-app "
#define NPM_init "npm init -y"
#define ES_install "npm install bcrypt express jsonwebtoken mongoose nodemon"





size_t totLen(char* command, char* path, char* projectName){
	if((command == NULL || command[0] == '\0') && (path != NULL || path[0] != '\0') && (projectName!= NULL || projectName[0] != '\0') ){
		return strlen(path) + strlen(projectName) + 1;
	}else if ((path == NULL || path[0] =='\0') && (command != NULL || command[0] != '\0') && (projectName!= NULL || projectName[0] != '\0'
) ){
		return strlen(command)  + strlen(projectName) + 1;
	}else if ((projectName == NULL || projectName[0] =='\0')&& (path != NULL || path[0] != '\0') && (command != NULL || command[0] != '\0'
)){
		return strlen(command) + strlen(path) + 1;
	}else if((command != NULL || command[0] != '\0') && (path != NULL || path[0] != '\0') && (projectName!= NULL || projectName[0] != '\0') ){
	    	return strlen(command) + strlen(path) + strlen(projectName) + 1;
	}else{
		return 0;
	}
}

char* createProjectDirectory(char* path, char* projectName){
        size_t basePathLen = strlen(path) + strlen(projectName) + 2; // this accounts for 1 '/' and the '/0'
	char *basePath = (char *)malloc(basePathLen * sizeof(char));
	

	if (basePath == NULL){
         fprintf(stderr,"memory allcoation failed.\n");
         fprintf(stderr,"Could not create project  project path.");
         return NULL;
        }
        
        basePath[0] = '\0';
        
                
	
	//create basePath for the project
	//check if there is a '/' at the end of the path already:
	

	strcat(basePath,path);
        strcat(basePath,projectName);
        char suffix[] = "/";
        strcat(basePath,suffix);
        
        size_t l = totLen(EXPO,path,projectName);
        char *expoPrj = (char *)malloc(l * sizeof(char));
        if(expoPrj == NULL){
	      fprintf(stderr,"Could not create an EXPO project");
              return NULL;
	}
	
	strcat(expoPrj,EXPO);
        strcat(expoPrj,path);
        strcat(expoPrj,projectName);
        
        if(system(expoPrj) == 0){
        printf("Project directory: %s, created succesfully \xF0\x9F\x98\x8E.\n", projectName);
        }else {
	printf("project not created, check Node.js or npm.");
	}

	free(expoPrj);

        return basePath;   
}

void createProjectStructure(char* basePath){
   	size_t len = totLen(MK_DIR,basePath,""); 

    	char *structure = (char *)malloc(len * sizeof(char));

	if(structure == NULL){
         fprintf(stderr,"Could not organized the project.\n");
         return ;
        }


    	structure[0]= '\0';
	
        
        strcat(structure,MK_DIR); 
    	strcat(structure, basePath);                                                                                             
    	strcat(structure, "src");                                                                                       
        

	if(system(structure) == 0){
		printf("src directory created succesfully.\xF0\x9F\x98\x8E\n");
	} else {
	        printf("src directory not created, check the path you provide.\n");
		printf("the path is %s", structure);
		return;
	}                                                                                                   
        
	
       
       char* dirs[] = {"hooks","components"};

       
       for(int i = 0; i < 2; i++){
		size_t lenRm = totLen(RM_DIR,basePath,dirs[i]); 
		char *removeDirs = (char *)malloc(lenRm * sizeof(char));
		
		if(removeDirs == NULL){
			fprintf(stderr, "Could not organize the project.\n");
            		return;
		}
		
		removeDirs[0] = '\0';
		
		strcat(removeDirs,RM_DIR);
                strcat(removeDirs,basePath);
                strcat(removeDirs,dirs[i]);
                
                if(system(removeDirs) != 0){
			printf("Could not clean the Project directory.\n");
			return;
		}
		free(removeDirs);
       }



        free(structure);

 
        char* screenDir = "/screens";
        char* componentsDir = "/components";
        char* hooksDir ="/hooks";
        char* contextDir = "/context";
        char* apiDir = "/api";
 
	size_t newBasePathLen = strlen(basePath) + strlen("src") + 1;        
	char *newBasePath = (char *)malloc(newBasePathLen * sizeof(char));
        
        if(newBasePath == NULL){
		 fprintf(stderr,"Could not organized the project.\n");
         	return ;                                             
	}

	newBasePath[0] = '\0';
	
	strcat(newBasePath,basePath);                                                                                
        strcat(newBasePath, "src"); 


        size_t lenScreen = totLen(MK_DIR, newBasePath, screenDir);
	size_t lenComponents = totLen(MK_DIR, newBasePath, componentsDir); 
	size_t lenHooks = totLen(MK_DIR, newBasePath, hooksDir); 
	size_t lenContext = totLen(MK_DIR, newBasePath, contextDir); 
	size_t lenApi = totLen(MK_DIR, newBasePath, apiDir); 
 
        char *screen = (char *)malloc(lenScreen * sizeof(char));
	char *components = (char *)malloc(lenComponents * sizeof(char));
	char *hooks = (char *)malloc(lenHooks* sizeof(char));
	char *context = (char *)malloc(lenContext * sizeof(char));
	char *api = (char *)malloc(lenApi * sizeof(char));
        
        if(screen  == NULL || components == NULL || hooks == NULL || context == NULL  || api == NULL ){
         fprintf(stderr,"Could not organized the project.\n");                                                     
         return ;                                                                                                     
        }
	
	screen[0] = '\0';
	components[0] = '\0';
        hooks[0] = '\0';
        context[0] = '\0';
	api[0] = '\0';
        
	        
        strcat(screen,MK_DIR);
        strcat(screen, newBasePath);
        strcat(screen, screenDir); 
        if(system(screen) != 0){
		printf("could not organized the project.\n");
		free(screen);
		return;
        }else{
		free(screen);
	}


        strcat(components,MK_DIR);
        strcat(components, newBasePath);
        strcat(components, componentsDir);  
        if(system(components) != 0){
                printf("could not organized the project.\n");
        	free(components);
                return;
	 }else {
		free(components);
	}



	strcat(hooks,MK_DIR);
        strcat(hooks, newBasePath);
        strcat(hooks, hooksDir);  
        if(system(hooks) != 0){
                printf("could not organized the project.\n");
		free(hooks);
		return;
        }else {
		free(hooks);
	}



	strcat(context,MK_DIR);
        strcat(context, newBasePath);
        strcat(context, contextDir);  
        if(system(context) != 0){
                printf("could not organized the project.\n");
		free(context);
		return;
        }else {
		free(context);
	}

	strcat(api,MK_DIR);                                                                                      
        strcat(api, newBasePath);                                                                                  
        strcat(api, apiDir);                                                                                 
        if(system(api) != 0){                                                                                     
                printf("could not organized the project.\n");                                                        
                free(api);
                return;
        }else {
                free(api);
        }

	printf("project organized succesfully.\xF0\x9F\x98\x8E\n");




           
    	free(newBasePath);
    
     
}





char* getPwd(){
   	char pwd[300];
        char *result;
	FILE *command_reader;
        
        //open the command to read it
	command_reader = popen(PWD, "r");
        if (command_reader == NULL ){
		perror("Could not read the current working directory."); 
	}	
	
	if(fgets(pwd, sizeof(pwd), command_reader) != NULL){
	 	 pclose(command_reader); 
          
         	 result = malloc(strlen(pwd)+1);
	  	 if (result != NULL){
	              strcpy(result,pwd);
	 	      result[strcspn(result, "\n")] = 0;
	         }



		return result;
	}
        
        pclose(command_reader);
        return NULL;
}
#endif
