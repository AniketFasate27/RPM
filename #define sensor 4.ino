#define sensor 4

int delay1()
{
  //unsigned int long k;
  int i, j;
  unsigned int count = 0;
  for (i = 0; i < 1000; i++)
  {
    for (j = 0; j < 1000; j++)
    {
      if (digitalRead(sensor))
      {
        count++;
        while (digitalRead(sensor));
      }
    }
  }
  return count;
}
void setup()
{
  Serial.begin(115200);
  pinMode(sensor, INPUT);
  //  pinMode(start, INPUT);

  delay(2000);
  //  digitalWrite(start, HIGH);
}
void loop()
{
  unsigned int time = 0, RPM = 0;

  //  while (digitalRead(start));

  time = delay1();

  //  RPM = (time * 12) / 3;
  RPM = (time * 12);
  //  delay(2000);
  Serial.print("RPM = ");
  Serial.println(RPM);
    delay(5000);
}