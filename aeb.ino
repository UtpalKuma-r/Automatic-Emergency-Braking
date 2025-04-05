int outputValue = 0;
long duration;
int distance;
int trig = 7;
int echo = 6;

void setup()
{
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  Serial.begin(9600);
  digitalWrite(trig, LOW);
}

void loop()
{
  // read the value from the sensor
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;
  outputValue = map(distance, 30, 300, 0, 255);
  
  analogWrite(9, outputValue);
  
  if(distance < 60){
  	digitalWrite(5, HIGH);
  } else{
  	digitalWrite(5, LOW);
  }
  
  Serial.print("sensor = ");
  Serial.print(distance);
  Serial.print("     motor speed = ");
  Serial.println(outputValue);
  delay(100); // Wait for 100 millisecond(s)
}
