bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; a,b-word; c,d-byte; e-doubleword; x-qword  - Unsigned represantation 
    a dw 1
    b dw 1
    c db 1
    d db 1 
    e dd 1
    x dq 1
    var1 resd 1
    
; our code starts here
segment code use32 class=code
    start:
        ; Problem statement  1/a+200*b-c/(d+1)+x/a-e ;
        mov EAX, 1; EAX = 1
        push EAX
        pop AX
        pop DX; DX:AX = EAX 
        
        div word [a]; AX = DX:AX / a = 1 / a
        mov BX, AX; BX = AX // BX = 1 / a
        
        mov AX, [b]
        mov CX, 200; CX = 200
        mul CX; DX:AX = AX * CX = b * 200
        
        mov CX, 0; converting BX to CX:BX // word to double word // CX:BX = 1 / a
        
        clc; clear carry flag 
        add BX, AX
        adc CX, DX; CX:BX = CX:BX - DX:AX = 1/a + 200*b
                
        mov AL, [c]; AL = c 
        mov AH, 0; converting AL to AX; AX = c 
        
        mov DL, [d]; DL = d
        add DL, 1; DL = d + 1
        div DL; AL = AX / DL = c / (d+1)
        
        mov AH, 0; converting AL to AX
        mov DX, 0; converting AX to DX:AX 
        
        sub BX, AX 
        sbb CX, DX; CX:BX = CX:BX - DX:AX = 1/a + 200*b - c/(d+1) 
        
        mov AX, [a]; AX = a 
        mov DX, 0; converting AX to DX:AX 
        
        mov word [var1], AX
        mov word [var1+2], DX ; var1 = DX:AX = a
        
        mov EAX, dword [x]
        mov EDX, dword [x+4]; EDX:EAX = x 
        
        div dword [var1]; EAX = EDX:EAX / var1 = x / a
        push EAX
        pop AX 
        pop DX; DX:AX = EAX
        
        clc; clear carry flag 
        add BX, AX 
        adc CX, DX; CX:BX = CX:BX - BX:AX = 1/a + 200*b - c/(d+1) + x / a
        
        
        sub BX, [e]
        sbb CX, [e+2]; CX:BX = CX:BX - e = 1/a + 200*b- c/(d+1) + x / a - e
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
