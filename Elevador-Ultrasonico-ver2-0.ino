/* 
6|| @Elevador + sensor ultrasonico
|| |Sensor HC-SR04
|| |Ultrasonic sensor Pins:
|| |    VCC: +5VDC
|| |    Trig : Trigger (INPUT) - Pin11
|| |    Echo: Echo (OUTPUT) - Pin 12
|| |    GND: GND
|| |
|| #
*/
//Variables para puente H
#define data01 4
#define data02 5
#define data03 6
#define data04 7
//Variables para los pines de los pulsadores
#define boton01  8
#define boton02  9
#define boton03  10
//Variables para los pines de sensor
#define trigPin 11
#define echoPin 12

int boton01State = 0;         // variable for reading the pushbutton status
int boton02State = 0;         // variable for reading the pushbutton status
int boton03State = 0;         // variable for reading the pushbutton status

int count=0;//mio


long duration, cm, inches;
long nivelActual;
long nivelMover;
void setup() 
{

    Serial.begin (9600);
    
  pinMode(data01, OUTPUT);
  pinMode(data02, OUTPUT);
  pinMode(data03, OUTPUT);
  pinMode(data04, OUTPUT);
  
  pinMode(boton01, INPUT);
  pinMode(boton02, INPUT);
  pinMode(boton03, INPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

 
}

long hacer_medicion()
{

  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  return cm;
  delay(250);
  
}

void loop()
{
  count++;// mio
  delay(10);//mio
  hacer_medicion();
if(count==100){//mio
  hacer_medicion();//
}
  boton01State = digitalRead(boton01);//Leemos la pulsaciones del boton
  boton02State = digitalRead(boton02);
  boton03State = digitalRead(boton03);


if (boton01State==HIGH){ //nivel 3
      
          while(cm>18 )
     
           digitalWrite(data01,1);
           digitalWrite(data02,0);
         count==0;
  //      }

}
else {
      digitalWrite(data01,0);
        digitalWrite(data02,0);
       count==0;
}

}
        
    
