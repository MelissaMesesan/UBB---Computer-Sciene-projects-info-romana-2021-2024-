bits 32
global procedura

segment data use32 class=data
    ; ...
    adr_sir resd 1
    adr_P resd 1
    adr_N resd 1

segment code use32 class=code 
    procedura:
    ; input = (sir, len_sir, sirul N, sirul P)
    ; output = nimic, se modifica sirurile N si P
    mov ebx, [esp + 4]
    mov [adr_sir], ebx
    mov ecx, [esp + 8]
    mov ebx, [esp + 12]
    mov [adr_N], ebx
    mov ebx, [esp + 16]
    mov [adr_P], ebx
    
    jecxz sfarsit
    mov esi, [adr_sir]
    cld
    alt_repeta:
        lodsd
        test eax, 1
        jz par
        
        impar:
            mov [adr_N], eax
            add dword [adr_N], 4
        jmp after
        par:
            mov [adr_P], eax
            add dword [adr_P], 4
        after:
    loop alt_repeta
    sfarsit:
    ret
    