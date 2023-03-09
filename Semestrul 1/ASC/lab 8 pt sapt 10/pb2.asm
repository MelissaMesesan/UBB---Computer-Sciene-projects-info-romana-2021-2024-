bits 32 

global start        

extern exit, fopen, fread, printf, fclose
import exit msvcrt.dll   
import fopen msvcrt.dll
import fread msvcrt.dll
import printf msvcrt.dll
import fclose msvcrt.dll



segment data use32 class=data
    output_format db "Numarul de litere mari este: %u", 0
    input_file_name db "input.txt", 0
    acces_mode db "r", 0
    file_descriptor resd 1
    contor_max dd 0
    
    max_length equ 100
    actual_length resd 1
    input_text resb max_length
   
segment code use32 class=code
    start:
        
    ;fopen(input_file_name, acces_mode)
        push acces_mode
        push input_file_name
        call [fopen]
        add esp, 4 * 2
        mov dword[file_descriptor], eax
        cmp eax, 0
        je end_program
        
    ;fread(input_text, 1, max_length, file_descriptor)
        push dword[file_descriptor]
        push max_length
        push 1
        push input_text
        call [fread]
        add esp, 4 * 4
        mov dword[actual_length], eax
    
    ;numaram cate litere mari sunt
    ;literele mari au codul ascii cuprins intre 65-90
        mov ecx, dword[actual_length]
        mov esi, input_text
        cld
        fiecare_litera:
            lodsb
            ;verificam daca in al e litera mare
            cmp al, 65
            jb nu_e_litera_mare
            cmp al, 90
            jbe e_litera_mare
                    
            e_litera_mare:
                inc dword[contor_max]
                
            nu_e_litera_mare:
                loop fiecare_litera
    
    ;printf("Numarul de litere este: %u", contor_max)
        push dword[contor_max]
        push dword output_format
        call [printf]
        add esp, 4 * 2
    
    ;fclose(file_descriptor)
        push dword [file_descriptor]
        call [fclose]
        add esp, 4 * 1
        
    end_program:
    push    dword 0
    call    [exit]