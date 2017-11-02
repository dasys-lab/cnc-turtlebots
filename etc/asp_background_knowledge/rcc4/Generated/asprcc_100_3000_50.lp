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
partialOverlapping(25, 78).
partialOverlapping(78, 10).
partialOverlapping(10, 36).
partialOverlapping(36, 15).
partialOverlapping(15, 4).
partialOverlapping(4, 28).
partialOverlapping(28, 54).
partialOverlapping(54, 29).
partialOverlapping(29, 52).
partialOverlapping(52, 35).
partialOverlapping(35, 57).
partialOverlapping(57, 93).
partialOverlapping(93, 98).
partialOverlapping(98, 59).
partialOverlapping(59, 44).
partialOverlapping(44, 71).
partialOverlapping(71, 87).
partialOverlapping(87, 19).
partialOverlapping(19, 2).
partialOverlapping(2, 50).
partialOverlapping(50, 38).
partialOverlapping(38, 41).
partialOverlapping(41, 22).
partialOverlapping(22, 7).
partialOverlapping(7, 47).
