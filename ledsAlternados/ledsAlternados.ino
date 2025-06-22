
int ledAzul = 10;
int ledVermelho = 11;
int ledAmarelo = 12;
int ledVerde = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledAzul, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledAzul, HIGH);
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAmarelo, HIGH);
  digitalWrite(ledVerde, LOW);
  delay(1500);
  digitalWrite(ledAzul, LOW);
  digitalWrite(ledVermelho, HIGH);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVerde, HIGH);
  delay(1500);
}
