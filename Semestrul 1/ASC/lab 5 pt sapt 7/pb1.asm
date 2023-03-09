bits 32 

global start        

extern exit               
import exit msvcrt.dll    

segment data use32 class=data

; 1. Se da un sir de octeti S de lungime l. 
;    Sa se construiasca sirul D de lungime l-1 astfel incat 
;    elementele din D sa reprezinte produsul 
;    dintre fiecare 2 elemente consecutive S(i) si S(i+1) din S.

    s db 1, 2, 3, 4
    l equ $-s-1           ; stabilirea lungimii initiale a sirului l
    d times l-1 dw 0      ; rezervarea unui spatiu de dimensiune l-1 pentru sirul destinatie d si initializarea acestuia

segment code use32 class=code
    start:
    
        mov ecx, l  ; ecx primeste lungimea pentru a putea face loop de ecx ori
        mov esi, 0
        jecxz Sfarsit
        Repeta:
            mov al, [s+esi]     ; primul numar
            mov bl, [s+1+esi]   ; al doilea numar    
            mul bl              ; inmultire intre primul si al doilea element
            mov [d+esi], ax     ; rezultatul
            inc esi
        loop Repeta
        
        Sfarsit     ; se termina programul
    
        push    dword 0      
        call    [exit]       
