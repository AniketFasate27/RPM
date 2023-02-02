unsigned long lastflash;
int RPM;
void ICACHE_RAM_ATTR sens() {
  RPM++;
}

void setup() {
  Serial.begin(115200);
  // IR Infrared sensor
  pinMode(4, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(4), sens, FALLING);
  //SENSOR: GPIO0 (NodeMCU - D3)
}

void loop() {
  noInterrupts();
  int wings = 3; // no of wings of rotating object, for disc object use 1 with white tape on one side
  int RPMnew = RPM / wings; //here we used fan which has 3 wings
  Serial.print(RPMnew);
  Serial.print(" Rot/sec :");  //Revolutions per second
//  lcd.clear();
//  lcd.print(RPMnew);
//  lcd.print("Rot/sec");
  Serial.print((RPMnew * 60));
  Serial.println("Rot/min. ");   //Revolutions per minute
//  lcd. setCursor (0, 1);
//  lcd.print(RPMnew * 60);
//  lcd.print("Rot/min");
  RPM = 0;
  interrupts();
  delay(50);  //1 second.
}
