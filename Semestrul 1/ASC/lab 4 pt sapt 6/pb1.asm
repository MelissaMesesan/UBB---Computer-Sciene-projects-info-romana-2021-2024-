bits 32 

global start        

extern exit               
import exit msvcrt.dll    

segment data use32 class=data

; 16.
    ;Se dau octetul A si cuvantul B. Sa se obtina dublucuvantul C:
    ;bitii 0-7 ai lui C au valoarea 1
    ;bitii 8-11 ai lui C coincid cu bitii 4-7 ai lui A
    ;bitii 12-19 coincid cu bitii 2-9 ai lui B
    ;bitii 20-23 coincid cu bitii 0-3 ai lui A
    ;bitii 24-31 coincid cu octetului high din cuvantul B
    
    a db 9fh
    b dw 0af9ah
    c dd 0    ;affe 69ff
    
segment code use32 class=code
    start:
    
    mov ebx, 0                   ; formam cuvantul c in ebx
    
    ; - bitii 0-7 ai lui C au valoarea 1
    
    or ebx, 0000000011111111b
    
    ; - bitii 8-11 ai lui C coincid cu bitii 4-7 ai lui A
    
    mov eax, 0
    mov al, [a]                 ; al = a
    and eax, 11110000b          ; se izoleaza bitii 4-7 a lui A
    rol eax, 4                  ; deplasare la stanga cu 3 biti
    or ebx, eax                 ; concatenare
    
    ; - bitii 12-19 coincid cu bitii 2-9 ai lui B
    
    mov eax, 0
    mov ax, [b]                 ; ax = b
    and eax, 0000001111111100b  ; se izoleaza bitii 2-9 a lui B
    rol eax, 10                  ; deplasare la stanga cu 3 biti
    or ebx, eax                 ; concatenare
    
    ; - bitii 20-23 coincid cu bitii 0-3 ai lui A
    
    mov eax, 0
    mov al, [a]                 ; al = a
    and eax, 00001111b          ; se izoleaza bitii 0-3 a lui A
    rol eax, 20                 ; deplasare la stanga cu 10 biti
    or ebx, eax                 ; concatenare
    
    ; - bitii 24-31 coincid cu octetului high (4-7) din cuvantul B
    
    mov eax, 0
    mov ax, [b]                 ; ax = b
    and eax, 1111111100000000b  ; se izoleaza octetul hign din B 
    rol eax, 16                 ; se deplaseaza la stanga cu 24 biti
    or ebx, eax                 ; concatenare
    
    ; rezultatul in ebx ( dublul cuvantul C se afla in ebx )
    
        push    dword 0      
        call    [exit]       
