
const int IR_IN = 2; //IR sensor INPUT
unsigned long prevmicros; // To store time
unsigned long duration; // To store time difference
unsigned long lcdrefresh; // To store time for lcd to refresh

int rpm; // RPM value

boolean currentstate; // Current state of IR input scan
boolean prevstate; // State of IR sensor in previous scan

void setup()
{
  Serial.begin(115200);
  pinMode(IR_IN,INPUT);    
  prevmicros = 0;
  prevstate = LOW;  
  Serial.println("printing the values");
}

void loop()
{
 ///////////////////////////////////////////////////////////////////////////////// RPM Measurement
 currentstate = digitalRead(IR_IN); // Read IR sensor state
 Serial.println(currentstate);
 if( prevstate != currentstate) // If there is change in input
   {
     if( currentstate == HIGH ) // If input only changes from HIGH to LOW
       {
         duration = ( micros() - prevmicros ); // Time difference between revolution in microsecond
         rpm = ((60000000/duration)/3); // rpm = (1/ time millis)*1000*1000*60;
         prevmicros = micros(); // store time for nect revolution calculation
       }
   }
  prevstate = currentstate; // store this scan (prev scan) data for next scan
  
  //////////////////////////////////////////////////////////////////////////////////// LCD Display
//   if( ( millis()-lcdrefresh ) >= 100 )
//     {
      
//       Serial.print("Speed of Motor");
//       // lcd.setCursor(0,1);
//       // lcd.print("RPM = ");
//       Serial.print("RPM = ");
//       // lcd.print(rpm);  
//       Serial.print(rpm);    
//       lcdrefresh = millis();   
//     }

// }
