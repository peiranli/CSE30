@PID: A92036065  Name: Peiran Li
@PID: A92010328  Name: Ziang Jing

.syntax unified

.text

.align 8
.global get_max_ARM
.func get_max_ARM, get_max_ARM
.type get_max_ARM, %function

get_max_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE (list *ls is in r0)
    @-----------------------
    MOV r4, r0
    LDR r6, [r4, #4]
    CMP r6, #0
    BEQ empty
    SUB r6, r6, #1
    LSL r6, r6, #2
    LDR r5, [r4]
    LDR r5, [r5, r6]
    MOV r0, r5
    B end
empty: MOV r0, #-1

    @ (your code)

    @ put your return value in r0 here:    

    @-----------------------

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
end: BX lr
.endfunc

.end

