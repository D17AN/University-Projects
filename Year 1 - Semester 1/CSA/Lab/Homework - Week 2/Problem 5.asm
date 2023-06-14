bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; a,b,c,d-byte, e,f,g,h-word
    a db 5
    b db 3
    c db 2
    d db 10

; our code starts here
segment code use32 class=code
    start:
        ; (a+b)*(c+d) = (5+3)*(2+10) = 8 * 12 = 96
        mov AX, [a] ;  AX = a
        add AX, [b] ;  adding to AX value b
        mov BX, [c] ;  BX = c
        add BX, [d] ;  adding to BX value d
        mul BX ; multiplying AX with BX and the value will be stored in AX, more accurately in AL 
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
