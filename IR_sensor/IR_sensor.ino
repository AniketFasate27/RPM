#define IR 4
int val = 0 ;

void setup()
{
  Serial.begin(115200); // sensor buart rate
 
  pinMode(IR, INPUT);
}
void loop()
{
  val = digitalRead(IR);
  if (val == 1 )
  {
    Serial.println("High")
  }
  else
  {
    Serial.println ("LOW"); // LED OFF
  }
}
