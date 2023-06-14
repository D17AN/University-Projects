bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
; a,b-word; c,d-byte; e-doubleword; x-qword  - Signed represantation 
    a dw 1
    b dw 1
    c db 1 
    d db 1 
    e dd 1 
    x dq 1 
    var resw 1
    r resd 1
    

; our code starts here
segment code use32 class=code
    start:        
        ; Problem statement  1/a+200*b-c/(d+1)+x/a-e ;
        ; double size/ size -> size 
        mov AL, 1
        cbw; converts AL to AX
        cwd; converts AX to DX:AX 
        idiv word [a]; AX = DX:AX / a = 1 / a
        mov [var], AX; var = AX = 1 / a
        
        mov AX, 200;  AX = 200
        imul word [b]; DX:AX = AX * b = 200 * b
        mov CX, DX; CX = DX 
        mov BX, AX; BX = AX 
        
        mov AX, [var]; AX = var 
        cwd; converts AX to DX:AX 
        
        clc; clear CF 
        add BX, AX
        adc CX, DX; CX:BX = CX:BX + DX:AX = 1 / a + 200*b
        
        mov AL, [c]; AL = c 
        cbw; converts AL to AX 
        mov DL, [d]; DL = d
        add DL, 1; DL = DL + 1 = d + 1
        idiv DL; AL = AX / DL = c / (d + 1)
        
        cbw; converts AL to AX
        cwd; converts AX to DX:AX
        
        sub BX, AX
        sbb CX, DX; CX:BX = CX:BX - DX:AX = 1 / a + 200*b - c / (d+1)
        
        mov word [r], BX
        mov word [r+2], CX; r = CX:BX = 1 / a + 200*b - c / (d+1)
        
        mov AX, [a]; AX = a
        cwde; converts AX to EAX
        mov EBX, EAX; EBX = EAX
        
        mov EAX, dword [x]
        mov EDX, dword [x+4]; EDX:EAX = x
        
        idiv EBX; EAX = EDX:EAX / EBX = x / a
        
        push EAX
        pop AX
        pop DX ; DX:AX = EAX = x / a 
        
        mov BX, word [r]
        mov CX, word [r+2] ;CX:BX = r = 1 / a + 200*b - c / (d+1)
        
        clc; clear CF
        add BX, AX
        adc CX, DX; CX:BX = CX:BX + DX:AX = 1 / a + 200*b - c / (d+1) + x / a 
        
        sub BX, word [e]
        sbb CX, word [e+2]; CX:BX = CX:BX - e = 1 / a + 200*b - c / (d+1) + x / a - e
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
        