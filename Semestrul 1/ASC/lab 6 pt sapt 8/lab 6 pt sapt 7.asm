bits 32
global start
extern exit
import exit msvcrt.dll

segment data use32 class=data
    w dw 1432h, 8675h, 0ADBCh
    lenw equ ($-w)/2
    d times lenw dd 0
    help db 0,0,0,0
    
    
segment code use32 class=code
    start:
        mov ecx,lenw  
        CLD     ; parsing from left to right
        mov esi,w       ; esi contains the words from w
        mov edi,d
        repeat1:
            lodsw   ;AX:= the current word from string 
                    ;AH:= 14, AL:= 32
            
            mov bl,ah
            shr bl,4    ; BL:=0000 and the rest of bl ex 14h -> 01h 
            mov dh,bl   ; DH:=0000 and the rest of bl ex 14h -> 01h
            
            mov bl,ah
            shl bl,4    ; BL:= the first byte and 0000 ex 14h -> 10h
            rol bl,4    ; BL:= 0000 and the first byte  ex 10h -> 01h
            mov dl,bl    ; DL:= 0000 and the first byte ex 14h -> 01h
            
            mov bl,al
            shr bl,4    ; BL:=0000 and the rest of bl ex 32h -> 03h
            mov ah,bl   ; AL:=0000 and the rest of bl ex 32h -> 03h
            
            mov bl,al
            shl bl,4    ; BL:= the first byte and 0000 ex 32h -> 20h
            rol bl,4    ; BL:= 0000 and the first byte  ex 20h -> 02h
            mov al,bl   ; AL:= 0000 and the first byte ex 32h -> 02h

            
            push dx
            push ax
            pop  eax
            
            stosd   ;EDI:=EAX 
            
        loop repeat1

            
            
                
    push dword 0
    call [exit]
    
    ; exit loop does not work 