@Peiran Li   username:peiranli
@Ziang Jing  username:andigreen

.syntax unified

.text

.align 3
.global binaryToText
.func binaryToText, binaryToText
.type binaryToText, %function

@ void binaryToText(FILE *in, FILE *out)
binaryToText:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE
    @-----------------------
    MOV r4, r0  @save in
    MOV r5, r1   @save out
    MOV r0, #6  @sizeof(char)*6
    BL malloc @call to malloc
    MOV r11, r0 @save the pointer to arr 
    MOV r6, #0 @flag = 0
out_loop: MOV r7, #0 @ i = 0
in_loop: CMP r7, #6 @i < 6
    BGE in_end  @ exit loop when i >= 6
    MOV r0, r4 @ r0 = in
    BL fgetc  @call to fgetc 
    CMP r0, #-1 @compare c to EOF
    BNE if_end 
    MOV r6, #1 @flag = 1
    B in_end @exit for loop

if_end:  STRB r0, [r11, r7] @arr[i] = c
    ADD r7, r7, #1 @i++
    B in_loop 

in_end: CMP r6, #1
    BEQ out_end
    MOV r0, r11 
    BL decodeChar  @call to decodeChar
    MOV r1, r5
    BL fputc  @call to fputc
    B out_loop

out_end: MOV r0, r11
    BL free @call to free
        

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
