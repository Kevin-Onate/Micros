/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 *            FICA
 *          CIERCOM
 *   SISTEMAS MICROPROCESADOS
 *
 *NOMBRE: Kevin Oñate
 *FECHA: 17/05/2019
 */

String cedula;
int tam;
String region;
int num_region;
int num1;
int num2;
int num3;
int num4;
int num5;
int num6;
int num7;
int num8;
int num9;
int num10;
 
void setup() {
  Serial.begin(9600);

}

void loop() {
if(Serial.available()>0){
  cedula=Serial.readString();
  Serial.println(cedula);
  delay(200);
  tam=cedula.length();
  if(tam ==11 && cedula.charAt(9)== '-' ){
    Serial.println("La cedula que ingreso es:"+cedula);
    region=cedula.substring(0,2);
    num_region=region.toInt();
    delay(100);
    if(num_region>=0 && num_region<=24){
      num1=(cedula.substring(0,1)).toInt();
      num2=(cedula.substring(1,2)).toInt();
      num3=(cedula.substring(2,3)).toInt();
      num4=(cedula.substring(3,4)).toInt();
      num5=(cedula.substring(4,5)).toInt();
      num6=(cedula.substring(5,6)).toInt();
      num7=(cedula.substring(6,7)).toInt();
      num8=(cedula.substring(7,8)).toInt();
      num9=(cedula.substring(8,9)).toInt();
      num10=(cedula.substring(10,11)).toInt();      //último número

      //Operación impares n1,n3,n5,n7,n9
      num1=num1*2;
      if(num1>9){
        num1=num1-9;
        }
      num3=num3*2;
      if(num3>9){
        num3=num3-9;
        }  
      num5=num5*2;
      if(num5>9){
        num5=num5-9;
        }
      num7=num7*2;
      if(num7>9){
        num7=num7-9;
        }
     num9=num9*2;
      if(num9>9){
        num9=num9-9;
        }
      int suma_impares=num1+num3+num5+num7+num9;
      int suma_pares=num2+num4+num6+num8;
      int suma_total=suma_impares+suma_pares;
      if(num10==(suma_total%10)|| num10==(10-suma_total%10)){
        Serial.println("La cedula ingresada es correcta");
        switch(num_region){
          case 01:
             Serial.println("Este numero de cedula pertenece a la provincia de Azuay");
          break;
          case 02:
             Serial.println("Este numero de cedula pertenece a la provincia de Bolivar");
          break;
          case 03:
             Serial.println("Este numero de cedula pertenece a la provincia de Cañar");
          break;
          case 04:
             Serial.println("Este numero de cedula pertenece a la provincia de Carchi");
          break;
          case 05:
             Serial.println("Este numero de cedula pertenece a la provincia de Cotopaxi");
          break;
          case 06:
             Serial.println("Este numero de cedula pertenece a la provincia de Chimborazo");
          break;
          case 07:
             Serial.println("Este numero de cedula pertenece a la provincia de EL Oro");
          break;
          case 8:
             Serial.println("Este numero de cedula pertenece a la provincia de Esmeraldas");
          break;
          case 9:
             Serial.println("Este numero de cedula pertenece a la provincia de Guayas");
          break;
          case 10:
             Serial.println("Este numero de cedula pertenece a la provincia de Imbabura");
          break;
          case 11:
             Serial.println("Este numero de cedula pertenece a la provincia de Loja");
          break;
          case 12:
             Serial.println("Este numero de cedula pertenece a la provincia de Los Rios");
          break;
          case 13:
             Serial.println("Este numero de cedula pertenece a la provincia de Manabi");
          break;
          case 14:
             Serial.println("Este numero de cedula pertenece a la provincia de Morona Santiago");
          break;
          case 15:
             Serial.println("Este numero de cedula pertenece a la provincia de Napo");
          break;
          case 16:
             Serial.println("Este numero de cedula pertenece a la provincia de Pastaza");
          break;
          case 17:
             Serial.println("Este numero de cedula pertenece a la provincia de Pichincha");
          break;
          case 18:
             Serial.println("Este numero de cedula pertenece a la provincia de Tungurahua");
          break;
          case 19:
             Serial.println("Este numero de cedula pertenece a la provincia de Zamora Chinchipe");
          break;
          case 20:
             Serial.println("Este numero de cedula pertenece a la provincia de Galapagos");
          break;
          case 21:
             Serial.println("Este numero de cedula pertenece a la provincia de Sucumbios");
          break;
          case 22:
             Serial.println("Este numero de cedula pertenece a la provincia de Orellana");
          break;
          case 23:
             Serial.println("Este numero de cedula pertenece a la provincia de Santo Domingo");
          break;
          case 24:
             Serial.println("Este numero de cedula pertenece a la provincia de Santa Elena");
          break;
          }
        
        }
        else{
          Serial.println("La cedula ingresada no es valida");
          }
  } 
     else{
      Serial.println("La cedula ingresada no es valida");   
         }        
    }
  else {
    Serial.println("La cedula ingresada no es valida");
    }
  }  

}
