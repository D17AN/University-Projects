
bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import printf msvcrt.dll
;A list of doublewords is given. 
;Obtain the list made out of the low bytes of the high words of each doubleword 
;from the given list with the property that these bytes are palindromes in base 10

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ;s DD 12345678h, 1A2C3C4Dh, 98FCDC76h
    ;d DB 2Ch, FCh.
    s dd 12345678h, 1A2C3C4Dh, 98FCDC76h
    s_len equ ($-s)/4
    d times s_len db 0
    ten db 10
    quotient1 resb 1
    remainder1 resb 1
    remainder2 resw 1
    nr_digits1 resb 1
    nr_digits2 resb 1
  
    
; our code starts here
segment code use32 class=code
    start:
        mov esi, s; esi = s 
        mov edi, d; edi = d 
        mov ecx, s_len; ecx = lenght of string s  
        cld;clear direction flag 
        
        for1_label:
            cmp ecx, 0
            je end_for1
            lodsd; eax = the double word from <ds:esi> loaded in EAX 
            ror eax, 16; rotate eax with 16 bits to right
            mov bl, al; bl = al 
            mov eax, 0; eax = 0
            mov al, bl; al = bl
            mov byte[nr_digits1], 0
            split_digits:
                mov ah, 0
                div byte[ten]; al = ax / 10, ah = ax % 10
                mov byte[quotient1], al; quotient1 = al 
                mov byte[remainder1], ah; remainder1 = ah
                mov al, byte[remainder1]; al  = remainder1 // here shit happens
                mov ah, 0
                push ax; push on the stack ax(the remainder)
                mov ax, 0; reseting the value of ax
                mov al, byte[quotient1];al = quotient1, al takes its initial value after the division with ten
                inc byte[nr_digits1]; counting the number of digits of the number
                cmp al, 0; if al != 0 -> repeat the process
                jne split_digits
            mov al, bl; al = bl
            mov byte[nr_digits2], 0
            Pal:
                mov ah, 0
                div byte[ten]; al = ax / 10, ah = ax % 10
                mov byte[quotient1], al; quotient1 = al
                mov byte[remainder1], ah; remainder1 = ah
                mov al, byte[remainder1]; al = remainder1 
                mov ah, 0
                pop dx; take from the stack the complement digit of the current digit from the current number
                cmp ax, dx; if both digits share the same value, then we inc nr_digits2
                jne isnotvalid
                isvalid:
                    inc byte[nr_digits2]
                isnotvalid:
                mov ax, 0; reseting the value of ax
                mov al, byte[quotient1]; reseting the initial value of al after the division with 10
                cmp al, 0; if al != 0 -> repeat the process
                jne Pal
            mov al, byte[nr_digits1]
            mov dl, byte[nr_digits2]
            cmp al, dl; if the number is not a palindrome
            jne isnotpalindrome
            ispalindrome:
                mov al, bl; al = bl
                stosb; <DS:EDI>  = al // add the palindrome to string d
            isnotpalindrome:
            dec ecx
            jmp for1_label
            
        end_for1:
               
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
