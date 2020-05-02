int pinBuzzer = 7;
int pinSensorPIR = 8;
int pinLed = 9;
int valorSensorPIR = 0;

void setup() {
    Serial.begin(9600);
    pinMode(pinBuzzer, OUTPUT);
    pinMode(pinSensorPIR, INPUT);
    pinMode(pinLed, OUTPUT);
}

void loop() {
    valorSensorPIR = digitalRead(pinSensorPIR);
    Serial.print("Valor do Sensor PIR: ");
    Serial.println(valorSensorPIR);

    if (valorSensorPIR == 0){
        ligarAlarme();

  } else {
      desligarAlarme();
  }
}

void ligarAlarme(){
  digitalWrite(pinLed, HIGH);
  tone(pinBuzzer, 1500);
  delay(4000);
  desligarAlarme();
}

void desligarAlarme() {
  digitalWrite(pinLed, LOW);
  noTone(pinBuzzer);
}
