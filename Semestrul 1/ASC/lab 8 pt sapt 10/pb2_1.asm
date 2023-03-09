bits 32 

global start        


extern exit, fopen, fclose, fread, printf
import exit msvcrt.dll 
import fopen msvcrt.dll 
import fread msvcrt.dll 
import fclose msvcrt.dll 
import printf msvcrt.dll


segment data use32 class=data
    nume_fisier db "input.txt", 0   ; numele fisierului
    mod_acces db "r", 0             ; r for reading
    descriptor_fis dd -1            ; identificatoruk
    nr_car_citite dd 0              ; numarul de caractere pe care le citip la un pas
    len equ 100                     ; numarul maxim de elemente citite din fisier intr-o etapa
    buffer resb len                 ; sirul in care se va citi textul din fisier
    format db "Am citit %d caractere din fisier. Textul e: %s ",10, 0
    format_final db "Litera mare e: %c si apare de %d ori", 0
    character db 0FFh
    len2 equ 256
    ascii_table resb len2
    final_character dd 0
    nr_final dd 0
    nr db 0 
    format_test db "%c", 0
    
    ;Se da un fisier text. 
    ;Sa se citeasca continutul fisierului, sa se determine litera mare (uppercase) 
    ;cu cea mai mare frecventa si sa se afiseze acea litera, impreuna cu frecventa acesteia. 
    ;Numele fisierului text este definit in segmentul de date.

segment code use32 class=code
    start:
        
        ; eax = fopen(nume_fisier, mod_acces)
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 4*2
        
        ; verificam daca fisierul e gol
        cmp eax, 0                  
        je final
        
        mov [descriptor_fis], eax   ; textul e salvat in descriptor_fis
        

        bucla:
            ; citim 100 de caractere odata
            ; eax = fread(buffer, 1, len, descriptor_fis)
            push dword [descriptor_fis]
            push dword len
            push dword 1
            push dword buffer
            call [fread]
            add esp, 4*4
            
            ; eax = numarul de biti pe care ii citim
            cmp eax, 0          ; daca numarul e 0 ne oprim si verificam frecventa
            je frequency

            mov [nr_car_citite], eax        ; salvam numarul de caractere in nr_car_citite
            
            ; procesarea caracterelor:
            ; ascii_table = frequency array with 256 bytes(1byte = 1ascii character) 
            mov ecx, 0
            mov ecx, [nr_car_citite]
            mov edx, 0

            start_loop2:
                ;luam ficare caracter si adaugam 1 la pozitia din tabelul ascii
                mov bl,[buffer+edx]
                mov [character], bl
                inc edx
                ;transformam caracterul in dword
                mov bh, 0
                push 0
                push bx
                pop ebx
                ;punem frecventa
                mov al, [ascii_table+ebx]
                inc al
                mov [ascii_table+ebx],al
                ;loop'ul se opreste cand s-au citit toate caracterele
            loop start_loop2
            
            ;verificam daca textul a fost citit bine dupa nr de caractere
            push dword buffer
            push dword [nr_car_citite]
            push dword format
            call [printf]
            add esp, 4*3
            
            ; facem iar bucla sa vedem daca s-au citit toate caracterele
            jmp bucla
        
        ; dupa ce am trecut prin toate testele verificam frecventa maxima a literei maxime
        frequency:
            mov ecx, 256
            mov bh, 0
            mov edx, 0
            start_loop:
                mov bl,[ascii_table+edx] ;bl = de cate ori apare litera
                                         ;daca bl e 0 trecem peste
                                         ;verificam aca e litera mare
                cmp bl, 0
                je is_zero
                
                cmp edx, 'Z' ; if A <= character <= Z
                jle found_big_letter
                
                
                found_big_letter:
                    ;daca e litera mare, atunci verificam daca are frecventa maxima sau nu
                    cmp bl, [nr_final]
                    jle ignore_if_not_more
                    mov [final_character], edx
                    mov [nr_final], bl
                    ignore_if_not_more:
                is_zero:
                inc edx
            loop start_loop
      

        ;afisam litera si frecventa
        push dword [nr_final]
        push dword [final_character]
        push dword format_final
        call [printf]
        
        ; inchidem fisierul
        ; fclose(descriptor_fis)
        push dword [descriptor_fis]
        call [fclose]
        add esp, 4
        
      final:  
        ; exit(0)
        push    dword 0      
        call    [exit]       