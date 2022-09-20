int analogPin = 2;

void setup()
{
  pinMode(analogPin, OUTPUT);
}

void loop()
{
  analogWrite(analogPin, 102.2); //duty40%
}
