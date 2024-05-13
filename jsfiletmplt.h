#ifndef _JSFILETMPLT_H
#define _JSFILETMPLT_H



void screen(char fileName[200], char buffer[200]){
	printf("\nimport React from 'react';\n");
	printf("import { View, Text, StyleSheet } from 'react-native';\n\n");
        sprintf(buffer, "const %s = () => {\n\treturn <View>\n\t\t<Text>boilerplate</Text>\n\t</View>\n};", fileName);
        printf("%s",buffer);
        printf("\n\n\nconst styles = StyleSheet.create({\n\n});\n");
	sprintf(buffer,"\n\n\nexport default %s;\n\n\n", fileName);
        printf("%s", buffer);
}



#endif
