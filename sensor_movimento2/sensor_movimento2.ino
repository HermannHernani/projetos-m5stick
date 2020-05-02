int LED1 = 13;
int LED2 = 12;
int BUZZER = 11;
int pir = 10;
int armazena = 0; 


void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(pir, INPUT);
  
}

void loop() {
  pinMode(BUZZER, LOW);
  armazena = digitalRead(pir);

  if (armazena == HIGH){
    alarme();
  }
  else{
    silenciar();
  }
  delay(10);
}



void alarme(){
  digitalWrite(LED2, LOW);
  digitalWrite(LED1, HIGH);
  tone(BUZZER, 1450);
  delay(250);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED1, LOW);
  tone(BUZZER, 1890);
  delay(250);
}


void silenciar(){
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  noTone(BUZZER);
  delay(50);
}
