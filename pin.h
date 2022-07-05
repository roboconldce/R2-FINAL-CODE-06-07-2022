
/////////////////////////////////////     LPM REED SWITCH   ///////////////////////////////////////////
//
//                                       |     | APP DATA
//                PK0 = 5TH LAGORI(BIG)  -  A8  - 1
//                PK1 = 4TH LAGORI       -  A9  - 2
//                PK2 = 3RD LAGORI       -  A10 - 3
//                PK3 = 2ND LAGORI       -  A11 - 4
//                PK4 = 1ST LAGORI       -  A12 - 5                  // LIMIT SWITCH FOR 1ST LAGORI
//                PK5 = BOTTOM LIMIT     -  A13
//                PK6 = COLLISION LIMIT  -  A14
//                PK7 = TOP LIMIT        -  A15
//////////////////////////////////////    LPM MOTOR   //////////////////////////////////////////////////
//
//                (PL3)OCR5A= UPPER GRIPPER  - 46  | DIR FOR UPPER GRIPPER =   A4    - PF4
//                (PL5)OCR5C= BOTTOM GRIPPER - 44  | DIR FOR BOTTOM GRIPPER =  A3    - PF3
/////////////////////////////////// LPM GRIPPER SERVO ////////////////////////////////////////////////
//
//                 (PB5)OCR1A= 7.5 V Servo_bottom        -  11

//                 (PB6)OCR1B= 7.5 V Servo_up            -  12 
//                 (PH6)OCR2B= 7.5 V 1ST ROTATE SERVO    -  9
//                 (PE4)OCR3B= 12 v dc motor SERVO_PP              -  2
//                 (PE5)OCR3C= 5 V 1ST LAGORI GRIPPER    -  3
///////////////////////////////////// PP /////////////////////////////////////////////////////////////
//
//                  PP SOLENOID = 39(PG2)/41(PG0)
/////////////////////////////////////   BASE MOTOR //////////////////////////////////////////////////
//
//                  (PH3)OCR4A = 6 | DIR FOR MOTOR1 =   PF2      - A2
//                  (PH4)OCR4B = 7 | DIR FOR MOTOR2 =   PF1      - A1
//                  (PH5)OCR4C = 8 | DIR FOR MOTOR3 =   PF0      - A0
//////////////////////////////////////////////////////////////////////////////////////////////
/// 4th lagori close servo data= 61  open data = 51
/// 5th lagori close servo data= 50  open data = 80 (big lagori)
//5th individual ground data= 71
/// 3th lagori close servo data= 80  open data = 60
/// 2nd lagori close servo data= 81  open data = 51
//  1st lagori -90 = 150| 0 = 151 | 90 = 152
