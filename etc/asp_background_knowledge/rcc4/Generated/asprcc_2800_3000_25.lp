#program asprccgen.

room(0..2799).

reachable(X, Y) :- reachable(Y, X), X!=Y.
reachable(X, Z) :- reachable(X, Y), reachable(Y,Z), X!=Y, Y!=Z, X!=Z.
reachable(X, Y) :- partialOverlapping(X, Y), room(X), room(Y).
partialOverlapping(263, 259).
partialOverlapping(259, 1662).
partialOverlapping(1662, 1228).
partialOverlapping(1228, 778).
partialOverlapping(778, 2379).
partialOverlapping(2379, 596).
partialOverlapping(596, 2515).
partialOverlapping(2515, 513).
partialOverlapping(513, 1061).
partialOverlapping(1061, 2131).
partialOverlapping(2131, 1196).
partialOverlapping(1196, 1279).
partialOverlapping(1279, 2148).
partialOverlapping(2148, 1781).
partialOverlapping(1781, 1064).
partialOverlapping(1064, 2141).
partialOverlapping(2141, 632).
partialOverlapping(632, 1847).
partialOverlapping(1847, 960).
partialOverlapping(960, 850).
partialOverlapping(850, 587).
partialOverlapping(587, 339).
partialOverlapping(339, 1784).
partialOverlapping(1784, 2686).
partialOverlapping(2686, 1586).
partialOverlapping(1586, 43).
partialOverlapping(43, 2636).
partialOverlapping(2636, 260).
partialOverlapping(260, 91).
partialOverlapping(91, 2274).
partialOverlapping(2274, 523).
partialOverlapping(523, 350).
partialOverlapping(350, 1136).
partialOverlapping(1136, 1751).
partialOverlapping(1751, 2680).
partialOverlapping(2680, 2267).
partialOverlapping(2267, 1099).
partialOverlapping(1099, 2395).
partialOverlapping(2395, 2780).
partialOverlapping(2780, 913).
partialOverlapping(913, 1726).
partialOverlapping(1726, 1176).
partialOverlapping(1176, 2192).
partialOverlapping(2192, 2626).
partialOverlapping(2626, 1709).
partialOverlapping(1709, 456).
partialOverlapping(456, 720).
partialOverlapping(720, 1093).
partialOverlapping(1093, 1055).
partialOverlapping(1055, 432).
partialOverlapping(432, 1943).
partialOverlapping(1943, 1643).
partialOverlapping(1643, 771).
partialOverlapping(771, 928).
partialOverlapping(928, 281).
partialOverlapping(281, 1110).
partialOverlapping(1110, 2523).
partialOverlapping(2523, 117).
partialOverlapping(117, 1370).
partialOverlapping(1370, 2614).
partialOverlapping(2614, 2392).
partialOverlapping(2392, 645).
partialOverlapping(645, 164).
partialOverlapping(164, 2280).
partialOverlapping(2280, 1148).
partialOverlapping(1148, 1597).
partialOverlapping(1597, 1748).
partialOverlapping(1748, 2247).
partialOverlapping(2247, 1192).
partialOverlapping(1192, 480).
partialOverlapping(480, 360).
partialOverlapping(360, 119).
partialOverlapping(119, 409).
partialOverlapping(409, 1304).
partialOverlapping(1304, 1497).
partialOverlapping(1497, 2118).
partialOverlapping(2118, 1760).
partialOverlapping(1760, 2217).
partialOverlapping(2217, 412).
partialOverlapping(412, 1568).
partialOverlapping(1568, 2650).
partialOverlapping(2650, 1107).
partialOverlapping(1107, 411).
partialOverlapping(411, 2173).
partialOverlapping(2173, 2035).
partialOverlapping(2035, 692).
partialOverlapping(692, 483).
partialOverlapping(483, 1759).
partialOverlapping(1759, 2362).
partialOverlapping(2362, 605).
partialOverlapping(605, 1573).
partialOverlapping(1573, 1954).
partialOverlapping(1954, 2).
partialOverlapping(2, 490).
partialOverlapping(490, 186).
partialOverlapping(186, 1150).
partialOverlapping(1150, 2087).
partialOverlapping(2087, 1934).
partialOverlapping(1934, 2150).
partialOverlapping(2150, 2031).
partialOverlapping(2031, 1167).
partialOverlapping(1167, 2510).
partialOverlapping(2510, 902).
partialOverlapping(902, 1576).
partialOverlapping(1576, 1015).
partialOverlapping(1015, 2400).
partialOverlapping(2400, 894).
partialOverlapping(894, 1527).
partialOverlapping(1527, 1817).
partialOverlapping(1817, 58).
partialOverlapping(58, 295).
partialOverlapping(295, 419).
partialOverlapping(419, 1166).
partialOverlapping(1166, 2258).
partialOverlapping(2258, 2593).
partialOverlapping(2593, 1953).
partialOverlapping(1953, 1703).
partialOverlapping(1703, 1828).
partialOverlapping(1828, 912).
partialOverlapping(912, 1265).
partialOverlapping(1265, 1186).
partialOverlapping(1186, 1238).
partialOverlapping(1238, 1971).
partialOverlapping(1971, 1188).
partialOverlapping(1188, 2157).
partialOverlapping(2157, 1091).
partialOverlapping(1091, 1319).
partialOverlapping(1319, 44).
partialOverlapping(44, 441).
partialOverlapping(441, 550).
partialOverlapping(550, 1211).
partialOverlapping(1211, 1453).
partialOverlapping(1453, 1539).
partialOverlapping(1539, 2718).
partialOverlapping(2718, 1053).
partialOverlapping(1053, 2433).
partialOverlapping(2433, 198).
partialOverlapping(198, 1622).
partialOverlapping(1622, 1244).
partialOverlapping(1244, 2045).
partialOverlapping(2045, 794).
partialOverlapping(794, 2410).
partialOverlapping(2410, 1504).
partialOverlapping(1504, 2139).
partialOverlapping(2139, 1563).
partialOverlapping(1563, 407).
partialOverlapping(407, 2719).
partialOverlapping(2719, 424).
partialOverlapping(424, 1105).
partialOverlapping(1105, 1218).
partialOverlapping(1218, 1046).
partialOverlapping(1046, 1698).
partialOverlapping(1698, 504).
partialOverlapping(504, 889).
partialOverlapping(889, 1769).
partialOverlapping(1769, 548).
partialOverlapping(548, 1330).
partialOverlapping(1330, 2319).
partialOverlapping(2319, 511).
partialOverlapping(511, 233).
partialOverlapping(233, 2524).
partialOverlapping(2524, 2050).
partialOverlapping(2050, 1704).
partialOverlapping(1704, 2329).
partialOverlapping(2329, 436).
partialOverlapping(436, 1902).
partialOverlapping(1902, 2704).
partialOverlapping(2704, 1680).
partialOverlapping(1680, 2699).
partialOverlapping(2699, 698).
partialOverlapping(698, 42).
partialOverlapping(42, 155).
partialOverlapping(155, 37).
partialOverlapping(37, 357).
partialOverlapping(357, 2114).
partialOverlapping(2114, 2756).
partialOverlapping(2756, 1585).
partialOverlapping(1585, 2538).
partialOverlapping(2538, 1555).
partialOverlapping(1555, 2133).
partialOverlapping(2133, 2412).
partialOverlapping(2412, 453).
partialOverlapping(453, 1390).
partialOverlapping(1390, 501).
partialOverlapping(501, 2222).
partialOverlapping(2222, 1938).
partialOverlapping(1938, 1831).
partialOverlapping(1831, 494).
partialOverlapping(494, 1202).
partialOverlapping(1202, 816).
partialOverlapping(816, 218).
partialOverlapping(218, 452).
partialOverlapping(452, 2520).
partialOverlapping(2520, 2548).
partialOverlapping(2548, 2440).
partialOverlapping(2440, 374).
partialOverlapping(374, 2452).
partialOverlapping(2452, 1320).
partialOverlapping(1320, 274).
partialOverlapping(274, 114).
partialOverlapping(114, 429).
partialOverlapping(429, 1939).
partialOverlapping(1939, 472).
partialOverlapping(472, 2544).
partialOverlapping(2544, 647).
partialOverlapping(647, 809).
partialOverlapping(809, 1034).
partialOverlapping(1034, 2013).
partialOverlapping(2013, 2365).
partialOverlapping(2365, 1920).
partialOverlapping(1920, 1625).
partialOverlapping(1625, 1570).
partialOverlapping(1570, 510).
partialOverlapping(510, 878).
partialOverlapping(878, 2545).
partialOverlapping(2545, 1200).
partialOverlapping(1200, 1461).
partialOverlapping(1461, 239).
partialOverlapping(239, 2402).
partialOverlapping(2402, 2278).
partialOverlapping(2278, 457).
partialOverlapping(457, 1607).
partialOverlapping(1607, 1998).
partialOverlapping(1998, 1757).
partialOverlapping(1757, 1247).
partialOverlapping(1247, 1125).
partialOverlapping(1125, 161).
partialOverlapping(161, 151).
partialOverlapping(151, 2063).
partialOverlapping(2063, 1434).
partialOverlapping(1434, 2132).
partialOverlapping(2132, 658).
partialOverlapping(658, 1876).
partialOverlapping(1876, 602).
partialOverlapping(602, 220).
partialOverlapping(220, 1663).
partialOverlapping(1663, 2615).
partialOverlapping(2615, 2585).
partialOverlapping(2585, 783).
partialOverlapping(783, 193).
partialOverlapping(193, 107).
partialOverlapping(107, 1293).
partialOverlapping(1293, 1071).
partialOverlapping(1071, 2652).
partialOverlapping(2652, 2493).
partialOverlapping(2493, 2533).
partialOverlapping(2533, 848).
partialOverlapping(848, 763).
partialOverlapping(763, 2101).
partialOverlapping(2101, 2455).
partialOverlapping(2455, 1513).
partialOverlapping(1513, 2610).
partialOverlapping(2610, 2454).
partialOverlapping(2454, 2638).
partialOverlapping(2638, 2772).
partialOverlapping(2772, 974).
partialOverlapping(974, 2789).
partialOverlapping(2789, 1161).
partialOverlapping(1161, 2122).
partialOverlapping(2122, 1990).
partialOverlapping(1990, 571).
partialOverlapping(571, 2750).
partialOverlapping(2750, 1344).
partialOverlapping(1344, 791).
partialOverlapping(791, 1613).
partialOverlapping(1613, 1159).
partialOverlapping(1159, 2128).
partialOverlapping(2128, 104).
partialOverlapping(104, 2236).
partialOverlapping(2236, 2441).
partialOverlapping(2441, 2728).
partialOverlapping(2728, 840).
partialOverlapping(840, 887).
partialOverlapping(887, 1213).
partialOverlapping(1213, 932).
partialOverlapping(932, 1735).
partialOverlapping(1735, 1976).
partialOverlapping(1976, 1785).
partialOverlapping(1785, 142).
partialOverlapping(142, 689).
partialOverlapping(689, 1595).
partialOverlapping(1595, 2596).
partialOverlapping(2596, 2080).
partialOverlapping(2080, 319).
partialOverlapping(319, 821).
partialOverlapping(821, 2355).
partialOverlapping(2355, 684).
partialOverlapping(684, 1695).
partialOverlapping(1695, 297).
partialOverlapping(297, 1255).
partialOverlapping(1255, 398).
partialOverlapping(398, 1641).
partialOverlapping(1641, 799).
partialOverlapping(799, 2011).
partialOverlapping(2011, 1552).
partialOverlapping(1552, 1679).
partialOverlapping(1679, 1912).
partialOverlapping(1912, 1657).
partialOverlapping(1657, 1115).
partialOverlapping(1115, 1553).
partialOverlapping(1553, 337).
partialOverlapping(337, 708).
partialOverlapping(708, 1550).
partialOverlapping(1550, 392).
partialOverlapping(392, 127).
partialOverlapping(127, 726).
partialOverlapping(726, 2177).
partialOverlapping(2177, 269).
partialOverlapping(269, 167).
partialOverlapping(167, 66).
partialOverlapping(66, 2389).
partialOverlapping(2389, 1821).
partialOverlapping(1821, 1151).
partialOverlapping(1151, 1825).
partialOverlapping(1825, 716).
partialOverlapping(716, 1448).
partialOverlapping(1448, 1832).
partialOverlapping(1832, 1114).
partialOverlapping(1114, 289).
partialOverlapping(289, 1383).
partialOverlapping(1383, 1878).
partialOverlapping(1878, 1841).
partialOverlapping(1841, 990).
partialOverlapping(990, 2250).
partialOverlapping(2250, 130).
partialOverlapping(130, 1295).
partialOverlapping(1295, 2587).
partialOverlapping(2587, 838).
partialOverlapping(838, 2488).
partialOverlapping(2488, 1337).
partialOverlapping(1337, 1230).
partialOverlapping(1230, 1367).
partialOverlapping(1367, 815).
partialOverlapping(815, 2159).
partialOverlapping(2159, 389).
partialOverlapping(389, 2535).
partialOverlapping(2535, 1884).
partialOverlapping(1884, 2007).
partialOverlapping(2007, 734).
partialOverlapping(734, 680).
partialOverlapping(680, 348).
partialOverlapping(348, 2555).
partialOverlapping(2555, 479).
partialOverlapping(479, 2757).
partialOverlapping(2757, 338).
partialOverlapping(338, 768).
partialOverlapping(768, 1341).
partialOverlapping(1341, 968).
partialOverlapping(968, 1361).
partialOverlapping(1361, 1604).
partialOverlapping(1604, 1958).
partialOverlapping(1958, 812).
partialOverlapping(812, 1734).
partialOverlapping(1734, 2006).
partialOverlapping(2006, 2151).
partialOverlapping(2151, 2573).
partialOverlapping(2573, 446).
partialOverlapping(446, 1813).
partialOverlapping(1813, 256).
partialOverlapping(256, 1915).
partialOverlapping(1915, 2202).
partialOverlapping(2202, 2791).
partialOverlapping(2791, 2551).
partialOverlapping(2551, 1409).
partialOverlapping(1409, 431).
partialOverlapping(431, 509).
partialOverlapping(509, 481).
partialOverlapping(481, 2262).
partialOverlapping(2262, 2682).
partialOverlapping(2682, 2505).
partialOverlapping(2505, 2741).
partialOverlapping(2741, 2640).
partialOverlapping(2640, 1596).
partialOverlapping(1596, 2261).
partialOverlapping(2261, 2733).
partialOverlapping(2733, 2564).
partialOverlapping(2564, 2374).
partialOverlapping(2374, 1537).
partialOverlapping(1537, 475).
partialOverlapping(475, 386).
partialOverlapping(386, 2023).
partialOverlapping(2023, 1233).
partialOverlapping(1233, 1979).
partialOverlapping(1979, 304).
partialOverlapping(304, 2244).
partialOverlapping(2244, 987).
partialOverlapping(987, 971).
partialOverlapping(971, 1647).
partialOverlapping(1647, 979).
partialOverlapping(979, 722).
partialOverlapping(722, 1808).
partialOverlapping(1808, 1705).
partialOverlapping(1705, 1153).
partialOverlapping(1153, 2318).
partialOverlapping(2318, 938).
partialOverlapping(938, 2167).
partialOverlapping(2167, 952).
partialOverlapping(952, 2196).
partialOverlapping(2196, 860).
partialOverlapping(860, 2344).
partialOverlapping(2344, 992).
partialOverlapping(992, 1873).
partialOverlapping(1873, 2277).
partialOverlapping(2277, 2308).
partialOverlapping(2308, 1447).
partialOverlapping(1447, 1014).
partialOverlapping(1014, 1535).
partialOverlapping(1535, 586).
partialOverlapping(586, 1790).
partialOverlapping(1790, 2768).
partialOverlapping(2768, 2338).
partialOverlapping(2338, 2642).
partialOverlapping(2642, 1092).
partialOverlapping(1092, 2042).
partialOverlapping(2042, 1491).
partialOverlapping(1491, 1773).
partialOverlapping(1773, 287).
partialOverlapping(287, 2051).
partialOverlapping(2051, 2230).
partialOverlapping(2230, 192).
partialOverlapping(192, 321).
partialOverlapping(321, 1921).
partialOverlapping(1921, 1111).
partialOverlapping(1111, 1274).
partialOverlapping(1274, 1317).
partialOverlapping(1317, 2370).
partialOverlapping(2370, 1044).
partialOverlapping(1044, 1848).
partialOverlapping(1848, 2121).
partialOverlapping(2121, 1614).
partialOverlapping(1614, 857).
partialOverlapping(857, 1830).
partialOverlapping(1830, 604).
partialOverlapping(604, 2377).
partialOverlapping(2377, 906).
partialOverlapping(906, 143).
partialOverlapping(143, 1225).
partialOverlapping(1225, 713).
partialOverlapping(713, 1069).
partialOverlapping(1069, 1507).
partialOverlapping(1507, 1103).
partialOverlapping(1103, 1312).
partialOverlapping(1312, 2033).
partialOverlapping(2033, 563).
partialOverlapping(563, 1463).
partialOverlapping(1463, 335).
partialOverlapping(335, 2437).
partialOverlapping(2437, 584).
partialOverlapping(584, 1446).
partialOverlapping(1446, 2463).
partialOverlapping(2463, 653).
partialOverlapping(653, 2170).
partialOverlapping(2170, 466).
partialOverlapping(466, 1966).
partialOverlapping(1966, 1081).
partialOverlapping(1081, 2588).
partialOverlapping(2588, 410).
partialOverlapping(410, 2197).
partialOverlapping(2197, 2052).
partialOverlapping(2052, 1774).
partialOverlapping(1774, 650).
partialOverlapping(650, 947).
partialOverlapping(947, 199).
partialOverlapping(199, 1363).
partialOverlapping(1363, 2485).
partialOverlapping(2485, 20).
partialOverlapping(20, 1623).
partialOverlapping(1623, 788).
partialOverlapping(788, 1332).
partialOverlapping(1332, 856).
partialOverlapping(856, 930).
partialOverlapping(930, 648).
partialOverlapping(648, 17).
partialOverlapping(17, 1837).
partialOverlapping(1837, 1656).
partialOverlapping(1656, 1464).
partialOverlapping(1464, 1500).
partialOverlapping(1500, 2309).
partialOverlapping(2309, 834).
partialOverlapping(834, 733).
partialOverlapping(733, 2776).
partialOverlapping(2776, 567).
partialOverlapping(567, 1316).
partialOverlapping(1316, 715).
partialOverlapping(715, 2015).
partialOverlapping(2015, 1707).
partialOverlapping(1707, 19).
partialOverlapping(19, 2487).
partialOverlapping(2487, 2358).
partialOverlapping(2358, 967).
partialOverlapping(967, 1439).
partialOverlapping(1439, 2473).
partialOverlapping(2473, 652).
partialOverlapping(652, 211).
partialOverlapping(211, 1296).
partialOverlapping(1296, 296).
partialOverlapping(296, 2152).
partialOverlapping(2152, 2674).
partialOverlapping(2674, 944).
partialOverlapping(944, 2692).
partialOverlapping(2692, 1533).
partialOverlapping(1533, 1356).
partialOverlapping(1356, 341).
partialOverlapping(341, 942).
partialOverlapping(942, 966).
partialOverlapping(966, 1869).
partialOverlapping(1869, 1246).
partialOverlapping(1246, 285).
partialOverlapping(285, 385).
partialOverlapping(385, 1961).
partialOverlapping(1961, 2300).
partialOverlapping(2300, 1098).
partialOverlapping(1098, 869).
partialOverlapping(869, 2320).
partialOverlapping(2320, 427).
partialOverlapping(427, 2039).
partialOverlapping(2039, 977).
partialOverlapping(977, 1652).
partialOverlapping(1652, 1443).
partialOverlapping(1443, 149).
partialOverlapping(149, 1635).
partialOverlapping(1635, 1484).
partialOverlapping(1484, 261).
partialOverlapping(261, 1180).
partialOverlapping(1180, 1477).
partialOverlapping(1477, 153).
partialOverlapping(153, 2713).
partialOverlapping(2713, 146).
partialOverlapping(146, 2651).
partialOverlapping(2651, 2755).
partialOverlapping(2755, 2665).
partialOverlapping(2665, 1720).
partialOverlapping(1720, 150).
partialOverlapping(150, 2106).
partialOverlapping(2106, 363).
partialOverlapping(363, 1203).
partialOverlapping(1203, 1956).
partialOverlapping(1956, 2784).
partialOverlapping(2784, 2275).
partialOverlapping(2275, 1494).
partialOverlapping(1494, 1963).
partialOverlapping(1963, 1514).
partialOverlapping(1514, 1223).
partialOverlapping(1223, 157).
partialOverlapping(157, 2517).
partialOverlapping(2517, 544).
partialOverlapping(544, 2648).
partialOverlapping(2648, 770).
partialOverlapping(770, 805).
partialOverlapping(805, 1029).
partialOverlapping(1029, 2248).
partialOverlapping(2248, 2511).
partialOverlapping(2511, 2494).
partialOverlapping(2494, 1393).
partialOverlapping(1393, 1258).
partialOverlapping(1258, 2081).
partialOverlapping(2081, 160).
partialOverlapping(160, 139).
partialOverlapping(139, 1797).
partialOverlapping(1797, 2095).
partialOverlapping(2095, 1782).
partialOverlapping(1782, 2342).
partialOverlapping(2342, 2497).
partialOverlapping(2497, 1104).
partialOverlapping(1104, 765).
partialOverlapping(765, 13).
partialOverlapping(13, 1929).
partialOverlapping(1929, 230).
partialOverlapping(230, 2109).
partialOverlapping(2109, 1778).
partialOverlapping(1778, 1001).
partialOverlapping(1001, 115).
partialOverlapping(115, 1559).
partialOverlapping(1559, 2001).
partialOverlapping(2001, 5).
partialOverlapping(5, 1350).
partialOverlapping(1350, 1398).
partialOverlapping(1398, 71).
partialOverlapping(71, 1278).
partialOverlapping(1278, 1408).
partialOverlapping(1408, 2712).
partialOverlapping(2712, 1569).
partialOverlapping(1569, 1043).
partialOverlapping(1043, 1710).
partialOverlapping(1710, 1684).
partialOverlapping(1684, 1890).
partialOverlapping(1890, 1275).
partialOverlapping(1275, 1432).
partialOverlapping(1432, 950).
partialOverlapping(950, 1145).
partialOverlapping(1145, 79).
partialOverlapping(79, 2685).
partialOverlapping(2685, 454).
partialOverlapping(454, 609).
partialOverlapping(609, 2438).
partialOverlapping(2438, 569).
partialOverlapping(569, 2168).
partialOverlapping(2168, 1639).
partialOverlapping(1639, 1947).
partialOverlapping(1947, 926).
partialOverlapping(926, 102).
partialOverlapping(102, 498).
partialOverlapping(498, 2324).
partialOverlapping(2324, 173).
partialOverlapping(173, 528).
partialOverlapping(528, 933).
partialOverlapping(933, 1077).
partialOverlapping(1077, 2502).
partialOverlapping(2502, 2120).
partialOverlapping(2120, 903).
partialOverlapping(903, 1386).
partialOverlapping(1386, 1210).
partialOverlapping(1210, 2661).
partialOverlapping(2661, 1395).
partialOverlapping(1395, 736).
partialOverlapping(736, 993).
partialOverlapping(993, 2345).
partialOverlapping(2345, 2138).
partialOverlapping(2138, 581).
partialOverlapping(581, 2592).
partialOverlapping(2592, 538).
partialOverlapping(538, 219).
partialOverlapping(219, 1914).
partialOverlapping(1914, 1458).
partialOverlapping(1458, 611).
partialOverlapping(611, 2384).
partialOverlapping(2384, 311).
partialOverlapping(311, 1909).
partialOverlapping(1909, 35).
partialOverlapping(35, 2797).
partialOverlapping(2797, 48).
partialOverlapping(48, 144).
partialOverlapping(144, 2323).
partialOverlapping(2323, 1041).
partialOverlapping(1041, 1241).
partialOverlapping(1241, 1467).
partialOverlapping(1467, 1931).
partialOverlapping(1931, 1170).
partialOverlapping(1170, 2048).
partialOverlapping(2048, 1723).
partialOverlapping(1723, 1708).
partialOverlapping(1708, 1019).
partialOverlapping(1019, 366).
partialOverlapping(366, 382).
partialOverlapping(382, 651).
partialOverlapping(651, 2751).
partialOverlapping(2751, 1095).
partialOverlapping(1095, 2514).
partialOverlapping(2514, 1860).
partialOverlapping(1860, 2285).
partialOverlapping(2285, 858).
partialOverlapping(858, 654).
partialOverlapping(654, 200).
partialOverlapping(200, 2443).
partialOverlapping(2443, 702).
partialOverlapping(702, 1787).
partialOverlapping(1787, 2136).
partialOverlapping(2136, 537).
partialOverlapping(537, 918).
partialOverlapping(918, 2184).
partialOverlapping(2184, 681).
partialOverlapping(681, 442).
partialOverlapping(442, 1977).
partialOverlapping(1977, 675).
partialOverlapping(675, 1108).
partialOverlapping(1108, 1845).
partialOverlapping(1845, 2709).
partialOverlapping(2709, 1584).
partialOverlapping(1584, 753).
partialOverlapping(753, 1173).
partialOverlapping(1173, 2671).
partialOverlapping(2671, 1311).
partialOverlapping(1311, 576).
partialOverlapping(576, 2622).
partialOverlapping(2622, 1158).
partialOverlapping(1158, 1843).
partialOverlapping(1843, 434).
partialOverlapping(434, 644).
partialOverlapping(644, 2701).
partialOverlapping(2701, 2396).
partialOverlapping(2396, 542).
partialOverlapping(542, 1384).
partialOverlapping(1384, 428).
partialOverlapping(428, 1431).
partialOverlapping(1431, 1347).
partialOverlapping(1347, 1354).
partialOverlapping(1354, 1789).
partialOverlapping(1789, 1545).
partialOverlapping(1545, 2029).
partialOverlapping(2029, 2450).
partialOverlapping(2450, 1405).
partialOverlapping(1405, 2359).
partialOverlapping(2359, 1741).
partialOverlapping(1741, 1667).
partialOverlapping(1667, 2003).
partialOverlapping(2003, 995).
partialOverlapping(995, 577).
partialOverlapping(577, 461).
partialOverlapping(461, 38).
