#include <Wire.h>

<<<<<<< HEAD
=======
#define I2C_READ_LENGTH 1
>>>>>>> 2a0d11c8df12158e590e979bde933ffba3259f34

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.requestFrom(8,I2C_READ_LENGTH);
  char i2cBuf[I2C_READ_LENGTH]

<<<<<<< HEAD

  while(Wire.available()){
      char c =Wire.read();
      Serial.print(c,HEX);
    }

=======
  for(int i=0;i<I2C_READ_LENGTH;i++){
    i2cBuf[i]=Wire.read();
  }
>>>>>>> 2a0d11c8df12158e590e979bde933ffba3259f34
  delay(500);
} 