//name:Peiran Li  userid: peiranli
//name: Ziang Jing  userid:andigreen


/**
 * ALL IMPLEMENTATIONS AND HELPER FUNCTIONS FOR DECODER WILL BE IN THIS FILE.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "decoder.h"
 
/**
 * Takes a char c and int index as input. 
 * Extracts the bit at the input index from the char c. The 0 index
 * refers to the LSB, so for example, index 2 should extract the 3rd
 * least significant bit.
 *
 * @param c the char to extract a bit from
 * @param index the index of the bit to extract
 * @returns the value of the bit at index in c
 */
int extractBit(char c, int index){
    int bit;
    // create a mask to extract bit
    int mask = 0x01;
    //fetch the bit by shifting the char right by index number of bits
    bit = mask & c>>index;
    return bit;
}

/**
 * Takes a 6 character array b as input and returns the corresponding
 * char from MAPPING that is indexed by the binary ASCII string b.
 * For example, if b = "010101", then the char that is mapped to it is 
 * in MAPPING, index 1*16 + 1*4 + 1*1 = 21.
 *
 * @param b a pointer to a 6 character array, with ASCII '1's and '0's
 * @returns the corresponding character from MAPPING
 */
char decodeChar(char *b){
    // parameter as the index of the needed char in MAPPING
    int sum = 0;
    int index;
    int mask = 0x01;
    int bit;
    //loop to get the decimal value that the char array represents
    for(index = 0; index<6; index++){
        //convert the char value to int value with two if statements
        if(b[index] == '1')
           bit = 1;
        else
           bit = 0;
        sum += bit*(mask << (5-index));
    } 
    //get and return the char c
    char c = MAPPING[sum];
    return c;
}

/**
 * Takes a FILE handle in as input (corresponding to
 * an encoded file) and reads the file, char by char. The
 * bit at the input index of each char is extracted (by calling
 * extractBit). The least significant bit is in index 0.
 *
 * For each character, if the extracted bit is 0, output ASCII '0' to
 * the output file. If the extracted bit is 1, output ASCII
 * '1' to the output file.
 *
 * @param in the input file handle to read from
 * @param out the output file to write the extracted ASCII binary into
 * @param index the index of the bit to extract from each char
*/
void codeToBinary(FILE *in, FILE *out, int index){
    char c;
    // loop to get each bit from each char one by one
    while(1){
      c = fgetc(in);
      if(feof(in)) break;
      int bit = extractBit(c, index);
      //change the int to char with two if statements
      if(bit==1)
         fputc('1',out);
      else 
         fputc('0',out);
      
    }
}

/**
 * Takes a FILE handle in as input (corresponding to a
 * "binary" decoded file) and reads the file, 6 chars at a
 * time. Each 6 chars (all ASCII 0's and 1's) should be read into a
 * char array and decoded into its corresponding char (by calling
 * decodeChar). The resulting chars would be output to the FILE handle
 * pointed to by out.
 *
 * @param in the input file, encoded as ASCII '1's and '0's
 * @Param out the decoded output file (ASCII)
*/
void binaryToText(FILE *in, FILE *out){
    // take 6 char into a char array at a time
    char *arr = (char*)malloc(sizeof(char)*6);
    char c;
    // controller to end the stream
    int flag = 0;
    while(1){
       int i;
       // fill in the array with 6 continuous chars
       for(i = 0; i < 6;i++){
          c = fgetc(in);
          if(feof(in)){
             flag = 1; 
             break;
          }
          arr[i] = c;
       }
       if(flag)
           break;
       //write the decoded char into a file
       c = decodeChar(arr);
       fputc(c, out);
    }
    free(arr);
   
}

/**
 * Reads in a file from the specified input path and outputs a a binary decoding to
 * specified bin path and a fully decoded version to specified output path.
 * This should simply open the necessary files, call the above helper functions
 * in the correct sequence, and close the necessary files.
 *
 * @param input the path to the input file
 * @param bin the path to the decoded ASCII binary output file
 * @param output the path to the decoded output file
 * @param index The index of the bit from which binary values should be extracted
 */
void decodeFile(char* input, char* bin, char* output, int index){
    // open two stream for code to binary
    FILE* in = fopen(input, "r");
    FILE* out = fopen(bin, "w");
    //NULL check
    if(in == NULL){
       return;
    }   
    if(out == NULL){
       return;
    }
    codeToBinary(in, out, index);
    fclose(in);
    fclose(out); // code to binary finished
    
    // open two stream for binary to text
    in = fopen(bin, "r");
    out = fopen(output, "w");
    // NULL check
    if(in == NULL){
        return;
    }
    if(out == NULL){
        return;
    }
    
    binaryToText(in, out);
    fclose(in);
    fclose(out); //decode finished
}
