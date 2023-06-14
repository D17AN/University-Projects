bits 32

global _ascii_code
extern printam
segment data use32 class=data
    format dd "%c", 0
    

; our code starts here
segment code use32 class=code
_ascii_code:
    push ebp
    mov ebp, esp
    mov eax, [ebp + 8]
    push eax
    push dword format
    call [printam]
    mov esp, ebp
    pop ebp
    ret 