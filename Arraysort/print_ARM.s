@PID: A92036065  Name: Peiran Li
@PID: A92010328  Name: Ziang Jing


.syntax unified
.data
formatInt: .asciz "%d "
.align 2
breakLine: .asciz "\n"
.text

.align 8
.global print_ARM
.func print_ARM, print_ARM
.type print_ARM, %function

print_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE (list *ls is in r0)
    @-----------------------

    @ (your code)
    LDR r4, =formatInt  @r4 has the memory location of formatInt
    MOV r6, #0  @i=0
    LDR r7, [r0, #4]  @ls->size
    LDR r8, [r0]  @ls->sortedList
    
loop:    CMP r6, r7 
    BGE loopend
    MOV r0, r4
    LSL r9, r6, #2  @i*4
    LDR r10, [r8, r9]  @value
    MOV r1, r10
    BL printf
    ADD r6, r6, #1  @i++
    B loop


loopend:
    LDR r4, =breakLine 
    MOV r0, r4
    BL printf
    @ put your return value in r0 here:

    @-----------------------

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end

