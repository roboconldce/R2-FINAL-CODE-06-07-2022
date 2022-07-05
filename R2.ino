
#include"motor_control_func.h"
//#include"function.h"
#include"app.h"
#include"lpm.h"
int temp = 9;

void setup() {
  Serial.begin(115200);
  Serial2.begin(74880);
  pin_setup();
  set_manual();
}
void loop()
{
  ps3_data();
  manual_control();
  lagori_piling();
}

//  if (Serial.available()) {
//    temp = Serial.parseInt();
//  }
//  OCR3A = temp;
//  //  OCR1B =
//  //  OCR1B = temp;
//  //  OCR3B =
//  //  OCR3C = temp;

//  if (temp == 4)  lagori4_up();
//  else if (temp == 5)  lagori5_up();
//  else if (temp == 3)  lagori3_up();
//  else if (temp == 2)  lagori2_up();
//  else if (temp == 1) bottom_down();
//  else if (temp == 0) ground();
