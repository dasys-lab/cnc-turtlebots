#program navTest.

#external externalqueryExternal1.
#external reachable(r1405B, r1411).

goalReachable(X,1) :- reachable(X, Y), goal(X,1), start(Y,1), room(X), room(Y), externalqueryExternal1.
goal(r1405B,1) :- externalqueryExternal1.
start(r1411,1) :- externalqueryExternal1.
room(r1405B).
room(r1411).

#program navTest2.

#external externalqueryExternal2.

goalReachable(X,2) :- reachable(X, Y), goal(X,2), start(Y,2), room(X), room(Y), externalqueryExternal2.
goal(r1405B,2) :- externalqueryExternal2.
start(r1411,2) :- externalqueryExternal2.

#program navTest3.

#external externalqueryExternal3.

goalReachable(X,3) :- reachable(X, Y), goal(X,3), start(Y,3), room(X), room(Y), externalqueryExternal3.
goal(r1405B,3) :- externalqueryExternal3.
start(r1411,3) :- externalqueryExternal3.
