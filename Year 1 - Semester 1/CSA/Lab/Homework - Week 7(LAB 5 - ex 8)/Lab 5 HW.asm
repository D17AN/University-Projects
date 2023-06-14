bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

;A character string S is given. Obtain the string D that contains all capital letters of the string S
;Example:
;S: 'a', 'A', 'b', 'B', '2', '%', 'x', 'M'
;D: 'A', 'B', 'M'

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    S db 'a', 'A', 'b', 'B', '2', '%', 'x', 'M'; declare string of bytes 
    lenght equ $-S; compute the lenght of the string in lenght
    D times lenght db 0; reserve lenght bytes for the destination string and initialize it

; our code starts here
segment code use32 class=code
    start:
        mov ecx, lenght
        mov esi, 0; esi -> represents the current index in string S
        mov edx, 0; edx -> represents the current index of string D
        
        jecxz end_program
        repeat_label:
                mov al, [S+esi]; al = S at the index esi 
                cmp al, 'A'; if al < 'A'
                jl end_if
                cmp al, 'Z'; if al > 'Z'
                jg end_if
                valid: ;if 'A' <= al <= 'Z'
                   mov [D + edx], al 
                   inc edx
                end_if:
                inc esi
        loop repeat_label
        end_program: ; end of the program
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
