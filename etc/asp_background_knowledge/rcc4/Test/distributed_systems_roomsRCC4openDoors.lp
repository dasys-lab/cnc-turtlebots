#program distributedSystemsRooms1.
%%%%% Relations for PathPlanning

reachable(X, Y, 1) :- reachable(Y, X, 1), X!=Y.
reachable(X, Z, 1) :- reachable(X, Y, 1), reachable(Y, Z, 1), X!=Y, Y!=Z, X!=Z. 
reachable(X, Y, 1) :- partialOverlapping(X, Y, 1), area(X, 1), area(Y, 1). 
reachable(X, Y, 1) :- properPart(X, Y, 1), room(X, 1), area(Y, 1).

%%%%% Discribes the rcc4 relations between the rooms in distributed systems

%%%%% rooms are part of an area

%%%% studentArea
partialOverlapping(studentArea, mainHallA, 1).
disconnected(studentArea, mainHallB, 1).
disconnected(studentArea, workshop, 1).
disconnected(studentArea, offices, 1).
disconnected(studentArea, utility, 1).
disconnected(studentArea, organization, 1).

%%%% the studentArea consists of the rooms 1411 1411A and 1411C
properPart(r1411, studentArea, 1).
properPart(r1411A, studentArea, 1).
properPart(r1411C, studentArea, 1).

%%%% the rooms which are part of the studentArea are in relation to each other
partialOverlapping(r1411, r1411C, 1).
partialOverlapping(r1411A, r1411C, 1).
disconnected(r1411, r1411A, 1).

%%%% workshop
partialOverlapping(workshop, mainHallA, 1).
disconnected(studentArea, mainHallB, 1).
disconnected(workshop, studentArea, 1).
disconnected(workshop, offices, 1).
disconnected(workshop, utility, 1).
disconnected(workshop, organization, 1).

%%%% the workshop consists of the rooms 1410 1410A and 1410B
properPart(r1410, workshop, 1).
properPart(r1410A, workshop, 1).
properPart(r1410B, workshop, 1).

%%%% the rooms which are part of the workshop are in relation to each other
partialOverlapping(r1410, r1410A, 1).
partialOverlapping(r1410, r1410B, 1).
disconnected(r1410A, r1410B, 1).

%%%% offices
partialOverlapping(offices, mainHallA, 1).
partialOverlapping(offices, mainHallB, 1).
partialOverlapping(offices, utility, 1).
disconnected(offices, workshop, 1).
disconnected(offices, studentArea, 1).
disconnected(offices, organization, 1).

%%%% the offices consists of the rooms 1407 1408A 1408B 1408C 1406A 1406B 1406C
properPart(r1407, offices, 1).
properPart(r1408A, offices, 1).
properPart(r1408B, offices, 1).
properPart(r1408C, offices, 1).
properPart(r1406A, offices, 1).
properPart(r1406B, offices, 1).
properPart(r1406C, offices, 1).

%%%% the rooms which are part of the offices are in relation to each other
partialOverlapping(r1407, r1408A, 1).
partialOverlapping(r1407, r1408B, 1).
partialOverlapping(r1407, r1408C, 1).
partialOverlapping(r1407, r1406A, 1).
partialOverlapping(r1407, r1406B, 1).
partialOverlapping(r1407, r1406C, 1).
disconnected(r1408A, r1408B, 1).
disconnected(r1408A, r1408C, 1).
disconnected(r1408A, r1406A, 1).
disconnected(r1408A, r1406B, 1).
disconnected(r1408A, r1406C, 1).
disconnected(r1408B, r1408C, 1).
disconnected(r1408B, r1406A, 1).
disconnected(r1408B, r1406B, 1).
disconnected(r1408B, r1406C, 1).
disconnected(r1408C, r1406A, 1).
disconnected(r1408C, r1406B, 1).
disconnected(r1408C, r1406C, 1).
disconnected(r1406A, r1406B, 1).
disconnected(r1406A, r1406C, 1).
disconnected(r1406B, r1406C, 1).

%%%% mainHallA only consists of room 1401A
partialOverlapping(mainHallA, studentArea, 1).
partialOverlapping(mainHallA, mainHallB, 1).
partialOverlapping(mainHallA, workshop, 1).
partialOverlapping(mainHallA, offices, 1).
disconnected(mainHallA, utility, 1).
disconnected(mainHallA, organization, 1).

equal(r1401A, mainHallA, 1).

%%%% mainHallB only consists of 1401B
partialOverlapping(mainHallB, mainHallA, 1).
partialOverlapping(mainHallB, offices, 1).
partialOverlapping(mainHallB, utility, 1).
partialOverlapping(mainHallB, organization, 1).
disconnected(mainHallB, studentArea, 1).
disconnected(mainHallB, workshop, 1).

equal(r1401B, mainHallB, 1).

%%%% utility
partialOverlapping(utility, mainHallB, 1).
partialOverlapping(utility, organization, 1).
partialOverlapping(utility, offices, 1).
disconnected(utility, workshop, 1).
disconnected(utility, studentArea, 1).
disconnected(utility, mainHallA, 1).

%%%% the utility area consists of the rooms 1405 1405A 1405B and 1403C
properPart(r1405, utility, 1).
properPart(r1405A, utility, 1).
properPart(r1405B, utility, 1).
properPart(r1403C, utility, 1).

%%%% the rooms which are part of the utility area are in relation to each other
partialOverlapping(r1405, r1405A, 1).
partialOverlapping(r1405A, r1405B, 1).
partialOverlapping(r1405A, r1403C, 1).
disconnected(r1410A, r1410B, 1).
disconnected(r1410A, r1410B, 1).
disconnected(r1410A, r1410B, 1).

%%%% organization
partialOverlapping(organization, mainHallB, 1).
partialOverlapping(organization, utility, 1).
disconnected(organization, mainHallA, 1).
disconnected(organization, workshop, 1).
disconnected(organization, offices, 1).
disconnected(organization, studentArea, 1).

%%%% the organization area consists of the rooms 1403 1403A and 1403B
properPart(r1403, organization, 1).
properPart(r1403A, organization, 1).
properPart(r1403B, organization, 1).

%%%% the rooms which are part of the organization area are in relation to each other
partialOverlapping(r1403A, r1403B, 1).
partialOverlapping(r1403B, r1403, 1).
disconnected(r1403A, r1403, 1).

%%%% relations between rooms and POIs

%%% 1411
properPart(studentLab1, r1411, 1).
properPart(kicker, r1411, 1).
properPart(studentLab2, r1411, 1).
properPart(studentLabDoor1, r1411, 1).

%%%% 1411C
properPart(floor1, r1411C, 1).
properPart(studentLabDoor2, r1411C, 1).
properPart(hiWiDoor1, r1411C, 1).

%%%% 1411A
properPart(hiwiroom, r1411A, 1).
properPart(hiWiDoor2, r1411A, 1).

%%%% 1401A
properPart(floor1Door1, r1401A, 1).
properPart(floor1Door2, r1401A, 1).
properPart(floor1Door3, r1401A, 1).
properPart(floor1Door4, r1401A, 1).

%%%% 1401B
properPart(floor3Door1, r1401B, 1).
properPart(floor3Door2, r1401B, 1).
properPart(floor3Door3, r1401B, 1).
properPart(floor3Door4, r1401B, 1).

%%%% 1410
properPart(workShopDoor1, r1410, 1).
properPart(workShopDoor2, r1410, 1).

%%%% 1407
properPart(floor2Door1, r1407, 1).
properPart(floor2Door2, r1407, 1).
properPart(floor2Door3, r1407, 1).
properPart(floor2Door4, r1407, 1).
properPart(floor2Door5, r1407, 1).
properPart(floor2Door6, r1407, 1).
properPart(floor2Door7, r1407, 1).
properPart(floor2Door8, r1407, 1).
properPart(floor2Door9, r1407, 1).

%%%% 1410A
properPart(workShopDoor3, r1410A, 1).
properPart(workShopright, r1410A, 1).

%%%% 1410B
properPart(workShopDoor4, r1410B, 1).
properPart(workShopLeft, r1410B, 1).

%%%% 1408A
properPart(room1408A, r1408A, 1).

%%%% 1408B
properPart(room1408BFront, r1408B, 1).
properPart(room1408BWindow, r1408B, 1).

%%%% 1408C
properPart(room1408CFront, r1408C, 1).
properPart(room1408CWindow, r1408C, 1).

%%%% 1406A
properPart(room1406AFront, r1406A, 1).
properPart(room1406AWindow, r1406A, 1).

%%%% 1406B
properPart(room1406BFront, r1406B, 1).
properPart(room1406BWindow, r1406B, 1).

%%%% 1406C
properPart(room1406C, r1406C, 1).

%%%% 1405B
properPart(kitchen, r1405B, 1).

%%%% 1405A
properPart(floor4, r1405A, 1).
properPart(floor4Door1, r1405A, 1).
properPart(floor4Door2, r1405A, 1).

%%%% 1405
properPart(meetingroom, r1405, 1).

%%%% 1403C
properPart(copyroom, r1403C, 1).
properPart(copyroomDoor1, r1403C, 1).
properPart(copyroomDoor2, r1403C, 1).

%%%% 1403A
properPart(secreteriatDoor1, r1403A, 1).
properPart(secreteriatDoor2, r1403A, 1).
properPart(secreteriatDoor3, r1403A, 1).
properPart(secreteriat, r1403A, 1).

%%%% 1403
properPart(room1403Door, r1403, 1).
properPart(room1403, r1403, 1).

%%%%% Areas
area(mainHallA, 1).
area(mainHallB, 1).
area(workshop, 1).
area(offices, 1).
area(utility, 1).
area(organization, 1).
area(studentArea, 1).

%%%%% Rooms
room(r1411, 1).
room(r1411A, 1).
room(r1411C, 1).
room(r1410, 1).
room(r1410A, 1).
room(r1410B, 1).
room(r1407, 1).
room(r1408A, 1).
room(r1408B, 1).
room(r1408C, 1).
room(r1406A, 1).
room(r1406B, 1).
room(r1405, 1).
room(r1405A, 1).
room(r1405B, 1).
room(r1403C, 1).
room(r1403, 1).
room(r1403A, 1).
room(r1403B, 1).

%%%%% POI
poi(studentLab1, 1).
poi(kicker, 1).
poi(studentLab2, 1).
poi(studentLabDoor1, 1).
poi(floor1, 1).
poi(studentLabDoor2, 1).
poi(hiWiDoor1, 1).
poi(hiwiroom, 1).
poi(hiWiDoor2, 1).
poi(floor1Door1, 1).
poi(floor1Door2, 1).
poi(floor1Door3, 1).
poi(floor1Door4, 1).
poi(floor3Door1, 1).
poi(floor3Door2, 1).
poi(floor3Door3, 1).
poi(floor3Door4, 1).
poi(workShopDoor1, 1).
poi(workShopDoor2, 1).
poi(floor2Door1, 1).
poi(floor2Door2, 1).
poi(floor2Door3, 1).
poi(floor2Door4, 1).
poi(floor2Door5, 1).
poi(floor2Door6, 1).
poi(floor2Door7, 1).
poi(floor2Door8, 1).
poi(floor2Door9, 1).
poi(workShopDoor3, 1).
poi(workShopright, 1).
poi(workShopDoor4, 1).
poi(workShopLeft, 1).
poi(room1408A, 1).
poi(room1408BFront, 1).
poi(room1408BWindow, 1).
poi(room1408CFront, 1).
poi(room1408CWindow, 1).
poi(room1406AFront, 1).
poi(room1406AWindow, 1).
poi(room1406BFront, 1).
poi(room1406BWindow, 1).
poi(room1406C, 1).
poi(kitchen, 1).
poi(floor4, 1).
poi(floor4Door1, 1).
poi(floor4Door2, 1).
poi(meetingroom, 1).
poi(copyroom, 1).
poi(copyroomDoor1, 1).
poi(copyroomDoor2, 1).
poi(secreteriatDoor1, 1).
poi(secreteriatDoor2, 1).
poi(secreteriatDoor3, 1).
poi(secreteriat, 1).
poi(room1403Door, 1).
poi(room1403, 1).
