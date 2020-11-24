const int TrigPin = 7; // Trigger Pin of Ultrasonic Sensor
const int EchoPin = 6; // Echo Pin of Ultrasonic Sensor
int led = 9;
int sensorValue = 0;
float distance;

void setup()
{
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

  sensorValue = map(distance, 0,50,255,0);
  if (distance <= 50)
  {
    analogWrite(led, sensorValue);   
  } 
  else
  {
    digitalWrite(led, LOW);
  }
  
  
}
