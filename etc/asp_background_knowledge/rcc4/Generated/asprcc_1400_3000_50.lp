#program asprccgen.

room(0..1399).

reachable(X, Y) :- reachable(Y, X), X!=Y.
reachable(X, Z) :- reachable(X, Y), reachable(Y,Z), X!=Y, Y!=Z, X!=Z.
reachable(X, Y) :- partialOverlapping(X, Y), room(X), room(Y).
partialOverlapping(906, 231).
partialOverlapping(231, 1321).
partialOverlapping(1321, 1103).
partialOverlapping(1103, 524).
partialOverlapping(524, 1279).
partialOverlapping(1279, 1218).
partialOverlapping(1218, 1042).
partialOverlapping(1042, 1234).
partialOverlapping(1234, 149).
partialOverlapping(149, 101).
partialOverlapping(101, 256).
partialOverlapping(256, 1043).
partialOverlapping(1043, 684).
partialOverlapping(684, 994).
partialOverlapping(994, 1081).
partialOverlapping(1081, 269).
partialOverlapping(269, 305).
partialOverlapping(305, 163).
partialOverlapping(163, 963).
partialOverlapping(963, 1048).
partialOverlapping(1048, 1101).
partialOverlapping(1101, 279).
partialOverlapping(279, 653).
partialOverlapping(653, 1097).
partialOverlapping(1097, 365).
partialOverlapping(365, 960).
partialOverlapping(960, 643).
partialOverlapping(643, 325).
partialOverlapping(325, 978).
partialOverlapping(978, 1063).
partialOverlapping(1063, 1231).
partialOverlapping(1231, 1210).
partialOverlapping(1210, 1136).
partialOverlapping(1136, 934).
partialOverlapping(934, 334).
partialOverlapping(334, 1015).
partialOverlapping(1015, 904).
partialOverlapping(904, 128).
partialOverlapping(128, 849).
partialOverlapping(849, 1054).
partialOverlapping(1054, 229).
partialOverlapping(229, 1106).
partialOverlapping(1106, 697).
partialOverlapping(697, 1065).
partialOverlapping(1065, 852).
partialOverlapping(852, 378).
partialOverlapping(378, 1335).
partialOverlapping(1335, 1157).
partialOverlapping(1157, 693).
partialOverlapping(693, 898).
partialOverlapping(898, 806).
partialOverlapping(806, 394).
partialOverlapping(394, 1329).
partialOverlapping(1329, 59).
partialOverlapping(59, 244).
partialOverlapping(244, 294).
partialOverlapping(294, 1171).
partialOverlapping(1171, 887).
partialOverlapping(887, 619).
partialOverlapping(619, 749).
partialOverlapping(749, 702).
partialOverlapping(702, 450).
partialOverlapping(450, 559).
partialOverlapping(559, 438).
partialOverlapping(438, 136).
partialOverlapping(136, 893).
partialOverlapping(893, 205).
partialOverlapping(205, 1041).
partialOverlapping(1041, 1022).
partialOverlapping(1022, 1207).
partialOverlapping(1207, 847).
partialOverlapping(847, 3).
partialOverlapping(3, 144).
partialOverlapping(144, 1069).
partialOverlapping(1069, 517).
partialOverlapping(517, 675).
partialOverlapping(675, 1156).
partialOverlapping(1156, 275).
partialOverlapping(275, 120).
partialOverlapping(120, 1233).
partialOverlapping(1233, 667).
partialOverlapping(667, 735).
partialOverlapping(735, 44).
partialOverlapping(44, 911).
partialOverlapping(911, 1029).
partialOverlapping(1029, 1215).
partialOverlapping(1215, 550).
partialOverlapping(550, 248).
partialOverlapping(248, 564).
partialOverlapping(564, 1252).
partialOverlapping(1252, 850).
partialOverlapping(850, 1276).
partialOverlapping(1276, 442).
partialOverlapping(442, 1138).
partialOverlapping(1138, 769).
partialOverlapping(769, 647).
partialOverlapping(647, 931).
partialOverlapping(931, 543).
partialOverlapping(543, 454).
partialOverlapping(454, 699).
partialOverlapping(699, 119).
partialOverlapping(119, 520).
partialOverlapping(520, 637).
partialOverlapping(637, 102).
partialOverlapping(102, 276).
partialOverlapping(276, 1064).
partialOverlapping(1064, 222).
partialOverlapping(222, 897).
partialOverlapping(897, 889).
partialOverlapping(889, 569).
partialOverlapping(569, 941).
partialOverlapping(941, 552).
partialOverlapping(552, 198).
partialOverlapping(198, 756).
partialOverlapping(756, 1254).
partialOverlapping(1254, 598).
partialOverlapping(598, 72).
partialOverlapping(72, 1258).
partialOverlapping(1258, 200).
partialOverlapping(200, 1348).
partialOverlapping(1348, 300).
partialOverlapping(300, 90).
partialOverlapping(90, 870).
partialOverlapping(870, 948).
partialOverlapping(948, 13).
partialOverlapping(13, 154).
partialOverlapping(154, 152).
partialOverlapping(152, 864).
partialOverlapping(864, 426).
partialOverlapping(426, 827).
partialOverlapping(827, 1384).
partialOverlapping(1384, 929).
partialOverlapping(929, 412).
partialOverlapping(412, 727).
partialOverlapping(727, 1304).
partialOverlapping(1304, 246).
partialOverlapping(246, 376).
partialOverlapping(376, 945).
partialOverlapping(945, 815).
partialOverlapping(815, 1317).
partialOverlapping(1317, 98).
partialOverlapping(98, 1165).
partialOverlapping(1165, 825).
partialOverlapping(825, 104).
partialOverlapping(104, 515).
partialOverlapping(515, 1363).
partialOverlapping(1363, 867).
partialOverlapping(867, 846).
partialOverlapping(846, 263).
partialOverlapping(263, 958).
partialOverlapping(958, 316).
partialOverlapping(316, 732).
partialOverlapping(732, 481).
partialOverlapping(481, 118).
partialOverlapping(118, 884).
partialOverlapping(884, 544).
partialOverlapping(544, 312).
partialOverlapping(312, 82).
partialOverlapping(82, 359).
partialOverlapping(359, 1393).
partialOverlapping(1393, 1238).
partialOverlapping(1238, 1297).
partialOverlapping(1297, 214).
partialOverlapping(214, 843).
partialOverlapping(843, 461).
partialOverlapping(461, 283).
partialOverlapping(283, 1093).
partialOverlapping(1093, 1108).
partialOverlapping(1108, 1197).
partialOverlapping(1197, 1046).
partialOverlapping(1046, 757).
partialOverlapping(757, 1160).
partialOverlapping(1160, 665).
partialOverlapping(665, 203).
partialOverlapping(203, 176).
partialOverlapping(176, 375).
partialOverlapping(375, 671).
partialOverlapping(671, 139).
partialOverlapping(139, 1107).
partialOverlapping(1107, 1305).
partialOverlapping(1305, 257).
partialOverlapping(257, 592).
partialOverlapping(592, 953).
partialOverlapping(953, 1056).
partialOverlapping(1056, 237).
partialOverlapping(237, 64).
partialOverlapping(64, 1201).
partialOverlapping(1201, 1036).
partialOverlapping(1036, 1302).
partialOverlapping(1302, 1251).
partialOverlapping(1251, 530).
partialOverlapping(530, 268).
partialOverlapping(268, 1143).
partialOverlapping(1143, 703).
partialOverlapping(703, 539).
partialOverlapping(539, 273).
partialOverlapping(273, 411).
partialOverlapping(411, 488).
partialOverlapping(488, 1319).
partialOverlapping(1319, 1169).
partialOverlapping(1169, 401).
partialOverlapping(401, 737).
partialOverlapping(737, 124).
partialOverlapping(124, 577).
partialOverlapping(577, 1112).
partialOverlapping(1112, 716).
partialOverlapping(716, 820).
partialOverlapping(820, 1005).
partialOverlapping(1005, 1126).
partialOverlapping(1126, 164).
partialOverlapping(164, 1008).
partialOverlapping(1008, 831).
partialOverlapping(831, 1372).
partialOverlapping(1372, 1397).
partialOverlapping(1397, 896).
partialOverlapping(896, 1173).
partialOverlapping(1173, 1034).
partialOverlapping(1034, 950).
partialOverlapping(950, 1024).
partialOverlapping(1024, 1371).
partialOverlapping(1371, 470).
partialOverlapping(470, 211).
partialOverlapping(211, 674).
partialOverlapping(674, 1161).
partialOverlapping(1161, 484).
partialOverlapping(484, 250).
partialOverlapping(250, 556).
partialOverlapping(556, 1007).
partialOverlapping(1007, 651).
partialOverlapping(651, 1293).
partialOverlapping(1293, 1283).
partialOverlapping(1283, 1228).
partialOverlapping(1228, 983).
partialOverlapping(983, 696).
partialOverlapping(696, 588).
partialOverlapping(588, 422).
partialOverlapping(422, 741).
partialOverlapping(741, 348).
partialOverlapping(348, 713).
partialOverlapping(713, 346).
partialOverlapping(346, 902).
partialOverlapping(902, 487).
partialOverlapping(487, 132).
partialOverlapping(132, 452).
partialOverlapping(452, 600).
partialOverlapping(600, 423).
partialOverlapping(423, 734).
partialOverlapping(734, 811).
partialOverlapping(811, 1250).
partialOverlapping(1250, 495).
partialOverlapping(495, 1295).
partialOverlapping(1295, 1088).
partialOverlapping(1088, 745).
partialOverlapping(745, 451).
partialOverlapping(451, 148).
partialOverlapping(148, 496).
partialOverlapping(496, 730).
partialOverlapping(730, 314).
partialOverlapping(314, 679).
partialOverlapping(679, 1399).
partialOverlapping(1399, 173).
partialOverlapping(173, 5).
partialOverlapping(5, 886).
partialOverlapping(886, 501).
partialOverlapping(501, 907).
partialOverlapping(907, 125).
partialOverlapping(125, 633).
partialOverlapping(633, 112).
partialOverlapping(112, 389).
partialOverlapping(389, 1385).
partialOverlapping(1385, 687).
partialOverlapping(687, 1123).
partialOverlapping(1123, 796).
partialOverlapping(796, 689).
partialOverlapping(689, 370).
partialOverlapping(370, 691).
partialOverlapping(691, 377).
partialOverlapping(377, 1268).
partialOverlapping(1268, 1224).
partialOverlapping(1224, 16).
partialOverlapping(16, 707).
partialOverlapping(707, 145).
partialOverlapping(145, 645).
partialOverlapping(645, 1021).
partialOverlapping(1021, 1122).
partialOverlapping(1122, 77).
partialOverlapping(77, 1121).
partialOverlapping(1121, 830).
partialOverlapping(830, 1288).
partialOverlapping(1288, 1331).
partialOverlapping(1331, 938).
partialOverlapping(938, 14).
partialOverlapping(14, 1050).
partialOverlapping(1050, 555).
partialOverlapping(555, 701).
partialOverlapping(701, 490).
partialOverlapping(490, 430).
partialOverlapping(430, 249).
partialOverlapping(249, 1179).
partialOverlapping(1179, 800).
partialOverlapping(800, 157).
partialOverlapping(157, 668).
partialOverlapping(668, 988).
partialOverlapping(988, 133).
partialOverlapping(133, 685).
partialOverlapping(685, 840).
partialOverlapping(840, 982).
partialOverlapping(982, 613).
partialOverlapping(613, 856).
partialOverlapping(856, 1158).
partialOverlapping(1158, 41).
partialOverlapping(41, 160).
partialOverlapping(160, 871).
partialOverlapping(871, 608).
partialOverlapping(608, 48).
partialOverlapping(48, 955).
partialOverlapping(955, 147).
partialOverlapping(147, 1349).
partialOverlapping(1349, 921).
partialOverlapping(921, 1277).
partialOverlapping(1277, 439).
partialOverlapping(439, 1351).
partialOverlapping(1351, 126).
partialOverlapping(126, 371).
partialOverlapping(371, 1219).
partialOverlapping(1219, 680).
partialOverlapping(680, 172).
partialOverlapping(172, 959).
partialOverlapping(959, 813).
partialOverlapping(813, 1009).
partialOverlapping(1009, 1243).
partialOverlapping(1243, 406).
partialOverlapping(406, 743).
partialOverlapping(743, 924).
partialOverlapping(924, 1019).
partialOverlapping(1019, 199).
partialOverlapping(199, 834).
partialOverlapping(834, 1212).
partialOverlapping(1212, 137).
partialOverlapping(137, 1194).
partialOverlapping(1194, 391).
partialOverlapping(391, 284).
partialOverlapping(284, 161).
partialOverlapping(161, 966).
partialOverlapping(966, 234).
partialOverlapping(234, 1082).
partialOverlapping(1082, 1186).
partialOverlapping(1186, 970).
partialOverlapping(970, 690).
partialOverlapping(690, 628).
partialOverlapping(628, 1014).
partialOverlapping(1014, 194).
partialOverlapping(194, 776).
partialOverlapping(776, 344).
partialOverlapping(344, 752).
partialOverlapping(752, 20).
partialOverlapping(20, 319).
partialOverlapping(319, 854).
partialOverlapping(854, 184).
partialOverlapping(184, 0).
partialOverlapping(0, 1020).
partialOverlapping(1020, 1129).
partialOverlapping(1129, 808).
partialOverlapping(808, 542).
partialOverlapping(542, 573).
partialOverlapping(573, 233).
partialOverlapping(233, 480).
partialOverlapping(480, 295).
partialOverlapping(295, 1170).
partialOverlapping(1170, 1236).
partialOverlapping(1236, 962).
partialOverlapping(962, 936).
partialOverlapping(936, 337).
partialOverlapping(337, 1308).
partialOverlapping(1308, 833).
partialOverlapping(833, 660).
partialOverlapping(660, 432).
partialOverlapping(432, 1184).
partialOverlapping(1184, 903).
partialOverlapping(903, 611).
partialOverlapping(611, 1211).
partialOverlapping(1211, 1292).
partialOverlapping(1292, 1192).
partialOverlapping(1192, 358).
partialOverlapping(358, 207).
partialOverlapping(207, 366).
partialOverlapping(366, 1336).
partialOverlapping(1336, 1174).
partialOverlapping(1174, 661).
partialOverlapping(661, 839).
partialOverlapping(839, 956).
partialOverlapping(956, 494).
partialOverlapping(494, 761).
partialOverlapping(761, 208).
partialOverlapping(208, 298).
partialOverlapping(298, 34).
partialOverlapping(34, 610).
partialOverlapping(610, 868).
partialOverlapping(868, 625).
partialOverlapping(625, 865).
partialOverlapping(865, 1237).
partialOverlapping(1237, 1137).
partialOverlapping(1137, 504).
partialOverlapping(504, 1181).
partialOverlapping(1181, 297).
partialOverlapping(297, 158).
partialOverlapping(158, 1388).
partialOverlapping(1388, 663).
partialOverlapping(663, 1376).
partialOverlapping(1376, 1325).
partialOverlapping(1325, 590).
partialOverlapping(590, 335).
partialOverlapping(335, 738).
partialOverlapping(738, 750).
partialOverlapping(750, 1175).
partialOverlapping(1175, 447).
partialOverlapping(447, 1396).
partialOverlapping(1396, 536).
partialOverlapping(536, 1392).
partialOverlapping(1392, 204).
partialOverlapping(204, 986).
partialOverlapping(986, 26).
partialOverlapping(26, 473).
partialOverlapping(473, 197).
partialOverlapping(197, 155).
partialOverlapping(155, 143).
partialOverlapping(143, 272).
partialOverlapping(272, 1172).
partialOverlapping(1172, 1145).
partialOverlapping(1145, 109).
partialOverlapping(109, 1062).
partialOverlapping(1062, 1309).
partialOverlapping(1309, 698).
partialOverlapping(698, 220).
partialOverlapping(220, 832).
partialOverlapping(832, 114).
partialOverlapping(114, 196).
partialOverlapping(196, 909).
partialOverlapping(909, 704).
partialOverlapping(704, 531).
partialOverlapping(531, 247).
partialOverlapping(247, 206).
partialOverlapping(206, 306).
partialOverlapping(306, 202).
partialOverlapping(202, 995).
partialOverlapping(995, 838).
partialOverlapping(838, 581).
partialOverlapping(581, 1032).
partialOverlapping(1032, 930).
partialOverlapping(930, 511).
partialOverlapping(511, 1339).
partialOverlapping(1339, 1226).
partialOverlapping(1226, 935).
partialOverlapping(935, 1111).
partialOverlapping(1111, 971).
partialOverlapping(971, 1196).
partialOverlapping(1196, 925).
partialOverlapping(925, 369).
partialOverlapping(369, 823).
partialOverlapping(823, 78).
partialOverlapping(78, 1353).
partialOverlapping(1353, 937).
partialOverlapping(937, 274).
partialOverlapping(274, 393).
partialOverlapping(393, 805).
partialOverlapping(805, 599).
partialOverlapping(599, 1264).
partialOverlapping(1264, 860).
partialOverlapping(860, 1011).
partialOverlapping(1011, 1359).
partialOverlapping(1359, 192).
partialOverlapping(192, 1315).
partialOverlapping(1315, 991).
partialOverlapping(991, 1275).
partialOverlapping(1275, 579).
partialOverlapping(579, 794).
partialOverlapping(794, 824).
partialOverlapping(824, 63).
partialOverlapping(63, 471).
partialOverlapping(471, 992).
partialOverlapping(992, 523).
partialOverlapping(523, 212).
partialOverlapping(212, 425).
partialOverlapping(425, 711).
partialOverlapping(711, 605).
partialOverlapping(605, 1230).
partialOverlapping(1230, 725).
partialOverlapping(725, 1356).
partialOverlapping(1356, 1246).
partialOverlapping(1246, 185).
partialOverlapping(185, 857).
partialOverlapping(857, 635).
partialOverlapping(635, 1202).
partialOverlapping(1202, 551).
partialOverlapping(551, 764).
partialOverlapping(764, 1077).
partialOverlapping(1077, 1282).
partialOverlapping(1282, 506).
partialOverlapping(506, 464).
partialOverlapping(464, 57).
partialOverlapping(57, 1154).
partialOverlapping(1154, 942).
partialOverlapping(942, 708).
partialOverlapping(708, 466).
partialOverlapping(466, 1343).
partialOverlapping(1343, 280).
partialOverlapping(280, 1318).
partialOverlapping(1318, 915).
partialOverlapping(915, 939).
partialOverlapping(939, 218).
partialOverlapping(218, 455).
partialOverlapping(455, 1178).
partialOverlapping(1178, 100).
partialOverlapping(100, 895).
partialOverlapping(895, 460).
partialOverlapping(460, 324).
partialOverlapping(324, 169).
partialOverlapping(169, 1028).
partialOverlapping(1028, 75).
partialOverlapping(75, 489).
partialOverlapping(489, 541).
partialOverlapping(541, 1049).
partialOverlapping(1049, 1332).
partialOverlapping(1332, 636).
partialOverlapping(636, 621).
partialOverlapping(621, 916).
partialOverlapping(916, 127).
partialOverlapping(127, 920).
partialOverlapping(920, 1066).
partialOverlapping(1066, 802).
partialOverlapping(802, 951).
partialOverlapping(951, 1176).
partialOverlapping(1176, 681).
partialOverlapping(681, 516).
partialOverlapping(516, 1006).
partialOverlapping(1006, 1261).
partialOverlapping(1261, 1257).
partialOverlapping(1257, 812).
partialOverlapping(812, 626).
partialOverlapping(626, 1362).
partialOverlapping(1362, 215).
partialOverlapping(215, 1262).
partialOverlapping(1262, 509).
partialOverlapping(509, 1366).
partialOverlapping(1366, 282).
partialOverlapping(282, 917).
partialOverlapping(917, 240).
partialOverlapping(240, 572).
partialOverlapping(572, 168).
partialOverlapping(168, 397).
partialOverlapping(397, 476).
partialOverlapping(476, 1079).
partialOverlapping(1079, 993).
partialOverlapping(993, 537).
partialOverlapping(537, 97).
partialOverlapping(97, 648).
partialOverlapping(648, 622).
partialOverlapping(622, 373).
partialOverlapping(373, 1146).
partialOverlapping(1146, 545).
partialOverlapping(545, 793).
partialOverlapping(793, 845).
partialOverlapping(845, 908).
partialOverlapping(908, 578).
partialOverlapping(578, 1355).
partialOverlapping(1355, 264).
partialOverlapping(264, 1150).
partialOverlapping(1150, 662).
partialOverlapping(662, 379).
partialOverlapping(379, 493).
partialOverlapping(493, 700).
partialOverlapping(700, 27).
partialOverlapping(27, 612).
partialOverlapping(612, 1310).
partialOverlapping(1310, 1116).
partialOverlapping(1116, 1209).
partialOverlapping(1209, 261).
partialOverlapping(261, 844).
partialOverlapping(844, 1232).
partialOverlapping(1232, 973).
partialOverlapping(973, 1274).
partialOverlapping(1274, 410).
partialOverlapping(410, 928).
partialOverlapping(928, 291).
partialOverlapping(291, 1204).
partialOverlapping(1204, 540).
partialOverlapping(540, 664).
partialOverlapping(664, 514).
partialOverlapping(514, 773).
partialOverlapping(773, 746).
partialOverlapping(746, 836).
partialOverlapping(836, 338).
partialOverlapping(338, 614).
partialOverlapping(614, 965).
partialOverlapping(965, 875).
partialOverlapping(875, 93).
partialOverlapping(93, 1289).
partialOverlapping(1289, 459).
partialOverlapping(459, 140).
partialOverlapping(140, 445).
partialOverlapping(445, 96).
partialOverlapping(96, 985).
partialOverlapping(985, 748).
partialOverlapping(748, 1285).
partialOverlapping(1285, 795).
partialOverlapping(795, 1263).
partialOverlapping(1263, 321).
partialOverlapping(321, 1141).
partialOverlapping(1141, 232).
partialOverlapping(232, 153).
partialOverlapping(153, 554).
partialOverlapping(554, 1180).
partialOverlapping(1180, 818).
partialOverlapping(818, 336).
partialOverlapping(336, 30).
partialOverlapping(30, 1299).
partialOverlapping(1299, 1091).
partialOverlapping(1091, 322).
partialOverlapping(322, 1306).
partialOverlapping(1306, 570).
partialOverlapping(570, 1273).
partialOverlapping(1273, 642).
partialOverlapping(642, 775).
partialOverlapping(775, 1390).
partialOverlapping(1390, 1222).
partialOverlapping(1222, 853).
partialOverlapping(853, 1147).
partialOverlapping(1147, 1379).
partialOverlapping(1379, 758).
partialOverlapping(758, 80).
partialOverlapping(80, 782).
partialOverlapping(782, 352).
partialOverlapping(352, 877).
partialOverlapping(877, 382).
partialOverlapping(382, 68).
partialOverlapping(68, 731).
partialOverlapping(731, 407).
partialOverlapping(407, 1131).
partialOverlapping(1131, 816).
partialOverlapping(816, 715).
partialOverlapping(715, 557).
partialOverlapping(557, 230).
partialOverlapping(230, 159).
partialOverlapping(159, 1140).
partialOverlapping(1140, 926).
partialOverlapping(926, 45).
partialOverlapping(45, 390).
partialOverlapping(390, 428).
partialOverlapping(428, 1284).
partialOverlapping(1284, 500).
partialOverlapping(500, 1311).
partialOverlapping(1311, 357).
partialOverlapping(357, 1383).
partialOverlapping(1383, 1352).
partialOverlapping(1352, 142).
partialOverlapping(142, 360).
partialOverlapping(360, 1203).
partialOverlapping(1203, 33).
partialOverlapping(33, 1241).
partialOverlapping(1241, 1326).
partialOverlapping(1326, 799).
partialOverlapping(799, 1223).
partialOverlapping(1223, 396).
partialOverlapping(396, 980).
partialOverlapping(980, 718).
partialOverlapping(718, 8).
partialOverlapping(8, 53).
partialOverlapping(53, 513).
partialOverlapping(513, 190).
partialOverlapping(190, 107).
partialOverlapping(107, 548).
partialOverlapping(548, 1149).
partialOverlapping(1149, 652).
partialOverlapping(652, 981).
partialOverlapping(981, 1012).
partialOverlapping(1012, 666).
partialOverlapping(666, 967).
partialOverlapping(967, 1220).
partialOverlapping(1220, 807).
partialOverlapping(807, 1061).
partialOverlapping(1061, 733).
partialOverlapping(733, 596).
partialOverlapping(596, 1074).
partialOverlapping(1074, 1127).
partialOverlapping(1127, 922).
partialOverlapping(922, 532).
partialOverlapping(532, 688).
partialOverlapping(688, 640).
partialOverlapping(640, 618).
partialOverlapping(618, 589).
partialOverlapping(589, 79).
partialOverlapping(79, 1270).
partialOverlapping(1270, 1060).
partialOverlapping(1060, 1035).
partialOverlapping(1035, 353).
partialOverlapping(353, 271).
partialOverlapping(271, 1078).
partialOverlapping(1078, 1216).
partialOverlapping(1216, 563).
