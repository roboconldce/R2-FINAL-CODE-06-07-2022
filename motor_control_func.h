#include "MPU.h"
#include "ps3.h"
#include <Servo.h>
Servo myservo;
int base_spd = 1250;
int slow_spd = 1000;
int rotate_spd = -600;
int slow_rotate = -300;
int prev_state = 0, memory_flag = 0;
int pp = 0;
float g = 0;
bool g1 = 0, g2 = 0, g3 = 0, g4 = 0, g5 = 0, a = 0, mech_select = 0;
int f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, t = 0;

bool reed_5() {
  return (!(PINK & (1 << PK0)));
}

bool reed_4() {
  return (!(PINK & (1 << PK1)));
}

bool reed_3() {
  return (!(PINK & (1 << PK2)));
}

bool top_limit() {
  return ((PINK & (1 << PK3)));
}

bool bottom_limit() {
  return (!(PINK & (1 << PK5)));
}

bool up_limit() {
  return (!(PINK & (1 << PK6)));
}

void up_motor(int a4)
{
  if (a4 > 0) PORTF |= (1 << PF4);
  else PORTF &= ~ (1 << PF4);
  OCR5A = constrain(abs(a4), 0, 1000);
}
void bottom_motor(int a5)
{
  if (a5 > 0) PORTF |= (1 << PF3);
  else PORTF &= ~ (1 << PF3);
  OCR5C = constrain(abs(a5), 0, 1000);
}

void bottom_gripper(int a) {
  if (a == 0) OCR1A = 5;
  else if (a == 5) OCR1A = 10;
  else if (a == 3) OCR1A = 12;
}

void up_gripper(int b) {
  if (b == 0) OCR1B = 7;
  else if (b == 4) OCR1B = 11;
  else if (b == 2) OCR1B = 14;
}

void small_lagori_servo(int c) {
  if (c == 0) OCR3C = 7;
  else if (c == 1) OCR3C = 15;
}

void small_lagori_rotate_servo(int d)
{
  if (OCR3C == 15) {
    if (d == -90) OCR2B = 6;
    else if (d == 0) OCR2B = 12;
    else if (d == 90) OCR2B = 19;
  }
}

void pp_motor(int a10)
{
  if (a10 > 0) PORTC |= (1 << PC2);
  else PORTC &= ~ (1 << PC2);
  OCR3B = constrain(abs(a10), 0, 1000);
}
void pp_servo(int e)
{
  if (e == 0) OCR3A = 16;
  else if (e == 1) OCR3A = 9;
}

void pin_setup() {
  DDRC |= (1 << PC2);
  DDRB |= (1 << PB5) | (1 << PB6) | (1 << PB4);
  DDRH |= (1 << PH3) | (1 << PH4) | (1 << PH5) | (1 << PH6); // BASE MOTOR
  DDRE |= (1 << PE3) | (1 << PE4) | (1 << PE5);
  DDRF |= (1 << PF0) | (1 << PF1) | (1 << PF2) | (1 << PF3) | (1 << PF4);
  DDRL |= (1 << PL3) | (1 << PL5);
  DDRG |= (1 << PG0) | (1 << PG2);
  DDRK = 0X00;
  PORTK = 0XFF;
  // SERVO TIMER

  TCCR1A = 0XA2;
  ICR1 = 156;
  TCCR1B = 0X15;

  TCCR2A = 0X21;
  OCR2A = 156;
  TCCR2B = 0X0F;

  TCCR3A = 0XAA;
  ICR3 = 156;
  TCCR3B = 0X15;

  // BASE MOTOR TIMER

  TCCR4A = 0XAA;
  ICR4 = 2019;
  TCCR4B = 0X19;

  // LMP MOTOR TIMER

  TCCR5A = 0X8A;
  ICR5 = 2019;
  TCCR5B = 0X19;
}

void motor_speed(float m1, float m2, float m3) {
  if (m1 > 0) PORTF |= (1 << PF2);
  else PORTF &= ~ (1 << PF2);

  if (m2 > 0) PORTF |= (1 << PF1);
  else PORTF &= ~ (1 << PF1);

  if (m3 > 0) PORTF |= (1 << PF0);
  else PORTF &= ~ (1 << PF0);

  OCR4A = constrain(abs(m1), 0, 1500);
  OCR4B = constrain(abs(m2), 0, 1500);
  OCR4C = constrain(abs(m3), 0, 1500);
}

float cosine(float val) {
  return cos(val * PI / 180);
}

float sine(float val) {
  return sin(val * PI / 180);
}

void give_speed(int s, float a, int t) {
  a += 180;
  float m1, m2, m3;
  pid_mpu();
  if (t != 0) {
    m1 = -((s * 2 * cosine(a)) / 3 ) + ( t / 3) ;
    m2 = ((s * cosine(a)) / 3)  - ((s * sine(a)) / 1.73) + (t / 3) ;
    m3 = ((s * cosine(a)) / 3) + ((s * sine(a)) / 1.73) + (t / 3) ;
  }
  else {
    m1 = -((s * 2 * cosine(a)) / 3 ) + z;
    m2 = ((s * cosine(a)) / 3)  - ((s * sine(a)) / 1.73) + z ;
    m3 = ((s * cosine(a)) / 3) + ((s * sine(a)) / 1.73) + z;
  }
  motor_speed(m1, m2, m3);
}
void manual_control()
{
  if (ps3.select) {
    give_speed(z, z, z);
    if (a == 0) {
      mech_select = !mech_select ;
      a = 1;
    }
  }
  else {
    //    motor_speed(z, z, z);
    a = 0;
  }

  if (ps3.up) {
    if (ps3.left) give_speed(base_spd, 225, 0);
    else if (ps3.right) give_speed(base_spd, 315, 0);
    else if (ps3.L1) {
      reset_para();
      while (ps3.L1) {
        ps3_data();
        give_speed(base_spd - 300, 270, 450);
      }
      motor_speed(0, 0, 0);
      delay(40);
      set_mpu();
    }
    else if (ps3.R1) {
      reset_para();
      while (ps3.R1) {
        ps3_data();
        give_speed(base_spd - 300, 270, -450);
      }
      motor_speed(0, 0, 0);
      delay(40);
      set_mpu();
    }
    else give_speed(base_spd, 270, 0);
  }
  else if (ps3.down) {
    if (ps3.left) give_speed(base_spd, 135, 0);
    else if (ps3.right) give_speed(base_spd, 45, 0);
    else if (ps3.L1) {
      reset_para();
      while (ps3.L1) {
        ps3_data();
        give_speed(base_spd - 300, 90, -450);
      }
      motor_speed(0, 0, 0);
      delay(40);
      set_mpu();
    }
    else if (ps3.R1) {
      reset_para();
      while (ps3.R1) {
        ps3_data();
        give_speed(base_spd - 300, 90, 450);
      }
      motor_speed(0, 0, 0);
      delay(40);
      set_mpu();
    }
    else give_speed(base_spd, 90, 0);
  }
  else if (ps3.left) {
    if (ps3.up) give_speed(base_spd, 225, 0);
    else if (ps3.down) give_speed(base_spd, 135, 0);
    else give_speed(base_spd, 180, 0);
  }
  else if (ps3.right) {
    if (ps3.up) give_speed(base_spd, 315, 0);
    else if (ps3.down) give_speed(base_spd, 45, 0);
    else give_speed(base_spd, 0, 0);
  }
  else if (ps3.L1) {
    motor_speed(-slow_rotate, -slow_rotate, -slow_rotate);
    reset_para();
    while (ps3.L1) ps3_data();
    motor_speed(0, 0, 0);
    delay(40);
    set_mpu();
  }
  else if (ps3.R1) {
    motor_speed(slow_rotate, slow_rotate, slow_rotate);
    reset_para();
    while (ps3.R1) ps3_data();
    motor_speed(0, 0, 0);
    delay(40);
    set_mpu();
  }
  else {
    give_speed(0, 0, 0);
  }

  if (mech_select) {
    if (ps3.tri)
    {
      pp_servo(1);
      pp_motor(-45);
    }
    else if (ps3.circle) {
      pp_motor(-80);
    }
    else if (ps3.cross) {
      pp_motor(60);
    }
    else {
      pp_servo(0);
      pp_motor(0);
    }
  }
  else {
    pp_servo(1);

    if (ps3.start) {
      up_motor(400);
      t = 1;
    }
    else {
      if (t == 1 && !up_limit()) up_motor(-200);
      else {
        if (t == 1) {
          up_motor(0);
          t = 2;
        }
      }
    }

    if (ps3.tri) {
      if (g1 == 0) {
        if (f1 % 2 == 0)  up_gripper(4);
        else  up_gripper(0);
        g1 = 1;
        f1++;
      }
    }
    else {
      g1 = 0;
    }

    if (ps3.circle) {
      if (g2 == 0) {
        if (f2 % 2 == 0)  bottom_gripper(5);
        else  bottom_gripper(0);
        g2 = 1;
        f2++;
      }
    }
    else {
      g2 = 0;
    }

    if (ps3.cross) {
      if (g3 == 0) {
        if (f3 % 2 == 0)  up_gripper(2);
        else  up_gripper(0);
        g3 = 1;
        f3++;
      }
    }
    else {
      g3 = 0;
    }

    if (ps3.square) {
      if (g4 == 0) {
        if (f4 % 2 == 0)  bottom_gripper(3);
        else bottom_gripper(0);
        g4 = 1;
        f4++;
      }
    }
    else {
      g4 = 0;
    }

    if (ps3.R3) {
      if (g5 == 0) {
        if (f5 % 2 == 0)  small_lagori_servo(1);
        else  small_lagori_servo(0);
        g5 = 1;
        f5++;
      }
    }
    else {
      g5 = 0;
    }
  }


}
void set_manual() {
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif

  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }

  Serial.println(F("\r\nPS3 Bluetooth Library Started"));

  set_mpu();

  while (!PS3.PS3Connected) {
    Serial.println("Not Connected");
    Usb.Task();
    pid_mpu();
  }
}
