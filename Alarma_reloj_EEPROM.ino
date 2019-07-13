#include <MsTimer2.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>

LiquidCrystal lcd (13, 12, 11, 10, 9, 8);
int segundero;
int minutero;
int horero;
int funcion = 0;
String hora_alarma;
int al_hora = 0;
String minuto_alarma;
int al_minuto = 0;

void setup() {
  MsTimer2::set(20,reloj);
  MsTimer2::start();
  lcd.begin(16,2);
  Serial.begin(9600);
  attachInterrupt(0,alarma,LOW);
  pinMode(4,OUTPUT);
  lcd.setCursor(0,0);
  lcd.print("HH:MM:SS");
  lcd.setCursor(0,1);
  lcd.print('0');
  lcd.print(EEPROM.read(0));
  lcd.print(':');
  lcd.print(EEPROM.read(1));
  lcd.print(':');
  lcd.print(EEPROM.read(2));
  Serial.println("Presione para configurar la alarma"); 
  horero = EEPROM.read(0);
  minutero = EEPROM.read(1);
  segundero = EEPROM.read(2);
  al_hora = EEPROM.read(3);
  al_minuto = EEPROM.read(4);
  funcion = EEPROM.read(5);
  Serial.print("Alarma programada para ->   ");
  Serial.print(EEPROM.read(3));
  Serial.print(':');
  Serial.println(EEPROM.read(4));
}

void loop() {
  if(funcion==1){
    if(Serial.available()>0){
      hora_alarma=Serial.readString();
      al_hora=hora_alarma.toInt();
      EEPROM.write(3,al_hora);
      Serial.println("Valor guardado");
      if(al_hora>24){
        Serial.println("La hora ingresada no es valida");
        funcion=0;
      }
    }
  }
  if(funcion==2){
    if(Serial.available()>0){
      minuto_alarma=Serial.readString();
      al_minuto=minuto_alarma.toInt();
      EEPROM.write(4,al_minuto);
      Serial.println("Valor guardado");
      if(al_minuto>60){
        Serial.println("El minuto ingresado no es valido");
        funcion=1;
      }
    }
  }
  if(funcion==3){
    Serial.print("Alarma programada para ->  ");
    Serial.print(EEPROM.read(3));
    Serial.print("HH");
    Serial.print(':');
    Serial.print(EEPROM.read(4));
    Serial.println("MM");
    delay(500);
    if(horero==al_hora && minutero==al_minuto){
      Serial.println("ALARMA ACTIVADA");
      digitalWrite(4,HIGH);
      delay(5000);
      digitalWrite(4,LOW);
    }
  }
}

void reloj(){
  if(segundero<59){
    segundero++;
    EEPROM.write(2,segundero);
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
      EEPROM.write(1,minutero);
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
        EEPROM.write(0,horero);
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
}

void alarma(){
  switch(funcion){
    case 0:
      Serial.println("Ingrese la Hora");
      funcion++;
      EEPROM.write(5,funcion);
    break;
    case 1:
      Serial.println("Ingrese los minutos");
      funcion++; 
      EEPROM.write(5,funcion);     
    break;
    case 2:
      Serial.print("La alarma es: ");
      funcion++;
      EEPROM.write(5,funcion);
    break;
    case 3:
      Serial.println("Alarma reinicidad");
      funcion=0;
      al_hora=0;
      al_minuto=0;
      EEPROM.write(3,0);
      EEPROM.write(4,0);
      EEPROM.write(5,funcion);   
    break;
  }
}


