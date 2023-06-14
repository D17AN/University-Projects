bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
     a db 3
     b db 100
     c db 64h
     d dw 70 ; 00 46h -> in mem 46 00 
     e dw 1000    ; 03 E8  in hexa
     
     a1 dd 5500
     a2 dd 2000

    ten EQU 10     

    f dq 1122334455667788h
    
; our code starts here
segment code use32 class=code
    start:

        ;          EAX -32 bits
        ;            |      AX - 16 bits
        ;            |   AH  |    AL    ( 8 bits each)
        
        
        ; EBX, ECX, EDX, ESP, EBP, ESI, EDI
    
      ;  mov AL, [a] 
      ;  add AL, [b] ; AL<- AL+b = a+b =103
        
      ;  mov AX, [d]
      ;  mov BX, [e] 
      ;  add BX, AX ; BX<- BX+AX=e+d = 1070 
    
      ;  mov EAX, dword [a1]
      ;  add EAX, [a2] ; EAX = a1+a2
    
    ; a1-a2
    ;    mov EAX, [a1]
    ;    sub EAX, [a2] ; EAX <- EAX-a2 = a1-a2 =3500
    
    ;    inc EAX ; EAX = 3501
    ;    dec EAX; EAX = 3500
        
    ;    inc byte [a] ; a=4
    ;    dec byte [a] ; a=3
        
    ;    neg byte [a] ; a=-3
    ;    neg word [a] ; ? a=3???
    
    ;byte+byte=  1 byte
    
    
    ; byte*byte= word
    ; w*w= dword
    ; dw*dw= qw
    
    ;a*b 
        mov AL, [b]
        mul byte [a] ;   AX  <- AL* a = b*a = 300
    
    ;             DX:AX <- AX * w 
    ; d*e 
        mov AX, [d]
        mov BX, [e] 
        mul BX ;   DX:AX <- AX* BX =d*e = 70 000 =>  0001 1170 h 
        
        ; DX:AX into EAX 
        push DX
        push AX
        pop EAX
        
    
    ;   dw*dw = 
        mov EAX , [a1]
        mul dword [a2] ; EDX:EAX <- EAX* a2 = 11000000
    
    ;  double size / size = size 
    ; word / byte -> byte  remainder byte 
    ; dw / w -> w 
    ; qw/ dw -> dw 
    ; d/a ( word/byte)
        mov AX, [d]
        div byte [a] ; AL  <- AX / a  ; AH <- AX % a 
                                  ; d/a ; 70/3 ; AL = 23; AH= 1
    
    ;   a1 (dw) / e (w)
        mov EBX, [a1]
        push EBX
        pop AX
        pop DX ; DX:AX = EBX = a1
        
        div word [e] ;  AX <- DX:AX / e   ;  DX<- DX:AX % e
                        ; Ax =5       ; DX=500
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
     

     
        
        
         ;   mov AL, byte [a]
     ;   add AL, [b] ; AL<- a+b =103
    
     ;   mov BX, word [d]
     ;   mov CX, word [e]
     ;   add BX, CX ; BX<- BX+CX = d+e =1007
    
     ;   mov EAX, [a1]
     ;   mov EBX, [a2]
     ;   add EBX, EAX; EBX <- EBX+EAX 
    
    ; a1-a2 
     ;   mov EAX, [a1]
     ;   mov EBX, [a2]
     ;   sub EAX, EBX ; EAX<- EAX-EBX = 5500-2000=3500
    
      ;  inc EAX ; 3501
      ;  dec EAX ; 3500
        
     ;   dec byte [a] ; a=2
     ;   neg byte [a] ; a=-2; feh
        
     ;   neg word [a] 
    
    ; EAX   , AX, AL 
    ; s * s -> double s
    ; a* b (bytes) - > word 
    ; AL * x -> AX
    ;    mov AL, [a]
    ;    mul byte [b]; AX<- AL* b = a*b = 3*100=300
    
    ; d* e (words)
    ;(dword) DX:AX <- AX* op16
    ;    mov AX, [d]
    ;    mov BX, [e]
    ;    mul BX ; DX:AX <- Ax* BX= d*e = 7 000 000 ->  006A CFC0h 
        
        ; DX:AX into EAX
    ;    push DX
    ;    push AX
    ;    pop EAX
        
    ; a1*a2 (dwords) 
    ; (quad) EDX:EAX <- EAX*op32
    ;    mov EAX, [a1]
    ;    mul dword [a2] ; EDX: EAX <- EAX* a2 = 5500*2000
    
    ; double s / s -> s
    ; word / byte -> byte quitient ;  remainder
    ; d/a word/byte
    ;    mov AX, [d]
    ;    div byte [a] ;  Al<- AX/a   AH<- AX%a  70/3 = 23 r 1
    
    ; dword / word   a2/e ; DX:AX / word   AX-qut  DX - remainder
    ;    mov EBX, [a2] 
    ;    push EBX
    ;    pop AX
    ;    pop DX        
    ;    div word [e] ; DX:AX / e      AX=a2/e DX a2%e
    
    
    ; qword/ dword ;   EDX:EAX / EAX ; quot in EAX and remain EDX
    
