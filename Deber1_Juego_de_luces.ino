//SISTEMAS MICROPROCESADOS
//DEBER #1
//Tema: Juego de luces
//Nombre: Kevin Oñate


int leds[8]={6,7,8,9,10,11,12,13};
int i=0;

void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<8;i++){
    pinMode(leds[i],OUTPUT);
    }
 i=0;  
}

void loop() {
  // put your main code here, to run repeatedly:

  //Se encienden los leds pares
/* for(i=0;i<8;i++){
    if(i % 2 == 0){
      digitalWrite(leds[i],HIGH);
      delay(500);
      digitalWrite(leds[i],LOW);
      delay(500);
      }   
    }
*/  
 
  //Se prenden los leds impares
/*  for(i=0;i<8;i++){
    if(i % 2 !=0){
      digitalWrite(leds[i],HIGH);
      delay(300);
      digitalWrite(leds[i],LOW);
      delay(300);
      }
    }
*/
   // Se repelen los leds
/*   for(i=0;i<=4;i++){
      digitalWrite(leds[i],HIGH);
      digitalWrite(leds[7-i],HIGH);
      delay(300);
   }
   for(i=4;i>=0;i--){
      digitalWrite(leds[i],LOW);
      digitalWrite(leds[7-i],LOW);
      delay(75);
   }   
*/    

      //Los pares se encienden una vez y los impares 2 veces
/*      for(i=0;i<8;i++){
        if(i % 2==0){
          digitalWrite(leds[i],HIGH);
          delay(300);
          digitalWrite(leds[i],LOW);
          delay(300);
          }
        else if(i % 2 !=0){
          digitalWrite(leds[i],HIGH);
          delay(300);
          digitalWrite(leds[i],LOW);
          delay(300);
          digitalWrite(leds[i],HIGH);
          delay(300);
          digitalWrite(leds[i],LOW);
          delay(300);
          }
        }
*/

      //Cada led parpadea dependiendo en la posicion que esté
        for(i=0;i<8;i++){
          switch(i){
            case 1:
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            break;
            case 2:
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            break;
            case 3:
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            break;
            case 4:
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            break;
            case 5:
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            break;
            case 6:
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            break;
            case 7:
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            digitalWrite(leds[i],HIGH);
            delay(500);
            digitalWrite(leds[i],LOW);
            delay(500);
            break;
            }
          }
}
