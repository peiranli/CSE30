@name: Peiran Li  userid:peiranli
@name: Ziang Jing  userid:andigreen

.syntax unified

.text

.align 8
.global bitAnd_ARM
.func bitAnd_ARM, bitAnd_ARM
.type bitAnd_ARM, %function

bitAnd_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE 
    @-----------------------
    MVN r4, r0  @~x
    MVN r5, r1  @~y
    ORR r6, r4, r5 @(~x | ~y)
    
    
    @ (your code)
    
    @ put your return value in r0 here:
    MVN r0, r6  @~(~x | ~y)
    @-----------------------

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc



.global getByte_ARM
.func getByte_ARM, getByte_ARM
.type getByte_ARM, %function

getByte_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE 
    @-----------------------

    @ (your code)
    LSL r2, r1, #3   @n << 3
    ASR r3, r0, r2   @x >> (n << 3)
     
    @ put your return value in r0 here:
    AND r0, r3, #0xFF
    @-----------------------

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

@ TO DO: Add the function definitions for all the following functions
@ logicalShift_ARM
.global logicalShift_ARM
.func logicalShift_ARM, logicalShift_ARM
.type logicalShift_ARM, %function

logicalShift_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}
    
    MOV r8, #1    
    LSL r4, r8, #31 @1 << 31
    SUB r5, r1, 1   @ n-1
    ASR r6, r4, r5  @ 1<<31 >>(n-1)
    ASR r7, r0, r1  @ x >> n
    BIC r0, r7, r6  @ (x >> n) & ~mask 
    
    pop {r4-r11, ip, lr}

    BX lr
.endfunc 
@ bitCount_ARM
.global bitCount_ARM
.func bitCount_ARM, bitCount_ARM
.type bitCount_ARM, %function

bitCount_ARM:
    push {r4-r11, ip, lr}
   
    MOV r4, #0x01  
    LSL r5, r4, #8  @1<<8
    ORR r5, r4, r5   @1 | 1<<8
    LSL r4, r5, #16  @halfmask << 16
    ORR r5, r5, r4   @halfmask | halfmask<<16
    AND r6, r0, r5  @x& mask 
    ADD r6, r6, #0  @sum += x& mask
    ASR r7, r0, #1  @x>>1
    AND r7, r7, r5  @x>>1 & mask
    ADD r6, r6, r7  @sum += (x>>1) &mask
    ASR r7, r0, #2  @x>>2
    AND r7, r7, r5  @x>>2 & mask
    ADD r6, r6, r7  @sum += (x>>2) &mask
    ASR r7, r0, #3  @x>>3
    AND r7, r7, r5  @x>>3 &mask
    ADD r6, r6, r7  @ sum +=
    ASR r7, r0, #4  @x>>4
    AND r7, r7, r5  @x>>4 & mask
    ADD r6, r6, r7  @sum+=
    ASR r7, r0, #5  @x>>5
    AND r7, r7, r5  @x>>5 & mask
    ADD r6, r6, r7  @ sum +=
    ASR r7, r0, #6  @x>>6
    AND r7, r7, r5  @x>>6 &mask
    ADD r6, r6, r7  @sum+=
    ASR r7, r0, #7  @x>>7
    AND r7, r7, r5  @x>>7 &mask
    ADD r6, r6, r7
    ASR r7, r6, #16 @sum>>16
    ADD r6, r6, r7  @sum += sum >>16
    ASR r7, r6, #8  @sum >>8
    ADD r6, r6, r7  @sum += sum >> 16
    
    AND r0, r6, #0xFF 
    pop {r4-r11, ip, lr}
    
    BX lr
.endfunc

@ fitsBits_ARM
.global fitsBits_ARM
.func fitsBits_ARM, fitsBits_ARM
.type fitsBits_ARM, %function

fitsBits_ARM:
    push {r4-r11, ip, lr}
    
    SUB r4, r1, #1
    ASR r5, r0, r4
    ASR r6, r0, r1
    EOR r7, r5, r6
    EOR r0, r7, #1
    pop {r4-r11, ip, lr}

    BX lr
.endfunc
@ negate_ARM
.global negate_ARM
.func negate_ARM, negate_ARM
.type negate_ARM, %function

negate_ARM:
    push {r4-r11, ip, lr}
    
    MVN r0, r0
    ADD r0, r0, #1 
    pop {r4-r11, ip, lr}

    BX lr
.endfunc
@ isLessOrEqual_ARM
.global isLessOrEqual_ARM
.func isLessOrEqual_ARM, isLessOrEqual_ARM
.type isLessOrEqual_ARM, %function
   
isLessOrEqual_ARM:
    push {r4-r11, ip, lr}
    
    ASR r4, r0, #31
    ASR r5, r0, #31
    EOR r6, r4, r5  @signX ^ signY
    EOR r7, r6, #1   @!(signX ^ signY)
    MVN r8, r1 @~y
    ADD r9, r0, r8 @x+~y
    ASR r9, r9, #31 @>>31
    AND r9, r7, r9   @ !(signX ^ signY) & (x+~y) >> 31
    EOR r10, r5, #1 @!signY
    AND r11, r4, r10  @signX & !signY
    AND r11, r6, r11
    ORR r0, r11, r9
   
    pop {r4-r11, ip, lr}
    
    BX lr
.endfunc

.end

