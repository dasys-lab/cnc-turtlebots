#program asprccgen.

room(0..799).

reachable(X, Y) :- reachable(Y, X), X!=Y.
reachable(X, Z) :- reachable(X, Y), reachable(Y,Z), X!=Y, Y!=Z, X!=Z.
reachable(X, Y) :- partialOverlapping(X, Y), room(X), room(Y).
partialOverlapping(506, 231).
partialOverlapping(231, 121).
partialOverlapping(121, 103).
partialOverlapping(103, 524).
partialOverlapping(524, 279).
partialOverlapping(279, 418).
partialOverlapping(418, 442).
partialOverlapping(442, 634).
partialOverlapping(634, 349).
partialOverlapping(349, 101).
partialOverlapping(101, 456).
partialOverlapping(456, 643).
partialOverlapping(643, 284).
partialOverlapping(284, 194).
partialOverlapping(194, 681).
partialOverlapping(681, 669).
partialOverlapping(669, 705).
partialOverlapping(705, 563).
partialOverlapping(563, 363).
partialOverlapping(363, 48).
partialOverlapping(48, 301).
partialOverlapping(301, 479).
partialOverlapping(479, 253).
partialOverlapping(253, 697).
partialOverlapping(697, 365).
partialOverlapping(365, 360).
partialOverlapping(360, 43).
partialOverlapping(43, 125).
partialOverlapping(125, 378).
partialOverlapping(378, 63).
partialOverlapping(63, 631).
partialOverlapping(631, 610).
partialOverlapping(610, 536).
partialOverlapping(536, 734).
partialOverlapping(734, 334).
partialOverlapping(334, 15).
partialOverlapping(15, 704).
partialOverlapping(704, 328).
partialOverlapping(328, 649).
partialOverlapping(649, 254).
partialOverlapping(254, 429).
partialOverlapping(429, 306).
partialOverlapping(306, 97).
partialOverlapping(97, 265).
partialOverlapping(265, 52).
partialOverlapping(52, 778).
partialOverlapping(778, 135).
partialOverlapping(135, 757).
partialOverlapping(757, 93).
partialOverlapping(93, 498).
partialOverlapping(498, 6).
partialOverlapping(6, 394).
partialOverlapping(394, 529).
partialOverlapping(529, 259).
partialOverlapping(259, 644).
partialOverlapping(644, 94).
partialOverlapping(94, 171).
partialOverlapping(171, 687).
partialOverlapping(687, 219).
partialOverlapping(219, 549).
partialOverlapping(549, 302).
partialOverlapping(302, 50).
partialOverlapping(50, 359).
partialOverlapping(359, 38).
partialOverlapping(38, 336).
partialOverlapping(336, 693).
partialOverlapping(693, 405).
partialOverlapping(405, 241).
partialOverlapping(241, 222).
partialOverlapping(222, 607).
partialOverlapping(607, 47).
partialOverlapping(47, 203).
partialOverlapping(203, 465).
partialOverlapping(465, 144).
partialOverlapping(144, 469).
partialOverlapping(469, 517).
partialOverlapping(517, 475).
partialOverlapping(475, 156).
partialOverlapping(156, 120).
partialOverlapping(120, 206).
partialOverlapping(206, 33).
partialOverlapping(33, 67).
partialOverlapping(67, 735).
partialOverlapping(735, 711).
partialOverlapping(711, 29).
partialOverlapping(29, 150).
partialOverlapping(150, 248).
partialOverlapping(248, 564).
partialOverlapping(564, 452).
partialOverlapping(452, 650).
partialOverlapping(650, 476).
partialOverlapping(476, 42).
partialOverlapping(42, 538).
partialOverlapping(538, 369).
partialOverlapping(369, 447).
partialOverlapping(447, 331).
partialOverlapping(331, 143).
partialOverlapping(143, 699).
partialOverlapping(699, 719).
partialOverlapping(719, 75).
partialOverlapping(75, 720).
partialOverlapping(720, 437).
partialOverlapping(437, 102).
partialOverlapping(102, 76).
partialOverlapping(76, 464).
partialOverlapping(464, 497).
partialOverlapping(497, 289).
partialOverlapping(289, 569).
partialOverlapping(569, 341).
partialOverlapping(341, 552).
partialOverlapping(552, 598).
partialOverlapping(598, 356).
partialOverlapping(356, 398).
partialOverlapping(398, 472).
partialOverlapping(472, 258).
partialOverlapping(258, 600).
partialOverlapping(600, 148).
partialOverlapping(148, 300).
partialOverlapping(300, 690).
partialOverlapping(690, 70).
partialOverlapping(70, 748).
partialOverlapping(748, 213).
partialOverlapping(213, 554).
partialOverlapping(554, 152).
partialOverlapping(152, 26).
partialOverlapping(26, 227).
partialOverlapping(227, 384).
partialOverlapping(384, 463).
partialOverlapping(463, 329).
partialOverlapping(329, 12).
partialOverlapping(12, 127).
partialOverlapping(127, 104).
partialOverlapping(104, 646).
partialOverlapping(646, 176).
partialOverlapping(176, 745).
partialOverlapping(745, 415).
partialOverlapping(415, 565).
partialOverlapping(565, 425).
partialOverlapping(425, 304).
partialOverlapping(304, 515).
partialOverlapping(515, 667).
partialOverlapping(667, 246).
partialOverlapping(246, 558).
partialOverlapping(558, 316).
partialOverlapping(316, 332).
partialOverlapping(332, 81).
partialOverlapping(81, 118).
partialOverlapping(118, 484).
partialOverlapping(484, 98).
partialOverlapping(98, 712).
partialOverlapping(712, 482).
partialOverlapping(482, 159).
partialOverlapping(159, 593).
partialOverlapping(593, 638).
partialOverlapping(638, 14).
partialOverlapping(14, 661).
partialOverlapping(661, 83).
partialOverlapping(83, 508).
partialOverlapping(508, 197).
partialOverlapping(197, 46).
partialOverlapping(46, 157).
partialOverlapping(157, 760).
partialOverlapping(760, 403).
partialOverlapping(403, 376).
partialOverlapping(376, 375).
partialOverlapping(375, 271).
partialOverlapping(271, 739).
partialOverlapping(739, 707).
partialOverlapping(707, 57).
partialOverlapping(57, 392).
partialOverlapping(392, 3).
partialOverlapping(3, 553).
partialOverlapping(553, 656).
partialOverlapping(656, 37).
partialOverlapping(37, 264).
partialOverlapping(264, 1).
partialOverlapping(1, 436).
partialOverlapping(436, 251).
partialOverlapping(251, 330).
partialOverlapping(330, 468).
partialOverlapping(468, 446).
partialOverlapping(446, 543).
partialOverlapping(543, 339).
partialOverlapping(339, 73).
partialOverlapping(73, 611).
partialOverlapping(611, 88).
partialOverlapping(88, 119).
partialOverlapping(119, 769).
partialOverlapping(769, 401).
partialOverlapping(401, 737).
partialOverlapping(737, 724).
partialOverlapping(724, 777).
partialOverlapping(777, 312).
partialOverlapping(312, 548).
partialOverlapping(548, 716).
partialOverlapping(716, 220).
partialOverlapping(220, 5).
partialOverlapping(5, 326).
partialOverlapping(326, 164).
partialOverlapping(164, 8).
partialOverlapping(8, 431).
partialOverlapping(431, 372).
partialOverlapping(372, 397).
partialOverlapping(397, 696).
partialOverlapping(696, 373).
partialOverlapping(373, 34).
partialOverlapping(34, 350).
partialOverlapping(350, 624).
partialOverlapping(624, 371).
partialOverlapping(371, 270).
partialOverlapping(270, 11).
partialOverlapping(11, 474).
partialOverlapping(474, 161).
partialOverlapping(161, 84).
partialOverlapping(84, 250).
partialOverlapping(250, 556).
partialOverlapping(556, 651).
partialOverlapping(651, 493).
partialOverlapping(493, 628).
partialOverlapping(628, 183).
partialOverlapping(183, 96).
partialOverlapping(96, 577).
partialOverlapping(577, 188).
partialOverlapping(188, 422).
partialOverlapping(422, 741).
partialOverlapping(741, 54).
partialOverlapping(54, 313).
partialOverlapping(313, 146).
partialOverlapping(146, 532).
partialOverlapping(532, 652).
partialOverlapping(652, 0).
partialOverlapping(0, 223).
partialOverlapping(223, 495).
partialOverlapping(495, 95).
partialOverlapping(95, 247).
partialOverlapping(247, 702).
partialOverlapping(702, 514).
partialOverlapping(514, 399).
partialOverlapping(399, 773).
partialOverlapping(773, 286).
partialOverlapping(286, 501).
partialOverlapping(501, 307).
partialOverlapping(307, 525).
partialOverlapping(525, 233).
partialOverlapping(233, 512).
partialOverlapping(512, 589).
partialOverlapping(589, 585).
partialOverlapping(585, 287).
partialOverlapping(287, 123).
partialOverlapping(123, 596).
partialOverlapping(596, 89).
partialOverlapping(89, 170).
partialOverlapping(170, 691).
partialOverlapping(691, 177).
partialOverlapping(177, 424).
partialOverlapping(424, 616).
partialOverlapping(616, 343).
partialOverlapping(343, 145).
partialOverlapping(145, 245).
partialOverlapping(245, 21).
partialOverlapping(21, 122).
partialOverlapping(122, 277).
partialOverlapping(277, 627).
partialOverlapping(627, 521).
partialOverlapping(521, 630).
partialOverlapping(630, 79).
partialOverlapping(79, 738).
partialOverlapping(738, 614).
partialOverlapping(614, 116).
partialOverlapping(116, 450).
partialOverlapping(450, 755).
partialOverlapping(755, 701).
partialOverlapping(701, 290).
partialOverlapping(290, 430).
partialOverlapping(430, 49).
partialOverlapping(49, 379).
partialOverlapping(379, 293).
partialOverlapping(293, 557).
partialOverlapping(557, 268).
partialOverlapping(268, 388).
partialOverlapping(388, 533).
partialOverlapping(533, 85).
partialOverlapping(85, 283).
partialOverlapping(283, 40).
partialOverlapping(40, 582).
partialOverlapping(582, 413).
partialOverlapping(413, 256).
partialOverlapping(256, 358).
partialOverlapping(358, 160).
partialOverlapping(160, 71).
partialOverlapping(71, 408).
partialOverlapping(408, 347).
partialOverlapping(347, 414).
partialOverlapping(414, 423).
partialOverlapping(423, 721).
partialOverlapping(721, 677).
partialOverlapping(677, 639).
partialOverlapping(639, 351).
partialOverlapping(351, 726).
partialOverlapping(726, 571).
partialOverlapping(571, 504).
partialOverlapping(504, 680).
partialOverlapping(680, 772).
partialOverlapping(772, 409).
partialOverlapping(409, 443).
partialOverlapping(443, 419).
partialOverlapping(419, 799).
partialOverlapping(799, 434).
partialOverlapping(434, 212).
partialOverlapping(212, 594).
partialOverlapping(594, 591).
partialOverlapping(591, 361).
partialOverlapping(361, 566).
partialOverlapping(566, 282).
partialOverlapping(282, 25).
partialOverlapping(25, 186).
partialOverlapping(186, 370).
partialOverlapping(370, 141).
partialOverlapping(141, 28).
partialOverlapping(28, 214).
partialOverlapping(214, 794).
partialOverlapping(794, 744).
partialOverlapping(744, 352).
partialOverlapping(352, 20).
partialOverlapping(20, 771).
partialOverlapping(771, 454).
partialOverlapping(454, 184).
partialOverlapping(184, 537).
partialOverlapping(537, 163).
partialOverlapping(163, 22).
partialOverlapping(22, 107).
partialOverlapping(107, 729).
partialOverlapping(729, 208).
partialOverlapping(208, 742).
partialOverlapping(742, 480).
partialOverlapping(480, 295).
partialOverlapping(295, 762).
partialOverlapping(762, 136).
partialOverlapping(136, 308).
partialOverlapping(308, 660).
partialOverlapping(660, 232).
partialOverlapping(232, 605).
partialOverlapping(605, 503).
partialOverlapping(503, 303).
partialOverlapping(303, 411).
partialOverlapping(411, 292).
partialOverlapping(292, 158).
partialOverlapping(158, 7).
partialOverlapping(7, 766).
partialOverlapping(766, 736).
partialOverlapping(736, 174).
partialOverlapping(174, 559).
partialOverlapping(559, 239).
partialOverlapping(239, 694).
partialOverlapping(694, 298).
partialOverlapping(298, 69).
partialOverlapping(69, 668).
partialOverlapping(668, 281).
partialOverlapping(281, 449).
partialOverlapping(449, 637).
partialOverlapping(637, 581).
partialOverlapping(581, 758).
partialOverlapping(758, 588).
partialOverlapping(588, 663).
partialOverlapping(663, 576).
partialOverlapping(576, 390).
partialOverlapping(390, 335).
partialOverlapping(335, 575).
partialOverlapping(575, 592).
partialOverlapping(592, 4).
partialOverlapping(4, 586).
partialOverlapping(586, 226).
partialOverlapping(226, 355).
partialOverlapping(355, 345).
partialOverlapping(345, 309).
partialOverlapping(309, 662).
partialOverlapping(662, 109).
partialOverlapping(109, 420).
partialOverlapping(420, 314).
partialOverlapping(314, 196).
partialOverlapping(196, 531).
partialOverlapping(531, 606).
partialOverlapping(606, 402).
partialOverlapping(402, 595).
partialOverlapping(595, 406).
partialOverlapping(406, 381).
partialOverlapping(381, 32).
partialOverlapping(32, 311).
partialOverlapping(311, 169).
partialOverlapping(169, 678).
partialOverlapping(678, 753).
partialOverlapping(753, 74).
partialOverlapping(74, 193).
partialOverlapping(193, 698).
partialOverlapping(698, 192).
partialOverlapping(192, 391).
partialOverlapping(391, 779).
partialOverlapping(779, 682).
partialOverlapping(682, 714).
partialOverlapping(714, 321).
partialOverlapping(321, 792).
partialOverlapping(792, 723).
partialOverlapping(723, 199).
partialOverlapping(199, 625).
partialOverlapping(625, 111).
partialOverlapping(111, 756).
partialOverlapping(756, 385).
partialOverlapping(385, 709).
partialOverlapping(709, 257).
partialOverlapping(257, 635).
partialOverlapping(635, 621).
partialOverlapping(621, 2).
partialOverlapping(2, 77).
partialOverlapping(77, 730).
partialOverlapping(730, 706).
partialOverlapping(706, 211).
partialOverlapping(211, 457).
partialOverlapping(457, 130).
partialOverlapping(130, 754).
partialOverlapping(754, 342).
partialOverlapping(342, 108).
partialOverlapping(108, 66).
partialOverlapping(66, 91).
partialOverlapping(91, 80).
partialOverlapping(80, 518).
partialOverlapping(518, 715).
partialOverlapping(715, 618).
partialOverlapping(618, 455).
partialOverlapping(455, 500).
partialOverlapping(500, 260).
partialOverlapping(260, 60).
partialOverlapping(60, 428).
partialOverlapping(428, 275).
partialOverlapping(275, 749).
partialOverlapping(749, 249).
partialOverlapping(249, 36).
partialOverlapping(36, 520).
partialOverlapping(520, 466).
partialOverlapping(466, 421).
partialOverlapping(421, 202).
partialOverlapping(202, 751).
partialOverlapping(751, 703).
partialOverlapping(703, 516).
partialOverlapping(516, 612).
partialOverlapping(612, 642).
partialOverlapping(642, 561).
partialOverlapping(561, 426).
partialOverlapping(426, 362).
partialOverlapping(362, 462).
partialOverlapping(462, 131).
partialOverlapping(131, 547).
partialOverlapping(547, 717).
partialOverlapping(717, 240).
partialOverlapping(240, 172).
partialOverlapping(172, 368).
partialOverlapping(368, 276).
partialOverlapping(276, 679).
partialOverlapping(679, 793).
partialOverlapping(793, 280).
partialOverlapping(280, 622).
partialOverlapping(622, 346).
partialOverlapping(346, 262).
partialOverlapping(262, 87).
partialOverlapping(87, 393).
partialOverlapping(393, 445).
partialOverlapping(445, 796).
partialOverlapping(796, 230).
partialOverlapping(230, 64).
partialOverlapping(64, 550).
partialOverlapping(550, 100).
partialOverlapping(100, 578).
partialOverlapping(578, 179).
partialOverlapping(179, 590).
partialOverlapping(590, 510).
partialOverlapping(510, 61).
partialOverlapping(61, 496).
partialOverlapping(496, 58).
partialOverlapping(58, 44).
partialOverlapping(44, 173).
partialOverlapping(173, 274).
partialOverlapping(274, 410).
partialOverlapping(410, 528).
partialOverlapping(528, 353).
partialOverlapping(353, 540).
partialOverlapping(540, 114).
partialOverlapping(114, 126).
partialOverlapping(126, 686).
partialOverlapping(686, 59).
partialOverlapping(59, 732).
partialOverlapping(732, 140).
partialOverlapping(140, 185).
partialOverlapping(185, 672).
partialOverlapping(672, 201).
partialOverlapping(201, 795).
partialOverlapping(795, 263).
partialOverlapping(263, 441).
partialOverlapping(441, 139).
partialOverlapping(139, 357).
partialOverlapping(357, 354).
partialOverlapping(354, 149).
partialOverlapping(149, 180).
partialOverlapping(180, 438).
partialOverlapping(438, 759).
partialOverlapping(759, 30).
partialOverlapping(30, 499).
partialOverlapping(499, 522).
partialOverlapping(522, 570).
partialOverlapping(570, 775).
partialOverlapping(775, 53).
partialOverlapping(53, 544).
partialOverlapping(544, 404).
partialOverlapping(404, 579).
partialOverlapping(579, 182).
partialOverlapping(182, 718).
partialOverlapping(718, 68).
partialOverlapping(68, 395).
partialOverlapping(395, 216).
partialOverlapping(216, 115).
partialOverlapping(115, 526).
partialOverlapping(526, 444).
partialOverlapping(444, 45).
partialOverlapping(45, 190).
partialOverlapping(190, 322).
partialOverlapping(322, 228).
partialOverlapping(228, 337).
partialOverlapping(337, 511).
partialOverlapping(511, 541).
partialOverlapping(541, 473).
partialOverlapping(473, 641).
partialOverlapping(641, 534).
partialOverlapping(534, 580).
partialOverlapping(580, 166).
partialOverlapping(166, 453).
partialOverlapping(453, 513).
partialOverlapping(513, 790).
partialOverlapping(790, 165).
partialOverlapping(165, 181).
partialOverlapping(181, 266).
partialOverlapping(266, 740).
partialOverlapping(740, 221).
partialOverlapping(221, 167).
partialOverlapping(167, 733).
partialOverlapping(733, 657).
partialOverlapping(657, 527).
partialOverlapping(527, 722).
partialOverlapping(722, 440).
partialOverlapping(440, 18).
partialOverlapping(18, 789).
partialOverlapping(789, 670).
partialOverlapping(670, 460).
partialOverlapping(460, 435).
partialOverlapping(435, 471).
partialOverlapping(471, 478).
partialOverlapping(478, 763).
partialOverlapping(763, 602).
partialOverlapping(602, 671).
partialOverlapping(671, 299).
partialOverlapping(299, 530).
partialOverlapping(530, 746).
partialOverlapping(746, 519).
partialOverlapping(519, 784).
partialOverlapping(784, 491).
partialOverlapping(491, 315).
partialOverlapping(315, 731).
partialOverlapping(731, 90).
partialOverlapping(90, 389).
partialOverlapping(389, 700).
partialOverlapping(700, 344).
partialOverlapping(344, 255).
partialOverlapping(255, 99).
partialOverlapping(99, 459).
partialOverlapping(459, 545).
partialOverlapping(545, 636).
partialOverlapping(636, 225).
partialOverlapping(225, 675).
partialOverlapping(675, 237).
partialOverlapping(237, 768).
partialOverlapping(768, 142).
partialOverlapping(142, 458).
partialOverlapping(458, 323).
partialOverlapping(323, 613).
partialOverlapping(613, 117).
partialOverlapping(117, 427).
partialOverlapping(427, 568).
partialOverlapping(568, 154).
partialOverlapping(154, 658).
partialOverlapping(658, 138).
partialOverlapping(138, 770).
partialOverlapping(770, 481).
partialOverlapping(481, 623).
partialOverlapping(623, 788).
partialOverlapping(788, 39).
partialOverlapping(39, 494).
partialOverlapping(494, 374).
partialOverlapping(374, 562).
partialOverlapping(562, 62).
partialOverlapping(62, 647).
partialOverlapping(647, 288).
partialOverlapping(288, 451).
