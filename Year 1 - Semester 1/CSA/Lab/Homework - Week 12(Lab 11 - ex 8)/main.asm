bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        
extern base_8_and_ascii_code
extern printf
import printf msvcrt.dll
; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    msg1 db "Buna dimineata,", 13, 10, "Fie ca razele soarelui sa va mangaie fata!", 13, 10, 0
    msg db "%d is %o in base 8 and %c in ascii code", 13, 10, 0
    
segment code use32 class=code
    start:
        ; ...
        push dword msg1
        call[printf]
        add esp, 4
        
        mov ecx, 32
        start_for:
            cmp ecx, 126
            jg end_for
            
            
            push ecx
            call base_8_and_ascii_code
            
            inc ecx
            jmp start_for
        end_for:
         
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
