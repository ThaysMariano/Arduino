//Sensor de distancia com leds (niveis) e auto-falante
// 09 e 10 de agosto de 2025 

//Leitura de distancia com o sensor HC-SR04
#include <Ultrasonic.h>
 Ultrasonic ultrassom(10,8); //trig(10) echo(8)

long distancia;

int ledVermelho = 2;
int ledAmarelo = 3;
int ledAzul= 4;
int ledVerde = 5;

int autoFalante = 6;

//metodo para desligar leds
void desligar_leds(int led1, int led2, int led3){
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}

 void setup() {
 Serial.begin(9600); 

 pinMode(ledVermelho, OUTPUT);
 pinMode(ledVerde, OUTPUT);
 pinMode(ledAmarelo, OUTPUT);
 pinMode(ledAzul, OUTPUT);

 pinMode(autoFalante, OUTPUT);

 }

 void loop()
 {
   distancia = ultrassom.Ranging(CM); //define em cm a distancia
   Serial.print(distancia); //imprime o valor da variável (para testes)
   Serial.print(" ");
   delay(100);

  //iniciar desligados
   digitalWrite(ledAmarelo, LOW);
   desligar_leds(ledAzul, ledVerde, ledVermelho);

  //comparações
  if(distancia>=55 && distancia<=80){
    digitalWrite(ledAmarelo, HIGH);

    desligar_leds(ledAzul, ledVerde, ledVermelho);
    
  }else if(distancia>=30 && distancia<55){
    digitalWrite(ledVerde, HIGH);

    desligar_leds(ledAzul, ledAmarelo, ledVermelho);

  }else if(distancia>=10 && distancia<30){
    digitalWrite(ledAzul, HIGH);

    desligar_leds(ledAmarelo, ledVerde, ledVermelho);

  }else if(distancia<10){
    digitalWrite(ledVermelho, HIGH);
    tone(autoFalante, 1000);
    delay(100);
    noTone(autoFalante);

    desligar_leds(ledAzul, ledVerde, ledAmarelo);
  }
 }