# so below is the code and i included a servo motor library
#include <Servo.h> 
# I initialized constants at the beginning to 
const int trigPin = 9;# this is where the transmitting wire will be placed 
const int echoPin = 10;# this is where the echo pin of ultrasonic sensor is placed

long duration;
int distinCM;

Servo radarServo;
# here we start initializing our setup
void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  radarServo.attach(11);
}
# here is where our for loop begins
void loop() 
{
  for(int i=0;i<=180;i++)
  {
    radarServo.write(i);
    delay(50);
    
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distinCM = duration*0.034/2;
    
    Serial.print(i);
    Serial.print("*");
    Serial.print(distinCM);
    Serial.print("#");
  }
  
  for(int i=180;i>=0;i--)
  {
    radarServo.write(i);
    delay(50);
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distinCM = duration*0.034/2; # a function to calculate the distance in centimetre
    
    Serial.print(i);
    Serial.print("*");# this prints to the serial monitor
    Serial.print(distinCM);
    Serial.print("#");# this also prints to the serial monitor
  }
}
# i hope it is clear <agrey>