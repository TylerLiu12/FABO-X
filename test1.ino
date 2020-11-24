#include <Servo.h>
Servo myservo; 

int pos = 180;
const int TrigPin = 7; // Trigger Pin of Ultrasonic Sensor
const int EchoPin = 6; // Echo Pin of Ultrasonic Sensor
int led = 9;
int sensorValue = 0;
float distance;

void setup()
{
   myservo.attach(10);
   Serial.begin(9600);
   pinMode(TrigPin, OUTPUT);
   pinMode(EchoPin, INPUT);
   pinMode(led, OUTPUT);
   Serial.println("Ultrasonic sensor:");
}

void loop()
{
  unsigned int x1;
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  distance = pulseIn(EchoPin, HIGH) / 58.00;
  x1 = distance * 100.0; 
  distance = x1 / 100.0;

  Serial.print(distance);
  Serial.print("cm");
  Serial.println();

  sensorValue = map(distance, 0,20,255,0);
  if (distance <= 20)
  {
    analogWrite(led, sensorValue);
    for(pos = 180; pos >= 90; pos -= 1)
    {
      myservo.write(pos);
      delay(50);
    }
    delay(5000);
     for(pos = 90; pos < 180; pos += 1)
    {
      myservo.write(pos);
      delay(50);
    }
  } 
  else
  {
    digitalWrite(led, LOW);
  }
  
  
}
