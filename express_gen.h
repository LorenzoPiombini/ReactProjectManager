#ifndef _EXPRESS_GEN_H
#define _EXPRESS_GEN_H


int isNgrok(){

	if (system("ngrok > /dev/null 2>&1") == 0 ){
		return 1;
	} 
	
	return 0;
}


void createServer(char nameProject[200], char path[200]){
     	if(!isNgrok()){
		RED_TEXT("Ngrok not intalled. It is easier working with ngronk to comunicate with your phone and the server.\nplease follow this guide:\nhttps://ngrok.com/download");
     	}else{
        	GREEN_TEXT("\nNgrok installed.");
     	}
	
        
	char fullCommand[300];
        
         

}



void generateExpressServer(){
   //create a directory with the name of the project and attach "-server" to it.
   //inside the new created folder run npm init -y
   //then run npm install bcrypt express jsonwebtoken mongoose nodemon
   // in the folder make another folder called src, where you will put the src code
   // generate index.js


}


#endif


