bits 32

global base_8_and_ascii_code
extern printf
import printf msvcrt.dll


segment data use32 class=data
    msg db "%d is %o in base 8 and %c in ascii code", 13, 10, 0
    

segment code use32 class=code   
;base_8_and_ascii_code(int value)
; Display the parameter it gets on the screen
; parameters:
;   - value : the value which must be displayed in base 8 and as a character(in ASCII code)
; register eax it's used for retaining the value of the parameter 

base_8_and_ascii_code:
    mov eax, [esp + 4]     
    pushad ; we save the content of the registers on the stack
    push eax
    push eax
    push eax
    push dword msg
    call[printf]
    add esp, 16
    popad ; we reassign original values to the registers
    
    ret 4; free the stack of the parameter which was used in the subroutine 
        
        
        
        
        
        
    
    
    