#include <LowPower.h>
#include <MsTimer2.h>

void setup() {
  Serial.begin(9600);                  
  MsTimer2::set(1000, timer);         
  MsTimer2::start();                   
  Serial.print("Dato del sensor: ");
  Serial.println(analogRead(0));      
}

void loop() {
 
}
void timer() {  
  LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF);
}


