#include <Arduino.h>

const int irSensorPin = 4; // change to the pin that your IR sensor is connected to
unsigned long lastTime = 0;
unsigned long curTime = 0;
unsigned long deltaTime = 0;
double RPM = 0;
int count = 0;

void IRAM_ATTR onSensorChange() {
  count++;
}

void setup() {
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(irSensorPin), onSensorChange, RISING);
}

void loop() {
  curTime = millis();
  deltaTime = curTime - lastTime;
  if (deltaTime >= 1000) { // calculate RPM every second
    RPM = (count / 2) * (60000.0 / deltaTime);
    Serial.println(RPM);
    lastTime = curTime;
    count = 0;
  }
}
