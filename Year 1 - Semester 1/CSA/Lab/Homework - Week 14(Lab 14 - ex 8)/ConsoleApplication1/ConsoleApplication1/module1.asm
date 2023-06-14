bits 32

global _base_8
extern printam
segment data use32 class=data
    format dd "%o", 0
    

; our code starts here
segment code use32 class=code
_base_8:
    push ebp
    mov ebp, esp
    mov eax, [ebp + 8]
    push eax
    push dword format
    call [printam]
    mov esp, ebp
    pop ebp
    ret 