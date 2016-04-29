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

%%%% the workshop consists of the rooms 1410 1410A and 1410B
tangentialProperPart(1410, workshop).
tangentialProperPart(1410A, workshop).
tangentialProperPart(1410B, workshop).

%%%% the rooms which are part of the workshop are in relation to each other
externallyConnected(1410, 1410A).
externallyConnected(1410, 1410B).
disconnected(1410A, 1410B).

%%%% offices
externallyConnected(offices,mainHallA).
externallyConnected(offices,mainHallB).
externallyConnected(offices,utility).
disconnected(offices,workshop).
disconnected(offices,studentArea).
disconnected(offices,organization).

%%%% the offices consists of the rooms 1407 1408A 1408B 1408C 1406A 1406B 1406C
tangentialProperPart(1407, offices).
tangentialProperPart(1408A, offices).
tangentialProperPart(1408B, offices).
tangentialProperPart(1408C, offices).
tangentialProperPart(1406A, offices).
tangentialProperPart(1406B, offices).
tangentialProperPart(1406C, offices).

%%%% the rooms which are part of the offices are in relation to each other
externallyConnected(1407, 1408A).
externallyConnected(1407, 1408B).
externallyConnected(1407, 1408C).
externallyConnected(1407, 1406A).
externallyConnected(1407, 1406B).
externallyConnected(1407, 1406C).
disconnected(1408A, 1408B).
disconnected(1408A, 1408C).
disconnected(1408A, 1406A).
disconnected(1408A, 1406B).
disconnected(1408A, 1406C).
disconnected(1408B, 1408C).
disconnected(1408B, 1406A).
disconnected(1408B, 1406B).
disconnected(1408B, 1406C).
disconnected(1408C, 1406A).
disconnected(1408C, 1406B).
disconnected(1408C, 1406C).
disconnected(1406A, 1406B).
disconnected(1406A, 1406C).
disconnected(1406B, 1406C).

%%%% mainHallA only consists of room 1401A
externallyConnected(mainHallA, studentArea).
externallyConnected(mainHallA, mainHallB).
externallyConnected(mainHallA, workshop).
externallyConnected(mainHallA, offices).
disconnected(mainHallA, utility).
disconnected(mainHallA, organization).

equal(1401A, mainHallA).

%%%% mainHallB only consists of 1401B
externallyConnected(mainHallB, mainHallA).
externallyConnected(mainHallB, offices).
externallyConnected(mainHallB, utility).
externallyConnected(mainHallB, organization).
disconnected(mainHallB, studentArea).
disconnected(mainHallB, workshop).

equal(1401B, mainHallB).

%%%% utility
externallyConnected(utility, mainHallB).
externallyConnected(utility, organization).
externallyConnected(utility, offices).
disconnected(utility, workshop).
disconnected(utility, studentArea).
disconnected(utility, mainHallA).

%%%% the utility area consists of the rooms 1405 1405A 1405B and 1403C
tangentialProperPart(1405, utility).
tangentialProperPart(1405A, utility).
tangentialProperPart(1405B, utility).
tangentialProperPart(1403C, utility).

%%%% the rooms which are part of the utility area are in relation to each other
externallyConnected(1405, 1405A).
externallyConnected(1405A, 1405B).
externallyConnected(1405A, 1403C).
disconnected(1410A, 1410B).
disconnected(1410A, 1410B).
disconnected(1410A, 1410B).

%%%% organization
externallyConnected(organization, mainHallB).
externallyConnected(organization, utility).
disconnected(organization, mainHallA).
disconnected(organization, workshop).
disconnected(organization, offices).
disconnected(organization, studentArea).

%%%% the organization area consists of the rooms 1403 1403A and 1403B
tangentialProperPart(1403, organization).
tangentialProperPart(1403A, organization).
tangentialProperPart(1403B, organization).

%%%% the rooms which are part of the organization area are in relation to each other
externallyConnected(1403A, 1403B).
externallyConnected(1403B, 1403).
disconnected(1403A, 1403).
