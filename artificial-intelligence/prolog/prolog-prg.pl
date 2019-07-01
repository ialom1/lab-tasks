friends(raju, mahesh).
singer(sonu).
odd_number(5).

mother_child(trude, sally).
father_child(tom, sally).
father_child(tom, erica).
parent_child(X, Y) :- father_child(X, Y).
parent_child(X, Y) :- mother_child(X, Y).
sibling(X, Y)      :- parent_child(Z, X), parent_child(Z, Y).

hello :- format('Hello world~n').

happy(yolanda).
happy(vincent).
listens2music(butch).
listen2music(mia).

listen2music(yolanda):-happy(yolanda).
listens2music(vincent):- happy(vincent).

playsAirGuitar(butch):- happy(butch).
playsAirGuiter(mia):-listen2music(mia).
playsAirGuiter(yolanda):-listen2music(yolanda).
playsAirGuitar(butch):- listens2music(butch).
playsAirGuitar(vincent):- listens2music(vincent), happy(vincent).