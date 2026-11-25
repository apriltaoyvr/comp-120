#include <SPI.h>
#include <SD.h>

const int CHIP_SELECT = 8;
const char FILE_NAME[] = "data26.txt";

File f;
unsigned long t1;

void setup() {
  delay(5000);
  Serial.begin(9600);

  Serial.print("\nInitializing SD card........");

  if (!SD.begin(CHIP_SELECT)) {
    Serial.println("initialization failed. Things to check:");
    Serial.println("* is a card inserted?");
    Serial.println("* is your wiring correct?");
    while (1);
  } else {
    Serial.println("Wiring is correct and a card is present.");
  }

  if (SD.exists(FILE_NAME)) {
    SD.remove(FILE_NAME);
  }

  f = SD.open(FILE_NAME, FILE_WRITE);

  if (!f) {
    Serial.println("Could not open the txt file.");
    while (1);
  }

  t1 = millis();
}

void sense() {
  int sensor_value = analogRead(A0);

  Serial.println(sensor_value);
  f.println(sensor_value);
  delay(250);
}

void loop() {

  while (millis() - t1 < 20000) {
    sense();
  } 
    
  f.close();
}