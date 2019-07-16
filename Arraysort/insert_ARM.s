@PID: A92036065  Name: Peiran Li
@PID: A92010328  Name: Ziang Jing
.syntax unified

.text

.align 8
.global insert_ARM
.func insert_ARM, insert_ARM
.type insert_ARM, %function

insert_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE (list *ls is in r0, int val in r1)
    @-----------------------

    @ (your code)
    MOV r7, r1  @r7 = val
    CMP r1, #0
    BLT failed
    CMP r0, #0
    BEQ failed
    LDR r4, [r0, #4]  @r4 = ls->size
    LDR r5, [r0, #8]   @r5 = ls->maxSize
    CMP r4, r5     
    BNE notFull    @size != maxSize
    
    MOV r11, r0   @ r11 = ls
    LDR r0, [r0]   @r0 = ls->sortedList  
    LSL r1, r5, #3   @r1 = maxSize*=8 
    BL realloc @call to realloc 
    CMP r0, #0   @r0 == NULL
    BEQ failed
    LDR r8, [r11] 
    CMP r0, r8
    BEQ update
    MOV r8, #0
    STR r8, [r11]
update: STR r0, [r11] 
    LSL r5, r5, #1  @double the maxSize
    STR r5, [r11, #8]  @store the maxSize
    STR r4, [r11, #4]  @store the size
    MOV r0, r11   @r0 = ls    
     
 
notFull: MOV r4, #0  @i=0
    LDR r5, [r0, #4]  @r5 = ls->size
    LDR r8, [r0]  @r8 = ls->sortedList
loop1: CMP r4, r5
    BGE loopEnd1
    LSL r10, r4, #2
    LDR r9, [r8, r10] @r9 = *(r8+i)
    CMP r7, r9   @val <= *(ls->sortedList+i)
    BLE loopEnd1
    ADD r4, r4, #1  @ i++
    B loop1

loopEnd1: MOV r6, r4 @index = i
    SUB r4, r5, #1  @ i =ls->size-1

loop2: CMP r4, r6  @ i>=index
    BLT loopEnd2
    LSL r10, r4, #2
    LDR r9, [r8, r10] @r9 = *(ls->sortedList+i)
    ADD r10, r10, #4
    STR r9, [r8, r10]  @ *(ls->sortedList+i+1) = r9
    SUB r4, r4, #1  @i--
    B loop2

loopEnd2:
    LSL r10, r6, #2 
    STR r7, [r8, r10]  @*(ls->sortedList+index) = val
    ADD r5, r5, #1 @ls->size++
    STR r5, [r0,#4]
    MOV r0, r6  @r0 = index
    B return
   
    @ put your return value in r0 here:
failed: MOV r0, #-1
    B return
    @-----------------------

    @ restore caller's registers
return: pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end

