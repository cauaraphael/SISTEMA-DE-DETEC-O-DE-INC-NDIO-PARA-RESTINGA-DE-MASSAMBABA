#include <LoRa.h>
#include <SPI.h>
#include <Streaming.h>
char inChar;
int val = 0;
String inString = "";
void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("LoRa Receiver");
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
}
}
void loop() {
  delay(50);
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    while (LoRa.available()){
      inChar = LoRa.read();
      26
      inString += inChar;
      val = inString.toInt();
}
    inString = "";
}
  switch (val){
    case 1:
      Serial << "Há fumaça, chama e temperatura elevada!" << endl;
    break;
    case 2:
      Serial << "Há apenas chama e fumaça!" << endl;
    break;
    case 3:
      Serial << "Há apenas chama e temperatura elevada!" << endl;
    break;
    case 4:
      Serial << "Há apenas chama!"<< endl;
    break;
    case 5:
      Serial << "Há apenas fumaça e temperatura elevada!"<< endl;
    break;
    case 6:
      Serial << "Há apenas fumaça!" << endl;
    break;
    case 7:
      Serial << "Há apenas temperatura elevada!" << endl;
    break;
    case 8:
      Serial << "Não há chama, fumaça e temperatura elevada!" << endl;
    break;
    default:
      Serial << "Não há conexão com o outro LoRa" << endl;
    break;
  }
}
