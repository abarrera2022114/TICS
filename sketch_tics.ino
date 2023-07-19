int estado = 0; //variables que necesitaremos
int r1 = 7;
int r2 = 6;

void setup() {
    Serial.begin(9600);  //activamos el monitor serial
    pinMode(r1,OUTPUT);//activa como salida el Rele1 
    pinMode(r2,OUTPUT);//activa como salida el Rele2
    digitalWrite(r1,HIGH);//apagar el foco
    digitalWrite(r2,HIGH);//apagar el foco
  }

void loop() {
  
 if(Serial.available() > 0){ //que lea los datos si se activa el if
    estado = Serial.read(); //estado guardara los valores del bluetooth
 }

 if(estado == '1'){ //cuando el bluetooth mande un 1 se activara la secuencia
    digitalWrite(r1,LOW);
    digitalWrite(r2,HIGH);
 }

 if(estado == '2'){ //cuando el bluetooth mande un 2 se activara la secuencia
    digitalWrite(r1,HIGH);
    digitalWrite(r2,LOW);
 }

}