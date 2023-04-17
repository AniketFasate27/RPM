int RPM;
uint32_t time1;
uint32_t time2;
uint32_t result;
void ICACHE_RAM_ATTR sens() {
  RPM++;
  delay(10);
}

void setup() {
  time1 = millis();
  Serial.begin(115200);

  pinMode(4, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(4), sens, FALLING);
  //SENSOR: GPIO0 (NodeMCU - D3)
}

void loop() {
  time1 = millis();
  noInterrupts();

  int wings = 1; // no of wings of rotating object, for disc object use 1 with white tape on one side
  int RPMnew = RPM / wings; //here we used fan which has 3 wings
  //  Serial.println(RPMnew);
  //    Serial.println(" Rot/sec :");  //Revolutions per second
  //    Serial.println((RPMnew * 60));
  //    Serial.println("Rot/min. ");   //Revolutions per minute

  RPM = 0;
  time2 = millis();
  result = (time1 / time2);
  interrupts();
  time2 = millis();
  result = (time1 - time2);
  Serial.println(result);
  delay(500);  //1 second.
}
