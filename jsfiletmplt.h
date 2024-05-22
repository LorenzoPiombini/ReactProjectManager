#ifndef _JSFILETMPLT_H
#define _JSFILETMPLT_H


void screen(char *fileName, char *path){
        char basePath[500];
        int result;
        
        result = snprintf(basePath, sizeof(basePath), "%s%s.js",path,fileName);
	
	if(result < 0 || result >= sizeof(basePath)){
		printf("Error: path is too long");
	        return;
        }

	FILE *file = fopen(basePath,"w");
        if(file == NULL){
		printf("Error opening file %s!", fileName);
		return;
	}
	
	fprintf(file, "import React from 'react';\n");	
        fprintf(file,"import { View, Text, StyleSheet } from 'react-native';\n\n");
        fprintf(file, "const %s = () => {\n\treturn <View>\n\t\t<Text>this is %s </Text>\n\t</View>\n};", fileName,fileName);
        fprintf(file,"\n\n\nconst styles = StyleSheet.create({\n\n\t//add your styles here\n\n});\n");
	fprintf(file,"\n\n\nexport default %s;\n\n\n", fileName);
        
	fclose(file);
	printf("\nScreen %s, created succesfully.\n",fileName);
}

void indexJs(char *fileName, char *path, char * mongoUri){
    size_t len = strlen(fileName) + strlen(path) + 1;
    char *basePath = (char *)malloc(len * sizeof(char));
     
    if (basePath == NULL){
         fprintf(stderr,"Could not generate the basePath to create the server project.\n");
         return ;
        }
    

    basePath[0]= '\0';

    strcat(basePath, path);
    strcat(basePath, fileName);
    

    FILE *file = fopen(basePath, "w");
    if(file == NULL){
                printf("Error opening file %s!", fileName);
                free(basePath);
                return;
        }

    fprintf(file, "require('./modules/User');\nconst express = require('express');\n");
    fprintf(file,"const mongoose = require('mongoose');\nconst bodyParser = require('body-parser');\n");
    fprintf(file,"const authRoutes = require('./routes/authRoutes');\n\nconst app = express();\n\n");
    fprintf(file,"// the order is important:\n{/** 1 */} app.use(bodyParser.json());\n{/** 2 */} app.use(authRoutes);\n");
    fprintf(file,"/** MONGO DB CONNECTION @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/\n");
    fprintf(file,"const mongoURI = \"%s\"\n", mongoUri);
    fprintf(file, "mongoose.connect(mongoURI);\nmongoose.connection.on('connected', () =>{\nconsole.log('connected to mongo instance');\n});\n");
    fprintf(file,"mongoose.connection.on('error', (e) =>{\nconsole.log('Error connecting to mongo', e);\n})\n");
    fprintf(file,"/**@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */\n");
    fprintf(file,"app.get(\"/\", requireAuth, (req, res) => {\nres.send(`Your email: ${req.user.email}`);\n});\n");
    fprintf(file,"app.listen(3000, () => {\nconsole.log(\"Listening on port 3000\");\n});\n");
 
    fclose(file);
    free(basePath);
    printf("\n Index.js, created succesfully.\n");	

}



void requireAuth(char* path){
	const char *requireAuth = "requireAuth";
        
        size_t len = strlen(path) + strlen(requireAuth)+ 1;
        char *fullPath = (char *)malloc(len *sizeof(char));

        if(fullPath == NULL){
	      fprintf(stderr,"Could not generate the full path to create requireAuth.js");
	      return;	
        }

	fullPath[0] = '\0';

        strcat(fullPath, path);
	strcat(fullPath,requireAuth);

	FILE *file = fopen(fullPath,"w");
        
        fprintf(file,"");
        fprintf(file,"");
        fprintf(file,"");
        fprintf(file,"");
        fprintf(file,"");
        fprintf(file,"");
        fprintf(file,"");
        fprintf(file,"");



	fclose(file);
}
#endif
