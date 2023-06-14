bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, scanf, printf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import scanf msvcrt.dll
import printf msvcrt.dll
;A natural number a (a: dword, defined in the data segment) is given. 
;Read a natural number b from the keyboard and calculate: a + a/b. 
;Display the result of this operation. The values will be displayed in decimal format (base 10) with sign.
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a dd 20
    b dd 0
    format_message db "b = ", 0
    format db "%d", 0
    message db "%d + %d/%d = %d", 0
    error_message db "division with zero forbidden!", 0
    
; our code starts here
segment code use32 class=code
    start:
        push dword format_message
        call [printf]
        add esp, 4*1
        
        push dword b
        push dword format 
        call [scanf]
        add esp, 4*2
        
        mov eax, dword[b]
        cmp eax, 0
        je ZeroDivision
        
        clc
        mov eax, dword[a]
        cdq; eax -> edx:eax
        idiv dword[b]; eax = edx:eax / b, edx = edx:eax % b
        adc eax, dword[a]; eax = a + eax = a + a / b 
        
        push eax
        push dword[b]
        push dword[a]
        push dword[a]
        push dword message
        call [printf]
        add esp, 4*5
          
        ;exit(0)
        push dword 0
        call [exit] 
        
        ZeroDivision:
        push error_message
        call[printf]
     
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
