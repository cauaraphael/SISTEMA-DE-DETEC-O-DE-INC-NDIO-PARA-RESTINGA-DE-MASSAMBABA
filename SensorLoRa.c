#include <DHT.h>
#include <LoRa.h>
#include <SPI.h>
#define DHTTYPE DHT11
#define DHTPIN 3
DHT dht(DHTPIN, DHTTYPE);
int chama = 7;
int gas = 6;
int val = 0;
int leiturachama;
int leituragas;
void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(chama, INPUT);
  pinMode(gas, INPUT);

  while (!Serial);
  Serial.println("LoRa Sender");
  if (!LoRa.begin(433E6)){
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  }
void loop() {
  delay(50);
  leiturachama = digitalRead(chama);
  leituragas = digitalRead(gas);
  float t = dht.readTemperature();
  if((leiturachama == 0) && (leituragas == 0) && (t>45)){
    val = 1;
  }
  else if ((leiturachama == 0) && (leituragas == 0) && (t<45)){
    val = 2;
  }
  else if ((leiturachama == 0) && (leituragas == 1) && (t>45)){
    val = 3;
  }
  else if ((leiturachama == 0) && (leituragas == 1) && (t<45)){
    val = 4;
  }
  else if ((leiturachama == 1) && (leituragas == 0) && (t>45)){
    val = 5;
  }
  else if ((leiturachama == 1) && (leituragas == 0) && (t<45)){
    val = 6;
  }
  else if ((leiturachama == 0) && (leituragas == 0) && (t>45)){
    val = 7;
  }
  else {
    val = 8;
  }
LoRa.beginPacket();
LoRa.print(val);
LoRa.endPacket();
}
