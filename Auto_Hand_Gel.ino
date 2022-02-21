/* Auto Hand Gel
 by Ferdinand

 this sketch was created so if you have a hand gel bottle at home you would not need to touch it
 risking getting bacteria and viruses on it. This project is quite simple but i still like it.

 Created on 16th March 2020
 by Ferdinand
*/

#include <Servo.h>       // including the servo libary
Servo myservo;           // creates servo object to control a servo
int pos = 0;             // variable to store the servo position
const int trigPin = 10;  // Trigger Pin of Ultrasonic Sensor
const int echoPin = 11;  // Echo Pin of Ultrasonic Sensor
long duration;           // used to calculate distance from the ultrasonic sensor
int distance;            // is the disance from the ultrasonic sensor

void setup() {
  myservo.attach(9);         // attaches the servo on pin 9 to the servo object
  pinMode(trigPin, OUTPUT);  // makes the trigger pin of the sensor an output
  pinMode(echoPin, INPUT);   // makes the echo pin of the sensor an input
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  if (distance <= 10){ 
    for (pos = 0; pos <= 100; pos += 4) {   // goes from 0 degrees to 180 degrees in steps of 4 degree
      myservo.write(pos);                   // tell servo to go to position in variable 'pos'
      delay(15);                            // waits 15ms for the servo to reach the position
      }
    for (pos = 100; pos >= 0; pos -= 4) {   // goes from 180 degrees to 0 degrees
      myservo.write(pos);                   // tell servo to go to position in variable 'pos'
      delay(15);                            // waits 15ms for the servo to reach the position
                                            // does one 'pump' of the hand gel
     }
  }  
}
