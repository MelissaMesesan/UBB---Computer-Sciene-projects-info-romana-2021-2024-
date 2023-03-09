bits 32 
global start        

extern exit               
import exit msvcrt.dll    
segment data use32 class=data
   s dw 3412h, 8675h, 0dacbh, 1546h
   len equ ($-s)/2 
   d times len resd 0
   
;2. Se da un sir de cuvinte. Sa se obtina din acesta un sir de dublucuvinte,
;   in care fiecare dublucuvant va contine nibble-urile despachetate pe octet 
;   (fiecare cifra hexa va fi precedata de un 0), 
;   aranjate crescator in interiorul dublucuvantului.

segment code use32 class=code
    start:
        mov ecx, len    ; lungimea, de cate ori vrem sa facem "repeta"
        jecxz final
        mov esi, s      ; sirul s
        mov edi, d      ; rezultatul de dublucuvinte
        cld             ; incepem de la stanga la dreapta
        
        repeta:
        
            ; izolam fiecare cifra in cate un registru (bl, bh, dl, dh)
            lodsw                   
            mov bl, al              ; bl
            and bl, 0000_1111b
            mov bh, al              ; bh
            and bh, 1111_0000b
            shr bh, 4
            mov dl, ah              ; dl
            and dl, 0000_1111b
            mov dh, ah              ; dh
            and dh, 1111_0000b 
            shr dh, 4   
            
            ; facem comparari pentru ordonare
            ; comparam fiecare registru cu fiecare registru
            ; la final vrem sa fie: bl, bh, dl, dh
            cmp bh, bl          ; comparam bl cu bh 
            jna step1            ; daca bl e mai mare sarim la urmatorul pas: (bh<bl), adica cum ne dorim
            xchg bl, bh         ; interschimbam pozitiile
            
            step1:
            cmp dl, bl          ; comparam bl cu dl
            jna step2 
            xchg bl, dl 
            
            step2:
            cmp dh, bl          ; comparam bl cu dh
            jna step3
            xchg bl, dh 
            
            step3:
            cmp dl, bh        ; comparam bh cu dl
            jna step4
            xchg bh, dl 
            
            step4:
            cmp dh, bh          ; comparam bh cu dh
            jna step5 
            xchg bh, dh 
            
            step5:              
            cmp dh, dl          ; comparam  dl cu dh
            jna gata
            xchg dl, dh         
            
            gata:       ; gata, cifrele sunt ordonate
            
            ;creem in eax dublucuvantul sub forma 0_bl_0_bh_0_dl_0_dh
            mov eax, 0
            add al, bl 
            shl eax, 8
            add al, bh
            shl eax, 8
            add al, dl 
            shl eax, 8
            add al, dh       
            
            stosd       
        loop repeta     ; repetam pentru fiecare word in parte
        
        final:
        push    dword 0      
        call    [exit]