bits 32 
global start        

extern exit      
import exit msvcrt.dll 

segment data use32 class=data
        a dw 10
        b dw -5 ;   1111 1111 1111 1011 idiv -5 
        c db -3 ; imul   1111 1101  
        d db 10
        e dd 7890abcdh    ; 78 90 ab cd number
               ; in memory  cd ab 90 78 
                mov ebx, dword [e] ; take 4 byte from address e 
                ; put in register in number form (transform from little endian) EBX = 78 90 ab cd 
                ; load in e in BX:CX =78 90 ab cd ; BX=78 90 CX =ab cd
                mov CX, word [e]; take 2 bytes CX= ab cd 
                mov BX, [e + 2]; BX= 78 90
                        
                          
segment code use32 class=code
    start:
       
       byte+byte=byte  
          . ...
       1000 1111 +
       1000 1111
       --------------
       0001 1110   CF=1
         
        AH:AL (AX) +
        BH:BL (BX)
        ----------
 (AH+BH+CF):(AL=AL+BL and set CF to 0 or 1)         
        
        add AX, BX ; AX<- AX+BX
    
        add AL, BL ; (AL=AL+BL and set CF to 0 or 1) 
        adc AH, BH ; (AH=AH+BH+CF)
    
    
    
    ;    DX:AX    double
    ;    00 BX   word -> double
    
              0000 0000 1010 1100
    
    ; unsigned, CX=0
    ; result DX:AX<- DX:AX +BX
        
        add AX, BX ; AX<- AX+BX, set CF
        adc DX, 0 ; DX<- DX+ 0 + CF
       
    ;    DX:AX 
    ;    CX:BX , CX=0
        mov CX, 0
        add AX, BX ; AX<- AX+BX, set CF
        adc DX, CX ; DX<- DX+ CX + CF
        
        ;a/b word/word no
        ; a-< double DX:AX /word yes
        ;unsigned
        mov AX, [a]   ;   
        mov DX, 0 ; DX:AX = a  
        div word [b] ; Ax<- DX:AX/b  rem in dx  
        
        
        ;signed
        mov AX, [a]   ;   
        cwd ; DX:AX=a
        idiv word [b] ; 10/-5  AX=-2
                   
                    0000 0000 0000 0001 (1) word 00
                    1111 1111 1111 1111 (-1)     ffff

                   
            
        ;AX=a ; byte [-128, 127]  , word [-32000, 32000]
       
       mov AL, [c]
       cbw ; AX<- c 
        
        mov AX, [a]
        cwd ; DX:AX=a
        idiv word [b] ; AX<-a/b DX<- a%b 
        
        ;1  e+ BX ?  double + word 
         mov AX, BX
         cwd ; DX:AX 
        ; load e in BX:CX 
        ;   BX:CX = 7890 abcd   ; BX=78 90  CX= ab cd 
                        ;  mov eax, [e] ; eax=78 90 ab cd 
                          mov cx , [e] ; cx =ab cd
                          mov bx, [e+2] ;  bx = 78 90
        ; DX:AX + BX:CX
        add AX, CX
        adc DX, BX
        
        
        ;2  e+ BX ?  double + word 
         mov AX, BX
         cwde ; EAX 
        ; mov ECX, [e] 
         add EAX, [e] ;rez in  EAX
        
             unsigned       |      signed
                   add, sub, adc, sbb
             div, mul             idiv, imul
             mov ah, 0            cbw
             mov dx, 0            cwd ; dx:ax 
             mov edx, 0           cdq ; edx:eax 
            {mov dx, 0            cwde; ax -> eax
             push dx
             push ax
             pop eax    }
             
         ; e (double) + EDX:EAX  (quad)   
         ; unsigned 
         mov EBX, [e]
         mov ECX, 0  ; ECX:EBX +EDX:EAX           
         add EBX, EAX 
         adc ECX, EDX ; ECX:EBX = e+ EDX:EAX

         ; signed       EDX:EAX  - e     
         mov EBX, EAX ; save result to use EAX for conversion
         mov ECX, EDX ; ECX:EBX=EDX:EAX 
         mov EAX , [e]
         cdq ; EDX:EAX=e
         ;ECX:EBX - EDX:EAX
         sub EBX, EAX   ; EBX=EBX-EAX and set CF 
         sbb ECX, EDX ; ECX= ECX-EDX-CF 
           .  .... ..
           1  0000 0001 -
              0000 0010
             ----------
    CF=1      1111 1111
             
             
             
        ; exit(0)
        push    dword 0   
        call    [exit]  
