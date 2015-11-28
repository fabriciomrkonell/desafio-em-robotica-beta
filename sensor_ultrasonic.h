#include <arduino.h>

typedef struct {
  int ultrasonicECHO, ultrasonicTRIG;
} 
sensorUltrasonic;


sensorUltrasonic iniciarUltrasonic(int ECHO, int TRIG){
  sensorUltrasonic aux; 

  aux.ultrasonicECHO = ECHO;
  aux.ultrasonicTRIG = TRIG;

  pinMode (aux.ultrasonicECHO, INPUT);
  pinMode (aux.ultrasonicTRIG, OUTPUT);
  
  return aux;
} 

int leituraUltrasonic(sensorUltrasonic aux){
  digitalWrite(aux.ultrasonicTRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(aux.ultrasonicTRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(aux.ultrasonicTRIG, LOW);  
  long duration = pulseIn(aux.ultrasonicECHO,HIGH);
  long distancia = duration /29 / 2 ;
  Serial.print("Valor distancia : ");
  Serial.println(distancia);
  return distancia;
}
