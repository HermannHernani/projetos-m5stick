#include <M5StickC.h>
#include "DHT12.h"
#include <Wire.h>
#include "Adafruit_Sensor.h"
DHT12 dht12; 

int battery = 0;
float b = 0;
int state = 1;
bool LCD = true;
bool alertM = true;
const int ledPin = 26;
int randNumber;

//WiFi credentials
char* ssid       = "JACQUES HERNANI_2G";
char* password   = "Hera2908"; 

// database connection

void sendData(){
  IPAddress ip(127,0,0,1);
  int photocellPin = 0;  // Analog input pin on Arduino we connected the SIG pin from sensor
  int photocellReading;  // Here we will place our reading
  char server[] = "127.0.0.1:3306"; // IMPORTANT: If you are using XAMPP you will have to find out the IP address of your computer and put it here (it is explained in previous article). If you have a web page, enter its address (ie. "www.yourwebpage.com")
  char database[] = "person_data";
  send = (hum;temp;1);
}

void batteryPercent() {
  M5.Lcd.setCursor(115, 2);
  M5.Lcd.setTextSize(1);
  b = M5.Axp.GetVbatData() * 1.1 / 1000;
  battery = ((b - 3.0) / 1.2) * 100;

  if (battery > 100)
    battery = 100;
  else if (battery < 100 && battery > 9)
    M5.Lcd.print(" ");
  else if (battery < 9)
    M5.Lcd.print("  ");
  if (battery < 10)
    M5.Axp.DeepSleep();
  M5.Lcd.print(battery);
  M5.Lcd.print("%");
}

void buttons_code() {
  // Button B control the LCD (ON/OFF)
  if (M5.BtnB.wasPressed()) {
    if (LCD) {
      M5.Lcd.writecommand(ST7735_DISPOFF);
      M5.Axp.ScreenBreath(0);
      LCD = !LCD;
    } else {
      M5.Lcd.writecommand(ST7735_DISPON);
      M5.Axp.ScreenBreath(10);
      LCD = !LCD;
    }
  }
  if (M5.BtnA.wasPressed()) {
    M5.Lcd.writecommand(ST7735_DISPON);
    M5.Axp.ScreenBreath(10);
    M5.Lcd.setTextSize(1);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(20, 15);
    M5.Lcd.println("Enviando/Conectando");
    delay(1000);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(20, 15);
    M5.Lcd.println("Aguarde");
    delay(1000);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(20, 15);
    M5.Lcd.println("Aguarde .");
    delay(1000);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(20, 15);
    M5.Lcd.println("Aguarde ..");
    delay(1000);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(20, 15);
    M5.Lcd.println("Aguarde ...");
    delay(1000);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(20, 15);
    M5.Lcd.println("Aguarde ....");
    delay(2000);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(20, 15);
    M5.Lcd.println("ENVIADO!");
    delay(2000);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(5, 5, 2);
    M5.Lcd.println("V1.0");
    m5.update();
    checkTemp();
    //delay(60000);
    delay(6000);
    alert();
    checkTemp();
    M5.Lcd.setCursor(5, 5, 2);
    M5.Lcd.println("V1.0");
    batteryPercent();
    sendData(hum, temp);
  }
}


void alert(){
  delay(1000);
  M5.Lcd.fillScreen(RED);
  M5.Lcd.setCursor(20, 15);
  M5.Lcd.println("RISCO DE ALERGIA");
  delay(1000);
  M5.Lcd.fillScreen(BLUE);
  M5.Lcd.setCursor(20, 15);
  M5.Lcd.println("RISCO DE ALERGIA");
  delay(1000);
  M5.Lcd.fillScreen(RED);
  M5.Lcd.setCursor(20, 15);
  M5.Lcd.println("RISCO DE ALERGIA");
  delay(1000);
  M5.Lcd.fillScreen(BLUE);
  M5.Lcd.setCursor(20, 15);
  M5.Lcd.println("RISCO DE ALERGIA");
  delay(1000);
  M5.Lcd.fillScreen(RED);
  M5.Lcd.setCursor(20, 15);
  M5.Lcd.println("RISCO DE ALERGIA");
  delay(1000);
  M5.Lcd.fillScreen(BLUE);
  M5.Lcd.setCursor(20, 15);
  M5.Lcd.println("RISCO DE ALERGIA");
  delay(1000);
  M5.Lcd.fillScreen(RED);
  M5.Lcd.setCursor(20, 15);
  M5.Lcd.println("RISCO DE ALERGIA");
  delay(1000);
  M5.Lcd.fillScreen(BLUE);
  M5.Lcd.setCursor(20, 15);
  M5.Lcd.println("RISCO DE ALERGIA");
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(5, 5, 2);
  M5.Lcd.println("V1.0");
}

void checkTemp(){
  // put your main code here, to run repeatedly:
  float tmp = dht12.readTemperature();
  float hum = dht12.readHumidity();
  M5.Lcd.setCursor(5, 20, 2);
  M5.Lcd.printf("Temp: %2.0f", tmp);
  M5.Lcd.setCursor(5, 40, 2);
  M5.Lcd.printf("Humi: %2.0f%%", hum);
  batteryPercent();
}

void setup() {
  // put your setup code here, to run once:
  M5.begin();
  Wire.begin(0,26);
  M5.Lcd.setRotation(1);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(5, 5, 2);
  M5.Lcd.println("V1.0");
}

void loop() {
  M5.update();
  pinMode (ledPin, OUTPUT);
  buttons_code();
  checkTemp();
  batteryPercent();
}
