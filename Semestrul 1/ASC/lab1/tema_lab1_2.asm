bits 32 

global start        


extern exit               
import exit msvcrt.dll    

segment data use32 class=data
    
    a db 12
    b db 2
    ;c db 3
    d db 4

segment code use32 class=code

        ;a+13-c+d-7+b
    start:
        
        mov ax, a    ; ax = a
        add ax, 13      ; ax = a + 13
        ;mov bx, [c]
        ;sub ax, bx
        ;mov bx, [d]
        ;add ax, bx
        ;sub ax, 7
        ;mov bx, [b]
        ;add ax, bx
        
        push    dword 0      
        call    [exit]       
