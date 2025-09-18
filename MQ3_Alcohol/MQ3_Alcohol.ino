const int pin_sensor = 34;  
const int buzzer = 12;      

void setup() {
  Serial.begin(9600);            
  pinMode(buzzer, OUTPUT);       
  pinMode(pin_sensor, INPUT);    
}

void loop() {
  int valor_alcohol = analogRead(pin_sensor);  
  Serial.print("Valor alcohol: ");
  Serial.println(valor_alcohol);                
  float porcentaje = (valor_alcohol / 1023.0) * 100;
  const int pin_sensor = 34;  
const int buzzer = 12;     



  if (valor_alcohol > 1200) {  
    digitalWrite(buzzer, HIGH);   
  } else {
    digitalWrite(buzzer, LOW);    
  }
  Serial.print("Porcentaje: ");
  Serial.println(porcentaje);                 
   delay(200); 
}