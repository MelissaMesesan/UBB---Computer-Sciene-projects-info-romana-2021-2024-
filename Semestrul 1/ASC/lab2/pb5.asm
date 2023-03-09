bits 32 ; 


global start        

extern exit               
import exit msvcrt.dll    

segment data use32 class=data
    
    a db 3
    e dw 1
    f dw 2

segment code use32 class=code

    ;a*a-(e+f)
    
    start:
    
    mov al, [a]     ; al = a
    mul byte [a]    ; al = al * a
    
    mov bl, [e]     ; bl = e
    add bl, [f]     ; bl = e + f

    sub al, bl      ; al = al - bl
    
        ; rezultatul in al
    
        push    dword 0      
        call    [exit]       
