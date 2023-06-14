bits 32 ; assembling for the 32 bits architecture


; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; A, B - words, C - byte
    a dw 0100101011110100b
    b dw 0110110001101001b
    c resb 1    ; C should be 0111 0100b

; our code starts here
segment code use32 class=code
    start:
        ;Problem statement
        ;Given the words A and B, compute the byte C as follows:    
        ;the bits 0-5 are the same as the bits 5-10 of A
        ;the bits 6-7 are the same as the bits 1-2 of B.
        and word [a], 0000000000111111b; A = 0000 0000 0011 0100b // retaining only the bits from 0 to 5
        and word [b], 0000000011000000b; B = 0000 0000 0100 0000 // retaining only the bits from 6 to 7
        mov BL, byte [a]; BX = a 
        or BL, byte [b]; BL will retain the result
        mov byte [c], BL
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
