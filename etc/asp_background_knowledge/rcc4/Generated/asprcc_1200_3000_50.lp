#program asprccgen.

room(0..1199).

reachable(X, Y) :- reachable(Y, X), X!=Y.
reachable(X, Z) :- reachable(X, Y), reachable(Y,Z), X!=Y, Y!=Z, X!=Z.
reachable(X, Y) :- partialOverlapping(X, Y), room(X), room(Y).
partialOverlapping(106, 631).
partialOverlapping(631, 121).
partialOverlapping(121, 503).
partialOverlapping(503, 124).
partialOverlapping(124, 1079).
partialOverlapping(1079, 18).
partialOverlapping(18, 442).
partialOverlapping(442, 634).
partialOverlapping(634, 349).
partialOverlapping(349, 901).
partialOverlapping(901, 856).
partialOverlapping(856, 243).
partialOverlapping(243, 684).
partialOverlapping(684, 594).
partialOverlapping(594, 281).
partialOverlapping(281, 669).
partialOverlapping(669, 305).
partialOverlapping(305, 963).
partialOverlapping(963, 363).
partialOverlapping(363, 48).
partialOverlapping(48, 1101).
partialOverlapping(1101, 879).
partialOverlapping(879, 653).
partialOverlapping(653, 697).
partialOverlapping(697, 365).
partialOverlapping(365, 760).
partialOverlapping(760, 43).
partialOverlapping(43, 525).
partialOverlapping(525, 1178).
partialOverlapping(1178, 863).
partialOverlapping(863, 610).
partialOverlapping(610, 136).
partialOverlapping(136, 1134).
partialOverlapping(1134, 734).
partialOverlapping(734, 15).
partialOverlapping(15, 304).
partialOverlapping(304, 328).
partialOverlapping(328, 649).
partialOverlapping(649, 654).
partialOverlapping(654, 29).
partialOverlapping(29, 306).
partialOverlapping(306, 897).
partialOverlapping(897, 1065).
partialOverlapping(1065, 52).
partialOverlapping(52, 535).
partialOverlapping(535, 357).
partialOverlapping(357, 93).
partialOverlapping(93, 898).
partialOverlapping(898, 406).
partialOverlapping(406, 1194).
partialOverlapping(1194, 929).
partialOverlapping(929, 1059).
partialOverlapping(1059, 1044).
partialOverlapping(1044, 94).
partialOverlapping(94, 971).
partialOverlapping(971, 1087).
partialOverlapping(1087, 619).
partialOverlapping(619, 949).
partialOverlapping(949, 1102).
partialOverlapping(1102, 50).
partialOverlapping(50, 359).
partialOverlapping(359, 38).
partialOverlapping(38, 336).
partialOverlapping(336, 1093).
partialOverlapping(1093, 405).
partialOverlapping(405, 641).
partialOverlapping(641, 222).
partialOverlapping(222, 207).
partialOverlapping(207, 447).
partialOverlapping(447, 603).
partialOverlapping(603, 865).
partialOverlapping(865, 144).
partialOverlapping(144, 469).
partialOverlapping(469, 917).
partialOverlapping(917, 475).
partialOverlapping(475, 156).
partialOverlapping(156, 75).
partialOverlapping(75, 920).
partialOverlapping(920, 206).
partialOverlapping(206, 833).
partialOverlapping(833, 67).
partialOverlapping(67, 1135).
partialOverlapping(1135, 1111).
partialOverlapping(1111, 815).
partialOverlapping(815, 150).
partialOverlapping(150, 648).
partialOverlapping(648, 564).
partialOverlapping(564, 1050).
partialOverlapping(1050, 76).
partialOverlapping(76, 538).
partialOverlapping(538, 1169).
partialOverlapping(1169, 847).
partialOverlapping(847, 331).
partialOverlapping(331, 543).
partialOverlapping(543, 1054).
partialOverlapping(1054, 778).
partialOverlapping(778, 299).
partialOverlapping(299, 719).
partialOverlapping(719, 1120).
partialOverlapping(1120, 437).
partialOverlapping(437, 902).
partialOverlapping(902, 864).
partialOverlapping(864, 622).
partialOverlapping(622, 497).
partialOverlapping(497, 689).
partialOverlapping(689, 569).
partialOverlapping(569, 341).
partialOverlapping(341, 952).
partialOverlapping(952, 598).
partialOverlapping(598, 1156).
partialOverlapping(1156, 254).
partialOverlapping(254, 398).
partialOverlapping(398, 872).
partialOverlapping(872, 658).
partialOverlapping(658, 600).
partialOverlapping(600, 948).
partialOverlapping(948, 1100).
partialOverlapping(1100, 290).
partialOverlapping(290, 70).
partialOverlapping(70, 748).
partialOverlapping(748, 613).
partialOverlapping(613, 954).
partialOverlapping(954, 552).
partialOverlapping(552, 64).
partialOverlapping(64, 826).
partialOverlapping(826, 627).
partialOverlapping(627, 1184).
partialOverlapping(1184, 63).
partialOverlapping(63, 329).
partialOverlapping(329, 412).
partialOverlapping(412, 927).
partialOverlapping(927, 104).
partialOverlapping(104, 1046).
partialOverlapping(1046, 576).
partialOverlapping(576, 1145).
partialOverlapping(1145, 415).
partialOverlapping(415, 165).
partialOverlapping(165, 25).
partialOverlapping(25, 915).
partialOverlapping(915, 667).
partialOverlapping(667, 646).
partialOverlapping(646, 958).
partialOverlapping(958, 716).
partialOverlapping(716, 763).
partialOverlapping(763, 732).
partialOverlapping(732, 481).
partialOverlapping(481, 518).
partialOverlapping(518, 84).
partialOverlapping(84, 712).
partialOverlapping(712, 882).
partialOverlapping(882, 559).
partialOverlapping(559, 193).
partialOverlapping(193, 638).
partialOverlapping(638, 297).
partialOverlapping(297, 293).
partialOverlapping(293, 14).
partialOverlapping(14, 1061).
partialOverlapping(1061, 83).
partialOverlapping(83, 378).
partialOverlapping(378, 108).
partialOverlapping(108, 597).
partialOverlapping(597, 446).
partialOverlapping(446, 157).
partialOverlapping(157, 360).
partialOverlapping(360, 265).
partialOverlapping(265, 803).
partialOverlapping(803, 376).
partialOverlapping(376, 375).
partialOverlapping(375, 671).
partialOverlapping(671, 1139).
partialOverlapping(1139, 1107).
partialOverlapping(1107, 457).
partialOverlapping(457, 1192).
partialOverlapping(1192, 3).
partialOverlapping(3, 953).
partialOverlapping(953, 1056).
partialOverlapping(1056, 37).
partialOverlapping(37, 664).
partialOverlapping(664, 401).
partialOverlapping(401, 836).
partialOverlapping(836, 102).
partialOverlapping(102, 1051).
partialOverlapping(1051, 1130).
partialOverlapping(1130, 468).
partialOverlapping(468, 143).
partialOverlapping(143, 903).
partialOverlapping(903, 739).
partialOverlapping(739, 873).
partialOverlapping(873, 1011).
partialOverlapping(1011, 488).
partialOverlapping(488, 119).
partialOverlapping(119, 1).
partialOverlapping(1, 737).
partialOverlapping(737, 1124).
partialOverlapping(1124, 377).
partialOverlapping(377, 1112).
partialOverlapping(1112, 316).
partialOverlapping(316, 1020).
partialOverlapping(1020, 1126).
partialOverlapping(1126, 164).
partialOverlapping(164, 408).
partialOverlapping(408, 31).
partialOverlapping(31, 372).
partialOverlapping(372, 797).
partialOverlapping(797, 696).
partialOverlapping(696, 773).
partialOverlapping(773, 434).
partialOverlapping(434, 1150).
partialOverlapping(1150, 624).
partialOverlapping(624, 771).
partialOverlapping(771, 1070).
partialOverlapping(1070, 11).
partialOverlapping(11, 474).
partialOverlapping(474, 961).
partialOverlapping(961, 884).
partialOverlapping(884, 250).
partialOverlapping(250, 607).
partialOverlapping(607, 251).
partialOverlapping(251, 893).
partialOverlapping(893, 883).
partialOverlapping(883, 628).
partialOverlapping(628, 805).
partialOverlapping(805, 983).
partialOverlapping(983, 96).
partialOverlapping(96, 977).
partialOverlapping(977, 188).
partialOverlapping(188, 22).
partialOverlapping(22, 1141).
partialOverlapping(1141, 54).
partialOverlapping(54, 313).
partialOverlapping(313, 546).
partialOverlapping(546, 132).
partialOverlapping(132, 1052).
partialOverlapping(1052, 0).
partialOverlapping(0, 623).
partialOverlapping(623, 495).
partialOverlapping(495, 895).
partialOverlapping(895, 888).
partialOverlapping(888, 745).
partialOverlapping(745, 647).
partialOverlapping(647, 148).
partialOverlapping(148, 1096).
partialOverlapping(1096, 330).
partialOverlapping(330, 1128).
partialOverlapping(1128, 702).
partialOverlapping(702, 114).
partialOverlapping(114, 479).
partialOverlapping(479, 399).
partialOverlapping(399, 403).
partialOverlapping(403, 1086).
partialOverlapping(1086, 101).
partialOverlapping(101, 707).
partialOverlapping(707, 125).
partialOverlapping(125, 233).
partialOverlapping(233, 912).
partialOverlapping(912, 989).
partialOverlapping(989, 585).
partialOverlapping(585, 687).
partialOverlapping(687, 523).
partialOverlapping(523, 596).
partialOverlapping(596, 89).
partialOverlapping(89, 170).
partialOverlapping(170, 291).
partialOverlapping(291, 68).
partialOverlapping(68, 424).
partialOverlapping(424, 216).
partialOverlapping(216, 743).
partialOverlapping(743, 145).
partialOverlapping(145, 245).
partialOverlapping(245, 21).
partialOverlapping(21, 522).
partialOverlapping(522, 1077).
partialOverlapping(1077, 1027).
partialOverlapping(1027, 921).
partialOverlapping(921, 650).
partialOverlapping(650, 230).
partialOverlapping(230, 738).
partialOverlapping(738, 1014).
partialOverlapping(1014, 916).
partialOverlapping(916, 450).
partialOverlapping(450, 1155).
partialOverlapping(1155, 301).
partialOverlapping(301, 830).
partialOverlapping(830, 49).
partialOverlapping(49, 379).
partialOverlapping(379, 1000).
partialOverlapping(1000, 693).
partialOverlapping(693, 1068).
partialOverlapping(1068, 1188).
partialOverlapping(1188, 933).
partialOverlapping(933, 85).
partialOverlapping(85, 1083).
partialOverlapping(1083, 840).
partialOverlapping(840, 582).
partialOverlapping(582, 129).
partialOverlapping(129, 13).
partialOverlapping(13, 256).
partialOverlapping(256, 358).
partialOverlapping(358, 1041).
partialOverlapping(1041, 1177).
partialOverlapping(1177, 160).
partialOverlapping(160, 71).
partialOverlapping(71, 8).
partialOverlapping(8, 1048).
partialOverlapping(1048, 755).
partialOverlapping(755, 747).
partialOverlapping(747, 823).
partialOverlapping(823, 321).
partialOverlapping(321, 277).
partialOverlapping(277, 639).
partialOverlapping(639, 1151).
partialOverlapping(1151, 326).
partialOverlapping(326, 171).
partialOverlapping(171, 1019).
partialOverlapping(1019, 680).
partialOverlapping(680, 1172).
partialOverlapping(1172, 159).
partialOverlapping(159, 413).
partialOverlapping(413, 409).
partialOverlapping(409, 524).
partialOverlapping(524, 419).
partialOverlapping(419, 34).
partialOverlapping(34, 612).
partialOverlapping(612, 729).
partialOverlapping(729, 194).
partialOverlapping(194, 394).
partialOverlapping(394, 591).
partialOverlapping(591, 284).
partialOverlapping(284, 761).
partialOverlapping(761, 566).
partialOverlapping(566, 1082).
partialOverlapping(1082, 843).
partialOverlapping(843, 425).
partialOverlapping(425, 186).
partialOverlapping(186, 1170).
partialOverlapping(1170, 141).
partialOverlapping(141, 428).
partialOverlapping(428, 614).
partialOverlapping(614, 176).
partialOverlapping(176, 344).
partialOverlapping(344, 752).
partialOverlapping(752, 319).
partialOverlapping(319, 20).
partialOverlapping(20, 1171).
partialOverlapping(1171, 584).
partialOverlapping(584, 420).
partialOverlapping(420, 137).
partialOverlapping(137, 994).
partialOverlapping(994, 163).
partialOverlapping(163, 422).
partialOverlapping(422, 907).
partialOverlapping(907, 208).
partialOverlapping(208, 1142).
partialOverlapping(1142, 373).
partialOverlapping(373, 633).
partialOverlapping(633, 480).
partialOverlapping(480, 695).
partialOverlapping(695, 770).
partialOverlapping(770, 1162).
partialOverlapping(1162, 536).
partialOverlapping(536, 1137).
partialOverlapping(1137, 308).
partialOverlapping(308, 1060).
partialOverlapping(1060, 1032).
partialOverlapping(1032, 1005).
partialOverlapping(1005, 184).
partialOverlapping(184, 211).
partialOverlapping(211, 303).
partialOverlapping(303, 811).
partialOverlapping(811, 692).
partialOverlapping(692, 792).
partialOverlapping(792, 7).
partialOverlapping(7, 366).
partialOverlapping(366, 665).
partialOverlapping(665, 736).
partialOverlapping(736, 574).
partialOverlapping(574, 959).
partialOverlapping(959, 261).
partialOverlapping(261, 239).
partialOverlapping(239, 956).
partialOverlapping(956, 1094).
partialOverlapping(1094, 161).
partialOverlapping(161, 945).
partialOverlapping(945, 698).
partialOverlapping(698, 869).
partialOverlapping(869, 210).
partialOverlapping(210, 668).
partialOverlapping(668, 1081).
partialOverlapping(1081, 825).
partialOverlapping(825, 65).
partialOverlapping(65, 449).
partialOverlapping(449, 1037).
partialOverlapping(1037, 337).
partialOverlapping(337, 1104).
partialOverlapping(1104, 181).
partialOverlapping(181, 758).
partialOverlapping(758, 1063).
partialOverlapping(1063, 925).
partialOverlapping(925, 790).
partialOverlapping(790, 335).
partialOverlapping(335, 338).
partialOverlapping(338, 575).
partialOverlapping(575, 196).
partialOverlapping(196, 192).
partialOverlapping(192, 404).
partialOverlapping(404, 586).
partialOverlapping(586, 226).
partialOverlapping(226, 73).
partialOverlapping(73, 46).
partialOverlapping(46, 343).
partialOverlapping(343, 709).
partialOverlapping(709, 1062).
partialOverlapping(1062, 1049).
partialOverlapping(1049, 509).
partialOverlapping(509, 232).
partialOverlapping(232, 1114).
partialOverlapping(1114, 996).
partialOverlapping(996, 309).
partialOverlapping(309, 704).
partialOverlapping(704, 131).
partialOverlapping(131, 1006).
partialOverlapping(1006, 706).
partialOverlapping(706, 246).
partialOverlapping(246, 2).
partialOverlapping(2, 595).
partialOverlapping(595, 438).
partialOverlapping(438, 1181).
partialOverlapping(1181, 832).
partialOverlapping(832, 711).
partialOverlapping(711, 626).
partialOverlapping(626, 735).
partialOverlapping(735, 311).
partialOverlapping(311, 571).
partialOverlapping(571, 772).
partialOverlapping(772, 258).
partialOverlapping(258, 678).
partialOverlapping(678, 1153).
partialOverlapping(1153, 593).
partialOverlapping(593, 605).
partialOverlapping(605, 464).
partialOverlapping(464, 660).
partialOverlapping(660, 753).
partialOverlapping(753, 1098).
partialOverlapping(1098, 1159).
partialOverlapping(1159, 791).
partialOverlapping(791, 779).
partialOverlapping(779, 314).
partialOverlapping(314, 824).
partialOverlapping(824, 1071).
partialOverlapping(1071, 723).
partialOverlapping(723, 999).
partialOverlapping(999, 625).
partialOverlapping(625, 511).
partialOverlapping(511, 5).
partialOverlapping(5, 30).
partialOverlapping(30, 756).
partialOverlapping(756, 846).
partialOverlapping(846, 385).
partialOverlapping(385, 1057).
partialOverlapping(1057, 635).
partialOverlapping(635, 621).
partialOverlapping(621, 402).
partialOverlapping(402, 351).
partialOverlapping(351, 877).
partialOverlapping(877, 282).
partialOverlapping(282, 993).
partialOverlapping(993, 1106).
partialOverlapping(1106, 530).
partialOverlapping(530, 283).
partialOverlapping(283, 354).
partialOverlapping(354, 908).
partialOverlapping(908, 866).
partialOverlapping(866, 300).
partialOverlapping(300, 91).
partialOverlapping(91, 943).
partialOverlapping(943, 1147).
partialOverlapping(1147, 1115).
partialOverlapping(1115, 701).
partialOverlapping(701, 618).
partialOverlapping(618, 855).
partialOverlapping(855, 900).
partialOverlapping(900, 1095).
partialOverlapping(1095, 918).
partialOverlapping(918, 460).
partialOverlapping(460, 724).
partialOverlapping(724, 369).
partialOverlapping(369, 28).
partialOverlapping(28, 1075).
partialOverlapping(1075, 741).
partialOverlapping(741, 532).
partialOverlapping(532, 857).
partialOverlapping(857, 116).
partialOverlapping(116, 527).
partialOverlapping(527, 32).
partialOverlapping(32, 466).
partialOverlapping(466, 421).
partialOverlapping(421, 1002).
partialOverlapping(1002, 703).
partialOverlapping(703, 611).
partialOverlapping(611, 504).
partialOverlapping(504, 681).
partialOverlapping(681, 257).
partialOverlapping(257, 242).
partialOverlapping(242, 683).
partialOverlapping(683, 26).
partialOverlapping(26, 762).
partialOverlapping(762, 862).
partialOverlapping(862, 988).
partialOverlapping(988, 947).
partialOverlapping(947, 317).
partialOverlapping(317, 1040).
partialOverlapping(1040, 234).
partialOverlapping(234, 172).
partialOverlapping(172, 768).
partialOverlapping(768, 1197).
partialOverlapping(1197, 676).
partialOverlapping(676, 392).
partialOverlapping(392, 679).
partialOverlapping(679, 793).
partialOverlapping(793, 280).
partialOverlapping(280, 885).
partialOverlapping(885, 537).
partialOverlapping(537, 1022).
partialOverlapping(1022, 411).
partialOverlapping(411, 731).
partialOverlapping(731, 200).
partialOverlapping(200, 1173).
partialOverlapping(1173, 746).
partialOverlapping(746, 887).
partialOverlapping(887, 1193).
partialOverlapping(1193, 845).
partialOverlapping(845, 396).
partialOverlapping(396, 508).
partialOverlapping(508, 563).
partialOverlapping(563, 1030).
partialOverlapping(1030, 675).
partialOverlapping(675, 62).
partialOverlapping(62, 1179).
partialOverlapping(1179, 500).
partialOverlapping(500, 578).
partialOverlapping(578, 1038).
partialOverlapping(1038, 227).
partialOverlapping(227, 979).
partialOverlapping(979, 12).
partialOverlapping(12, 990).
partialOverlapping(990, 510).
partialOverlapping(510, 212).
partialOverlapping(212, 426).
partialOverlapping(426, 861).
partialOverlapping(861, 858).
partialOverlapping(858, 844).
partialOverlapping(844, 432).
partialOverlapping(432, 573).
partialOverlapping(573, 674).
partialOverlapping(674, 410).
partialOverlapping(410, 128).
partialOverlapping(128, 1091).
partialOverlapping(1091, 561).
partialOverlapping(561, 804).
partialOverlapping(804, 540).
partialOverlapping(540, 1024).
partialOverlapping(1024, 198).
partialOverlapping(198, 324).
partialOverlapping(324, 976).
partialOverlapping(976, 514).
partialOverlapping(514, 355).
partialOverlapping(355, 526).
partialOverlapping(526, 146).
partialOverlapping(146, 45).
partialOverlapping(45, 1165).
partialOverlapping(1165, 275).
partialOverlapping(275, 493).
partialOverlapping(493, 1089).
partialOverlapping(1089, 286).
partialOverlapping(286, 859).
partialOverlapping(859, 1163).
partialOverlapping(1163, 140).
partialOverlapping(140, 445).
partialOverlapping(445, 985).
partialOverlapping(985, 272).
partialOverlapping(272, 601).
partialOverlapping(601, 485).
partialOverlapping(485, 795).
partialOverlapping(795, 263).
partialOverlapping(263, 841).
partialOverlapping(841, 1121).
partialOverlapping(1121, 139).
partialOverlapping(139, 757).
partialOverlapping(757, 1154).
partialOverlapping(1154, 149).
partialOverlapping(149, 180).
partialOverlapping(180, 818).
partialOverlapping(818, 936).
partialOverlapping(936, 899).
partialOverlapping(899, 122).
partialOverlapping(122, 570).
partialOverlapping(570, 473).
partialOverlapping(473, 842).
partialOverlapping(842, 775).
