#program distributedSystemsRooms2.
%%%%% Relations for PathPlanning

reachable(X, Y, 2) :- reachable(Y, X, 2), X!=Y.
reachable(X, Z, 2) :- reachable(X, Y, 2), reachable(Y, Z, 2), X!=Y, Y!=Z, X!=Z. 
reachable(X, Y, 2) :- partialOverlapping(X, Y, 2), area(X, 2), area(Y, 2). 
reachable(X, Y, 2) :- properPart(X, Y, 2), room(X, 2), area(Y, 2).
reachable(X, Y, 2) :- partialOverlapping(X, Y, 2), room(X, 2), room(Y, 2). 

%%%%% Discribes the rcc4 relations between the rooms in distributed systems

%%%%% rooms are part of an area

%%%% studentArea
disconnected(studentArea, mainHallA, 2).
disconnected(studentArea, mainHallB, 2).
disconnected(studentArea, workshop, 2).
disconnected(studentArea, offices, 2).
disconnected(studentArea, utility, 2).
disconnected(studentArea, organization, 2).

%%%% the studentArea consists of the rooms 1411 1411A and 1411C
disconnected(r1411, studentArea, 2).
disconnected(r1411A, studentArea, 2).
disconnected(r1411C, studentArea, 2).

%%%% the rooms which are part of the studentArea are in relation to each other
disconnected(r1411, r1411C, 2).
disconnected(r1411A, r1411C, 2).
disconnected(r1411, r1411A, 2).

%%%% workshop
partialOverdisconnectedlapping(workshop, mainHallA, 2).
disconnected(studentArea, mainHallB, 2).
disconnected(workshop, studentArea, 2).
disconnected(workshop, offices, 2).
disconnected(workshop, utility, 2).
disconnected(workshop, organization, 2).

%%%% the workshop consists of the rooms 1410 1410A and 1410B
disconnected(r1410, workshop, 2).
disconnected(r1410A, workshop, 2).
disconnected(r1410B, workshop, 2).

%%%% the rooms which are part of the workshop are in relation to each other
disconnected(r1410, r1410A, 2).
disconnected(r1410, r1410B, 2).
disconnected(r1410A, r1410B, 2).

%%%% offices
disconnected(offices, mainHallA, 2).
disconnected(offices, mainHallB, 2).
disconnected(offices, utility, 2).
disconnected(offices, workshop, 2).
disconnected(offices, studentArea, 2).
disconnected(offices, organization, 2).

%%%% the offices consists of the rooms 1407 1408A 1408B 1408C 1406A 1406B 1406C
disconnected(r1407, offices, 2).
disconnected(r1408A, offices, 2).
disconnected(r1408B, offices, 2).
disconnected(r1408C, offices, 2).
disconnected(r1406A, offices, 2).
disconnected(r1406B, offices, 2).
disconnected(r1406C, offices, 2).

%%%% the rooms which are part of the offices are in relation to each other
disconnected(r1407, r1408A, 2).
disconnected(r1407, r1408B, 2).
disconnected(r1407, r1408C, 2).
disconnected(r1407, r1406A, 2).
disconnected(r1407, r1406B, 2).
disconnected(r1407, r1406C, 2).
disconnected(r1408A, r1408B, 2).
disconnected(r1408A, r1408C, 2).
disconnected(r1408A, r1406A, 2).
disconnected(r1408A, r1406B, 2).
disconnected(r1408A, r1406C, 2).
disconnected(r1408B, r1408C, 2).
disconnected(r1408B, r1406A, 2).
disconnected(r1408B, r1406B, 2).
disconnected(r1408B, r1406C, 2).
disconnected(r1408C, r1406A, 2).
disconnected(r1408C, r1406B, 2).
disconnected(r1408C, r1406C, 2).
disconnected(r1406A, r1406B, 2).
disconnected(r1406A, r1406C, 2).
disconnected(r1406B, r1406C, 2).

%%%% mainHallA only consists of room 1401A
disconnected(mainHallA, studentArea, 2).
disconnected(mainHallA, mainHallB, 2).
disconnected(mainHallA, workshop, 2).
disconnected(mainHallA, offices, 2).
disconnected(mainHallA, utility, 2).
disconnected(mainHallA, organization, 2).

equal(r1401A, mainHallA).

%%%% mainHallB only consists of 1401B
disconnected(mainHallB, mainHallA, 2).
disconnected(mainHallB, offices, 2).
disconnected(mainHallB, utility, 2).
disconnected(mainHallB, organization, 2).
disconnected(mainHallB, studentArea, 2).
disconnected(mainHallB, workshop, 2).

equal(r1401B, mainHallB).

%%%% utility
disconnected(utility, mainHallB, 2).
disconnected(utility, organization, 2).
disconnected(utility, offices, 2).
disconnected(utility, workshop, 2).
disconnected(utility, studentArea, 2).
disconnected(utility, mainHallA, 2).

%%%% the utility area consists of the rooms 1405 1405A 1405B and 1403C
disconnected(r1405, utility, 2).
disconnected(r1405A, utility, 2).
disconnected(r1405B, utility, 2).
disconnected(r1403C, utility, 2).

%%%% the rooms which are part of the utility area are in relation to each other
disconnected(r1405, r1405A, 2).
disconnected(r1405A, r1405B, 2).
disconnected(r1405A, r1403C, 2).
disconnected(r1410A, r1410B, 2).
disconnected(r1410A, r1410B, 2).
disconnected(r1410A, r1410B, 2).

%%%% organization
disconnected(organization, mainHallB, 2).
disconnected(organization, utility, 2).
disconnected(organization, mainHallA, 2).
disconnected(organization, workshop, 2).
disconnected(organization, offices, 2).
disconnected(organization, studentArea, 2).

%%%% the organization area consists of the rooms 1403 1403A and 1403B
disconnected(r1403, organization, 2).
disconnected(r1403A, organization, 2).
disconnected(r1403B, organization, 2).

%%%% the rooms which are part of the organization area are in relation to each other
disconnected(r1403A, r1403B, 2).
disconnected(r1403B, r1403, 2).
disconnected(r1403A, r1403, 2).

%%%% relations between rooms and POIs

%%% 1411
disconnected(studentLab1, r1411, 2).
disconnected(kicker, r1411, 2).
disconnected(studentLab2, r1411, 2).
disconnected(studentLabDoor1, r1411, 2).

%%%% 1411C
disconnected(floor1, r1411C, 2).
disconnected(studentLabDoor2, r1411C, 2).
disconnected(hiWiDoor1, r1411C, 2).

%%%% 1411A
disconnected(hiwiroom, r1411A, 2).
disconnected(hiWiDoor2, r1411A, 2).

%%%% 1401A
disconnected(floor1Door1, r1401A, 2).
disconnected(floor1Door2, r1401A, 2).
disconnected(floor1Door3, r1401A, 2).
disconnected(floor1Door4, r1401A, 2).

%%%% 1401B
disconnected(floor3Door1, r1401B, 2).
disconnected(floor3Door2, r1401B, 2).
disconnected(floor3Door3, r1401B, 2).
disconnected(floor3Door4, r1401B, 2).

%%%% 1410
disconnected(workShopDoor1, r1410, 2).
disconnected(workShopDoor2, r1410, 2).

%%%% 1407
disconnected(floor2Door1, r1407, 2).
disconnected(floor2Door2, r1407, 2).
disconnected(floor2Door3, r1407, 2).
disconnected(floor2Door4, r1407, 2).
disconnected(floor2Door5, r1407, 2).
disconnected(floor2Door6, r1407, 2).
disconnected(floor2Door7, r1407, 2).
disconnected(floor2Door8, r1407, 2).
disconnected(floor2Door9, r1407, 2).

%%%% 1410A
disconnected(workShopDoor3, r1410A, 2).
disconnected(workShopright, r1410A, 2).

%%%% 1410B
disconnected(workShopDoor4, r1410B, 2).
disconnected(workShopLeft, r1410B, 2).

%%%% 1408A
disconnected(room1408A, r1408A, 2).

%%%% 1408B
disconnected(room1408BFront, r1408B, 2).
disconnected(room1408BWindow, r1408B, 2).

%%%% 1408C
disconnected(room1408CFront, r1408C, 2).
disconnected(room1408CWindow, r1408C, 2).

%%%% 1406A
disconnected(room1406AFront, r1406A, 2).
disconnected(room1406AWindow, r1406A, 2).

%%%% 1406B
disconnected(room1406BFront, r1406B, 2).
disconnected(room1406BWindow, r1406B, 2).

%%%% 1406C
disconnected(room1406C, r1406C, 2).

%%%% 1405B
disconnected(kitchen, r1405B, 2).

%%%% 1405A
disconnected(floor4, r1405A, 2).
disconnected(floor4Door1, r1405A, 2).
disconnected(floor4Door2, r1405A, 2).

%%%% 1405
disconnected(meetingroom, r1405, 2).

%%%% 1403C
disconnected(copyroom, r1403C, 2).
disconnected(copyroomDoor1, r1403C, 2).
disconnected(copyroomDoor2, r1403C, 2).

%%%% 1403A
disconnected(secreteriatDoor1, r1403A, 2).
disconnected(secreteriatDoor2, r1403A, 2).
disconnected(secreteriatDoor3, r1403A, 2).
disconnected(secreteriat, r1403A, 2).

%%%% 1403
disconnected(room1403Door, r1403, 2).
disconnected(room1403, r1403, 2).

%%%%% Areas
area(mainHallA, 2).
area(mainHallB, 2).
area(workshop, 2).
area(offices, 2).
area(utility, 2).
area(organization, 2).
area(studentArea, 2).

%%%%% Rooms
room(r1411, 2).
room(r1411A, 2).
room(r1411C, 2).
room(r1410, 2).
room(r1410A, 2).
room(r1410B, 2).
room(r1407, 2).
room(r1408A, 2).
room(r1408B, 2).
room(r1408C, 2).
room(r1406A, 2).
room(r1406B, 2).
room(r1405, 2).
room(r1405A, 2).
room(r1405B, 2).
room(r1403C, 2).
room(r1403, 2).
room(r1403A, 2).
room(r1403B, 2).

%%%%% POI
poi(studentLab1, 2).
poi(kicker, 2).
poi(studentLab2, 2).
poi(studentLabDoor1, 2).
poi(floor1, 2).
poi(studentLabDoor2, 2).
poi(hiWiDoor1, 2).
poi(hiwiroom, 2).
poi(hiWiDoor2, 2).
poi(floor1Door1, 2).
poi(floor1Door2, 2).
poi(floor1Door3, 2).
poi(floor1Door4, 2).
poi(floor3Door1, 2).
poi(floor3Door2, 2).
poi(floor3Door3, 2).
poi(floor3Door4, 2).
poi(workShopDoor1, 2).
poi(workShopDoor2, 2).
poi(floor2Door1, 2).
poi(floor2Door2, 2).
poi(floor2Door3, 2).
poi(floor2Door4, 2).
poi(floor2Door5, 2).
poi(floor2Door6, 2).
poi(floor2Door7, 2).
poi(floor2Door8, 2).
poi(floor2Door9, 2).
poi(workShopDoor3, 2).
poi(workShopright, 2).
poi(workShopDoor4, 2).
poi(workShopLeft, 2).
poi(room1408A, 2).
poi(room1408BFront, 2).
poi(room1408BWindow, 2).
poi(room1408CFront, 2).
poi(room1408CWindow, 2).
poi(room1406AFront, 2).
poi(room1406AWindow, 2).
poi(room1406BFront, 2).
poi(room1406BWindow, 2).
poi(room1406C, 2).
poi(kitchen, 2).
poi(floor4, 2).
poi(floor4Door1, 2).
poi(floor4Door2, 2).
poi(meetingroom, 2).
poi(copyroom, 2).
poi(copyroomDoor1, 2).
poi(copyroomDoor2, 2).
poi(secreteriatDoor1, 2).
poi(secreteriatDoor2, 2).
poi(secreteriatDoor3, 2).
poi(secreteriat, 2).
poi(room1403Door, 2).
poi(room1403, 2).
