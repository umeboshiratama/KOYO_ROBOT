#include <Wire.h>

#define I2C_READ_LENGTH 1
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.requestFrom(8,I2C_READ_LENGTH);
  char i2cBuf[I2C_READ_LENGTH];

  for(int i=0; i<I2C_READ_LENGTH; i++){
    i2cBuf[i]=Wire.read();
    Serial.println(i2cBuf[i],HEX);
  }
  delay(500);
} 