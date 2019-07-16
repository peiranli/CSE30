#include <stdio.h>
#include"substring.h"
#include <string.h>

int substring(char* s1, char* s2){
   if(s1 == NULL || s2 == NULL)
      return 0;
   char* p;
   char* q;
   if(strlen(s1) > strlen(s2)){
      p = s2;
      q = s1;
   }
   else{
      p = s1;
      q = s2;
   }
   if(strlen(p) == 0)
      return 1;

   char* s = p;
   //find start
   while (*q != '\0'){
	p=s;
   	while(*q != '\0'){
      		if(*p == *q) break;
		q++;
   	}
        if(*q == '\0')
		return 0;
   	while(*p == *q){
      		if(*p == '\0' || *q == '\0')
         		break;
      		p++;
      		q++;
   	}  
	if(*p == '\0')
           return 1;
   }
   return 0;
}

