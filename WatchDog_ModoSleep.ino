/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 *              FICA
 *            CIERCOM
 *    SISTEMAS MICROPROCESADOS
 *
 *Nombre: Kevin Oñate
 *Fecha: 31/07/2019
 *
 *Realizar un sistema que permita en intervalos de tiempo (puede ser cada 2 segundos)
 *extrablecidos dormir al sistema y levantarse para lecturas de un conversor analógico
 *digital. Toma la lectura, la envía por comunicación serial y se vuelve a dormir.
 */


#include <LowPower.h>
#include <MsTimer2.h>

void setup() {
  Serial.begin(9600);                  
  MsTimer2::set(1000, timer);         
  MsTimer2::start();   
  float dato = analogRead(0);                
  Serial.print("Dato del sensor: ");
  Serial.println((dato*5.0)/1023.0);      
}

void loop() {
 
}
void timer() {  
  LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF);
}


