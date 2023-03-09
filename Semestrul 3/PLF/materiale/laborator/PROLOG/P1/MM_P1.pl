%predicates:
%M = integer
%L = list
%maxim(list, integer)
%
%predicatul returneaza numarul maxim din lista
maxim([],-99999).                            %lista vida
maxim([H|T],H) :- maxim(T,M) , H > M , !.    %daca L1>Maxim
maxim([_|T],M) :- maxim(T,M).                %altfel

%predicates:
%L = list
%R = list
%M = integer
%Poz = integer
%toate(list, list, integer, integer)
%
%predicatul returneaza lista de popzitii care au elementul dat maxim
toate([],[],_,_).                                  %lista vida
toate([H|T],[Poz|R],M,Poz) :- H =:= M ,            %daca L1==maxim (daca am gasit elem maxim)
                              Poz2 is Poz + 1 ,    %trecem la urmatoarea pozitie
                              toate(T,R,M,Poz2).   %apelam functia toate de la l2 si cu poz+1
toate([H|T],R,M,Poz) :- H =\= M ,                  %daca L1 nu e egal cu max
                        Poz2 is Poz + 1 ,          %trecem la urmatoarea pozitie
                        toate(T,R,M,Poz2).         %apelam functia toate cu pozitia cresuta

%predicates:
%L = list
%R = list
%poz_max(list, list)
%
%predicatul auxiliar returneaza lista elementrelor maxim dintr-o lista
poz_max(L,R) :- maxim(L,M) , toate(L,R,M,1).     %apeleaza maxim(lista, max) si toate(lista, max, prima_pozitie)
