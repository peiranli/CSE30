.syntax unified

/* You can put constants in the .data section. Look up how to do it on your own,
 * or come ask us if you're curious!*/
.data 


.text

/* int majority_count_ARM(int * arr, int len, int * result)*/
/* Remember to place your return value in r0. */
/* Return the count of the majority element in arr, */
/* or 0 if there is no majority. If "result" is not */
/* NULL, place the value of the majority element at */
/* that memory location before returning. */

.align 8
.global majority_count_ARM
.func majority_count_ARM, majority_count_ARM
.type majority_count_ARM, %function

majority_count_ARM:
    @ We need to save away a bunch of registers
    push    {r4-r11, ip, lr}
    @ May want to decrement stack pointer for more space
    SUB sp, sp, #32  @allocate space
    CMP r1, #0 
    BEQ ret_zero
    CMP r1, #1
    BNE ifend1
    CMP r2, #0 
    BEQ ret_one
    LDR r4, [r0]
    STR r4, [r2]
    B ret_one

ifend1:
    STR r0, [sp]    @arr
    STR r1, [sp, #4]  @len
    STR r2, [sp, #8]  @result
    ADD r6, sp, #12  @&left_majority
    ADD r7, sp, #16  @&right_majority
    ASR r5, r1, #1  @len/2
    MOV r1, r5   @len/2
    MOV r2, r6   @&left_majority
    BL majority_count_ARM @call to function
    STR r0, [sp, #24] @store left_majority_count
  
    LDR r5, [sp, #4]  @load len
    ASR r6, r5, #1  @len/2
    LDR r4, [sp]  @arr
    ADD r0, r4, r6
    SUB r1, r5, r6
    MOV r2, r7  
    BL majority_count_ARM @call to function
    STR r0, [sp, #28]  @store right_majority_count

if_left:
    LDR r4, [sp, #24] @load left_majority_count
    CMP r4, #0
    BEQ if_right
    LDR r0, [sp]  @load arr
    LDR r1, [sp, #4]  @load len
    LDR r2, [sp, #12]  @load left_majority
    BL count_ARM
    STR r0, [sp, #20]  @store c
    CMP r0, r6
    BLE if_right
    LDR r4, [sp, #8]  @result
    CMP r4, #0
    BEQ ret_c
    LDR r4, [sp, #12]  @load left_majority
    LDR r5, [sp, #8]  @load result
    STR r4, [r5]   @store *result
    B ret_c

if_right:
    LDR r4, [sp, #28]  @load right_majority_count
    CMP r4, #0
    BEQ ret_zero
    LDR r0, [sp]  @arr
    LDR r1, [sp, #4]  @len
    LDR r2, [sp, #16]  @right_majority
    BL count_ARM
    STR r0, [sp, #20]  @store to c
    CMP r0, r6 @compare c and len/2
    BLE ret_zero
    LDR r4, [sp, #8]
    CMP r4, #0
    BEQ ret_c
    LDR r4, [sp, #16] @load right_majority
    LDR r5, [sp, #8]
    STR r4, [r5]  @store *result
    B ret_c
       
    
    /* You should probably do something here */
       
ret_zero:
    MOV r0, #0 
    B return

ret_one:
    MOV r0, #1
    B return

ret_c:
    LDR r0, [sp, #20]
    B return
    @ Remember to restore your stack pointer before popping!
    @ This handles restoring registers and returning
return:
    ADD sp, sp, #32
    pop     {r4-r11, ip, pc}

.endfunc


.align 8 
.global count_ARM
.func count_ARM, count_ARM
.type count_ARM, %function

count_ARM:
    push    {r4-r11, ip, lr}

    
    MOV r4, #0  @i
    MOV r5, #0  @ret_count
loop:
    CMP r4, r1 
    BGE ret_count
    LSL r7, r4, #2 @i*4
    LDR r6, [r0, r7] @arr[i]
    CMP r6, r2
    ADD r4, r4, #1
    BNE loop
    ADD r5, r5, #1 @ret_count++
    B loop

ret_count:
    MOV r0, r5
    
    pop     {r4-r11, ip, pc}

.endfunc

.end
