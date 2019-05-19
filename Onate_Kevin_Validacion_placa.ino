/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 *            FICA
 *           CIERCOM
 *      SISTEMAS MICROPROCESADOS
 *      
 * NOMBRE: Kevin oñate
 * FECHA: 17/05/2019
 */

String placa;
int tam;
String letras;
String numeros;
int num;
char let1;
char let2;

void setup() {
  Serial.begin(9600);
  Serial.println("Ingrese la placa");

}

void loop() {
  if(Serial.available()>0){
    placa=Serial.readString();
    Serial.println(placa);
    delay(200);
    tam=placa.length();
    if(tam==7){
      letras=placa.substring(0,3);
      numeros=(placa.substring(3,7));
      if((letras.length()==3) && (numeros.length()==4)){
        num=numeros.toInt();
        if(num>0 && num<9999){
      
        Serial.println("La placa que ingreso es; "+letras+"-"+numeros);
        let1=placa.charAt(0);
        let2=letras.charAt(1);
        if((let1=='A') || (let1=='a')){
          Serial.println("La placa es la provicnia de Azuay");
          }
          if((let1=='B') || (let1=='b')){
          Serial.println("La placa es la provicnia de Bolivar");
          }
          if((let1=='U') || (let1=='u')){
          Serial.println("La placa es la provicnia de Canar");
          }
          if((let1=='C' || (let1=='c')) ){
          Serial.println("La placa es la provicnia de Carchi");
          }
          if((let1=='H') || (let1=='h')){
          Serial.println("La placa es la provicnia de Chimborazo");
          }
          if((let1=='X') || (let1=='x')){
          Serial.println("La placa es la provicnia de Cotopaxi");
          }
          if((let1=='O') || (let1=='o')){
          Serial.println("La placa es la provicnia de El Oro");
          }
          if((let1=='E') || (let1=='e')){
          Serial.println("La placa es la provicnia de Esmeraldas");
          }
          if((let1=='W') || (let1=='w')){
          Serial.println("La placa es la provicnia de Galapagos");
          }
          if((let1=='G') || (let1=='g')){
          Serial.println("La placa es la provicnia de Guayas");
          }
          if((let1=='I') || (let1=='i')){
          Serial.println("La placa es la provicnia de Imbabura");
          }
          if((let1=='L') || (let1=='l')){
          Serial.println("La placa es la provicnia de Loja");
          }
          if((let1=='R') || (let1=='r')){
          Serial.println("La placa es la provicnia de Los Rios");
          }
          if((let1=='M') || (let1=='m')){
          Serial.println("La placa es la provicnia de Manabi");
          }
          if((let1=='V') || (let1=='v')){
          Serial.println("La placa es la provicnia de Morona Santiago");
          }
          if((let1=='N') || (let1=='n')){
          Serial.println("La placa es la provicnia de Napo");
          }
          if((let1=='O') || (let1=='o')){
          Serial.println("La placa es la provicnia de Orellana");
          }
          if((let1=='S') || (let1=='s')){
          Serial.println("La placa es la provicnia de Pastaza");
          }
          if((let1=='P') || (let1=='p')){
          Serial.println("La placa es la provicnia de Pichincha");
          }
          if((let1=='Y') || (let1=='y')){
          Serial.println("La placa es la provicnia de Santa Elena");
          }
          if((let1=='J') || (let1=='j')){
          Serial.println("La placa es la provicnia de Santo Domingo");
          }
          if((let1=='K') || (let1=='k')){
          Serial.println("La placa es la provicnia de Sucumbios");
          }
          if((let1=='T') || (let1=='t')){
          Serial.println("La placa es la provicnia de Tungurahua");
          }
          if((let1=='Z') || (let1=='z')){
          Serial.println("La placa es la provicnia de Zamora Chinchipe");
          }
       if((let2=='A') || (let2=='U') || (let2=='Z') && (let2!='E') && (let2!='X') && (let2!='M') || (let2=='a') || (let2=='u') || (let2=='z') && (let2!='e') && (let2!='x') && (let2!='m')){
        delay(300);
        Serial.println("La placa es de un vehiculo comercial");
        if((let2=='E') && (let2!='X') && (let2!='M') || (let2=='e') && (let2!='x') && (let2!='m')){
          Serial.println("La placa es de un vehiculo gubernamental");
          if((let2=='X') || (let2=='x') &&(let2!='M') && (let2!='m')){
            Serial.println("La placa es de un vehículo de uso oficial");
            if((let2=='M') || (let2=='m')){
              Serial.println("La placa es de un vehiculo de los GAD");
              }
              
            }
          }
        }
        else{
                Serial.println("La placa es de un vehiculo particular");
                }
       
          
            
            
        }
    }
           else{
            Serial.println("La placa ingresada no es valida");
            }
      
      }
     else
     Serial.println("La placa ingresada no es valida"); 
    
    
    }
 

}
