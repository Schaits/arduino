/*
  Exercise 360 degree Servo motor
  Simply runs servo in one direction for 3 seconds, stops, then reverses direction
  Uses built-in Servo.h library
*/
#include "Servo.h"
#include <unistd.h>
#define SERVO_PIN 9   // Can use any PWM pin
#define SERVO_PIN2 10   // Can use any PWM pin

int sensorpin = 0;                 // analog pin used to connect the sharp sensor
int val = 0;                 // variable to store the values from sensor(initially zero)

int currentDegrees = 0;
int direction = 1;


Servo servo;          // creates servo object used to control the servo motor
Servo servo2;
//===============================================================================
//  Initialization
//===============================================================================
void setup()
{
  servo.attach(SERVO_PIN); // assigns PWM pin to the servo object
  servo2.attach(SERVO_PIN2); // assigns PWM pin to the servo object
  Serial.begin(9600);
  currentDegrees = 0;
  servo.write(0); //Spin in one direction
  servo2.write(100);

}
//===============================================================================
//  Main
//===============================================================================

void update () {

    if (direction == 1){
      currentDegrees = currentDegrees +1;
    } else {
      currentDegrees = currentDegrees -1;
    }

    if (currentDegrees >= 180){direction = 0; delay(100);}
    else if (currentDegrees <= 0){direction = 1; delay(100);}

    servo.write(currentDegrees);
    Serial.print(currentDegrees);
    Serial.print(", ");
    val = analogRead(sensorpin);       // reads the value of the sharp sensor
    Serial.print(val);            // prints the value of the sensor to the serial monitor
    Serial.print(", ");
    Serial.println(800);

    if (val > 500){servo2.write(currentDegrees);}
}
void loop()
{
  //servo.write(); //Spin in one direction



  while (1) {
     delay(10);
     update();
  }

}
