bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; A, B - words, C - byte, D - doubleword
    a dw 0100101011110100b
    b dw 0110110001101001b
    c resb 1   
    d resd 1 
; our code starts here
segment code use32 class=code
    start:
        
        ;Problem statement
        ;Given the words A and B, compute the byte C as follows:    
        ;the bits 0-5 are the same as the bits 5-10 of A
        ;the bits 6-7 are the same as the bits 1-2 of B.
        mov DL, 0; the result will be computed in DL
        mov AX, [a]; AX = a  
        mov BX, [b]; BX = b 
        and AX, 0000000000111111b; AX will keep only the bits from 0-5
        and BX, 0000000011000000b; BX will keep only the bits from 6-7
        or DL, BL; DL will contain the result C = 0111 0100b
        mov byte [c], DL; c = DL 
        
        ;Compute the doubleword D as follows:
        ;the bits 0-7 are the same as the bits 8-15 of B
        ;the bits 8-15 are the same as the bits of C
        ;the bits 16-23 are the same as the bits 8-15 of A
        ;the bits 24-31 are the same as the bits 0-7 of A
        
        mov dword[d], 0; where the result will be computed 
        
        ;the bits 0-7 are the same as the bits 8-15 of B
        mov AX, [b]; AX = b
        shr AX, 8; shift to right 8 bits
        cwde; AX converts to EAX
        or dword [d], EAX; setting the 0-7bits with EAX
        
        ;the bits 8-15 are the same as the bits of C
        mov AL, [c]; AL = c
        cbw; convert AL to AX
        cwde; convert AX to EAX
        shl EAX, 8; shift to left 8 bits
        or dword [d], EAX; setting the 8-15bits with EAX
        
       ;the bits 16-23 are the same as the bits 8-15 of A
       ;the bits 24-31 are the same as the bits 0-7 of A 
        mov AX, [a]
        rol AX, 8; rotate AX with 8 bits to the left 
        cwde; convert AX to EAX
        shl EAX, 16; shift to the left 16 bits
        or dword [d], EAX; setting the 16-31bits with EAX // d = 1111 0100 0100 1010 0111 0100 0110 1100b = F44A746C
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
        