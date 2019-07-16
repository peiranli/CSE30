.syntax unified

/* You can put constants in the .data section. Look up how to do it on your own,
 * or come ask us if you're curious!*/
.data 


.text

/*int binary_search_ARM(int * data, int toFind, int start, int end)*/
/*Note that you return your value in r0*/

.align 8
.global binary_search_ARM
.func binary_search_ARM, binary_search_ARM
.type binary_search_ARM, %function

binary_search_ARM:
    @ We need to save away a bunch of registers
    push    {r4-r11, ip, lr}
    @ May need to decrement stack pointer for more stack space
    SUB sp, sp, #20 @reserve for five local variables
    
    STR r0, [sp] 
    STR r1, [sp, #4]
    STR r2, [sp, #8]
    STR r3, [sp, #12]
    
    SUB r4, r3, r2
    ASR r4, r4, #1  @divide by 2
    ADD r5, r2, r4  @mid
    STR r5, [sp, #16] @store mid
    
    CMP r2, r3
    BGT ret_neg_one
    
    LSL r7, r5, #2
    LDR r6, [r0, r7]
    CMP r6, r1
    BEQ ret_mid
    BGT search_left
    BLT search_right    
    /* You should probably do something here */
    
ret_neg_one:
    MOV r0, #-1
    B return

ret_mid:
    MOV r0, r5
    B return

search_left:
    SUB r5, r5, #1
    MOV r3, r5
    BL binary_search_ARM
    B return

search_right:
    ADD r5, r5, #1
    MOV r2, r5
    BL binary_search_ARM
    B return
    @ Remember to restore the stack pointer before popping!
    @ This handles restoring registers and returning
return:
    ADD sp, sp, #20
    pop     {r4-r11, ip, pc}

.endfunc

.end


