/****************************************************************************
 *
 *   Copyright (c) 2020-2022 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#include <stdint.h>

static constexpr float SAMPLING_RES = 10;
static constexpr float SAMPLING_MIN_LAT = -90;
static constexpr float SAMPLING_MAX_LAT = 90;
static constexpr float SAMPLING_MIN_LON = -180;
static constexpr float SAMPLING_MAX_LON = 180;

static constexpr int LAT_DIM = 19;
static constexpr int LON_DIM = 37;


// *INDENT-OFF*
// Magnetic declination data in radians * 10^-4
// Model: WMM-2020,
// Version: 0.5.1.11,
// Date: 2023.1781,
static constexpr const int16_t declination_table[19][37] {
	//    LONGITUDE:   -180,  -170,  -160,  -150,  -140,  -130,  -120,  -110,  -100,   -90,   -80,   -70,   -60,   -50,   -40,   -30,   -20,   -10,     0,    10,    20,    30,    40,    50,    60,    70,    80,    90,   100,   110,   120,   130,   140,   150,   160,   170,   180,
	/* LAT: -90 */ {  25971, 24226, 22480, 20735, 18990, 17244, 15499, 13754, 12008, 10263,  8518,  6772,  5027,  3282,  1537,  -209, -1954, -3699, -5444, -7190, -8935,-10680,-12426,-14171,-15916,-17662,-19407,-21152,-22898,-24643,-26389,-28134,-29879, 31207, 29462, 27716, 25971, },
	/* LAT: -80 */ {  22536, 20406, 18468, 16695, 15055, 13517, 12054, 10642,  9268,  7918,  6586,  5268,  3959,  2654,  1346,    26, -1315, -2688, -4099, -5552, -7048, -8585,-10164,-11784,-13449,-15168,-16955,-18828,-20811,-22931,-25206,-27640,-30209, 29985, 27368, 24864, 22536, },
	/* LAT: -70 */ {  14981, 13582, 12454, 11491, 10621,  9788,  8945,  8057,  7104,  6084,  5014,  3922,  2837,  1783,   762,  -248, -1286, -2393, -3596, -4899, -6282, -7714, -9163,-10606,-12033,-13450,-14880,-16367,-17993,-19912,-22441,-26251, 30662, 24122, 19621, 16852, 14981, },
	/* LAT: -60 */ {   8434,  8185,  7902,  7625,  7370,  7114,  6804,  6370,  5754,  4933,  3931,  2819,  1701,   676,  -202,  -957, -1686, -2511, -3519, -4721, -6057, -7430, -8753, -9964,-11028,-11926,-12640,-13135,-13306,-12858,-10752, -3456,  4964,  7689,  8451,  8572,  8434, },
	/* LAT: -50 */ {   5495,  5531,  5473,  5382,  5306,  5267,  5231,  5103,  4757,  4092,  3080,  1806,   467,  -709, -1573, -2130, -2523, -2965, -3657, -4681, -5934, -7216, -8359, -9259, -9853,-10088, -9888, -9126, -7612, -5247, -2340,   409,  2519,  3944,  4818,  5292,  5495, },
	/* LAT: -40 */ {   3962,  4054,  4061,  4014,  3952,  3917,  3921,  3909,  3734,  3197,  2170,   725,  -837, -2145, -3000, -3442, -3619, -3675, -3850, -4435, -5428, -6511, -7395, -7929, -8028, -7642, -6745, -5357, -3648, -1950,  -493,   727,  1772,  2640,  3298,  3730,  3962, },
	/* LAT: -30 */ {   2990,  3076,  3104,  3088,  3027,  2947,  2886,  2852,  2724,  2243,  1202,  -321, -1928, -3174, -3905, -4242, -4313, -4093, -3658, -3452, -3838, -4596, -5291, -5633, -5498, -4902, -3938, -2733, -1531,  -593,    81,   680,  1306,  1912,  2425,  2789,  2990, },
	/* LAT: -20 */ {   2347,  2393,  2408,  2407,  2363,  2267,  2158,  2080,  1935,  1436,   374, -1120, -2597, -3650, -4172, -4279, -4067, -3500, -2635, -1848, -1591, -1959, -2609, -3072, -3100, -2735, -2096, -1283,  -513,   -30,   228,   528,   972,  1455,  1881,  2192,  2347, },
	/* LAT: -10 */ {   1954,  1947,  1923,  1917,  1887,  1801,  1688,  1596,  1411,   858,  -209, -1590, -2860, -3680, -3935, -3697, -3115, -2331, -1485,  -736,  -280,  -324,  -799, -1303, -1511, -1417, -1102,  -605,  -113,   123,   167,   325,   698,  1142,  1540,  1832,  1954, },
	/* LAT:   0 */ {   1740,  1706,  1648,  1637,  1623,  1552,  1444,  1328,  1073,   451,  -592, -1819, -2869, -3446, -3433, -2925, -2154, -1374,  -724,  -191,   219,   324,    39,  -378,  -630,  -684,  -585,  -325,   -39,    45,   -21,    65,   410,   858,  1284,  1608,  1740, },
	/* LAT:  10 */ {   1603,  1610,  1566,  1580,  1604,  1552,  1427,  1238,   862,   144,  -877, -1952, -2773, -3103, -2891, -2279, -1502,  -793,  -280,    98,   422,   567,   401,    79,  -154,  -262,  -287,  -210,  -108,  -154,  -298,  -273,    32,   492,   978,  1390,  1603, },
	/* LAT:  20 */ {   1415,  1563,  1623,  1713,  1798,  1776,  1618,  1314,   769,   -86, -1127, -2075, -2665, -2768, -2434, -1829, -1119,  -471,   -14,   294,   552,   695,   602,   358,   160,    41,   -54,  -123,  -207,  -400,  -640,  -699,  -462,   -10,   535,  1056,  1415, },
	/* LAT:  30 */ {   1108,  1474,  1734,  1958,  2117,  2127,  1938,  1514,   787,  -240, -1354, -2225, -2634, -2567, -2166, -1585,  -930,  -313,   147,   451,   681,   826,   803,   653,   505,   379,   217,     0,  -287,  -664, -1034, -1193, -1031,  -602,   -23,   587,  1108, },
	/* LAT:  40 */ {    744,  1330,  1825,  2218,  2468,  2512,  2296,  1763,   854,  -370, -1602, -2462, -2778, -2624, -2177, -1584,  -930,  -302,   207,   570,   839,  1035,  1127,  1115,  1039,   889,   615,   197,  -347,  -956, -1477, -1719, -1600, -1182,  -584,    87,   744, },
	/* LAT:  50 */ {    447,  1192,  1874,  2434,  2803,  2911,  2684,  2033,   896,  -593, -2007, -2915, -3207, -3015, -2525, -1879, -1169,  -472,   143,   647,  1064,  1417,  1695,  1864,  1881,  1690,  1238,   521,  -379, -1283, -1959, -2241, -2114, -1674, -1042,  -314,   447, },
	/* LAT:  60 */ {    240,  1090,  1896,  2595,  3104,  3321,  3113,  2310,   809, -1134, -2840, -3816, -4070, -3811, -3241, -2497, -1672,  -832,   -25,   725,  1416,  2045,  2586,  2979,  3134,  2941,  2292,  1164,  -258, -1577, -2439, -2744, -2577, -2086, -1399,  -605,   240, },
	/* LAT:  70 */ {    -16,   917,  1813,  2614,  3233,  3535,  3296,  2189,    -3, -2675, -4619, -5453, -5473, -4998, -4235, -3304, -2283, -1220,  -147,   912,  1936,  2901,  3767,  4472,  4915,  4939,  4317,  2825,   615, -1495, -2788, -3227, -3069, -2542, -1799,  -937,   -16, },
	/* LAT:  80 */ {   -789,   131,   981,  1673,  2062,  1900,   770, -1693, -4770, -6881, -7673, -7582, -6982, -6085, -5007, -3818, -2559, -1259,    63,  1388,  2701,  3983,  5210,  6349,  7347,  8109,  8452,  7997,  6024,  2144, -1513, -3223, -3574, -3238, -2559, -1710,  -789, },
	/* LAT:  90 */ { -29599,-27853,-26108,-24362,-22617,-20871,-19126,-17381,-15636,-13890,-12145,-10400, -8655, -6910, -5164, -3419, -1674,    71,  1816,  3561,  5307,  7052,  8797, 10542, 12288, 14033, 15778, 17524, 19269, 21015, 22760, 24506, 26251, 27997, 29742,-31344,-29599, },
};

// Magnetic inclination data in radians * 10^-4
// Model: WMM-2020,
// Version: 0.5.1.11,
// Date: 2023.1781,
static constexpr const int16_t inclination_table[19][37] {
	//    LONGITUDE:   -180,  -170,  -160,  -150,  -140,  -130,  -120,  -110,  -100,   -90,   -80,   -70,   -60,   -50,   -40,   -30,   -20,   -10,     0,    10,    20,    30,    40,    50,    60,    70,    80,    90,   100,   110,   120,   130,   140,   150,   160,   170,   180,
	/* LAT: -90 */ { -12568,-12568,-12568,-12568,-12568,-12568,-12568,-12567,-12567,-12567,-12567,-12567,-12567,-12567,-12567,-12567,-12567,-12567,-12567,-12567,-12567,-12567,-12567,-12567,-12567,-12567,-12568,-12568,-12568,-12568,-12568,-12568,-12568,-12568,-12568,-12568,-12568, },
	/* LAT: -80 */ { -13651,-13517,-13357,-13176,-12983,-12781,-12577,-12377,-12187,-12011,-11854,-11720,-11610,-11524,-11460,-11419,-11399,-11401,-11428,-11482,-11566,-11681,-11826,-11999,-12198,-12415,-12644,-12877,-13105,-13318,-13504,-13654,-13757,-13808,-13804,-13750,-13651, },
	/* LAT: -70 */ { -14099,-13780,-13461,-13138,-12807,-12463,-12108,-11751,-11409,-11101,-10849,-10666,-10554,-10502,-10488,-10490,-10496,-10504,-10527,-10583,-10691,-10866,-11113,-11429,-11803,-12221,-12669,-13134,-13600,-14052,-14469,-14813,-15000,-14944,-14713,-14415,-14099, },
	/* LAT: -60 */ { -13514,-13161,-12822,-12489,-12146,-11774,-11359,-10905,-10438,-10008, -9680, -9506, -9505, -9642, -9846,-10036,-10159,-10199,-10184,-10168,-10215,-10376,-10667,-11078,-11578,-12135,-12722,-13318,-13907,-14468,-14966,-15255,-15075,-14689,-14282,-13888,-13514, },
	/* LAT: -50 */ { -12494,-12152,-11820,-11498,-11174,-10828,-10429, -9958, -9429, -8909, -8522, -8400, -8604, -9067, -9630,-10139,-10493,-10650,-10614,-10459,-10317,-10325,-10551,-10971,-11516,-12109,-12696,-13233,-13679,-13976,-14083,-14010,-13806,-13522,-13193,-12845,-12494, },
	/* LAT: -40 */ { -11239,-10890,-10542,-10196, -9856, -9518, -9158, -8734, -8214, -7650, -7228, -7193, -7659, -8486, -9407,-10232,-10886,-11314,-11445,-11270,-10924,-10655,-10655,-10942,-11407,-11913,-12357,-12676,-12833,-12838,-12748,-12612,-12434,-12202,-11915,-11587,-11239, },
	/* LAT: -30 */ {  -9602, -9221, -8840, -8449, -8057, -7682, -7327, -6938, -6426, -5816, -5369, -5462, -6243, -7450, -8700, -9791,-10700,-11403,-11792,-11771,-11392,-10884,-10556,-10563,-10818,-11140,-11394,-11504,-11439,-11263,-11091,-10959,-10815,-10609,-10328, -9982, -9602, },
	/* LAT: -20 */ {  -7372, -6928, -6508, -6079, -5634, -5205, -4817, -4406, -3842, -3158, -2717, -2993, -4119, -5739, -7365, -8727, -9784,-10551,-10979,-11002,-10630,-10012, -9457, -9219, -9271, -9434, -9573, -9587, -9413, -9142, -8951, -8869, -8770, -8564, -8248, -7834, -7372, },
	/* LAT: -10 */ {  -4417, -3875, -3418, -2979, -2521, -2072, -1660, -1210,  -588,   112,   465,    21, -1327, -3254, -5225, -6821, -7904, -8526, -8782, -8710, -8292, -7601, -6938, -6598, -6562, -6655, -6770, -6791, -6602, -6307, -6157, -6175, -6142, -5929, -5546, -5016, -4417, },
	/* LAT:   0 */ {   -909,  -279,   191,   596,  1014,  1431,  1818,  2256,  2834,  3406,  3599,  3088,  1775,  -146, -2186, -3822, -4814, -5229, -5280, -5102, -4653, -3930, -3225, -2859, -2800, -2868, -2991, -3063, -2933, -2699, -2650, -2804, -2877, -2696, -2271, -1638,  -909, },
	/* LAT:  10 */ {   2558,  3191,  3629,  3972,  4327,  4694,  5043,  5425,  5871,  6235,  6263,  5763,  4668,  3094,  1405,    43,  -747,  -982,  -883,  -642,  -224,   420,  1053,  1387,  1450,  1409,  1310,  1219,  1261,  1362,  1280,  1003,   801,   869,  1222,  1827,  2558, },
	/* LAT:  20 */ {   5414,  5947,  6329,  6625,  6939,  7282,  7623,  7966,  8294,  8490,  8397,  7927,  7083,  5983,  4860,  3959,  3440,  3331,  3487,  3734,  4069,  4538,  4998,  5252,  5310,  5296,  5249,  5192,  5179,  5158,  4979,  4639,  4334,  4241,  4414,  4839,  5414, },
	/* LAT:  30 */ {   7568,  7943,  8262,  8545,  8854,  9201,  9556,  9895, 10168, 10278, 10129,  9703,  9071,  8359,  7701,  7194,  6908,  6873,  7019,  7233,  7482,  7784,  8073,  8246,  8304,  8320,  8324,  8314,  8290,  8205,  7980,  7623,  7264,  7042,  7026,  7222,  7568, },
	/* LAT:  40 */ {   9266,  9487,  9743, 10029, 10355, 10715, 11082, 11418, 11668, 11747, 11595, 11234, 10760, 10288,  9894,  9613,  9468,  9467,  9581,  9744,  9921, 10107, 10279, 10404, 10483, 10545, 10601, 10635, 10617, 10504, 10260,  9907,  9538,  9253,  9110,  9123,  9266, },
	/* LAT:  50 */ {  10802, 10923, 11124, 11393, 11715, 12068, 12422, 12737, 12957, 13014, 12874, 12576, 12213, 11869, 11595, 11410, 11319, 11318, 11386, 11491, 11606, 11723, 11840, 11956, 12075, 12198, 12313, 12385, 12374, 12247, 11999, 11670, 11330, 11045, 10856, 10776, 10802, },
	/* LAT:  60 */ {  12319, 12391, 12541, 12758, 13027, 13326, 13627, 13893, 14068, 14095, 13960, 13712, 13424, 13154, 12934, 12779, 12689, 12660, 12676, 12725, 12794, 12880, 12987, 13119, 13279, 13456, 13620, 13729, 13733, 13611, 13385, 13106, 12828, 12591, 12421, 12329, 12319, },
	/* LAT:  70 */ {  13758, 13799, 13893, 14033, 14211, 14414, 14621, 14802, 14907, 14889, 14754, 14554, 14337, 14134, 13961, 13827, 13733, 13679, 13661, 13674, 13717, 13789, 13893, 14030, 14198, 14385, 14569, 14709, 14754, 14680, 14518, 14320, 14126, 13961, 13840, 13771, 13758, },
	/* LAT:  80 */ {  14995, 15006, 15042, 15101, 15176, 15260, 15338, 15383, 15368, 15292, 15182, 15060, 14938, 14824, 14725, 14643, 14582, 14541, 14523, 14527, 14554, 14603, 14675, 14768, 14880, 15007, 15143, 15275, 15382, 15426, 15385, 15297, 15201, 15116, 15050, 15009, 14995, },
	/* LAT:  90 */ {  15398, 15398, 15398, 15398, 15397, 15397, 15397, 15397, 15397, 15397, 15397, 15397, 15397, 15397, 15397, 15397, 15397, 15397, 15397, 15397, 15397, 15397, 15397, 15397, 15397, 15397, 15397, 15397, 15397, 15397, 15397, 15397, 15397, 15398, 15398, 15398, 15398, },
};

// Magnetic strength data in milli-Gauss * 10
// Model: WMM-2020,
// Version: 0.5.1.11,
// Date: 2023.1781,
static constexpr const int16_t strength_table[19][37] {
	//    LONGITUDE:  -180, -170, -160, -150, -140, -130, -120, -110, -100,  -90,  -80,  -70,  -60,  -50,  -40,  -30,  -20,  -10,    0,   10,   20,   30,   40,   50,   60,   70,   80,   90,  100,  110,  120,  130,  140,  150,  160,  170,  180,
	/* LAT: -90 */ {  5448, 5448, 5448, 5448, 5448, 5448, 5448, 5448, 5448, 5448, 5448, 5447, 5447, 5447, 5447, 5447, 5447, 5447, 5447, 5447, 5447, 5447, 5448, 5448, 5448, 5448, 5448, 5448, 5448, 5448, 5448, 5448, 5448, 5448, 5448, 5448, 5448, },
	/* LAT: -80 */ {  6054, 5990, 5911, 5819, 5716, 5604, 5486, 5364, 5241, 5122, 5007, 4902, 4809, 4729, 4666, 4622, 4597, 4595, 4617, 4663, 4734, 4828, 4943, 5075, 5219, 5369, 5519, 5662, 5793, 5907, 5999, 6068, 6112, 6131, 6127, 6100, 6054, },
	/* LAT: -70 */ {  6299, 6165, 6014, 5849, 5670, 5477, 5272, 5057, 4838, 4623, 4421, 4239, 4081, 3950, 3847, 3770, 3723, 3711, 3740, 3817, 3945, 4126, 4355, 4623, 4919, 5226, 5530, 5814, 6064, 6267, 6418, 6513, 6554, 6546, 6496, 6411, 6299, },
	/* LAT: -60 */ {  6184, 5991, 5789, 5580, 5360, 5125, 4869, 4590, 4298, 4009, 3742, 3516, 3336, 3202, 3104, 3030, 2980, 2960, 2986, 3077, 3247, 3499, 3827, 4214, 4637, 5071, 5492, 5876, 6201, 6449, 6612, 6690, 6691, 6627, 6513, 6361, 6184, },
	/* LAT: -50 */ {  5842, 5611, 5378, 5147, 4914, 4669, 4398, 4095, 3766, 3435, 3133, 2894, 2733, 2643, 2594, 2560, 2525, 2499, 2504, 2577, 2752, 3044, 3442, 3914, 4422, 4928, 5402, 5821, 6159, 6400, 6538, 6578, 6535, 6424, 6261, 6062, 5842, },
	/* LAT: -40 */ {  5392, 5145, 4900, 4660, 4425, 4187, 3932, 3648, 3334, 3009, 2710, 2488, 2372, 2347, 2366, 2387, 2390, 2377, 2364, 2394, 2526, 2804, 3224, 3740, 4287, 4811, 5277, 5664, 5956, 6143, 6231, 6233, 6163, 6031, 5850, 5631, 5392, },
	/* LAT: -30 */ {  4877, 4636, 4396, 4161, 3935, 3716, 3497, 3266, 3010, 2734, 2477, 2295, 2226, 2252, 2318, 2389, 2454, 2503, 2524, 2535, 2605, 2807, 3172, 3662, 4194, 4691, 5108, 5423, 5625, 5724, 5751, 5723, 5644, 5511, 5331, 5114, 4877, },
	/* LAT: -20 */ {  4321, 4107, 3898, 3693, 3496, 3314, 3145, 2981, 2803, 2605, 2414, 2281, 2241, 2286, 2376, 2486, 2614, 2741, 2828, 2862, 2888, 2987, 3230, 3616, 4067, 4494, 4841, 5074, 5178, 5185, 5155, 5108, 5026, 4898, 4731, 4534, 4321, },
	/* LAT: -10 */ {  3790, 3628, 3475, 3328, 3193, 3072, 2969, 2876, 2779, 2663, 2541, 2443, 2399, 2424, 2512, 2641, 2797, 2954, 3076, 3138, 3152, 3180, 3306, 3560, 3887, 4209, 4472, 4634, 4668, 4615, 4548, 4484, 4396, 4271, 4122, 3958, 3790, },
	/* LAT:   0 */ {  3412, 3319, 3234, 3161, 3106, 3067, 3041, 3021, 2996, 2948, 2869, 2775, 2695, 2666, 2709, 2813, 2945, 3080, 3194, 3268, 3299, 3321, 3398, 3557, 3767, 3980, 4160, 4265, 4270, 4202, 4114, 4022, 3910, 3779, 3644, 3520, 3412, },
	/* LAT:  10 */ {  3283, 3251, 3230, 3226, 3250, 3297, 3352, 3405, 3439, 3429, 3360, 3246, 3120, 3026, 3001, 3044, 3125, 3223, 3324, 3408, 3472, 3535, 3623, 3743, 3879, 4018, 4137, 4207, 4208, 4146, 4036, 3893, 3731, 3571, 3436, 3339, 3283, },
	/* LAT:  20 */ {  3399, 3402, 3427, 3481, 3572, 3693, 3821, 3937, 4018, 4029, 3956, 3814, 3648, 3510, 3435, 3424, 3460, 3533, 3630, 3727, 3818, 3917, 4029, 4140, 4250, 4362, 4464, 4530, 4540, 4481, 4343, 4141, 3913, 3703, 3540, 3439, 3399, },
	/* LAT:  30 */ {  3722, 3728, 3782, 3880, 4023, 4193, 4368, 4524, 4632, 4658, 4585, 4430, 4242, 4079, 3975, 3930, 3934, 3986, 4074, 4172, 4270, 4376, 4493, 4611, 4731, 4858, 4979, 5066, 5091, 5032, 4876, 4635, 4361, 4106, 3907, 3778, 3722, },
	/* LAT:  40 */ {  4222, 4219, 4283, 4405, 4571, 4758, 4941, 5097, 5202, 5228, 5160, 5012, 4826, 4653, 4526, 4452, 4427, 4450, 4511, 4591, 4677, 4775, 4890, 5024, 5175, 5337, 5489, 5598, 5637, 5581, 5425, 5187, 4913, 4654, 4443, 4297, 4222, },
	/* LAT:  50 */ {  4832, 4823, 4877, 4986, 5131, 5290, 5440, 5561, 5635, 5645, 5582, 5456, 5294, 5131, 4995, 4898, 4844, 4833, 4858, 4909, 4979, 5070, 5189, 5339, 5515, 5699, 5866, 5983, 6026, 5981, 5849, 5654, 5430, 5214, 5034, 4904, 4832, },
	/* LAT:  60 */ {  5392, 5378, 5405, 5466, 5551, 5645, 5732, 5799, 5833, 5825, 5772, 5678, 5558, 5431, 5312, 5217, 5151, 5117, 5116, 5144, 5200, 5287, 5405, 5553, 5719, 5887, 6034, 6137, 6181, 6158, 6075, 5949, 5804, 5662, 5539, 5447, 5392, },
	/* LAT:  70 */ {  5726, 5705, 5701, 5712, 5733, 5759, 5783, 5798, 5799, 5780, 5742, 5685, 5616, 5540, 5467, 5403, 5355, 5328, 5323, 5343, 5388, 5458, 5550, 5659, 5776, 5890, 5988, 6061, 6100, 6103, 6074, 6021, 5954, 5883, 5818, 5764, 5726, },
	/* LAT:  80 */ {  5790, 5772, 5757, 5745, 5734, 5725, 5715, 5703, 5689, 5671, 5649, 5624, 5598, 5571, 5546, 5526, 5513, 5508, 5513, 5528, 5554, 5589, 5632, 5680, 5730, 5778, 5820, 5854, 5879, 5891, 5894, 5886, 5872, 5853, 5832, 5810, 5790, },
	/* LAT:  90 */ {  5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, 5683, },
};
