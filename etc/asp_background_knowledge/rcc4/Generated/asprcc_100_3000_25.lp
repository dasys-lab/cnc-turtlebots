#program asprccgen.

room(0..99).

reachable(X, Y) :- reachable(Y, X), X!=Y.
reachable(X, Z) :- reachable(X, Y), reachable(Y,Z), X!=Y, Y!=Z, X!=Z.
reachable(X, Y) :- partialOverlapping(X, Y), room(X), room(Y).
partialOverlapping(6, 31).
partialOverlapping(31, 21).
partialOverlapping(21, 3).
partialOverlapping(3, 24).
partialOverlapping(24, 79).
partialOverlapping(79, 18).
partialOverlapping(18, 42).
partialOverlapping(42, 34).
partialOverlapping(34, 49).
partialOverlapping(49, 1).
partialOverlapping(1, 56).
partialOverlapping(56, 43).
partialOverlapping(43, 84).
partialOverlapping(84, 94).
partialOverlapping(94, 81).
partialOverlapping(81, 69).
partialOverlapping(69, 5).
partialOverlapping(5, 63).
partialOverlapping(63, 48).
partialOverlapping(48, 53).
partialOverlapping(53, 97).
partialOverlapping(97, 65).
partialOverlapping(65, 60).
partialOverlapping(60, 25).
