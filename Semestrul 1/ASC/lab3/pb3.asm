bits 32 

global start        

extern exit               
import exit msvcrt.dll    

segment data use32 class=data

    a db 3
    b db 7
    c db 4
    d dd 3
    x dq 1

segment code use32 class=code
    start:
    ;29. (a+b)/(c-2)-d+2-x;     a,b,c-byte; d-doubleword; x-qword       - FARA SEMN
    
    ; a + b
    
    mov al, [a]     ; al = a
    add al, [b]     ; al = al + b = a + b
    mov bl, [c]     ; bl = c
    
    ; c - 2
    
    sub bl, 2       ; bl = bl - 2 = c - 2
    mov ah, 0       ; ah = 0
    
    ;(a+b)/(c-2)
    
    div byte bl     ; al = (a+b)/(c-2)
    
    mov ah, 0       ; ah = 0 -> conversie la word
    mov dx, 0       ; dx = 0 -> conversie la doubleword
    
    ;(a+b)/(c-2)-d
    
    mov ebx, [d]    ; ebx = d
    sub eax, ebx    ; eax =eax - ebx 
    
    ;(a+b)/(c-2)-d+2
    
    add eax, 2      ; eax = eax + 2
    mov edx, 0      ; edx = 0 -> conversie din doubleword in qword
    
    ;(a+b)/(c-2)-d+2-x
    
    mov ebx, [x]    ; ebx = x
    sub eax, ebx    ; edx-ecx-cf : eax-ebx
    sbb edx, ecx
    
    
    
        push    dword 0      
        call    [exit]       
