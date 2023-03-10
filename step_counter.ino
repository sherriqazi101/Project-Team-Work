#include "EncoderStepCounter.h"

#define ENCODER_PIN1 2
#define ENCODER_PIN2 3

#define AIN1 4
#define AIN2 5
#define BIN1 7
#define BIN2 8

// Create instance for one full step encoder
EncoderStepCounter encoder(ENCODER_PIN1, ENCODER_PIN2);
// Use the following for half step encoders
//EncoderStepCounter encoder(ENCODER_PIN1, ENCODER_PIN2, HALF_STEP);

void setup() {
  Serial.begin(9600);
  // Initialize encoder
  encoder.begin();
}

void interrupt() {
  encoder.tick();
}

signed char lastpos = 0;
void loop() {
  digitalWrite(AIN1,HIGH); 
  digitalWrite(AIN2,LOW);
  digitalWrite(BIN1,HIGH); 
 digitalWrite(BIN2,LOW);

  delay(700);
  // Call tick on every loop
  encoder.tick();
  // Print out current encoder value
  // Have a look at the InterruptExample on how
  // to have a bigger variable for the counter
  signed char pos = encoder.getPosition();
  if (pos != lastpos) {
    lastpos = pos;
    Serial.println(pos);
  }
}
