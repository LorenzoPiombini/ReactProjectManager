#include <stdlib.h>
#include <stdio.h>
#include "os_detection.h"

int isNode(){
	if( system("node -v > NULL") == 0){
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

	if(isNode() == 0){
        	printf("install Node before start working with React.");
        }
	checkOS();
	printf("\nenter name of the file: ");
	scanf("%s", fileName);

	printf("\nimport React from 'react';\n");
	printf("import { View, Text, StyleSheet } from 'react-native';\n\n");
        sprintf(buffer, "const %s = () => {\n\treturn <View>\n\t\t<Text>boilerplate</Text>\n\t</View>\n};", fileName);
        printf("%s",buffer);
        printf("\n\n\nconst styles = StyleSheet.create({\n\n});\n");
	sprintf(buffer,"\n\n\nexport default %s;\n\n\n", fileName);
        printf("%s", buffer);


	return 0;
}
