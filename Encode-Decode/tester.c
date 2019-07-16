/**
 * THIS FILE MAY BE USED FOR TEST CODE. IT WILL NOT BE COLLECTED
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "common.h"
#include "encoder.h"
#include "decoder.h"

int main(int argc, char *argv[]){
    int index = atoi(argv[4]);
    decodeFile(argv[1],argv[2],argv[3],index);


    return 0;
}
