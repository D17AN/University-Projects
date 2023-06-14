bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ;a,b,c,d - byte
    a db 13
    b db 7
    c db 37
    d db 10
    result db 0
    
    
; our code starts here
segment code use32 class=code
    start:
        ; compute c-(d+d+d)+(a-b)
           mov AX, [c]
           add [result], AX
           mov AX, [d]
           add AX, [d]
           add AX, [d]
           sub [result], AX
           mov AX, [a]
           sub AX, [b]
           add [result], AX
           mov AX, [result]
           
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
