#include <arduino.h>

typedef struct {
  int motorENA, motorENB, motorIN1, motorIN2, motorIN3, motorIN4;
} 
driverMotor;

driverMotor iniciarMotor(int ENA, int ENB, int IN1, int IN2, int IN3, int IN4){
  driverMotor aux; 

  aux.motorENA = ENA;
  aux.motorENB = ENB;
  aux.motorIN1 = IN1;
  aux.motorIN2 = IN2;
  aux.motorIN3 = IN3;
  aux.motorIN4 = IN4;

  pinMode (aux.motorENA, OUTPUT);
  pinMode (aux.motorENB, OUTPUT);
  pinMode (aux.motorIN1, OUTPUT);
  pinMode (aux.motorIN2, OUTPUT);
  pinMode (aux.motorIN3, OUTPUT);
  pinMode (aux.motorIN4, OUTPUT);
  
  return aux;
} 

void controleMotor(driverMotor aux, int sentido, float potenciaEsquerda ,float potenciaDireita, int tempo){
  int pE = (int)(potenciaEsquerda * 255);
  int pD = (int)(potenciaDireita * 255);
  switch (sentido){
  case 6:
    //Serial.println("motores sentido para direita");
    analogWrite(aux.motorENA, pE);
    analogWrite(aux.motorENB, pD);
    digitalWrite(aux.motorIN1, LOW);
    digitalWrite(aux.motorIN2, HIGH);
    digitalWrite(aux.motorIN3, LOW);
    digitalWrite(aux.motorIN4, HIGH);
    delay(tempo);
    break;
  case 4:
    //Serial.println("motores sentido para esquerda");
    analogWrite(aux.motorENA, pE);
    analogWrite(aux.motorENB, pD);
    digitalWrite(aux.motorIN1, HIGH);
    digitalWrite(aux.motorIN2, LOW);
    digitalWrite(aux.motorIN3, HIGH);
    digitalWrite(aux.motorIN4, LOW);
    delay(tempo);
    break;
  case 2:
    //Serial.println("motores sentido para traz");
    analogWrite(aux.motorENA, pE);
    analogWrite(aux.motorENB, pD);
    digitalWrite(aux.motorIN1, HIGH);
    digitalWrite(aux.motorIN2, LOW);
    digitalWrite(aux.motorIN3, LOW);
    digitalWrite(aux.motorIN4, HIGH);
    delay(tempo);
    break;
  case 8:
    //Serial.println("motores sentido para frente");
    analogWrite(aux.motorENA, pE);
    analogWrite(aux.motorENB, pD);
    digitalWrite(aux.motorIN1, LOW);
    digitalWrite(aux.motorIN2, HIGH);
    digitalWrite(aux.motorIN3, HIGH);
    digitalWrite(aux.motorIN4, LOW);
    delay(tempo);
    break;
  case 5:
    //Serial.println("motores parado");
    analogWrite(aux.motorENA, pE);
    analogWrite(aux.motorENB, pD);
    digitalWrite(aux.motorIN1, LOW);
    digitalWrite(aux.motorIN2, LOW);
    digitalWrite(aux.motorIN3, LOW);
    digitalWrite(aux.motorIN4, LOW);
    break;
  }
}  



