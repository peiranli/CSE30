@PID: A92036065  Name: Peiran Li
@PID: A92010328  Name: Ziang Jing

.syntax unified

.text

.align 8
.global createlist_ARM
.func createlist_ARM, createlist_ARM
.type createlist_ARM, %function

createlist_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE (int maxElements is in r0)
    @-----------------------

    @ (your code)
    MOV r4, r0   @tmp = maxElements
    MOV r0, #12  @r0 = 12 
    BL malloc @call to malloc   list*emptylist =(list*)malloc(sizeof(list));
    MOV r5, r0   @assign the pointer to r5
    CMP r0, #0  @ emptylist == 0
    BEQ return
    MOV r0, r4  @r0 = maxElements
    LSL r0, #2  @r0 = r0*4
    BL malloc  @call to malloc
    STR r0, [r5]  @assign the pointer to r5
    CMP r0, #0 
    BEQ return
    MOV r7, #0
    STR r7, [r5,#4]
    STR r4, [r5,#8]
    MOV r0, r5

    @ put your return value in r0 here:

    @-----------------------

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
return: BX lr
.endfunc

.end

