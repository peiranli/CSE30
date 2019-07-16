@PID: A92036065  Name: Peiran Li
@PID: A92010328  Name: Ziang Jing

.syntax unified

.text

.align 8
.global remove_val_ARM
.func remove_val_ARM, remove_val_ARM
.type remove_val_ARM, %function

remove_val_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE (list *ls is in r0, int val is in r1)
    @-----------------------
    
    @ (your code)
    MOV r8, #0 @count = 0
    MOV r4, #0  @ i=0
    LDR r5, [r0, #4]  @ls->size
    LDR r6, [r0] @ls->sortedList
   
    @find the first value's index
loop1:    CMP r4, r5
    BGE loopEnd1
    LSL r11, r4, #2  @i*4
    LDR r7, [r6, r11]  
    CMP r7, r1 @ *(ls->sortedList+i) == val
    BEQ found 
    ADD r4, r4, #1 @i++
    B loop1
found: MOV r9, r4 @startIndex
    MOV r10, r4 @endIndex
    ADD r8, r8, #1 @count++
loopEnd1:CMP r8, #0
    BEQ failed
   
    @find last index of value
    ADD r4, r9, #1  @i=startIndex+1
loop2:    CMP r4, r5   @i<ls->size
    BGE loopEnd2 
    LSL r11, r4, #2 @i*4
    LDR r7, [r6, r11]   @*(ls->sortedList+i)
    CMP r7, r1  @ ==val
    BNE next
    MOV r10, r4  @endIndex = i
    ADD r8, r8, #1 @count++
next:    ADD r4, r4, #1  @i++
    B loop2

     @move elements forwards
loopEnd2:   ADD r4, r10, #1  @i = endIndex+1
    @r9 is startIndex
loop3: CMP r4, r5  @i<ls->size
    BGE loopEnd3
    LSL r11, r4, #2 @r11 = i*4
    LDR r7, [r6, r11] @*(ls->sortedList+i)
    LSL r11, r9, #2 @r11 = j*4
    STR r7, [r6, r11]  
    ADD r4, r4, #1  @i++
    ADD r9, r9, #1  @j++
    B loop3

loopEnd3: SUB r5, r5, r8  @ls->size -= count
    STR r5, [r0, #4]  
    MOV r0, r8
    B return
    @ put your return value in r0 here:

    @-----------------------

    @ restore caller's registers
failed: MOV r0, #0
    B return
return:  pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end

