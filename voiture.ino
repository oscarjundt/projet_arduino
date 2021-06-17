int inches = 0;

int cm = 0;

long readUltrasonicDistance(int e, int f)
{
  pinMode(e, OUTPUT);  // Clear the trigger
  digitalWrite(e, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(e, HIGH);
  delayMicroseconds(10);
  digitalWrite(e, LOW);
  pinMode(f, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(f, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  // measure the ping time in cm
  cm = 0.01723 * readUltrasonicDistance(7, 7);
  // convert to inches by dividing by 2.54
  inches = (cm / 2.54);
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.println("cm");
  delay(100); // Wait for 100 millisecond(s)
  if(cm<100){
    digitalWrite(6,LOW);
    digitalWrite(5, LOW);
  }
  else{
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
  }
}
