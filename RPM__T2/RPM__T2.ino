#define IR 4
int val = 0 ;
unsigned long myTime_1, myTime_2, myTime_3;
int count;
void setup()
{
  Serial.begin(115200); // sensor buart rate
  pinMode(IR, INPUT);
}
void loop() {
  val = digitalRead(IR);
  delay(1);
  if (val == 0)
  {
    count += 1;
    myTime_1 = millis();
//    Serial.println(myTime_1);
    if (myTime_1 == 60000) {
//      Serial.println(count);
      int wings = 3; // no of wings of rotating object, for disc object use 1 with white tape on one side
      int RPMnew = count / wings; //here we used fan which has 3 wings
      Serial.print(RPMnew);
      Serial.print(" Rot/sec :");  //Revolutions per second
      Serial.print((RPMnew * 60));
      Serial.println("Rot/min. ");
      count = 0;
      myTime_1 = 0;
    }
  }
}
