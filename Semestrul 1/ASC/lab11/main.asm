bits 32
global start

extern exit, fscanf, fopen, fclose, printf, procedura
import exit msvcrt.dll
import fscanf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll

segment data use32 class=code

    sir times 101 dd 0
    N times 101 dd 0
    P times 101 dd 0
    nume_fisier db "numere.txt", 0
    mod_acces db "r", 0
    format db '%u', 0
    format_afisare db '%u ', 0
    new_line db 10, 13, 0
    descriptor dd -1
    citit resd 1
    len_sir dd 0
    index_n dd N
    index_p dd P
    
    ; 27. Se citesc din fisierul numere.txt mai multe numere (pare si impare). 
    ; Sa se creeze 2 siruri rezultat N si Pastfel:
    ; N - doar numere impare si P - doar numere pare. Afisati cele 2 siruri rezultate pe ecran.
    
segment code use32 class=code
    start:
        ; ...
        ; fopen("numere.txt", "r")
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0
        je final
        mov [descriptor], eax
        
        cld
        mov edi, sir
        repeta:
            ; fscanf(descriptor, format, citit)
            push dword citit
            push dword format
            push dword [descriptor]
            call [fscanf]
            add esp, 4*3
        
            cmp eax, -1
            je peste
            
            mov eax, [citit]
            stosd
            inc dword [len_sir]
        jmp repeta
        
        peste:
        procedura(sir, len_sir, sir_N, sir_P)
        push dword P
        push dword N 
        push dword [len_sir]
        push dword sir
        call procedura
        add esp, 4*4
        
        cld
        ; printf(N)
        mov esi, N
        iar_repeta:
            lodsd
            cmp eax, 0
            je dupa
            
            push dword eax
            push dword format_afisare
            call [printf]
            add esp, 4*2
        jmp iar_repeta
        
        dupa:
        ; print(new_line)
        push new_line
        call [printf]
        add esp, 4
        
        ; printf(P)
        mov esi, P
        inca_un_repeta:
            lodsd
            cmp eax, 0
            je aici
            
            push dword eax
            push dword format_afisare
            call [printf]
            add esp, 4*2
        jmp inca_un_repeta
        
        aici:
        ; fclose(descriptor)
        push dword [descriptor]
        call [fclose]
        add esp, 4
        
        final:
        ; exit(0)
        push    dword 0
        call    [exit]
