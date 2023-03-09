%permutari
inseram(E,L,[E|L]).
inseram(E,[H|T],[H|R]) :- inseram(E,T,R).

permutare([],[]).
permutare([H|T],R) :- permutare(T,R2) , inseram(H,R2,R).

permut_all(L,R) :- findall( X , permutare(L,X) , R).

%combinari
combinn([H|_],1,[H]).
combinn([_|T],K,R) :- combinn(T,K,R).
combinn([H|T],K,[H|R]) :- K > 1 , K2 is K - 1 , combinn(T,K2,R).

%aranjament
aranjamente(L,K,R) :- combinn(L,K,R2) , permut_all(R2,R).
