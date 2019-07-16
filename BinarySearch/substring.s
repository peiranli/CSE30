.syntax unified

.text

.align 8
.global substring
.func substring, substring
.type substring, %function

substring:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE (char *str1 is in r0, char *str2 is in r1)
    @-----------------------

    @ (your code)
    CMP r0, #0 
    BEQ ret_zero
    CMP r1, #0
    BEQ ret_zero
    
   
    MOV r4, r0 @store s1
    MOV r5, r1 @store s2
    BL strlen  @call to function strlen
    MOV r6, r0  @strlen(s1)
    MOV r0, r5  @move s2 to r0
    BL strlen  @call to function strlen
    MOV r7, r0  @strlen(s2)
    CMP r6, r7  @compare strlen(s1) and strlen(s2)
    BLE else
    MOV r8, r5
    MOV r9, r4
    B if1
else:
    MOV r8, r4 @p = s1
    MOV r9, r5 @q = s2
if1:
    MOV r0, r8
    BL strlen
    CMP r0, #0  @compare strlen(s1)
    BEQ ret_one
    
    MOV r11, r8 @char*s = p
out_loop:
    LDRB r7, [r9] @load *q
    CMP r7, #0
    BEQ ret_zero
    MOV r8, r11 @p=s
loop1: 
    LDRB r6, [r8]  @load *p
    LDRB r7, [r9]  @load *q
    CMP r7, #0
    BEQ if2
    CMP r6, r7   @compare *p and *q
    BEQ if2
    ADD r9, r9, #1  @q++
    B loop1 
if2:
    LDRB r7, [r9]
    CMP r7, #0
    BEQ ret_zero

loop2:
    LDRB r6, [r8]  @load *p
    LDRB r7, [r9]  @load *q
    CMP r6, r7  @compare *p and *q
    BNE if3
    CMP r6, #0
    BEQ if3
    CMP r7, #0
    BEQ if3
    ADD r8, r8, #1 @p++
    ADD r9, r9, #1 @q++
    B loop2

if3: 
    LDRB r6, [r8]  @load p
    CMP r6, #0
    BEQ ret_one
    B out_loop 
    
    @ put your return value in r0 here:
ret_zero:
    MOV r0, #0
    B return

ret_one:
    MOV r0, #1
    B return
    @-----------------------

    @ restore caller's registers
return: 
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end

