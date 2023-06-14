bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; a - byte, b - word, c - double word, d - qword - Signed representation
    a db 5
    b dw 5
    c dd 6
    d dq 7
    r resq 1

; our code starts here
segment code use32 class=code
    start:
        ; Problem statement(b+c+d)-(a+a)
        ;Compute (b + c + d)
        mov AX, [b]
        cwde; converting AX to EAX
        
        add EAX, [c];EAX = EAX + c
        
        cdq; converting EAX to EDX:EAX
        
        clc; clear the carry flag
        add EAX, dword [d]; 
        adc EDX, dword [d+4]; EDX:EAX = EDX:EAX + d = b + c + d
        
        mov dword[r], EAX
        mov dword[r+4], EDX; r = EDX:EAX
        
        mov AL, [a]
        add AL, [a]
        cbw; convert AL to AX
        cwde; convert AX to EAX
        cdq; convert EAX to EDX:EAX 
        
        sub dword [r], EAX
        sbb dword [r+4], EDX; r = b + c + d - (a + a)
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
        