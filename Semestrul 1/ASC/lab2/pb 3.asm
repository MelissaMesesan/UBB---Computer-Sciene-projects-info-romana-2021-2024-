bits 32 

global start        

extern exit               
import exit msvcrt.dll    

segment data use32 class=data
    
    ;(a+b+b)+(c-d)
    
    
    a dw 1
    b dw 2
    c dw 3
    d dw 4
    
    
segment code use32 class=code
    start:
        
        ; a + b + b
        
        mov ax, word [a]    ; ax = a
        add ax, word [b]    ; ax = a + b
        add ax, word [b]    ; ax = a + b + b
        
        ; c - d
        add bx, word [c]    ; bx = c
        sub bx, word [d]    ; bx = c - d
        
        ; ( a + b + b ) + ( c - d )
        add ax, bx          ; ax = ax + bx
        
            ;rezultatul in ax
        
        
        push    dword 0      
        call    [exit]       
