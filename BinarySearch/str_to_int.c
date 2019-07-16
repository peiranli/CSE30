#include <stdio.h>
#include <string.h>


int str_to_int(char * s, int * dest){
   if(s == NULL || dest == NULL)
       return 0;
   if(*s != 45 && (*s < 48 || *s > 57))
       return 0;
   char* p = s;
   p++;
   while(*p){
       if(*p < 48 || *p > 57)
          return 0;
       p++;
   }
   p = s;
   *dest = 0;
   if(*s == 45){
       p++;
       while(*p){
          *dest = *dest*10 - (*p - '0');
          p++;
       }
   }
   if(*s != 45){
       while(*p){
          *dest = *dest * 10 + *p - '0';
          p++;
       } 
   }
   return 1;
}
