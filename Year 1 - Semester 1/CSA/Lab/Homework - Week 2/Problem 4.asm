bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; a,b,c - byte, d - word
    d dw 5025
    

; our code starts here
segment code use32 class=code
    start:
        ;[100*(d+3)-10]/d = [100*(500+3)-10]/500 = (100*503 - 10)/500 = (50300 - 10)/500 = 50290/500 = 100, remainder = 290
        mov AX, 100 ; moving to the AX the value 100
        mov DX, [d] ; moving to DX, the value d 
        add DX, 3   ; adding to the register DX, value 3  
        mul DX ; DX:AX = AX * DX
        
        push  DX ;the high part of the doubleword DX:AX is saved on the stack
        push  AX ;the low part of the doubleword DX:AX is saved on the stack
        pop  EAX 
        
        sub EAX, 10  ; subracting from the register AX value 10
        
        push EAX
        pop AX
        pop DX
        
        mov BX, [d]; moving to BX value d 
        div BX  ; dividing DX:AX with BX, and the value will be stored in AX(integer part in AX, fractional part in DX)
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
