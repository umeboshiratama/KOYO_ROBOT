#include <Wire.h>


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.requestFrom(8,1);


  while(Wire.available()){
      char c =Wire.read();
      Serial.print(c,HEX);
    }

  delay(500);
} 