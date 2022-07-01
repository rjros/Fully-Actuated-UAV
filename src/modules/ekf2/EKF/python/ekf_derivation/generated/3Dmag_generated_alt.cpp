// Sub Expressions
const float HK0 = magD*q2;
const float HK1 = HK0 - magE*q3;
const float HK2 = magD*q3;
const float HK3 = magE*q2;
const float HK4 = HK2 + HK3;
const float HK5 = magD*q0;
const float HK6 = magE*q1;
const float HK7 = magN*q2;
const float HK8 = HK5 - HK6 + 2*HK7;
const float HK9 = magD*q1;
const float HK10 = magE*q0;
const float HK11 = magN*q3;
const float HK12 = HK10 - 2*HK11 + HK9;
const float HK13 = 2*(q2)*(q2);
const float HK14 = 2*(q3)*(q3) - 1;
const float HK15 = HK13 + HK14;
const float HK16 = q0*q3;
const float HK17 = HK16 + q1*q2;
const float HK18 = q0*q2;
const float HK19 = HK18 - q1*q3;
const float HK20 = 2*HK1;
const float HK21 = 2*HK19;
const float HK22 = 2*HK8;
const float HK23 = -2*HK12*P(0,3) + HK15*P(0,16) - 2*HK17*P(0,17) + HK20*P(0,0) + HK21*P(0,18) + HK22*P(0,2) - 2*HK4*P(0,1) - P(0,19);
const float HK24 = -R_MAG;
const float HK25 = -2*HK12*P(3,16) + HK15*P(16,16) - 2*HK17*P(16,17) + HK20*P(0,16) + HK21*P(16,18) + HK22*P(2,16) - 2*HK4*P(1,16) - P(16,19);
const float HK26 = -2*HK12*P(1,3) + HK15*P(1,16) - 2*HK17*P(1,17) + HK20*P(0,1) + HK21*P(1,18) + HK22*P(1,2) - 2*HK4*P(1,1) - P(1,19);
const float HK27 = 2*HK4;
const float HK28 = -2*HK12*P(3,17) + HK15*P(16,17) - 2*HK17*P(17,17) + HK20*P(0,17) + HK21*P(17,18) + HK22*P(2,17) - 2*HK4*P(1,17) - P(17,19);
const float HK29 = 2*HK17;
const float HK30 = -2*HK12*P(3,3) + HK15*P(3,16) - 2*HK17*P(3,17) + HK20*P(0,3) + HK21*P(3,18) + HK22*P(2,3) - 2*HK4*P(1,3) - P(3,19);
const float HK31 = 2*HK12;
const float HK32 = -2*HK12*P(3,18) + HK15*P(16,18) - 2*HK17*P(17,18) + HK20*P(0,18) + HK21*P(18,18) + HK22*P(2,18) - 2*HK4*P(1,18) - P(18,19);
const float HK33 = -2*HK12*P(2,3) + HK15*P(2,16) - 2*HK17*P(2,17) + HK20*P(0,2) + HK21*P(2,18) + HK22*P(2,2) - 2*HK4*P(1,2) - P(2,19);
const float HK34 = HK15*P(16,19) + HK20*P(0,19) + HK21*P(18,19) + HK22*P(2,19) - HK27*P(1,19) - HK29*P(17,19) - HK31*P(3,19) - P(19,19);
const float HK35 = 1.0F/(-HK15*HK25 - HK20*HK23 - HK21*HK32 - HK22*HK33 + HK24 + HK26*HK27 + HK28*HK29 + HK30*HK31 + HK34);
const float HK36 = -P(19,21);
const float HK37 = -HK11;
const float HK38 = HK37 + HK9;
const float HK39 = HK5 - 2*HK6 + HK7;
const float HK40 = magN*q1;
const float HK41 = HK2 + HK40;
const float HK42 = magN*q0;
const float HK43 = magE*q3;
const float HK44 = -HK0 + HK42 + 2*HK43;
const float HK45 = HK16 - q1*q2;
const float HK46 = 2*(q1)*(q1);
const float HK47 = HK14 + HK46;
const float HK48 = q0*q1;
const float HK49 = HK48 + q2*q3;
const float HK50 = 2*HK49;
const float HK51 = 2*HK41;
const float HK52 = 2*HK38;
const float HK53 = 2*HK45;
const float HK54 = 2*HK39;
const float HK55 = 2*HK44;
const float HK56 = -HK47*P(0,17) + HK50*P(0,18) + HK51*P(0,2) + HK52*P(0,0) - HK53*P(0,16) + HK54*P(0,1) - HK55*P(0,3) + P(0,20);
const float HK57 = -HK47*P(17,17) + HK50*P(17,18) + HK51*P(2,17) + HK52*P(0,17) - HK53*P(16,17) + HK54*P(1,17) - HK55*P(3,17) + P(17,20);
const float HK58 = -HK47*P(16,17) + HK50*P(16,18) + HK51*P(2,16) + HK52*P(0,16) - HK53*P(16,16) + HK54*P(1,16) - HK55*P(3,16) + P(16,20);
const float HK59 = -HK47*P(3,17) + HK50*P(3,18) + HK51*P(2,3) + HK52*P(0,3) - HK53*P(3,16) + HK54*P(1,3) - HK55*P(3,3) + P(3,20);
const float HK60 = -HK47*P(2,17) + HK50*P(2,18) + HK51*P(2,2) + HK52*P(0,2) - HK53*P(2,16) + HK54*P(1,2) - HK55*P(2,3) + P(2,20);
const float HK61 = -HK47*P(17,18) + HK50*P(18,18) + HK51*P(2,18) + HK52*P(0,18) - HK53*P(16,18) + HK54*P(1,18) - HK55*P(3,18) + P(18,20);
const float HK62 = -HK47*P(1,17) + HK50*P(1,18) + HK51*P(1,2) + HK52*P(0,1) - HK53*P(1,16) + HK54*P(1,1) - HK55*P(1,3) + P(1,20);
const float HK63 = -HK47*P(17,20) + HK50*P(18,20) + HK51*P(2,20) + HK52*P(0,20) - HK53*P(16,20) + HK54*P(1,20) - HK55*P(3,20) + P(20,20);
const float HK64 = 1.0F/(-HK47*HK57 + HK50*HK61 + HK51*HK60 + HK52*HK56 - HK53*HK58 + HK54*HK62 - HK55*HK59 + HK63 + R_MAG);
const float HK65 = HK6 - magN*q2;
const float HK66 = HK10 + HK37 + 2*HK9;
const float HK67 = -2*HK0 + HK42 + HK43;
const float HK68 = HK3 + HK40;
const float HK69 = HK18 + q1*q3;
const float HK70 = HK48 - q2*q3;
const float HK71 = HK13 + HK46 - 1;
const float HK72 = 2*HK65;
const float HK73 = 2*HK70;
const float HK74 = 2*HK66;
const float HK75 = -2*HK67*P(0,2) - 2*HK68*P(0,3) - 2*HK69*P(0,16) + HK71*P(0,18) + HK72*P(0,0) + HK73*P(0,17) + HK74*P(0,1) - P(0,21);
const float HK76 = -2*HK67*P(2,18) - 2*HK68*P(3,18) - 2*HK69*P(16,18) + HK71*P(18,18) + HK72*P(0,18) + HK73*P(17,18) + HK74*P(1,18) - P(18,21);
const float HK77 = -2*HK67*P(2,3) - 2*HK68*P(3,3) - 2*HK69*P(3,16) + HK71*P(3,18) + HK72*P(0,3) + HK73*P(3,17) + HK74*P(1,3) - P(3,21);
const float HK78 = 2*HK68;
const float HK79 = -2*HK67*P(2,16) - 2*HK68*P(3,16) - 2*HK69*P(16,16) + HK71*P(16,18) + HK72*P(0,16) + HK73*P(16,17) + HK74*P(1,16) - P(16,21);
const float HK80 = 2*HK69;
const float HK81 = -2*HK67*P(2,2) - 2*HK68*P(2,3) - 2*HK69*P(2,16) + HK71*P(2,18) + HK72*P(0,2) + HK73*P(2,17) + HK74*P(1,2) - P(2,21);
const float HK82 = 2*HK67;
const float HK83 = -2*HK67*P(2,17) - 2*HK68*P(3,17) - 2*HK69*P(16,17) + HK71*P(17,18) + HK72*P(0,17) + HK73*P(17,17) + HK74*P(1,17) - P(17,21);
const float HK84 = -2*HK67*P(1,2) - 2*HK68*P(1,3) - 2*HK69*P(1,16) + HK71*P(1,18) + HK72*P(0,1) + HK73*P(1,17) + HK74*P(1,1) - P(1,21);
const float HK85 = HK71*P(18,21) + HK72*P(0,21) + HK73*P(17,21) + HK74*P(1,21) - HK78*P(3,21) - HK80*P(16,21) - HK82*P(2,21) - P(21,21);
const float HK86 = 1.0F/(HK24 - HK71*HK76 - HK72*HK75 - HK73*HK83 - HK74*HK84 + HK77*HK78 + HK79*HK80 + HK81*HK82 + HK85);


// Observation Jacobians - axis 0
Hfusion.at<0>() = -2*HK1;
Hfusion.at<1>() = 2*HK4;
Hfusion.at<2>() = -2*HK8;
Hfusion.at<3>() = 2*HK12;
Hfusion.at<16>() = -HK15;
Hfusion.at<17>() = 2*HK17;
Hfusion.at<18>() = -2*HK19;
Hfusion.at<19>() = 1;


// Kalman gains - axis 0
Kfusion(0) = HK23*HK35;
Kfusion(1) = HK26*HK35;
Kfusion(2) = HK33*HK35;
Kfusion(3) = HK30*HK35;
Kfusion(4) = HK35*(HK15*P(4,16) + HK20*P(0,4) + HK21*P(4,18) + HK22*P(2,4) - HK27*P(1,4) - HK29*P(4,17) - HK31*P(3,4) - P(4,19));
Kfusion(5) = HK35*(HK15*P(5,16) + HK20*P(0,5) + HK21*P(5,18) + HK22*P(2,5) - HK27*P(1,5) - HK29*P(5,17) - HK31*P(3,5) - P(5,19));
Kfusion(6) = HK35*(HK15*P(6,16) + HK20*P(0,6) + HK21*P(6,18) + HK22*P(2,6) - HK27*P(1,6) - HK29*P(6,17) - HK31*P(3,6) - P(6,19));
Kfusion(7) = HK35*(HK15*P(7,16) + HK20*P(0,7) + HK21*P(7,18) + HK22*P(2,7) - HK27*P(1,7) - HK29*P(7,17) - HK31*P(3,7) - P(7,19));
Kfusion(8) = HK35*(HK15*P(8,16) + HK20*P(0,8) + HK21*P(8,18) + HK22*P(2,8) - HK27*P(1,8) - HK29*P(8,17) - HK31*P(3,8) - P(8,19));
Kfusion(9) = HK35*(HK15*P(9,16) + HK20*P(0,9) + HK21*P(9,18) + HK22*P(2,9) - HK27*P(1,9) - HK29*P(9,17) - HK31*P(3,9) - P(9,19));
Kfusion(10) = HK35*(HK15*P(10,16) + HK20*P(0,10) + HK21*P(10,18) + HK22*P(2,10) - HK27*P(1,10) - HK29*P(10,17) - HK31*P(3,10) - P(10,19));
Kfusion(11) = HK35*(HK15*P(11,16) + HK20*P(0,11) + HK21*P(11,18) + HK22*P(2,11) - HK27*P(1,11) - HK29*P(11,17) - HK31*P(3,11) - P(11,19));
Kfusion(12) = HK35*(HK15*P(12,16) + HK20*P(0,12) + HK21*P(12,18) + HK22*P(2,12) - HK27*P(1,12) - HK29*P(12,17) - HK31*P(3,12) - P(12,19));
Kfusion(13) = HK35*(HK15*P(13,16) + HK20*P(0,13) + HK21*P(13,18) + HK22*P(2,13) - HK27*P(1,13) - HK29*P(13,17) - HK31*P(3,13) - P(13,19));
Kfusion(14) = HK35*(HK15*P(14,16) + HK20*P(0,14) + HK21*P(14,18) + HK22*P(2,14) - HK27*P(1,14) - HK29*P(14,17) - HK31*P(3,14) - P(14,19));
Kfusion(15) = HK35*(HK15*P(15,16) + HK20*P(0,15) + HK21*P(15,18) + HK22*P(2,15) - HK27*P(1,15) - HK29*P(15,17) - HK31*P(3,15) - P(15,19));
Kfusion(16) = HK25*HK35;
Kfusion(17) = HK28*HK35;
Kfusion(18) = HK32*HK35;
Kfusion(19) = HK34*HK35;
Kfusion(20) = HK35*(HK15*P(16,20) + HK20*P(0,20) + HK21*P(18,20) + HK22*P(2,20) - HK27*P(1,20) - HK29*P(17,20) - HK31*P(3,20) - P(19,20));
Kfusion(21) = HK35*(HK15*P(16,21) + HK20*P(0,21) + HK21*P(18,21) + HK22*P(2,21) - HK27*P(1,21) - HK29*P(17,21) - HK31*P(3,21) + HK36);
Kfusion(22) = HK35*(HK15*P(16,22) + HK20*P(0,22) + HK21*P(18,22) + HK22*P(2,22) - HK27*P(1,22) - HK29*P(17,22) - HK31*P(3,22) - P(19,22));
Kfusion(23) = HK35*(HK15*P(16,23) + HK20*P(0,23) + HK21*P(18,23) + HK22*P(2,23) - HK27*P(1,23) - HK29*P(17,23) - HK31*P(3,23) - P(19,23));


// Observation Jacobians - axis 1
Hfusion.at<0>() = 2*HK38;
Hfusion.at<1>() = 2*HK39;
Hfusion.at<2>() = 2*HK41;
Hfusion.at<3>() = -2*HK44;
Hfusion.at<16>() = -2*HK45;
Hfusion.at<17>() = -HK47;
Hfusion.at<18>() = 2*HK49;
Hfusion.at<20>() = 1;


// Kalman gains - axis 1
Kfusion(0) = HK56*HK64;
Kfusion(1) = HK62*HK64;
Kfusion(2) = HK60*HK64;
Kfusion(3) = HK59*HK64;
Kfusion(4) = HK64*(-HK47*P(4,17) + HK50*P(4,18) + HK51*P(2,4) + HK52*P(0,4) - HK53*P(4,16) + HK54*P(1,4) - HK55*P(3,4) + P(4,20));
Kfusion(5) = HK64*(-HK47*P(5,17) + HK50*P(5,18) + HK51*P(2,5) + HK52*P(0,5) - HK53*P(5,16) + HK54*P(1,5) - HK55*P(3,5) + P(5,20));
Kfusion(6) = HK64*(-HK47*P(6,17) + HK50*P(6,18) + HK51*P(2,6) + HK52*P(0,6) - HK53*P(6,16) + HK54*P(1,6) - HK55*P(3,6) + P(6,20));
Kfusion(7) = HK64*(-HK47*P(7,17) + HK50*P(7,18) + HK51*P(2,7) + HK52*P(0,7) - HK53*P(7,16) + HK54*P(1,7) - HK55*P(3,7) + P(7,20));
Kfusion(8) = HK64*(-HK47*P(8,17) + HK50*P(8,18) + HK51*P(2,8) + HK52*P(0,8) - HK53*P(8,16) + HK54*P(1,8) - HK55*P(3,8) + P(8,20));
Kfusion(9) = HK64*(-HK47*P(9,17) + HK50*P(9,18) + HK51*P(2,9) + HK52*P(0,9) - HK53*P(9,16) + HK54*P(1,9) - HK55*P(3,9) + P(9,20));
Kfusion(10) = HK64*(-HK47*P(10,17) + HK50*P(10,18) + HK51*P(2,10) + HK52*P(0,10) - HK53*P(10,16) + HK54*P(1,10) - HK55*P(3,10) + P(10,20));
Kfusion(11) = HK64*(-HK47*P(11,17) + HK50*P(11,18) + HK51*P(2,11) + HK52*P(0,11) - HK53*P(11,16) + HK54*P(1,11) - HK55*P(3,11) + P(11,20));
Kfusion(12) = HK64*(-HK47*P(12,17) + HK50*P(12,18) + HK51*P(2,12) + HK52*P(0,12) - HK53*P(12,16) + HK54*P(1,12) - HK55*P(3,12) + P(12,20));
Kfusion(13) = HK64*(-HK47*P(13,17) + HK50*P(13,18) + HK51*P(2,13) + HK52*P(0,13) - HK53*P(13,16) + HK54*P(1,13) - HK55*P(3,13) + P(13,20));
Kfusion(14) = HK64*(-HK47*P(14,17) + HK50*P(14,18) + HK51*P(2,14) + HK52*P(0,14) - HK53*P(14,16) + HK54*P(1,14) - HK55*P(3,14) + P(14,20));
Kfusion(15) = HK64*(-HK47*P(15,17) + HK50*P(15,18) + HK51*P(2,15) + HK52*P(0,15) - HK53*P(15,16) + HK54*P(1,15) - HK55*P(3,15) + P(15,20));
Kfusion(16) = HK58*HK64;
Kfusion(17) = HK57*HK64;
Kfusion(18) = HK61*HK64;
Kfusion(19) = HK64*(-HK47*P(17,19) + HK50*P(18,19) + HK51*P(2,19) + HK52*P(0,19) - HK53*P(16,19) + HK54*P(1,19) - HK55*P(3,19) + P(19,20));
Kfusion(20) = HK63*HK64;
Kfusion(21) = HK64*(-HK47*P(17,21) + HK50*P(18,21) + HK51*P(2,21) + HK52*P(0,21) - HK53*P(16,21) + HK54*P(1,21) - HK55*P(3,21) + P(20,21));
Kfusion(22) = HK64*(-HK47*P(17,22) + HK50*P(18,22) + HK51*P(2,22) + HK52*P(0,22) - HK53*P(16,22) + HK54*P(1,22) - HK55*P(3,22) + P(20,22));
Kfusion(23) = HK64*(-HK47*P(17,23) + HK50*P(18,23) + HK51*P(2,23) + HK52*P(0,23) - HK53*P(16,23) + HK54*P(1,23) - HK55*P(3,23) + P(20,23));


// Observation Jacobians - axis 2
Hfusion.at<0>() = -2*HK65;
Hfusion.at<1>() = -2*HK66;
Hfusion.at<2>() = 2*HK67;
Hfusion.at<3>() = 2*HK68;
Hfusion.at<16>() = 2*HK69;
Hfusion.at<17>() = -2*HK70;
Hfusion.at<18>() = -HK71;
Hfusion.at<21>() = 1;


// Kalman gains - axis 2
Kfusion(0) = HK75*HK86;
Kfusion(1) = HK84*HK86;
Kfusion(2) = HK81*HK86;
Kfusion(3) = HK77*HK86;
Kfusion(4) = HK86*(HK71*P(4,18) + HK72*P(0,4) + HK73*P(4,17) + HK74*P(1,4) - HK78*P(3,4) - HK80*P(4,16) - HK82*P(2,4) - P(4,21));
Kfusion(5) = HK86*(HK71*P(5,18) + HK72*P(0,5) + HK73*P(5,17) + HK74*P(1,5) - HK78*P(3,5) - HK80*P(5,16) - HK82*P(2,5) - P(5,21));
Kfusion(6) = HK86*(HK71*P(6,18) + HK72*P(0,6) + HK73*P(6,17) + HK74*P(1,6) - HK78*P(3,6) - HK80*P(6,16) - HK82*P(2,6) - P(6,21));
Kfusion(7) = HK86*(HK71*P(7,18) + HK72*P(0,7) + HK73*P(7,17) + HK74*P(1,7) - HK78*P(3,7) - HK80*P(7,16) - HK82*P(2,7) - P(7,21));
Kfusion(8) = HK86*(HK71*P(8,18) + HK72*P(0,8) + HK73*P(8,17) + HK74*P(1,8) - HK78*P(3,8) - HK80*P(8,16) - HK82*P(2,8) - P(8,21));
Kfusion(9) = HK86*(HK71*P(9,18) + HK72*P(0,9) + HK73*P(9,17) + HK74*P(1,9) - HK78*P(3,9) - HK80*P(9,16) - HK82*P(2,9) - P(9,21));
Kfusion(10) = HK86*(HK71*P(10,18) + HK72*P(0,10) + HK73*P(10,17) + HK74*P(1,10) - HK78*P(3,10) - HK80*P(10,16) - HK82*P(2,10) - P(10,21));
Kfusion(11) = HK86*(HK71*P(11,18) + HK72*P(0,11) + HK73*P(11,17) + HK74*P(1,11) - HK78*P(3,11) - HK80*P(11,16) - HK82*P(2,11) - P(11,21));
Kfusion(12) = HK86*(HK71*P(12,18) + HK72*P(0,12) + HK73*P(12,17) + HK74*P(1,12) - HK78*P(3,12) - HK80*P(12,16) - HK82*P(2,12) - P(12,21));
Kfusion(13) = HK86*(HK71*P(13,18) + HK72*P(0,13) + HK73*P(13,17) + HK74*P(1,13) - HK78*P(3,13) - HK80*P(13,16) - HK82*P(2,13) - P(13,21));
Kfusion(14) = HK86*(HK71*P(14,18) + HK72*P(0,14) + HK73*P(14,17) + HK74*P(1,14) - HK78*P(3,14) - HK80*P(14,16) - HK82*P(2,14) - P(14,21));
Kfusion(15) = HK86*(HK71*P(15,18) + HK72*P(0,15) + HK73*P(15,17) + HK74*P(1,15) - HK78*P(3,15) - HK80*P(15,16) - HK82*P(2,15) - P(15,21));
Kfusion(16) = HK79*HK86;
Kfusion(17) = HK83*HK86;
Kfusion(18) = HK76*HK86;
Kfusion(19) = HK86*(HK36 + HK71*P(18,19) + HK72*P(0,19) + HK73*P(17,19) + HK74*P(1,19) - HK78*P(3,19) - HK80*P(16,19) - HK82*P(2,19));
Kfusion(20) = HK86*(HK71*P(18,20) + HK72*P(0,20) + HK73*P(17,20) + HK74*P(1,20) - HK78*P(3,20) - HK80*P(16,20) - HK82*P(2,20) - P(20,21));
Kfusion(21) = HK85*HK86;
Kfusion(22) = HK86*(HK71*P(18,22) + HK72*P(0,22) + HK73*P(17,22) + HK74*P(1,22) - HK78*P(3,22) - HK80*P(16,22) - HK82*P(2,22) - P(21,22));
Kfusion(23) = HK86*(HK71*P(18,23) + HK72*P(0,23) + HK73*P(17,23) + HK74*P(1,23) - HK78*P(3,23) - HK80*P(16,23) - HK82*P(2,23) - P(21,23));


