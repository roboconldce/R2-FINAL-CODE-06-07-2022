
//int f1, f2, f3, f4, f5;

//void bottom_5()
//{
//  if (!(PINK & (1 << PK1))) {
//    Serial.println("condition satisfy");
//
//    if ((PINK & (1 << PK0))) //A8(PK0) reed not detected
//    {
//
//      Serial.println("5th");
//      bottom_motor(700);
//    }
//    else
//    {
//      up_motor(50);
//      bottom_motor(50);
//      Serial.println("no");
//    }
//  }
//  else
//  {
//    bottom_motor(50);
//    Serial.println("no speed");
//  }
//}
//void up_4()
//{
//  if (!(PINK & (1 << PK3))) {
//    up_motor(70);
//    Serial.println("no speed");
//  }
//  else
//  {
//
//    Serial.println("Condition satisfy");
//    if ((PINK & (1 << PK1))) //A9(PK1)
//    {
//      up_motor(700);
//      Serial.println("4th");
//    }
//    else
//    {
//      up_motor(70);
//      Serial.println("no");
//    }
//  }
//}
//void bottom_3()
//{
//  if ((PINK & (1 << PK2))) //A10(PK2)
//  {
//
//    bottom_motor(800);
//    Serial.println("3rd");
//  }
//  else
//  {
//    up_motor(25);
//    bottom_motor(50);
//    Serial.println("no");
//
//  }
//}
//void up_2() {
//  if ((PINK & (1 << PK3))) //A11(PK3) REED NOT DETECTED
//  {
//
//    up_motor(700);
//    Serial.println("2nd");
//  }
//  else
//  {
//    up_motor(70);
//    Serial.println("no");
//  }
//}
//
//void up_1() {
//  if (PINK & (1 << PK7))
//  {
//    Serial.println("1 up");
//    up_motor(70);// TOP LIMIT SWITCH (PK7)
//  }
//  else
//  {
//
//    up_motor(700);
//    Serial.println("no");
//  }
//}

void bottom_g()
{
  if ((PINK & (1 << PK5)))
  {
    bottom_motor(-800);
    Serial.println("niche");
  }
  else
  {
    bottom_motor(0);
    Serial.println("reached");
  }
  if ((PINK & (1 << PK6))) {
    up_motor(-190);
  }
  else {
    up_motor(0);
  }
}
void collision()
{
  if (!(PINK & (1 << PK6)) && (PINK & (1 << PK5)))
  {
    Serial.println("collision");
    up_motor(70);
    bottom_motor(70);
  }
  else
  {
    Serial.println("no collision");
  }

}
void collision_2()
{
  if (!(PINK & (1 << PK3))) //A11(PK3) REED NOT DETECTED
  {
    if (!(PINK & (1 << PK6)) && (PINK & (1 << PK5)))
    {
      up_motor(70);
      Serial.println("collision");
    }
    else
    {
      up_motor(500);
      Serial.println("2nd");
    }
  }
  else
  {
    up_motor(70);
    f4 = 0;
    Serial.println("no");
  }
}
void collision_4()
{
  if ((PINK & (1 << PK3))) {
    up_motor(70);
      Serial.println("no speed");
  }
  else
  {
    //Serial.println("Condition satisfy");
    if ((PINK & (1 << PK1))) //A9(PK1)
    {
      if (!(PINK & (1 << PK6)) && (PINK & (1 << PK5)))
      {
        up_motor(70);
                      Serial.println("collision");
      }
      else
      {
        up_motor(500);
        Serial.println("4thh");
      }
    }
    else
    {
      up_motor(80);
      f2 = 0;
      Serial.println("4flag exited");
    }
  }
}
void collision_5()
{

  if (!(PINK & (1 << PK1))) {
    Serial.println("condition satisfy");

    if ((PINK & (1 << PK0))) //A8(PK0) reed not detected
    {
      if (!(PINK & (1 << PK6)) && (PINK & (1 << PK5)))
      {
        Serial.println("collision");
        bottom_motor(70);
      }
      else
      {
        bottom_motor(700);
        Serial.println("5th");
      }
    }
    else
    {
      up_motor(50);
      bottom_motor(50);
      f1 = 0;
      Serial.println("5th reached and flag exited");
    }
  }
  else
  {
    bottom_motor(50);
    Serial.println("no speed");
  }
}
void collision_3()
{
  //  if (!(PINK & (1 << PK3))) {

  if ((PINK & (1 << PK2))) //A10(PK2)
  {
    if (!(PINK & (1 << PK6)) && (PINK & (1 << PK5)))
    {
      bottom_motor(70);
      Serial.println("collision");
    }
    else
    {
      bottom_motor(700);
      Serial.println("3rd");
    }
  }
  else
  {
    f3 = 0;
    up_motor(70);
    bottom_motor(50);
    Serial.println("no");
  }
}
//  else
//  {
//    bottom_motor(50);
//    Serial.println("no speed");
//  }
//}
void collision_1()
{

  if (PINK & (1 << PK7))
  {
    Serial.println("1 up");
    f5 = 0;
    up_motor(70);// TOP LIMIT SWITCH (PK7)
  }
  else
  {
    if (!(PINK & (1 << PK6)) && (PINK & (1 << PK5)))
    {
      up_motor(70);
      Serial.println("collision");
    }
    else
    {
      up_motor(700);
      Serial.println("1st");
    }
  }
}
void bottom()
{
  if ((PINK & (1 << PK5)))
  {

    bottom_motor(-800);
    Serial.println("niche");
  }
  else
  {
    bottom_motor(0);
    Serial.println("reached");
  }
}
void collision_f5()
{

  //  if(!(PINK & (1<<PK1))){
  //  Serial.println("condition satisfy");

  if ((PINK & (1 << PK0))) //A8(PK0) reed not detected
  {
    if (!(PINK & (1 << PK6)) && (PINK & (1 << PK5)))
    {
      Serial.println("collision");
      bottom_motor(70);
    }
    else
    {
      bottom_motor(700);
      Serial.println("5th");
    }
  }
  else
  {
    up_motor(50);
    bottom_motor(50);
    f1 = 0;
    Serial.println("5th reached and flag exited");
  }
}
// else
// {
//  bottom_motor(50);
//  Serial.println("no speed");
// }
//}
