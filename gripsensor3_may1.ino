#include <Arduino.h>

int in1 = A0;
int Vout1 = 0;
float Vin = 1024; // 3.3V in units of V, assumed to the same for all of the FSRs
float R1 = 5100; // in units of Ohms, same for all FSRs
float FSR_1 = 0;
int force1 = 0;
int hardestSqueeze = 1024; //currently set to max, but may be more useful to set to ~650

void setup() {
  Serial.begin(9600);
  pinMode(in1, INPUT);

  //calibrate for maximum possible force
  Serial.println("Hello, please begin by squeezing as hard as you can!");
  delay(1500);
  int temp = 0;
  for(int i =0; i < 500; i++){
    temp = (temp +  analogRead(in1))/2;
  }
  hardestSqueeze = temp;
  temp = 0;
  delay(1500);
  Serial.println("STOP");
  delay(1500);
  Serial.print("Good Job! Your hardest was: ");
  Serial.println(hardestSqueeze);
  delay(2000);
  Serial.println("Thank you. Calibration is now complete");
}

void loop() {
  
  Vout1 = analogRead(in1);
  //Serial.println(Vout1);
  
  float percent = float(float(Vout1)*100/float(hardestSqueeze));
  //Serial.println(hardestSqueeze);
  Serial.println(percent);
  if(percent<50){
    Serial.println("You are NOT SQUEEZING");
  }
  
  unsigned long timeBegin = 0;
  unsigned long timeEnd;
  if(percent>=50){
    Serial.println("You are SQUEEZING");
    timeEnd = micros();
    Serial.println(timeEnd);
 } 
    unsigned long duration = timeEnd - timeBegin;
    double durationSec = (double)duration / 1000000.0;
    Serial.print("Duration in seconds: ");
    Serial.println(durationSec);
}
 
