#program asprccgen.

room(0..399).

reachable(X, Y) :- reachable(Y, X), X!=Y.
reachable(X, Z) :- reachable(X, Y), reachable(Y,Z), X!=Y, Y!=Z, X!=Z.
reachable(X, Y) :- partialOverlapping(X, Y), room(X), room(Y).
partialOverlapping(106, 231).
partialOverlapping(231, 121).
partialOverlapping(121, 103).
partialOverlapping(103, 124).
partialOverlapping(124, 279).
partialOverlapping(279, 18).
partialOverlapping(18, 42).
partialOverlapping(42, 234).
partialOverlapping(234, 349).
partialOverlapping(349, 101).
partialOverlapping(101, 56).
partialOverlapping(56, 243).
partialOverlapping(243, 284).
partialOverlapping(284, 194).
partialOverlapping(194, 281).
partialOverlapping(281, 269).
partialOverlapping(269, 305).
partialOverlapping(305, 163).
partialOverlapping(163, 363).
partialOverlapping(363, 48).
partialOverlapping(48, 301).
partialOverlapping(301, 79).
partialOverlapping(79, 253).
partialOverlapping(253, 297).
partialOverlapping(297, 365).
partialOverlapping(365, 360).
partialOverlapping(360, 43).
partialOverlapping(43, 125).
partialOverlapping(125, 378).
partialOverlapping(378, 63).
partialOverlapping(63, 210).
partialOverlapping(210, 136).
partialOverlapping(136, 334).
partialOverlapping(334, 15).
partialOverlapping(15, 304).
partialOverlapping(304, 328).
partialOverlapping(328, 249).
partialOverlapping(249, 254).
partialOverlapping(254, 29).
partialOverlapping(29, 306).
partialOverlapping(306, 97).
partialOverlapping(97, 265).
partialOverlapping(265, 52).
partialOverlapping(52, 135).
partialOverlapping(135, 357).
partialOverlapping(357, 93).
partialOverlapping(93, 98).
partialOverlapping(98, 6).
partialOverlapping(6, 394).
partialOverlapping(394, 129).
partialOverlapping(129, 259).
partialOverlapping(259, 244).
partialOverlapping(244, 94).
partialOverlapping(94, 171).
partialOverlapping(171, 287).
partialOverlapping(287, 219).
partialOverlapping(219, 149).
partialOverlapping(149, 302).
partialOverlapping(302, 50).
partialOverlapping(50, 359).
partialOverlapping(359, 38).
partialOverlapping(38, 336).
partialOverlapping(336, 293).
partialOverlapping(293, 5).
partialOverlapping(5, 241).
partialOverlapping(241, 222).
partialOverlapping(222, 207).
partialOverlapping(207, 47).
partialOverlapping(47, 203).
partialOverlapping(203, 65).
partialOverlapping(65, 144).
partialOverlapping(144, 69).
partialOverlapping(69, 117).
partialOverlapping(117, 75).
partialOverlapping(75, 156).
partialOverlapping(156, 120).
partialOverlapping(120, 206).
partialOverlapping(206, 33).
partialOverlapping(33, 67).
partialOverlapping(67, 335).
partialOverlapping(335, 311).
partialOverlapping(311, 150).
partialOverlapping(150, 248).
partialOverlapping(248, 164).
partialOverlapping(164, 250).
partialOverlapping(250, 76).
partialOverlapping(76, 138).
partialOverlapping(138, 369).
partialOverlapping(369, 331).
partialOverlapping(331, 143).
partialOverlapping(143, 299).
partialOverlapping(299, 319).
partialOverlapping(319, 320).
partialOverlapping(320, 37).
partialOverlapping(37, 102).
partialOverlapping(102, 64).
partialOverlapping(64, 289).
partialOverlapping(289, 169).
partialOverlapping(169, 341).
partialOverlapping(341, 152).
partialOverlapping(152, 198).
partialOverlapping(198, 356).
partialOverlapping(356, 398).
partialOverlapping(398, 72).
partialOverlapping(72, 258).
partialOverlapping(258, 200).
partialOverlapping(200, 148).
partialOverlapping(148, 300).
partialOverlapping(300, 290).
partialOverlapping(290, 70).
partialOverlapping(70, 348).
partialOverlapping(348, 213).
partialOverlapping(213, 154).
partialOverlapping(154, 26).
partialOverlapping(26, 227).
partialOverlapping(227, 384).
partialOverlapping(384, 329).
partialOverlapping(329, 12).
partialOverlapping(12, 127).
partialOverlapping(127, 104).
partialOverlapping(104, 246).
partialOverlapping(246, 176).
partialOverlapping(176, 345).
partialOverlapping(345, 165).
partialOverlapping(165, 25).
partialOverlapping(25, 115).
partialOverlapping(115, 267).
partialOverlapping(267, 158).
partialOverlapping(158, 316).
partialOverlapping(316, 332).
partialOverlapping(332, 81).
partialOverlapping(81, 118).
partialOverlapping(118, 84).
partialOverlapping(84, 312).
partialOverlapping(312, 82).
partialOverlapping(82, 159).
partialOverlapping(159, 193).
partialOverlapping(193, 238).
partialOverlapping(238, 14).
partialOverlapping(14, 261).
partialOverlapping(261, 83).
partialOverlapping(83, 108).
partialOverlapping(108, 197).
partialOverlapping(197, 46).
partialOverlapping(46, 157).
partialOverlapping(157, 3).
partialOverlapping(3, 376).
partialOverlapping(376, 375).
partialOverlapping(375, 271).
partialOverlapping(271, 339).
partialOverlapping(339, 307).
partialOverlapping(307, 57).
partialOverlapping(57, 392).
partialOverlapping(392, 153).
partialOverlapping(153, 256).
partialOverlapping(256, 264).
partialOverlapping(264, 1).
partialOverlapping(1, 36).
partialOverlapping(36, 251).
partialOverlapping(251, 330).
partialOverlapping(330, 68).
partialOverlapping(68, 73).
partialOverlapping(73, 211).
partialOverlapping(211, 88).
partialOverlapping(88, 119).
partialOverlapping(119, 337).
partialOverlapping(337, 324).
partialOverlapping(324, 377).
partialOverlapping(377, 220).
partialOverlapping(220, 326).
partialOverlapping(326, 8).
partialOverlapping(8, 31).
partialOverlapping(31, 372).
partialOverlapping(372, 397).
partialOverlapping(397, 296).
partialOverlapping(296, 373).
partialOverlapping(373, 34).
partialOverlapping(34, 350).
partialOverlapping(350, 224).
partialOverlapping(224, 371).
partialOverlapping(371, 270).
partialOverlapping(270, 11).
partialOverlapping(11, 74).
partialOverlapping(74, 161).
partialOverlapping(161, 228).
partialOverlapping(228, 183).
partialOverlapping(183, 96).
partialOverlapping(96, 177).
partialOverlapping(177, 188).
partialOverlapping(188, 22).
partialOverlapping(22, 54).
partialOverlapping(54, 313).
partialOverlapping(313, 146).
partialOverlapping(146, 132).
partialOverlapping(132, 252).
partialOverlapping(252, 0).
partialOverlapping(0, 223).
partialOverlapping(223, 95).
partialOverlapping(95, 247).
