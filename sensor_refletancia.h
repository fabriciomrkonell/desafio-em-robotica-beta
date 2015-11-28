#include <arduino.h>

typedef struct {
  int refletanciaFrente, refletanciaTraz;
} 
sensorRefletancia;


sensorRefletancia iniciarRefletancia(int Frente, int Traz){
  sensorRefletancia aux; 

  aux.refletanciaFrente = Frente;
  aux.refletanciaTraz = Traz;

  return aux;
} 

int leituraRefletancia(int opcao, sensorRefletancia aux){
  long valor;
  //Serial.print("Valor refletancia ");
  switch (opcao){
  case 1:
    valor = analogRead(aux.refletanciaFrente);
    //Serial.print("frente : ");
    break;
  case 2:
    valor = analogRead(aux.refletanciaTraz);
    //Serial.print("traz : ");
    break;
  }
  Serial.println(valor);
  return valor;
}

