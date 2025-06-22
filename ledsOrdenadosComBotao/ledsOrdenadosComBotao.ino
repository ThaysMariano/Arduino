
// Acender leds em ordem ao pressionar o botão
// 22/06/2025 Thays Mariano

// variáveis
int botao = 2; //pino do botão
int leds[] = {9, 10, 11, 12}; //pino dos leds
int ledsNum = 4; // quantidade de leds
int pos =0; //posição do led ligado

void setup() {
  // put your setup code here, to run once:

  // todos os leds são saídas
  for (int i =0; i<ledsNum; i++) {
    pinMode(leds[i], OUTPUT);
  }

  //botão como entrada
  pinMode(botao, INPUT_PULLUP); //LOW quando pressionado
 
}

void loop() {
  // put your main code here, to run repeatedly:

  //ao pressionar o botão:
  if(digitalRead(botao) == LOW){

    //apaga todos os leds
    for (int i=0; i<ledsNum; i++) {
    digitalWrite(leds[i], LOW);
    }

    //liga o led da vez
    digitalWrite(leds[pos], HIGH);

    //add posição para ligar o próximo led
    pos++;
  }

  //se já chegou no último volta para o início
  if(pos>3){
    pos = 0;
  }

  //evitar bounce
  while (digitalRead(botao) == LOW);
   delay(100);

}
