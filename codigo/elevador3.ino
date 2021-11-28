//Motor
int LeftPin=2;
int RightPin=3;
//Pisos
int con=0;
//Piso actual
int act=1;
//Piso destino
int nue=0;
//Sensor para detectar los pisos
const int buttonPin = 8;
int buttonState = 0;

void setup(){
  Serial.begin(9600);
  pinMode(LeftPin,OUTPUT);
  pinMode(RightPin,OUTPUT);
  pinMode(buttonPin, INPUT); 
}

void loop(){
  if (Serial.available()!=0) {
    //Ingresar nuevo piso
    nue=Serial.read();
    Serial.println(nue, DEC);
    //Si el elevador se va a mover
    if (nue!=0){
      //Operaciones para detectar el nuevo nivel
      //y saber cuantos pulsos (pisos) omitir para llegar
      //al destino
      con=nue-act;
      act=nue;
      nue=0;
      //En el caso de bajar
      if (con<0){
        //Convertir el resultado a positivo
        con*=-1;
        //Echar a andar el motor
        digitalWrite(LeftPin,HIGH);
        digitalWrite(RightPin,LOW);
        delay(100);
      }
      //En el caso de subir
      else{
        if (con>0){
          //Echar a andar el motor
          digitalWrite(LeftPin,LOW);
          digitalWrite(RightPin,HIGH);
          delay(700);
        }
      }
    }
  }
  //Si aun no se llega al destino
  if (con!=0){
    //Esperar pulso (piso)
    buttonState = digitalRead(buttonPin);
    //Se detecta el pulso
    if (buttonState == HIGH) {
      //Restar uno al contador
      con--;
      //Es el destino? detener motor
      if(con<=0){
        digitalWrite(LeftPin,LOW);
        digitalWrite(RightPin,LOW);
      }
      //Dar tiempo para omitir el pulkso y sebir subiendo/bajando
      else{
        delay(100);
      }
    }
  }
}//Fin del loop
