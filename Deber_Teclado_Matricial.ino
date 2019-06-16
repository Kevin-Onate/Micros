/*
 * Nombre: Kevin Oñate
 * Fecha: 16/06/2019
 */
#include <Keypad.h>
#include <LiquidCrystal.h>
 LiquidCrystal lcd(13,12,11,10,9,8);
 const int filas = 4;
 const int colms = 4;
 byte Pin_filas[] = {7,6,5,4};     
 byte Pin_colms[] = {3,2,1,0};
 char teclas [filas][colms]=
 {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'} 
 };
 char clave[]="1234";
 int pos=5;
 char pass[4];
 int cont=0;
 int contador=0;
 Keypad teclado = Keypad(makeKeymap(teclas), Pin_filas, Pin_colms, filas, colms); 
     
void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Ingrese la clave");
  lcd.setCursor(pos,1);      
}

void loop() {
  char pulsacion = teclado.getKey();
  if(pulsacion != 0){
    pass[cont]=pulsacion;
    lcd.print(pulsacion);
    cont=cont+1;
    if(cont==4){
      delay(1000);
      if((pass[0]==clave[0]) && (pass[1]==clave[1]) && (pass[2]==clave[2]) && (pass[3]=clave[3])){
      lcd.setCursor(0,0);
      lcd.print("                 ");
      lcd.setCursor(0,0);
      lcd.print("Clave correcta");
      lcd.setCursor(5,1);
      lcd.print("****");
      lcd.setCursor(5,1);
    }
    else{
      pos=5;
      cont=0;
      lcd.setCursor(0,0);
      lcd.print("Clave incorrecta");
      lcd.setCursor(5,1);
      lcd.print("****");
      lcd.setCursor(5,1);
    }  
    }  
    
  }   
    if(pulsacion =='*'){
      cont=0;
      pos=5;
      lcd.setCursor(0,0);
      lcd.print("Ingrese la clave");
      lcd.setCursor(5,1);
      lcd.print("      ");
      lcd.setCursor(5,1);  
    }
}
