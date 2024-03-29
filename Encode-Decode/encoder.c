//name: Peiran Li  userid: peiranli
//name: Ziang Jing  userid: andigreen

/**
 * ALL FUNCTION IMPLEMENTATIONS AND HELPER FUNCTIONS FOR ENCODER WILL BE IN THIS FILE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "common.h"
#include "encoder.h"
/**
 *
 * This function takes a char c as input and returns a (6 character) array
 * that represents the 6 digit code for that character. This code is simply
 * the index of the char in the MAPPING array (represented in binary). 
 * You should use the REVERSE\_MAPPING array in this function to get 
 * the binary code for the character. REVERSE\_MAPPING array MUST be 
 * initialized with createReverseMapping(), prior to calling this function.
 *
 * @param c The input character to encode
 * @returns a six character array which encodes the index into ASCII binary
 */
char* encodeChar(char c){
    createReverseMapping();//initialize 
    int code = REVERSE_MAPPING[(int)c]; // get the code
    //create an array
    char* result = (char*)malloc(sizeof(char)*6);
    int j;
    int mask = 0x01;
    //encode
    for(j=0; j<6; j++){
      int tmp = (code  >> (5-j)) & mask;
      if(tmp)
         result[j] = '1';
      else 
         result[j] = '0';
  
    }
    return result;
}

/**
 * Takes a char c and int bit (should be either 0 or 1) and int index as input. 
 * Sets the bit at input index of c to be the input bit and returns the result.
 * The 0 index refers to the LSB, so for example, index 2 should 
 * set the 3rd least significant bit.
 * 
 * @param c the char to implant a bit into
 * @param bit the bit value to implant (0 or 1)
 * @param index the index to implant the bit into (0 is LSB)
 * @returns the char with bit b implanted into the input index
 */
char implantBit(char c, int bit, int index){
    //create a mask
    int mask = 0x01 << index;
    //bit clear
    c = c &(~mask);
    c += (bit << index);
    return c;
}

/**
 * Takes a FILE handle in as input (corresponding to a regular ASCII
 * text file) and reads the file, char by char. Encodes each char into
 * a 6 character "binary" char array (by calling encodeChar).  The
 * resulting character arrays should be written to the output file
 * handle out
 *
 * @param in The input text file to read
 * @param out The output file, in ASCII encoded "binary"
 */
void textToBinary(FILE *in, FILE *out){
    char tmp;
    char* arr;
    //get a char each time and encode
    while(1){
       tmp = fgetc(in);
       if(feof(in)) break;
       arr = encodeChar(tmp);
       fwrite(arr, 6, 1, out);
       free(arr);
    }
}

/**
 * Takes a FILE handle in as input (corresponding to a
 * "binary" encoded file) and reads the file 1 char at a time. Each
 * char read will be an ASCII '0' or ASCII '1', and either 0 or 1 
 * will be implanted into randomized chars generated by rand()%256.
 *
 * If ASCII '0', then implant 0 into the bit at the input index 
 * of a randomized char . If ASCII '1', then implant 1 into the bit at 
 * the input index of the randomized char (by calling implantBit). 
 * Write the result into the output file handle out 
 * (Note: The least significant bit is in index 0)
 *
 * @param in The input file handle to read (ASCII encoded binary)
 * @param out The output file to write to
 * @param index the index of the bit where binary values should be implanted (0 is LSB)
 */
void binaryToCode(FILE *in, FILE *out, int index){
    srand(1); //DO NOT REMOVE OR EDIT THIS LINE OF CODE
    
    char random;
    char c;
    //get random char each time and implant
    while(1){
       random = (char)rand()%256;
       c =fgetc(in);
       if(feof(in)) break;
       if(c == '0')
          random = implantBit(random,0,index);
       else
          random = implantBit(random,1,index);
       fputc(random,out);
    }
    
}

/**
 * Reads in a file from the specified input path and outputs a a binary encoding to
 * specified bin path and a fully encoded version to specified output path. 
 * This should simply open the necessary files and call the above helper 
 * functions in the correct sequence, and close the necessary files.
 *
 * @param input the path to the input file
 * @param bin the path to the encoded ASCII binary output file
 * @param output the path to the encoded output file 
 * @param index The index of the bit where binary values should be implanted (0 is LSB)
*/
void encodeFile(char* input, char* bin, char* output, int index){
    //open stream
    FILE *in = fopen(input, "r");
    FILE *out = fopen(bin, "w");
    //null check
    if(in == NULL){
       return;
    }
    if(out == NULL){
       return;
    }
    textToBinary(in, out);
    //close stream
    fclose(in);
    fclose(out);
    //open stream 
    in = fopen(bin, "r");
    out = fopen(output, "w");
    //null check
    if(in == NULL){
        return;
    }
    if(out == NULL){
        return;
    }

    binaryToCode(in, out,index);
    //close stream
    fclose(in);
    fclose(out);
 
}

