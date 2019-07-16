.syntax unified


/* You can put constants in the .data section. Look up how to do it on your own,
 * or come ask us if you're curious!*/
.data 



.text

/* int str_to_int(char * str, int * dest);*/
/* Return 1 for success and 0 for failure. */
/* If successful, store the result at the */
/* location pointed to by "dest" */

.align 8
.global str_to_int
.func str_to_int, str_to_int
.type str_to_int, %function

str_to_int:
    @ We need to save away a bunch of registers
    push    {r4-r11, ip, lr}

    /* Your code goes here */
    CMP r0, #0
    BEQ ret_zero
    CMP r1, #0
    BEQ ret_zero
    LDRB r4, [r0] 
    CMP r4, #45 
    BNE check_range
    B check_end 
check_range: 
    CMP r4, #48
    BLT ret_zero
    CMP r4, #57
    BGT ret_zero
check_end:
    MOV r5, r0 @store r0
    ADD r5, r5, #1 @p++
    
loop1:
    LDRB r6, [r5]
    CMP r6, #0
    BEQ loop1_end
    CMP r6, #48
    BLT ret_zero
    CMP r6, #57
    BGT ret_zero
    ADD r5, r5, #1 @ p++
    B loop1

loop1_end:
    MOV r5, r0
    MOV r10, #0
    STR r10, [r1]
    LDRB r6, [r0] 
    CMP r6, #45
    BEQ negative
    BNE positive
negative:
    ADD r5, r5, #1 @p++
loop2:
    LDRB r6, [r5]
    CMP r6, #0
    BEQ ret_one
    LDR r7, [r1] @*dest
    LSL r8, r7, #3 @*dest*8
    LSL r9, r7, #1 @*dest*2
    ADD r7, r8, r9  @*dest*10
    SUB r6, r6, #48 @*p - '0'
    SUB r7, r7, r6  @*dest - (*p - '0')
    STR r7, [r1]  
    ADD r5, r5, #1 @p++
    B loop2

positive:
loop3:
    LDRB r6, [r5]
    CMP r6, #0
    BEQ ret_one
    LDR r7, [r1]  @*dest
    LSL r8, r7, #3
    LSL r9, r7, #1
    ADD r7, r8, r9
    SUB r6, r6, #48
    ADD r7, r7, r6
    STR r7, [r1]
    ADD r5, r5, #1
    B loop3
    /* Return back to calling function */
ret_one: 
    MOV r0, #1
    B return 

ret_zero: 
    MOV r0, #0
    B return
    @ This handles restoring registers and returning
return: 
    pop     {r4-r11, ip, pc}

.endfunc

.end


