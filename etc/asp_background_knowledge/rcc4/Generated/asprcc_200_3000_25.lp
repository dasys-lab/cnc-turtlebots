#program asprccgen.

room(0..199).

reachable(X, Y) :- reachable(Y, X), X!=Y.
reachable(X, Z) :- reachable(X, Y), reachable(Y,Z), X!=Y, Y!=Z, X!=Z.
reachable(X, Y) :- partialOverlapping(X, Y), room(X), room(Y).
partialOverlapping(106, 31).
partialOverlapping(31, 121).
partialOverlapping(121, 103).
partialOverlapping(103, 124).
partialOverlapping(124, 79).
partialOverlapping(79, 18).
partialOverlapping(18, 42).
partialOverlapping(42, 34).
partialOverlapping(34, 149).
partialOverlapping(149, 101).
partialOverlapping(101, 56).
partialOverlapping(56, 43).
partialOverlapping(43, 84).
partialOverlapping(84, 194).
partialOverlapping(194, 81).
partialOverlapping(81, 69).
partialOverlapping(69, 105).
partialOverlapping(105, 163).
partialOverlapping(163, 48).
partialOverlapping(48, 53).
partialOverlapping(53, 97).
partialOverlapping(97, 165).
partialOverlapping(165, 160).
partialOverlapping(160, 125).
partialOverlapping(125, 178).
partialOverlapping(178, 63).
partialOverlapping(63, 10).
partialOverlapping(10, 136).
partialOverlapping(136, 134).
partialOverlapping(134, 15).
partialOverlapping(15, 104).
partialOverlapping(104, 128).
partialOverlapping(128, 49).
partialOverlapping(49, 54).
partialOverlapping(54, 29).
partialOverlapping(29, 65).
partialOverlapping(65, 52).
partialOverlapping(52, 135).
partialOverlapping(135, 157).
partialOverlapping(157, 93).
partialOverlapping(93, 98).
partialOverlapping(98, 6).
partialOverlapping(6, 129).
partialOverlapping(129, 59).
partialOverlapping(59, 44).
partialOverlapping(44, 94).
partialOverlapping(94, 171).
partialOverlapping(171, 87).
partialOverlapping(87, 19).
