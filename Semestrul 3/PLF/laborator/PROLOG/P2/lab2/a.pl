%Domeniu:
%list = integer*

%Predicate:
%add_impar(list, integre, integer, integer, list)
%add(list, integer, list)




add_impar([],_,_,_,[]).
add_impar([H|T],E,LastGoodPoz,CurrPoz,[H,E|Lrez2]):-CurrPoz is 2*LastGoodPoz + 1,
				             UrmPoz is CurrPoz + 1,
	                                     add_impar(T,E,CurrPoz,UrmPoz,Lrez2).
add_impar([H|T],E,LastGoodPoz,CurrPoz,[H|Lrez2]):-CurrPoz \= 2*LastGoodPoz + 1,
				             UrmPoz is CurrPoz + 1,
	                                     add_impar(T,E,LastGoodPoz,UrmPoz,Lrez2).
add(L,E,Lrez):-add_impar(L,E,0,1,Lrez).
