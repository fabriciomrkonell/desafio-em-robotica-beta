#include "driver_motor.h"
#include "sensor_ultrasonic.h"
#include "sensor_refletancia.h"

driverMotor motor;
sensorUltrasonic sonar;
sensorRefletancia refletancia;

long corBranca = 800;
boolean flag = true;
int cont = 0;

void setup(){
  motor=iniciarMotor(6,3,7,5,4,2);
  sonar=iniciarUltrasonic(9,8);
  refletancia=iniciarRefletancia(1,0);
  Serial.begin(9600);  
  delay(4000);
}

void loop(){
  
  long refletanciaFrente = leituraRefletancia(1,refletancia);
  long refletanciaTraz = leituraRefletancia(2,refletancia);

  if (refletanciaFrente < corBranca || refletanciaTraz < corBranca){   
    if (refletanciaFrente < corBranca && refletanciaTraz > corBranca){
       controleMotor(motor,2,1,1,1200);
      controleMotor(motor,4,1,1,600);
     
    }
    if (refletanciaFrente > corBranca && refletanciaTraz < corBranca){
      controleMotor(motor,8,1,1,1200);
      controleMotor(motor,6,1,1,600);
    }
    controleMotor(motor,8,1,1,0);
  }else{

    int distancias[5] = {leituraUltrasonic(sonar), leituraUltrasonic(sonar), leituraUltrasonic(sonar), leituraUltrasonic(sonar), leituraUltrasonic(sonar)};
    int distancia = 0;
    int distanciaLast = 0;
  
    for(int i = 0; i < 5; i++){
      distancia = distancia + distancias[i];
    }
   
    distancia = distancia / 5;
    
    if ( distancia < 70 && distanciaLast < 70){
      distanciaLast = distancia;
      controleMotor(motor,8,1,1,0); 
      flag = true;
    } else {         
       controleMotor(motor,6,0.7,0.7,0);
       if(flag == true){
         controleMotor(motor,4,1,1,0);
       }
       flag = false;
    }
  }
}









