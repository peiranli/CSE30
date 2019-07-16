@Peiran Li    username: peiranli
@Ziang Jing   username: andigreen

.syntax unified

.text

.align 3
.global extractBit
.func extractBit, extractBit
.type extractBit, %function

@ int extractBit(char c, int index)
extractBit:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE
    @-----------------------
    MOV r4, #0x01 @ create mask
    ASR r5, r0, r1  
    AND r6, r4, r5  @bit
    @ (your code)
    @ put your return value in r0 here:
    MOV r0, r6
    @-----------------------
return: 
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
