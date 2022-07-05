#define addr 0xC0
#include<ArduinoJson.h>
StaticJsonDocument<200> json;
unsigned char i = 0;
unsigned int data = 0;
unsigned char c1 = 0, c2 = 0;
char string[10];
//int zz = 0, zz1;
short HEIGHT = 0;
//float PRESSURE = 0.0;

void getDataFromApp()
{
  String str = "";
  while (Serial2.available())
  {
    char c = Serial2.read();
    str += c;
  }
 
  deserializeJson(json, str.c_str());
  int digit = json["digit"].as<int>();
  float pressure_digit = json["pressure_digit"].as<float>();
//  Serial.println(pressure_digit);
  // short localData = 0;
  short LOCALHEIGHT = 0;
  float LOCALPRESSURE = 0.0;

  if (digit) {
    LOCALHEIGHT = digit;
    HEIGHT = LOCALHEIGHT;
  } else {
    LOCALHEIGHT = HEIGHT;
  }

}
//  if (pressure_digit) {
//    LOCALPRESSURE = pressure_digit;
//    PRESSURE = LOCALPRESSURE;
//  } else {
//    LOCALPRESSURE = PRESSURE;
//  }

//    Serial.print("HEIGHT: ");
//    Serial.print(HEIGHT);
//    Serial.print("  ");
//    Serial.print("PRESSURE: ");
//    Serial.println(PRESSURE);



//void i2c_stop() {
//  TWCR = 0x94;
//}
//void i2c_write(unsigned char d) {
//  TWDR = d;
//  TWCR = 0x84;
//  while (!(TWCR & 0x80));
//  if (!(TWSR & 0x28)) {
//    i2c_stop();
//    Serial.println("write error+");
//  }
//}
//void i2c_start() {
//  TWCR = 0xA4;
//  while (!(TWCR & 0x80));
//  if (!(TWSR & 0x08)) {
//    i2c_stop();
//    Serial.println("start error");
//  }
//}
//
//void i2c_addr() {
//  TWDR = addr;
//  TWCR = 0x84;
//  while (!(TWCR & 0x80));
//  if (!(TWSR & 0x18)) {
//    i2c_stop();
//    //    Serial.println("addr error");
//  }
//}
//void i2c_send() {
//  TWBR = 0x03;
//
//  c1 = (data >> 8) & 0x0F;
//  c2 = data & 0xFF;
//  i2c_start();
//  // Serial.println("start");
//  i2c_addr();
//  // Serial.println("addr");
//  i2c_write(c1);
//  // Serial.println("c1");
//  i2c_write(c2);
//  // Serial.println("c2");
//  i2c_stop();
//  // Serial.println(data/807);
//}
