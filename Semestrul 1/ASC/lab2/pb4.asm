bits 32 

global start        

extern exit               
import exit msvcrt.dll    


segment data use32 class=data

    a db 6
    b db 4
    c db 2
    d dw 4
    var db 2
    var2 db 4

segment code use32 class=code
    start:
    
    ;(a+b)/2 + (10-a/c)+b/4
    
    mov al, byte [a]    ; al = a
    add al, byte [b]    ; al = a + b
    mov ah, 0
    
    div byte [var]      ; al = ax / 2, ah = ax % 2
    
    mov bl, al          ; bl = a + b / 2
    
    mov al, byte [a]    ; al =  a
    mov ah, 0
    div byte [c]        ; al = a / c, ah = bx % c
    
    mov cl, 10          ; cl = 10
    
    sub cl, al          ; cl = cl - al =  10 - a/c
    
    add bl, cl          ; a+b/2 + (10-a/c)
    
	mov al, byte [b]    ; al=b
	mov ah, 0
	div byte [var2]     ; al = b/4 , ah = b%4
	
	add al, bl          ; al = b/4 + a+b/2 + (10-a/c) 
    
        ; rezultatul in al
  
    
        push    dword 0      
        call    [exit]       
