//name: Peiran Li  userid:peiranli
//name: Ziang Jing   userid:andigreen


#include <stdio.h>
#include "warmup.h"
int main(int argc, char* argv[]){
   FILE *inputfile;
   inputfile = fopen(argv[1],"r");
   unsigned * arr = char_freqs(inputfile);
   int i;
   for(i=0;i<256;i++){
     printf("%d  ",arr[i]);
   
   }
   fclose(inputfile);
  

}
