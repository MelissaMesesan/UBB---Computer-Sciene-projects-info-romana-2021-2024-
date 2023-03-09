bits 32 

global start        

extern exit               
import exit msvcrt.dll    


segment data use32 class=data

    a db 10
    b dw 8
    c dd 6
    d dq -78
    val1 resw 1
    val2 resq 1
    val3 resq 1
    val4 resq 1

segment code use32 class=code

    ; 29. (a+a)-(b+b)-(c+d)+(d+d)       a - byte, b - word, c - double word, d - qword - Interpretare cu semn

    start:
        
        ; a+a
        mov al, [a]     ; al = a
        add al, [a]     ; al = a + a
        cbw             ; conversie la word
        
        ;b+b
        mov bx, [b]     ; bx = b
        add bx, [b]     ; bx = b + b
        
        ;(a+a)-(b+b)
        sub ax, bx      ; ax = ax - bx
        mov [val1], ax  ; val1 = ax
        
        ;c+d
        mov ax, [c]     ; dx:ax = c
        cdq             ; conversie la qword
        
        mov ebx, [d]    ; ecx:ebx = d
        add eax, ebx    ; edx+ecx+CF : eax+ebx
        adc edx, ecx
        
        ;(c+d)+(d+d)
        add eax, ebx    ; edx+ecx+CF : eax+ebx
        adc edx, ecx
        add eax, ebx    ; edx+ecx+CF : eax+ebx
        adc edx, ecx
        
        ;(a+a)-(b+b)-(c+d)+(d+d)
        mov ebx, eax    ; ebx = c+d+d+d
        
        mov ax, [val1]  ; ax = (a+a)-(b+b)
        cwd
        cdq
        sub eax, ebx    ;edx-ecx-CF : eax-ebx
        sbb edx, ecx
                        ; rezultatul eax
        
        
        
        
        
        
        
        
        
         
        
    
    
        push    dword 0      
