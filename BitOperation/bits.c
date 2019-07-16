
/* 
 * CS:APP Data Lab 
 * 
 * Name: Peiran Li    Userid: peiranli
 * Name: Ziang Jing   Userid: andigreen
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the gradescope autograder and your own tester to check your functions for correctness.
  4. Use the dlc program to check if your functions meet the constraints on the
     maximum number of ops and permissible operators.
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the gradescope autograder to check for logical correctness 
 */


#endif
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  //x&y == ~(~x | ~y)
  return ~(~x | ~y);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  //shift right by n*8 bits and extract
  return (x >> (n << 3)) & 0xFF;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  //create a mask 
  int mask = (1 << 31) >> (n + (~1) + 1);
  //bit clear
  return (x >> n) & (~mask);
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
   //create a mask  0x01010101
   int halfMask = 0x01 | (0x01 << 8);
   int mask = halfMask | (halfMask << 16);
   int sum  = 0;
   sum += x & mask;//check if 0,8,16,24 digit is 1
   sum += (x >> 1) & mask;//check if 1,9,17,25 digit is 1
   sum += (x >> 2) & mask;//check if 2,10,18,25 digit is 1
   sum += (x >> 3) & mask;//check if 3,11,19,26 digit is 1
   sum += (x >> 4) & mask;//check if 4,12,20,28 digit is 1
   sum += (x >> 5) & mask;//check if 5,13,21,29 digit is 1
   sum += (x >> 6) & mask;//check if 6,14,22,30 digit is 1
   sum += (x >> 7) & mask;//check if 7,15,23,31 digit is 1
   //use binary to get a 8 digit number
   sum += (sum >> 16);
   sum += (sum >> 8);
   sum = sum & 0xFF;
   return sum;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  //x + (-x) and shift right by 31 bits and plus 1,
  // non-zero becomes 0 zero becomes 1
  return (((~x + 1) | x) >> 31) + 1;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  //shift 1 left by 31bits
  return (1 << 31);
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
   //compare cIn and cOut
   int cIn = x >> (n + (~1)+1);
   int cOut = x >> n; 
   return !(cIn ^ cOut);
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
   //positive shift right by n and negative shift right by (n+1)
   int signBit = x >> 31 & 1;
   int bias = signBit & ((1<<n)+(~1)+1);
   return (x+bias)>>n;
}
/* 
 * negate - return -x 
 * You may handle results that fall out of signed int range in any way that you
 * like
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  //get the negative and plus one
  return (~x)+1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  //check the signbit and if it is zero 
  int checkSignBit = !((1<<31) & x);
  return checkSignBit ^ !x;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  //get the sign of x and y
  int signX = x >> 31;
  int signY = y >> 31;
  //equal sign, then compare x-y
  int equalSign = (!(signX ^ signY)) & ((x + ~y) >> 31);
  //not equal sign, if signX = 1 and signY = 0 then x < y
  int notEqualSign = (signX ^ signY) & (signX & !signY);
  return equalSign | notEqualSign;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
 
  int result=0;
  //compare with 2^16 to determine the first 1
  result = !(!(x>>16))<<4;
  //determine second 1
  result += (!(!(x>>(8+result))))<<3;
  //determine third 1
  result += (!(!(x>>(4+result))))<<2;
  //determine fourth 1
  result += (!(!(x>>(2+result))))<<1;
  //determine fifth 1
  result += (!(!(x>>(1+result))));  
  return result;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  //extract exp and fraction
  unsigned exponent = (uf >> 23) & 0xFF;
  unsigned fraction = uf << 9;
  //return argument when NaN
  if(exponent == 0xFF && !fraction)
    return uf;
  //invert signBit
  return uf ^ (1 << 31);
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  // make a mask for the fraction part
  unsigned fraction_mask = (1<<23)-1;
  //initialize the position for the first one appearance
  unsigned firstOnePosition = 30;
  unsigned fraction;
  unsigned exponent;
  unsigned signBit = (1<<31) & x;
  //make the x to be a unsigned number
  if (x<0)
      x = ~x+1;
  // get the position of first one
  while(!(x & (1<<firstOnePosition))){
      firstOnePosition--;
  }
  //get the fraction part
  fraction = ((x << (31 - firstOnePosition)) >> 8) & fraction_mask;
  // get the exponent part
  exponent = ((127 + firstOnePosition)<<23);
  
  return fraction+exponent+signBit;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
  *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  //extract exp frac signbit
  unsigned exponent = (uf >> 23) & 0xFF;
  unsigned fraction = uf & ((1 << 23)+(~1)+1);
  unsigned signBit = (uf >> 31) & 1;
  unsigned result = 0;
  //check NaN
  if(exponent == 0xFF && fraction !=0)
    return uf;
  //normalized
  else if(exponent != 0){
    exponent = exponent + 1;
    result = (exponent << 23) + fraction + (signBit << 31);
  }
  //denormalized
  else if(exponent == 0){
    result = (fraction << 1) | (signBit << 31);      
  } 
  return result;
}

