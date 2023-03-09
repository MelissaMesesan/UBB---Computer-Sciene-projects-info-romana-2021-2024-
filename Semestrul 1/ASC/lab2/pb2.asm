bits 32 

global start        


extern exit               
import exit msvcrt.dll    

segment data use32 class=data
    
    a db 1
    b db 2
    c db 3
    d db 4

segment code use32 class=code

        ;a+13-c+d-7+b
    start:
        
        mov al, [a]     ; al = a
        add al, 13      ; al = a + 13
        
        sub al, [c]     ; al = a + 13 - c
        
        add al, [d]     ; al = a + 13 - c + d
        
        sub al, 7       ; al = a + 13 - c + d - 7
        
        add al, [b]     ; al = a + 13 - c + d - 7 + b
        
            ; rezultatul in al
        
        
        push    dword 0      
        call    [exit]       
