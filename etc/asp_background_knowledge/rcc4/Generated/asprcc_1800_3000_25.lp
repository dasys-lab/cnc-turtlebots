#program asprccgen.

room(0..1799).

reachable(X, Y) :- reachable(Y, X), X!=Y.
reachable(X, Z) :- reachable(X, Y), reachable(Y,Z), X!=Y, Y!=Z, X!=Z.
reachable(X, Y) :- partialOverlapping(X, Y), room(X), room(Y).
partialOverlapping(1306, 631).
partialOverlapping(631, 721).
partialOverlapping(721, 1703).
partialOverlapping(1703, 1324).
partialOverlapping(1324, 1679).
partialOverlapping(1679, 1218).
partialOverlapping(1218, 1642).
partialOverlapping(1642, 634).
partialOverlapping(634, 349).
partialOverlapping(349, 901).
partialOverlapping(901, 1456).
partialOverlapping(1456, 843).
partialOverlapping(843, 1284).
partialOverlapping(1284, 1194).
partialOverlapping(1194, 281).
partialOverlapping(281, 1269).
partialOverlapping(1269, 305).
partialOverlapping(305, 1563).
partialOverlapping(1563, 48).
partialOverlapping(48, 501).
partialOverlapping(501, 1479).
partialOverlapping(1479, 1253).
partialOverlapping(1253, 97).
partialOverlapping(97, 965).
partialOverlapping(965, 760).
partialOverlapping(760, 43).
partialOverlapping(43, 1725).
partialOverlapping(1725, 578).
partialOverlapping(578, 863).
partialOverlapping(863, 1231).
partialOverlapping(1231, 1210).
partialOverlapping(1210, 736).
partialOverlapping(736, 1134).
partialOverlapping(1134, 734).
partialOverlapping(734, 615).
partialOverlapping(615, 1504).
partialOverlapping(1504, 1528).
partialOverlapping(1528, 1249).
partialOverlapping(1249, 54).
partialOverlapping(54, 629).
partialOverlapping(629, 906).
partialOverlapping(906, 897).
partialOverlapping(897, 1065).
partialOverlapping(1065, 1252).
partialOverlapping(1252, 1178).
partialOverlapping(1178, 535).
partialOverlapping(535, 1557).
partialOverlapping(1557, 93).
partialOverlapping(93, 298).
partialOverlapping(298, 1606).
partialOverlapping(1606, 594).
partialOverlapping(594, 929).
partialOverlapping(929, 1059).
partialOverlapping(1059, 1644).
partialOverlapping(1644, 94).
partialOverlapping(94, 971).
partialOverlapping(971, 1687).
partialOverlapping(1687, 19).
partialOverlapping(19, 1549).
partialOverlapping(1549, 1702).
partialOverlapping(1702, 1250).
partialOverlapping(1250, 959).
partialOverlapping(959, 638).
partialOverlapping(638, 1536).
partialOverlapping(1536, 1693).
partialOverlapping(1693, 405).
partialOverlapping(405, 1241).
partialOverlapping(1241, 1422).
partialOverlapping(1422, 807).
partialOverlapping(807, 447).
partialOverlapping(447, 1203).
partialOverlapping(1203, 865).
partialOverlapping(865, 1344).
partialOverlapping(1344, 469).
partialOverlapping(469, 317).
partialOverlapping(317, 1675).
partialOverlapping(1675, 156).
partialOverlapping(156, 75).
partialOverlapping(75, 920).
partialOverlapping(920, 1406).
partialOverlapping(1406, 833).
partialOverlapping(833, 667).
partialOverlapping(667, 1044).
partialOverlapping(1044, 511).
partialOverlapping(511, 215).
partialOverlapping(215, 1350).
partialOverlapping(1350, 648).
partialOverlapping(648, 1764).
partialOverlapping(1764, 1050).
partialOverlapping(1050, 76).
partialOverlapping(76, 1042).
partialOverlapping(1042, 1738).
partialOverlapping(1738, 1769).
partialOverlapping(1769, 1447).
partialOverlapping(1447, 331).
partialOverlapping(331, 543).
partialOverlapping(543, 454).
partialOverlapping(454, 778).
partialOverlapping(778, 899).
partialOverlapping(899, 1319).
partialOverlapping(1319, 1275).
partialOverlapping(1275, 520).
partialOverlapping(520, 1637).
partialOverlapping(1637, 302).
partialOverlapping(302, 676).
partialOverlapping(676, 864).
partialOverlapping(864, 1222).
partialOverlapping(1222, 1234).
partialOverlapping(1234, 1697).
partialOverlapping(1697, 89).
partialOverlapping(89, 941).
partialOverlapping(941, 1552).
partialOverlapping(1552, 598).
partialOverlapping(598, 1156).
partialOverlapping(1156, 254).
partialOverlapping(254, 398).
partialOverlapping(398, 272).
partialOverlapping(272, 658).
partialOverlapping(658, 600).
partialOverlapping(600, 348).
partialOverlapping(348, 1700).
partialOverlapping(1700, 1490).
partialOverlapping(1490, 1270).
partialOverlapping(1270, 1348).
partialOverlapping(1348, 22).
partialOverlapping(22, 13).
partialOverlapping(13, 954).
partialOverlapping(954, 1752).
partialOverlapping(1752, 64).
partialOverlapping(64, 1426).
partialOverlapping(1426, 1227).
partialOverlapping(1227, 584).
partialOverlapping(584, 1263).
partialOverlapping(1263, 1529).
partialOverlapping(1529, 412).
partialOverlapping(412, 327).
partialOverlapping(327, 104).
partialOverlapping(104, 1646).
partialOverlapping(1646, 1176).
partialOverlapping(1176, 1145).
partialOverlapping(1145, 1615).
partialOverlapping(1615, 898).
partialOverlapping(898, 1365).
partialOverlapping(1365, 625).
partialOverlapping(625, 304).
partialOverlapping(304, 915).
partialOverlapping(915, 963).
partialOverlapping(963, 1246).
partialOverlapping(1246, 358).
partialOverlapping(358, 716).
partialOverlapping(716, 1363).
partialOverlapping(1363, 1332).
partialOverlapping(1332, 1681).
partialOverlapping(1681, 518).
partialOverlapping(518, 144).
partialOverlapping(144, 712).
partialOverlapping(712, 1482).
partialOverlapping(1482, 559).
partialOverlapping(559, 1393).
partialOverlapping(1393, 1047).
partialOverlapping(1047, 38).
partialOverlapping(38, 1497).
partialOverlapping(1497, 893).
partialOverlapping(893, 1214).
partialOverlapping(1214, 1661).
partialOverlapping(1661, 683).
partialOverlapping(683, 378).
partialOverlapping(378, 1308).
partialOverlapping(1308, 1197).
partialOverlapping(1197, 446).
partialOverlapping(446, 1357).
partialOverlapping(1357, 360).
partialOverlapping(360, 265).
partialOverlapping(265, 803).
partialOverlapping(803, 376).
partialOverlapping(376, 1575).
partialOverlapping(1575, 671).
partialOverlapping(671, 1739).
partialOverlapping(1739, 1107).
partialOverlapping(1107, 1505).
partialOverlapping(1505, 457).
partialOverlapping(457, 592).
partialOverlapping(592, 603).
partialOverlapping(603, 1553).
partialOverlapping(1553, 456).
partialOverlapping(456, 1237).
partialOverlapping(1237, 1264).
partialOverlapping(1264, 1001).
partialOverlapping(1001, 1436).
partialOverlapping(1436, 1302).
partialOverlapping(1302, 1651).
partialOverlapping(1651, 530).
partialOverlapping(530, 1668).
partialOverlapping(1668, 1343).
partialOverlapping(1343, 1503).
partialOverlapping(1503, 739).
partialOverlapping(739, 873).
partialOverlapping(873, 1011).
partialOverlapping(1011, 1088).
partialOverlapping(1088, 569).
partialOverlapping(569, 601).
partialOverlapping(601, 737).
partialOverlapping(737, 524).
partialOverlapping(524, 977).
partialOverlapping(977, 512).
partialOverlapping(512, 916).
partialOverlapping(916, 1620).
partialOverlapping(1620, 1005).
partialOverlapping(1005, 526).
partialOverlapping(526, 1364).
partialOverlapping(1364, 1608).
partialOverlapping(1608, 972).
partialOverlapping(972, 197).
partialOverlapping(197, 696).
partialOverlapping(696, 173).
partialOverlapping(173, 1634).
partialOverlapping(1634, 1150).
partialOverlapping(1150, 24).
partialOverlapping(24, 1316).
partialOverlapping(1316, 171).
partialOverlapping(171, 1670).
partialOverlapping(1670, 11).
partialOverlapping(11, 1674).
partialOverlapping(1674, 1561).
partialOverlapping(1561, 884).
partialOverlapping(884, 850).
partialOverlapping(850, 1356).
partialOverlapping(1356, 607).
partialOverlapping(607, 1451).
partialOverlapping(1451, 293).
partialOverlapping(293, 283).
partialOverlapping(283, 628).
partialOverlapping(628, 805).
partialOverlapping(805, 1583).
partialOverlapping(1583, 1577).
partialOverlapping(1577, 788).
partialOverlapping(788, 1141).
partialOverlapping(1141, 1548).
partialOverlapping(1548, 654).
partialOverlapping(654, 313).
partialOverlapping(313, 1746).
partialOverlapping(1746, 502).
partialOverlapping(502, 487).
partialOverlapping(487, 732).
partialOverlapping(732, 1652).
partialOverlapping(1652, 1463).
partialOverlapping(1463, 1200).
partialOverlapping(1200, 23).
partialOverlapping(23, 1334).
partialOverlapping(1334, 1211).
partialOverlapping(1211, 1095).
partialOverlapping(1095, 295).
partialOverlapping(295, 888).
partialOverlapping(888, 145).
partialOverlapping(145, 647).
partialOverlapping(647, 748).
partialOverlapping(748, 1096).
partialOverlapping(1096, 930).
partialOverlapping(930, 528).
partialOverlapping(528, 102).
partialOverlapping(102, 714).
partialOverlapping(714, 1225).
partialOverlapping(1225, 1599).
partialOverlapping(1599, 403).
partialOverlapping(403, 1405).
partialOverlapping(1405, 486).
partialOverlapping(486, 1301).
partialOverlapping(1301, 107).
partialOverlapping(107, 125).
partialOverlapping(125, 233).
partialOverlapping(233, 912).
partialOverlapping(912, 1589).
partialOverlapping(1589, 585).
partialOverlapping(585, 87).
partialOverlapping(87, 1123).
partialOverlapping(1123, 1796).
partialOverlapping(1796, 1370).
partialOverlapping(1370, 291).
partialOverlapping(291, 668).
partialOverlapping(668, 1624).
partialOverlapping(1624, 1416).
partialOverlapping(1416, 1707).
partialOverlapping(1707, 1445).
partialOverlapping(1445, 621).
partialOverlapping(621, 522).
partialOverlapping(522, 477).
partialOverlapping(477, 427).
partialOverlapping(427, 321).
partialOverlapping(321, 650).
partialOverlapping(650, 830).
partialOverlapping(830, 879).
partialOverlapping(879, 288).
partialOverlapping(288, 138).
partialOverlapping(138, 414).
partialOverlapping(414, 1516).
partialOverlapping(1516, 1155).
partialOverlapping(1155, 301).
partialOverlapping(301, 290).
partialOverlapping(290, 1430).
partialOverlapping(1430, 379).
partialOverlapping(379, 1000).
partialOverlapping(1000, 693).
partialOverlapping(693, 1788).
partialOverlapping(1788, 333).
partialOverlapping(333, 1285).
partialOverlapping(1285, 483).
partialOverlapping(483, 240).
partialOverlapping(240, 582).
partialOverlapping(582, 129).
partialOverlapping(129, 256).
partialOverlapping(256, 1558).
partialOverlapping(1558, 441).
partialOverlapping(441, 577).
partialOverlapping(577, 1360).
partialOverlapping(1360, 1271).
partialOverlapping(1271, 608).
partialOverlapping(608, 1648).
partialOverlapping(1648, 755).
partialOverlapping(755, 747).
partialOverlapping(747, 1423).
partialOverlapping(1423, 949).
partialOverlapping(949, 1521).
partialOverlapping(1521, 877).
partialOverlapping(877, 1239).
partialOverlapping(1239, 1151).
partialOverlapping(1151, 326).
partialOverlapping(326, 771).
partialOverlapping(771, 1304).
partialOverlapping(1304, 1019).
partialOverlapping(1019, 1280).
partialOverlapping(1280, 1172).
partialOverlapping(1172, 159).
partialOverlapping(159, 1613).
partialOverlapping(1613, 1609).
partialOverlapping(1609, 643).
partialOverlapping(643, 1006).
partialOverlapping(1006, 1724).
partialOverlapping(1724, 612).
partialOverlapping(612, 1329).
partialOverlapping(1329, 194).
partialOverlapping(194, 84).
partialOverlapping(84, 137).
partialOverlapping(137, 994).
partialOverlapping(994, 1791).
partialOverlapping(1791, 1361).
partialOverlapping(1361, 566).
partialOverlapping(566, 34).
partialOverlapping(34, 1082).
partialOverlapping(1082, 1443).
partialOverlapping(1443, 425).
partialOverlapping(425, 1386).
partialOverlapping(1386, 1770).
partialOverlapping(1770, 890).
partialOverlapping(890, 141).
partialOverlapping(141, 1628).
partialOverlapping(1628, 176).
partialOverlapping(176, 944).
partialOverlapping(944, 752).
partialOverlapping(752, 1519).
partialOverlapping(1519, 20).
partialOverlapping(20, 1771).
partialOverlapping(1771, 0).
partialOverlapping(0, 763).
partialOverlapping(763, 1022).
partialOverlapping(1022, 1507).
partialOverlapping(1507, 208).
partialOverlapping(208, 1742).
partialOverlapping(1742, 973).
partialOverlapping(973, 633).
partialOverlapping(633, 480).
partialOverlapping(480, 95).
partialOverlapping(95, 134).
partialOverlapping(134, 236).
partialOverlapping(236, 1762).
partialOverlapping(1762, 1736).
partialOverlapping(1736, 537).
partialOverlapping(537, 1508).
partialOverlapping(1508, 112).
partialOverlapping(112, 460).
partialOverlapping(460, 1632).
partialOverlapping(1632, 1605).
partialOverlapping(1605, 1384).
partialOverlapping(1384, 303).
partialOverlapping(303, 1411).
partialOverlapping(1411, 1120).
partialOverlapping(1120, 92).
partialOverlapping(92, 1392).
partialOverlapping(1392, 7).
partialOverlapping(7, 1566).
partialOverlapping(1566, 1265).
partialOverlapping(1265, 1336).
partialOverlapping(1336, 1774).
partialOverlapping(1774, 359).
partialOverlapping(359, 1461).
partialOverlapping(1461, 1560).
partialOverlapping(1560, 839).
partialOverlapping(839, 1556).
partialOverlapping(1556, 1694).
partialOverlapping(1694, 945).
partialOverlapping(945, 808).
partialOverlapping(808, 1298).
partialOverlapping(1298, 1469).
partialOverlapping(1469, 1410).
partialOverlapping(1410, 1268).
partialOverlapping(1268, 1081).
partialOverlapping(1081, 394).
partialOverlapping(394, 225).
partialOverlapping(225, 665).
partialOverlapping(665, 1649).
partialOverlapping(1649, 937).
partialOverlapping(937, 1104).
partialOverlapping(1104, 1248).
partialOverlapping(1248, 181).
partialOverlapping(181, 697).
partialOverlapping(697, 158).
partialOverlapping(158, 188).
partialOverlapping(188, 463).
partialOverlapping(463, 576).
partialOverlapping(576, 1525).
partialOverlapping(1525, 1390).
partialOverlapping(1390, 935).
partialOverlapping(935, 338).
partialOverlapping(338, 1775).
partialOverlapping(1775, 196).
partialOverlapping(196, 192).
partialOverlapping(192, 1004).
partialOverlapping(1004, 1786).
partialOverlapping(1786, 826).
partialOverlapping(826, 673).
partialOverlapping(673, 1397).
partialOverlapping(1397, 1755).
partialOverlapping(1755, 943).
partialOverlapping(943, 1472).
partialOverlapping(1472, 1572).
partialOverlapping(1572, 1745).
partialOverlapping(1745, 1309).
partialOverlapping(1309, 1662).
partialOverlapping(1662, 1049).
partialOverlapping(1049, 1709).
partialOverlapping(1709, 1020).
partialOverlapping(1020, 232).
partialOverlapping(232, 514).
partialOverlapping(514, 1596).
partialOverlapping(1596, 909).
partialOverlapping(909, 731).
partialOverlapping(731, 1247).
partialOverlapping(1247, 406).
partialOverlapping(406, 706).
partialOverlapping(706, 1446).
