//name: Peiran Li userid:peiranli
//name: Ziang Jing  userid:andigreen


#include <stdio.h>
#include <stdlib.h>
#include "warmup.h"

int main(int argc, char** argv){
     /* Your main code for reversing endian-ness goes here*/
     if(argc != 3){
       printf("incorrect number of commands!\n");
       exit(-1);
     }
 
     FILE *inFile;
     //open stream
     inFile  = fopen(argv[1], "rb");
     //null check
     if(inFile == NULL)
         exit(-1);
     FILE *outFile;
     //open stream
     outFile = fopen(argv[2], "wb");
     //null check
     if(outFile == NULL)
         exit(-1);
     int nextInt;
     int reverse;
     //read int from file each time and reverse it
     // and then write it to file
     while(1){
        fread(&nextInt, 4, 1, inFile);
        if(feof(inFile))         
              break;
        
        reverse = reorder_bytes(nextInt);  
        fwrite(&reverse, 4, 1, outFile);     
     }
     fclose(inFile);
     fclose(outFile);
}
