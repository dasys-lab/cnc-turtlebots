#program asprccgen.

room(0..899).

reachable(X, Y) :- reachable(Y, X), X!=Y.
reachable(X, Z) :- reachable(X, Y), reachable(Y,Z), X!=Y, Y!=Z, X!=Z.
reachable(X, Y) :- partialOverlapping(X, Y), room(X), room(Y).
partialOverlapping(406, 631).
partialOverlapping(631, 721).
partialOverlapping(721, 803).
partialOverlapping(803, 424).
partialOverlapping(424, 779).
partialOverlapping(779, 318).
partialOverlapping(318, 742).
partialOverlapping(742, 634).
partialOverlapping(634, 349).
partialOverlapping(349, 1).
partialOverlapping(1, 556).
partialOverlapping(556, 843).
partialOverlapping(843, 384).
partialOverlapping(384, 294).
partialOverlapping(294, 281).
partialOverlapping(281, 369).
partialOverlapping(369, 305).
partialOverlapping(305, 663).
partialOverlapping(663, 48).
partialOverlapping(48, 501).
partialOverlapping(501, 579).
partialOverlapping(579, 353).
partialOverlapping(353, 97).
partialOverlapping(97, 65).
partialOverlapping(65, 760).
partialOverlapping(760, 43).
partialOverlapping(43, 825).
partialOverlapping(825, 578).
partialOverlapping(578, 863).
partialOverlapping(863, 331).
partialOverlapping(331, 310).
partialOverlapping(310, 736).
partialOverlapping(736, 234).
partialOverlapping(234, 734).
partialOverlapping(734, 615).
partialOverlapping(615, 604).
partialOverlapping(604, 628).
partialOverlapping(628, 54).
partialOverlapping(54, 629).
partialOverlapping(629, 6).
partialOverlapping(6, 897).
partialOverlapping(897, 165).
partialOverlapping(165, 352).
partialOverlapping(352, 278).
partialOverlapping(278, 535).
partialOverlapping(535, 657).
partialOverlapping(657, 93).
partialOverlapping(93, 298).
partialOverlapping(298, 706).
partialOverlapping(706, 594).
partialOverlapping(594, 29).
partialOverlapping(29, 159).
partialOverlapping(159, 744).
partialOverlapping(744, 94).
partialOverlapping(94, 71).
partialOverlapping(71, 787).
partialOverlapping(787, 19).
partialOverlapping(19, 649).
partialOverlapping(649, 802).
partialOverlapping(802, 350).
partialOverlapping(350, 59).
partialOverlapping(59, 638).
partialOverlapping(638, 636).
partialOverlapping(636, 793).
partialOverlapping(793, 405).
partialOverlapping(405, 341).
partialOverlapping(341, 522).
partialOverlapping(522, 807).
partialOverlapping(807, 447).
partialOverlapping(447, 303).
partialOverlapping(303, 865).
partialOverlapping(865, 444).
partialOverlapping(444, 469).
partialOverlapping(469, 317).
partialOverlapping(317, 775).
partialOverlapping(775, 156).
partialOverlapping(156, 75).
partialOverlapping(75, 20).
partialOverlapping(20, 506).
partialOverlapping(506, 833).
partialOverlapping(833, 667).
partialOverlapping(667, 144).
partialOverlapping(144, 511).
partialOverlapping(511, 215).
partialOverlapping(215, 450).
partialOverlapping(450, 648).
partialOverlapping(648, 864).
partialOverlapping(864, 150).
partialOverlapping(150, 76).
partialOverlapping(76, 142).
partialOverlapping(142, 838).
partialOverlapping(838, 869).
partialOverlapping(869, 547).
partialOverlapping(547, 543).
partialOverlapping(543, 454).
partialOverlapping(454, 778).
partialOverlapping(778, 899).
partialOverlapping(899, 419).
partialOverlapping(419, 375).
partialOverlapping(375, 520).
partialOverlapping(520, 737).
partialOverlapping(737, 302).
partialOverlapping(302, 676).
partialOverlapping(676, 322).
partialOverlapping(322, 334).
partialOverlapping(334, 797).
partialOverlapping(797, 89).
partialOverlapping(89, 41).
partialOverlapping(41, 652).
partialOverlapping(652, 598).
partialOverlapping(598, 256).
partialOverlapping(256, 254).
partialOverlapping(254, 398).
partialOverlapping(398, 272).
partialOverlapping(272, 658).
partialOverlapping(658, 600).
partialOverlapping(600, 348).
partialOverlapping(348, 800).
partialOverlapping(800, 590).
partialOverlapping(590, 370).
partialOverlapping(370, 448).
partialOverlapping(448, 22).
partialOverlapping(22, 13).
partialOverlapping(13, 852).
partialOverlapping(852, 64).
partialOverlapping(64, 526).
partialOverlapping(526, 327).
partialOverlapping(327, 584).
partialOverlapping(584, 363).
partialOverlapping(363, 412).
partialOverlapping(412, 104).
partialOverlapping(104, 746).
partialOverlapping(746, 276).
partialOverlapping(276, 245).
partialOverlapping(245, 715).
partialOverlapping(715, 898).
partialOverlapping(898, 465).
partialOverlapping(465, 625).
partialOverlapping(625, 304).
partialOverlapping(304, 15).
partialOverlapping(15, 63).
partialOverlapping(63, 346).
partialOverlapping(346, 358).
partialOverlapping(358, 716).
partialOverlapping(716, 463).
partialOverlapping(463, 432).
partialOverlapping(432, 781).
partialOverlapping(781, 518).
partialOverlapping(518, 712).
partialOverlapping(712, 582).
partialOverlapping(582, 559).
partialOverlapping(559, 493).
partialOverlapping(493, 147).
partialOverlapping(147, 38).
partialOverlapping(38, 597).
partialOverlapping(597, 893).
partialOverlapping(893, 314).
partialOverlapping(314, 761).
partialOverlapping(761, 683).
partialOverlapping(683, 378).
partialOverlapping(378, 408).
partialOverlapping(408, 297).
partialOverlapping(297, 446).
partialOverlapping(446, 457).
partialOverlapping(457, 360).
partialOverlapping(360, 265).
partialOverlapping(265, 376).
partialOverlapping(376, 675).
partialOverlapping(675, 671).
partialOverlapping(671, 839).
partialOverlapping(839, 207).
partialOverlapping(207, 605).
partialOverlapping(605, 592).
partialOverlapping(592, 603).
partialOverlapping(603, 653).
partialOverlapping(653, 456).
partialOverlapping(456, 337).
partialOverlapping(337, 364).
partialOverlapping(364, 101).
partialOverlapping(101, 536).
partialOverlapping(536, 402).
partialOverlapping(402, 751).
partialOverlapping(751, 530).
partialOverlapping(530, 768).
partialOverlapping(768, 443).
partialOverlapping(443, 739).
partialOverlapping(739, 873).
partialOverlapping(873, 111).
partialOverlapping(111, 188).
partialOverlapping(188, 569).
partialOverlapping(569, 601).
partialOverlapping(601, 524).
partialOverlapping(524, 77).
partialOverlapping(77, 512).
partialOverlapping(512, 16).
partialOverlapping(16, 720).
partialOverlapping(720, 105).
partialOverlapping(105, 464).
partialOverlapping(464, 708).
partialOverlapping(708, 72).
partialOverlapping(72, 197).
partialOverlapping(197, 696).
partialOverlapping(696, 173).
partialOverlapping(173, 250).
partialOverlapping(250, 24).
partialOverlapping(24, 416).
partialOverlapping(416, 171).
partialOverlapping(171, 770).
partialOverlapping(770, 11).
partialOverlapping(11, 774).
partialOverlapping(774, 661).
partialOverlapping(661, 884).
partialOverlapping(884, 850).
partialOverlapping(850, 607).
partialOverlapping(607, 551).
partialOverlapping(551, 293).
partialOverlapping(293, 283).
partialOverlapping(283, 805).
partialOverlapping(805, 677).
partialOverlapping(677, 788).
partialOverlapping(788, 241).
partialOverlapping(241, 654).
partialOverlapping(654, 313).
partialOverlapping(313, 846).
partialOverlapping(846, 502).
partialOverlapping(502, 487).
partialOverlapping(487, 732).
partialOverlapping(732, 752).
partialOverlapping(752, 563).
partialOverlapping(563, 300).
partialOverlapping(300, 23).
partialOverlapping(23, 434).
partialOverlapping(434, 311).
partialOverlapping(311, 195).
partialOverlapping(195, 295).
partialOverlapping(295, 888).
partialOverlapping(888, 145).
partialOverlapping(145, 647).
partialOverlapping(647, 748).
partialOverlapping(748, 196).
partialOverlapping(196, 30).
partialOverlapping(30, 528).
partialOverlapping(528, 102).
partialOverlapping(102, 714).
partialOverlapping(714, 325).
partialOverlapping(325, 699).
partialOverlapping(699, 403).
partialOverlapping(403, 505).
partialOverlapping(505, 486).
partialOverlapping(486, 401).
partialOverlapping(401, 107).
partialOverlapping(107, 125).
partialOverlapping(125, 233).
partialOverlapping(233, 12).
partialOverlapping(12, 689).
partialOverlapping(689, 585).
partialOverlapping(585, 87).
partialOverlapping(87, 223).
partialOverlapping(223, 896).
partialOverlapping(896, 470).
partialOverlapping(470, 291).
partialOverlapping(291, 668).
partialOverlapping(668, 724).
partialOverlapping(724, 516).
partialOverlapping(516, 545).
partialOverlapping(545, 621).
partialOverlapping(621, 477).
partialOverlapping(477, 427).
partialOverlapping(427, 321).
partialOverlapping(321, 650).
partialOverlapping(650, 830).
partialOverlapping(830, 879).
partialOverlapping(879, 288).
partialOverlapping(288, 138).
partialOverlapping(138, 414).
partialOverlapping(414, 616).
partialOverlapping(616, 255).
partialOverlapping(255, 301).
partialOverlapping(301, 290).
partialOverlapping(290, 379).
partialOverlapping(379, 100).
partialOverlapping(100, 693).
partialOverlapping(693, 333).
partialOverlapping(333, 385).
partialOverlapping(385, 483).
partialOverlapping(483, 240).
partialOverlapping(240, 129).
partialOverlapping(129, 441).
partialOverlapping(441, 577).
partialOverlapping(577, 460).
partialOverlapping(460, 371).
partialOverlapping(371, 608).
partialOverlapping(608, 755).
partialOverlapping(755, 747).
partialOverlapping(747, 523).
partialOverlapping(523, 49).
partialOverlapping(49, 877).
partialOverlapping(877, 339).
partialOverlapping(339, 251).
partialOverlapping(251, 326).
partialOverlapping(326, 771).
partialOverlapping(771, 404).
partialOverlapping(404, 119).
partialOverlapping(119, 380).
partialOverlapping(380, 713).
partialOverlapping(713, 709).
partialOverlapping(709, 643).
partialOverlapping(643, 106).
partialOverlapping(106, 824).
partialOverlapping(824, 612).
partialOverlapping(612, 429).
partialOverlapping(429, 194).
partialOverlapping(194, 84).
partialOverlapping(84, 137).
partialOverlapping(137, 891).
partialOverlapping(891, 461).
partialOverlapping(461, 566).
partialOverlapping(566, 34).
partialOverlapping(34, 182).
partialOverlapping(182, 425).
partialOverlapping(425, 870).
partialOverlapping(870, 890).
partialOverlapping(890, 141).
partialOverlapping(141, 728).
partialOverlapping(728, 176).
partialOverlapping(176, 44).
partialOverlapping(44, 619).
partialOverlapping(619, 871).
partialOverlapping(871, 0).
partialOverlapping(0, 763).
partialOverlapping(763, 122).
partialOverlapping(122, 208).
partialOverlapping(208, 842).
partialOverlapping(842, 73).
partialOverlapping(73, 633).
partialOverlapping(633, 480).
partialOverlapping(480, 95).
partialOverlapping(95, 134).
partialOverlapping(134, 236).
partialOverlapping(236, 862).
partialOverlapping(862, 836).
partialOverlapping(836, 537).
partialOverlapping(537, 112).
partialOverlapping(112, 705).
partialOverlapping(705, 484).
partialOverlapping(484, 220).
partialOverlapping(220, 92).
partialOverlapping(92, 492).
partialOverlapping(492, 7).
partialOverlapping(7, 666).
partialOverlapping(666, 365).
partialOverlapping(365, 436).
partialOverlapping(436, 874).
partialOverlapping(874, 359).
partialOverlapping(359, 561).
partialOverlapping(561, 660).
partialOverlapping(660, 656).
partialOverlapping(656, 794).
partialOverlapping(794, 45).
partialOverlapping(45, 808).
partialOverlapping(808, 510).
partialOverlapping(510, 368).
partialOverlapping(368, 181).
partialOverlapping(181, 394).
partialOverlapping(394, 225).
partialOverlapping(225, 665).
partialOverlapping(665, 749).
partialOverlapping(749, 37).
partialOverlapping(37, 204).
partialOverlapping(204, 697).
partialOverlapping(697, 158).
partialOverlapping(158, 576).
partialOverlapping(576, 490).
partialOverlapping(490, 35).
partialOverlapping(35, 338).
partialOverlapping(338, 875).
partialOverlapping(875, 192).
partialOverlapping(192, 886).
partialOverlapping(886, 826).
partialOverlapping(826, 673).
partialOverlapping(673, 497).
partialOverlapping(497, 855).
partialOverlapping(855, 572).
partialOverlapping(572, 672).
partialOverlapping(672, 845).
partialOverlapping(845, 409).
partialOverlapping(409, 762).
partialOverlapping(762, 149).
partialOverlapping(149, 809).
partialOverlapping(809, 120).
partialOverlapping(120, 232).
partialOverlapping(232, 514).
partialOverlapping(514, 9).
partialOverlapping(9, 731).
partialOverlapping(731, 347).
partialOverlapping(347, 546).
partialOverlapping(546, 602).
partialOverlapping(602, 738).
partialOverlapping(738, 532).
partialOverlapping(532, 539).
partialOverlapping(539, 26).
partialOverlapping(26, 735).
partialOverlapping(735, 296).
partialOverlapping(296, 172).
partialOverlapping(172, 258).
partialOverlapping(258, 269).
partialOverlapping(269, 553).
partialOverlapping(553, 174).
partialOverlapping(174, 614).
partialOverlapping(614, 5).
partialOverlapping(5, 113).
partialOverlapping(113, 399).
partialOverlapping(399, 764).
partialOverlapping(764, 153).
partialOverlapping(153, 211).
partialOverlapping(211, 498).
partialOverlapping(498, 859).
partialOverlapping(859, 315).
partialOverlapping(315, 491).
partialOverlapping(491, 475).
partialOverlapping(475, 479).
partialOverlapping(479, 494).
partialOverlapping(494, 21).
partialOverlapping(21, 123).
partialOverlapping(123, 745).
partialOverlapping(745, 630).
partialOverlapping(630, 609).
partialOverlapping(609, 757).
partialOverlapping(757, 351).
partialOverlapping(351, 264).
partialOverlapping(264, 882).
partialOverlapping(882, 206).
partialOverlapping(206, 132).
partialOverlapping(132, 157).
partialOverlapping(157, 230).
partialOverlapping(230, 583).
partialOverlapping(583, 242).
partialOverlapping(242, 308).
partialOverlapping(308, 91).
partialOverlapping(91, 343).
partialOverlapping(343, 756).
partialOverlapping(756, 780).
partialOverlapping(780, 815).
partialOverlapping(815, 239).
partialOverlapping(239, 555).
partialOverlapping(555, 78).
partialOverlapping(78, 18).
partialOverlapping(18, 212).
partialOverlapping(212, 124).
partialOverlapping(124, 354).
partialOverlapping(354, 857).
partialOverlapping(857, 527).
partialOverlapping(527, 620).
partialOverlapping(620, 332).
partialOverlapping(332, 766).
partialOverlapping(766, 702).
partialOverlapping(702, 474).
partialOverlapping(474, 851).
partialOverlapping(851, 103).
partialOverlapping(103, 611).
partialOverlapping(611, 804).
partialOverlapping(804, 681).
partialOverlapping(681, 136).
partialOverlapping(136, 806).
partialOverlapping(806, 557).
partialOverlapping(557, 312).
partialOverlapping(312, 542).
partialOverlapping(542, 61).
partialOverlapping(61, 162).
partialOverlapping(162, 88).
partialOverlapping(88, 431).
partialOverlapping(431, 617).
partialOverlapping(617, 140).
partialOverlapping(140, 534).
partialOverlapping(534, 772).
partialOverlapping(772, 692).
partialOverlapping(692, 79).
partialOverlapping(79, 880).
partialOverlapping(880, 885).
partialOverlapping(885, 722).
partialOverlapping(722, 411).
partialOverlapping(411, 200).
partialOverlapping(200, 573).
partialOverlapping(573, 887).
partialOverlapping(887, 593).
partialOverlapping(593, 508).
partialOverlapping(508, 263).
partialOverlapping(263, 430).
partialOverlapping(430, 455).
partialOverlapping(455, 362).
partialOverlapping(362, 168).
partialOverlapping(168, 472).
partialOverlapping(472, 478).
partialOverlapping(478, 878).
partialOverlapping(878, 827).
partialOverlapping(827, 390).
partialOverlapping(390, 810).
partialOverlapping(810, 812).
partialOverlapping(812, 116).
partialOverlapping(116, 126).
partialOverlapping(126, 861).
partialOverlapping(861, 558).
partialOverlapping(558, 544).
partialOverlapping(544, 74).
partialOverlapping(74, 710).
partialOverlapping(710, 428).
partialOverlapping(428, 191).
partialOverlapping(191, 840).
partialOverlapping(840, 198).
partialOverlapping(198, 324).
partialOverlapping(324, 214).
partialOverlapping(214, 655).
partialOverlapping(655, 146).
partialOverlapping(146, 345).
partialOverlapping(345, 275).
partialOverlapping(275, 193).
partialOverlapping(193, 789).
partialOverlapping(789, 440).
partialOverlapping(440, 154).
partialOverlapping(154, 396).
partialOverlapping(396, 759).
partialOverlapping(759, 85).
partialOverlapping(85, 57).
partialOverlapping(57, 785).
partialOverlapping(785, 541).
partialOverlapping(541, 821).
partialOverlapping(821, 854).
partialOverlapping(854, 36).
partialOverlapping(36, 570).
partialOverlapping(570, 773).
partialOverlapping(773, 175).
partialOverlapping(175, 60).
partialOverlapping(60, 695).
partialOverlapping(695, 847).
partialOverlapping(847, 280).
partialOverlapping(280, 382).
partialOverlapping(382, 52).
partialOverlapping(52, 704).
partialOverlapping(704, 750).
partialOverlapping(750, 374).
partialOverlapping(374, 868).
partialOverlapping(868, 831).
partialOverlapping(831, 307).
partialOverlapping(307, 740).
partialOverlapping(740, 226).
partialOverlapping(226, 790).
partialOverlapping(790, 435).
partialOverlapping(435, 700).
partialOverlapping(700, 357).
partialOverlapping(357, 552).
partialOverlapping(552, 42).
partialOverlapping(42, 860).
partialOverlapping(860, 624).
partialOverlapping(624, 626).
partialOverlapping(626, 730).
partialOverlapping(730, 799).
partialOverlapping(799, 496).
partialOverlapping(496, 680).
partialOverlapping(680, 466).
partialOverlapping(466, 818).
partialOverlapping(818, 53).
partialOverlapping(53, 613).
partialOverlapping(613, 244).
partialOverlapping(244, 407).
partialOverlapping(407, 249).
partialOverlapping(249, 452).
partialOverlapping(452, 381).
partialOverlapping(381, 266).
partialOverlapping(266, 221).
partialOverlapping(221, 867).
partialOverlapping(867, 420).
partialOverlapping(420, 139).
partialOverlapping(139, 127).
partialOverlapping(127, 640).
partialOverlapping(640, 418).
partialOverlapping(418, 589).
partialOverlapping(589, 231).
partialOverlapping(231, 549).
partialOverlapping(549, 753).
partialOverlapping(753, 299).
partialOverlapping(299, 273).
partialOverlapping(273, 519).
partialOverlapping(519, 442).
partialOverlapping(442, 361).
partialOverlapping(361, 260).
partialOverlapping(260, 186).
partialOverlapping(186, 819).
partialOverlapping(819, 115).
partialOverlapping(115, 588).
partialOverlapping(588, 645).
partialOverlapping(645, 531).
partialOverlapping(531, 690).
partialOverlapping(690, 400).
partialOverlapping(400, 729).
partialOverlapping(729, 202).
partialOverlapping(202, 422).
partialOverlapping(422, 644).
partialOverlapping(644, 355).
partialOverlapping(355, 599).
partialOverlapping(599, 659).
partialOverlapping(659, 257).
partialOverlapping(257, 798).
partialOverlapping(798, 323).
partialOverlapping(323, 17).
partialOverlapping(17, 468).
partialOverlapping(468, 213).
partialOverlapping(213, 485).
partialOverlapping(485, 164).
partialOverlapping(164, 366).
partialOverlapping(366, 3).
partialOverlapping(3, 179).
partialOverlapping(179, 801).
partialOverlapping(801, 881).
partialOverlapping(881, 488).
partialOverlapping(488, 62).
partialOverlapping(62, 262).
partialOverlapping(262, 688).
partialOverlapping(688, 261).
partialOverlapping(261, 178).
partialOverlapping(178, 669).
partialOverlapping(669, 564).
partialOverlapping(564, 451).
partialOverlapping(451, 482).
partialOverlapping(482, 218).
partialOverlapping(218, 639).
partialOverlapping(639, 201).
partialOverlapping(201, 161).
partialOverlapping(161, 832).
partialOverlapping(832, 415).
partialOverlapping(415, 499).
partialOverlapping(499, 335).
partialOverlapping(335, 765).
partialOverlapping(765, 51).
partialOverlapping(51, 507).
partialOverlapping(507, 372).
partialOverlapping(372, 32).
partialOverlapping(32, 423).
partialOverlapping(423, 282).
partialOverlapping(282, 289).
partialOverlapping(289, 565).
partialOverlapping(565, 701).
partialOverlapping(701, 267).
partialOverlapping(267, 707).
partialOverlapping(707, 462).
partialOverlapping(462, 894).
partialOverlapping(894, 685).
partialOverlapping(685, 68).
partialOverlapping(68, 473).
partialOverlapping(473, 509).
partialOverlapping(509, 586).
partialOverlapping(586, 393).
partialOverlapping(393, 439).
partialOverlapping(439, 167).
partialOverlapping(167, 458).
partialOverlapping(458, 892).
partialOverlapping(892, 8).
partialOverlapping(8, 504).
partialOverlapping(504, 606).
partialOverlapping(606, 844).
partialOverlapping(844, 55).
partialOverlapping(55, 725).
partialOverlapping(725, 329).
partialOverlapping(329, 117).
partialOverlapping(117, 670).
partialOverlapping(670, 199).
partialOverlapping(199, 646).
partialOverlapping(646, 481).
partialOverlapping(481, 247).
partialOverlapping(247, 529).
partialOverlapping(529, 309).
partialOverlapping(309, 27).
partialOverlapping(27, 387).
partialOverlapping(387, 723).
partialOverlapping(723, 813).
