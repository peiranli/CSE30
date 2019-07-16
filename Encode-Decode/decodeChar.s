@Peiran Li   username: peiranli
@Ziang Jing   username: andigreen


.syntax unified

.text

.align 3
.global decodeChar
.func decodeChar, decodeChar
.type decodeChar, %function

@ char decodeChar(char *b)
decodeChar:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE
    @-----------------------
    MOV r4, #0 @sum=0
    MOV r5, #0 @index=0
    MOV r6, #1 @mask=0x01
    MOV r7, #0 @bit=0
    
loop:CMP r5,#6
    BGE loopend
    LDRB r11,[r0,r5] @r11=b[index]
    CMP r11, #49  @compare to the value of ascii value of 1
    BEQ equalsone
    MOV r7, #0 @ if r11!='1', bit=0
    B ifend
equalsone:MOV r7, #1
ifend:
    RSB r10, r5, #5 @r10 = 5-index
    LSL r10, r6, r10  @mask << (5-index)
    MUL r7, r7, r10  @bit * mask 
    ADD r4, r4, r7 @sum+=bit*(mask<<5-index)
    ADD r5, r5, #1 @index++   
    B loop
loopend:
    LDR r9, =MAPPING @get mapping
    LDRB r0, [r9,r4]
    
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
