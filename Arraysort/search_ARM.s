@PID: A92036065  Name: Peiran Li
@PID: A92010328  Name: Ziang Jing



.syntax unified

.text

.align 8
.global search_ARM
.func search_ARM, search_ARM
.type search_ARM, %function

search_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE (list *ls is in r0, int val is in r1)
    @-----------------------

    @ (your code)
    
    @ put your return value in r0 here:
    MOV r4, #0 @ i=0
    LDR r5, [r0, #4] @ r5 = ls->size
    LDR r6, [r0] @ r6 = ls->sortedlist
    CMP r5, #0
    BEQ loopend

loop: CMP r4, r5
    BGE loopend
    LSL r8, r4, #2  @i*4
    LDR r7, [r6, r8] @r7 = *(ls->sortedlist+i)
    CMP r1, r7 
    BNE continue @ if r1!=r7, continue
    MOV r0, r4
    B end
continue: ADD r4, r4, #1 
    B loop
    
loopend:    MOV r0, #-1
    @-----------------------

    @ restore caller's registers
end:    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end

