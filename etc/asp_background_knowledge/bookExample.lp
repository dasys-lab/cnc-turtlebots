#program bookExample.

-test(5).

agent(raphael).
agent(donatello).
agent(leonardo).

book(atificialIntelligence).
book(snowWhite).
book(rapunzel).
book(motherHulda).
book(hanselAndGrethel).
book(harryPotter1).
book(harryPotter2).

genre(fairyTail).
genre(factualBook).
genre(novel).

bookGenre(atificialIntelligence, factualBook).
bookGenre(snowWhite, fairyTail).
bookGenre(rapunzel, fairyTail).
bookGenre(motherHulda, fairyTail).
bookGenre(harryPotter1, novel).
bookGenre(harryPotter2, novel).
bookGenre(hanselAndGrethel, fairyTail).

on(atificialIntelligence, raphael).
on(snowWhite, raphael).
on(rapunzel, donatello).

%available(X) :- book(X), not on(X,Y) : agent(Y).
