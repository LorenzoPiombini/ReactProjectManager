#ifndef OS_DETECTION_H
#define OS_DETECTION_H

#include <stdio.h>
 
/*window OS*/
#ifdef  _WIN32 
#define WIN 1
#else
#define WIN 0
#endif

/*Linux OS*/
#ifdef __linux__
#define LNX 1
#else 
#define LNX 0
#endif

/*macOs*/
#ifdef __APPLE__
#define APL 1
#else
#define APL 0
#endif

/*FreeBSD*/
#ifdef __FreeBDS__
#define BDS 1
#else
#define BDS 0
#endif

/*UNIX*/
#ifdef __unix__
#define UNX 1
#else
#define UNX 0
#endif

/*SOLARIS*/
#ifdef __sun
#define SUN 1
#else
#define SUN 0
#endif


void checkOS(){
   if(WIN){
   	printf("this is a windows system.\n");
   }else if(LNX) {
	printf("this is a Linux system.\n");
   }else if(APL){
	printf("this is a macOS system.\n");
   }else if(UNX){
   	printf("this is a Unix system.\n");
   }else if(BDS){
	printf("this is a FreeBSD system.\n");
   }else if(SUN){
   	printf("this is a Solaris system.\n");
   }
}


#endif // OS_DETECTION_H
