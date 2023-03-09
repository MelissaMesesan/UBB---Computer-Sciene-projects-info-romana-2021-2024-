bits 32

global start        

extern exit, printf, scanf          
import exit msvcrt.dll    
import printf msvcrt.dll    
import scanf msvcrt.dll     
                          
segment data use32 class=data

    ;Sa se citeasca de la tastatura un numar in baza 10 
    ;si sa se afiseze valoarea acelui numar in baza 16

	n dd  0                     
	message  db "n=", 0  
	format  db "%d", 0          ; %d <=> un numar decimal (baza 10)
    
    message_format db "n=%x", 0 ; %d <=> un numar hexadecimal (baza 16)
    
segment code use32 class=code
    start:
       
        ;printf(message)
        push dword message 
        call [printf]      
        add esp, 4*1       
                                                   
        ;scanf(format, n)
        push dword n       
        push dword format
        call [scanf]       
        add esp, 4 * 2     
        
        ;printf(%x, n)
        push dword [n]
        push dword message_format
        call [printf]
        add esp, 4*2
        
        ; exit(0)
        push dword 0      ; punem pe stiva parametrul pentru exit
        call [exit]       ; apelam exit pentru a incheia programul