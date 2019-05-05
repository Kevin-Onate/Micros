/*
 * SISTEMAS MIRCOPROCESADOS
 * NOMBRE: Kevin Oñate
 * FECHA: 01/05/2019
 * TEMA: Sumador con pulsadores
 * 
 * Instrucción: Realice un programa que mediante dos pulsadores (operando 1 y operando 2) 
 *              sumen su valor de veces (hasta 25 cada uno)que han sido presionados. 
 *              Dicho valor se mostrará en displas multiplexados al presionar un tercer pulsador
 */

int bt1=5;
int bt2=4;
int bt3=3;
int cont1=0;
int cont2=0;
int suma=0;
int A=11;
int B=10;
int C=9;
int D=8;
int decenas;
int unidades;
int dec=13;
int uni=12;

void setup() {
  // put your setup code here, to run once:
  pinMode(bt2,INPUT);
  pinMode(bt1,INPUT);
  pinMode(bt3,INPUT);
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(dec,OUTPUT);
  pinMode(uni,OUTPUT);
  Serial.begin(9600) ;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(bt1)==LOW){
    delay(300);
    cont1++;
     Serial.println(cont1) ;
    }
    if(cont1==26){
      cont1=0 ;
    }
  if(digitalRead(bt2)==LOW){
    delay(300);
    cont2++;
     Serial.println(cont2) ;
    }
    if(cont2==26){
      cont2=0 ;
    }
    if(digitalRead(bt3)==LOW){
      delay(300);
      suma=cont1+cont2;
      decenas=suma/10;
      unidades=suma-decenas*10;
      digitalWrite(uni,HIGH);
      digitalWrite(dec,LOW);
      contador(unidades);
      delay(50);
      digitalWrite(uni,LOW);
      digitalWrite(dec,HIGH);
      contador(decenas);
      delay(50);
      }
      
  
}


  void contador (int dato){
    switch(dato){
     case 0:
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
     break;
     case 1:
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
     break;
     case 2:
      digitalWrite(A,LOW);
      digitalWrite(B,HIGH);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
     break;
     case 3:
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
     break;
     case 4:
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
     break;
     case 5:
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
     break;
     case 6:
      digitalWrite(A,LOW);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
     break;
     case 7:
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
     break;
     case 8:
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,HIGH);
     break;
     case 9:
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,HIGH);
      break;
      }
}
