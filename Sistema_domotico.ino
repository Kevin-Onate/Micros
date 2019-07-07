/*
 *          UNIVERSIDAD TÉCNICA DEL NORTE
 *                        FICA
 *                      CIERCOM
 *              SISTEMAS MICROPROCESADOS
 *              
 *Nombre: Kevin oñate
 *Fecha: 07/07/2019
 *Teama: Segurdidad domótica
 *
 *Instrucciones:
 *  Realizar un progrma de seguridad domótica quepermita encender
 *  las luces de un domicilio de 5 habitaciones de forma aleatoria
 *  solo en horario nocturno. El sistema se activa al ingresar una
 *  contraseña por comunicación serial.
 */
#include <MsTimer2.h>

int segundero;
int minutero;
int horero;
int funcion=0;
String clave;
boolean validar;
int leds;
int on=0;

void setup() {
  MsTimer2::set(1000,reloj);
  MsTimer2::start();
  Serial.begin(9600);
  //attachInterrupt(0,funcionamiento,LOW);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  Serial.println("INGRESE LA CLAVE");
}

void loop() {
  if(Serial.available()>0){
    clave=Serial.readString();
    if(clave.length()!=4){
      Serial.println("CLAVE INVALIDA");
    }
    else{
      validar=clave.equals("1234");
      if(validar==true){
        Serial.println("CLAVE VALIDA");
        leds=random(1,6);
        if((horero>=19 && horero<24) || (horero>=0 && horero<=6)){
          digitalWrite(leds,HIGH);
          delay(500);
          digitalWrite(leds,LOW);
          delay(500);  
        }
        else{
          digitalWrite(3,LOW);  
          digitalWrite(4,LOW);
          digitalWrite(5,LOW);
          digitalWrite(6,LOW);
          digitalWrite(7,LOW);
        }
      }
      else{
        Serial.println("CLAVE INVALIDA");  
      }    
    }
  }
}

void reloj(){
  if(segundero<60){
    segundero++;
//    Serial.print(horero);
//    Serial.print(':');
//    Serial.print(minutero);
//    Serial.print(':');
//    Serial.println(segundero);       
  }
  else{         //else segundero
    segundero=0;
//    Serial.print(horero);
//    Serial.print(':');
//    Serial.print(minutero);
//    Serial.print(':');
//    Serial.println(segundero);
    if(minutero<60){
      minutero++;
//      Serial.print(horero);
//      Serial.print(':');
//      Serial.print(minutero);
//      Serial.print(':');
//      Serial.println(segundero);
    }  
    else{         //else minutero
      minutero=0;
//      Serial.print(horero);
//      Serial.print(':');
//      Serial.print(minutero);
//      Serial.print(':');
//      Serial.println(segundero);
      if(horero<24){
        horero++;
//        Serial.print(horero);
//        Serial.print(':');
//        Serial.print(minutero);
//        Serial.print(':');
//        Serial.println(segundero);
      }    
      else{       //else horero
        horero=0;  
//        Serial.print(horero);
//        Serial.print(':');
//        Serial.print(minutero);
//        Serial.print(':');
//        Serial.println(segundero);
      }
    }
  }       
}

