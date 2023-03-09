bits 32 

global start        

extern exit               
import exit msvcrt.dll    


segment data use32 class=data
    
    a db 10
    b dw 2
    c dd 8
    d dq 4


segment code use32 class=code

    ;29. d+c-b+(a-c)    a - byte, b - word, c - double word, d - qword - Interpretare fara semn

    start:
        
        ;a - c      a - byte, c - double word
        
    mov al, [a]     ; al = a-c
    mov ah, 0       ; ah = 0    ; ax = 0000 1010
    mov bx, [c]     ; bx = c
    
    sub ax, bx      ;         dx:ax -
    sbb dx, cx      ;         cx:bx
                    ;------------------------
                    ; CF + dx + cx : ax + bx
    push dx
    push ax
    pop eax      
    
    mov ecx, eax    ; ecx = a-c
    
        ; c + d     c - double word, d - qword
    
    mov ebx, [d]    ; ebx = d
    mov ax, [c]     ; ax = c
    cdq             ; convert double word to qword => edx:eax = c
    add ebx, eax    ; ebx = ebx + eax = c + d
    
        ; d + c - b
    
    mov ax, [b]     ; ax = b
    cwd             ; convert word to double word
    cdq             ; convert double word to qword => edx:eax = b
    sub ebx, eax    ; ebx = d + c - b
    
        ;d + c - b + ( a - c )
        
    mov eax, ecx    ; eax = a - c
    cdq             ; convert double word to qword
    add eax, ebx    ; eax = eax + ebx => d+c-b+(a-c)
    adc edx, ecx
                    ;rezultatul in eax
  
        push    dword 0      
        call    [exit]      
