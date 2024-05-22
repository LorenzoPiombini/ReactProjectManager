#ifndef _INPUT_CHECKS_H
#define _INPUT_CHECKS_H



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



char* check_real_length_from_input(){
	char temp[600];
	
        if(fgets(temp, sizeof(temp), stdin) == NULL){
		fprintf(stderr,"Error reading input");
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
