%Domeniu:
%list = integer*

%Predicate:
%add_lista(integer, list, list)
%add_main(list, list)

:-consult(a).
add_list(_,[],[]).
add_list(LastEl,[H|T],Lrez):-is_list(H),
	                     add_list(H,T,Lrez2),
			     add(H,LastEl,Lpoz),
			     Lrez=[Lpoz|Lrez2].

add_list(LastEl,[H|T],Lrez):-number(H),
	                     add_list(H,T,Lrez2),
			     Lrez=[H|Lrez2].
add_main([H|T],Lrez):-add_list(H,T,Lrez2),
                      Lrez=[H|Lrez2].