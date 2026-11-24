const int SENSOR = A0;
const int VERDE = 2;
const int AMARELO = 3;
const int VERMELHO = 4;

const float LIMITE_ATENCAO = 27.0;
const float LIMITE_CRITICO = 31.0;

void setup() {
  pinMode(VERDE, OUTPUT);
  pinMode(AMARELO, OUTPUT);
  pinMode(VERMELHO, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float tensao = analogRead(SENSOR) * 5.0 / 1024.0;
  float tempC = (tensao - 0.5) * 100.0;

  digitalWrite(VERDE, tempC < LIMITE_ATENCAO);
  digitalWrite(AMARELO, tempC >= LIMITE_ATENCAO && tempC < LIMITE_CRITICO);
  digitalWrite(VERMELHO, tempC >= LIMITE_CRITICO);

  Serial.print("Temperatura: ");
  Serial.print(tempC);
  Serial.println(" C");
  delay(500);
}
