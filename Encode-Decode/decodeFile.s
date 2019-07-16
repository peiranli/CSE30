@Peiran Li   username: peiranli
@Ziang Jing   username: andigreen

.syntax unified

.data
format_read: .asciz "r"
.align 2
format_write: .asciz "w"

.text

.align 3
.global decodeFile
.func decodeFile, decodeFile
.type decodeFile, %function
 
@ void decodeFile(char *input, char *bin, char * output, int index)
decodeFile:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE
    @-----------------------
    MOV r4, r0  @input
    MOV r5, r1  @bin
    MOV r6, r2  @output
    MOV r7, r3  @index
    
    LDR r1, =format_read  @load read to r1
    BL fopen  @call to fopen
    CMP r0, #0
    BEQ return @null check
  
    MOV r8, r0  @FILE* in
    MOV r0, r5   @move bin to r0
    LDR r1, =format_write @load write to r1
    BL fopen
    CMP r0, #0
    BEQ return @null check

    MOV r9, r0   @FILE* out   
    
    MOV r0, r8  @r0 = in
    MOV r1, r9  @r1 = out
    MOV r2, r7  @r2 = index
    BL codeToBinary @call to codeToBinary
 
    MOV r0, r8 @r0 = in
    BL fclose  @call to close
    MOV r0, r9 @r0 = out
    BL fclose

    MOV r0, r5  @r0 = bin
    LDR r1, =format_read @r1 = "r"
    BL fopen 
    CMP r0, #0 
    BEQ return @null check
    MOV r8, r0 @FILE* in
    MOV r0, r6  @r0 = output
    LDR r1, =format_write @r1 = "w" 
    BL fopen
    CMP r0, #0
    BEQ return @null check
    MOV r9, r0  @FILE* out
   
    MOV r0, r8 @r0 = in
    MOV r1, r9  @r1 = out
    BL binaryToText @call to binaryToText
    MOV r0, r8 @r0 = in
    BL fclose 
    MOV r0, r9 @r0 = out
    BL fclose

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
