// arduino de 3 motores //
#include <SoftwareSerial.h>
SoftwareSerial BT(8,9); //RX -> 9   TX ->8 


void setup (){ 
  BT.begin(9600);
  pinMode(4, OUTPUT); //Giro M1
  pinMode(5, OUTPUT); //Activar M1
  pinMode(6, OUTPUT); //Activar M2
  pinMode(7, OUTPUT); //Giro M2
  pinMode(11, OUTPUT); //Activar M4
  pinMode(12, OUTPUT); //Giro M4
  
}

void loop(){



  if (BT.available()){
    switch (BT.read()){
      case ('f'):
      
          adelante();
       
      break;    
      case ('b'):
        atras();
      break;
      case ('l'):
        izquierda();
      break;
      case ('r'):
        derecha();
      break;
      case ('s'):
        detener();
      break;
      case ('m'): //subir palanca
        palancaON();
      break;
      case ('n'):  //bajar palanca
        palancaOff();
      break;

    }
  }

}

void atras(){
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
}

void adelante(){
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
}

void derecha(){
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
}

void izquierda(){
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
}

void detener(){
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(11,LOW);
}
void palancaON(){
  digitalWrite(11,HIGH);
  analogWrite(11,70);
  digitalWrite(12,HIGH);
 }
 void palancaOff(){
  digitalWrite(11,HIGH);
   analogWrite(11,50);
  digitalWrite(12,LOW);
 }
