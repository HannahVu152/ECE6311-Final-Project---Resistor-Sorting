#include <AFMotor.h> 
AF_DCMotor motor1(1, MOTOR12_1KHZ);
const int sensorPin = A8;  // Analog input pin that senses Vout
int sensorValue = 0;       // sensorPin default value
float Vin = 5;             // Input voltage
float Vout = 0;            // Vout default value
float Rref = 999;          // Reference resistor's value in ohms (you can give this value in kiloohms or megaohms - the resistance of the tested resistor will be given in the same units)
float R = 0;               // Tested resistors default value
void setup ()
{
  motor1.setSpeed(170);
  Serial.begin(9600);      // Initialize serial communications at 9600 bps
  // pinMode(motor1, OUTPUT);
}
void loop ()
{

  sensorValue = analogRead(sensorPin);  // Read Vout on analog input pin A0 (Arduino can sense from 0-1023, 1023 is 5V)
  Vout = (Vin * sensorValue) / 1023;    // Convert Vout to volts  
    R = Rref * (1 / ((Vin / Vout) - 1))/2 ;  // Formula to calculate tested resistor's value
  Serial.print("R: ");                  
  Serial.println(R);                    // Give calculated resistance in Serial Monitor
  delay(500);                          // Delay in milliseconds between reeds
  if(R==inf)
  {
    motor1.run(BACKWARD);             // DC motor run backward direction 
    delay(400);                       // Delay in milliseconds between reeds
    motor1.run(FORWARD);              // DC motor run forward direction 
    delay(550);                       // Delay in milliseconds between reeds
    motor1.run(RELEASE);              // DC motor stops
    
  }
 
  else
  {
    motor1.run(RELEASE);             // DC motor stops moving when the resistor comes out of toothpick dispenser
  }
}

    