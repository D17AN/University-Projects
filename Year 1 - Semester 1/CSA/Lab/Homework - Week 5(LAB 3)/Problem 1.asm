bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ;a - byte, b - word, c - double word, d - qword - Unsigned representation
    a db 127
    b dw 300
    d dq 45
    r resq 1; reserve 1 quadword in memory to save the result
    

; our code starts here
segment code use32 class=code
    start:
        ;Problem statement (a+b-d)+(a-b-d) => (127 + 300 - 45) + (127 - 300 - 45) = 164
        
        
        ;Computing (a+b-d)
        mov AL, [a]; AL = a
        mov AH, 0; converting AL to AX/byte to word
        
        add AX, [b]; AX = AX + b = a + b 
        
        mov DX, 0; converting AX to DX:AX/word to double word
        
        push DX; push the high part to the stack
        push AX; push the low part to the stack
        pop EAX; EAX = DX:AX = a + b
        
        mov EDX, 0; converting EAX to EDX:EAX/double word to quadword 
        
        sub EAX, dword [d]
        sbb EDX, dword [d+4]; EDX:EAX = a + b - d
        
        ;Computing (a-b-d)
        mov BL, [a]; BL = a
        mov BH, 0; converting BL to BX/ byte to word 
        
        sub BX, [b]; BX = BX - b = a - b
        
        mov CX, 0; converting BX to CX:BX/ word to a double word

        push CX; push the high part to the stack
        push BX; push the low part to the stack
        pop EBX; EBX = CX:BX = a + b
        
        mov ECX, 0; converting EBX to ECX:EBX/ double word to quadword 
        
        sub EBX, dword [d]
        sbb ECX, dword[d+4]; ECX:EBX = a - b - d
        
        ;Computing (a+b-d)+(a-b-d)
        clc; clear the carry flag(CF = 0)
        add EAX, EBX; EAX = EAX + EBX
        adc EDX, ECX; EDX = EDX + ECX + CF
        
        ;EDX:EAX has the result 
        mov dword[r], EAX
        mov dword[r+4], EDX
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
        