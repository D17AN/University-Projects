bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fclose, fread, printf  ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import fopen msvcrt.dll 
import fread msvcrt.dll 
import fclose msvcrt.dll
import printf msvcrt.dll

; PROBLEM STATEMENT                     
; A text file is given. Read the content of the file, determine the uppercase letter with the 
; highest frequency and display the letter along with its frequency on the screen.
; The name of text file is defined in the data segment.


; our data is declared here (the variables needed by our program)
segment data use32 class=data
    file_name db "fisier.txt", 0
    acces_mode db "r", 0
    file_descriptor dd -1; a reference to the file 
    len equ 1; the maximum number of characters read in a stage
    buffer resb len; the character which is read
    nr_characters dd 0
    format db "%c - %d times", 13, 10, 0
    frequency_array times 26 dd 0; reserve 26 positions for the frequency array
    max1 dd -1
    
    
; our code starts here
segment code use32 class=code
    start:
        push dword acces_mode
        push dword  file_name
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0; if the file was opened then eax != 0, otherwise eax = 0
        je end_program
        mov [file_descriptor], eax; save the value returned by fopen 
        
        my_loop:
            push dword[file_descriptor]
            push dword len
            push dword 1
            push dword buffer
            call [fread]
            add esp, 4*4
            
            cmp eax, 0; in eax will be stored the number of read characters // if it's zero than we reached the end of the file
            je cleanup
            
            mov [nr_characters], eax ; save the number of read characters
            ; instructions
            mov al, byte[buffer]
            cmp al, 'A'; if al < 'A'
            jl end_if
            cmp al, 'Z'; if al > 'Z'
            jg end_if
            valid: ;if 'A' <= al <= 'Z
               sub al, 'A'
               cbw
               cwd
               inc dword[frequency_array + eax*4]
            end_if:
            
            ;end instructions
            jmp my_loop
       
        
        cleanup:
            push dword [file_descriptor]
            call [fclose]
            add esp, 4
        
        ;find the maximum from a frequency array
        mov ecx, 26
        mov esi, 0  
        jecxz end_for1
        start_for1:
            mov ebx,[frequency_array+esi*4]
            cmp ebx, dword[max1]
            jng not_max
            mov dword [max1], ebx
            not_max:
            inc esi 
        loop start_for1
        end_for1:
        
        mov ecx, 26
        mov esi, 0
        mov eax, 'A'  
        jecxz end_for
        start_for:  
            ;printf("%c - %d times", c, d)
            mov ebx,[frequency_array+esi*4]
            cmp ebx, dword[max1]
            jne not_max2
            pushad
            push ebx
            push eax
            push dword format
            call [printf]
            add esp, 4*3
            popad
            not_max2:
            inc eax 
            inc esi 
        loop start_for
        end_for:
        
        end_program:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
