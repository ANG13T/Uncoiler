#include <Stepper.h>

const float STEPS_PER_REV = 32; 
 
//  Amount of Gear Reduction
const float GEAR_RED = 64;
 
// Number of steps per geared output rotation
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;

const int buttonReciever = 7;
int val = 0;
 
// Define Variables
 
// Number of Steps Required
int StepsRequired;
 
Stepper steppermotor(STEPS_PER_REV, 8, 10, 9, 11);
 
void setup()
{
  Serial.begin(9600);
  pinMode(buttonReciever, INPUT);
}
 
void loop()
{
  val = digitalRead(buttonReciever);
  if(val == HIGH){
    Serial.println("Button pressed");
    StepsRequired  =  -STEPS_PER_OUT_REV * 2; 
    steppermotor.setSpeed(1000);   
    steppermotor.step(StepsRequired);
    delay(500);
  }
  
}
