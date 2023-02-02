int RPM;
void ICACHE_RAM_ATTR sens() {
  RPM++;
}

void setup() {
  Serial.begin(250000);

  pinMode(4, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(4), sens, RISING);
  //SENSOR: GPIO0 (NodeMCU - D3)
}

void loop() {
  noInterrupts();
  int wings = 3; // no of wings of rotating object, for disc object use 1 with white tape on one side
  int RPMnew = RPM / wings; //here we used fan which has 3 wings
  Serial.println(RPMnew);
  //  Serial.println(" Rot/sec :");  //Revolutions per second
  //  Serial.print((RPMnew * 60));
  //  Serial.println("Rot/min. ");   //Revolutions per minute

  RPM = 0;
  interrupts();
  delay(1000);  //1 second.
}
