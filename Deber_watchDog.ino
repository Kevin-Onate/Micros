/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 *              FICA
 *            CIERCOM
 *    SISTEMAS MICROPROCESADOS
 *
 *Nombre: Kevin Oñate
 *Fecha: 28/07/2019
 *
 *Realizar un programa que reinicie el sistema al tener la hora 00:11:10 
 *El princeso se observa en unaLCD
 */
#include <LiquidCrystal.h>
#include <MsTimer2.h>
#include <EEPROM.h>
#include <avr/wdt.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int segundero;
int minutero;
int horero;

void setup() {
//  EEPROM.write(0, 0);
//  EEPROM.write(1, 0);
//  EEPROM.write(2, 0);
//  EEPROM.write(3, 0);
  horero = EEPROM.read(0);
  minutero = EEPROM.read(1);
  segundero = EEPROM.read(2);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("HH:MM:SS");
  lcd.setCursor(0,1);
  lcd.print('0');
  lcd.print(EEPROM.read(0));
  lcd.print(':');
  lcd.print(EEPROM.read(1));
  lcd.print(':');
  lcd.print(EEPROM.read(2));
  MsTimer2::set(10, reloj);
  MsTimer2::start();
}
void loop() {

}

void reloj(){
  if(segundero<59){
    segundero++;
    EEPROM.update(2,segundero);
    if(segundero<10){
      lcd.setCursor(6,1);
      lcd.print("0 ");
      lcd.setCursor(7,1);
      lcd.print(EEPROM.read(2));
    }
    else{
      lcd.setCursor(6,1);
      lcd.print(EEPROM.read(2));  
    }
  }  
  else{
    segundero=0;
    if(segundero==0){
      lcd.setCursor(6,1);
      lcd.print("00");
    }
    if(minutero<59){
      minutero++;
      EEPROM.update(1,minutero);
      if(minutero<10){
        lcd.setCursor(2,1);
        lcd.print(":0 :");
        lcd.setCursor(4,1);
        lcd.print(EEPROM.read(1));
      }
      else{
        lcd.setCursor(2,1);
        lcd.print(":  :");
        lcd.setCursor(3,1);
        lcd.print(EEPROM.read(1)); 
      }
    }
    else{
      minutero=0;
      if(minutero==0){
        lcd.setCursor(3,1);
        lcd.print("00");
      }
      if(horero<23){
        horero++;
        EEPROM.update(0,horero);
        if(horero<10){
          lcd.setCursor(0,1);
          lcd.print("0 ");
          lcd.setCursor(1,1);
          lcd.print(EEPROM.read(0));
        }
        else{
          lcd.setCursor(0,1);
          lcd.print(EEPROM.read(0));  
        }  
      }
      else{
        horero=0;
        if(horero==0){
          lcd.setCursor(0,1);
          lcd.print("00");
        }    
      }  
    }    
  }
  if(horero==0 && minutero==10 && segundero==50){
    EEPROM.update(1,11);
    EEPROM.update(2,10);
    delay(100);
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("REINICIO");
    wdt_enable(WDTO_8S);
    MsTimer2::stop();
  }
}
