#program distributed_systems_rooms.

%%%%% Discribes the rcc8 relations between the rooms in distributed systems

%%%%% rooms are par of a section

%%%% studentArea
externallyConnected(studentArea, mainHallA).
disconnected(studentArea, mainHallB).
disconnected(studentArea, workshop).
disconnected(studentArea, offices).
disconnected(studentArea, utility).
disconnected(studentArea, organization).

%%%% the studenArea consists of the rooms 1411 1411A and 1411C
tangentialProperPart(1411, studenArea).
tangentialProperPart(1411A, studenArea).
tangentialProperPart(1411C, studenArea).

%%%% the rooms which are part of the studentArea are in relation to each other
externallyConnected(1411, 1411C).
externallyConnected(1411A, 1411C).
disconnected(1411, 1411A).

%%%% workshop
externallyConnected(workshop, mainHallA).
disconnected(studentArea, mainHallB).
disconnected(workshop, studentArea).
disconnected(workshop, offices).
disconnected(workshop, utility).
disconnected(workshop, organization).

%%%% offices
externallyConnected(offices,mainHallA).
externallyConnected(offices,mainHallB).
disconnected(offices,workshop).
disconnected(offices,studentArea).
externallyConnected(offices,utility).
disconnected(offices,organization).

%%%% mainHallA
externallyConnected(mainHallA, studentArea).
externallyConnected(mainHallA, mainHallB).
externallyConnected(mainHallA, workshop).
externallyConnected(mainHallA, offices).
disconnected(mainHallA, utility).
disconnected(mainHallA, organization).

%%%% mainHallB
externallyConnected(mainHallB, mainHallA).
disconnected(mainHallB, studentArea).
disconnected(mainHallB, workshop).
externallyConnected(mainHallB, offices).
externallyConnected(mainHallB, utility).
externallyConnected(mainHallB, organization).

%%%% utility
disconnected(utility, mainHallA).
externallyConnected(utility, mainHallB).
disconnected(utility, workshop).
externallyConnected(utility, offices).
disconnected(utility, studentArea).
externallyConnected(utility, organization).

%%%% organization
disconnected(organization, mainHallA).
externallyConnected(organization, mainHallB).
disconnected(organization, workshop).
disconnected(organization, offices).
externallyConnected(organization, utility).
disconnected(organization, studentArea).
