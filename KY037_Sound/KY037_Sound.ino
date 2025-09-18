#include <Servo.h>

Servo myServo;  // Crea un objeto servo
int sensorPin = A0;  // Pin donde se conecta la señal del sensor de sonido
int sensorValue = 0;  // Variable para leer el valor del sensor
float voltage = 0.0;  // Para almacenar el voltaje calculado
float dB = 0.0;  // Para almacenar el valor en decibelios
int threshold = 50;  // Umbral para detectar sonido (ajustable)

void setup() {
  myServo.attach(9);  // Conecta el servomotor al pin 9
  Serial.begin(9600);  // Inicia la comunicación serial
}

void loop() {
  sensorValue = analogRead(sensorPin);  // Lee el valor del sensor de sonido
  voltage = sensorValue * (5.0 / 1023.0);  // Convertir el valor a voltaje

  if (voltage > 0) {
    dB = (20 * log10(voltage);  // Cálculo de decibelios
  } else {
    dB = 0;
  }

  // Enviar datos a Visual Studio en formato estructurado
   Serial.print(dB);
  Serial.println(" dB");

  // Si el sonido supera el umbral, mover el servo
  if (sensorValue > threshold) {
    myServo.write(10);
    delay(1000);
    myServo.write(90);
    delay(1000);
  }

  delay(500);  // Pequeña pausa para evitar sobrecarga en la comunicación
}
