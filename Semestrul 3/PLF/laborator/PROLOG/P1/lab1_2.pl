 sterge(_,[],[]).
 sterge(E,[E|T],T1):-sterge(E,T,T1).
 sterge(E,[H|T],[H|T1]):-E\=H, sterge(E,T,T1).


 nr_apar(_,[],0).
 nr_apar(E,[E|H],N):-nr_apar(E,H,N1),N is N1+1,!.
 nr_apar(E,[_|H],N):-nr_apar(E,H,N).


 get_perechi([],[]).
 %get_perechi([E],[[E,1]]).
 get_perechi([H|T],[[H,N]|P]):-nr_apar(H,[H|T],N),
 sterge(H,[H|T],L),
 get_perechi(L,P).
