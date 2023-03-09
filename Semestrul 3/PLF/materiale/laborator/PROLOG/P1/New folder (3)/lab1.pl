delete(A, [A|B], B).
    delete(A, [B, C|D], [B|E]) :-
	    delete(A, [C|D], E).
