//name: Peiran Li    userid:peiranli
//name: Ziang Jing  userid:andigreen


#include <stdio.h>
#include <stdlib.h>
#include "warmup.h"

unsigned int *char_freqs(FILE *fp){
   /* Your code goes here*/
   // NULL check
   if(fp == NULL)
      return NULL;
   int nextChar;
   unsigned *arr = (unsigned*)malloc(sizeof(unsigned)*256);
   int i;
   // loop for setting up the char freqs array
   for(i = 0; i < 256; i++)
      *(arr+i) = 0;
   int index;
   while(1){
     nextChar = fgetc(fp);
     if(feof(fp))
        break;
     // increase the index by the ASCII value of the last char
     index = nextChar;
     (*(arr+index))++;
   }
   return arr;
}
  

int reorder_bytes(int num){
   /* Your code goes here*/
   //mask for the LSB
   int mask = 0xFF;
   int lsb = num & mask;
   int result = 0;
   // make the lsb to be the msb
   result += lsb << 24;
   // make the l2sb to be the m2sb
   lsb = (num >> 8) & mask;
   result += lsb << 16;
   // make the m2sb to be the l2sb
   lsb = (num >> 16) & mask;
   result += lsb << 8;
   // make the msb to be the lsb
   lsb = (num >> 24) & mask;
   result += lsb;
   // return the reversed ending result
   return result;
}
