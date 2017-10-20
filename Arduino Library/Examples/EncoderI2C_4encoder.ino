/*This example show how to read 4 I2C Encoder
All the 4 encoders will count between -20 and 20, the color of the LED will blink according to the direction of rotation.
The INT pin is readed in polling mode

Connections with Arduino UNO:
- -> GND
+ -> 5V
SDA -> A4
SCL -> A5
INT -> 12
*/

#include <Wire.h>
#include "i2cEncoderLib.h"


#define ENCODER_N 4
const int IntPin = 12;
i2cEncoderLib encoder[ENCODER_N] = { i2cEncoderLib(0x39), i2cEncoderLib(0x30), i2cEncoderLib(0x32), i2cEncoderLib(0x34)}; //Class initialization with the I2C addresses 


int32_t counter[ENCODER_N] = {0, 0, 0, 0};
int32_t maxvalue[ENCODER_N] = {20, 20, 20, 20};
int32_t minvalue[ENCODER_N] = { -20, -20, -20, -20};
int32_t econfig[ENCODER_N] = {(INTE_ENABLE | LEDE_ENABLE | WRAP_DISABLE | DIRE_RIGHT | IPUP_ENABLE | RMOD_X1 ),
                              (INTE_ENABLE | LEDE_ENABLE | WRAP_DISABLE | DIRE_RIGHT | IPUP_ENABLE | RMOD_X1 ),
                              (INTE_ENABLE | LEDE_ENABLE | WRAP_DISABLE | DIRE_RIGHT | IPUP_ENABLE | RMOD_X1 ),
                              (INTE_ENABLE | LEDE_ENABLE | WRAP_DISABLE | DIRE_RIGHT | IPUP_ENABLE | RMOD_X1 ),
                             };
uint8_t encoder_status;

volatile uint8_t i;
void setup(void)
{
  pinMode(IntPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  
  Serial.print("Encoder Test!!\n");
  //Encoder Initialization
  for (i = 0; i < ENCODER_N; i++) {
    Serial.println(econfig[i], HEX);
    encoder[i].begin(econfig[i]);
    encoder[i].writeLEDA(0x00);
    encoder[i].writeLEDB(0x00);
    encoder[i].writeCounter(counter[i]);
    encoder[i].writeMax(maxvalue[i]);
    encoder[i].writeMin(minvalue[i]);
    encoder[i].updateStatus();
  }
}

void loop() {


  if (digitalRead(IntPin) == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);

    for (i = 0; i < ENCODER_N; i++) { //Use a for loop for read all the 4 encoders
        if (digitalRead(IntPin) == HIGH)
            break;
            
      if (encoder[i].updateStatus()) {

        if (encoder[i].readStatus(E_INCREMENT)) {
          encoder[i].writeLEDA(0xff);
        }

        if (encoder[i].readStatus(E_DECREMENT)) {
          encoder[i].writeLEDB(0xff);
        }

        if (encoder[i].readStatus(E_PUSH)) {
          Serial.print("E");
          Serial.print(i);
          Serial.print(" Push\n");
        }

        if (encoder[i].readStatus(E_MAXVALUE)) {
          Serial.print("E");
          Serial.print(i);
          Serial.print(" Max\n");
        }

        if (encoder[i].readStatus(E_MINVALUE)) {
          Serial.print("E");
          Serial.print(i);
          Serial.print(" Min\n");
        }

        counter[i] = encoder[i].readCounterByte();
        encoder[i].writeLEDA(0x00);
        encoder[i].writeLEDB(0x00);
      }
    }

    for (i = 0; i < ENCODER_N; i++) { //print the final value
      Serial.print(counter[i], DEC);
      Serial.print("\t");
    }
    Serial.println();

    digitalWrite(LED_BUILTIN, LOW);
  }
}

