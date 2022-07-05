void lagori5_up() {
  if (reed_4()) {
    if (!reed_5())  bottom_motor(1000);
    else  bottom_motor(50);
  }
  else {
    bottom_motor(50);
  }
}

void lagori4_up() {
  if (!reed_4())  up_motor(700);
  else  up_motor(50);
}

void lagori3_up() {
  if (top_limit()) {
    if (!reed_3())  bottom_motor(1000);
    else  bottom_motor(50);
  }
  else {
    bottom_motor(50);
  }
}

void lagori2_up() {
  if (!top_limit())  up_motor(700);
  else  up_motor(60);
}

void bottom_ground() {
  if (!bottom_limit()) bottom_motor(-800);
  else bottom_motor(0);
}

void ground() {
  if (!bottom_limit()) bottom_motor(-800);
  else bottom_motor(0);

  if (!up_limit()) up_motor(-190);
  else up_motor(0);
}

void lagori_piling() {
  getDataFromApp();
  if (HEIGHT == 7)  ground();
  else if (HEIGHT == 1) lagori5_up();
  else if (HEIGHT == 2)  lagori4_up();
  else if (HEIGHT == 3)  lagori3_up();
  else if (HEIGHT == 4)  lagori2_up();
  else if (HEIGHT == 5)  lagori2_up();
  else if (HEIGHT == 71)  bottom_ground();
//  else if (HEIGHT == 51)  up_gripper(0);
//  else if (HEIGHT == 61)  up_gripper(4);
//  else if (HEIGHT == 81)  up_gripper(2);
//  else if (HEIGHT == 60)  bottom_gripper(0);
//  else if (HEIGHT == 50)  bottom_gripper(5);
//  else if (HEIGHT == 80)  bottom_gripper(3);
//  else if (HEIGHT == 189)  small_lagori_servo(0);
//  else if (HEIGHT == 78)  small_lagori_servo(1);
  else if (HEIGHT == 150)  small_lagori_rotate_servo(-90);
  else if (HEIGHT == 151)  small_lagori_rotate_servo(0);
  else if (HEIGHT == 152)  small_lagori_rotate_servo(90);
}
//////////////////////////////////////////////////////////////////////////////
////int f1=0,f2=0,f3=0,f4=0;
//int f6;
//void lpm_pp()
//{
//  getDataFromApp();
//  if (HEIGHT == 100)
//  {
//    Serial.println("upp");
//  }
// else  if (HEIGHT == 1)
//  {
//    collision_5();
//    Serial.println("big lagori");
//  }
//  else if (HEIGHT == 2)
//  {
//    collision_4();
//    Serial.println("4th");
//  }
//  else if (HEIGHT == 3)
//  {
//   collision_3();
//   Serial.println("3rd");
//  }
//  else if (HEIGHT == 4)
//  {
//   collision_2();
//   Serial.println("2nd");
//  }
//  else if (HEIGHT == 5)
//  {
//   collision_1();
//   Serial.println("1st");
//  }
//    else if (HEIGHT == 7)
//  {
//    bottom_g();
//    Serial.println("ground");
//  }
//  else if(HEIGHT == 61)
//  {
//    servo_up(11);
//    Serial.println("4th close");
//  }
//  else if(HEIGHT == 51)
//  {
//    servo_up(5);
//    Serial.println("4th open");
//  }
//  else if(HEIGHT == 50)
//  {
//    servo_bottom(11);
//    Serial.println("5th close");
//  }
//  else if(HEIGHT == 60)
//  {
//    servo_bottom(5);
//    Serial.println("5th open");
//  }
//  else if(HEIGHT == 81)
//  {
//    servo_up(14);
//    Serial.println("2nd Close");
//  }
//  else if(HEIGHT == 51)
//  {
//    servo_up(5);
//    Serial.println("2nd Open");
//  }
//  else if(HEIGHT == 80)
//  {
//    servo_bottom(14);
//    Serial.println("3rd Close");
//  }
//  else if(HEIGHT == 60)
//  {
//    servo_bottom(5);
//    Serial.println("3rd Open");
//  }
//  else if(HEIGHT == 150)
//  {
//    small_lagori_rotate_servo(19);
//    Serial.println("-90 degree");
//  }
//  else if(HEIGHT == 151)
//  {
//    small_lagori_rotate_servo(12);
//    Serial.println("0 degree");
//
//  }
//  else if(HEIGHT == 152)
//  {
//    small_lagori_rotate_servo(6);
//    Serial.println("90 degree");
//  }
//  else if(HEIGHT == 78)
//  {
//    small_lagori_servo(14);
//    Serial.println("1st Close");
//  }
//  else if(HEIGHT ==189)
//  {
//    small_lagori_servo(7);
//    Serial.println("1st Open");
//  }
////  if (HEIGHT == 199)
////  {
////    PORTG = (1<<PG0);
////    Serial.println("HOLD");
////  }
////  else if (HEIGHT == 99)
////  {
////    PORTG &= ~ (1 << PG0);
////    Serial.println("THROW");
////  }
//  else if(HEIGHT == 243){
//   Serial.println("close");
//   pp_servo(6);
//  }
//  else if(HEIGHT == 87)
//  {
//    Serial.println("open");
//    pp_servo(9);
//  }
//  else if(HEIGHT ==71)
//  {
//    bottom();
//    Serial.println("5th & 3rd individual ground");
//  }
////  data = PRESSURE * 912.03;
////  if (data > 4095)data = 4095;
////  i2c_send();
//}
//void flag()
//{
//  if(f1==1){collision_f5(); }
//  if(f2==1){collision_4(); }
//  if(f3==1){collision_3();}
//  if(f4==1){collision_2(); }
//  if(f5==1){collision_2(); }
//}
//void servo_constrain()
//{
//  if(f6==1)
//  {
//    if(HEIGHT == 150)
//  {
//    small_lagori_rotate_servo(19);
//    flag();
//    Serial.println("-90 degree");
//  }
//   if(HEIGHT == 151)
//  {
//    small_lagori_rotate_servo(12);
//    flag();
//    Serial.println("0 degree");
//
//  }
//   if(HEIGHT == 152)
//  {
//    small_lagori_rotate_servo(6);
//    flag();
//    Serial.println("90 degree");
//  }
//  }
//  else
//  {
//    flag();
//  }
//}
//void lpm_with_flag()
//{
//getDataFromApp();
//  if(HEIGHT == 1)
//  {
//    f1=1;
//    flag();
//  }
//  else if(HEIGHT == 2)
//  {
//    f2=1;
//    flag();
//  }
//  else if(HEIGHT== 3)
//  {
//    f3=1;
//    flag();
//  }
//  else if(HEIGHT == 4)
//  {
//    f4=1;
//    flag();
//  }
//  else if(HEIGHT== 5)
//  {
//    f5=1;
//    flag();
//  }
//  else if (HEIGHT == 7)
//  {
//    bottom_g();
//  }
//  else if(HEIGHT == 61)
//  {
//    servo_up(11);
//    flag();
//    Serial.println("4th close");
//  }
//  else if(HEIGHT == 51)
//  {
//    servo_up(5);
//    flag();
//    Serial.println("4th open");
//  }
//  else if(HEIGHT == 50)
//  {
//    servo_bottom(11);
//    flag();
//    Serial.println("5th close");
//  }
//  else if(HEIGHT == 60)
//  {
//    servo_bottom(5);
//    flag();
//    Serial.println("5th open");
//  }
//  else if(HEIGHT == 81)
//  {
//    servo_up(14);
//    flag();
//    Serial.println("2nd Close");
//  }
//  else if(HEIGHT == 51)
//  {
//    servo_up(5);
//    flag();
//    Serial.println("2nd Open");
//  }
//  else if(HEIGHT == 80)
//  {
//    servo_bottom(14);
//    Serial.println("3rd Close");
//  }
//  else if(HEIGHT == 60)
//  {
//    servo_bottom(5);
//    flag();
//    Serial.println("3rd Open");
//  }
//  else if(HEIGHT == 78)
//  {
//    f6=1;
//    small_lagori_servo(14);
//    flag();
//    Serial.println("1st Close");
//  }
//  else if(HEIGHT ==189)
//  {
//    f6=0;
//    small_lagori_servo(8);
//    flag();
//    Serial.println("1st Open");
//  }
//   else if(HEIGHT == 150)
//  {
//    servo_constrain();
//  }
//  else if(HEIGHT == 151)
//  {
//    servo_constrain();
//  }
//  else if(HEIGHT == 152)
//  {
//    servo_constrain();
//  }
//  else if (HEIGHT == 199)
//  {
//    PORTG = (1<<PG0);
//    flag();
//    Serial.println("HOLD");
//  }
//  else if (HEIGHT == 99)
//  {
//    PORTG &= ~ (1 << PG0);
//    flag();
//    Serial.println("THROW");
//  }
//  else if(HEIGHT == 243){
//   Serial.println("close");
//   flag();
//   pp_servo(6);
//  }
//  else if(HEIGHT == 87)
//  {
//    Serial.println("open");
//    pp_servo(9);
//    flag();
//  }
//  else if(HEIGHT ==71)
//  {
//    bottom();
//    Serial.println("5th & 3rd individual ground");
//}
//}
