#include <Wire.h>
#include "i2cEncoderLib.h"

/*In this example, i want my variable counter between -10 and 10. 
When it reaches the limit the LED will blink red in case of minimum and will blink green when it reaches the maximum.*/

const int IntPin = 12;
i2cEncoderLib encoder(0x30); //Initialize the I2C encoder class with the I2C address 0x30 is the address with all the jumper open
int32_t counter;
uint8_t encoder_status;
void setup(void)
{
  pinMode(IntPin, INPUT);
  Serial.begin(115200);
  Serial.print("Encoder Test!!\n");
  encoder.begin((INTE_ENABLE | LEDE_ENABLE | WRAP_DISABLE | DIRE_RIGHT | IPUP_ENABLE | RMOD_X1 ));
  encoder.writeCounter(0);
  encoder.writeMax(10); //Set maximum threshold
  encoder.writeMin(-10); //Set minimum threshold
  encoder.writeLEDA(0x00);
  encoder.writeLEDB(0x00);
}
void loop() {
  if (digitalRead(IntPin) == LOW) {
  if (encoder.updateStatus()) {
      if (encoder.readStatus(E_PUSH)) {
        Serial.println("Encoder Pushed!");
      }
      if (encoder.readStatus(E_MAXVALUE)) {
        Serial.println("Encoder Max!");
        encoder.writeLEDA(0xFF);
        delay(50);
        encoder.writeLEDA(0x00);
      }
      if (encoder.readStatus(E_MINVALUE)) {
        Serial.println("Encoder Min!");
        encoder.writeLEDB(0xFF);
        delay(50);
        encoder.writeLEDB(0x00);
      }
      counter = encoder.readCounterByte(); //Read only the first byte of the counter register
      Serial.print("Encoder: ");
      Serial.println(counter, DEC);
    }
  }
}

