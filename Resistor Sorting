// Students names: Hannah Vu, Ajay Dhakal, Koushiram Gali, Suganya Radhakrishnan Elumalai
// ECE6311 - Intro to Robotics
// Final Project: Resistor sorting
// 12/13/2022

const int DMMPin = A12;    // Analog input pin that senses Vout for the Digital Multimeter
const int EMPin = 22;      // Digital pin for the Electromagnet

// Define analog pins for 4 Potentiometers
#define P1 A8 
#define P2 A9
#define P3 A10
#define P4 A11
// Declare 4 DCMotors
#include <AFMotor.h> // https://learn.adafruit.com/adafruit-motorshield/af-dcmotor-class
AF_DCMotor motor1(1, MOTOR12_1KHZ); // The first argument stands for the number of the motors in the shield and the second 
AF_DCMotor motor2(2, MOTOR12_1KHZ); // one stands for the motor speed control frequency. 
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

// Set up initial values to process Digital Multimeter
int DMMValue = 0;          // sensorPin default value
float Vin = 5;             // Input voltage
float Vout = 0;            // Vout default value
float Rref = 987;          // Reference resistor's value in ohms (you can give this value in kiloohms or megaohms - the resistance of the tested resistor will be given in the same units)
float R = 0;               // Tested resistors default value
float R1 = 0;               // Tested resistors default value

void setup ()
{
  Serial.begin(9600);      // Initialize serial communications at 9600 bps
  // Setup Pinout for the Electromagnet
  pinMode(EMPin, OUTPUT);     // Set EMpin as OUTPUT
  digitalWrite(EMPin, LOW);   // Set the Electromagnet to LOW
  
  // Setup speed for the DCmotor
  Serial.begin(9600);
  Serial.println("Resistor Sorting!");
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);


// Get to start position
  Move1(630); 
  Move3(488);
  Move2(837);
  Move4(357);
}

void loop ()
{
  //digitalWrite();
  DMMValue = analogRead(DMMPin);        // Read Vout on analog input pin A0 (Arduino can sense from 0-1023, 1023 is 5V)
  Vout = (Vin * DMMValue) / 1023;       // Convert Vout to volts
  R1 = Rref * (1 / ((Vin / Vout) - 1))/2;  // Formula to calculate tested resistor's value
  R = R1 - R1*0.1;
  Serial.print("R: ");                  
  Serial.println(R);                    // Give calculated resistance in Serial Monitor
  delay(1000);                          // Delay in milliseconds between reeds

  //Displays current values of the potentiometers for Debugging
  Serial.print("Base: ");
  Serial.print(analogRead(P4));

  Serial.print(" - Shoulder: ");
  Serial.print(analogRead(P3));

  Serial.print(" - Elbow: ");
  Serial.print(analogRead(P2));

  Serial.print(" - Wrist: ");
  Serial.print(analogRead(P1));
  Serial.print('\n');

// Pick up and drop off 100 [Ohm] resistor
  if(R>=80 && R<=200){        
    PickupResistor();
    OneHundredOhm();
  }

// Pick up and drop off 1 [KOhm] resistor
  else if(R>=700 && R<=2000){
    PickupResistor();
    OneKOhm();
  }

// Pick up and drop off 11 [KOhm] resistor
  else if(R>=8000 && R<=16000){
    PickupResistor();
    ElevenKOhm();
  }

// Pick up and drop off 47 [KOhm] resistor
  else if(R>=35000 && R<=57000){
    PickupResistor();
    FoutySevenKOhm();
  }
  else {
  }
}

// function for 100 Ohm resistor
void OneHundredOhm(){
  Move1(630);                 // Move to the 100 [Ohm] Bin
  Move4(577);
  Move3(615);
  Move2(869);  
  digitalWrite(EMPin, LOW);   // Drop the registor off
  Move2(837);                 // Move back to the start position
  Move3(488);
  Move4(357);
}

// Function for 1 [KOhm]
void OneKOhm(){
  Move1(630);                 // Move to the 1 [KOhm] Bin
  Move4(486);
  Move3(645);
  Move2(853);  
  digitalWrite(EMPin, LOW);   // Drop the registor off
  Move2(837);                 // Move back to the start position
  Move3(488);
  Move4(357);
}

// Function for 11 [KOhm]
void ElevenKOhm(){
  Move1(630);                 // Move to the 11 [KOhm] Bin
  Move4(215);
  Move3(670);
  digitalWrite(EMPin, LOW);
  Move2(770);
  //digitalWrite(EMPin, LOW);  // Drop the registor off
  Move2(837);                 // Move back to the start position
  Move3(488);
  Move4(357);

}

// Function for 47 [KOhm] Resistor
void FoutySevenKOhm(){
  Move1(630);                 // Move to the 47 [KOhm] Bin
  Move4(122);
  Move3(660);
  digitalWrite(EMPin, LOW);
  Move2(685);
  //digitalWrite(EMPin, LOW);  // Drop the registor off
  Move2(837);                 // Move back to the start position
  Move3(488);
  Move4(357);

}

// Always move from the start position to pick up a resistor and move back up
void PickupResistor(){
    Move1(555);
    Move3(680);
    digitalWrite(EMPin, HIGH);    // pick the registor up
    Move3(488);       // Move back up
}

// Subroutin to move Motor 1 to a specific position
void Move1(int voltage){
  int data1 = analogRead(P1);
  while (1){
    if(data1 >=voltage+10){
      motor1.run(BACKWARD); delay(30);
    }
    else if(data1<=voltage-10){
      motor1.run(FORWARD); delay(30);
    }  
    else{
      motor1.run(RELEASE); delay(500);
      break;
    }  
    data1 = analogRead(P1);
  }


}

// Subroutin to move Motor 2 to a specific position
void Move2(int voltage){
  int data2 = analogRead(P2);
  while (1){
    if(data2 >=voltage+10){
      motor2.run(BACKWARD); delay(30);
    }
    else if(data2<=voltage-10){
      motor2.run(FORWARD); delay(30);
    }  
    else{
      motor2.run(RELEASE); delay(500);
      break;
    }  
    data2 = analogRead(P2);
  }


}

// Subroutin to move Motor 3 to a specific position
void Move3(int voltage){
  int data3 = analogRead(P3);
  while (1){
    if(data3 >=voltage+10){
      motor3.run(BACKWARD); delay(30);
    }
    else if(data3<=voltage-10){
      motor3.run(FORWARD); delay(30);
    }  
    else{
      motor3.run(RELEASE); delay(500);
      break;
    }  
    data3 = analogRead(P3);
  }
}

// Subroutin to move Motor 4 to a specific position
void Move4(int voltage){
  int data4 = analogRead(P4);
  while (1){
    if(data4 >=voltage+10){
      motor4.run(BACKWARD); delay(30);
    }
    else if(data4<=voltage-10){
      motor4.run(FORWARD); delay(30);
    }  
    else{
      motor4.run(RELEASE); delay(500);
      break;
    }  
    data4 = analogRead(P4);
  }
}
