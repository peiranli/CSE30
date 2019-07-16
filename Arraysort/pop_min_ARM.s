@PID: A92036065  Name: Peiran Li
@PID: A92010328  Name: Ziang Jing

.syntax unified

.text

.align 8
.global pop_min_ARM
.func pop_min_ARM, pop_min_ARM
.type pop_min_ARM, %function

pop_min_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE (list *ls is in r0)
    @-----------------------
    MOV r4, r0
    LDR r5, [r4, #4] @ r5=ls->size
    CMP r5, #0 @ if size == 0 then return -1
    BEQ empty
    LDR r11, [r4] @ r11=ls->sortedlist
    LDR r4, [r11] @ r4 =*(ls->sortedlist)
    SUB r6, r5, #1 @ r6=size-1
    MOV r7, #0 @ i=0

loop: CMP r7, r6
    BGE loopend
    LSL r10, r7, #2
    ADD r10, r10, #4
    LDR r9, [r11, r10] @ r9 = *(ls->sortedlist+i+1)
    SUB r10, r10, #4 
    STR r9, [r11, r10] @ *(ls->sortedlist+i) = r9 
    ADD r7, r7, #1 @ i++
    B loop

loopend:
    SUB r5, r5, #1
    STR r5, [r0, #4] @size --
    B success
    @ (your code)
   
    @ put your return value in r0 here:

    @-----------------------
empty: MOV r0, #-1
    B end
success: MOV r0, r4 @return popped val

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
end: BX lr
.endfunc

.end

