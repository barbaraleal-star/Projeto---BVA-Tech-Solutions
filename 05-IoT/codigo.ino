// Monitoramento de temperatura da sala de servidores
// Le o sensor TMP36 e indica o estado por LEDs:
// verde = normal, amarelo = atencao, vermelho = critico

const int PINO_SENSOR = A0;   // sensor TMP36
const int LED_VERDE = 2;
const int LED_AMARELO = 3;
const int LED_VERMELHO = 4;

// Limites escolhidos(em graus Celsius)
const float LIMITE_ATENCAO = 27.0;  // a partir daqui: atencao
const float LIMITE_CRITICO = 31.0;  // a partir daqui: critico

void setup() {
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Converte a leitura analogica (0 a 1023) em tensao (0 a 5 V)
  float tensao = analogRead(PINO_SENSOR) * 5.0 / 1024.0;
  // TMP36: 0,5 V = 0 C e 10 mV por grau
  float tempC = (tensao - 0.5) * 100.0;

  // Apaga todos os LEDs antes de acender o do estado atual
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERMELHO, LOW);

  if (tempC < LIMITE_ATENCAO) {
    digitalWrite(LED_VERDE, HIGH);      // normal
  } else if (tempC < LIMITE_CRITICO) {
    digitalWrite(LED_AMARELO, HIGH);    // atencao
  } else {
    digitalWrite(LED_VERMELHO, HIGH);   // critico
  }

  Serial.print("Temperatura: ");
  Serial.print(tempC);
  Serial.println(" C");
  delay(500);
}
