const int sensorPin=A0;

void setup() 
{
Serial.begin(9600);
pinMode(13, OUTPUT);
}

boolean on = LOW;

void loop() 
{
int value = analogRead(sensorPin);
float millivolts= (value/1023.0)*5000;
float celsius = millivolts/10;
Serial.print(celsius);
Serial.println(" °C");
delay(1000);
if(celsius>10)
{
digitalWrite(13,LOW);
}
else
{
digitalWrite(13,HIGH);
}
}
