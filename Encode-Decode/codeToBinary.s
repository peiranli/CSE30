@Peiran Li   username: peiranli
@Ziang Jing   username: andigreen


.syntax unified

.text

.align 3
.global codeToBinary
.func codeToBinary, codeToBinary
.type codeToBinary, %function

@void codeToBinary(FILE *in, FILE *out, int index);

codeToBinary:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE
    @-----------------------
    MOV r4, r0  @save in
    MOV r5, r1 @save out
    MOV r6, r2  @save index
loop:  MOV r0, r4 
    BL fgetc  @call to fgetc
    CMP r0, #-1  @compare with EOF
    BLE return
    MOV r1, r6  @move index
    BL extractBit
    CMP r0, #1 
    MOV r1, r5 @move out
    MOVEQ r0, #49 @r0 = '1'
    MOVNE r0, #48  @r0 = '0'
    BL fputc  @call to fputc
    B loop

    @ (your code)
    @ put your return value in r0 here:

    @-----------------------
return:
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
